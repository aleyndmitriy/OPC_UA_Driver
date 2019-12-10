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

#ifndef IX509IDENTITYTOKEN_H
#define IX509IDENTITYTOKEN_H

#include "X509IdentityTokenStruct.h"
#include "ByteString.h"
#include "IByteString.h"

namespace SoftingOPCToolbox5
{
	/*! The X509IdentityToken data type is used to pass an X509v3 certificate which issued by the user.
	*
	* UA defines various tokens for user identification. This one is using a certificate for authorization. */
	class TBC_EXPORT IX509IdentityToken
	{
	public:
		/*! Destructor */
		virtual ~IX509IdentityToken(){};

		/*! Returns the identifier for the UserTokenPolicy that the token conforms to.
		*
		* @see setPolicyId() */
		virtual tstring getPolicyId() const = 0;
		/*! Sets the identifier for the UserTokenPolicy that the token conforms to.
		*
		* The PolicyId is an identifier, specified by the user identities returned from server
		* during GetEndpoints service call (see Application::getEndpointsFromServer()).
		* This value is only unique within the context of a single server. */
		virtual void setPolicyId(const tstring& value) = 0;

		/*! Returns the X509 certificate (in DER format) that is used for authorization. */
		virtual const IByteString* getCertificate() const = 0;
		/*! Set the X509 certificate (in DER format) that is used for authorization.
		*
		* @param value The certificate as byte string */
		virtual EnumStatusCode setCertificate(const IByteString* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setCertificate(const ByteString& value) = 0;

		/*! Loads the X509 private key of the certificate from a file.
		*
		* @param privateKeyFile	The file containing the private key (in PEM format)
		* @param password		The pass phrase that was used to protect the private key */
		virtual EnumStatusCode loadPrivateKey(const tstring& privateKeyFile, const tstring& password) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IX509IdentityToken* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IX509IdentityToken& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IX509IdentityToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IX509IdentityToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IX509IdentityToken& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IX509IdentityToken& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IX509IdentityToken
} // end namespace

#endif	// IX509IDENTITYTOKEN_H
