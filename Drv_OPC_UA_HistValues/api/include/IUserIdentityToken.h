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

#ifndef IUSERIDENTITYTOKEN_H
#define IUSERIDENTITYTOKEN_H

#include "UserIdentityTokenStruct.h"
#include "AnonymousIdentityToken.h"
#include "UserNameIdentityToken.h"
#include "X509IdentityToken.h"
#include "IssuedIdentityToken.h"

namespace SoftingOPCToolbox5
{
	/*! The UserIdentityToken data type allows clients to specify the identity of the user
	* they are acting on behalf of. The UserIdentityToken contains the credentials of the
	* user associated with the client application.
	*
	* The server uses these credentials to determine whether the client should be
	* allowed to activate a Session and what resources the client may access during this session.
	*
	* OPC UA defines the following types of identity tokens:
	* @li IAnonymousIdentityToken for anonymous authentication
	* @li IUserNameIdentityToken for username/password authentication
	* @li IX509IdentityToken for certificate-based authentication
	* @li IIssuedIdentityToken for authentication based on issued tokens (such as Kerberos tokens) */
	class TBC_EXPORT IUserIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~IUserIdentityToken(){};

		/*! Returns the actual type of the identity token. */
		virtual EnumUserTokenType getType() const = 0;

		/*! Returns the an identifier for the UserTokenPolicy that the token conforms to.
		* The policy identifier is server-specific. */
		virtual tstring getPolicyId() const = 0;

		/*! Returns the AnonymousIdentityToken. If this token is not an AnonymousIdentityToken,
		* this method returns a bad status code.
		*
		* @see setAnonymousIdentityToken() */
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& token) const = 0;
		/*! Indicates that the client authenticates with anonymous identity.
		*
		* @see AnonymousIdentityToken */
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pToken) = 0;

		/*! Returns the UserNameIdentityToken. If this token is not an UserNameIdentityToken,
		* this method returns a bad status code.
		*
		* @see setUserNameIdentityToken() */
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& token) const = 0;
		/*! Indicates that the client authenticates with username/password.
		* The provided token contains the credentials required for authentication.
		*
		* @see IUserNameIdentityToken */
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pToken) = 0;

		/*! Returns the X509IdentityToken. If this token is not an X509IdentityToken,
		* this method returns a bad status code.
		*
		* @see setX509IdentityToken() */
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& token) const = 0;
		/*! Indicates that the client authenticates with an X509 certificate.
		* The provided token contains the certificate that is used for authentication.
		*
		* @see IX509IdentityToken */
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pToken) = 0;

		/*! Returns the IssuedIdentityToken. If this token is not an IssuedIdentityToken,
		* this method returns a bad status code.
		*
		* @see setIssuedIdentityToken() */
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& token) const = 0;
		/*! Indicates that the client authenticates with an issued token (such as Kerberos).
		* The provided token contains the issued token that is used for authentication as ByteString.
		*
		* @see IIssuedIdentityToken */
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pToken) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IUserIdentityToken* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IUserIdentityToken& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserIdentityToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IUserIdentityToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserIdentityToken& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserIdentityToken& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IUserIdentityToken
} // end namespace

#endif	// IUSERIDENTITYTOKEN_H
