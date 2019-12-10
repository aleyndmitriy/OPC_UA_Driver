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

#ifndef IUSERTOKENPOLICY_H
#define IUSERTOKENPOLICY_H

#include "UserTokenPolicyStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The UserTokenPolicy data type is used by a server to specify a policy
	* for a UserIdentityToken that the server will accept.
	*
	* Each endpoint exposes a list of supported user token policies.
	* When connecting to a server the client has to specify the matching policy ID. */
	class TBC_EXPORT IUserTokenPolicy
	{
	public:
		/*! Destructor */
		virtual ~IUserTokenPolicy(){};

		/*! Returns the identifier for the UserTokenPolicy assigned by the server.
		*
		* @see setPolicyId() */
		virtual tstring getPolicyId() const = 0;
		/*! Returns the identifier for the UserTokenPolicy assigned by the server.
		*
		* The client specifies this value when it constructs a UserIdentityToken that
		* conforms to the policy. This value is only unique within the context of a
		* single server. */
		virtual void setPolicyId(const tstring& value) = 0;

		/*! Returns the type of the user identity token required. */
		virtual EnumUserTokenType getTokenType() const = 0;
		/*! Sets the type of user identity token required.
		* See enumeration type for available values. */
		virtual void setTokenType(const EnumUserTokenType& value) = 0;

		/*! Returns a URI for the type of the issued token. The URI identifies
		* a WS-Security profile.
		*
		* The result of this method is only defined if the token type is EnumUserTokenType_IssuedToken. */
		virtual tstring getIssuedTokenType() const = 0;
		/*! Sets the URI for the type of the issued token. The URI identifies a
		* WS-Security profile.
		*
		* This field may only be specified if TokenType is EnumUserTokenType_IssuedToken.
		* Vendors may specify their own token. */
		virtual void setIssuedTokenType(const tstring& value) = 0;

		/*! Returns the optional URL for the token issuing service.
		*
		* @see setIssuerEndpointUrl() */
		virtual tstring getIssuerEndpointUrl() const = 0;
		/*! Sets the optional URL for the token issuing service.
		* The meaning of this value depends on the type of the issued token.
		*
		* Kerberos tokens, for example, use the string "\\<realm>\<ServerPrincipalName>"
		* where &lt;realm&gt; is the Kerberos realm name (e.g. Windows Domain) and &lt;ServerPrincipalName&gt;
		* is the Kerberos principal name for the OPC UA server. */
		virtual void setIssuerEndpointUrl(const tstring& value) = 0;

		/*! Returns the security policy URI that defines the algorithms that are applied
		* for encrypting and signing a UserIdentityToken when the token is passed to a server
		* during session establishment.
		*
		* @see setSecurityPolicyUri() */
		virtual tstring getSecurityPolicyUri() const = 0;
		/*! Sets the security policy URI that defines the algorithms that are applied
		* for encrypting and signing a UserIdentityToken when the token is passed to a server
		* during session establishment.
		*
		* The security policy of the SecureChannel is used if this value is omitted. */
		virtual void setSecurityPolicyUri(const tstring& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IUserTokenPolicy* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IUserTokenPolicy& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserTokenPolicy* other) const = 0;
		/*! @overload */
		virtual int compare(const IUserTokenPolicy& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserTokenPolicy& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserTokenPolicy& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IUserTokenPolicy
} // end namespace

#endif	// IUSERTOKENPOLICY_H
