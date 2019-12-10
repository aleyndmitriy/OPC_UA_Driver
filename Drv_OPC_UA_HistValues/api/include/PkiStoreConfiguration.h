/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2019                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             dataFEED OPC UA C++ Server & Client SDK           *
*                                                                            *
* VERSION                  5.61.0                                            *
*                                                                            *
* DATE                     05.11.2019                                        *
*                                                                            *
*****************************************************************************/

#ifndef PKISTORECONFIGURATION_H
#define PKISTORECONFIGURATION_H

#include "IPkiStoreConfiguration.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class holds all the information that is required to verify client instance certificates.
	*
	* If a client opens a secure connection with the server (i.e. if the clients requests messages to be signed
	* and/or encrypted), the provided client instance certificate is validated.
	*
	* A certificate can be signed (issued) by another certificate. In general the issuer is a certificate authority (CA)
	* but for special use cases non-CA certificates can also sign other certificates.
	* Every issued certificate can be revoked by the signer, e.g. in case of a compromised private key.
	* Revoked certificates are stored in a Certificate Revocation List (CRL) and shall be rejected on validation.
	*
	* Root certificates are signed by themselves, they are named self-signed. Both self-signed and issued certificates
	* can be used as application instance certificate. In case of many instance certificates it might be easier to deploy
	* only the CA certificates (and their CRLs).
	*
	* General certificate handling:
	*
	* A client provides its application certificate via the Application::setInstanceCertificate method.
	* This certificate is used when connecting to a server.
	* The server validates the certificate in case of a secure connection:
	* @li The certificate must be a valid certificate (i.e. is conform to X509)
	* @li The certificate and all issuers up to the root are needed at server side to verify that the chain up to the root certificate is a valid chain.
	*     A valid chain does not necessary imply a trusted certificate, it just ensures that all certificates are really signed by the named issuer.
	*     In case of a self-signed certificate the issuer is the certificate itself, i.e. it is a root certificate.
	* @li In case of revocation list validation the certificate must not be revoked by its issuer.
	*     There are multiple options how revocation list validation can be performed. see EnumCrlCheckOption
	* @li Additionally the certificate (or one of its issuer) must be recognized as a trusted certificate.
	*
	* Validation strategies:
	*
	* @li The strategy supported by earlier dataFEED OPC UA C++ Server & Client SDK versions was to specify a list of trusted certificates only.
	*     In this list all trusted client certificates or the certificate of the issuer was stored, revocation list validation was not supported.
	*     To enabled this strategy the untrusted list can remain empty, the trusted list shall be added for chain validation and CRL validation shall be set to none.
	*     The check whether the certificate is in the trusted list can be skipped for performance reasons since only trusted certificates are added for chain validation.
	* @li Using the untrusted list for chain validation should imply the flag that one of the certificates in the chain must reside in the trusted list.
	*     Otherwise all certificates which pass the chain validation would be trusted.
	*     This strategy can be used if a global root certificate authority (CA) is used for signing certificates (or sub-CA).
	*     However it might be useful not trusting all other certificates signed by this global CA.
	* @li Certificate Revocation List (CRL) validation can be combined with any strategy.
	*     If a CRL validation of a specific certificate is performed the CRL of the issuer must be available, otherwise the validation fails. */
	class TBC_EXPORT PkiStoreConfiguration
		: public IPkiStoreConfiguration
	{
	public:
		/*! Default constructor */
		PkiStoreConfiguration();
		/*! Constructs a copy of the given instance */
		PkiStoreConfiguration(const IPkiStoreConfiguration*);
		/*! @overload */
		PkiStoreConfiguration(const IPkiStoreConfiguration&);
		/*! @overload */
		PkiStoreConfiguration(const PkiStoreConfiguration&);

		/*! Destructor */
		virtual ~PkiStoreConfiguration();

		/*! Assigns the contents of @p cp to this instance */
		PkiStoreConfiguration& operator=(const IPkiStoreConfiguration* cp);
		/*! @overload */
		PkiStoreConfiguration& operator=(const IPkiStoreConfiguration& cp);
		/*! @overload */
		PkiStoreConfiguration& operator=(const PkiStoreConfiguration& cp);

		/* see IPkiStoreConfiguration::set */
		virtual EnumStatusCode set(const IPkiStoreConfiguration* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPkiStoreConfiguration& pSrc);

		/* see IPkiStoreConfiguration::compare */
		virtual int compare(const IPkiStoreConfiguration*) const;
		/*! @overload */
		virtual int compare(const IPkiStoreConfiguration&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPkiStoreConfiguration& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPkiStoreConfiguration& other) const;

		/* see IPkiStoreConfiguration::getCertificateTrustListLocation */
		virtual tstring getCertificateTrustListLocation() const;
		/* see IPkiStoreConfiguration::setCertificateTrustListLocation */
		virtual void setCertificateTrustListLocation(const tstring& certificateTrustListLocation);

		/* see IPkiStoreConfiguration::getIssuerCertificateListLocation */
		virtual tstring getIssuerCertificateListLocation() const;
		/* see IPkiStoreConfiguration::setIssuerCertificateListLocation */
		virtual void setIssuerCertificateListLocation(const tstring& issuerListLocation);

		/* see IPkiStoreConfiguration::getCertificateRevocationListLocation */
		virtual tstring getCertificateRevocationListLocation() const;
		/* see IPkiStoreConfiguration::setCertificateRevocationListLocation */
		virtual void setCertificateRevocationListLocation(const tstring& certificateRevocationListLocation);

		/* see IPkiStoreConfiguration::getRejectedCertificateLocation */
		virtual tstring getRejectedCertificateLocation() const;
		/* see IPkiStoreConfiguration::setRejectedCertificateLocation */
		virtual void setRejectedCertificateLocation(const tstring& rejectedCertificateLocation);

		/* see IPkiStoreConfiguration::getSuppressedCertificateChecks */
		virtual EnumCertificateCheck getSuppressedCertificateChecks() const;
		/* see IPkiStoreConfiguration::setSuppressedCertificateChecks */
		virtual void setSuppressedCertificateChecks(EnumCertificateCheck suppressedCertificateChecks);

		/* see IPkiStoreConfiguration::getRevocationCheckOptions */
		virtual EnumCrlCheckOption getRevocationCheckOptions() const;
		/* see IPkiStoreConfiguration::setRevocationCheckOptions */
		virtual void setRevocationCheckOptions(EnumCrlCheckOption revocationCheckOptions);

		/* see IPkiStoreConfiguration::areProxyCertificatesAllowed */
		virtual bool areProxyCertificatesAllowed() const;
		/* see IPkiStoreConfiguration::allowProxyCertificates */
		virtual void allowProxyCertificates(bool allowProxies);

		/* see IPkiStoreConfiguration::isSelfSignedSignatureChecked */
		virtual bool isSelfSignedSignatureChecked() const;
		/* see IPkiStoreConfiguration::checkSelfSignedSignature */
		virtual void checkSelfSignedSignature(bool checkSignature);

		/* see IPkiStoreConfiguration::getEnableStrictKeyUsageCheck */
		virtual bool getEnableStrictKeyUsageCheck() const;
		/* see IPkiStoreConfiguration::setEnableStrictKeyUsageCheck */
		virtual void setEnableStrictKeyUsageCheck(bool strictKeyUsage);

		/* see IPkiStoreConfiguration::isUrlMatchChecked */
		virtual bool isUrlMatchChecked() const;
		/* see IPkiStoreConfiguration::checkUrlMatch */
		virtual void checkUrlMatch(bool checkMatch);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		PkiStoreConfigurationStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// PKISTORECONFIGURATION_H
