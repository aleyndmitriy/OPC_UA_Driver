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

#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#include "OTExports.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


struct MonitoringChangeStruct;
struct ApplicationDescriptionStruct;
struct UserIdentityTokenStruct;
struct QueryDataSetStruct;
struct ParsingResultStruct;
struct ContentFilterResultStruct;
struct DataValueStruct;
struct HistoryReadResultStruct;
struct CallMethodResultStruct;
struct EventFieldListStruct;
struct SignatureDataStruct;
struct NodeIdStruct;
struct SignedSoftwareCertificateStruct;
struct QualifiedNameStruct;
struct ValueStruct;
struct BrowseResultStruct;
struct ByteStringStruct;
typedef ByteStringStruct XmlElementStruct;
struct GuidStruct;
struct DataSetMetaDataTypeStruct;
struct ConfigurationVersionDataTypeStruct;
struct RelativePathStruct;

#ifdef __cplusplus
extern "C"
{
#endif

	// prevent object from being destroyed
	typedef void (OTAPI_CALL *CB_OTLockObject)(TBHandle otbHandle);

	// release reference to locked object
	typedef void (OTAPI_CALL *CB_OTUnlockObject)(TBHandle otbHandle);

	// create API object of given type (see OTEnumApiClassType)
	typedef void* (OTAPI_CALL *CB_OTCreateObject)(TBHandle OTBObject, const NodeIdStruct* pNodeId, const NodeIdStruct* pTypeNodeId, const XmlElementStruct* pXmlTag);

	// registers the object (means object will not be deleted also if there is no reference anymore from the user impl)
	typedef void (OTAPI_CALL *CB_OTRegisterObject)(TBHandle OTBObject);

	// unregisters the object (removes delete protection of user created object)
	typedef void (OTAPI_CALL *CB_OTUnregisterObject)(TBHandle OTBObject);

	// unregisters all API objects
	typedef void (OTAPI_CALL *CB_OTUnregisterAll)();

	// callback to receive log messages
	// original (documented) definition is in Trace.h
	typedef void (OTAPI_CALL *CB_OnLogMessageCore)(const tstring& timeStamp,
		const tstring& traceLevel,
		OTUInt32 threadId,
		const tstring& traceGroup,
		const tstring& location,
		const tstring& message);

	typedef void (OTAPI_CALL *CB_OTTraceOnLogMessage)(CB_OnLogMessageCore pApiCallback,
		const OTChar* timeStamp,
		const OTChar* traceLevel,
		OTUInt32 threadId,
		const OTChar* traceGroup,
		const OTChar* location,
		const OTChar* message);

	// PubSub callback functions
	typedef void (OTAPI_CALL *CB_OTPConnectionStateChanged)(TBHandle otbHandle,
		EnumPubSubState newState);
	typedef void (OTAPI_CALL *CB_OTPStateChanged)(TBHandle otbHandle,
		EnumPubSubState newState);
	typedef void (OTAPI_CALL *CB_OTPStateChanged)(TBHandle otbHandle,
		EnumPubSubState newState);
	typedef void (OTAPI_CALL *CB_OTPConnectionStateChanged)(TBHandle otbHandle,
		EnumPubSubState newState);
	typedef void (OTAPI_CALL *CB_OTPSubscribedDataSetOnValuesReceived)(TBHandle otbHandle,
		ValueStruct* pPublisherId,
		GuidStruct* pDataSetClassId,
		OTUInt16 writerGroupId,
		OTUInt16 writerId,
		ConfigurationVersionDataTypeStruct* pConfigVersion,
		OTUInt32 valueCount,
		OTUInt32* pIndices,
		DataValueStruct** ppValues);
	typedef void (OTAPI_CALL *CB_OTPDataSetReaderOnMetaDataChanged)(TBHandle otbHandle,
		ValueStruct* pPublisherId,
		OTUInt16 writerId,
		EnumStatusCode responseStatus,
		DataSetMetaDataTypeStruct* pMeteData);

#if TB5_CLIENT
	// generated callback functions
	// callback function pointer for ClientMonitoredItem::onError
	typedef void (OTAPI_CALL *CB_OTCMonitoredItemOnError)(
			TBHandle otbHandle,
			EnumStatusCode enum_status);

	// callback function pointer for ClientMonitoredItem::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCMonitoredItemOnStatusChange)(
			TBHandle otbHandle,
			bool status);

	// callback function pointer for ClientSession::onError
	typedef void (OTAPI_CALL *CB_OTCSessionOnError)(
			TBHandle otbHandle,
			EnumStatusCode enum_status);

	// callback function pointer for ClientSession::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCSessionOnStatusChange)(
			TBHandle otbHandle,
			bool status);

	// callback function pointer for ClientSession::onCertificateChange
	typedef void (OTAPI_CALL *CB_OTCSessionOnCertificateChange)(
			TBHandle otbHandle,
			TBHandle transaction);

	// callback function pointer for ClientSession::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCSessionOnUpdateDictionariesComplete)(
			TBHandle otbHandle,
			void* requestHandle,
			EnumStatusCode updateResult);

	// callback function pointer for ClientSession::onReadComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnReadComplete)(
			TBHandle otbHandle,
			void* requestHandle,
			EnumStatusCode serviceResult,
			unsigned valuesCount,
			DataValueStruct* pValues);

#if TB5_HISTORY
	// callback function pointer for ClientSession::onHistoryReadRawComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnHistoryReadRawComplete)(
			TBHandle otbHandle,
			void* requestHandle,
			EnumStatusCode serviceResult,
			unsigned valuesCount,
			HistoryReadResultStruct* pValues);

	// callback function pointer for ClientSession::onHistoryReadRawComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnHistoryReadProcessedComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		HistoryReadResultStruct* pValues);
#endif

#if TB5_QUERY
	// callback function pointer for ClientSession::onQueryFirstComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnQueryFirstComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned queryDataSetsCount,
		QueryDataSetStruct* pQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		unsigned parsingResultsCount,
		ParsingResultStruct* pParsingResults,
		ContentFilterResultStruct* pFilterResult);

	// callback function pointer for ClientSession::onQueryNextComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnQueryNextComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned queryDataSetsCount,
		QueryDataSetStruct* pQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint);
#endif
	// callback function pointer for ClientSession::onWriteComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnWriteComplete)(
			TBHandle otbHandle,
			void* requestHandle,
			EnumStatusCode serviceResult,
			unsigned resultsCount,
			EnumStatusCode* pResults);

	// callback function pointer for ClientSession::onCallMethodsComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnCallMethodsComplete)(
			TBHandle otbHandle,
			void* requestHandle,
			EnumStatusCode serviceResult,
			unsigned resultsCount,
			CallMethodResultStruct* pCallMethodResults);

	// callback function pointer for ClientSession::onBrowseComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnBrowseComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		BrowseResultStruct* pResults);

	// callback function pointer for ClientSession::onBrowseNextComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnBrowseNextComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		BrowseResultStruct* pResults);

#if TB5_HISTORY
	// callback function pointer for ClientSession::onHistoryReadEventComplete
	typedef void (OTAPI_CALL *CB_OTCSessionOnHistoryReadEventComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		HistoryReadResultStruct* pValues);
#endif

	// callback function pointer for ClientRedundantSession::onError
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnError)(
		TBHandle otbHandle,
		EnumStatusCode enum_status,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnStatusChange)(
		TBHandle otbHandle,
		bool status,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onCertificateChange
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnCertificateChange)(
		TBHandle otbHandle,
		TBHandle transaction,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onUpdateDataTypesComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnUpdateDictionariesComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode updateResult,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onReadComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnReadComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		DataValueStruct* pValues,
		OTUInt32 redundantServerIndex);

#if TB5_HISTORY
	// callback function pointer for ClientRedundantSession::onHistoryReadRawComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnHistoryReadRawComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		HistoryReadResultStruct* pValues,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onHistoryReadRawComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnHistoryReadProcessedComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		HistoryReadResultStruct* pValues,
		OTUInt32 redundantServerIndex);
#endif

#if TB5_QUERY
	// callback function pointer for ClientRedundantSession::onQueryFirstComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnQueryFirstComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned queryDataSetsCount,
		QueryDataSetStruct* pQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		unsigned parsingResultsCount,
		ParsingResultStruct* pParsingResults,
		ContentFilterResultStruct* pFilterResult,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onQueryNextComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnQueryNextComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned queryDataSetsCount,
		QueryDataSetStruct* pQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint,
		OTUInt32 redundantServerIndex);
#endif

	// callback function pointer for ClientRedundantSession::onWriteComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnWriteComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		EnumStatusCode* pResults,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onCallMethodsComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnCallMethodsComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		CallMethodResultStruct* pCallMethodResults,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onBrowseComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnBrowseComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		BrowseResultStruct* pResults,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientRedundantSession::onBrowseNextComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnBrowseNextComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned resultsCount,
		BrowseResultStruct* pResults,
		OTUInt32 redundantServerIndex);

#if TB5_HISTORY
	// callback function pointer for ClientRedundantSession::onHistoryReadEventComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnHistoryReadEventComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		unsigned valuesCount,
		HistoryReadResultStruct* pValues,
		OTUInt32 redundantServerIndex);
#endif
	// callback function pointer for ClientRedundantSession::onServiceLevelChanged
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnServiceLevelChanged)(
		TBHandle otbHandle,
		OTUInt32 serviceLevelsCount,
		const DataValueStruct* serviceLevels,
		OTUInt32 primaryIndex);

	// callback function pointer for ClientRedundantSession::onSwitchoverComplete
	typedef void (OTAPI_CALL *CB_OTCRedundantSessionOnSwitchoverComplete)(
		TBHandle otbHandle,
		void* requestHandle,
		EnumStatusCode serviceResult,
		OTUInt32 statusCount,
		const bool* connectionStatus,
		OTUInt32 primaryIndex);

	// callback function pointer for ClientSubscription::onDataChange
	typedef void (OTAPI_CALL *CB_OTCSubscriptionOnDataChange)(
			TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items,
			unsigned valuesCount, DataValueStruct** pValues);

	// callback function pointer for ClientSubscription::onEventsReceived
	typedef void (OTAPI_CALL *CB_OTCSubscriptionOnEventsReceived)(
			TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items,
			unsigned valuesCount, EventFieldListStruct* pValues);

	// callback function pointer for ClientSubscription::onError
	typedef void (OTAPI_CALL *CB_OTCSubscriptionOnError)(
			TBHandle otbHandle,
			EnumStatusCode enum_status);

	// callback function pointer for ClientSubscription::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCSubscriptionOnStatusChange)(
			TBHandle otbHandle,
			bool status);

	// callback function pointer for ClientSubscription::onDataChange
	typedef void (OTAPI_CALL *CB_OTCRedundantSubscriptionOnDataChange)(
		TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items,
		unsigned valuesCount, DataValueStruct** pValues,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientSubscription::onEventsReceived
	typedef void (OTAPI_CALL *CB_OTCRedundantSubscriptionOnEventsReceived)(
		TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items,
		unsigned valuesCount, EventFieldListStruct* pValues,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientSubscription::onError
	typedef void (OTAPI_CALL *CB_OTCRedundantSubscriptionOnError)(
		TBHandle otbHandle,
		EnumStatusCode enum_status,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientSubscription::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCRedundantSubscriptionOnStatusChange)(
		TBHandle otbHandle,
		bool status,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientSubscription::onError
	typedef void (OTAPI_CALL *CB_OTCRedundantMonitoredItemOnError)(
		TBHandle otbHandle,
		EnumStatusCode enum_status,
		OTUInt32 redundantServerIndex);

	// callback function pointer for ClientSubscription::onStatusChange
	typedef void (OTAPI_CALL *CB_OTCRedundantMonitoredItemOnStatusChange)(
		TBHandle otbHandle,
		bool status,
		OTUInt32 redundantServerIndex);
#endif

	// callback function pointer for Application::handleMonitoringChange
	typedef EnumStatusCode (OTAPI_CALL *CB_OTBApplicationHandleMonitoringChange)(
			TBHandle otbHandle,
			OTUInt32 NodesCount, TBHandle* Nodes,
			OTUInt32 ChangesCount, MonitoringChangeStruct* pChanges);

	// callback function pointer for ServerMethod::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSMethodHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerEndpoint::authenticate
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSEndpointAuthenticate)(
			TBHandle otbHandle,
			UserIdentityTokenStruct* pUserIdentityToken,
			SignatureDataStruct* pSignature,
			TBHandle session,
			ApplicationDescriptionStruct* pApplicationUri,
			OTUInt32* userGroupIndex);

	// callback function pointer for Nodes when DataProvider changes
	typedef void (OTAPI_CALL *CB_OTSVariableOnDataProviderChanged)(
			TBHandle otbHandle,
			bool useDataProvider);

	// callback function pointer for ServerEndpoint::onCreateSession
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSEndpointOnCreateSession)(
			TBHandle otbHandle,
			TBHandle session);

	// callback function pointer for ServerEndpoint::handleDeleteSession
	typedef void (OTAPI_CALL *CB_OTSEndpointHandleDeleteSession)(
		TBHandle otbHandle,
		TBHandle request);

	// callback function pointer for ServerEndpoint::onInvalidCertificate
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSEndpointOnInvalidCertificate)(
			TBHandle otbHandle,
			EnumStatusCode enum_error,
			const ByteStringStruct* certificate,
			const OTChar* securityPolicy,
			EnumMessageSecurityMode enum_messageSecurityMode);

	// callback function pointer when a new secure channel was opened
	typedef void (OTAPI_CALL *CB_OTSEndpointOnSecureChannelOpened)(
			TBHandle otbHandle,
			EnumStatusCode result,
			const OTChar* secureChannelId,
			const ByteStringStruct* clientCertificate,
			const OTChar* clientCertificateThumbprint,
			EnumOpenRequest requestType,
			const OTChar* securityPolicy,
			EnumMessageSecurityMode securityMode,
			double requestedLifetime);

	// callback function pointer when a new session was created
	typedef void (OTAPI_CALL *CB_OTSEndpointOnSessionCreated)(
		TBHandle otbHandle,
		EnumStatusCode result,
		const OTChar*auditEntryId,
		const OTChar*secureChannelId,
		const ByteStringStruct * clientCertificate,
		const OTChar*clientCertificateThumbprint,
		TBHandle sessionHandle);

	// callback function pointer when the endpoint of a new session does not match the provided endpoint URLS
	typedef void (OTAPI_CALL *CB_OTSEndpointOnUrlMismatch)(
		TBHandle otbHandle,
		EnumStatusCode result,
		const OTChar*auditEntryId,
		const OTChar*secureChannelId,
		const ByteStringStruct * clientCertificate,
		const OTChar*clientCertificateThumbprint,
		TBHandle sessionHandle,
		const OTChar*endpointUrl);

	// callback function pointer when a new session was activated
	typedef void (OTAPI_CALL *CB_OTSEndpointOnSessionActivated)(
		TBHandle otbHandle,
		EnumStatusCode result,
		const OTChar *auditEntryId,
		const NodeIdStruct *sessionId,
		OTUInt32 signedSoftwareCertificateCount,
		const SignedSoftwareCertificateStruct *signedSoftwareCertificates,
		const UserIdentityTokenStruct *userIdentityToken);

	typedef void (OTAPI_CALL *CB_OTSSessionOnDeleteContinuationPoint)(
		TBHandle otbHandle, EnumContinuationPointType continuationPointType, TBHandle continuationPointHandle);

	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSessionOnRegisterNodes)(
		TBHandle otbHandle, unsigned nodeIdCount, const TBHandle* registeredNodeIds);

	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSessionOnUnregisterNodes)(
		TBHandle otbHandle, unsigned nodeIdCount, const TBHandle* registeredNodeIds);

	typedef void (OTAPI_CALL *CB_OTSSessionOnTransactionCancelled)(
		TBHandle otbHandle, EnumStatusCode result, OTUInt32 transactionId, const OTChar * auditEntryId);

	// callback function pointer for ServerSubscription::onDelete
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionOnDelete)(
			TBHandle otbHandle);

	// callback function pointer for ServerSubscription::onCreate
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionOnCreate)(
			TBHandle otbHandle);

	// callback function pointer for ServerSubscription::onModify
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionOnModify)(
			TBHandle otbHandle);

	// callback function pointer for ServerSubscription::handleDelete
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionHandleDelete)(
			TBHandle, TBHandle deleteRequest);

	// callback function pointer for ServerSubscription::onProvideInitialValues
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionOnProvideInitialValues)(
		TBHandle otbHandle,
		OTUInt32 monitoredItemsCount, TBHandle* monitoredItems, EnumInitialValueProvider* pInitialValueProviders);

	// callback function pointer for ServerSubscription::handleCreateMonitoredItems
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionHandleCreateMonitoredItems)(
		TBHandle otbHandle, OTUInt32 requestsCount, TBHandle* requests);

	// callback function pointer for ServerSubscription::handleModifyMonitoredItems
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionHandleModifyMonitoredItems)(
		TBHandle otbHandle, OTUInt32 requestsCount, TBHandle* requests);

	// callback function pointer for ServerSubscription::handleDeleteMonitoredItems
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSSubscriptionHandleDeleteMonitoredItems)(
		TBHandle otbHandle, OTUInt32 requestsCount, TBHandle* requests);

	// callback function pointer for ServerMonitoredItem::onSetTriggering
	typedef void (OTAPI_CALL *CB_OTSMonitoredItemOnSetTriggering)(
		TBHandle otbHandle,
		unsigned addedLinksCount, TBHandle* addedLinks,
		unsigned removedLinksCount, TBHandle* removedLinks);

	// callback function pointer for ServerReadTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSReadTransactionHandleRequests)(
			TBHandle otbHandle);

	// callback function pointer for ServerWriteTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSWriteTransactionHandleRequests)(
			TBHandle otbHandle);

#if TB5_HISTORY
	// callback function pointer for HistoryReadRawTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSHistoryReadRawTransactionHandleRequests)(
			TBHandle otbHandle);

	// callback function pointer for HistoryReadProcessedTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSHistoryReadProcessedTransactionHandleRequests)(
		TBHandle otbHandle);

	// callback function pointer for HistoryReadEventTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSHistoryReadEventTransactionHandleRequests)(
		TBHandle otbHandle);
#endif

	// callback function pointer for ServerMethodCallTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSMethodCallTransactionHandleRequests)(
			TBHandle otbHandle);

	// callback function pointer for ServerBrowseTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSBrowseTransactionHandleRequests)(
		TBHandle otbHandle);

	// callback function pointer for ServerBrowseNextTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSBrowseNextTransactionHandleRequests)(
		TBHandle otbHandle);

	// callback function pointer for ServerTranslateBrowsePathsToNodeIdsTransaction::handleRequests
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSTranslateBrowsePathsToNodeIdsTransactionHandleRequests)(
		TBHandle otbHandle);

#if TB5_ALARMS
	// callback function pointer for ServerCondition::onEnable
	typedef void (OTAPI_CALL *CB_OTSConditionOnEnable)(
			TBHandle otbHandle);

	// callback function pointer for ServerCondition::onDisable
	typedef void (OTAPI_CALL *CB_OTSConditionOnDisable)(
			TBHandle otbHandle);
#endif

	// callback function pointer for ServerCondition::onVariableChanged
	typedef void (OTAPI_CALL *CB_OTSConditionOnVariableChanged)(
			TBHandle otbHandle,
			TBHandle var,
			const DataValueStruct* pValue);

	// callback function pointer for ServerAcknowledgeableCondition::onAcknowledge
	typedef void (OTAPI_CALL *CB_OTSAcknowledgeableConditionOnAcknowledge)(
			TBHandle otbHandle);

	// callback function pointer for ServerAcknowledgeableCondition::onConfirm
	typedef void (OTAPI_CALL *CB_OTSAcknowledgeableConditionOnConfirm)(
			TBHandle otbHandle);

	// callback function pointer for ServerConditionEnable::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSConditionEnableHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerConditionDisable::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSConditionDisableHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerShelvedStateMachineTimedShelve::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSShelvedStateMachineTimedShelveHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerShelvedStateMachineOneShotShelve::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSShelvedStateMachineOneShotShelveHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerShelvedStateMachineUnshelve::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSShelvedStateMachineUnshelveHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerConditionAddComment::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSConditionAddCommentHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerAcknowledgeableConditionAcknowledge::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSAcknowledgeableConditionAcknowledgeHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerAcknowledgeableConditionConfirm::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSAcknowledgeableConditionConfirmHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerConditionRefresh::handleExecuteRequest
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSConditionRefreshHandleExecuteRequest)(
			TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request);

	// callback function pointer for ServerVariable::onDataValueChanged
	typedef void (OTAPI_CALL *CB_OTSVariableOnDataValueChanged)(
		TBHandle otbHandle,
		const DataValueStruct* pDataValue);


	// callback function pointer for AddressSpaceRoot::onIncrementNodeVersion
	typedef void(OTAPI_CALL *CB_OTSAddressSpaceRootOnIncrementNodeVersion)(
		TBHandle otbHandle,
		unsigned changedNodesCount,
		TBHandle* changesNodes);

	// callback function pointer for AddressSpaceRoot::onValidateError
	typedef void(OTAPI_CALL *CB_OTSAddressSpaceRootOnValidateError)(
		TBHandle otbHandle,
		const NodeIdStruct *nodeId,
		OTUInt16 severity,
		const OTChar* errorMessage);

	// callback function pointer for IContentFilterTarget::getTypeDefinitionId
	typedef EnumStatusCode(OTAPI_CALL *CB_OTSIContentFilterTargetGetTypeDefinitionId)(
		void* pApiHandle,
		NodeIdStruct* pTypeDefinitionId);

	// callback function pointer for IContentFilterTarget::getAttributeValue
	typedef EnumStatusCode(OTAPI_CALL *CB_OTSIContentFilterTargetGetAttributeValue)(
		void* pApiHandle,
		const QualifiedNameStruct* pBrowsePath,
		OTUInt32 browsePath_count,
		EnumAttributeId attributeId,
		ValueStruct* pAttributeValue);

	// callback function pointer for ServerBaseNode::onDataValueChanged
	typedef EnumStatusCode (OTAPI_CALL *CB_OTSNodeGenerateNodeIdForSubNode)(
		TBHandle otbHandle,
		RelativePathStruct* pRelativePath,
		NodeIdStruct* pNewNodeId);

	////////////////////////////////////////////////////////////////////////////////
	// Common callbacks
	typedef struct _OTCommonCallbackFunctions
	{
		// callback Application::handleMonitoringChange
		CB_OTBApplicationHandleMonitoringChange m_OTBApplicationHandleMonitoringChange;
		CB_OTLockObject m_OTLockObject;
		CB_OTUnlockObject m_OTUnlockObject;
		CB_OTCreateObject m_OTCreateApiObject;
		CB_OTRegisterObject m_OTRegisterApiObject;
		CB_OTUnregisterObject m_OTUnregisterApiObject;
		CB_OTUnregisterAll m_OTUnregisterAll;
		CB_OTTraceOnLogMessage m_OTTraceOnLogMessage;
	}
	OTCommonCallbackFunctions;

	////////////////////////////////////////////////////////////////////////////////
	// Common callbacks
	typedef struct _OTPubSubCallbackFunctions
	{
		// callback Connection::onStateChanged
		CB_OTPStateChanged m_OTPConnectionOnStateChanged;
		// callback Group::onStateChanged
		CB_OTPStateChanged m_OTPGroupOnStateChanged;
		// callback DataSetWriter::onStateChanged
		CB_OTPStateChanged m_OTPDataSetWriterOnStateChanged;
		// callback DataSetReader::onStateChanged
		CB_OTPStateChanged m_OTPDataSetReaderOnStateChanged;
		// callback SubscribedDataSet::onValuesReceived
		CB_OTPSubscribedDataSetOnValuesReceived m_OTPSubscribedDataSetOnValuesReceived;
		// callback SubscribedDataSet::onValuesReceived
		CB_OTPDataSetReaderOnMetaDataChanged m_OTPDataSetReaderOnMetaDataChanged;
	}
	OTPubSubCallbackFunctions;

#if TB5_CLIENT
	////////////////////////////////////////////////////////////////////////////////
	// client callbacks
	typedef struct _OTClientSessionCallbackFunctions
	{
		// callback ClientSession::onError
		CB_OTCSessionOnError m_OTCSessionOnError;
		// callback ClientSession::onStatusChange
		CB_OTCSessionOnStatusChange m_OTCSessionOnStatusChange;
		// callback ClientSession::onCertificateChange
		CB_OTCSessionOnCertificateChange m_OTCSessionOnCertificateChange;
		// callback ClientSession::onUpdateDataTypesComplete
		CB_OTCSessionOnUpdateDictionariesComplete m_OTCSessionOnUpdateDictionariesComplete;
		// callback ClientSession::onReadComplete
		CB_OTCSessionOnReadComplete m_OTCSessionOnReadComplete;
#if TB5_HISTORY
		// callback ClientSession::onHistoryReadRawComplete
		CB_OTCSessionOnHistoryReadRawComplete m_OTCSessionOnHistoryReadRawComplete;
		// callback ClientSession::onHistoryReadProcessedComplete
		CB_OTCSessionOnHistoryReadProcessedComplete m_OTCSessionOnHistoryReadProcessedComplete;
#endif
#if TB5_QUERY
		// callback ClientSession::onQueryFirstComplete
		CB_OTCSessionOnQueryFirstComplete m_OTCSessionOnQueryFirstComplete;
		// callback ClientSession::onQueryNextComplete
		CB_OTCSessionOnQueryNextComplete m_OTCSessionOnQueryNextComplete;
#endif
		// callback ClientSession::onWriteComplete
		CB_OTCSessionOnWriteComplete m_OTCSessionOnWriteComplete;
		// callback ClientSession::onCallMethodsComplete
		CB_OTCSessionOnCallMethodsComplete m_OTCSessionOnCallMethodsComplete;
		// callback ClientSession::onBrowseComplete
		CB_OTCSessionOnBrowseComplete m_OTCSessionOnBrowseComplete;
		// callback ClientSession::onBrowseNextComplete
		CB_OTCSessionOnBrowseNextComplete m_OTCSessionOnBrowseNextComplete;
#if TB5_HISTORY
		// callback ClientSession::onHistoryReadEventComplete
		CB_OTCSessionOnHistoryReadEventComplete m_OTCSessionOnHistoryReadEventComplete;
#endif
	}
	OTClientSessionCallbackFunctions;

	typedef struct _OTClientRedundantSessionCallbackFunctions
	{
		// callback ClientRedundantSession::onError
		CB_OTCRedundantSessionOnError m_OTCRedundantSessionOnError;
		// callback ClientRedundantSession::onStatusChange
		CB_OTCRedundantSessionOnStatusChange m_OTCRedundantSessionOnStatusChange;
		// callback ClientRedundantSession::OnCertificateChange
		CB_OTCRedundantSessionOnCertificateChange m_OTCRedundantSessionOnCertificateChange;
		// callback ClientRedundantSession::OnUpdateDictionariesComplete
		CB_OTCRedundantSessionOnUpdateDictionariesComplete m_OTCRedundantSessionOnUpdateDictionariesComplete;
		// callback ClientRedundantSession::onReadComplete
		CB_OTCRedundantSessionOnReadComplete m_OTCRedundantSessionOnReadComplete;
#if TB5_HISTORY
		// callback ClientRedundantSession::onHistoryReadRawComplete
		CB_OTCRedundantSessionOnHistoryReadRawComplete m_OTCRedundantSessionOnHistoryReadRawComplete;
		// callback ClientRedundantSession::onHistoryReadProcessedComplete
		CB_OTCRedundantSessionOnHistoryReadProcessedComplete m_OTCRedundantSessionOnHistoryReadProcessedComplete;
		// callback ClientRedundantSession::onQueryFirstComplete
#endif
#if TB5_QUERY
		CB_OTCRedundantSessionOnQueryFirstComplete m_OTCRedundantSessionOnQueryFirstComplete;
		// callback ClientRedundantSession::onQueryNextComplete
		CB_OTCRedundantSessionOnQueryNextComplete m_OTCRedundantSessionOnQueryNextComplete;
		// callback ClientRedundantSession::onWriteComplete
#endif
		CB_OTCRedundantSessionOnWriteComplete m_OTCRedundantSessionOnWriteComplete;
		// callback ClientRedundantSession::onCallMethodsComplete
		CB_OTCRedundantSessionOnCallMethodsComplete m_OTCRedundantSessionOnCallMethodsComplete;
		// callback ClientRedundantSession::onBrowseComplete
		CB_OTCRedundantSessionOnBrowseComplete m_OTCRedundantSessionOnBrowseComplete;
		// callback ClientRedundantSession::onBrowseComplete
		CB_OTCRedundantSessionOnBrowseNextComplete m_OTCRedundantSessionOnBrowseNextComplete;
#if TB5_HISTORY
		// callback ClientRedundantSession::onHistoryReadEventComplete
		CB_OTCRedundantSessionOnHistoryReadEventComplete m_OTCRedundantSessionOnHistoryReadEventComplete;
#endif
		// callback ClientRedundantSession::onServiceLevelChanged
		CB_OTCRedundantSessionOnServiceLevelChanged m_OTCRedundantSessionOnServiceLevelChanged;
		// callback ClientRedundantSession::onSwitchoverComplete
		CB_OTCRedundantSessionOnSwitchoverComplete m_OTCRedundantSessionOnSwitchoverComplete;
	}
	OTClientRedundantSessionCallbackFunctions;

	typedef struct _OTClientSubscriptionCallbackFunctions
	{
		// callback ClientSubscription::onDataChange
		CB_OTCSubscriptionOnDataChange m_OTCSubscriptionOnDataChange;
		// callback ClientSubscription::onEventsReceived
		CB_OTCSubscriptionOnEventsReceived m_OTCSubscriptionOnEventsReceived;
		// callback ClientSubscription::onError
		CB_OTCSubscriptionOnError m_OTCSubscriptionOnError;
		// callback ClientSubscription::onStatusChange
		CB_OTCSubscriptionOnStatusChange m_OTCSubscriptionOnStatusChange;
	}
	OTClientSubscriptionCallbackFunctions;

	typedef struct _OTClientRedundantSubscriptionCallbackFunctions
	{
		// callback ClientRdundantSubscription::onDataChange
		CB_OTCRedundantSubscriptionOnDataChange m_OTCRedundantSubscriptionOnDataChange;
		// callback ClientRdundantSubscription::onEventsReceived
		CB_OTCRedundantSubscriptionOnEventsReceived m_OTCRedundantSubscriptionOnEventsReceived;
		// callback ClientRdundantSubscription::onError
		CB_OTCRedundantSubscriptionOnError m_OTCRedundantSubscriptionOnError;
		// callback ClientRdundantSubscription::onStatusChange
		CB_OTCRedundantSubscriptionOnStatusChange m_OTCRedundantSubscriptionOnStatusChange;
	}
	OTClientRedundantSubscriptionCallbackFunctions;

	typedef struct _OTClientMonitoredItemCallbackFunctions
	{
		// callback ClientMonitoredItem::onError
		CB_OTCMonitoredItemOnError m_OTCMonitoredItemOnError;
		// callback ClientMonitoredItem::onStatusChange
		CB_OTCMonitoredItemOnStatusChange m_OTCMonitoredItemOnStatusChange;
	}
	OTClientMonitoredItemCallbackFunctions;

	typedef struct _OTClientRedundantMonitoredItemCallbackFunctions
	{
		// callback ClientRdundantSubscription::onError
		CB_OTCRedundantMonitoredItemOnError m_OTCRedundantMonitoredItemOnError;
		// callback ClientRdundantSubscription::onStatusChange
		CB_OTCRedundantMonitoredItemOnStatusChange m_OTCRedundantMonitoredItemOnStatusChange;
	}
	OTClientRedundantMonitoredItemCallbackFunctions;
#endif

	////////////////////////////////////////////////////////////////////////////////
	// server callbacks
	typedef struct _OTServerCallbackFunctions
	{
		// callback ServerMethod::handleExecuteRequest
		CB_OTSMethodHandleExecuteRequest m_OTSMethodHandleExecuteRequest;
		// callback ServerEndpoint::authenticate
		CB_OTSEndpointAuthenticate m_OTSEndpointAuthenticate;
		// callback ServerVariable::onDataProiderChanged
		CB_OTSVariableOnDataProviderChanged m_OTSVariableOnDataProviderChanged;
		// callback ServerEndpoint::onCreateSession
		CB_OTSEndpointOnCreateSession m_OTSEndpointOnCreateSession;
		// callback ServerEndpoint::handleDeleteSession
		CB_OTSEndpointHandleDeleteSession m_OTSEndpointHandleDeleteSession;
		// callback ServerEndpoint::onInvalidCertificate
		CB_OTSEndpointOnInvalidCertificate m_OTSEndpointOnInvalidCertificate;
		// callback ServerEndpoint::onSecureChannelOpened
		CB_OTSEndpointOnSecureChannelOpened m_OTSEndpointSecureChannelOpened;
		// callback ServerEndpoint::onSessionCreated
		CB_OTSEndpointOnSessionCreated m_OTSEndpointOnSessionCreated;
		// callback ServerEndpoint::onUrlMismatch
		CB_OTSEndpointOnUrlMismatch m_OTSEndpointOnUrlMismatch;
		// callback ServerEndpoint::onSessionActivated
		CB_OTSEndpointOnSessionActivated m_OTSEndpointOnSessionActivated;
		// callback ServerSession::onDeleteContinuationPoint
		CB_OTSSessionOnDeleteContinuationPoint m_OTSSessionOnDeleteContinuationPoint;
		// callback ServerSession::onRegisterNodes
		CB_OTSSessionOnRegisterNodes m_OTSSessionOnRegisterNodes;
		// callback ServerSession::onRegisterNodes
		CB_OTSSessionOnUnregisterNodes m_OTSSessionOnUnregisterNodes;
		// callback ServerSession::onRegisterNodes
		CB_OTSSessionOnTransactionCancelled m_OTSSessionOnTransactionCancelled;
		// callback ServerSubscription::onCreate
		CB_OTSSubscriptionOnCreate m_OTSSubscriptionOnCreate;
		// callback ServerSubscription::onModify
		CB_OTSSubscriptionOnModify m_OTSSubscriptionOnModify;
		// callback ServerSubscription::handleDelete
		CB_OTSSubscriptionHandleDelete m_OTSSubscriptionHandleDelete;
		// callback ServerSubscription::onProvideInitialValues
		CB_OTSSubscriptionOnProvideInitialValues m_OTSSubscriptionOnProvideInitialValues;
		// callback ServerSubscription::handleCreateMonitoredItems
		CB_OTSSubscriptionHandleCreateMonitoredItems m_OTSSubscriptionHandleCreateMonitoredItems;
		// callback ServerSubscription::handleModifyMonitoredItems
		CB_OTSSubscriptionHandleModifyMonitoredItems m_OTSSubscriptionHandleModifyMonitoredItems;
		// callback ServerSubscription::handleDeleteMonitoredItems
		CB_OTSSubscriptionHandleDeleteMonitoredItems m_OTSSubscriptionHandleDeleteMonitoredItems;
		// callback ServerMonitoredItem::onSetTriggering
		CB_OTSMonitoredItemOnSetTriggering m_OTSMonitoredItemOnSetTriggering;
		// callback ServerReadTransaction::handleRequests
		CB_OTSReadTransactionHandleRequests m_OTSReadTransactionHandleRequests;
		// callback ServerWriteTransaction::handleRequests
		CB_OTSWriteTransactionHandleRequests m_OTSWriteTransactionHandleRequests;
#if TB5_HISTORY
		// callback HistoryReadRawTransaction::handleRequests
		CB_OTSHistoryReadRawTransactionHandleRequests m_OTSHistoryReadRawTransactionHandleRequests;
		// callback HistoryReadProcessedTransaction::handleRequests
		CB_OTSHistoryReadProcessedTransactionHandleRequests m_OTSHistoryReadProcessedTransactionHandleRequests;
		// callback HistoryReadEventTransaction::handleRequests
		CB_OTSHistoryReadEventTransactionHandleRequests m_OTSHistoryReadEventTransactionHandleRequests;
		// callback ServerMethodCallTransaction::handleRequests
#endif
		CB_OTSMethodCallTransactionHandleRequests m_OTSMethodCallTransactionHandleRequests;
		// callback ServerBrowseTransaction::handleRequests
		CB_OTSBrowseTransactionHandleRequests m_OTSBrowseTransactionHandleRequests;
		// callback ServerBrowseNextTransaction::handleRequests
		CB_OTSBrowseNextTransactionHandleRequests m_OTSBrowseNextTransactionHandleRequests;
		// callback ServerBrowseNextTransaction::handleRequests
		CB_OTSTranslateBrowsePathsToNodeIdsTransactionHandleRequests m_OTSTranslateBrowsePathsToNodeIdsTransactionHandleRequests;
#if TB5_ALARMS
		// callback ServerCondition::onEnable
		CB_OTSConditionOnEnable m_OTSConditionOnEnable;
		// callback ServerCondition::onDisable
		CB_OTSConditionOnDisable m_OTSConditionOnDisable;
		// callback ServerCondition::onVariableChanged
		CB_OTSConditionOnVariableChanged m_OTSConditionOnVariableChanged;
		// callback ServerAcknowledgeableCondition::onAcknowledge
		CB_OTSAcknowledgeableConditionOnAcknowledge m_OTSAcknowledgeableConditionOnAcknowledge;
		// callback ServerAcknowledgeableCondition::onConfirm
		CB_OTSAcknowledgeableConditionOnConfirm m_OTSAcknowledgeableConditionOnConfirm;
#endif
		// callback ServerVariable::onDataValueChanged
		CB_OTSVariableOnDataValueChanged m_OTSVariableOnDataValueChanged;
		// callback ServerAddressSpaceRoot::onIncrementNodeVersion
		CB_OTSAddressSpaceRootOnIncrementNodeVersion m_OTSAddressSpaceRootOnIncrementNodeVersion;
		// callback ServerAddressSpaceRoot::onValidateError
		CB_OTSAddressSpaceRootOnValidateError m_OTSAddressSpaceRootOnValidateError;
		// callback IContentFilterTarget::getTypeDefinitionId
		CB_OTSIContentFilterTargetGetTypeDefinitionId m_OTSIContentFilterTargetGetTypeDefinitionId;
		// callback IContentFilterTarget::getAttributeValue
		CB_OTSIContentFilterTargetGetAttributeValue m_OTSIContentFilterTargetGetAttributeValue;
		// callback 
		CB_OTSNodeGenerateNodeIdForSubNode m_OTSNodeGenerateNodeIdForSubNode;

	}
	OTServerCallbackFunctions;


#ifdef __cplusplus
}
#endif

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _CALLBACKS_H_
