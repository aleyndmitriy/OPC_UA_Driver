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

#ifndef IENDPOINTDESCRIPTION_H
#define IENDPOINTDESCRIPTION_H

#include "EndpointDescriptionStruct.h"
#include "InnerApplicationDescription.h"
#include "ApplicationDescription.h"
#include "InnerUserTokenPolicy.h"
#include "UserTokenPolicy.h"

namespace SoftingOPCToolbox5
{
	/*! The EndpointDescription data type describes the endpoint for a server
	* and is returned by the GetEndpoints service (see Application::getEndpointsFromServer()).
	*
	* An EndpointDescription contains all information a client needs to establish
	* a session with the server. */
	class TBC_EXPORT IEndpointDescription
	{
	public:
		/*! Destructor */
		virtual ~IEndpointDescription(){};

		/*! Returns the URL of the described endpoint.
		* Clients may use this URL to connect to the endpoint of the server. */
		virtual tstring getEndpointUrl() const = 0;

		/*! Returns a description for the server that the endpoint belongs to. */
		virtual const IApplicationDescription* getServer() const = 0;
		/*! @overload */
		virtual IApplicationDescription* getServer() = 0;

		/*! Returns the application instance certificate issued to the server. */
		virtual ByteString getServerCertificate() const = 0;

		/*! Returns the type of security that is applied to messages exchanged between the
		* client and the server.
		*
		* @see EnumMessageSecurityMode */
		virtual EnumMessageSecurityMode getMessageSecurityMode() const = 0;

		/*! Returns The URI for the SecurityPolicy to use when securing messages.
		*
		* The following constants are defined as convenience for the security policy URIs
		* defined by the OPC UA specifications:
		* @li	SecurityPolicyUri_None
		* @li	SecurityPolicyUri_Basic128Rsa15 (deprecated - shall no longer be used)
		* @li	SecurityPolicyUri_Basic256 (deprecated - shall no longer be used)
		* @li	SecurityPolicyUri_Basic256Sha256
		* @li	SecurityPolicyUri_Aes128Sha256RsaOaep
		* @li	SecurityPolicyUri_Aes256Sha256RsaPss */
		virtual tstring getSecurityPolicy() const = 0;

		/*! The methods getUserIdentityTokenCount() and getUserIdentityToken() are provided for efficient access to data.
		* The semantics of these methods are documented in getUserIdentityTokens(). */
		virtual unsigned getUserIdentityTokenCount() const = 0;
		/*! The methods getUserIdentityTokenCount() and getUserIdentityToken() are provided for efficient access to data.
		* The semantics of these methods are documented in getUserIdentityTokens(). */
		virtual const IUserTokenPolicy* getUserIdentityToken(unsigned index) const = 0;
		/*! Returns a list of user token policies that define the user identity tokens that
		* the server will accept. One of these policies must be used when creating a
		* session with a server.
		*
		* @see Client::Session::setUserSecurityPolicy() Client::Session::setUserIdentityToken() */
		virtual std::vector<UserTokenPolicy> getUserIdentityTokens() const = 0;

		/*! Returns the URI of the Transport Profile supported by the endpoint.
		* In this version, the SDK has only support for the TransportProfileUri_UaTcp_UaSc_UaBinary
		* transport profile.
		*
		* @see TransportProfileUri_UaTcp_UaSc_UaBinary et al. */
		virtual tstring getTransportProfile() const = 0;

		/*! Returns a numeric value that indicates how secure the EndpointDescription is compared
		* to other EndpointDescriptions for the same server. A value of 0 indicates that the EndpointDescription
		* is not recommended and is only supported for backward compatibility. */
		virtual unsigned char getSecurityLevel() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEndpointDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEndpointDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEndpointDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IEndpointDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEndpointDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEndpointDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEndpointDescription
} // end namespace
#endif	// IENDPOINTDESCRIPTION_H
