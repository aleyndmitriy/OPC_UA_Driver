#include"pch.h"
#include"Log.h"
#include <stdio.h>
#include <OdsErr.h>
#include <String/OdsStringUtils.h>

namespace DrvOPCUAHistValues
{

	static const TCHAR MODULE_NAME_PREFIX[] = _T("ODBC HDA TAGS| ");

	Log* Log::m_pInstance = 0;

	struct Log::LogBody
	{
		LogBody();

		ODS::System::ILog* m_pILog;
	};

	Log::LogBody::LogBody()
	{
		m_pILog = 0;
	}

	Log::Log()
	{
		m_pBody = new LogBody;
	}

	Log::~Log()
	{
		delete m_pBody;
	}

	Log* Log::GetInstance()
	{
		if (!m_pInstance)
			m_pInstance = new Log;

		return m_pInstance;
	}

	void Log::Init(ODS::System::ILog* pILog)
	{
		m_pBody->m_pILog = pILog;
	}

	void Log::WriteImpl(int nLevel, int nMsgType, const TCHAR* szFormat, va_list argList)
	{
		if (!m_pBody->m_pILog)
			return;

		ODS::OdsString msgPrefix = MODULE_NAME_PREFIX;

		ODS::OdsString msg;

		ODS::OdsStringUtils::FormatOdsStringFromArgList(szFormat, argList, &msg);

		msgPrefix += msg;

		m_pBody->m_pILog->Write(nLevel, nMsgType, _T("%s"), msgPrefix.GetBuffer());
	}

	void Log::WriteInfo(const TCHAR* szFormat, ...)
	{
		if (!m_pBody->m_pILog)
			return;

		va_list argList;
		va_start(argList, szFormat);

		WriteImpl(ODS::System::ILog::Level::LOG_NORMAL, ODS::System::ILog::MsgType::INFO, szFormat, argList);

		va_end(argList);
	}

	void Log::WriteInfoDebug(const TCHAR* szFormat, ...)
	{
		if (!m_pBody->m_pILog)
			return;

		va_list argList;
		va_start(argList, szFormat);

		WriteImpl(ODS::System::ILog::Level::LOG_DEBUG, ODS::System::ILog::MsgType::INFO, szFormat, argList);

		va_end(argList);
	}

	void Log::WriteError(const TCHAR* szFormat, ...)
	{
		if (!m_pBody->m_pILog)
			return;

		va_list argList;
		va_start(argList, szFormat);

		WriteImpl(ODS::System::ILog::Level::LOG_NORMAL, ODS::System::ILog::MsgType::ERR, szFormat, argList);

		va_end(argList);
	}

	void Log::WriteErrorDebug(const TCHAR* szFormat, ...)
	{
		if (!m_pBody->m_pILog)
			return;

		va_list argList;
		va_start(argList, szFormat);

		WriteImpl(ODS::System::ILog::Level::LOG_DEBUG, ODS::System::ILog::MsgType::ERR, szFormat, argList);

		va_end(argList);
	}

} // namespace