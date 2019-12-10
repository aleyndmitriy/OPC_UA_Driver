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

#ifndef SERVERIBASEEVENT_H
#define SERVERIBASEEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerObject.h"
#include "TimeZone.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This interface is implemented by any event an OPC UA server may want to emit. */
		class TBC_EXPORT IBaseEvent
		{
		public:
			/*! Destructor */
			virtual ~IBaseEvent() {};

			/*! Returns the unique identifier of the event.
			*
			* The event ID is generated by the server to uniquely identify a particular event notification.
			* The server is responsible to ensure that each event has its unique EventId.
			*
			* This mandatory property will be automatically filled during event reporting.
			* Before reporting this property is not filled.
			*
			* @return The ByteString representing the event ID. */
			virtual ByteString getEventId() const = 0;
			/*! Sets the event ID of an event.
			*
			* In general the event ID is generated during event reporting.
			* If no event ID is set, it is generated.
			*
			* However some events (e.g. AuditConditionAcknowledgeEvent) shall fill this property on its own.
			*
			* @param eventId ByteString representing the event ID. */
			virtual EnumStatusCode setEventId(const IByteString* eventId) = 0;

			/*! Returns the NodeId of the event's type.
			*
			* @see setEventType() */
			virtual NodeId getEventType() const = 0;
			/*! Sets the EventType property of the event.
			*
			* This mandatory property will be automatically filled during event reporting if not set before.
			* It represents the node ID of the event type.
			*
			* @param eventType The NodeId of the event type */
			virtual EnumStatusCode setEventType(const INodeId* eventType) = 0;
			/*! @overload */
			virtual EnumStatusCode setEventType(const INodeId& eventTypeNode) = 0;

			/*! Returns the NodeId of the Node that the event originated from.
			*
			* @see setSourceNode() */
			virtual NodeId getSourceNode() const = 0;
			/*! Sets the NodeId of the Node that the event originated from.
			*
			* If the event is not specific to a Node the NodeId is set to null.
			* Some subtypes of this BaseEventType may define additional rules for SourceNode.
			*
			* @param sourceNode The NodeId of the event source */
			virtual EnumStatusCode setSourceNode(const INodeId* sourceNode) = 0;
			/*! @overload */
			virtual EnumStatusCode setSourceNode(const INodeId& sourceNode) = 0;

			/*! Returns the description of the source of the event.
			*
			* @see setSourceNode() */
			virtual tstring getSourceName() const = 0;
			/*! Sets the description of the source of the event.
			*
			* This could be the DisplayName of the event source - if the event is specific to a Node - or some server-specific notation.
			*
			* @param sourceName The description of the event source */
			virtual EnumStatusCode setSourceName(const tstring& sourceName) = 0;

			/*! Returns the time the event occurred.
			*
			* @see setTime() */
			virtual DateTime getTime() const = 0;
			/*! Sets the time the event occurred.
			*
			* This value is set as close to the event generator as
			* possible. It often comes from the underlying system or device. Once set, intermediate OPC UA
			* Servers shall not alter the value.
			*
			* @param time The time the event occurred */
			virtual EnumStatusCode setTime(const IDateTime* time) = 0;
			/*! @overload */
			virtual EnumStatusCode setTime(const IDateTime& time) = 0;

			/*! Returns the time the OPC UA server received the event.
			*
			* @see setReceiveTime() */
			virtual DateTime getReceiveTime() const = 0;
			/*! Sets the time the OPC UA server received the event.
			*
			* The event can be received from the underlying device or another server.
			* In the case where the OPC UA server gets an event from another OPC UA server,
			* each server applies its own ReceiveTime.
			*
			* @param receiveTime The time when the event was received */
			virtual EnumStatusCode setReceiveTime(const IDateTime* receiveTime) = 0;
			/*! @overload */
			virtual EnumStatusCode setReceiveTime(const IDateTime& receiveTime) = 0;

			/*! Returns the time zone information of the event's timestamps.
			*
			* @see setLocalTime() */
			virtual TimeZone getLocalTime() const = 0;
			/*! Sets time zone information of the event's timestamps.
			*
			* See TimeZone for further information. This property is optional.
			*
			* @param localTime The time zone information */
			virtual EnumStatusCode setLocalTime(const ITimeZone* localTime) = 0;
			/*! @overload */
			virtual EnumStatusCode setLocalTime(const ITimeZone& localTime) = 0;

			/*! Returns the human-readable and localized text description of the event.
			*
			* @see setMessage() */
			virtual LocalizedText getMessage() const = 0;
			/*! Sets a human-readable and localized text description of the event.
			*
			* The server may return any appropriate text to describe the event.
			* A null string is not a valid value; if the server does not have a description,
			* it shall return the string part of the BrowseName of the Node associated with the event.
			*
			* @param message The description of the event */
			virtual EnumStatusCode setMessage(const ILocalizedText* message) = 0;
			/*! @overload */
			virtual EnumStatusCode setMessage(const ILocalizedText& message) = 0;

			/*! Returns the severity of the event.
			*
			* @see setSeverity() */
			virtual OTUInt16 getSeverity() const = 0;
			/*! Sets the severity of the event. Severity is an indication of the urgency of the event.
			*
			* This is also commonly called 'priority'. Values will range from 1 to 1000, with 1 being the lowest severity and 1000 being the highest.
			* Typically, a severity of 1 would indicate an event which is informational in nature, while a value of 1000 would
			* indicate an event of catastrophic nature, which could potentially result in severe financial loss or
			* loss of life.
			*
			* @param severity The severity of the event */
			virtual EnumStatusCode setSeverity(OTUInt16 severity) = 0;

			/*! Returns the value of a property identified by the given @p propertyName.
			*
			* @see setProperty() */
			virtual Value getProperty(const IQualifiedName& propertyName) const = 0;
			/*! Sets a value for a specific property identified by the given @p propertyName.
			*
			* Using this method it is possible to specify vendor specific event types and provide properties.
			*
			* @param propertyName Qualified name of the property. Vendor specific property should use vendor specific namespace.
			* @param propertyValue Value of the property */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue* propertyValue) = 0;
			/*! @overload */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue& propertyValue) = 0;
			/*! Removes the property identified by a given @p propertyName from the event.
			*
			* @see setProperty() */
			virtual EnumStatusCode removeProperty(const IQualifiedName& propertyName) = 0;

			/*! Reports the event to the client(s).
			*
			* The reporting will be done on the source node if given.
			* If SourceNode property is not set, the reporting will be done on the server node. */
			virtual EnumStatusCode report(const INodeId* reportingNode) = 0;
		};
	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERIBASEEVENT_H
