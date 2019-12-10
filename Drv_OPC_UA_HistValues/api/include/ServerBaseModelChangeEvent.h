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

#ifndef SERVERBASEMODELCHANGEEVENT_H
#define SERVERBASEMODELCHANGEEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerBaseEventNotification.h"
#include "ModelChangeStructureDataType.h"

namespace SoftingOPCToolbox5
{

	namespace Server
	{
		/*! ModelChangeEvents are generated to indicate a change of the AddressSpace structure.
		*
		* BaseModelChangeEvents are Events of the BaseModelChangeEventType.
		* The BaseModelChangeEventType is the base type for ModelChangeEvents
		* and does not contain information about the changes but only indicates
		* that changes occurred. Therefore the Client shall assume that any
		* or all of the Nodes may have changed.
		*
		* There is a correlation between ModelChangeEvents and the NodeVersion Property of Nodes. Every
		* time a ModelChangeEvent is issued for a Node, its NodeVersion shall be changed, and every time
		* the NodeVersion is changed, a ModelChangeEvent shall be generated. A Server shall support both
		* the ModelChangeEvent and the NodeVersion Property or neither, but never only one of the two
		* mechanisms.
		*
		* This relation also implies that only those Nodes of the AddressSpace having a NodeVersion shall
		* trigger a ModelChangeEvent. Other Nodes shall not trigger a ModelChangeEvent.
		*
		* @see BaseNode::setVersioned(), BaseNode::setNodeVersion()
		*
		* @see AddressSpaceRoot::beginModelChange() AddressSpaceRoot::endModelChange() and AddressSpaceRoot::onIncrementNodeVersion() */
		class TBC_EXPORT ServerBaseModelChangeEvent
			: public BaseEventNotification
		{
		public:
			/*! Constructs a new BaseModelChangeEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Server"
			* @li SourceNode:		Server node */
			static ObjectPointer<ServerBaseModelChangeEvent> create();
			/*! Destructor */
			virtual ~ServerBaseModelChangeEvent();

		protected:
			/*! Constructs a new event for the given event type.
			*
			* This constructor shall be called from derived classes with the concrete event type.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Server"
			* @li SourceNode:		Server node */
			ServerBaseModelChangeEvent(const INodeId* eventTypeNode);

		private:
			void initMembers();

			/*! Forbid use default constructor */
			ServerBaseModelChangeEvent();
			/*! Forbid use assignment operator */
			ServerBaseModelChangeEvent& operator=(const ServerBaseModelChangeEvent&);
			/*! Forbid use of copy constructor */
			ServerBaseModelChangeEvent(const ServerBaseModelChangeEvent&);
		};
		typedef ObjectPointer<ServerBaseModelChangeEvent> ServerBaseModelChangeEventPtr;
		typedef ObjectPointer<const ServerBaseModelChangeEvent> ServerBaseModelChangeEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif // SERVERBASEMODELCHANGEEVENT_H
