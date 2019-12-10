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

#ifndef USERTOKENPOLICY_H
#define USERTOKENPOLICY_H

#include "IUserTokenPolicy.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The UserTokenPolicy data type is used by a server to specify a policy
	* for a UserIdentityToken that the server will accept.
	*
	* Each endpoint exposes a list of supported user token policies.
	* When connecting to a server the client has to specify the matching policy ID. */
	class TBC_EXPORT UserTokenPolicy
		: public IUserTokenPolicy
	{
	public:
		/*! Default constructor */
		UserTokenPolicy();
		/*! Constructs a copy of the given instance @p cp */
		UserTokenPolicy(const IUserTokenPolicy* cp);
		/*! @overload */
		UserTokenPolicy(const IUserTokenPolicy& cp);
		/*! @overload */
		UserTokenPolicy(const UserTokenPolicy& cp);

		/*! Destructor */
		virtual ~UserTokenPolicy();

		/*! Assigns the contents of @p cp to this instance */
		UserTokenPolicy& operator=(const IUserTokenPolicy* cp);
		/*! @overload */
		UserTokenPolicy& operator=(const IUserTokenPolicy& cp);
		/*! @overload */
		UserTokenPolicy& operator=(const UserTokenPolicy& cp);

		/* see IUserTokenPolicy::set */
		virtual EnumStatusCode set(const IUserTokenPolicy* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IUserTokenPolicy& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IUserTokenPolicy* other) const;
		/*! @overload */
		virtual int compare(const IUserTokenPolicy& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IUserTokenPolicy& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IUserTokenPolicy& other) const;

		/* see IUserTokenPolicy::getPolicyId */
		virtual tstring getPolicyId() const;
		/* see IUserTokenPolicy::setPolicyId */
		virtual void setPolicyId(const tstring& value);

		/* see IUserTokenPolicy::getTokenType */
		virtual EnumUserTokenType getTokenType() const;
		/* see IUserTokenPolicy::setTokenType */
		virtual void setTokenType(const EnumUserTokenType& value);

		/* see IUserTokenPolicy::getIssuedTokenType */
		virtual tstring getIssuedTokenType() const;
		/* see IUserTokenPolicy::setIssuedTokenType */
		virtual void setIssuedTokenType(const tstring& value);

		/* see IUserTokenPolicy::getIssuerEndpointUrl */
		virtual tstring getIssuerEndpointUrl() const;
		/* see IUserTokenPolicy::setIssuerEndpointUrl */
		virtual void setIssuerEndpointUrl(const tstring& value);

		/* see IUserTokenPolicy::getSecurityPolicyUri */
		virtual tstring getSecurityPolicyUri() const;
		/* see IUserTokenPolicy::setSecurityPolicyUri */
		virtual void setSecurityPolicyUri(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		UserTokenPolicyStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// USERTOKENPOLICY_H
