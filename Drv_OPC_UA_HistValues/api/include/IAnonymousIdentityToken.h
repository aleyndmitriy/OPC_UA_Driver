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

#ifndef IANONYMOUSIDENTITYTOKEN_H
#define IANONYMOUSIDENTITYTOKEN_H

#include "AnonymousIdentityTokenStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The AnonymousIdentityToken is used to indicate that the client has no user credentials.
	* OPC UA defines various tokens for user identification. This one is using no identification. */
	class TBC_EXPORT IAnonymousIdentityToken
	{
	public:
		/*! Destructor */
		virtual ~IAnonymousIdentityToken(){};

		/*! Returns the policy identifier for this user identity token.
		* @see setPolicyId */
		virtual tstring getPolicyId() const = 0;
		/*! Sets the policy identifier for this user identity token.
		*
		* The policyId is an identifier, specified by the user identities returned from server during getEndpoints() call.
		* This value is only unique within the context of a single server.
		*
		* @param value An identifier for the UserTokenPolicy that the token conforms to */
		virtual void setPolicyId(const tstring& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IAnonymousIdentityToken* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IAnonymousIdentityToken& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAnonymousIdentityToken* other) const = 0;
		/*! @overload */
		virtual int compare(const IAnonymousIdentityToken& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAnonymousIdentityToken& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAnonymousIdentityToken& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IAnonymousIdentityToken
} // end namespace

#endif	// IANONYMOUSIDENTITYTOKEN_H
