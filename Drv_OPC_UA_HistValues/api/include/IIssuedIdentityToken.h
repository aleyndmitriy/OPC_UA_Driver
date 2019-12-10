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

#ifndef IISSUEDIDENTITYTOKEN_H
#define IISSUEDIDENTITYTOKEN_H

#include "IssuedIdentityTokenStruct.h"
#include "ByteString.h"
#include "IByteString.h"

namespace SoftingOPCToolbox5
{
	/*! The IssuedIdentityToken data type is used to pass WS-Security compliant security tokens to the server.
	*
	* WS-Security defines a number of token profiles that may be used to represent different types of security tokens.
	* For example, Kerberos and SAML tokens have WS-Security token profiles and shall be exchanged in OPC UA as XML Security Tokens.
	*
	* Please note that the WS-Security X509 and UserName tokens should not be exchanged as XML security tokens.
	* Instead, IUserNameIdentityToken and IX509IdentityToken shall be used for that purpose. */
	class TBC_EXPORT IIssuedIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~IIssuedIdentityToken(){};

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

		/*! Returns an XML representation of the token.
		*
		* @see setData */
		virtual const IByteString* getData() const = 0;
		/*! Set the XML representation of the token. The XML schema must conform
		* to one of the WS-Security token profiles.
		*
		* Please note that the WS-Security X509 and UserName tokens should not be exchanged as XML security tokens.
		* Instead, IUserNameIdentityToken and IX509IdentityToken shall be used for that purpose.
		*
		* @param value The XML representation of the token */
		virtual EnumStatusCode setData(const IByteString* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setData(const ByteString& value) = 0;

		/*! Returns a URI that identifies the encryption algorithm used for encrypting
		* and decrypting the token data.
		*
		* @see setEncryptionAlgorithm() */
		virtual tstring getEncryptionAlgorithm() const = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IIssuedIdentityToken* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IIssuedIdentityToken& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IIssuedIdentityToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IIssuedIdentityToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IIssuedIdentityToken& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IIssuedIdentityToken& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IIssuedIdentityToken
} // end namespace

#endif	// IISSUEDIDENTITYTOKEN_H
