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

#ifndef SERVERGETMONITOREDITEMS_H
#define SERVERGETMONITOREDITEMS_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerMethod.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class MethodCallTransaction;
		class MethodCallRequest;
	}

	namespace Server
	{
		/*! This class represents the 'GetMonitoredItems' method to retrieve all ClientHandles and ServerHandles
		* from all MonitoredItems of a Subscription.
		*
		* This method is required to identify MonitoredItems, where the client does not know, whether the item was
		* created or not and to retrieve the ServerHandle when only the ClientHandle is known.
		* Such cases can occur when a CreateMonitoredItemsRequest times out and the client can not know if the server
		* had processed the request or not.
		* Publish responses for a Subscription contain only the ClientHandles for the MonitoredItems, if the client
		* identifies an unknown MonitoredItem, it has to retrieve the corresponding ServerHandle to be able to delete it. */
		class TBC_EXPORT GetMonitoredItems
			: public Method
		{
		public:
			/*! Constructs a new GetMonitoredItems instance */
			static ObjectPointer<GetMonitoredItems> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			GetMonitoredItems(TBHandle otbHandle);

			/*! Destructor */
			virtual ~GetMonitoredItems();

			/*! Callback method that is called whenever the 'Refresh' method is executed by a client.
			* This method may be overridden by server applications.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleExecuteRequest(Server::MethodCallTransaction* transaction, Server::MethodCallRequest* request);

		private:
			/*! Forbid use assignment operator */
			GetMonitoredItems& operator=(const GetMonitoredItems&);
			/*! Forbid use default constructor */
			GetMonitoredItems();
			/*! Forbid use of copy constructor */
			GetMonitoredItems(const GetMonitoredItems&);
		};
		typedef ObjectPointer<GetMonitoredItems> GetMonitoredItemsPtr;
		typedef ObjectPointer<const GetMonitoredItems> GetMonitoredItemsConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERGETMONITOREDITEMS_H
