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

#ifndef ISIGNEDSOFTWARECERTIFICATE_H
#define ISIGNEDSOFTWARECERTIFICATE_H

#include "SignedSoftwareCertificateStruct.h"
#include "ByteString.h"
#include "IByteString.h"

namespace SoftingOPCToolbox5
{
	/*! The SignedSoftwareCertificate data type contains the DER encoded form of an X509v3 certificate
	* and a signature generated with the private key associated with the certificate.
	*
	* The certificate is issued by a certifying authority and contains an X509v3 extension with the
	* SoftwareCertificate which specifies the claims verified by the certifying authority. */
	class TBC_EXPORT ISignedSoftwareCertificate
	{
	public:
		/*! Destructor */
		virtual ~ISignedSoftwareCertificate(){};

		/*! Returns the DER encoded certificate. */
		virtual const IByteString* getCertificateData() const = 0;
		/*! Sets the certificate
		*
		* @param value The DER encoded certificate */
		virtual EnumStatusCode setCertificateData(const IByteString* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCertificateData(const ByteString& value) = 0;

		/*! Returns the signature that was created with the private key
		* associated with the certificate. */
		virtual const IByteString* getSignature() const = 0;
		/*! Sets the signature data that was created with the private key
		* associated with the certificate.
		*
		* @param value The DER encoded certificate */
		virtual EnumStatusCode setSignature(const IByteString* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setSignature(const ByteString& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const ISignedSoftwareCertificate* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ISignedSoftwareCertificate& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISignedSoftwareCertificate* other) const = 0;
		/*! @overload */
		virtual int compare(const ISignedSoftwareCertificate& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISignedSoftwareCertificate& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISignedSoftwareCertificate& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ISignedSoftwareCertificate
} // end namespace

#endif	// ISIGNEDSOFTWARECERTIFICATE_H
