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

#ifndef SERVERSEMANTICCHANGEEVENT_H
#define SERVERSEMANTICCHANGEEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerBaseEventNotification.h"
#include "SemanticChangeStructureDataType.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! derived from BaseEventNotification
		*
		* SemanticChangeEvents are Events of SemanticChangeEventType that are
		* generated to indicate a change of the AddressSpace semantics. The
		* change consists of a change to the Value Attribute of a Property.
		* The SemanticChangeEvent contains information about the Node owning
		* the Property that was changed. If this is a Variable or Object, the
		* TypeDefinitionNode is also present.
		* The SemanticChange bit of the AccessLevel Attribute of a Property
		* indicates whether changes of the Property value are considered for
		* SemanticChangeEvents */
		class TBC_EXPORT ServerSemanticChangeEvent
			: public BaseEventNotification
		{
		public:
			/*! Constructs a new SemanticChangeEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Server"
			* @li SourceNode:		Server node */
			static ObjectPointer<ServerSemanticChangeEvent> create();
			/*! Destructor */
			virtual ~ServerSemanticChangeEvent();

		protected:
			/*! Constructs a new event for the given event type.
			*
			* This constructor shall be called from derived classes with the concrete event type.
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName:		"Server"
			* @li SourceNode:		Server node */
			ServerSemanticChangeEvent(const INodeId* eventTypeNode);

		public:
			/*! Sets the the changes for the Event
			*
			* @param changes The array of SemanticChangeStructureDataType */
			EnumStatusCode setChanges(const std::vector<SemanticChangeStructureDataType> &changes);

			/*! Returns the changes property.
			*
			* @see setChanges() */
			std::vector<SemanticChangeStructureDataType> getChanges();
		private:
			void initMembers();

			/*! Forbid use default constructor */
			ServerSemanticChangeEvent();
			/*! Forbid use assignment operator */
			ServerSemanticChangeEvent& operator=(const ServerSemanticChangeEvent&);
			/*! Forbid use of copy constructor */
			ServerSemanticChangeEvent(const ServerSemanticChangeEvent&);
		};
		typedef ObjectPointer<ServerSemanticChangeEvent> ServerSemanticChangeEventPtr;
		typedef ObjectPointer<const ServerSemanticChangeEvent> ServerSemanticChangeEventConstPtr;
	} // end Server namespace
} // toolbox namespace end

#endif
#endif // SERVERSEMANTICCHANGEEVENT_H
