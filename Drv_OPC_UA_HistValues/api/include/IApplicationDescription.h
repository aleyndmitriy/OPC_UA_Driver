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

#ifndef IAPPLICATIONDESCRIPTION_H
#define IAPPLICATIONDESCRIPTION_H

#include "ApplicationDescriptionStruct.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The ApplicationDescription data type is used to characterize an OPC UA application.
	* The application type (see setApplicationType()) defines whether the application
	* is a server and/or client application and is used during initialization (see Application::initialize()). */
	class TBC_EXPORT IApplicationDescription
	{
	public:
		/*! Destructor */
		virtual ~IApplicationDescription(){};

		/*! Returns the globally unique identifier for the application instance. */
		virtual tstring getApplicationUri() const = 0;
		/*! Sets the globally unique identifier for the application instance. */
		virtual void setApplicationUri(const tstring& value) = 0;

		/*! Returns the globally unique identifier for the product. */
		virtual tstring getProductUri() const = 0;
		/*! Sets the globally unique identifier for the product. */
		virtual void setProductUri(const tstring& value) = 0;

		/*! Returns a localized descriptive name for the application. */
		virtual const ILocalizedText* getApplicationName() const = 0;
		/*! @overload */
		virtual ILocalizedText* getApplicationName() = 0;
		/*! Sets a localized descriptive name for the application. */
		virtual void setApplicationName(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual void setApplicationName(const LocalizedText& value) = 0;

		/*! Returns the type of the application (whether client, server or both). */
		virtual EnumApplicationType getApplicationType() const = 0;
		/*! Sets the type of the application (whether client, server or both). */
		virtual void setApplicationType(EnumApplicationType value) = 0;

		/*! Returns the URI that identifies the gateway server associated with the discoveryUrls.
		* @see setGatewayServerUri() */
		virtual tstring getGatewayServerUri() const = 0;
		/*! Sets the URI that identifies the gateway server associated with the discoveryUrls.
		* The gateway server URI is not set if the server can be accessed directly.
		*
		* @note This parameter must not be set for client applications. */
		virtual void setGatewayServerUri(const tstring& value) = 0;

		/*! Returns the URI that identifies the discovery profile supported by the provided discovery URLs.
		* @see setDiscoveryProfileUri() */
		virtual tstring getDiscoveryProfileUri() const = 0;
		/*! Sets the URI that identifies the discovery profile supported by the provided discovery URLs.
		* If the value is not specified then the Endpoints shall support the standard DiscoveryServices.
		*
		* @note This parameter must not be set for client applications. */
		virtual void setDiscoveryProfileUri(const tstring& value) = 0;

		/*! Returns a list of URLs for the discovery endpoints provided by the application. */
		virtual std::vector<tstring> getDiscoveryUrls() const = 0;
		/*! Sets a list of URLs for the discovery endpoints provided by the application.
		*
		* @note This parameter must not be set for client applications. */
		virtual EnumStatusCode setDiscoveryUrls(const std::vector<tstring>&) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IApplicationDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IApplicationDescription& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IApplicationDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IApplicationDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IApplicationDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IApplicationDescription& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IApplicationDescription
} // end namespace
#endif	// IAPPLICATIONDESCRIPTION_H
