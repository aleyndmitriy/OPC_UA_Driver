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

#ifndef SIGNEDSOFTWARECERTIFICATE_H
#define SIGNEDSOFTWARECERTIFICATE_H

#include "ISignedSoftwareCertificate.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SignedSoftwareCertificate data type contains the DER encoded form of an X509v3 certificate
	* and a signature generated with the private key associated with the certificate.
	*
	* The certificate is issued by a certifying authority and contains an X509v3 extension with the
	* SoftwareCertificate which specifies the claims verified by the certifying authority. */
	class TBC_EXPORT SignedSoftwareCertificate
		: public ISignedSoftwareCertificate
	{
	public:
		/*! Default constructor */
		SignedSoftwareCertificate();
		/*! Constructs a copy of the given instance @p cp */
		SignedSoftwareCertificate(const ISignedSoftwareCertificate* cp);
		/*! @overload */
		SignedSoftwareCertificate(const ISignedSoftwareCertificate& cp);
		/*! @overload */
		SignedSoftwareCertificate(const SignedSoftwareCertificate& cp);

		/*! Destructor */
		virtual ~SignedSoftwareCertificate();

		/*! Assigns the contents of @p cp to this instance */
		SignedSoftwareCertificate& operator=(const ISignedSoftwareCertificate* cp);
		/*! @overload */
		SignedSoftwareCertificate& operator=(const ISignedSoftwareCertificate& cp);
		/*! @overload */
		SignedSoftwareCertificate& operator=(const SignedSoftwareCertificate& cp);

		/* see ISignedSoftwareCertificate::set */
		virtual EnumStatusCode set(const ISignedSoftwareCertificate* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISignedSoftwareCertificate& pSrc);

		/* see ISignedSoftwareCertificate::compare */
		virtual int compare(const ISignedSoftwareCertificate* other) const;
		/*! @overload */
		virtual int compare(const ISignedSoftwareCertificate& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISignedSoftwareCertificate& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISignedSoftwareCertificate& other) const;

		/* see ISignedSoftwareCertificate::getCertificateData */
		virtual const IByteString* getCertificateData() const;
		/* see ISignedSoftwareCertificate::setCertificateData */
		virtual EnumStatusCode setCertificateData(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setCertificateData(const ByteString& value);

		/* see ISignedSoftwareCertificate::getSignature */
		virtual const IByteString* getSignature() const;
		/* see ISignedSoftwareCertificate::setSignature */
		virtual EnumStatusCode setSignature(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setSignature(const ByteString& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_certificateData;
		InnerByteString m_signature;

		SignedSoftwareCertificateStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SIGNEDSOFTWARECERTIFICATE_H
