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

#ifndef SERVERCREATEMONITOREDITEMSREQUEST_H
#define SERVERCREATEMONITOREDITEMSREQUEST_H

#include "Base.h"
#include "Enums.h"
#include "ServerDataRequest.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// Forward declarations
		class MonitoredItem;

		/*! The CreateMonitoredItemRequest class encapsulates client requests for creation of monitored items.
		*
		* The status code already has a value according to internal evaluation, e.g. EnumStatusCode_BadNodeIdUnknown if
		* the monitored item refers to a node which does not (yet) exist. */
		class TBC_EXPORT CreateMonitoredItemRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			CreateMonitoredItemRequest(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~CreateMonitoredItemRequest();

			/*! Returns the monitored item to be created.
			*
			* The attributes of the monitored items can be revised until the transaction is completed.
			* If creation of a monitored item shall be refused, a bad status code must be set via the setStatusCode method.
			*
			* @note This method can return a NULL pointer for bad requests, which cannot be handled or fixed by an application,
			*       like for malformed service parameters */
			ObjectPointer<Server::MonitoredItem> getMonitoredItem();
			/*! @overload */
			ObjectPointer<const Server::MonitoredItem> getMonitoredItem() const;

			/*! Returns the status code for this request. */
			EnumStatusCode getStatusCode() const;
			/*! Sets the status code for this request.
			*
			* A bad status code will refuse creation of the monitored item.
			*
			* @param statusCode The request status code
			* @return A good result, if the provided status code was accepted */
			EnumStatusCode setStatusCode(EnumStatusCode statusCode);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::MonitoredItem> m_monitoredItem)

			// Requests are always created by the SDK core.
			CreateMonitoredItemRequest();

			/*! Forbid use assignment operator */
			CreateMonitoredItemRequest& operator=(const CreateMonitoredItemRequest&);
			/*! Forbid use of copy constructor */
			CreateMonitoredItemRequest(const CreateMonitoredItemRequest&);
		};
		typedef ObjectPointer<CreateMonitoredItemRequest> CreateMonitoredItemRequestPtr;
		typedef ObjectPointer<const CreateMonitoredItemRequest> CreateMonitoredItemRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERCREATEMONITOREDITEMSREQUEST_H
