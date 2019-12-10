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

#ifndef INNERUSERNAMEIDENTITYTOKEN_H
#define INNERUSERNAMEIDENTITYTOKEN_H

#include "IUserNameIdentityToken.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

namespace SoftingOPCToolbox5
{
	/*! Structure that stores UserNameIdentityToken in case of embedded structure
	*
	* UA defines various tokens for user identification.
	* This one is using a user name and a password for identification.
	*
	* The password is transported encrypted to avoid a "man in the middle" to see the password. */
	class TBC_EXPORT InnerUserNameIdentityToken
		: public IUserNameIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~InnerUserNameIdentityToken();

		/*! @see IUserNameIdentityToken::getUserName */
		virtual tstring getUserName() const;
		/*! @see IUserNameIdentityToken::setUserName */
		virtual void setUserName(const tstring& value);

		/*! @see IUserNameIdentityToken::getPassword */
		virtual const IByteString* getPassword() const;
		/*! @see IUserNameIdentityToken::setPassword */
		virtual EnumStatusCode setPassword(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setPassword(const ByteString& value);

		/*! @see IUserNameIdentityToken::getEncryptionAlgorithm */
		virtual tstring getEncryptionAlgorithm() const;

		/*! @see IUserNameIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/*! @see IUserNameIdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/*! For internal use only */
		void initInner(UserNameIdentityTokenStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserNameIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IUserNameIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserNameIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserNameIdentityToken& other) const;

		/*! @see IUserNameIdentityToken::set(const IUserNameIdentityToken*) */
		EnumStatusCode set(const IUserNameIdentityToken* pSrc);
		/*! @see IUserNameIdentityToken::set(const IUserNameIdentityToken&) */
		EnumStatusCode set(const IUserNameIdentityToken& pSrc);

		/*! @see IUserNameIdentityToken::getInternHandle() */
		virtual void* getInternHandle() const;

	private:
		InnerByteString m_password;

		UserNameIdentityTokenStruct* m_pContent;
	};
} // end namespace

#endif	// INNERUSERNAMEIDENTITYTOKEN_H
