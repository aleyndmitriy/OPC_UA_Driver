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

#ifndef INNERISSUEDIDENTITYTOKEN_H
#define INNERISSUEDIDENTITYTOKEN_H

#include "IIssuedIdentityToken.h"
#include "ByteString.h"
#include "IByteString.h"
#include "InnerByteString.h"

namespace SoftingOPCToolbox5
{
	/*! Structure that stores IssuedIdentityToken in case of embedded structure
	*
	* UA defines various tokens for user identification.
	* This one is used to pass WS-Security compliant SecurityTokens. */
	class TBC_EXPORT InnerIssuedIdentityToken
		: public IIssuedIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~InnerIssuedIdentityToken();

		/*! @see IIssuedIdentityToken::getData */
		virtual const IByteString* getData() const;
		/*! @see IIssuedIdentityToken::setData */
		virtual EnumStatusCode setData(const IByteString* value);
		/*! @overload */
		virtual EnumStatusCode setData(const ByteString& value);

		/*! @see IIssuedIdentityToken::getEncryptionAlgorithm */
		virtual tstring getEncryptionAlgorithm() const;

		/*! @see IIssuedIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/*! @see IIssuedIdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/*! For internal use only */
		void initInner(IssuedIdentityTokenStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IIssuedIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IIssuedIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IIssuedIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IIssuedIdentityToken& other) const;

		/*! @see IIssuedIdentityToken::set(const IIssuedIdentityToken*) */
		EnumStatusCode set(const IIssuedIdentityToken* pSrc);
		/*! @see IIssuedIdentityToken::set(const IIssuedIdentityToken&) */
		EnumStatusCode set(const IIssuedIdentityToken& pSrc);

		/*! @see IIssuedIdentityToken::getInternHandle() */
		virtual void* getInternHandle() const;

	private:
		InnerByteString m_tokenData;

		IssuedIdentityTokenStruct* m_pContent;
	};
} // end namespace

#endif	// INNERISSUEDIDENTITYTOKEN_H
