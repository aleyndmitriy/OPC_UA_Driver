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

#ifndef USERIDENTITYTOKEN_H
#define USERIDENTITYTOKEN_H

#include "IUserIdentityToken.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

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
	class TBC_EXPORT UserIdentityToken
		: public IUserIdentityToken
	{
	public:
		/*! Default constructor */
		UserIdentityToken();
		/*! Constructs a copy of the given instance @p cp */
		UserIdentityToken(const IUserIdentityToken* cp);
		/*! @overload */
		UserIdentityToken(const IUserIdentityToken& cp);
		/*! @overload */
		UserIdentityToken(const UserIdentityToken& cp);

		/*! Destructor */
		virtual ~UserIdentityToken();

		/*! Assigns the contents of @p cp to this instance */
		UserIdentityToken& operator=(const IUserIdentityToken* cp);
		/*! @overload */
		UserIdentityToken& operator=(const IUserIdentityToken& cp);
		/*! @overload */
		UserIdentityToken& operator=(const UserIdentityToken& cp);

		/* see IUserIdentityToken::set */
		virtual EnumStatusCode set(const IUserIdentityToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IUserIdentityToken& pSrc);

		/* see IUserIdentityToken::compare */
		virtual int compare(const IUserIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IUserIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserIdentityToken& other) const;

		/* see IUserIdentityToken::getType */
		virtual EnumUserTokenType getType() const;

		/* see IUserIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;

		/* see IUserIdentityToken::getAnonymousIdentityToken */
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& token) const;
		/* see IUserIdentityToken::setAnonymousIdentityToken */
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pToken);
		/*! @overload */
		virtual EnumStatusCode setAnonymousIdentityToken(tstring policyId);

		/* see IUserIdentityToken::getUserNameIdentityToken */
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& token) const;
		/* see IUserIdentityToken::setUserNameIdentityToken */
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pToken);
		/*! @overload */
		virtual EnumStatusCode setUserNameIdentityToken(tstring policyId, tstring userName, IByteString* password);

		/* see IUserIdentityToken::getX509IdentityToken */
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& token) const;
		/* see IUserIdentityToken::setX509IdentityToken */
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pToken);
		/*! @overload */
		virtual EnumStatusCode setX509IdentityToken(tstring policyId, IByteString* certificate, tstring privateKeyFile, tstring privateKeyPassword);

		/* see IUserIdentityToken::getIssuedIdentityToken */
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& token) const;
		/* see IUserIdentityToken::setIssuedIdentityToken */
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pToken);
		/*! @overload */
		virtual EnumStatusCode setIssuedIdentityToken(tstring policyId, IByteString* tokenData);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		UserIdentityTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// USERIDENTITYTOKEN_H
