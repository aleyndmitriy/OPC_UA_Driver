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

#ifndef SERVERBASEEVENTNOTIFICATION_H
#define SERVERBASEEVENTNOTIFICATION_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "IServerBaseEvent.h"
#include "TimeZone.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class for simple events that are not represented by nodes in the address space.
		*
		* In general, those event types are almost anything except conditions.
		* These simple events can be described by a flat, unstructured set of properties. */
		class TBC_EXPORT BaseEventNotification
			: public IBaseEvent,
			public Base
		{
		public:
			/*! Constructs a new event notification object for the given event type */
			static ObjectPointer<BaseEventNotification> create(const INodeId* eventTypeNode);

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BaseEventNotification(TBHandle otbHandle);

		protected:
			/*! Constructs a new event notification object for the given event type */
			BaseEventNotification(const INodeId* eventTypeNode);

			/*! For internal use only */
			BaseEventNotification(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BaseEventNotification();

			/*! Initializes the BaseEventNotification instance with the given event type or event instance node.
			* If the node is of a wrong type the function call will return an error.
			*
			* @note	The event type is already defined in the constructor. Unless derived classes
			*		override init(), there is no need to call this method again. */
			virtual EnumStatusCode init(const INodeId* eventTypeNode);

			/* see IBaseEvent::getEventId() */
			virtual ByteString getEventId() const;
			/* see IBaseEvent::setEventId() */
			virtual EnumStatusCode setEventId(const IByteString* eventId);

			/* see IBaseEvent::getEventType() */
			virtual NodeId getEventType() const;
			/* see IBaseEvent::setEventType() */
			virtual EnumStatusCode setEventType(const INodeId* eventTypeNode);
			/* see IBaseEvent::setEventType() */
			virtual EnumStatusCode setEventType(const INodeId& eventTypeNode);

			/* see IBaseEvent::getSourceNode() */
			virtual NodeId getSourceNode() const;
			/* see IBaseEvent::setSourceNode() */
			virtual EnumStatusCode setSourceNode(const INodeId* sourceNode);
			/* see IBaseEvent::setSourceNode() */
			virtual EnumStatusCode setSourceNode(const INodeId& sourceNode);

			/* see IBaseEvent::getSourceName() */
			virtual tstring getSourceName() const;
			/* see IBaseEvent::setSourceName() */
			virtual EnumStatusCode setSourceName(const tstring& sourceName);

			/* see IBaseEvent::getTime() */
			virtual DateTime getTime() const;
			/* see IBaseEvent::setTime() */
			virtual EnumStatusCode setTime(const IDateTime* time);
			/* see IBaseEvent::setTime() */
			virtual EnumStatusCode setTime(const IDateTime& time);

			/* see IBaseEvent::getReceiveTime() */
			virtual DateTime getReceiveTime() const;
			/* see IBaseEvent::setReceiveTime() */
			virtual EnumStatusCode setReceiveTime(const IDateTime* receiveTime);
			/* see IBaseEvent::setReceiveTime() */
			virtual EnumStatusCode setReceiveTime(const IDateTime& receiveTime);

			/* see IBaseEvent::getLocalTime() */
			virtual TimeZone getLocalTime() const;
			/* see IBaseEvent::setLocalTime() */
			virtual EnumStatusCode setLocalTime(const ITimeZone* localTime);
			/* see IBaseEvent::setLocalTime() */
			virtual EnumStatusCode setLocalTime(const ITimeZone& localTime);

			/* see IBaseEvent::getMessage() */
			virtual LocalizedText getMessage() const;
			/* see IBaseEvent::setMessage() */
			virtual EnumStatusCode setMessage(const ILocalizedText* message);
			/* see IBaseEvent::setMessage() */
			virtual EnumStatusCode setMessage(const ILocalizedText& message);

			/* see IBaseEvent::getSeverity() */
			virtual OTUInt16 getSeverity() const;
			/* see IBaseEvent::setSeverity() */
			virtual EnumStatusCode setSeverity(OTUInt16 severity);

			/* see IBaseEvent::getProperty() */
			virtual Value getProperty(const IQualifiedName& propertyName) const;
			/* see IBaseEvent::setProperty() */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue* propertyValue);
			/* see IBaseEvent::setProperty() */
			virtual EnumStatusCode setProperty(const IQualifiedName& propertyName, const IValue& propertyValue);
			/* see IBaseEvent::removeProperty() */
			virtual EnumStatusCode removeProperty(const IQualifiedName& propertyName);

			/* see IBaseEvent::report() */
			virtual EnumStatusCode report(const INodeId* reportingNode);

		private:
			/*! Forbid use assignment operator */
			BaseEventNotification& operator=(const BaseEventNotification&);
			/*! Forbid use of copy constructor */
			BaseEventNotification(const BaseEventNotification&);
		};
		typedef ObjectPointer<BaseEventNotification> BaseEventNotificationPtr;
		typedef ObjectPointer<const BaseEventNotification> BaseEventNotificationConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERBASEEVENTNOTIFICATION_H
