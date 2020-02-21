#include"pch.h"
#include"SoftingApplication.h"
#include "Utils.h"
#include"Constants.h"
#include<algorithm>

DrvOPCUAHistValues::SoftingApplication::SoftingApplication():m_pApp(), m_AppDesc(), m_enumResult(), m_CertificateInfo(), m_pOutputList()
{

}

void DrvOPCUAHistValues::SoftingApplication::SetSertificate(const SecurityCertificateAccess& certificateInfo)
{
	if (m_pApp.isNull()) {
		m_CertificateInfo = certificateInfo;
	}
}

DrvOPCUAHistValues::SoftingApplication::~SoftingApplication()
{
	stopApplication();
}

void DrvOPCUAHistValues::SoftingApplication::AddDelegate(std::shared_ptr<SoftingApplicationOutput> delegate)
{
	std::vector< std::weak_ptr<SoftingApplicationOutput> >::iterator newEnd = std::remove_if(m_pOutputList.begin(), m_pOutputList.end(), [&](std::weak_ptr<SoftingApplicationOutput> ptr) {
		std::shared_ptr<SoftingApplicationOutput> output = ptr.lock();
		if (output == nullptr || output == delegate) {
			return true;
		}
		return false; });
	m_pOutputList.erase(newEnd, m_pOutputList.end());
	m_pOutputList.push_back(delegate);
}

void DrvOPCUAHistValues::SoftingApplication::initApplicationDescription()
{
	std::string computerName;
	if (getComputerName(computerName) == false) {
		computerName = std::string("localhost");
	}
	m_AppDesc.clear();
	std::string folder = std::string("/ODS/DreamReport/System/");
	m_AppDesc.setApplicationType(EnumApplicationType_Client);
	m_AppDesc.setApplicationName(SoftingOPCToolbox5::LocalizedText(_T("DreamReport OpcUa Histotical Items Client"), _T("en")));
	m_AppDesc.setApplicationUri(_T("urn:") + computerName + folder + std::string(OPC_UA_LIBRARY_NAME));	// The ApplicationUri should match with the URI in the application certificate
	m_AppDesc.setProductUri(_T("urn:") + folder + std::string(OPC_UA_LIBRARY_NAME));
}

bool DrvOPCUAHistValues::SoftingApplication::StartApplication()
{
	if (m_pApp.isNotNull()) {
		return true;
	}
	m_enumResult = SoftingOPCToolbox5::loadToolbox(NULL);
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("Failed to load the SDK: ") + std::string(getEnumStatusCodeString(m_enumResult));
		sendErrorMessageToDelegates(std::move(message));
		return false;
	}

	m_pApp = SoftingOPCToolbox5::Application::instance();
	if (!m_CertificateInfo.m_pkiTrustedPath.empty()) {
		SoftingOPCToolbox5::PkiStoreConfiguration storeConfiguration;
		storeConfiguration.setCertificateTrustListLocation(m_CertificateInfo.m_pkiTrustedPath.c_str());
		m_enumResult = m_pApp->setPkiStoreConfiguration(&storeConfiguration);
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("Failed to set the PKI store configuration: ") + std::string(getEnumStatusCodeString(m_enumResult));
			sendErrorMessageToDelegates(std::move(message));
			resetApplication();
			return false;
		}
	}
	initApplicationDescription();
	m_enumResult = m_pApp->initialize(&m_AppDesc);
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("Failed to initialize the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
		sendErrorMessageToDelegates(std::move(message));
		resetApplication();
		return false;
	}

	if (StatusCode::isGood(m_enumResult))
	{
		if (m_CertificateInfo.m_certificate.empty() == false && m_CertificateInfo.m_privateKey.empty() == false &&
			m_CertificateInfo.m_password.empty() == false) {
			m_enumResult = m_pApp->setInstanceCertificate(m_CertificateInfo.m_certificate.c_str(), m_CertificateInfo.m_privateKey.c_str(), m_CertificateInfo.m_password.c_str());
			if (StatusCode::isBad(m_enumResult))
			{
				std::string message = std::string("Failed to load the application certificate: ") + std::string(getEnumStatusCodeString(m_enumResult));
				sendErrorMessageToDelegates(std::move(message));
				resetApplication();
				return false;
			}
		}
		m_enumResult = m_pApp->start();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("Failed to start the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			sendErrorMessageToDelegates(std::move(message));
			resetApplication();
			return false;
		}
	}
	return true;
}

void DrvOPCUAHistValues::SoftingApplication::resetApplication()
{
	m_pApp.reset();
	EnumStatusCode m_enumResult = SoftingOPCToolbox5::unloadToolbox();
	if (StatusCode::isBad(m_enumResult))
	{
		std::string message = std::string("An error occurred while unloading the SDK:") + std::string(getEnumStatusCodeString(m_enumResult));
		sendErrorMessageToDelegates(std::move(message));
	}
}

bool DrvOPCUAHistValues::SoftingApplication::stopApplication()
{
	if (m_pApp.isNull()) {
		return true;
	}
	if (StatusCode::isGood(m_enumResult))
	{
		m_enumResult = m_pApp->stop();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("An error occurred while stopping the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			sendErrorMessageToDelegates(std::move(message));
			resetApplication();
			return false;
		}

		m_enumResult = m_pApp->uninitialize();
		if (StatusCode::isBad(m_enumResult))
		{
			std::string message = std::string("An error occurred while uninitializing the application: ") + std::string(getEnumStatusCodeString(m_enumResult));
			sendErrorMessageToDelegates(std::move(message));
			resetApplication();
			return false;
		}
		m_AppDesc.clear();
		resetApplication();
	}
	return true;
}

EnumStatusCode DrvOPCUAHistValues::SoftingApplication::AddSession(SoftingOPCToolbox5::Client::SessionPtr session)
{
	return  m_pApp->addSession(session);
}

EnumStatusCode DrvOPCUAHistValues::SoftingApplication::RemoveSession(SoftingOPCToolbox5::Client::SessionPtr session)
{
	return  m_pApp->removeSession(session);
}


EnumStatusCode DrvOPCUAHistValues::SoftingApplication::FindServers(const std::string& discoveryServerUrl, const std::vector<std::string>& serverURIs, std::vector<SoftingOPCToolbox5::ApplicationDescription>& serversList)
{
	return  m_pApp->findServers(discoveryServerUrl, serverURIs, serversList);
}


EnumStatusCode DrvOPCUAHistValues::SoftingApplication::GetEndpointsFromServer(const std::string& serverUrl, const std::vector<std::string>& transportProfiles, std::vector<SoftingOPCToolbox5::EndpointDescription>& endpointDescriptions)
{
	return m_pApp->getEndpointsFromServer(serverUrl, transportProfiles, endpointDescriptions);
}

void DrvOPCUAHistValues::SoftingApplication::sendErrorMessageToDelegates(std::string&& message)
{
	std::for_each(m_pOutputList.begin(), m_pOutputList.end(), [&](std::weak_ptr<SoftingApplicationOutput> ptr) {
		std::shared_ptr<SoftingApplicationOutput> output = ptr.lock();
		if (output) { output->SendMessageError(std::move(message)); }
		});
}


DrvOPCUAHistValues::SoftingApplication& DrvOPCUAHistValues::SoftingApplication::Instance()
{
	static SoftingApplication shared;
	return shared;
}
