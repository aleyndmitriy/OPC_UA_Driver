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

#ifndef INNERANONYMOUSIDENTITYTOKEN_H
#define INNERANONYMOUSIDENTITYTOKEN_H

#include "IAnonymousIdentityToken.h"

namespace SoftingOPCToolbox5
{
	/*! @copydoc IAnonymousIdentityToken */
	class TBC_EXPORT InnerAnonymousIdentityToken
		: public IAnonymousIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~InnerAnonymousIdentityToken();

		virtual tstring getPolicyId() const;
		virtual void setPolicyId(const tstring& value);

		/*! For internal use only */
		void initInner(AnonymousIdentityTokenStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAnonymousIdentityToken* other) const;
		/*! @overload */
		virtual int compare(const IAnonymousIdentityToken& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAnonymousIdentityToken& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAnonymousIdentityToken& other) const;

		/*! @see IAnonymousIdentityToken::set(const IAnonymousIdentityToken*) */
		EnumStatusCode set(const IAnonymousIdentityToken* pSrc);
		/*! @see IAnonymousIdentityToken::set(const IAnonymousIdentityToken&) */
		EnumStatusCode set(const IAnonymousIdentityToken& pSrc);

		/*! @see IAnonymousIdentityToken::getInternHandle() */
		virtual void* getInternHandle() const;

	private:

		AnonymousIdentityTokenStruct* m_pContent;
	};
} // end namespace

#endif	// INNERANONYMOUSIDENTITYTOKEN_H
