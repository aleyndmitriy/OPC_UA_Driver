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

#ifndef SERVERAUDITWRITEUPDATEEVENT_H
#define SERVERAUDITWRITEUPDATEEVENT_H
#if TB5_ALARMS
#include "ServerAuditEvent.h"
#include "NumericRange.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This event may be generated if a client changes the value of any attribute.
		*
		* Beside properties of the base class additionally the following mandatory properties shall be set:
		* @li AttributeId:	The property that shall contain the attribute that was written on the SourceNode.
		* @li IndexRange:	The property that shall contain the index range of the written attribute.
		* @li NewValue:		The property that shall contain the value that was written to the SourceNode.
		* @li OldValue:		The property that shall contain the value that the SourceNode contained before the write. */
		class TBC_EXPORT AuditWriteUpdateEvent
			: public AuditEvent
		{
		public:
			/*! Constructs a new AuditWriteUpdateEvent instance
			*
			* The newly created object has already the following properties initially set:
			* @li SourceName		"Attribute/Write"
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditWriteUpdateEvent> create();

		protected:
			/*! Default constructor */
			AuditWriteUpdateEvent();
			/*! @overload */
			AuditWriteUpdateEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditWriteUpdateEvent();

			/*! Returns the AttributeId of the attribute that was written on the SourceNode.
			*
			* @see setAttributeId() */
			EnumAttributeId getAttributeId() const;
			/*! Sets the AttributeId of the attribute that was written on the SourceNode.
			*
			* @param attributeId The attribute that was written on */
			EnumStatusCode setAttributeId(EnumAttributeId attributeId);

			/*! Returns the IndexRange of the written attribute if the attribute was an array.
			*
			* @see setIndexRange() */
			EnumStatusCode getIndexRange(NumericRange &range) const;
			/*! Sets the IndexRange of the written attribute if the attribute was an array.
			* If the attribute is not an array or the whole array was written, this
			* property can be omitted.
			*
			* @param indexRange The range of the array that was written */
			EnumStatusCode setIndexRange(const INumericRange* indexRange);

			/*! Returns the new value that was written on the SourceNode.
			*
			* @see setNewValue() */
			Value getNewValue() const;
			/*! Sets the new value that was written on the SourceNode.
			* If an IndexRange was provided, only the values in the provided range must be set.

			* @param newValue The value that was written */
			EnumStatusCode setNewValue(IValue* newValue);

			/*! Returns the old value that the SourceNode contained before the write.
			*
			* @see setOldValue() */
			Value getOldValue() const;
			/*! Sets the old value that the SourceNode contained before the write.
			* If an IndexRange was provided, only the values in the provided range must be set.
			* It is acceptable for a server that does not have this information to omit this property.
			*
			* @param oldValue The value before the write */
			EnumStatusCode setOldValue(IValue* oldValue);

		private:
			/*! Forbid use assignment operator */
			AuditWriteUpdateEvent& operator=(const AuditWriteUpdateEvent&);
			/*! Forbid use of copy constructor */
			AuditWriteUpdateEvent(const AuditWriteUpdateEvent&);
		};
		typedef ObjectPointer<AuditWriteUpdateEvent> AuditWriteUpdateEventPtr;
		typedef ObjectPointer<const AuditWriteUpdateEvent> AuditWriteUpdateEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITWRITEUPDATEEVENT_H
