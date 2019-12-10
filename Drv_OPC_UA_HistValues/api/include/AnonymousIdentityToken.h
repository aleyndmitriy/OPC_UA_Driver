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

#ifndef ANONYMOUSIDENTITYTOKEN_H
#define ANONYMOUSIDENTITYTOKEN_H

#include "IAnonymousIdentityToken.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The AnonymousIdentityToken is used to indicate that the client has no user credentials.
	* OPC UA defines various tokens for user identification. This one is using no identification. */
	class TBC_EXPORT AnonymousIdentityToken
		: public IAnonymousIdentityToken
	{
	public:
		/*! Default constructor */
		AnonymousIdentityToken();
		/*! Constructs a copy of the given instance @p cp */
		AnonymousIdentityToken(const IAnonymousIdentityToken* cp);
		/*! @overload */
		AnonymousIdentityToken(const IAnonymousIdentityToken& cp);
		/*! @overload */
		AnonymousIdentityToken(const AnonymousIdentityToken& cp);

		/*! Destructor */
		virtual ~AnonymousIdentityToken();

		/*! Assigns the contents of @p cp to this instance */
		AnonymousIdentityToken& operator=(const IAnonymousIdentityToken* cp);
		/*! @overload */
		AnonymousIdentityToken& operator=(const IAnonymousIdentityToken& cp);
		/*! @overload */
		AnonymousIdentityToken& operator=(const AnonymousIdentityToken& cp);

		/* see IAnonymousIdentityToken::set */
		virtual EnumStatusCode set(const IAnonymousIdentityToken* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IAnonymousIdentityToken& pSrc);

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

		/* see IAnonymousIdentityToken::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IAnonymousIdentityToken::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		AnonymousIdentityTokenStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ANONYMOUSIDENTITYTOKEN_H
