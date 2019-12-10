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

#ifndef SERVERBASEEVENT_H
#define SERVERBASEEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "IServerBaseEvent.h"
#include "ServerObject.h"
#include "TimeZone.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class Variable;
	}

	namespace Server
	{
		/*! Base class for all event classes represented by nodes in address space.
		*
		* Usually, only conditions are represented as nodes in the address space.
		* Simple events that, unlike conditions, have no state associated with them,
		* should use the BaseEventNotification class. */
		class TBC_EXPORT BaseEvent
			: public Object, public IBaseEvent
		{
		public:
			/*! Constructs a new BaseEvent instance */
			static ObjectPointer<BaseEvent> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BaseEvent(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			BaseEvent();
			/*! For internal use only */
			BaseEvent(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BaseEvent();

			/*! Returns the EventId variable of the event.
			*
			* @see IBaseEvent::getEventId() for a description of the property. */
			ObjectPointer<Server::Variable> getEventIdVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getEventIdVar() const;
			/* see IBaseEvent::getEventId */
			virtual ByteString getEventId() const;
			/* see IBaseEvent::setEventId */
			virtual EnumStatusCode setEventId(const IByteString* eventId);

			/*! Returns the EventType variable of the event.
			*
			* @see IBaseEvent::getEventType() for a description of the property. */
			ObjectPointer<Server::Variable> getEventTypeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getEventTypeVar() const;
			/* see IBaseEvent::getEventType */
			virtual NodeId getEventType() const;
			/* see IBaseEvent::setEventType */
			virtual EnumStatusCode setEventType(const INodeId* eventTypeNode);
			/*! @overload */
			virtual EnumStatusCode setEventType(const INodeId& eventTypeNode);

			/*! Returns the SourceNode variable of the event.
			*
			* @see IBaseEvent::setSourceNode() for a description of the property. */
			ObjectPointer<Server::Variable> getSourceNodeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getSourceNodeVar() const;
			/* see IBaseEvent::getSourceNode */
			virtual NodeId getSourceNode() const;
			/* see IBaseEvent::setSourceNode */
			virtual EnumStatusCode setSourceNode(const INodeId* sourceNode);
			/*! @overload */
			virtual EnumStatusCode setSourceNode(const INodeId& sourceNode);

			/*! Returns the SourceName variable of the event.
			*
			* @see IBaseEvent::setSourceNode() for a description of the property. */
			ObjectPointer<Server::Variable> getSourceNameVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getSourceNameVar() const;
			/* see IBaseEvent::getSourceName */
			virtual tstring getSourceName() const;
			/* see IBaseEvent::setSourceName */
			virtual EnumStatusCode setSourceName(const tstring& sourceName);

			/*! Returns the Time variable of the event.
			*
			* @see IBaseEvent::setTime() for a description of the property. */
			ObjectPointer<Server::Variable> getTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getTimeVar() const;
			/* see IBaseEvent::getTime */
			virtual DateTime getTime() const;
			/* see IBaseEvent::setTime */
			virtual EnumStatusCode setTime(const IDateTime* time);
			/*! @overload */
			virtual EnumStatusCode setTime(const IDateTime& time);

			/*! Returns the ReceiveTime variable of the event.
			*
			* @see IBaseEvent::setReceiveTime() for a description of the property. */
			ObjectPointer<Server::Variable> getReceiveTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getReceiveTimeVar() const;
			/* see IBaseEvent::getReceiveTime */
			virtual DateTime getReceiveTime() const;
			/* see IBaseEvent::setReceiveTime */
			virtual EnumStatusCode setReceiveTime(const IDateTime* receiveTime);
			/*! @overload */
			virtual EnumStatusCode setReceiveTime(const IDateTime& receiveTime);

			/*! Returns the LocalTime variable of the event.
			*
			* @see IBaseEvent::setLocalTime() for a description of the property. */
			ObjectPointer<Server::Variable> getLocalTimeVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getLocalTimeVar() const;
			/* see IBaseEvent::getLocalTime */
			virtual TimeZone getLocalTime() const;
			/* see IBaseEvent::setLocalTime */
			virtual EnumStatusCode setLocalTime(const ITimeZone* localTime);
			/* @overload */
			virtual EnumStatusCode setLocalTime(const ITimeZone& localTime);

			/*! Returns the Message variable of the event.
			*
			* @see IBaseEvent::setMessage() for a description of the property. */
			ObjectPointer<Server::Variable> getMessageVar();
			/*! @overload */
			ObjectPointer<const Server::Variable> getMessageVar() const;
			/* see IBaseEvent::getMessage */
			virtual LocalizedText getMessage() const;
			/* see IBaseEvent::setMessage */
			virtual EnumStatusCode setMessage(const ILocalizedText* message);
			/*! @overload */
			virtual EnumStatusCode setMessage(const ILocalizedText& message);

			/*! Returns the Severity variable of the event.
			*
			* @see IBaseEvent::setSeverity() for a description of the property. */
			ObjectPointer<Server::Variable> getSeverityVar();
			/* see IBaseEvent::getSeverity */
			virtual OTUInt16 getSeverity() const;
			/*! @overload */
			ObjectPointer<const Server::Variable> getSeverityVar() const;
			/* see IBaseEvent::getSeverity */
			virtual EnumStatusCode setSeverity(OTUInt16 severity);

			/* see IBaseEvent::getProperty */
			virtual Value getProperty(const IQualifiedName& propertyName) const;
			/* see IBaseEvent::setProperty */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue* propertyValue);
			/*! @overload */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue& propertyValue);
			/* see IBaseEvent::removeProperty */
			virtual EnumStatusCode removeProperty(const IQualifiedName& propertyName);

			/* see IBaseEvent::report */
			virtual EnumStatusCode report(const INodeId* reportingNode);

		private:
			/*! Forbid use assignment operator */
			BaseEvent& operator=(const BaseEvent&);
			/*! Forbid use of copy constructor */
			BaseEvent(const BaseEvent&);
		};
		typedef ObjectPointer<BaseEvent> BaseEventPtr;
		typedef ObjectPointer<const BaseEvent> BaseEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERBASEEVENT_H
