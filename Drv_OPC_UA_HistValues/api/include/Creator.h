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

#ifndef CREATOR_H
#define CREATOR_H

#include "Enums.h"
#include "Base.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class Trace;
	class Application;
	class StringTable;
	class INodeId;
	class StructuredDataTypeDescription;
	class FieldDescription;
	class EnumerationDataTypeDescription;
	class EnumeratedValueDescription;
	namespace Client
	{
		class MonitoredItem;
		class Session;
		class Subscription;
		class RedundantMonitoredItem;
		class RedundantSubscription;
		class RedundantSession;
		class CertificateChangeTransaction;
	}

	namespace Server
	{
		class Diagnostics;
		class AddressSpaceRoot;
		class Variable;
		class Object;
		class Method;
		class ObjectType;
		class ReferenceType;
		class DataType;
		class View;
		class VariableType;
		class Endpoint;
		class MonitoredItem;
		class Subscription;
		class ReadRequest;
		class WriteRequest;
		class HistoryReadRawRequest;
		class HistoryReadProcessedRequest;
		class HistoryReadEventRequest;
		class BrowseRequest;
		class BrowseNextRequest;
		class TranslateBrowsePathsToNodeIdsRequest;
		class ReadTransaction;
		class WriteTransaction;
		class HistoryReadRawTransaction;
		class HistoryReadProcessedTransaction;
		class HistoryReadEventTransaction;
		class BrowseTransaction;
		class BrowseNextTransaction;
		class TranslateBrowsePathsToNodeIdsTransaction;
		class Session;
		class ReferenceIterator;
		class MethodCallRequest;
		class MethodCallTransaction;
		class BaseEvent;
		class Condition;
		class StateMachine;
		class StateVariable;
		class TransitionVariable;
		class FiniteStateMachine;
		class FiniteStateVariable;
		class FiniteTransitionVariable;
		class ConditionVariable;
		class TwoStateVariable;
		class AcknowledgeableCondition;
		class AlarmCondition;
		class ShelvedStateMachine;
		class ConditionEnable;
		class ConditionDisable;
		class State;
		class Transition;
#if TB5_ALARMS
		class LimitAlarm;
		class ShelvedStateMachineTimedShelve;
		class ShelvedStateMachineOneShotShelve;
		class ShelvedStateMachineUnshelve;
		class AcknowledgeableConditionAcknowledge;
		class AcknowledgeableConditionConfirm;
		class ConditionRefresh;
		class ConditionAddComment;
		class ExclusiveLimitAlarm;
		class ExclusiveLimitStateMachine;
		class ExclusiveLevelAlarm;
		class ExclusiveDeviationAlarm;
		class ExclusiveRateOfChangeAlarm;
		class DiscreteAlarm;
		class OffNormalAlarm;
		class TripAlarm;
		class NonExclusiveLimitAlarm;
		class NonExclusiveLevelAlarm;
		class NonExclusiveDeviationAlarm;
		class NonExclusiveRateOfChangeAlarm;
		class BaseEventNotification;
		class AuditWriteUpdateEvent;
#endif
		class HistoryReadRawContinuationPoint;
		class HistoryReadProcessedContinuationPoint;
		class HistoryReadEventContinuationPoint;
		class BrowseContinuationPoint;
		class AggregateConfiguration;
		class HistoricalDataConfiguration;
		class AggregateFunction;
		class CreateMonitoredItemRequest;
		class ModifyMonitoredItemRequest;
		class DeleteMonitoredItemRequest;
		class DictionaryVariable;
		class GetMonitoredItems;
		class DeleteSubscriptionRequest;
		class DeleteSessionRequest;
		class DataItem;
		class DiscreteItem;
		class TwoStateItem;
		class MultiStateItem;
		class MultiStateValueItem;
		class AnalogItem;
		class File;
		class FileDirectory;
	}

	/*! The Creator is an object factory that is used by the SDK to create API objects.
	* Applications that wish to derive from API objects should sub-class the Creator and override the
	* appropriate methods to create and return instances of derived objects. */
	class TBC_EXPORT Creator
	{
	public:
		/*! Default constructor */
		Creator(){}

		/*! Destructor */
		virtual ~Creator(){}

		//////////////////////////////////////////////////////////////////////////
		// Factory methods for creating common (both Server and Client) classes
		//////////////////////////////////////////////////////////////////////////

		/*! Creates and returns an instance of class Application */
		virtual Application* createApplication(TBHandle otbHandle);

		/*! Creates and returns an instance of class StringTable */
		virtual StringTable* createStringTable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Trace */
		virtual Trace* createTrace(TBHandle otbHandle);


		//////////////////////////////////////////////////////////////////////////
		// Factory methods for creating Client classes
		//////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////
		// Factory methods for creating Server classes
		//////////////////////////////////////////////////////////////////////////

		/*! Creates and returns an instance of class Server::Diagnostics */
		virtual Server::Diagnostics* createServerDiagnostics(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::AddressSpaceRoot */
		virtual Server::AddressSpaceRoot* createServerAddressSpaceRoot(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Variable
		 * @param	otbHandle	internal handle used by the constructor of the appropriate API class
		 * @param	pNodeId	NodeId of the object to be created of the object to be created
		 * @param	pTypeNodeId	TypeNode of the object to be created of the object to be created
		 * @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::Variable* createServerVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::Variable* createServerVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::Variable* createServerVariable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Object
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::Object* createServerObjectEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::Object* createServerObjectEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::Object* createServerObject(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Method
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::Method* createServerMethodEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::Method* createServerMethodEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::Method* createServerMethod(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ObjectType
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ObjectType* createServerObjectTypeEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ObjectType* createServerObjectTypeEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ObjectType* createServerObjectType(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ReferenceType
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ReferenceType* createServerReferenceTypeEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ReferenceType* createServerReferenceTypeEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ReferenceType* createServerReferenceType(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::DataType
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::DataType* createServerDataTypeEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::DataType* createServerDataTypeEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::DataType* createServerDataType(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::VariableType
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::VariableType* createServerVariableTypeEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::VariableType* createServerVariableTypeEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::VariableType* createServerVariableType(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::View
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::View* createServerViewEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::View* createServerViewEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::View* createServerView(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Endpoint
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::Endpoint* createServerEndpoint(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::MonitoredItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::MonitoredItem* createServerMonitoredItem(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Subscription
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::Subscription* createServerSubscription(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::DeleteSubscriptionRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::DeleteSubscriptionRequest* createServerDeleteSubscriptionRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::DeleteSessionRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::DeleteSessionRequest* createServerDeleteSessionRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ReadRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::ReadRequest* createServerReadRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::WriteRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::WriteRequest* createServerWriteRequest(TBHandle otbHandle);

#if TB5_HISTORY
		/*! Creates and returns an instance of class Server::HistoryReadRawRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadRawRequest* createServerHistoryReadRawRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoryReadProcessedRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadProcessedRequest* createServerHistoryReadProcessedRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoryReadEventRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadEventRequest* createServerHistoryReadEventRequest(TBHandle otbHandle);
#endif
		/*! Creates and returns an instance of class Server::BrowseRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::BrowseRequest* createServerBrowseRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::BrowseNextRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::BrowseNextRequest* createServerBrowseNextRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::TranslateBrowsePathsToNodeIdsRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::TranslateBrowsePathsToNodeIdsRequest* createServerTranslateBrowsePathsToNodeIdsRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ReadTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::ReadTransaction* createServerReadTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::WriteTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::WriteTransaction* createServerWriteTransaction(TBHandle otbHandle);

#if TB5_HISTORY
		/*! Creates and returns an instance of class Server::HistoryReadRawTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadRawTransaction* createServerHistoryReadRawTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoryReadProcessedTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadProcessedTransaction* createServerHistoryReadProcessedTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ReadEventTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadEventTransaction* createServerHistoryReadEventTransaction(TBHandle otbHandle);
#endif

		/*! Creates and returns an instance of class Server::BrowseTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::BrowseTransaction* createServerBrowseTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::BrowseNextTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::BrowseNextTransaction* createServerBrowseNextTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::TranslateBrowsePathsToNodeIdsTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::TranslateBrowsePathsToNodeIdsTransaction* createServerTranslateBrowsePathsToNodeIdsTransaction(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Session
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::Session* createServerSession(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ReferenceIterator
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::ReferenceIterator* createServerReferenceIterator(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::MethodCallRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::MethodCallRequest* createServerMethodCallRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::MethodCallTranscation
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::MethodCallTransaction* createServerMethodCallTransaction(TBHandle otbHandle);

#if TB5_ALARMS
		/*! Creates and returns an instance of class Server::BaseEvent
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::BaseEvent* createServerBaseEventEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::BaseEvent* createServerBaseEventEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::BaseEvent* createServerBaseEvent(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Condition
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::Condition* createServerConditionEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::Condition* createServerConditionEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::Condition* createServerCondition(TBHandle otbHandle);
#endif

		/*! Creates and returns an instance of class Server::StateMachine
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::StateMachine* createServerStateMachineEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::StateMachine* createServerStateMachineEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::StateMachine* createServerStateMachine(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::StateVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::StateVariable* createServerStateVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::StateVariable* createServerStateVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::StateVariable* createServerStateVariable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::TransitionVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::TransitionVariable* createServerTransitionVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::TransitionVariable* createServerTransitionVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::TransitionVariable* createServerTransitionVariable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::FiniteStateMachine
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::FiniteStateMachine* createServerFiniteStateMachineEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::FiniteStateMachine* createServerFiniteStateMachineEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::FiniteStateMachine* createServerFiniteStateMachine(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::FiniteStateVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::FiniteStateVariable* createServerFiniteStateVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::FiniteStateVariable* createServerFiniteStateVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::FiniteStateVariable* createServerFiniteStateVariable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::FiniteTransitionVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::FiniteTransitionVariable* createServerFiniteTransitionVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::FiniteTransitionVariable* createServerFiniteTransitionVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::FiniteTransitionVariable* createServerFiniteTransitionVariable(TBHandle otbHandle);

#if TB5_ALARMS
		/*! Creates and returns an instance of class Server::ConditionVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ConditionVariable* createServerConditionVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ConditionVariable* createServerConditionVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ConditionVariable* createServerConditionVariable(TBHandle otbHandle);
#endif

		/*! Creates and returns an instance of class Server::TwoStateVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::TwoStateVariable* createServerTwoStateVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::TwoStateVariable* createServerTwoStateVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::TwoStateVariable* createServerTwoStateVariable(TBHandle otbHandle);

#if TB5_ALARMS
		/*! Creates and returns an instance of class Server::AcknowledgeableCondition
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::AcknowledgeableCondition* createServerAcknowledgeableConditionEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::AcknowledgeableCondition* createServerAcknowledgeableConditionEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::AcknowledgeableCondition* createServerAcknowledgeableCondition(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::AlarmCondition
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::AlarmCondition* createServerAlarmConditionEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::AlarmCondition* createServerAlarmConditionEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::AlarmCondition* createServerAlarmCondition(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ShelvedStateMachine
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ShelvedStateMachine* createServerShelvedStateMachineEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ShelvedStateMachine* createServerShelvedStateMachineEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ShelvedStateMachine* createServerShelvedStateMachine(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ConditionEnable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ConditionEnable* createServerConditionEnableEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ConditionEnable* createServerConditionEnableEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ConditionEnable* createServerConditionEnable(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ConditionDisable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ConditionDisable* createServerConditionDisableEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ConditionDisable* createServerConditionDisableEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ConditionDisable* createServerConditionDisable(TBHandle otbHandle);
#endif
		/*! Creates and returns an instance of class Server::State
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::State* createServerStateEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::State* createServerStateEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::State* createServerState(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::Transition
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::Transition* createServerTransitionEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::Transition* createServerTransitionEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::Transition* createServerTransition(TBHandle otbHandle);

#if TB5_ALARMS
		/*! Creates and returns an instance of class Server::LimitAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::LimitAlarm* createServerLimitAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::LimitAlarm* createServerLimitAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::LimitAlarm* createServerLimitAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ShelvedStateMachineTimedShelve
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ShelvedStateMachineTimedShelve* createServerShelvedStateMachineTimedShelveEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ShelvedStateMachineTimedShelve* createServerShelvedStateMachineTimedShelveEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ShelvedStateMachineTimedShelve* createServerShelvedStateMachineTimedShelve(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ShelvedStateMachineOneShotShelve
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ShelvedStateMachineOneShotShelve* createServerShelvedStateMachineOneShotShelveEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ShelvedStateMachineOneShotShelve* createServerShelvedStateMachineOneShotShelveEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ShelvedStateMachineOneShotShelve* createServerShelvedStateMachineOneShotShelve(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ShelvedStateMachineUnshelve
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ShelvedStateMachineUnshelve* createServerShelvedStateMachineUnshelveEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ShelvedStateMachineUnshelve* createServerShelvedStateMachineUnshelveEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ShelvedStateMachineUnshelve* createServerShelvedStateMachineUnshelve(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ConditionAddComment
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ConditionAddComment* createServerConditionAddCommentEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ConditionAddComment* createServerConditionAddCommentEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ConditionAddComment* createServerConditionAddComment(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::AcknowledgeableConditionAcknowledge
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::AcknowledgeableConditionAcknowledge* createServerAcknowledgeableConditionAcknowledgeEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::AcknowledgeableConditionAcknowledge* createServerAcknowledgeableConditionAcknowledgeEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::AcknowledgeableConditionAcknowledge* createServerAcknowledgeableConditionAcknowledge(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::AcknowledgeableConditionConfirm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::AcknowledgeableConditionConfirm* createServerAcknowledgeableConditionConfirmEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::AcknowledgeableConditionConfirm* createServerAcknowledgeableConditionConfirmEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::AcknowledgeableConditionConfirm* createServerAcknowledgeableConditionConfirm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ConditionRefresh
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ConditionRefresh* createServerConditionRefreshEx2(TBHandle otbHandle, const INodeId* pNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ConditionRefresh* createServerConditionRefreshEx(TBHandle otbHandle, const INodeId* pNodeId);
		/*! @overload */
		virtual Server::ConditionRefresh* createServerConditionRefresh(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ExclusiveLimitAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ExclusiveLimitAlarm* createServerExclusiveLimitAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ExclusiveLimitAlarm* createServerExclusiveLimitAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ExclusiveLimitAlarm* createServerExclusiveLimitAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ExclusiveLimitStateMachine
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ExclusiveLimitStateMachine* createServerExclusiveLimitStateMachineEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ExclusiveLimitStateMachine* createServerExclusiveLimitStateMachineEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ExclusiveLimitStateMachine* createServerExclusiveLimitStateMachine(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ExclusiveLevelAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ExclusiveLevelAlarm* createServerExclusiveLevelAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ExclusiveLevelAlarm* createServerExclusiveLevelAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ExclusiveLevelAlarm* createServerExclusiveLevelAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ExclusiveDeviationAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ExclusiveDeviationAlarm* createServerExclusiveDeviationAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ExclusiveDeviationAlarm* createServerExclusiveDeviationAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ExclusiveDeviationAlarm* createServerExclusiveDeviationAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::ExclusiveRateOfChangeAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::ExclusiveRateOfChangeAlarm* createServerExclusiveRateOfChangeAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::ExclusiveRateOfChangeAlarm* createServerExclusiveRateOfChangeAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::ExclusiveRateOfChangeAlarm* createServerExclusiveRateOfChangeAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::DiscreteAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::DiscreteAlarm* createServerDiscreteAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::DiscreteAlarm* createServerDiscreteAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::DiscreteAlarm* createServerDiscreteAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::OffNormalAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::OffNormalAlarm* createServerOffNormalAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::OffNormalAlarm* createServerOffNormalAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::OffNormalAlarm* createServerOffNormalAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::TripAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::TripAlarm* createServerTripAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::TripAlarm* createServerTripAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::TripAlarm* createServerTripAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::NonExclusiveLimitAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::NonExclusiveLimitAlarm* createServerNonExclusiveLimitAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::NonExclusiveLimitAlarm* createServerNonExclusiveLimitAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::NonExclusiveLimitAlarm* createServerNonExclusiveLimitAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::NonExclusiveLevelAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::NonExclusiveLevelAlarm* createServerNonExclusiveLevelAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::NonExclusiveLevelAlarm* createServerNonExclusiveLevelAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::NonExclusiveLevelAlarm* createServerNonExclusiveLevelAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::NonExclusiveDeviationAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::NonExclusiveDeviationAlarm* createServerNonExclusiveDeviationAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::NonExclusiveDeviationAlarm* createServerNonExclusiveDeviationAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::NonExclusiveDeviationAlarm* createServerNonExclusiveDeviationAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::NonExclusiveRateOfChangeAlarm
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::NonExclusiveRateOfChangeAlarm* createServerNonExclusiveRateOfChangeAlarmEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::NonExclusiveRateOfChangeAlarm* createServerNonExclusiveRateOfChangeAlarmEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::NonExclusiveRateOfChangeAlarm* createServerNonExclusiveRateOfChangeAlarm(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::BaseEventNotification
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::BaseEventNotification* createServerBaseEventNotificationEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::BaseEventNotification* createServerBaseEventNotificationEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);
		/*! @overload */
		virtual Server::BaseEventNotification* createServerBaseEventNotification(TBHandle otbHandle);
#endif

#if TB5_HISTORY
		/*! Creates and returns an instance of class Server::HistoryReadRawContinuationPoint
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadRawContinuationPoint* createServerHistoryReadRawContinuationPoint(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoryReadProcessedContinuationPoint
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadProcessedContinuationPoint* createServerHistoryReadProcessedContinuationPoint(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoryReadEventContinuationPoint
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoryReadEventContinuationPoint* createServerHistoryReadEventContinuationPoint(TBHandle otbHandle);
#endif
		/*! Creates and returns an instance of class Server::BrowseContinuationPoint
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::BrowseContinuationPoint* createServerBrowseContinuationPoint(TBHandle otbHandle);

#if TB5_HISTORY
		/*! Creates and returns an instance of class Server::AggregateConfiguration
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::AggregateConfiguration* createServerAggregateConfiguration(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::HistoricalDataConfiguration
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::HistoricalDataConfiguration* createServerHistoricalDataConfiguration(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::AggregateFunction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::AggregateFunction* createServerAggregateFunction(TBHandle otbHandle);
#endif

		/*! Creates and returns an instance of class Server::CreateMonitoredItemRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::CreateMonitoredItemRequest* createServerCreateMonitoredItemRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::CreateMonitoredItemRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::ModifyMonitoredItemRequest* createServerModifyMonitoredItemRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::CreateMonitoredItemRequest
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Server::DeleteMonitoredItemRequest* createServerDeleteMonitoredItemRequest(TBHandle otbHandle);

		/*! Creates and returns an instance of class Server::DictionaryVariable
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::DictionaryVariable* createServerDictionaryVariableEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::DictionaryVariable* createServerDictionaryVariableEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class StructuredDataTypeDescription
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual StructuredDataTypeDescription* createStructuredDataTypeDescription(TBHandle otbHandle);

		/*! Creates and returns an instance of class FieldDescription
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual FieldDescription* createFieldDescription(TBHandle otbHandle);

		/*! Creates and returns an instance of class EnumerationDataTypeDescription
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual EnumerationDataTypeDescription* createEnumerationDataTypeDescription(TBHandle otbHandle);

		/*! Creates and returns an instance of class EnumeratedValueDescription
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual EnumeratedValueDescription* createEnumeratedValueDescription(TBHandle otbHandle);

		/*! For internal use only
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		Base* createInstanceFromHandle(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);

		/*! Creates and returns an instance of class Server::GetMonitoredItems
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::GetMonitoredItems* createServerGetMonitoredItemsEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::GetMonitoredItems* createServerGetMonitoredItemsEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::DataItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::DataItem* createServerDataItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::DataItem* createServerDataItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::DiscreteItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::DiscreteItem* createServerDiscreteItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::DiscreteItem* createServerDiscreteItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::TwoStateItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::TwoStateItem* createServerTwoStateItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::TwoStateItem* createServerTwoStateItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::MultiStateItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::MultiStateItem* createServerMultiStateItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::MultiStateItem* createServerMultiStateItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::MultiStateValueItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::MultiStateValueItem* createServerMultiStateValueItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::MultiStateValueItem* createServerMultiStateValueItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::AnalogItem
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::AnalogItem* createServerAnalogItemEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::AnalogItem* createServerAnalogItemEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::File
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::File* createServerFileEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::File* createServerFileEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Server::FileDirectory
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class
		* @param	pNodeId	NodeId of the object to be created
		* @param	pTypeNodeId	TypeNode of the object to be created
		* @param	xmlTag	XML tag of the node. From the XML tag additional information can be extracted. Only provided on creation via NodeSet import */
		virtual Server::FileDirectory* createServerFileDirectoryEx2(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId, const XmlElement& xmlTag);
		/*! @overload */
		virtual Server::FileDirectory* createServerFileDirectoryEx(TBHandle otbHandle, const INodeId* pNodeId, const INodeId* pTypeNodeId);

		/*! Creates and returns an instance of class Client::CertificateChangeTransaction
		* @param	otbHandle	internal handle used by the constructor of the appropriate API class */
		virtual Client::CertificateChangeTransaction* createClientCertificateChangeTransaction(TBHandle otbHandle);

	private:
		/*! Forbid use assignment operator */
		Creator& operator=(const Creator&);
		/*! Forbid use of copy constructor */
		Creator(const Creator&);
		/*! For internal use only */
		void releaseApiProtection(Base* pInstance);
	}; // end class
}// end toolbox namespace

#endif	// CREATOR_H
