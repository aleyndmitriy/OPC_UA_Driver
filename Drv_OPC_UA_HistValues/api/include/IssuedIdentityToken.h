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

#ifndef ISSUEDIDENTITYTOKEN_H
#define ISSUEDIDENTITYTOKEN_H

#include "IIssuedIdentityToken.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The IssuedIdentityToken data type is used to pass WS-Security compliant security tokens to the server.
	*
	* WS-Security defines a number of token profiles that may be used to represent different types of security tokens.
	* For example, Kerberos and SAML tokens have WS-Security token profiles and shall be exchanged in OPC UA as XML Security Tokens.
	*
	* Please note that the WS-Security X509 and UserName tokens should not be exchanged as XML security tokens.
	* Instead, IUserNameIdentityToken and IX509IdentityToken shall be used for that purpose. */
	class TBC_EXPORT IssuedIdentityToken
		: public IIssuedIdentityToken
	{
	public:
		/*! Default constructor */
		IssuedIdentityToken();
		/*! Constructs a copy of the given instance @p cp */
		IssuedIdentityToken(const IIssuedIdentityToken* cp);
		/*! @overload */
		IssuedIdentityToken(const IIssuedIdentityToken& cp);
		/*! @overload */
		IssuedIdentityToken(const IssuedIdentityToken& cp);

		/*! Destructor */
		virtual ~IssuedIdentityToken();

		/*! Assigns the contents of @p cp to this instance */
		IssuedIdentityToken& operator=(const IIssuedIdentityToken* cp);
		/*! @overload */
		IssuedIdentityToken& operator=(const IIssuedIdentityToken& cp);
		/*! @overload */
		IssuedIdentityToken& operator=(const IssuedIdentityToken& cp);

		/* see IIssuedIdentityToken::set */
		virtual EnumStatusCode set(const IIssuedIdentityToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IIssuedIdentityToken& pSrc);

		/* see IIssuedIdentityToken::compare */
		virtual int compare(const IIssuedIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IIssuedIdentityToken& other) const;
		/*! @overload */
		virtual int compare(const IssuedIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IIssuedIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IIssuedIdentityToken& other) const;

		/* see IIssuedIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IIssuedIdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/* see IIssuedIdentityToken::getData */
		virtual const IByteString* getData() const;
		/* see IIssuedIdentityToken::setData */
		virtual EnumStatusCode setData(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setData(const ByteString& value);

		/* see IIssuedIdentityToken::getEncryptionAlgorithm */
		virtual tstring getEncryptionAlgorithm() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_tokenData;

		IssuedIdentityTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ISSUEDIDENTITYTOKEN_H
