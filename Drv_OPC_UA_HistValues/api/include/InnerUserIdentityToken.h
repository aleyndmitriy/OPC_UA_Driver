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

#ifndef INNERUSERIDENTITYTOKEN_H
#define INNERUSERIDENTITYTOKEN_H

#include "IUserIdentityToken.h"

namespace SoftingOPCToolbox5
{
	/*! Structure that stores UserIdentityToken for embedded structures
	*
	* The UserIdentityToken contains the credentials of the user associated with the Client application.
	*
	* The Server uses these credentials to determine whether the Client should be
	* allowed to activate a Session and what resources the Client has access to during this Session.
	*
	* The identity token can be
	* @li AnonymousIdentityToken
	* @li UserNameIdentityToken
	* @li X509IdentityToken
	* @li IssuedIdentityToken */
	class TBC_EXPORT InnerUserIdentityToken
		: public IUserIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~InnerUserIdentityToken();

		/*! Returns the actual type of the identity token */
		virtual EnumUserTokenType getType() const;

		/*! Returns the actual policyId of the specific token */
		virtual tstring getPolicyId() const;

		/*! @see setAnonymousIdentityToken */
		virtual EnumStatusCode getAnonymousIdentityToken(AnonymousIdentityToken& token) const;
		/*! Set identity token to anonymous
		*
		*  @see AnonymousIdentityToken */
		virtual EnumStatusCode setAnonymousIdentityToken(const IAnonymousIdentityToken* pToken);

		/*! @see setUserNameIdentityToken */
		virtual EnumStatusCode getUserNameIdentityToken(UserNameIdentityToken& token) const;
		/*! Set identity token to user name
		*
		*  @see UserNameIdentityToken */
		virtual EnumStatusCode setUserNameIdentityToken(const IUserNameIdentityToken* pToken);

		/*! @see setX509IdentityToken */
		virtual EnumStatusCode getX509IdentityToken(X509IdentityToken& token) const;
		/*! Set identity token to anonymous
		*
		*  @see X509IdentityToken */
		virtual EnumStatusCode setX509IdentityToken(const IX509IdentityToken* pToken);

		/*! @see setIssuedIdentityToken */
		virtual EnumStatusCode getIssuedIdentityToken(IssuedIdentityToken& token) const;
		/*! Set identity token issued token
		*
		*  @see IssuedIdentityToken */
		virtual EnumStatusCode setIssuedIdentityToken(const IIssuedIdentityToken* pToken);

		/*! For internal use only */
		void initInner(UserIdentityTokenStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IUserIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserIdentityToken& other) const;

		/*! @see IUserIdentityToken::set(const IUserIdentityToken*) */
		EnumStatusCode set(const IUserIdentityToken* pSrc);
		/*! @see IUserIdentityToken::set(const IUserIdentityToken&) */
		EnumStatusCode set(const IUserIdentityToken& pSrc);

		/*! @see IUserIdentityToken::getInternHandle() */
		virtual void* getInternHandle() const;

	private:

		UserIdentityTokenStruct* m_pContent;
	};
} // end namespace

#endif	// INNERUSERIDENTITYTOKEN_H
