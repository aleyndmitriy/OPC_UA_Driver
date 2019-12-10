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

#ifndef IPKISTORECONFIGURATION_H
#define IPKISTORECONFIGURATION_H

#include "PkiStoreConfigurationStruct.h"

namespace SoftingOPCToolbox5
{
	/*! This class holds all the information that is required to verify application instance certificates.
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
	* A OPC UA application provides its application certificate via the Application::setInstanceCertificate() method.
	*
	* If a client likes to connect to a server the server instance certificate is provided in its EndpointDescription @see Application::getEndpointsFromServer().
	* The client application can validate this certificate using the Application::validateCertificate() method.
	* The dataFEED OPC UA C++ Server & Client SDK performs no automatic validation.
	*
	* If a client opens a secure connection (Client::Session::connect()) with the server (i.e. if the clients requests messages to be signed
	* and/or encrypted), the provided client instance certificate is validated in the server automatically by the dataFEED OPC UA C++ Server & Client SDK @see Application::setPkiStoreConfiguration().
	*
	* The validation of a certificate is done in the following steps:
	* @li The certificate must be a valid certificate (i.e. is conform to X509)
	* @li The certificate and all issuers up to the root are necessary to verify that the chain up to the root certificate is a valid chain.
	*     A valid chain does not necessarily imply a trusted certificate, it just ensures that all certificates are really signed by the named issuer.
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
	class TBC_EXPORT IPkiStoreConfiguration
	{
	public:
		/*! Destructor */
		virtual ~IPkiStoreConfiguration(){};

		/*! Returns the path to the folder containing trusted client instance certificates.
		*
		* @see setCertificateTrustListLocation() */
		virtual tstring getCertificateTrustListLocation() const = 0;
		/*! Sets the path to the folder containing trusted client instance certificates
		* (or the certificate of an issuer in the certificate chain). */
		virtual void setCertificateTrustListLocation(const tstring& certificateTrustListLocation) = 0;

		/*! Returns the path to the folder containing certificates needed for validating a
		* certificate chain to the root certificate.
		*
		* @see setIssuerCertificateListLocation() */
		virtual tstring getIssuerCertificateListLocation() const = 0;
		/*! Sets the path to the folder containing certificates needed for validating a
		* certificate chain to the root certificate. The certificates (and other certificates
		* issued by those) are not automatically trusted. */
		virtual void setIssuerCertificateListLocation(const tstring& issuerListLocation) = 0;

		/*! Returns the path to the certificate revocation list.
		*
		* @see setCertificateRevocationListLocation() */
		virtual tstring getCertificateRevocationListLocation() const = 0;
		/*! Sets the path to the certificate revocation list. The path can be either
		* a specific file with suffix .crl or a folder containing those files.
		* This parameter can be an empty string if no CRL checks are specified.
		*
		* @note	The certificate revocation list is not consulted by default.
		*		Please see setRevocationCheckOptions() to enable CRL checks. */
		virtual void setCertificateRevocationListLocation(const tstring& certificateRevocationListLocation) = 0;

		/*! Returns the path to the folder where rejected client certificates will be stored.
		*
		* @see setRejectedCertificateLocation() */
		virtual tstring getRejectedCertificateLocation() const = 0;
		/*! Sets the path to the folder where rejected client certificates will be stored
		* This parameter can be an empty string (e.g. in case of read-only file systems).
		* Rejected certificates are not stored in this case. */
		virtual void setRejectedCertificateLocation(const tstring& rejectedCertificateLocation) = 0;

		/*! Returns the bit field that indicates which kind of validation checks are omitted. */
		virtual EnumCertificateCheck getSuppressedCertificateChecks() const = 0;
		/*! Sets the bit field that indicates which kind of validation checks are omitted.
		*
		* Default value is EnumCertificateCheck_All, i.e. no checks are suppressed. */
		virtual void setSuppressedCertificateChecks(EnumCertificateCheck checkOptions) = 0;

		/*! Returns how certificate revocation checks are performed. */
		virtual EnumCrlCheckOption getRevocationCheckOptions() const = 0;
		/*! Defines how certificate revocation checks are performed.
		*
		* Default value is EnumCrlCheckOption_None, i.e. the certificate revocation
		* list is ignored and not consulted in order to verify a certificate. */
		virtual void setRevocationCheckOptions(EnumCrlCheckOption revocationCheckOptions) = 0;

		/*! Returns whether proxy certificates are allowed.
		*
		* @see allowProxyCertificates() */
		virtual bool areProxyCertificatesAllowed() const = 0;

		/*! A proxy certificate is a certificate which is signed by a leaf certificate instead of an
		* Certificate Authority. Usually all certificates need to be signed by an Certificate Authority
		* or by itself (self signed), so proxy certificates are usually not allowed. In some cases, it
		* makes sense to allow to pass a proxy certificate as a representation of its original certificate.
		* One example is to give one another one's access rights for a very limited time by restricting
		* the validity period of the generated proxy certificate.
		* With this flag set to false the certificate chain validation will fail if such a proxy certificate
		* is within the chain. Allowing proxy certificates on the other hand might downgrade security.
		*
		* Default value is 'false'. */
		virtual void allowProxyCertificates(bool allowProxies) = 0;

		/*! Returns whether the signature of self-signed certificates shall be verified. */
		virtual bool isSelfSignedSignatureChecked() const = 0;
		/*! Defines whether the signature of self-signed certificates shall be verified.
		*
		* Default value is 'false'. */
		virtual void checkSelfSignedSignature(bool checkSignature) = 0;

		/*! Sets the flag, whether the key usage of a certificate shall be validated.
		*
		* The key usage is a field in the certificate which gives information about the usage of the certificate.
		* Typical values for OPC UA are
		* @li Digital Signature
		* @li Non-Repudiation
		* @li Encipherment
		* @li Data Encipherment
		* @li Certificate Signing
		* @li Off-line CRL Signing
		* @li CRL Signing (f6)
		*
		* Some of them can be omitted, e.g. "Certificate Signing" if the certificate is signed by a CA.
		*
		* Do not mix "Key Usage" with "Extended KEyx Usage", where typical values are
		* @li Serverauthentifizierung (1.3.6.1.5.5.7.3.1)
		* @li Clientauthentifizierung (1.3.6.1.5.5.7.3.2)
		*
		* Default value is false, i.e. key usage is not validated. */
		virtual void setEnableStrictKeyUsageCheck(bool strictKeyUsage) = 0;
		/*! @see setEnableStrictKeyUsageCheck */
		virtual bool getEnableStrictKeyUsageCheck() const = 0;

		/*! Returns whether the check of matching URI in certificate against URI in application description is performed. */
		virtual bool isUrlMatchChecked() const = 0;
		/*! Defines whether the check of matching URI in certificate against URI in application description is performed.
		*
		* Default value is 'false'. */
		virtual void checkUrlMatch(bool checkMatch) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IPkiStoreConfiguration* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IPkiStoreConfiguration& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IPkiStoreConfiguration* other) const = 0;
		/*! @overload */
		virtual int compare(const IPkiStoreConfiguration& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPkiStoreConfiguration& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPkiStoreConfiguration& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IPkiStoreConfiguration
} // end namespace

#endif	// IPKISTORECONFIGURATION_H
