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

#ifndef SERVERAUDITUPDATEMETHODEVENT_H
#define SERVERAUDITUPDATEMETHODEVENT_H
#if TB5_ALARMS
#include "Base.h"
#include "Enums.h"
#include "ServerAuditEvent.h"
#include "ServerMethodCallRequest.h"
#include "ServerMethodCallTransaction.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class of all method related audit events.
		*
		* The SourceNode property for events of this type should be assigned to the NodeId of the object that the method resides on.
		* The SourceName property for events of this type should be "Attribute/Call".
		*
		* Beside mandatory properties of the base class additionally the following mandatory properties shall be set:
		* @li MethodId:			Identifies the method that was called.
		* @li InputArguments:	Identifies the input arguments for the method. This property can be omitted if no input arguments
		*						have been provided. */
		class TBC_EXPORT AuditUpdateMethodEvent
			: public AuditEvent
		{
		public:
			/*! Constructs a new AuditUpdateMethodEvent instance.
			*
			* The newly created object has already the following properties initially set:
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			static ObjectPointer<AuditUpdateMethodEvent> create();

		protected:
			/*! This constructor is used for derived classes.
			*
			* This constructor shall be called for specialized events with the concrete event type.
			*
			* The newly created object has already the following properties initially set:
			* @li Time:				The actual time.
			* @li ActionTimeStamp:	The actual time.
			* @li ReceiveTime:		The actual time.
			* @li Severity:			1
			* @li ServerId:			The ID of the server from the application description. */
			AuditUpdateMethodEvent(const INodeId* eventTypeNode);

		public:
			/*! Destructor */
			virtual ~AuditUpdateMethodEvent();

			/*! Sets the method related information.
			*
			* The properties filled with method are:
			* @li MethodId:				Identifies the method that was called.
			* @li InputArguments:		Identifies the input Arguments for the method.
			* @li ClientAuditEntryId:	Contains the human-readable AuditEntryId.
			* @li SourceNode:			Identifies the Node that the Event originated from.
			* @li Status:				Identifies whether the requested action could be performed.
			*
			* @param request		The request of the method call
			* @param transaction	The transaction containing the request
			* @param status			The Status property identifies whether the requested action could be performed (set Status to TRUE)
			*						or not (set Status to FALSE). */
			void setMethodAuditInformation(const Server::MethodCallRequest* request, const Server::MethodCallTransaction* transaction, bool status);

			/*! Returns the NodeId of the method that was called.
			*
			* @see setMethodId() */
			NodeId getMethodId() const;
			/*! Sets the NodeId of the method that was called.
			*
			* @param methodId The node ID of the called method
			*
			* @see setMethodAuditInformation() */
			EnumStatusCode setMethodId(const INodeId* methodId);

			/*! Returns the input arguments that have been provided with the method call.
			*
			* @see setInputArguments() */
			std::vector<Value> getInputArguments() const;
			/*! Sets the input arguments that have been provided with the method call.
			* This property needs not to be filled if no input arguments have been provided.
			*
			* @param inputArguments The input arguments of the method
			*
			* @see setMethodAuditInformation() */
			EnumStatusCode setInputArguments(const std::vector<Value>& inputArguments);

			/*! Returns the comment property of an audit event.
			*
			* @see setComment() */
			LocalizedText getComment() const;
			/*! Sets the comment property of an audit event.
			*
			* The comment property is mandatory for the following derived audit event types:
			* @li AuditConditionCommentEvent:		Report the "AddComment" action.
			* @li AuditConditionAcknowledgeEvent:	Indicates acknowledgment or confirmation of one or more conditions.
			* @li AuditConditionConfirmEvent:		Reports a "Confirm" action.
			*
			* All other derived audit events shall not set the comment property.
			*
			* @param comment The comment that was added */
			EnumStatusCode setComment(ILocalizedText* comment);

		private:
			/*! Forbid use default constructor */
			AuditUpdateMethodEvent();
			/*! Forbid use assignment operator */
			AuditUpdateMethodEvent& operator=(const AuditUpdateMethodEvent&);
			/*! Forbid use of copy constructor */
			AuditUpdateMethodEvent(const AuditUpdateMethodEvent&);
		};
		typedef ObjectPointer<AuditUpdateMethodEvent> AuditUpdateMethodEventPtr;
		typedef ObjectPointer<const AuditUpdateMethodEvent> AuditUpdateMethodEventConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAUDITUPDATEMETHODEVENT_H
