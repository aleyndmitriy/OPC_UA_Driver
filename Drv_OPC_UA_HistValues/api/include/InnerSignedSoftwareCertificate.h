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

#ifndef INNERSIGNEDSOFTWARECERTIFICATE_H
#define INNERSIGNEDSOFTWARECERTIFICATE_H

#include "ISignedSoftwareCertificate.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

namespace SoftingOPCToolbox5
{
	/*! A SignedSoftwareCertificate is a ByteString containing the DER encoded form of an X509v3 Certificate
	*
	* This Certificate is issued by a certifying authority and contains an X509v3
	* extension with the SoftwareCertificate which specifies the claims verified by the certifying
	* authority. The fields are defined completely in 346H RFC 3280. */
	class TBC_EXPORT InnerSignedSoftwareCertificate
		: public ISignedSoftwareCertificate
	{
	public:
		/*! Destructor */
		virtual ~InnerSignedSoftwareCertificate();

		virtual const IByteString* getCertificateData() const;
		virtual EnumStatusCode setCertificateData(const IByteString* value);
		virtual EnumStatusCode setCertificateData(const ByteString& value);

		virtual const IByteString* getSignature() const;
		virtual EnumStatusCode setSignature(const IByteString* value);
		virtual EnumStatusCode setSignature(const ByteString& value);

		/*! For internal use only */
		void initInner(SignedSoftwareCertificateStruct* pHandle);

		/*! @see ISignedSoftwareCertificate::set(const ISignedSoftwareCertificate*) */
		EnumStatusCode set(const ISignedSoftwareCertificate* pSrc);
		/*! @see ISignedSoftwareCertificate::set(const ISignedSoftwareCertificate&) */
		EnumStatusCode set(const ISignedSoftwareCertificate& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISignedSoftwareCertificate* other) const;
		/*! @overload */
		virtual int compare(const ISignedSoftwareCertificate& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISignedSoftwareCertificate& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISignedSoftwareCertificate& other) const;

		/*! @see ISignedSoftwareCertificate::getInternHandle() */
		virtual void* getInternHandle() const;

	private:
		InnerByteString m_certificateData;
		InnerByteString m_signature;

		SignedSoftwareCertificateStruct* m_pContent;
	};
} // end namespace

#endif	// INNERSIGNEDSOFTWARECERTIFICATE_H
