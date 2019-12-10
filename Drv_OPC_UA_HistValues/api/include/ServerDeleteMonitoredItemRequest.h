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

#ifndef SERVERDELETEMONITOREDITEMSREQUEST_H
#define SERVERDELETEMONITOREDITEMSREQUEST_H

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

		/*! The DeleteMonitoredItemRequest class encapsulates client requests for deletion of monitored items.
		*
		* The status code already has a value according to internal evaluation. */
		class TBC_EXPORT DeleteMonitoredItemRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DeleteMonitoredItemRequest(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~DeleteMonitoredItemRequest();

			/*! Returns the monitored item to be created.
			*
			* Deletion of a monitored item cannot be rejected. */
			ObjectPointer<Server::MonitoredItem> getMonitoredItem();
			/*! @overload */
			ObjectPointer<const Server::MonitoredItem> getMonitoredItem() const;

			/*! Returns the status code for this request.
			*
			* A status code is already evaluated and set by the SDK before invoking this request.
			* The status code cannot be changed since deletion of a monitored item cannot be rejected by the application. */
			EnumStatusCode getStatusCode() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			PRIVATE_EXPORTED_STL_CONTAINER(mutable ObjectPointer<Server::MonitoredItem> m_monitoredItem)

			// Requests are always created by the SDK core.
			DeleteMonitoredItemRequest();

			/*! Forbid use assignment operator */
			DeleteMonitoredItemRequest& operator=(const DeleteMonitoredItemRequest&);
			/*! Forbid use of copy constructor */
			DeleteMonitoredItemRequest(const DeleteMonitoredItemRequest&);
		};
		typedef ObjectPointer<DeleteMonitoredItemRequest> DeleteMonitoredItemRequestPtr;
		typedef ObjectPointer<const DeleteMonitoredItemRequest> DeleteMonitoredItemRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDELETEMONITOREDITEMSREQUEST_H
