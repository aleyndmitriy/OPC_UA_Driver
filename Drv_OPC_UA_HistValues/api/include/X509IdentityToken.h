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

#ifndef X509IDENTITYTOKEN_H
#define X509IDENTITYTOKEN_H

#include "IX509IdentityToken.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The X509IdentityToken data type is used to pass an X509v3 certificate which is issued by the user.
	*
	* UA defines various tokens for user identification. This one is using a certificate for authorization. */
	class TBC_EXPORT X509IdentityToken
		: public IX509IdentityToken
	{
	public:
		/*! Default constructor */
		X509IdentityToken();
		/*! Constructs a copy of the given instance @p cp */
		X509IdentityToken(const IX509IdentityToken* cp);
		/*! @overload */
		X509IdentityToken(const IX509IdentityToken& cp);
		/*! @overload */
		X509IdentityToken(const X509IdentityToken& cp);

		/*! Destructor */
		virtual ~X509IdentityToken();

		/*! Assigns the contents of @p cp to this instance */
		X509IdentityToken& operator=(const IX509IdentityToken* cp);
		/*! @overload */
		X509IdentityToken& operator=(const IX509IdentityToken& cp);
		/*! @overload */
		X509IdentityToken& operator=(const X509IdentityToken& cp);

		/* see IX509IdentityToken::set */
		virtual EnumStatusCode set(const IX509IdentityToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IX509IdentityToken& pSrc);

		/* see IX509IdentityToken::compare */
		virtual int compare(const IX509IdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IX509IdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IX509IdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IX509IdentityToken& other) const;

		/* see IX509IdentityToken::getCertificate */
		virtual const IByteString* getCertificate() const;
		/* see IX509IdentityToken::setCertificate */
		virtual EnumStatusCode setCertificate(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setCertificate(const ByteString& value);

		/*! @see IX509IdentityToken::loadPrivateKey */
		virtual EnumStatusCode loadPrivateKey(const tstring& privateKeyFile, const tstring& password);

		/* see IX509IdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IX509IdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_certificate;

		X509IdentityTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// X509IDENTITYTOKEN_H
