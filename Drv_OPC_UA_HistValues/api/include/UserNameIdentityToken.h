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

#ifndef USERNAMEIDENTITYTOKEN_H
#define USERNAMEIDENTITYTOKEN_H

#include "IUserNameIdentityToken.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The UserNameIdentityToken data type is used to pass username/password credentials to the server.
	*
	* UA defines various tokens for user identification. This one is using a user name
	* and a password for identification.
	*
	* The password is transported encrypted to avoid a "man in the middle" seeing the password. */
	class TBC_EXPORT UserNameIdentityToken
		: public IUserNameIdentityToken
	{
	public:
		/*! Default constructor */
		UserNameIdentityToken();
		/*! Constructs a copy of the given instance @p cp */
		UserNameIdentityToken(const IUserNameIdentityToken* cp);
		/*! @overload */
		UserNameIdentityToken(const IUserNameIdentityToken& cp);
		/*! @overload */
		UserNameIdentityToken(const UserNameIdentityToken& cp);

		/*! Destructor */
		virtual ~UserNameIdentityToken();

		/*! Assigns the contents of @p cp to this instance */
		UserNameIdentityToken& operator=(const IUserNameIdentityToken* cp);
		/*! @overload */
		UserNameIdentityToken& operator=(const IUserNameIdentityToken& cp);
		/*! @overload */
		UserNameIdentityToken& operator=(const UserNameIdentityToken& cp);

		/* see IUserNameIdentityToken::set */
		virtual EnumStatusCode set(const IUserNameIdentityToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IUserNameIdentityToken& pSrc);

		/* see IUserNameIdentityToken::compare */
		virtual int compare(const IUserNameIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IUserNameIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserNameIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserNameIdentityToken& other) const;

		/* see IUserNameIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IUserNameIdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/* see IUserNameIdentityToken::getUserName */
		virtual tstring getUserName() const;
		/* see IUserNameIdentityToken::setUserName */
		virtual void setUserName(const tstring& value);

		/* see IUserNameIdentityToken::getPassword */
		virtual const IByteString* getPassword() const;
		/* see IUserNameIdentityToken::setPassword */
		virtual EnumStatusCode setPassword(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setPassword(const ByteString& value);

		/* see IUserNameIdentityToken::getEncryptionAlgorithm */
		virtual tstring getEncryptionAlgorithm() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_password;

		UserNameIdentityTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// USERNAMEIDENTITYTOKEN_H
