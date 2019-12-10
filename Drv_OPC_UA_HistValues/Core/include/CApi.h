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

#ifndef _C_API_H_
#define _C_API_H_

#include "OTExports.h"
#include "OSCompat.h"
#include "OTTypes.h"
#include "Callbacks.h"

// Forward declarations
struct AccessPatternStruct;
struct AggregateConfigurationStruct;
struct AnonymousIdentityTokenStruct;
struct ApplicationDescriptionStruct;
struct ArgumentStruct;
struct AttributeOperandStruct;
struct BrowseDescriptionStruct;
struct BrowsePathResultStruct;
struct BrowsePathStruct;
struct BrowsePathTargetStruct;
struct BrowseResultStruct;
struct BuildInfoStruct;
struct ByteStringStruct;
struct CallMethodRequestStruct;
struct CallMethodResultStruct;
struct ContentFilterElementResultStruct;
struct ContentFilterElementStruct;
struct ContentFilterResultStruct;
struct ContentFilterStruct;
struct DataChangeFilterStruct;
struct DataValueStruct;
struct DateTimeStruct;
struct DiagnosticInfoStruct;
struct EUInformationStruct;
struct ElementOperandStruct;
struct EndpointDescriptionStruct;
struct EventFieldListStruct;
struct EventFilterStruct;
struct ExpandedNodeIdStruct;
struct FilterOperandStruct;
struct GuidStruct;
#if TB5_HISTORY
struct HistoryDataExtensionObjectStruct;
struct HistoryDataStruct;
struct HistoryEventFieldListStruct;
struct HistoryEventStruct;
struct HistoryReadDetailsStruct;
struct HistoryReadResultStruct;
struct HistoryReadValueIdStruct;
#endif
struct IssuedIdentityTokenStruct;
struct LiteralOperandStruct;
#include "LocalizedTextStruct.h" // C API requires definition of OTTextId
struct ModelChangeStructureDataTypeStruct;
struct MonitoringChangeStruct;
struct NodeIdStruct;
struct NodeTypeDescriptionStruct;
struct NumericRangeStruct;
struct ParsingResultStruct;
struct PkiStoreConfigurationStruct;
struct QualifiedNameStruct;
#if TB5_QUERY
struct QueryDataDescriptionStruct;
struct QueryDataSetStruct;
#endif
struct RangeStruct;
struct ReadEventDetailsStruct;
struct ReadProcessedDetailsStruct;
struct ReadRawModifiedDetailsStruct;
struct ReadValueIdStruct;
struct ReferenceDescriptionStruct;
struct RelativePathElementStruct;
struct RelativePathStruct;
struct SemanticChangeStructureDataTypeStruct;
struct ServerDiagnosticsSummaryDataTypeStruct;
struct ServerStatusDataTypeStruct;
struct ServiceCounterDataTypeStruct;
struct SessionDiagnosticsDataTypeStruct;
struct SessionSecurityDiagnosticsDataTypeStruct;
struct SignatureDataStruct;
struct SignedSoftwareCertificateStruct;
struct SimpleAttributeOperandStruct;
struct SubscriptionDiagnosticsDataTypeStruct;
struct TimeZoneStruct;
struct UserIdentityTokenStruct;
struct UserNameIdentityTokenStruct;
struct UserTokenPolicyStruct;
struct ValueStruct;
struct ViewDescriptionStruct;
struct WriteValueStruct;
struct X509IdentityTokenStruct;
struct EnumValueTypeStruct;
struct ConfigurationVersionDataTypeStruct;
struct DatagramConnectionTransportDataTypeStruct;
struct NetworkAddressDataTypeStruct;
struct DatagramWriterGroupTransportDataTypeStruct;
struct DataSetMetaDataTypeStruct;
struct DataSetReaderDataTypeStruct;
struct DataSetWriterDataTypeStruct;
struct DataTypeDescriptionStruct;
struct DataTypeSchemaHeaderStruct;
struct EnumDefinitionStruct;
struct EnumDescriptionStruct;
struct EnumFieldStruct;
struct FieldMetaDataStruct;
struct FieldTargetDataTypeStruct;
struct KeyValuePairStruct;
struct NetworkAddressUrlDataTypeStruct;
struct PublishedDataItemsDataTypeStruct;
struct PublishedDataSetDataTypeStruct;
struct PublishedDataSetDataTypeStruct;
struct PublishedEventsDataTypeStruct;
struct PublishedVariableDataTypeStruct;
struct PubSubConfigurationDataTypeStruct;
struct PubSubConnectionDataTypeStruct;
struct PubSubGroupDataTypeStruct;
struct ReaderGroupDataTypeStruct;
struct RolePermissionTypeStruct;
struct SimpleTypeDescriptionStruct;
struct StructureDefinitionStruct;
struct StructureDescriptionStruct;
struct StructureFieldStruct;
struct SubscribedDataSetMirrorDataTypeStruct;
struct TargetVariablesDataTypeStruct;
struct UadpDataSetReaderMessageDataTypeStruct;
struct UadpDataSetWriterMessageDataTypeStruct;
struct UadpWriterGroupMessageDataTypeStruct;
struct WriterGroupDataTypeStruct;
struct DataSetReaderTransportDataTypeStruct;
struct PublishedDataSetSourceDataTypeStruct;
struct WriterGroupTransportDataTypeStruct;
struct DataSetWriterTransportDataTypeStruct;
struct DataSetWriterMessageDataTypeStruct;
struct WriterGroupMessageDataTypeStruct;
struct ConnectionTransportDataTypeStruct;
struct NetworkAddressDataTypeStruct;
struct ReaderGroupTransportDataTypeStruct;
struct ReaderGroupMessageDataTypeStruct;
struct DataSetReaderTransportDataTypeStruct;
struct DataSetReaderMessageDataTypeStruct;
struct SubscribedDataSetDataTypeStruct;


#ifdef __cplusplus
extern "C"
{
#endif
	TBCORE_IF void OTAPI_CALL OTRegisterApiObject(TBHandle otbHandle, void* apiHandle);
	TBCORE_IF void OTAPI_CALL OTUnregisterApiObject(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTProtectApiObject(TBHandle otbHandle, bool protect);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReleaseApiRef(TBHandle otbHandle, EnumStatusCode* pReturn);
	TBCORE_IF void OTAPI_CALL OTTakeCreationRefcount(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTReleaseCreationRefcount(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCommonAdvise(IN OTCommonCallbackFunctions* pCallbacks);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubAdvise(IN OTPubSubCallbackFunctions* pCallbacks);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerAdvise(IN OTServerCallbackFunctions* pCallbacks);
#if TB5_CLIENT
	TBCORE_IF EnumStatusCode OTAPI_CALL OTClientAdvise(IN OTClientSessionCallbackFunctions* pSessionCallbacks,
		IN OTClientSubscriptionCallbackFunctions* pSubscriptionCallbacks, IN OTClientMonitoredItemCallbackFunctions* pMonitoredItemCallbacks,
		IN OTClientRedundantSessionCallbackFunctions* pRedundantSessionCallbacks, IN OTClientRedundantSubscriptionCallbackFunctions* pRedundantSubscriptionCallbacks,
		IN OTClientRedundantMonitoredItemCallbackFunctions* pRedundantMonitoredItemCallbacks);
#endif

	TBCORE_IF const OTChar* OTAPI_CALL OTGetErrorText(EnumStatusCode code);

	////////////////////////////////////////////////////////////////////////////////
	// Few missing exported methods
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeSet(void* pTarget, const void* pSource);
	TBCORE_IF int OTAPI_CALL OTDateTimeCompare(const void* pSource, const void* pTarget);
#ifdef SOOS_WINDOWS
	TBCORE_IF void OTAPI_CALL OTDateTimeSetFileTime(void* pTarget, const FILETIME& fileTime);
	TBCORE_IF void OTAPI_CALL OTDateTimeGetFileTime(const void* pTarget, FILETIME& fileTimefileTime);
#endif
	TBCORE_IF OTChar* OTAPI_CALL OTDateToString(const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateFromString(const void* pTarget, const OTChar* dateStr);
	TBCORE_IF void OTAPI_CALL OTDateTimeUtcNow(void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeMilliSecond(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeMilliSecondGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeSecond(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeSecondGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMinute(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMinuteGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeHour(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeHourGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeDay(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeDayGMT(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMonth(const void* pTarget);
	TBCORE_IF OTUInt16 OTAPI_CALL OTDateTimeMonthGMT(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeYear(const void* pTarget);
	TBCORE_IF OTUInt32 OTAPI_CALL OTDateTimeYearGMT(const void* pTarget);
	TBCORE_IF OTUInt64 OTAPI_CALL OTDateTimeDurationMilliseconds(const void* pFrom, const void* pTo);
	TBCORE_IF void OTAPI_CALL OTDateTimeAddMilliseconds(void* pTarget, OTUInt64 milliseconds);
	TBCORE_IF void OTAPI_CALL OTDateTimeSubtractMilliseconds(void* pTarget, OTUInt64 milliseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeIsNull(void* pTarget, bool* pIsNull);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDateTimeClear(DateTimeStruct* pTarget);
	TBCORE_IF int OTGetEnumerationValue(const OTChar* str, EnumGroup group, bool inclusiveUnknown, bool traceUnknown);
	TBCORE_IF const OTChar* OTGetEnumerationString(unsigned enumValue, EnumGroup group, bool inclusiveUnknown);
	TBCORE_IF void OTAPI_CALL OTGuidSet(GuidStruct* pTarget, const GuidStruct* pSource);
	TBCORE_IF int OTAPI_CALL OTGuidCompare(const GuidStruct* pSource, const GuidStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidGenerate(GuidStruct* pTarget);
	TBCORE_IF OTChar* OTAPI_CALL OTGuidToString(const GuidStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidFromString(const OTChar* guidString, GuidStruct* pGuid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTGuidClear(GuidStruct* pGuid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTInit(OT_Memory_Alloc_Func pAlloc, OT_Memory_ReAlloc_Func pRealloc, OT_Memory_Free_Func pFree, bool spawnThreadPerSession);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExit();
	TBCORE_IF void OTAPI_CALL OTThreadCleanup();
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSeedPrngState(const ByteStringStruct* pEntropy);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetNumeric(NodeIdStruct* pTarget, unsigned short namespaceIndex, OTUInt32 numeric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetString(NodeIdStruct* pTarget, unsigned short namespaceIndex, const OTChar* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetGuid(NodeIdStruct* pTarget, unsigned short namespaceIndex, const GuidStruct* guid);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetOpaque(NodeIdStruct* pTarget, unsigned short namespaceIndex, const ByteStringStruct* byteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSetNull(NodeIdStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTNodeIdIsNull(const NodeIdStruct* pTarget);
	TBCORE_IF OTChar* OTAPI_CALL OTNodeIdToString(const NodeIdStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTNodeIdAreEqual(const NodeIdStruct* pNodeId1, const NodeIdStruct* pNodeId2);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdParse(const OTChar* pString, NodeIdStruct* pNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCreateNodeId(NodeIdStruct* pTargetNodeId, EnumIdentifierType identifierType, unsigned short namespaceIndex);

	TBCORE_IF OTChar* OTAPI_CALL OTExpandedNodeIdToString(const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ValueStruct
	////////////////////////////////////////////////////////////////////////////////
	/*! @brief stands for copy constructor. */
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSet(ValueStruct* pTarget, const ValueStruct* pValue);
	TBCORE_IF void OTAPI_CALL OTValueClear(ValueStruct* pTarget);
	TBCORE_IF bool OTAPI_CALL OTValueAreEqual(ValueStruct* pVal1, ValueStruct* pVal2);
	TBCORE_IF OTChar* OTAPI_CALL OTValueToString(const ValueStruct* pTarget);
	TBCORE_IF int OTAPI_CALL OTValueCompare(const ValueStruct* pSource, const ValueStruct* pTarget);

	TBCORE_IF void OTAPI_CALL OTValueSetBoolean(ValueStruct* pTarget, OTBoolean value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt8(ValueStruct* pTarget, OTUInt8 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt8(ValueStruct* pTarget, OTInt8 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt16(ValueStruct* pTarget, OTUInt16 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt16(ValueStruct* pTarget, OTInt16 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt32(ValueStruct* pTarget, OTUInt32 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt32(ValueStruct* pTarget, OTInt32 value);
	TBCORE_IF void OTAPI_CALL OTValueSetUInt64(ValueStruct* pTarget, OTUInt64 value);
	TBCORE_IF void OTAPI_CALL OTValueSetInt64(ValueStruct* pTarget, OTInt64 value);
	TBCORE_IF void OTAPI_CALL OTValueSetFloat(ValueStruct* pTarget, OTFloat value);
	TBCORE_IF void OTAPI_CALL OTValueSetDouble(ValueStruct* pTarget, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetString(ValueStruct* pTarget, const OTChar* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetByteString(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetXmlElement(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDateTime(void* pTarget, const void* pValue);
	TBCORE_IF void OTAPI_CALL OTValueSetStatusCode(ValueStruct* pTarget, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetGuid(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetExpandedNodeId(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetQualifiedName(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEUInformation(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetTimeZone(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetRange(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetReferenceDescription(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetApplicationDescription(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerDiagnosticsSummaryDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubscriptionDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionSecurityDiagnosticsDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServiceCounterDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSemanticChangeStructureDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetModelChangeStructureDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetArgument(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetLocalizedText(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDataValue(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeId(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUserIdentityToken(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetVariant(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeId(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSignedSoftwareCertificate(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBuildInfo(void* pTarget, const void* pValue);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEventFilter(void* pTarget, const void* pValue);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerStatusDataType(void* pTarget, const void* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEnumValueType(void* pTarget, const void* pValue);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetComplexRaw(const ValueStruct* pTarget, NodeIdStruct* encodingNodeId, ByteStringStruct* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetComplexRaw(ValueStruct* pTarget, const NodeIdStruct* encodingNodeId, const ByteStringStruct* pValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetComplexRawArray(const ValueStruct* pTarget, EnumValueArrayType expectedArrayType, NodeIdStruct* encodingId, OTUInt32* pValueCount, ByteStringStruct** ppValues,
		OTUInt32* pNoOfArrayDimensions, OTUInt32** ppArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetComplexRawArray(ValueStruct* pTarget, EnumValueArrayType valueArrayType, const NodeIdStruct* encodingId, size_t valueCount, ByteStringStruct** ppValues,
		OTUInt32 noOfArrayDimensions, const OTUInt32* pArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetStructureFields(const ValueStruct* pTarget, TBHandle typeDescHandle, size_t *pFieldCount, ValueStruct*** pppArray);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStructureFields(ValueStruct* pTarget, TBHandle typeDescHandle, size_t fieldCount, const ValueStruct* const* pArray);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetStructureFieldsArray(const ValueStruct* pTarget, EnumValueArrayType expectedArrayType,
		TBHandle typeDescHandle, size_t* pCounterSize, size_t** ppCounterArray, ValueStruct**** ppppFieldArrays,
		OTUInt32* pNoOfArrayDimensions, OTUInt32** ppArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStructureFieldsArray(ValueStruct* pTarget, EnumValueArrayType valueArrayType,
		TBHandle typeDescHandle, size_t counterSize, size_t* pCounterArray, ValueStruct*** pppFieldArrays,
		OTUInt32 noOfArrayDimensions, const OTUInt32* pArrayDimensions);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBooleanArray(ValueStruct* pTarget, const OTBoolean* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBooleanMatrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTBoolean* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt8Array(ValueStruct* pTarget, const OTUInt8* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt8Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTUInt8* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt8Array(ValueStruct* pTarget, const OTInt8* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt8Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTInt8* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt16Array(ValueStruct* pTarget, const OTUInt16* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt16Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTUInt16* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt16Array(ValueStruct* pTarget, const OTInt16* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt16Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTInt16* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt32Array(ValueStruct* pTarget, const OTUInt32* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt32Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTUInt32* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt32Array(ValueStruct* pTarget, const OTInt32* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt32Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTInt32* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt64Array(ValueStruct* pTarget, const OTUInt64* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUInt64Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTUInt64* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt64Array(ValueStruct* pTarget, const OTInt64* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetInt64Matrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTInt64* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetFloatArray(ValueStruct* pTarget, const OTFloat* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetFloatMatrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTFloat* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDoubleArray(ValueStruct* pTarget, const OTDouble* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDoubleMatrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const OTDouble* matrix);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStatusCodeArray(ValueStruct* pTarget, const EnumStatusCode* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStatusCodeMatrix(ValueStruct* pTarget, OTUInt32 noOfDimensions, const OTUInt32 *pArrayDimensions, const EnumStatusCode* matrix);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDateTimeArray(ValueStruct* pTarget, const DateTimeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDateTimeMatrix(ValueStruct* pTarget, const DateTimeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStringArray(ValueStruct* pTarget, const OTChar** pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetStringMatrix(ValueStruct* pTarget, const OTChar** pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetGuidArray(void* pTarget, const void* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetGuidMatrix(ValueStruct* pTarget, const GuidStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeIdArray(ValueStruct* pTarget, const NodeIdStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetNodeIdMatrix(ValueStruct* pTarget, const NodeIdStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetExpandedNodeIdArray(ValueStruct* pTarget, const ExpandedNodeIdStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetExpandedNodeIdMatrix(ValueStruct* pTarget, const ExpandedNodeIdStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetLocalizedTextArray(ValueStruct* pTarget, const LocalizedTextStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetLocalizedTextMatrix(ValueStruct* pTarget, const LocalizedTextStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetValueArray(ValueStruct* pTarget, const ValueStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetValueMatrix(ValueStruct* pTarget, const ValueStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetQualifiedNameArray(ValueStruct* pTarget, const QualifiedNameStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetQualifiedNameMatrix(ValueStruct* pTarget, const QualifiedNameStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEUInformationArray(ValueStruct* pTarget, const EUInformationStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEUInformationMatrix(ValueStruct* pTarget, const EUInformationStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetTimeZoneArray(ValueStruct* pTarget, const TimeZoneStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetTimeZoneMatrix(ValueStruct* pTarget, const TimeZoneStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetRangeArray(ValueStruct* pTarget, const RangeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetRangeMatrix(ValueStruct* pTarget, const RangeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetReferenceDescriptionArray(ValueStruct* pTarget, const ReferenceDescriptionStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetReferenceDescriptionMatrix(ValueStruct* pTarget, const ReferenceDescriptionStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetApplicationDescriptionArray(ValueStruct* pTarget, const ApplicationDescriptionStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetApplicationDescriptionMatrix(ValueStruct* pTarget, const ApplicationDescriptionStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerDiagnosticsSummaryDataTypeArray(ValueStruct* pTarget, const ServerDiagnosticsSummaryDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerDiagnosticsSummaryDataTypeMatrix(ValueStruct* pTarget, const ServerDiagnosticsSummaryDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubscriptionDiagnosticsDataTypeArray(ValueStruct* pTarget, const SubscriptionDiagnosticsDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubscriptionDiagnosticsDataTypeMatrix(ValueStruct* pTarget, const SubscriptionDiagnosticsDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionDiagnosticsDataTypeArray(ValueStruct* pTarget, const SessionDiagnosticsDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionDiagnosticsDataTypeMatrix(ValueStruct* pTarget, const SessionDiagnosticsDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionSecurityDiagnosticsDataTypeArray(ValueStruct* pTarget, const SessionSecurityDiagnosticsDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSessionSecurityDiagnosticsDataTypeMatrix(ValueStruct* pTarget, const SessionSecurityDiagnosticsDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServiceCounterDataTypeArray(ValueStruct* pTarget, const ServiceCounterDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServiceCounterDataTypeMatrix(ValueStruct* pTarget, const ServiceCounterDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSemanticChangeStructureDataTypeArray(ValueStruct* pTarget, const SemanticChangeStructureDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSemanticChangeStructureDataTypeMatrix(ValueStruct* pTarget, const SemanticChangeStructureDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetModelChangeStructureDataTypeArray(ValueStruct* pTarget, const ModelChangeStructureDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetModelChangeStructureDataTypeMatrix(ValueStruct* pTarget, const ModelChangeStructureDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetArgumentArray(ValueStruct* pTarget, const ArgumentStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetArgumentMatrix(ValueStruct* pTarget, const ArgumentStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDataValueArray(ValueStruct* pTarget, const DataValueStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDataValueMatrix(ValueStruct* pTarget, const DataValueStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetByteStringArray(ValueStruct* pTarget, const ByteStringStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetByteStringMatrix(ValueStruct* pTarget, const ByteStringStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetXmlElementArray(ValueStruct* pTarget, const XmlElementStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetXmlElementMatrix(ValueStruct* pTarget, const XmlElementStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUserIdentityTokenArray(ValueStruct* pTarget, const UserIdentityTokenStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetUserIdentityTokenMatrix(ValueStruct* pTarget, const UserIdentityTokenStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSignedSoftwareCertificateArray(ValueStruct* pTarget, const SignedSoftwareCertificateStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSignedSoftwareCertificateMatrix(ValueStruct* pTarget, const SignedSoftwareCertificateStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDiagnosticInfo(ValueStruct* pTarget, const DiagnosticInfoStruct* pDiagnosticInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDiagnosticInfoArray(ValueStruct* pTarget, const DiagnosticInfoStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetDiagnosticInfoMatrix(ValueStruct* pTarget, const DiagnosticInfoStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBuildInfoArray(ValueStruct* pTarget, const BuildInfoStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetBuildInfoMatrix(ValueStruct* pTarget, const BuildInfoStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEventFilterArray(ValueStruct* pTarget, const EventFilterStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEventFilterMatrix(ValueStruct* pTarget, const EventFilterStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerStatusDataTypeArray(ValueStruct* pTarget, const ServerStatusDataTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetServerStatusDataTypeMatrix(ValueStruct* pTarget, const ServerStatusDataTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEnumValueTypeArray(ValueStruct* pTarget, const EnumValueTypeStruct* pArray, long length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetEnumValueTypeMatrix(ValueStruct* pTarget, const EnumValueTypeStruct* pArray, OTUInt32 noOfDimensions, const OTUInt32 *pDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueGetSubset(const ValueStruct* pTarget, ValueStruct* pDst, const NumericRangeStruct* indexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueSetSubset(ValueStruct* pTarget, const ValueStruct* pSrc, const NumericRangeStruct* indexRange);

	TBCORE_IF EnumValueCastType OTAPI_CALL OTValueCastHelperCanCast(EnumDataTypeId targetDataType, EnumDataTypeId sourceDataType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTValueCastHelperCast(EnumDataTypeId targetDataType, void* pTargetValue, const void* pSourceValue);

	TBCORE_IF EnumApiClassType OTAPI_CALL OTBGetObjectType(TBHandle otbHandle);
	TBCORE_IF bool OTAPI_CALL OTBIsOfApiClass(TBHandle otbHandle, EnumApiClassType apiClass);
	TBCORE_IF TBHandle OTAPI_CALL OTGetApiHandle(TBHandle otbHandle, bool releaseCore);
	TBCORE_IF TBHandle OTAPI_CALL OTGetApiHandleExtended(TBHandle otbHandle, bool releaseCore, const XmlElementStruct *pXmlTag);

	TBCORE_IF void OTAPI_CALL OTEnterUsage(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTLeaveUsage(TBHandle otbHandle);
	TBCORE_IF long OTAPI_CALL OTBAddRef(TBHandle otbHandle);
	TBCORE_IF long OTAPI_CALL OTBRelease(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTLockLifetimeSemaphore();
	TBCORE_IF void OTAPI_CALL OTUnlockLifetimeSemaphore();
	TBCORE_IF void OTAPI_CALL OTLockStructSemaphore();
	TBCORE_IF void OTAPI_CALL OTUnlockStructSemaphore();

	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionClear(ApplicationDescriptionStruct* pApplicationDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTApplicationDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTApplicationDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueClear(DataValueStruct* pDataValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueSet(DataValueStruct* pTarget, const DataValueStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataValueCopy(const DataValueStruct* pSource, DataValueStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataValueCompare(const DataValueStruct* pSource, const DataValueStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdClear(ExpandedNodeIdStruct* pExpandedNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdSet(ExpandedNodeIdStruct* pTarget, const ExpandedNodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdSetNodeId(ExpandedNodeIdStruct* pTarget, const NodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTExpandedNodeIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTExpandedNodeIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextAddReference(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextReleaseReference(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextClear(LocalizedTextStruct* pLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextSet(LocalizedTextStruct* pTarget, const LocalizedTextStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextCopy(const LocalizedTextStruct* pSource, LocalizedTextStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTLocalizedTextCompare(const LocalizedTextStruct* pSource, const LocalizedTextStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextGetTranslation(LocalizedTextStruct* pTarget, unsigned preferredLocalesCount, const OTChar** pPreferredLocales, OTChar** pTranslation, OTChar** pLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextGetAllTranslations(LocalizedTextStruct* pLocalizedText, OTChar*** pppAllTexts, size_t* pTextCount, OTChar*** pppAllLocales, size_t* pLocaleCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextDefineTranslation(LocalizedTextStruct* pTarget, const OTChar* pTranslation, const OTChar* pLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLocalizedTextRemoveTranslation(LocalizedTextStruct* pTarget, const OTChar* pLocale);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameClear(QualifiedNameStruct* pQualifiedName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameSet(QualifiedNameStruct* pTarget, const QualifiedNameStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQualifiedNameCopy(const QualifiedNameStruct* pSource, QualifiedNameStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTQualifiedNameCompare(const QualifiedNameStruct* pSource, const QualifiedNameStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionClear(ReferenceDescriptionStruct* pReferenceDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionSet(ReferenceDescriptionStruct* pTarget, const ReferenceDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReferenceDescriptionCopy(const ReferenceDescriptionStruct* pSource, ReferenceDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTReferenceDescriptionCompare(const ReferenceDescriptionStruct* pSource, const ReferenceDescriptionStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionClear(ViewDescriptionStruct* pViewDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTViewDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTViewDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdClear(NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdSet(NodeIdStruct* pTarget, const NodeIdStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeIdCopy(const NodeIdStruct* pSource, NodeIdStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTNodeIdCompare(const NodeIdStruct* pSource, const NodeIdStruct* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionClear(BrowseDescriptionStruct* pBrowseDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowseDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyClear(UserTokenPolicyStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserTokenPolicyCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetPolicyId(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetPolicyId(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetTokenType(TBHandle otbHandle, EnumUserTokenType* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetTokenType(TBHandle otbHandle, EnumUserTokenType value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetIssuedTokenType(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetIssuedTokenType(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetIssuerEndpointUrl(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetIssuerEndpointUrl(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicyGetSecurityPolicyUri(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserTokenPolicySetSecurityPolicyUri(TBHandle otbHandle, const OTChar* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionClear(EndpointDescriptionStruct* pEndpointDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionSet(EndpointDescriptionStruct* pTarget, const EndpointDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEndpointDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEndpointDescriptionCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdClear(ReadValueIdStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadValueIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadValueIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueClear(WriteValueStruct* pWriteValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriteValueCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTWriteValueCompare(const void* pSource, const void* pTarget);

#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsClear(ReadRawModifiedDetailsStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadRawModifiedDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadRawModifiedDetailsCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsClear(ReadEventDetailsStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadEventDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadEventDetailsCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdClear(HistoryReadValueIdStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadValueIdCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryReadValueIdCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataClear(HistoryDataStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryDataCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectClear(HistoryDataExtensionObjectStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryDataExtensionObjectCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryDataExtensionObjectCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultClear(HistoryReadResultStruct* pReadValueId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryReadResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryReadResultCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultClear(BrowseResultStruct* pBrowseResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowseResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowseResultCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternClear(AccessPatternStruct* pAccessPattern);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAccessPatternCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAccessPatternCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationInitialize(PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationClear(PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPkiStoreConfigurationCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTPkiStoreConfigurationCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathClear(RelativePathStruct* pRelativePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRelativePathCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementClear(RelativePathElementStruct* pRelativePathElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementSet(RelativePathElementStruct* pTarget, const RelativePathElementStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePathElementCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRelativePathElementCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathClear(BrowsePathStruct* pBrowsePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetClear(BrowsePathTargetStruct* pBrowsePathTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathTargetCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathTargetCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultClear(BrowsePathResultStruct* pBrowsePathResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBrowsePathResultCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterClear(DataChangeFilterStruct* pDataChangeFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataChangeFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataChangeFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEUInformationClear(EUInformationStruct* pEUInformation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEUInformationSet(void* pTarget, const void* pSource);
	TBCORE_IF int OTAPI_CALL OTEUInformationCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneClear(TimeZoneStruct* pTimeZone);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTimeZoneCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTTimeZoneCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentClear(ArgumentStruct* pArgument);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTArgumentCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSetValueRank(ArgumentStruct* pArgument, OTInt32 valueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTArgumentSetArrayDimensions(ArgumentStruct* pArgument, OTUInt32 dimensionsCount, const OTUInt32* pArrayDimensions);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeClear(RangeStruct* pRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTRangeCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestClear(CallMethodRequestStruct* pCallMethodRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequestCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTCallMethodRequestCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultClear(CallMethodResultStruct* pCallMethodResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTCallMethodResultCompare(const void* pSource, const void* pTarget);

#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterClear(EventFilterStruct* pEventFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEventFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandClear(SimpleAttributeOperandStruct* pSimpleAttributeOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandSet(SimpleAttributeOperandStruct* pTarget, const SimpleAttributeOperandStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSimpleAttributeOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListClear(EventFieldListStruct* pEventFieldList);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldListCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEventFieldListCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataClear(SignatureDataStruct* pSignatureData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignatureDataCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSignatureDataCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterClear(ContentFilterStruct* pContentFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementClear(ContentFilterElementStruct* pContentFilterElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementSet(ContentFilterElementStruct* pTarget, const ContentFilterElementStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterElementCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandClear(FilterOperandStruct* pFilterOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandSet(FilterOperandStruct* pTarget, const FilterOperandStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFilterOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTFilterOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandClear(ElementOperandStruct* pElementOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTElementOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTElementOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandClear(LiteralOperandStruct* pLiteralOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTLiteralOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTLiteralOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandClear(AttributeOperandStruct* pAttributeOperand);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAttributeOperandCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAttributeOperandCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeClear(MonitoringChangeStruct* pMonitoringChange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTMonitoringChangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTMonitoringChangeCompare(const void* pSource, const void* pTarget);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionClear(NodeTypeDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTNodeTypeDescriptionCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionGetIncludeSubTypes(TBHandle otbHandle, bool* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNodeTypeDescriptionSetIncludeSubTypes(TBHandle otbHandle, bool value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultClear(ParsingResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTParsingResultCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTParsingResultSetStatusCode(TBHandle otbHandle, EnumStatusCode value);

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionClear(QueryDataDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionSet(QueryDataDescriptionStruct* pTarget, const QueryDataDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTQueryDataDescriptionCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionGetAttributeId(TBHandle otbHandle, EnumAttributeId* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataDescriptionSetAttributeId(TBHandle otbHandle, EnumAttributeId value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetClear(QueryDataSetStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTQueryDataSetCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTQueryDataSetCompare(const void* pSource, const void* pTarget);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringClear(ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringSet(ByteStringStruct* pTarget, const ByteStringStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringInit(ByteStringStruct* pTarget, OTUInt32 length, const unsigned char* pData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringSetUtf8FromString(void* pTarget, const OTChar* pString);
	TBCORE_IF OTChar* OTAPI_CALL OTByteStringGetStringFromUtf8(const void* pTarget);
	TBCORE_IF int OTAPI_CALL OTByteStringCompare(const void* pSource, const void* pTarget);
	TBCORE_IF OTChar* OTAPI_CALL OTByteStringToString(const ByteStringStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringGetLength(const ByteStringStruct* pTarget, unsigned* pLength);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTByteStringGetData(const ByteStringStruct* pTarget, unsigned char** pData);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeClear(NumericRangeStruct* pNumericRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTNumericRangeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF void OTAPI_CALL OTNumericRangeReserve(NumericRangeStruct* pNumericRange, OTUInt32 n);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeAddRange(NumericRangeStruct* pNumericRange, unsigned lowerBound, unsigned upperBound);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNumericRangeParse(NumericRangeStruct* pNumericRange, const OTChar* numericRange);
	TBCORE_IF OTChar* OTAPI_CALL OTNumericRangeToString(const NumericRangeStruct* pNumericRange);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetApplicationUri(TBHandle otbHandle, OTChar** pApplicationUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetApplicationUri(TBHandle otbHandle, const OTChar* _ApplicationUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetProductUri(TBHandle otbHandle, OTChar** pProductUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetProductUri(TBHandle otbHandle, const OTChar* _ProductUri);
	TBCORE_IF TBHandle OTAPI_CALL OTBApplicationDescriptionGetApplicationNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetApplicationType(TBHandle otbHandle, EnumApplicationType* pApplicationType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetApplicationType(TBHandle otbHandle, EnumApplicationType _ApplicationType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetGatewayServerUri(TBHandle otbHandle, OTChar** pGatewayServerUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetGatewayServerUri(TBHandle otbHandle, const OTChar* _GatewayServerUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetDiscoveryProfileUri(TBHandle otbHandle, OTChar** pDiscoveryProfileUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetDiscoveryProfileUri(TBHandle otbHandle, const OTChar* _DiscoveryProfileUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionGetDiscoveryUrls(TBHandle otbHandle, unsigned* discoveryUrlsCount, OTChar*** pDiscoveryUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDescriptionSetDiscoveryUrls(TBHandle otbHandle, unsigned discoveryUrlsCount, const OTChar** _DiscoveryUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetSourceTimestampHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetServerTimestampHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetSourcePicoseconds(TBHandle otbHandle, unsigned short* pSourcePicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetSourcePicoseconds(TBHandle otbHandle, unsigned short _SourcePicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueGetServerPicoseconds(TBHandle otbHandle, unsigned short* pServerPicoseconds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataValueSetServerPicoseconds(TBHandle otbHandle, unsigned short _ServerPicoseconds);
	TBCORE_IF TBHandle OTAPI_CALL OTBDataValueGetValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdGetNamespaceUri(TBHandle otbHandle, OTChar** pNamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdSetNamespaceUri(TBHandle otbHandle, const OTChar* _NamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdGetServerIndex(TBHandle otbHandle, OTUInt32* pServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBExpandedNodeIdSetServerIndex(TBHandle otbHandle, OTUInt32 _ServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameGetName(TBHandle otbHandle, OTChar** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetName(TBHandle otbHandle, const OTChar* _Name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameGetNamespaceIndex(TBHandle otbHandle, unsigned short* pNamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetNamespaceIndex(TBHandle otbHandle, unsigned short _NamespaceIndex);

	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetReferenceTypeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionGetIsForward(TBHandle otbHandle, bool* pIsForward);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionSetIsForward(TBHandle otbHandle, bool _IsForward);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetBrowseNameHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetDisplayNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionGetNodeClass(TBHandle otbHandle, EnumNodeClass* pNodeClass);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReferenceDescriptionSetNodeClass(TBHandle otbHandle, EnumNodeClass _NodeClass);
	TBCORE_IF TBHandle OTAPI_CALL OTBReferenceDescriptionGetTypeDefinitionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetFileName(TBHandle otbHandle, OTChar** pFileName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetFileMaxSize(TBHandle otbHandle, OTUInt32* pFileMaxSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetMaximumBackups(TBHandle otbHandle, OTUInt32* pMaximumBackups);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceGetSocketPort(TBHandle otbHandle, OTUInt32* pSocketPort);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceSetSocketPort(TBHandle otbHandle, OTUInt32 _SocketPort);
	TBCORE_IF TBHandle OTAPI_CALL OTBViewDescriptionGetViewIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBViewDescriptionGetTimestampHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBViewDescriptionGetViewVersion(TBHandle otbHandle, OTUInt32* pViewVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBViewDescriptionSetViewVersion(TBHandle otbHandle, OTUInt32 _ViewVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdGetNamespaceIndex(TBHandle otbHandle, unsigned short* pNamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdSetNamespaceIndex(TBHandle otbHandle, unsigned short _NamespaceIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBNodeIdGetIdentifierType(TBHandle otbHandle, EnumIdentifierType* pIdentifierType);
	TBCORE_IF TBHandle OTAPI_CALL OTBApplicationGetDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetManufacturerName(TBHandle otbHandle, OTChar** ppManufacturerName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetManufacturerName(TBHandle otbHandle, const OTChar* pManufacturerName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMajorVersion(TBHandle otbHandle, unsigned short* pMajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMajorVersion(TBHandle otbHandle, unsigned short _MajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinorVersion(TBHandle otbHandle, unsigned short* pMinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinorVersion(TBHandle otbHandle, unsigned short _MinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPatchVersion(TBHandle otbHandle, unsigned short* pPatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetPatchVersion(TBHandle otbHandle, unsigned short _PatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetBuildNumber(TBHandle otbHandle, OTUInt32* pBuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetBuildNumber(TBHandle otbHandle, OTUInt32 _BuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetBuildDate(TBHandle otbHandle, DateTimeStruct* pBuildDate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetBuildDate(TBHandle otbHandle, const DateTimeStruct* pBuildDate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxMajorVersion(TBHandle otbHandle, unsigned short* pToolboxMajorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxMinorVersion(TBHandle otbHandle, unsigned short* pToolboxMinorVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxBuildNumber(TBHandle otbHandle, OTUInt32* pToolboxBuildNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetToolboxPatchVersion(TBHandle otbHandle, unsigned short* pToolboxPatchVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const OTChar** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, OTChar*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddServerProfile(TBHandle otbHandle, const OTChar* pServerProfile);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetServerProfiles(TBHandle otbHandle, OTChar*** pServerProfile, OTUInt32* pProfileCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetDefaultDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pDefaultMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDefaultDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _DefaultMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pMaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxDataChangeMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _MaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxEventMonitoringQueueSize(TBHandle otbHandle, OTUInt32* pMaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxEventMonitoringQueueSize(TBHandle otbHandle, OTUInt32 _MaxMonitoringQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinSessionTimeout(TBHandle otbHandle, OTUInt32* pMinSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinSessionTimeout(TBHandle otbHandle, OTUInt32 _MinSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxSessionTimeout(TBHandle otbHandle, OTUInt32* pMaxSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxSessionTimeout(TBHandle otbHandle, OTUInt32 _MaxSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxPipedPublishRequests(TBHandle otbHandle, OTUInt32* pMaxPipedPublishRequests);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxPipedPublishRequests(TBHandle otbHandle, OTUInt32 _MaxPipedPublishRequests);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxMonitoredItemsPerService(TBHandle otbHandle, OTUInt32* pMaxMonitoredItemsPerService);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxMonitoredItemsPerService(TBHandle otbHandle, OTUInt32 _MaxMonitoredItemsPerService);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetDefaultNetworkTimeout(TBHandle otbHandle, OTUInt32* pDefaultNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDefaultNetworkTimeout(TBHandle otbHandle, OTUInt32 _DefaultNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDefaultAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pDefaultAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationSetDefaultAutoReconnectInterval(TBHandle otbHandle, OTUInt32 _DefaultAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDefaultConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pDefaultConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationSetDefaultConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 _DefaultConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxDataSetsToReturn(TBHandle otbHandle, OTUInt32* pMaxDataSetsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxDataSetsToReturn(TBHandle otbHandle, OTUInt32 _MaxDataSetsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxReferencesToReturn(TBHandle otbHandle, OTUInt32* pMaxReferencesToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxReferencesToReturn(TBHandle otbHandle, OTUInt32 _MaxReferencesToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxNodesToAnalyzePerQueryRequest(TBHandle otbHandle, OTUInt32* pMaxNodesToAnalyzePerQueryRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxNodesToAnalyzePerQueryRequest(TBHandle otbHandle, OTUInt32 _MaxNodesToAnalyzePerQueryRequest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxBrowseContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxBrowseContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxBrowseContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxBrowseContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxHistoryContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxHistoryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxHistoryContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxHistoryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxQueryContinuationPoints(TBHandle otbHandle, OTUInt16* pMaxQueryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxQueryContinuationPoints(TBHandle otbHandle, OTUInt16 _MaxQueryContinuationPoints);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetMinDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32* pMinDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetMinDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32 _MinDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetMaxDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32* pMaxDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetMaxDiagnosticsUpdateInterval(TBHandle otbHandle, OTUInt32 _MaxDiagnosticsUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCApplicationGetDemoTime(TBHandle otbHandle, OTUInt32* pDemoTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetDemoTime(TBHandle otbHandle, OTUInt32 _DemoTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinPublishingInterval(TBHandle otbHandle, double* pMinPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinPublishingInterval(TBHandle otbHandle, double _MinPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxPublishingInterval(TBHandle otbHandle, double* pMaxPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxPublishingInterval(TBHandle otbHandle, double _MaxPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMinSamplingInterval(TBHandle otbHandle, double* pMinSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMinSamplingInterval(TBHandle otbHandle, double _MinSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetMaxSamplingInterval(TBHandle otbHandle, double* pMaxSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetMaxSamplingInterval(TBHandle otbHandle, double _MaxSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEnableAuditEvents(TBHandle otbHandle, bool* pEnableAuditEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetEnableAuditEvents(TBHandle otbHandle, bool _EnableAuditEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetChannelSharing(TBHandle otbHandle, bool* pEnableSharing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetChannelSharing(TBHandle otbHandle, bool enableSharing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationIsServiceGroupEnabled(TBHandle otbHandle, EnumServiceGroup serviceGroup, bool* pEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetEnableServiceGroup(TBHandle otbHandle, EnumServiceGroup serviceGroup, bool _Enable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetServerRedundancyMode(TBHandle otbHandle, EnumRedundancySupport* pRedundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetServerRedundancyMode(TBHandle otbHandle, EnumRedundancySupport redundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetRedundantServerArray(TBHandle otbHandle, OTUInt32* pRedundantServerDescriptionsCount, ApplicationDescriptionStruct** ppRedundantServerDescriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetRedundantServerArray(TBHandle otbHandle, OTUInt32 redundantServerDescriptionsCount, const ApplicationDescriptionStruct** pRedundantServerDescriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetDhParamFileLocation(TBHandle otbHandle, const OTChar* _DhParamFileLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationValidateCertificate(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration, const ByteStringStruct *pX509Certificate, const OTChar* pAppUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationGetSuppressAddresspaceCreation(TBHandle otbHandle, bool* pSuppress);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSApplicationSetSuppressAddresspaceCreation(TBHandle otbHandle, bool suppress);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationCreateCertificate(TBHandle otbHandle,
		const OTChar* psSecurityProfileUri,
		const OTChar* certificateFileName,
		const OTChar* privateKeyFileName,
		const OTChar* privateKeyPassword,
		OTUInt32 validityDuration,
		const OTChar* productName,
		const OTChar* organizationName,
		const OTChar* hostNames);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetSubscriptionCount(TBHandle otbHandle, OTUInt32* pSubscriptionCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetDataChangeEventCount(TBHandle otbHandle, OTUInt32* pDataChangeEventCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetNetworkFailureCount(TBHandle otbHandle, OTUInt32* pNetworkFailureCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStatisticsGetMonitoredItemCount(TBHandle otbHandle, OTUInt32* pMonitoredItemCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetPolicyId(TBHandle otbHandle, OTChar** pPolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetPolicyId(TBHandle otbHandle, const OTChar* _PolicyId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetTokenType(TBHandle otbHandle, EnumUserTokenType* pTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetTokenType(TBHandle otbHandle, EnumUserTokenType _TokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetIssuerEndpointUrl(TBHandle otbHandle, OTChar** pIssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetIssuerEndpointUrl(TBHandle otbHandle, const OTChar* _IssuerEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetSecurityPolicyUri(TBHandle otbHandle, OTChar** pSecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetSecurityPolicyUri(TBHandle otbHandle, const OTChar* _SecurityPolicyUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicyGetIssuedTokenType(TBHandle otbHandle, OTChar** pIssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBUserTokenPolicySetIssuedTokenType(TBHandle otbHandle, const OTChar* _IssuedTokenType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetEndpointUrl(TBHandle otbHandle, OTChar** pEndpointUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetEndpointUrl(TBHandle otbHandle, const OTChar* _EndpointUrl);
	TBCORE_IF TBHandle OTAPI_CALL OTBEndpointDescriptionGetServerHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetServerCertificate(TBHandle otbHandle, unsigned* serverCertificateCount, unsigned char** pServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetServerCertificate(TBHandle otbHandle, unsigned serverCertificateCount, const unsigned char* _ServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode _MessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetSecurityPolicy(TBHandle otbHandle, OTChar** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetSecurityPolicy(TBHandle otbHandle, const OTChar* _SecurityPolicy);
	TBCORE_IF TBHandle OTAPI_CALL OTBEndpointDescriptionGetUserIdentityTokensHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetTransportProfile(TBHandle otbHandle, OTChar** pTransportProfile);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetTransportProfile(TBHandle otbHandle, const OTChar* _TransportProfile);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionGetSecurityLevel(TBHandle otbHandle, unsigned char* pSecurityLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBEndpointDescriptionSetSecurityLevel(TBHandle otbHandle, unsigned char _SecurityLevel);
	TBCORE_IF TBHandle OTAPI_CALL OTBReadValueIdGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReadValueIdGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBReadValueIdSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
#if TB5_HISTORY
	TBCORE_IF TBHandle OTAPI_CALL OTBHistoryReadValueIdGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBHistoryReadValueIdGetDataEncodingHandle(TBHandle otbHandle);
#endif
	TBCORE_IF TBHandle OTAPI_CALL OTBWriteValueGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBWriteValueGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBWriteValueSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF TBHandle OTAPI_CALL OTBWriteValueGetValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetAccessField(TBHandle otbHandle, unsigned* accessFieldCount, unsigned char** pAccessField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetAccessField(TBHandle otbHandle, unsigned accessFieldCount, const unsigned char* _AccessField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetKey(TBHandle otbHandle, OTUInt32* pKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetKey(TBHandle otbHandle, OTUInt32 _Key);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternGetName(TBHandle otbHandle, OTChar** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAccessPatternSetName(TBHandle otbHandle, const OTChar* _Name);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathGetElementsHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathElementGetReferenceTypeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementGetIsInverse(TBHandle otbHandle, bool* pIsInverse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementSetIsInverse(TBHandle otbHandle, bool _IsInverse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementGetIncludeSubtypes(TBHandle otbHandle, bool* pIncludeSubtypes);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRelativePathElementSetIncludeSubtypes(TBHandle otbHandle, bool _IncludeSubtypes);
	TBCORE_IF TBHandle OTAPI_CALL OTBRelativePathElementGetTargetNameHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBBrowsePathTargetGetTargetIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBBrowsePathTargetGetRemainingPathIndex(TBHandle otbHandle, OTUInt32* pRemainingPathIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBBrowsePathTargetSetRemainingPathIndex(TBHandle otbHandle, OTUInt32 _RemainingPathIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetTrigger(TBHandle otbHandle, EnumDataChangeTrigger* pTrigger);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetTrigger(TBHandle otbHandle, EnumDataChangeTrigger _Trigger);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetDeadbandType(TBHandle otbHandle, EnumDeadbandType* pDeadbandType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetDeadbandType(TBHandle otbHandle, EnumDeadbandType _DeadbandType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterGetDeadbandValue(TBHandle otbHandle, double* pDeadbandValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBDataChangeFilterSetDeadbandValue(TBHandle otbHandle, double _DeadbandValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneGetOffset(TBHandle otbHandle, OTInt16* pOffet);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneSetOffset(TBHandle otbHandle, OTInt16 _Offset);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneGetDaylightSavingInOffset(TBHandle otbHandle, bool* pDSTInOffsetOffet);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTimeZoneSetDaylightSavingInOffset(TBHandle otbHandle, bool _DSTInOffsetOffet);
	TBCORE_IF TBHandle OTAPI_CALL OTBArgumentGetDescriptionHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenClear(AnonymousIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenSet(AnonymousIdentityTokenStruct* pTarget, const AnonymousIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenCopy(const AnonymousIdentityTokenStruct* pSource, AnonymousIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTAnonymousIdentityTokenCompare(const AnonymousIdentityTokenStruct* pSource, const AnonymousIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenGetPolicyId(AnonymousIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAnonymousIdentityTokenSetPolicyId(AnonymousIdentityTokenStruct* otbHandle, const OTChar* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenClear(UserNameIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSet(UserNameIdentityTokenStruct* pTarget, const UserNameIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenCopy(const UserNameIdentityTokenStruct* pSource, UserNameIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserNameIdentityTokenCompare(const UserNameIdentityTokenStruct* pSource, const UserNameIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetUserName(UserNameIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSetUserName(UserNameIdentityTokenStruct* otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetEncryptionAlgorithm(UserNameIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenGetPolicyId(UserNameIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserNameIdentityTokenSetPolicyId(UserNameIdentityTokenStruct* otbHandle, const OTChar* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenClear(X509IdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenSet(X509IdentityTokenStruct* pTarget, const X509IdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenCopy(const X509IdentityTokenStruct* pSource, X509IdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTX509IdentityTokenCompare(const X509IdentityTokenStruct* pSource, const X509IdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenGetPolicyId(X509IdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenSetPolicyId(X509IdentityTokenStruct* otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTX509IdentityTokenLoadPrivateKey(X509IdentityTokenStruct* pTarget,
		const OTChar* filePath,
		const OTChar* password, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenClear(IssuedIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenSet(IssuedIdentityTokenStruct* pTarget, const IssuedIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenCopy(const IssuedIdentityTokenStruct* pSource, IssuedIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTIssuedIdentityTokenCompare(const IssuedIdentityTokenStruct* pSource, const IssuedIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenGetEncryptionAlgorithm(IssuedIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenGetPolicyId(IssuedIdentityTokenStruct* otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTIssuedIdentityTokenSetPolicyId(IssuedIdentityTokenStruct* otbHandle, const OTChar* value);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenClear(UserIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSet(UserIdentityTokenStruct* pTarget, const UserIdentityTokenStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenCopy(const UserIdentityTokenStruct* pSource, UserIdentityTokenStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUserIdentityTokenCompare(const UserIdentityTokenStruct* pSource, const UserIdentityTokenStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetAnonymousIdentityToken(UserIdentityTokenStruct* otbHandle, AnonymousIdentityTokenStruct* pToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetUserNameIdentityToken(UserIdentityTokenStruct* otbHandle, UserNameIdentityTokenStruct* pToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetX509IdentityToken(UserIdentityTokenStruct* otbHandle, X509IdentityTokenStruct* pX509Token);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUserIdentityTokenSetIssuedIdentityToken(UserIdentityTokenStruct* otbHandle, IssuedIdentityTokenStruct* pIssuedToken);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeGetLow(TBHandle otbHandle, double* pLow);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeSetLow(TBHandle otbHandle, double _Low);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeGetHigh(TBHandle otbHandle, double* pHigh);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBRangeSetHigh(TBHandle otbHandle, double _High);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetObjectIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetMethodIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodRequestGetInputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBCallMethodResultGetInputArgumentResults(TBHandle otbHandle, unsigned* inputArgumentResultsCount, EnumStatusCode** pInputArgumentResults);
	TBCORE_IF TBHandle OTAPI_CALL OTBCallMethodResultGetOutputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBCallMethodResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFilterGetSelectClausesHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFilterGetWhereClauseHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandGetTypeDefinitionIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandGetBrowsePathHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBSimpleAttributeOperandIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSimpleAttributeOperandGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSimpleAttributeOperandSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF TBHandle OTAPI_CALL OTBEventFieldListGetEventFieldsHandle(TBHandle otbHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataGetSignature(TBHandle otbHandle, unsigned* signatureCount, unsigned char** pSignature);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataSetSignature(TBHandle otbHandle, unsigned signatureCount, const unsigned char* _Signature);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataGetAlgorithm(TBHandle otbHandle, OTChar** pAlgorithm);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBSignatureDataSetAlgorithm(TBHandle otbHandle, const OTChar* _Algorithm);
	TBCORE_IF TBHandle OTAPI_CALL OTBContentFilterGetElementsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBContentFilterElementGetFilterOperator(TBHandle otbHandle, EnumFilterOperator* pFilterOperator);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBContentFilterElementSetFilterOperator(TBHandle otbHandle, EnumFilterOperator _FilterOperator);
	TBCORE_IF TBHandle OTAPI_CALL OTBContentFilterElementGetFilterOperandsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBElementOperandGetIndex(TBHandle otbHandle, OTUInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBElementOperandSetIndex(TBHandle otbHandle, OTUInt32 _Index);
	TBCORE_IF TBHandle OTAPI_CALL OTBLiteralOperandGetValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandGetAlias(TBHandle otbHandle, OTChar** pAlias);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandSetAlias(TBHandle otbHandle, const OTChar* _Alias);
	TBCORE_IF TBHandle OTAPI_CALL OTBAttributeOperandGetBrowsePathHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBAttributeOperandSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class QualifiedName
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBQualifiedNameSetNameAndIndex(TBHandle otbHandle,
			const OTChar* name,
			unsigned short namespaceIndex);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Trace
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceWriteLine(TBHandle otbHandle,
			EnumTraceLevel enum_level,
			EnumTraceGroup enum_group,
			const OTChar* message,
			const OTChar* objectID);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceStop(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableFileLogging(TBHandle otbHandle,
			const OTChar* file,
			OTUInt32 maxFileSize,
			OTUInt32 maxBackups,
			OTUInt32 bufferSize, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableFileLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableTcpLogging(TBHandle otbHandle,
			const OTChar* host,
			unsigned short port,
			OTUInt32 maxQueueSize, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableTcpLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceWriteSourceLine(TBHandle otbHandle,
			EnumTraceLevel enum_level,
			EnumTraceGroup enum_group,
			const OTChar* message,
			const OTChar* file,
			OTUInt32 line);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableTraceLevel(TBHandle otbHandle,
			EnumTraceGroup enum_groups,
			EnumTraceLevel enum_level);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableTraceLevel(TBHandle otbHandle,
			EnumTraceGroup groups,
			EnumTraceLevel enum_level);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableStdOutLogging(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableStdErrLogging(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableStdOutLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableStdErrLogging(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceEnableCallbackLogging(TBHandle otbHandle, CB_OnLogMessageCore pApiCallback, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBTraceDisableCallbackLogging(TBHandle otbHandle);

	TBCORE_IF void* OTAPI_CALL OTBTraceGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTBTraceReleaseHandle(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Application
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationStart(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationStop(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddSession(TBHandle otbHandle,
			TBHandle session, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveSession(TBHandle otbHandle,
			TBHandle session, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddRedundantSession(TBHandle otbHandle,
		TBHandle redundantSession, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetRedundantSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveRedundantSession(TBHandle otbHandle,
		TBHandle redundantSession, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationActivateLicense(TBHandle otbHandle,
			EnumFeature enum_product,
			const OTChar* licenseKey, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationInitialize(TBHandle otbHandle,
			ApplicationDescriptionStruct* pDescription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationUninitialize(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddEndpoint(TBHandle otbHandle,
			TBHandle endPoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEndpoints(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemoveEndpoint(TBHandle otbHandle,
			TBHandle endPoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadCertificate(TBHandle otbHandle,
			const OTChar* applicationInstanceCertificate, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadPrivateKey(TBHandle otbHandle,
			const OTChar* privateKeyFile,
			const OTChar* password, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetEndpointsFromServer(TBHandle otbHandle,
			const OTChar* serverUrl,
			OTUInt32 transportProfilesCount, const OTChar** transportProfiles,
			const PkiStoreConfigurationStruct* pPkiConfig,
			const OTChar* pInstanceCertificateFile, const OTChar* pPrivateKeyFile, const OTChar* pPassword,
			OTUInt32* endpointDescriptionsCount, EndpointDescriptionStruct** pEndpointDescriptions, bool resolveToIPv4, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationLoadDiscoveryServerCertificate(TBHandle otbHandle,
			const OTChar* discoveryServerCertificate, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetAccessGroup(TBHandle otbHandle,
			AccessPatternStruct* pGroup, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetAccessGroups(TBHandle otbHandle,
			unsigned* groupsCount, AccessPatternStruct** pGroups, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationFindServers(TBHandle otbHandle,
			const OTChar* discoveryServerUrl,
			const PkiStoreConfigurationStruct* pPkiConfig,
			const OTChar* pInstanceCertificateFile, const OTChar* pPrivateKeyFile, const OTChar* pPassword,
			unsigned serverURIsCount, const OTChar** serverURIs,
			unsigned* applicationDescriptionsCount, ApplicationDescriptionStruct** pApplicationDescriptions, bool resolveToIPv4, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetUserAccessLevel(TBHandle otbHandle,
			OTUInt16 accessGroupKey,
			OTUInt32 userGroupIdx,
			OTUInt8* userAccessLevel, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationEnableServerRegistration(TBHandle otbHandle,
			const OTChar* discoveryServerUrl,
			const OTChar* discoveryServerSecurityProfile,
			EnumMessageSecurityMode enum_discoveryServerMessageSecurityMode,
			OTUInt32 refreshPeriod, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationDisableServerRegistration(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddPubSubConnection(TBHandle otbHandle, TBHandle otbConnectionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemovePubSubConnection(TBHandle otbHandle, TBHandle otbConnectionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPubSubConnections(TBHandle otbHandle, size_t* pSize, TBHandle** ppConnections);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddPubSubPublishedDataSet(TBHandle otbHandle, TBHandle otbPublishedDataSetHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemovePubSubPublishedDataSet(TBHandle otbHandle, TBHandle otbPublishedDataSetHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPubSubPublishedDataSets(TBHandle otbHandle, size_t* pSize, TBHandle** ppPublishedDataSets);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationAddPubSubSubscribedDataSet(TBHandle otbHandle, TBHandle otbSubscribedDataSetHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationRemovePubSubSubscribedDataSet(TBHandle otbHandle, TBHandle otbSubscribedDataSetHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetPubSubSubscribedDataSets(TBHandle otbHandle, size_t* pSize, TBHandle** ppSubscribedDataSets);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetShowPubSubNodes(TBHandle otbHandle, bool bShow);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationGetShowPubSubNodes(TBHandle otbHandle, bool* pShow);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBApplicationSetIgnoreMantis4545(TBHandle otbHandle, bool bIgnore);

	TBCORE_IF void* OTAPI_CALL OTBApplicationGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTBApplicationReleaseHandle(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Statistics
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDiagnosticsGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTSDiagnosticsReleaseHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsIsEnabled(TBHandle otbHandle, bool* pEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetEnabled(TBHandle otbHandle, bool enable, EnumStatusCode* pReturnValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsGetUpdateInterval(TBHandle otbHandle, OTUInt32* pUpdateInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetUpdateInterval(TBHandle otbHandle, OTUInt32 updateInterval, EnumStatusCode* pReturnValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDiagnosticsSetUpdateIntervalWritable(TBHandle otbHandle, bool writable);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FilterOperand
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetLiteralOperand(TBHandle otbHandle,
			LiteralOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetElementOperand(TBHandle otbHandle,
			ElementOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetAttributeOperand(TBHandle otbHandle,
			AttributeOperandStruct* pOperand, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTBFilterOperandSetSimpleAttributeOperand(TBHandle otbHandle,
			SimpleAttributeOperandStruct* pOperand, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class LiteralOperand
	////////////////////////////////////////////////////////////////////////////////

	void* OTAPI_CALL OTBLiteralOperand_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AttributeOperand
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTRelativePath_AddElement(TBHandle handle, const RelativePathElementStruct* pElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBrowsePathResult_AddTarget(TBHandle handle, const BrowsePathTargetStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCallMethodRequest_AddInputArgument(TBHandle handle, const ValueStruct* pInputArgument);
#if TB5_FILTER
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleAttributeOperand_AddBrowsePath(TBHandle handle, const QualifiedNameStruct* pBrowsePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilter_AddElement(TBHandle handle, const ContentFilterElementStruct* pElement);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElement_AddFilterOperand(TBHandle handle, const FilterOperandStruct* pFilterOperand);
#endif
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFilter_AddSelectClause(TBHandle handle, const SimpleAttributeOperandStruct* pSelectClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEventFieldList_AddEventField(TBHandle handle, const ValueStruct* pEventField);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventIdVar(TBHandle otbHandle, TBHandle* pEventIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventId(TBHandle otbHandle, OTUInt32* eventIdSize, unsigned char** eventIdValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventTypeVar(TBHandle otbHandle, TBHandle* pEventTypeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetEventType(TBHandle otbHandle, NodeIdStruct* eventType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNodeVar(TBHandle otbHandle, TBHandle* pSourceNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNode(TBHandle otbHandle, NodeIdStruct* sourceNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceNameVar(TBHandle otbHandle, TBHandle* pSourceNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSourceName(TBHandle otbHandle, OTChar** sourceName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetTimeVar(TBHandle otbHandle, TBHandle* pTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetTime(TBHandle otbHandle, DateTimeStruct* time);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetReceiveTimeVar(TBHandle otbHandle, TBHandle* pReceiveTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetReceiveTime(TBHandle otbHandle, DateTimeStruct* receiveTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetLocalTimeVar(TBHandle otbHandle, TBHandle* pLocalTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetLocalTime(TBHandle otbHandle, TimeZoneStruct* localTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetMessageVar(TBHandle otbHandle, TBHandle* pMessageHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetMessage(TBHandle otbHandle, LocalizedTextStruct* message);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSeverityVar(TBHandle otbHandle, TBHandle* pSeverityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventGetSeverity(TBHandle otbHandle, unsigned short* severity);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnabledStateVar(TBHandle otbHandle, TBHandle* pEnabledStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnabledState(TBHandle otbHandle, LocalizedTextStruct* enabledState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranchIdVar(TBHandle otbHandle, TBHandle* pBranchIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranchId(TBHandle otbHandle, NodeIdStruct* branchId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetRetainVar(TBHandle otbHandle, TBHandle* pRetainHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetRetain(TBHandle otbHandle, bool* retain);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetQualityVar(TBHandle otbHandle, TBHandle* pQualityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetQuality(TBHandle otbHandle, EnumStatusCode* quality);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetLastSeverityVar(TBHandle otbHandle, TBHandle* pLastSeverityHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetLastSeverity(TBHandle otbHandle, unsigned short* lastSeverity);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetCommentVar(TBHandle otbHandle, TBHandle* pCommentHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetComment(TBHandle otbHandle, LocalizedTextStruct* comment);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetClientUserIdVar(TBHandle otbHandle, TBHandle* pClientUserIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetClientUserId(TBHandle otbHandle, OTChar** clientUserId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetEnable(TBHandle otbHandle, TBHandle* pEnableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetDisable(TBHandle otbHandle, TBHandle* pDisableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetConditionRefresh(TBHandle otbHandle, TBHandle* pConditionRefreshHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetAddComment(TBHandle otbHandle, TBHandle* pAddCommentHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetCurrentStateVar(TBHandle otbHandle, TBHandle* pCurrentStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetCurrentState(TBHandle otbHandle, LocalizedTextStruct* currentState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetLastTransitionVar(TBHandle otbHandle, TBHandle* pLastTransitionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetLastTransition(TBHandle otbHandle, LocalizedTextStruct* lastTransition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetState(TBHandle otbHandle, QualifiedNameStruct* browseName, TBHandle* pStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineGetTransition(TBHandle otbHandle, QualifiedNameStruct* browseName, TBHandle* pTransitionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetId(TBHandle otbHandle, ValueStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNameVar(TBHandle otbHandle, TBHandle* pNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetName(TBHandle otbHandle, QualifiedNameStruct* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNumberVar(TBHandle otbHandle, TBHandle* pNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetNumber(TBHandle otbHandle, OTUInt32* number);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetEffectiveDisplayNameVar(TBHandle otbHandle, TBHandle* pEffectiveDisplayNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableGetEffectiveDisplayName(TBHandle otbHandle, LocalizedTextStruct* effectiveDisplayName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetId(TBHandle otbHandle, ValueStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNameVar(TBHandle otbHandle, TBHandle* pNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetName(TBHandle otbHandle, QualifiedNameStruct* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNumberVar(TBHandle otbHandle, TBHandle* pNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetNumber(TBHandle otbHandle, OTUInt32* number);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetTransitionTimeVar(TBHandle otbHandle, TBHandle* pTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableGetTransitionTime(TBHandle otbHandle, DateTimeStruct* transitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetCurrentStateVar(TBHandle otbHandle, TBHandle* pCurrentStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetCurrentState(TBHandle otbHandle, LocalizedTextStruct* currentState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetLastTransitionVar(TBHandle otbHandle, TBHandle* pLastTransitionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineGetLastTransition(TBHandle otbHandle, LocalizedTextStruct* lastTransition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateVariableGetId(TBHandle otbHandle, NodeIdStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteTransitionVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteTransitionVariableGetId(TBHandle otbHandle, NodeIdStruct* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionVariableGetSourceTimestampVar(TBHandle otbHandle, TBHandle* pSourceTimestampHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionVariableGetSourceTimestamp(TBHandle otbHandle, DateTimeStruct* sourceTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetIdVar(TBHandle otbHandle, TBHandle* pIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetId(TBHandle otbHandle, bool* id);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTransitionTimeVar(TBHandle otbHandle, TBHandle* pTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTransitionTime(TBHandle otbHandle, DateTimeStruct* transitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetEffectiveTransitionTimeVar(TBHandle otbHandle, TBHandle* pEffectiveTransitionTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetEffectiveTransitionTime(TBHandle otbHandle, DateTimeStruct* effectiveTransitionTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTrueStateVar(TBHandle otbHandle, TBHandle* pTrueStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetTrueState(TBHandle otbHandle, LocalizedTextStruct* trueState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetFalseStateVar(TBHandle otbHandle, TBHandle* pFalseStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableGetFalseState(TBHandle otbHandle, LocalizedTextStruct* falseState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAckedStateVar(TBHandle otbHandle, TBHandle* pAckedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAckedState(TBHandle otbHandle, LocalizedTextStruct* ackedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirmedStateVar(TBHandle otbHandle, TBHandle* pConfirmedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirmedState(TBHandle otbHandle, LocalizedTextStruct* confirmedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetAcknowledge(TBHandle otbHandle, TBHandle* pAcknowledgeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAcknowledgeableConditionGetConfirm(TBHandle otbHandle, TBHandle* pConfirmHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetActiveStateVar(TBHandle otbHandle, TBHandle* pActiveStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetActiveState(TBHandle otbHandle, LocalizedTextStruct* activeState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedOrShelvedVar(TBHandle otbHandle, TBHandle* pSuppressedOrShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedOrShelved(TBHandle otbHandle, bool* suppressedOrShelved);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedStateVar(TBHandle otbHandle, TBHandle* pSuppressedStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetSuppressedState(TBHandle otbHandle, LocalizedTextStruct* suppressedState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetMaxTimeShelvedVar(TBHandle otbHandle, TBHandle* pMaxTimeShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetMaxTimeShelved(TBHandle otbHandle, double* maxTimeShelved);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetShelvingState(TBHandle otbHandle, TBHandle* pShelvingStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetInputNodeVar(TBHandle otbHandle, TBHandle* pInputNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionGetInputNode(TBHandle otbHandle, NodeIdStruct* inputNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetAlarmCondition(TBHandle otbHandle, TBHandle* pAlarmCondition);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelveTimeVar(TBHandle otbHandle, TBHandle* pUnshelveTimeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelveTime(TBHandle otbHandle, double* unshelveTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelved(TBHandle otbHandle, TBHandle* pUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelved(TBHandle otbHandle, TBHandle* pTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelved(TBHandle otbHandle, TBHandle* pOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelvedToTimedShelved(TBHandle otbHandle, TBHandle* pUnshelvedToTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelvedToUnshelved(TBHandle otbHandle, TBHandle* pTimedShelvedToUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelvedToOneShotShelved(TBHandle otbHandle, TBHandle* pUnshelvedToOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelvedToUnshelved(TBHandle otbHandle, TBHandle* pOneShotShelvedToUnshelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelvedToTimedShelved(TBHandle otbHandle, TBHandle* pOneShotShelvedToTimedShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelve(TBHandle otbHandle, TBHandle* pTimedShelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetOneShotShelve(TBHandle otbHandle, TBHandle* pOneShotShelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetUnshelve(TBHandle otbHandle, TBHandle* pUnshelveHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineGetTimedShelvedToOneShotShelved(TBHandle otbHandle, TBHandle* pTimedShelvedToOneShotShelvedHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateGetStateNumberVar(TBHandle otbHandle, TBHandle* pStateNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateGetStateNumber(TBHandle otbHandle, OTUInt32* stateNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionGetTransitionNumberVar(TBHandle otbHandle, TBHandle* pTransitionNumberHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionGetTransitionNumber(TBHandle otbHandle, OTUInt32* transitionNumber);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighHighLimitVar(TBHandle otbHandle, TBHandle* pHighHighLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighHighLimit(TBHandle otbHandle, double* highHighLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighLimitVar(TBHandle otbHandle, TBHandle* pHighLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetHighLimit(TBHandle otbHandle, double* highLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLowLimitVar(TBHandle otbHandle, TBHandle* pLowLowLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLowLimit(TBHandle otbHandle, double* lowLowLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLimitVar(TBHandle otbHandle, TBHandle* pLowLimitHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSLimitAlarmGetLowLimit(TBHandle otbHandle, double* lowLimit);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitAlarmGetLimitState(TBHandle otbHandle, TBHandle* pLimitStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighHigh(TBHandle otbHandle, TBHandle* pHighHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHigh(TBHandle otbHandle, TBHandle* pHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLow(TBHandle otbHandle, TBHandle* pLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowLow(TBHandle otbHandle, TBHandle* pLowLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowLowToLow(TBHandle otbHandle, TBHandle* pLowLowToLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetLowToLowLow(TBHandle otbHandle, TBHandle* pLowToLowLowHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighHighToHigh(TBHandle otbHandle, TBHandle* pHighHighToHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveLimitStateMachineGetHighToHighHigh(TBHandle otbHandle, TBHandle* pHighToHighHighHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSOffNormalAlarmGetNormalStateVar(TBHandle otbHandle, TBHandle* pNormalStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSOffNormalAlarmGetNormalState(TBHandle otbHandle, NodeIdStruct* normalState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighHighStateVar(TBHandle otbHandle, TBHandle* pHighHighStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighHighState(TBHandle otbHandle, LocalizedTextStruct* highHighState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighStateVar(TBHandle otbHandle, TBHandle* pHighStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetHighState(TBHandle otbHandle, LocalizedTextStruct* highState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowStateVar(TBHandle otbHandle, TBHandle* pLowStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowState(TBHandle otbHandle, LocalizedTextStruct* lowState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowLowStateVar(TBHandle otbHandle, TBHandle* pLowLowStateHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveLimitAlarmGetLowLowState(TBHandle otbHandle, LocalizedTextStruct* lowLowState);

#if TB5_CLIENT
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetIndexRange(TBHandle otbHandle, const void* _IndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetAttributeId(TBHandle otbHandle, EnumAttributeId _AttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode _MonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetSamplingInterval(TBHandle otbHandle, double* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetSamplingInterval(TBHandle otbHandle, double _SamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetRevisedSamplingInterval(TBHandle otbHandle, double* pRevisedSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 _QueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetRevisedQueueSize(TBHandle otbHandle, OTUInt32* pRevisedQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetDiscardOldest(TBHandle otbHandle, bool _DiscardOldest);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetNodeId(TBHandle otbHandle, void* nodeIdHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetFilterHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetFilter(TBHandle otbHandle, void* filterHandle);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTCMonitoredItemGetEventFilterHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemSetEventFilter(TBHandle otbHandle, void* eventFilterHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId);


	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetUrl(TBHandle otbHandle, OTChar** pUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUrl(TBHandle otbHandle, const OTChar* _Url);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSessionTimeout(TBHandle otbHandle, double* pSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSessionTimeout(TBHandle otbHandle, double _SessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetRevisedSessionTimeout(TBHandle otbHandle, double* pRevisedSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode _MessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetSecurityPolicy(TBHandle otbHandle, OTChar** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSecurityPolicy(TBHandle otbHandle, const OTChar* _SecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUserIdentityToken(TBHandle otbHandle, UserIdentityTokenStruct* pUserIdentityToken);
	TBCORE_IF TBHandle OTAPI_CALL OTCSessionGetUserIdentityTokenHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetUserSecurityPolicy(TBHandle otbHandle, OTChar** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUserSecurityPolicy(TBHandle otbHandle, const OTChar* _SecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionImpersonateDifferentUser(TBHandle otbHandle, UserIdentityTokenStruct* userIdentityHandle, const OTChar* securityPolicy, OTUInt32 preferredLocaleCount, const OTChar** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetName(TBHandle otbHandle, OTChar** pName);
	TBCORE_IF NodeIdStruct* OTAPI_CALL OTCSessionGetSessionIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetName(TBHandle otbHandle, const OTChar* _Name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetUseIPv4AddressFlag(TBHandle otbHandle, bool* pUseIPv4Flag);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetUseIPv4AddressFlag(TBHandle otbHandle, const bool _UseIPv4Flag);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetServerCertificate(TBHandle otbHandle, OTUInt32* serverCertificateCount, unsigned char** pServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetServerCertificate(TBHandle otbHandle, OTUInt32 ServerCertificateCount, const unsigned char* _ServerCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetNetworkTimeout(TBHandle otbHandle, OTUInt32* pNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetNetworkTimeout(TBHandle otbHandle, OTUInt32 _NetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetAutoReconnectInterval(TBHandle otbHandle, OTUInt32 _AutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 _ConnectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const OTChar** preferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, OTChar*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetNamespaceTable(TBHandle otbHandle, TBHandle* namespaceTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUpdateNamespaceTable(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetCustomDataTypeIds(TBHandle otbHandle, size_t *pCount, NodeIdStruct** ppDataTypeIds);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDataTypeDescription(TBHandle otbHandle, const NodeIdStruct* pDataTypeId, TBHandle* pDescriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDataTypeDescriptionByValue(TBHandle otbHandle, const ValueStruct* pValue, TBHandle* pDescriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetInstanceCertificate(TBHandle otbHandle, const OTChar* certificateFile, const OTChar* privateKeyFile, const OTChar* password);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCancel(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 requestId,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pNoOfCancelledRequests,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRegisterNodes(TBHandle otbHandle,
		OTUInt32 diagnosticToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		NodeIdStruct **ppNewNodeIds,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUnregisterNodes(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionGetDiagnosticInfo(TBHandle otbHandle, OTUInt32* pConnectCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUpdateDictionaries(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionUpdateDictionariesAsync(TBHandle otbHandle, void* transactionHandle);

	TBCORE_IF void OTAPI_CALL OTCCertificateChangedGetCertificate(TBHandle otbHandle, ByteStringStruct* ppCertificate);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCCertificateChangedGetValidationResult(TBHandle otbHandle);
	TBCORE_IF void OTAPI_CALL OTCCertificateChangedComplete(TBHandle otbHandle, EnumStatusCode result);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedPublishingInterval(TBHandle otbHandle, double* pRevisedPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetLifeTimeCount(TBHandle otbHandle, OTUInt32* pLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetLifeTimeCount(TBHandle otbHandle, OTUInt32 _LifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedLifeTimeCount(TBHandle otbHandle, OTUInt32* pRevisedLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetRevisedMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pRevisedMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 _MaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionEnablePublishing(TBHandle otbHandle, bool _PublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetPriority(TBHandle otbHandle, unsigned char _Priority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetDiagnosticInformation(TBHandle otbHandle, OTUInt32* pNumberOfMonitoredItems, OTUInt32* pReceivedNotifications, OTUInt32* pReceviedDataChanges, OTUInt32* pReceivedEvents);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MonitoredItem
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemConnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemAddItemsToReport(TBHandle otbHandle,
			OTUInt32 itemsToReportCount, TBHandle* itemsToReport, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCMonitoredItemRemoveItemsToReport(TBHandle otbHandle,
			OTUInt32 itemsToReportCount, TBHandle* itemsToReport, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTCMonitoredItem_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Session
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionWrite(TBHandle otbHandle,
			OTUInt32 diagnosticsToReturn, unsigned writeValuesCount, WriteValueStruct* pWriteValues,
			TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics, unsigned* resultsCount, EnumStatusCode** enum_results, unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
			EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionWriteAsync(TBHandle otbHandle, void* requestHandle, unsigned writeValuesCount, WriteValueStruct* pWriteValues, EnumStatusCode* __pReturn, OTUInt32 requestId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRead(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn, EnumTimestampsToReturn enum_returnTimestamps, unsigned nodesToReadCount, ReadValueIdStruct* pNodesToRead, double maxAge,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics, unsigned* valuesCount, DataValueStruct** pValues, unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionReadAsync(TBHandle otbHandle, void* requestHandle, EnumTimestampsToReturn enum_returnTimestamps, unsigned nodesToReadCount, ReadValueIdStruct* pNodesToRead, double maxAge, EnumStatusCode* __pReturn, OTUInt32 requestId);

#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadRaw(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadRawAsync(TBHandle otbHandle,
			void* requestHandle,
			EnumTimestampsToReturn enum_returnTimestamps,
			bool releaseContinuationPoints,
			ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
			unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
			EnumStatusCode* __pReturn,
			OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadProcessed(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps, bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadProcessedAsync(TBHandle otbHandle,
		void* requestHandle,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadEvent(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* valuesCount, HistoryReadResultStruct** pValues,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionHistoryReadEventAsync(TBHandle otbHandle,
		void* requestHandle,
		EnumTimestampsToReturn enum_returnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		unsigned nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);
#endif

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryFirst(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		OTUInt32* pParsingResultsCount, ParsingResultStruct** ppParsingResults,
		ContentFilterResultStruct* pFilterResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryFirstAsync(TBHandle otbHandle,
		void* requestHandle,
		ViewDescriptionStruct* pView,
		unsigned nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		unsigned maxDataSetsToReturn,
		unsigned maxReferencesToReturn,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryNext(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionQueryNextAsync(TBHandle otbHandle,
		void* requestHandle,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		EnumStatusCode* __pReturn,
		OTUInt32 requestId);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionAddSubscription(TBHandle otbHandle,
			TBHandle subscription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionRemoveSubscription(TBHandle otbHandle,
			TBHandle subscription, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowse(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* resultsCount, BrowseResultStruct** pResults,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionSetSecurityConfiguration(TBHandle otbHandle,
			EnumMessageSecurityMode enum_messageSecurityMode,
			const OTChar* securityPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNext(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* resultsCount, BrowseResultStruct** pResults,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNextAsync(TBHandle otbHandle, void* requestHandle,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionConnect(TBHandle otbHandle,
			bool deep, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionBrowseNode(TBHandle otbHandle,
		ViewDescriptionStruct* pViewDescription,
		BrowseDescriptionStruct* pBrowseDescription,
		unsigned* resultsCount, ReferenceDescriptionStruct** pResults,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionTranslateBrowsePathToNodeIds(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned browsePathCount, const OTChar** browsePath,
		unsigned startingNodeCount, const OTChar** startingNode,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* browsePathResultCount, BrowsePathResultStruct** pBrowsePathResult,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionTranslateBrowsePathToNodeIds2(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const BrowsePathStruct** ppBrowsePath,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethods(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		unsigned methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* methodCallResultCount, CallMethodResultStruct** pMethodCallResult,
		unsigned* diagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethodsAsync(TBHandle otbHandle, void* requestHandle,
			OTUInt32 methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
			EnumStatusCode* __pReturn,
			OTUInt32 requestId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSessionCallMethod(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		NodeIdStruct* pObjectId,
		NodeIdStruct* pMethodId,
		unsigned inputArgsCount, ValueStruct* pInputArgs,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		unsigned* outputArgsCount, ValueStruct** pOutputArgs,
		unsigned* inputArgStatusCodesCount, EnumStatusCode** enum_inputArgStatusCodes,
		unsigned* inputArgDiagnosticInfosCount, DiagnosticInfoStruct** ppInputArgDiagnosticInfos,
		DiagnosticInfoStruct* pDiagnosticInfo,
		EnumStatusCode* enum_callResult, EnumStatusCode* __pReturn);

	TBCORE_IF void OTAPI_CALL OTCSessionIgnoreMissingNonce(TBHandle otbHandle, bool ignoreNonce);

	TBCORE_IF void* OTAPI_CALL OTCSession_Internal_Construct(TBHandle apiHandle, bool addRef);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Client::RedundantSession
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTCRedundantSession_Internal_Construct(TBHandle apiHandle, bool addRef);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetUrls(TBHandle otbHandle, OTUInt32* pUrlCount, OTChar*** ppSessionUrls);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetServerCertificates(TBHandle otbHandle, OTUInt32* pSize, ByteStringStruct** ppServerCertificates);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetServerInformation(TBHandle otbHandle, OTUInt32 serverCount, const OTChar** pUrls, OTUInt32 serverCertificatesCount, const ByteStringStruct** pServerCertificates, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSessionTimeout(TBHandle otbHandle, double* pSessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetSessionTimeout(TBHandle otbHandle, double sessionTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetRevisedSessionTimeout(TBHandle otbHandle, double* pRevisedSessionTimeout, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSecurityPolicy(TBHandle otbHandle, OTChar** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetSecurityConfiguration(TBHandle otbHandle, EnumMessageSecurityMode messageSecurityMode, const OTChar* securityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetUserSecurityPolicy(TBHandle otbHandle, OTChar** pUserSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetUserSecurityPolicy(TBHandle otbHandle, const OTChar* securityPolicy);
	TBCORE_IF const UserIdentityTokenStruct* OTAPI_CALL OTCRedundantSessionGetUserIdentityTokenHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetUserIdentityToken(TBHandle otbHandle, const UserIdentityTokenStruct* pUserIdentityToken);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSessionId(TBHandle otbHandle, NodeIdStruct* sessionIdHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetName(TBHandle otbHandle, const OTChar** pSessionName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetName(TBHandle otbHandle, const OTChar* name);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetUseIPv4AddressFlag(TBHandle otbHandle, bool* pUseIPv4Flag);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetUseIPv4AddressFlag(TBHandle otbHandle, const bool _UseIPv4Flag);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetNetworkTimeout(TBHandle otbHandle, OTUInt32* pNetworkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetNetworkTimeout(TBHandle otbHandle, OTUInt32 networkTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetAutoReconnectInterval(TBHandle otbHandle, OTUInt32* pAutoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetAutoReconnectInterval(TBHandle otbHandle, OTUInt32 autoReconnectInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32* pConnectionMonitorInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetConnectionMonitoringInterval(TBHandle otbHandle, OTUInt32 connectionMonitoringInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, OTChar*** ppPreferredLocaleStrings);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetPreferredLocales(TBHandle otbHandle, OTUInt32 preferredLocaleCount, const OTChar** pPreferredLocaleStrings);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 timeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetServiceTimeout(TBHandle otbHandle, EnumTimeoutGroup group, OTUInt32 *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetPrimaryIndex(TBHandle otbHandle, OTUInt32* pPrimaryIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetRedundancyMode(TBHandle otbHandle, EnumRedundancySupport* pRedundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetRedundancyMode(TBHandle otbHandle, EnumRedundancySupport redundancyMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSetInstanceCertificate(TBHandle otbHandle, const OTChar* certificateFile, const OTChar* privateKeyFile, const OTChar* password);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionConnect(TBHandle otbHandle, bool deep, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionDisconnect(TBHandle otbHandle, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionIsConnected(TBHandle otbHandle, bool* pConnected, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionImpersonateDifferentUser(TBHandle otbHandle, const UserIdentityTokenStruct* pUserAuthenticationToken,
		const OTChar* userSecurityPolicy, OTUInt32 preferredLocaleCount, const OTChar **preferredLocaleStrings, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** ppSubscriptions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionAddSubscription(TBHandle otbHandle, TBHandle pSubscription, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRemoveSubscription(TBHandle otbHandle, TBHandle pSubscription, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetNamespaceTable(TBHandle otbHandle, TBHandle* pNamespaceTable, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUpdateNamespaceTable(TBHandle otbHandle, OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUpdateDictionaries(TBHandle otbHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUpdateDictionariesAsync(TBHandle otbHandle, void* transactionHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetCustomDataTypeIds(TBHandle otbHandle, size_t *pCount, NodeIdStruct** ppDataTypeIds, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetDataTypeDescription(TBHandle otbHandle, const NodeIdStruct* pDataTypeId, TBHandle* pDescriptionHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionGetDataTypeDescriptionByValue(TBHandle otbHandle, const ValueStruct* pValue, TBHandle* pDescriptionHandle, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionSwitchover(TBHandle otbHandle, void* requestHandle, OTUInt32 primaryIndex, EnumStatusCode* pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionWrite(
		TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 nodesToWriteCount, WriteValueStruct* pNodesToWrite,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, EnumStatusCode** ppEnumResults,
		OTUInt32* pDiagnosticInfoCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionWriteAsync(
		TBHandle otbHandle, void* requestHandle, OTUInt32 writeValuesCount,
		WriteValueStruct* pWriteValues,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRead(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		OTUInt32 nodesToReadCount, ReadValueIdStruct* pNodesToRead,
		double maxAge,
		void* pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, DataValueStruct** ppValues,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionReadAsync(TBHandle otbHandle, void* requestHandle, EnumTimestampsToReturn enumReturnTimestamps,
		OTUInt32 nodesToReadCount, ReadValueIdStruct* pNodesToRead,
		double maxAge, OTUInt32 requestId, OTUInt32 redundantServerIndex, EnumStatusCode* pReturn);
#if TB5_HISTORY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadRaw(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		void* pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadRawAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadRawModifiedDetailsStruct *pHistoryReadRawModifiedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadProcessed(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadProcessedAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		ReadProcessedDetailsStruct *pHistoryReadProcessedDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadEvent(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pValuesCount, HistoryReadResultStruct** ppValues,
		OTUInt32* pDiagnisticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionHistoryReadEventAsync(TBHandle otbHandle, void* requestHandle,
		EnumTimestampsToReturn enumReturnTimestamps,
		bool releaseContinuationPoints,
		const ReadEventDetailsStruct *pHistoryReadEventDetails,
		OTUInt32 nodesToReadCount, HistoryReadValueIdStruct* pNodesToRead,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
#endif

#if TB5_QUERY
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryFirst(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount, QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pContinuationPoint,
		OTUInt32* pParsingResultsCount, ParsingResultStruct** ppParsingResults,
		ContentFilterResultStruct* pFilterResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryFirstAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pView,
		OTUInt32 nodeTypesCount,
		NodeTypeDescriptionStruct* pNodeTypes,
		ContentFilterStruct* pFilter,
		OTUInt32 maxDataSetsToReturn,
		OTUInt32 maxReferencesToReturn,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryNext(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pQueryDataSetsCount,
		QueryDataSetStruct** ppQueryDataSets,
		ByteStringStruct* pRevisedContinuationPoint,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionQueryNextAsync(TBHandle otbHandle, void* requestHandle,
		bool releaseContinuationPoint,
		ByteStringStruct* pContinuationPoint,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowse(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		ViewDescriptionStruct* pViewDescription,
		OTUInt32 browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, BrowseResultStruct** ppResults,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseAsync(TBHandle otbHandle, void* requestHandle,
		ViewDescriptionStruct* pViewDescription,
		unsigned browseDescriptionsCount, BrowseDescriptionStruct* pBrowseDescriptions,
		OTUInt32 maxReferencesPerNode,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNextAsync(TBHandle otbHandle, void* requestHandle,
		unsigned continuationPointsCount, const ByteStringStruct* continuationPoints,
		bool releaseContinuationPoints,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNext(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 continuationPointCount, const ByteStringStruct* pContinuationPoint,
		bool releaseContinuationPoints,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pResultsCount, BrowseResultStruct** ppResults,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionBrowseNode(TBHandle otbHandle, ViewDescriptionStruct* pViewDescription,
		BrowseDescriptionStruct* pBrowseDescription,
		OTUInt32* pResultsCount, ReferenceDescriptionStruct** ppResults,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionTranslateBrowsePathToNodeIds(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const OTChar** pBrowsePath,
		OTUInt32 startingNodeCount, const OTChar** pStartingNodes,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionTranslateBrowsePathToNodeIds2(TBHandle otbHandle,
		OTUInt32 diagnosticsToReturn,
		OTUInt32 browsePathCount, const BrowsePathStruct** ppBrowsePaths,
		TBHandle pStringTableHandle, DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pBrowsePathResultCount, BrowsePathResultStruct** ppBrowsePathResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethods(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 methodCallRequestCount,
		CallMethodRequestStruct* pMethodCallRequest,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pMethodCallResultCount,
		CallMethodResultStruct** ppMethodCallResult,
		OTUInt32* pDiagnosticInfosCount, DiagnosticInfoStruct** ppDiagnosticInfos,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethodsAsync(TBHandle otbHandle, void* requestHandle, OTUInt32 methodCallRequestCount, CallMethodRequestStruct* pMethodCallRequest,
		OTUInt32 requestId,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCallMethod(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		NodeIdStruct* pObjectId,
		NodeIdStruct* pMethodId,
		OTUInt32 inputArgsCount, ValueStruct* pInputArgs,
		OPTIONAL IN OUT TBHandle pStringTableHandle,
		OPTIONAL OUT DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pOutputArgsCount, ValueStruct** ppOutputArgs,
		OTUInt32* pInputArgStatusCodesCount, EnumStatusCode** ppEnumInputArgStatusCodes,
		OTUInt32* pInputArgumentDiagnosticInfosCount, OPTIONAL OUT DiagnosticInfoStruct** ppInputArgumentDiagnosticInfos,
		OPTIONAL OUT DiagnosticInfoStruct* pDiagnosticInfo,
		EnumStatusCode* pEnumCallResult,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionCancel(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 requestId,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32* pNoOfCancelledRequests,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionRegisterNodes(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		NodeIdStruct **ppNewNodeIds,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSessionUnregisterNodes(TBHandle otbHandle, OTUInt32 diagnosticsToReturn,
		OTUInt32 noOfNodeIds, const NodeIdStruct *pNodeIds,
		TBHandle pStringTableHandle,
		DiagnosticInfoStruct* pServiceDiagnostics,
		OTUInt32 redundantServerIndex,
		EnumStatusCode* pReturn);
	TBCORE_IF void OTAPI_CALL OTCRedundantSessionIgnoreMissingNonce(TBHandle otbHandle, bool ignoreNonce);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Subscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionRemoveAllMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionConnectMonitoredItems(TBHandle otbHandle, OTUInt32 itemsToConnectCount, TBHandle* itemsToConnect, EnumStatusCode** ppMIConnectResults);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionConnect(TBHandle otbHandle,
			bool deep, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionAddMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionRemoveMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdateMonitoredItems(TBHandle otbHandle,
			unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdateChangedMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionUpdate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionIsConnected(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetAllMonitoredItemsMonitoringMode(TBHandle otbHandle,
			EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionSetMonitoredItemsMonitoringMode(TBHandle otbHandle,
			unsigned monitoredItemsCount, TBHandle* monitoredItems,
			EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCSubscriptionEnableRepublish(TBHandle otbHandle, bool bEnable);

	TBCORE_IF void* OTAPI_CALL OTCSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class RedundantSubscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionRemoveAllMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionConnectMonitoredItems(TBHandle otbHandle,
		OTUInt32 itemsToConnectCount, TBHandle* itemsToConnect, EnumStatusCode** ppMIConnectResults);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionConnect(TBHandle otbHandle,
		bool deep, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionDisconnect(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionAddMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionRemoveMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdateMonitoredItems(TBHandle otbHandle,
		unsigned itemsCount, TBHandle* items, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdateChangedMonitoredItems(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionUpdate(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionIsConnected(TBHandle otbHandle, bool* pIsConnected, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetAllMonitoredItemsMonitoringMode(TBHandle otbHandle,
		EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMonitoredItemsMonitoringMode(TBHandle otbHandle,
		unsigned monitoredItemsCount, TBHandle* monitoredItems,
		EnumMonitoringMode enum_eMonitoringMode, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionEnableRepublish(TBHandle otbHandle, bool bEnable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedPublishingInterval(TBHandle otbHandle, double* pRevisedPublishingInterval, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetLifeTimeCount(TBHandle otbHandle, OTUInt32* pLifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetLifeTimeCount(TBHandle otbHandle, OTUInt32 _LifeTimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedLifeTimeCount(TBHandle otbHandle, OTUInt32* pRevisedLifeTimeCount, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetRevisedMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pRevisedMaxKeepAliveCount, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 _MaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionEnablePublishing(TBHandle otbHandle, bool _PublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionSetPriority(TBHandle otbHandle, unsigned char _Priority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId, OTUInt32 redundantServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantSubscriptionGetPrimaryServerIndex(TBHandle otbHandle, OTUInt32* primaryServerIndex);
	TBCORE_IF void* OTAPI_CALL OTCRedundantSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class RedundantMonitoredItem
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTCRedundantMonitoredItem_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemConnect(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemDisconnect(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemIsConnected(TBHandle otbHandle, bool* pIsConnected, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemAddItemsToReport(TBHandle otbHandle, OTUInt32 itemsToReportCount, TBHandle* itemsToReport);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemRemoveItemsToReport(TBHandle otbHandle, OTUInt32 itemsToReportCount, TBHandle* itemsToReport);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetPrimaryServerIndex(TBHandle otbHandle, OTUInt32* primaryServerIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetNodeId(TBHandle otbHandle, const NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetAttributeId(TBHandle otbHandle, EnumAttributeId attributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetIndexRange(TBHandle otbHandle, const NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode monitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetSamplingInterval(TBHandle otbHandle, OTDouble* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetSamplingInterval(TBHandle otbHandle, OTDouble samplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetRevisedSamplingInterval(TBHandle otbHandle, OTDouble* pRevisedSamplingInterval, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 queueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetRevisedQueueSize(TBHandle otbHandle, OTUInt32* pRevisedQueueSize, OTUInt32 serverIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetDiscardOldest(TBHandle otbHandle, bool discardOldest);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetFilter(TBHandle otbHandle, DataChangeFilterStruct* pFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetFilter(TBHandle otbHandle, const DataChangeFilterStruct* pFilter);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemGetEventFilter(TBHandle otbHandle, EventFilterStruct* pFilter);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTCRedundantMonitoredItemSetEventFilter(TBHandle otbHandle, const EventFilterStruct* pFilter);
#endif
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseNode
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetUserData(TBHandle otbHandle, void** pUserData);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetUserData(TBHandle otbHandle, void* _UserData);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetBrowseNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetBrowseName(TBHandle otbHandle, const QualifiedNameStruct* browseNameHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetDisplayNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetDisplayName(TBHandle otbHandle, const LocalizedTextStruct* displayNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetNodeClass(TBHandle otbHandle, EnumNodeClass* pNodeClass);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetNodeId(TBHandle otbHandle, const NodeIdStruct* nodeIdHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetWriteMask(TBHandle otbHandle, OTUInt32* pWriteMask);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetWriteMask(TBHandle otbHandle, OTUInt32 _WriteMask);
	TBCORE_IF TBHandle OTAPI_CALL OTSBaseNodeGetDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetDescription(TBHandle otbHandle, const LocalizedTextStruct* descriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestGetRequestState(TBHandle otbHandle, EnumRequestState* pRequestState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestSetRequestState(TBHandle otbHandle, EnumRequestState _RequestState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestIsCancelled(TBHandle otbHandle, OTBoolean *result);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetClientRequestHandle(TBHandle otbHandle, OTUInt32* pClientHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetAuditEntryId(TBHandle otbHandle, OTChar** pAuditEntryId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionIsCancelled(TBHandle otbHandle, OTBoolean *result);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetDataTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataType(TBHandle otbHandle, const NodeIdStruct* dataTypeHandle, bool validateDataTypeNode);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetVariableTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetVariableType(TBHandle otbHandle, void* variableTypeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetAccessLevel(TBHandle otbHandle, EnumAccessLevel* pAccessLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetAccessLevel(TBHandle otbHandle, EnumAccessLevel _AccessLevel);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetIsHistorizing(TBHandle otbHandle, bool* pIsHistorizing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetIsHistorizing(TBHandle otbHandle, bool _IsHistorizing);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetMinimumSamplingInterval(TBHandle otbHandle, double* pMinimumSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetMinimumSamplingInterval(TBHandle otbHandle, double minimumSamplingInterval);
	TBCORE_IF bool OTAPI_CALL OTSVariableUseDataProvider(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetDataValue(TBHandle otbHandle, DataValueStruct* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValue(TBHandle otbHandle, const DataValueStruct* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValueWithChangedSemantics(TBHandle otbHandle, void* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetValueRank(TBHandle otbHandle, OTInt32* pValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetValueRank(TBHandle otbHandle, OTInt32 _ValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetAccessGroupKey(TBHandle otbHandle, OTUInt32* pAccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetAccessGroupKey(TBHandle otbHandle, OTUInt32 _AccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetArrayDimensions(TBHandle otbHandle, unsigned* arrayDimensionsCount, OTUInt32** pArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetArrayDimensions(TBHandle otbHandle, unsigned ArrayDimensionsCount, OTUInt32* _ArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableSetDataValueChangeCallbackEnabled(TBHandle otbHandle, bool enabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectGetEventNotifier(TBHandle otbHandle, EnumEventNotifier* pEventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectSetEventNotifier(TBHandle otbHandle, EnumEventNotifier _EventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetExecutable(TBHandle otbHandle, bool* pExecutable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodSetExecutable(TBHandle otbHandle, bool _Executable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetAccessGroupKey(TBHandle otbHandle, OTUInt32* pAccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodSetAccessGroupKey(TBHandle otbHandle, OTUInt32 _AccessGroupKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF TBHandle OTAPI_CALL OTSReferenceTypeGetInverseNameHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetInverseName(TBHandle otbHandle, const LocalizedTextStruct* inverseNameHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeGetIsSymmetric(TBHandle otbHandle, bool* pIsSymmetric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceTypeSetIsSymmetric(TBHandle otbHandle, bool _IsSymmetric);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetIsAbstract(TBHandle otbHandle, bool* pIsAbstract);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetIsAbstract(TBHandle otbHandle, bool _IsAbstract);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableTypeGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetDataValue(TBHandle otbHandle, const DataValueStruct* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetValueRank(TBHandle otbHandle, OTInt32* pValueRank);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetValueRank(TBHandle otbHandle, OTInt32 _ValueRank);
	TBCORE_IF TBHandle OTAPI_CALL OTSVariableTypeGetDataTypeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetDataType(TBHandle otbHandle, const NodeIdStruct* dataTypeHandle, bool validateDataTypeNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetArrayDimensions(TBHandle otbHandle, unsigned* arrayDimensionsCount, OTUInt32** pArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeSetArrayDimensions(TBHandle otbHandle, unsigned ArrayDimensionsCount, OTUInt32* _ArrayDimensions);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewGetEventNotifier(TBHandle otbHandle, EnumEventNotifier* pEventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewSetEventNotifier(TBHandle otbHandle, EnumEventNotifier _EventNotifier);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewGetContainsNoLoops(TBHandle otbHandle, OTBoolean* pContainsNoLoops);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSViewSetContainsNoLoops(TBHandle otbHandle, OTBoolean _ContainsNoLoops);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUrl(TBHandle otbHandle, OTChar** pUrl);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUrl(TBHandle otbHandle, const OTChar* _Url);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetIsOpen(TBHandle otbHandle, bool* pIsOpen);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateRevocationListLocation(TBHandle otbHandle, OTChar** pUserCertificateRevocationListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateRevocationListLocation(TBHandle otbHandle, const OTChar* _UserCertificateRevocationListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateTrustListLocation(TBHandle otbHandle, OTChar** pUserCertificateTrustListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateTrustListLocation(TBHandle otbHandle, const OTChar* _UserCertificateTrustListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserCertificateIssuerListLocation(TBHandle otbHandle, OTChar** pUserCertificateIssuerListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserCertificateIssuerListLocation(TBHandle otbHandle, const OTChar* _UserCertificateIssuerListLocation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetUserPkiStoreConfiguration(TBHandle otbHandle, PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetUserPkiStoreConfiguration(TBHandle otbHandle, const PkiStoreConfigurationStruct* pPkiStoreConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetInstanceCertificate(TBHandle otbHandle, const OTChar* certificateFile, const OTChar* privateKeyFile, const OTChar* password);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetMonitoringMode(TBHandle otbHandle, EnumMonitoringMode* pMonitoringMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetSamplingInterval(TBHandle otbHandle, double* pSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemSetSamplingInterval(TBHandle otbHandle, double _SamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetDiscardOldest(TBHandle otbHandle, bool* pDiscardOldest);
#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByBaseEvent(TBHandle otbHandle, TBHandle eventHandle, bool evaluateWhereClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByBaseEventNotification(TBHandle otbHandle, TBHandle eventHandle, bool evaluateWhereClause);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportEventByFields(TBHandle otbHandle, TBHandle eventFieldsHandle);
#endif
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemReportDataChange(TBHandle otbHandle, const DataValueStruct* pValue, bool evaluateFilters);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetQueueSize(TBHandle otbHandle, OTUInt32* pQueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemSetQueueSize(TBHandle otbHandle, OTUInt32 _QueueSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetId(TBHandle otbHandle, OTUInt32* pMonitoredItemId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoredItemGetTriggeredMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetNodeIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetFilterHandle(TBHandle otbHandle);
#if TB5_ALARMS
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetEventFilterHandle(TBHandle otbHandle);
#endif
	TBCORE_IF TBHandle OTAPI_CALL OTSMonitoredItemGetIndexRangeHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPublishingInterval(TBHandle otbHandle, double* pPublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetPublishingInterval(TBHandle otbHandle, double _PublishingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetLifetimeCount(TBHandle otbHandle, OTUInt32* pLifetimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetLifetimeCount(TBHandle otbHandle, OTUInt32 _LifetimeCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* pMaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 _MaxKeepAliveCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* pMaxNotificationsPerPublish);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPublishingEnabled(TBHandle otbHandle, bool* pPublishingEnabled);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetPriority(TBHandle otbHandle, unsigned char* pPriority);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetId(TBHandle otbHandle, OTUInt32* pId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetSession(TBHandle otbHandle, TBHandle* pSessionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetMonitoredItems(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionGetDiagnosticInformation(TBHandle otbHandle, OTUInt32* pNumberOfMonitoredItems);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSubscriptionEnableClientHandleValidation(TBHandle otbHandle, bool enableCheck);

	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetValueIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetDataValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSReadRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestSetDataValue(TBHandle otbHandle, void* dataValueHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadRequestGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSWriteRequestGetWriteValueHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSWriteRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteRequestGetNode(TBHandle otbHandle, TBHandle* pBaseNodeHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetMaxAge(TBHandle otbHandle, double* pMaxAge);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetTimestampToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampToReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetViewDescription(TBHandle otbHandle, ViewDescriptionStruct* pViewDescription);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseTransactionGetRequestedMaxReferencesPerNode(TBHandle otbHandle, OTUInt32* maxReferencesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeIdToBrowse(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeToBrowse(TBHandle otbHandle, TBHandle* pNodeToBrowse);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetBrowseDirection(TBHandle otbHandle, EnumBrowseDirection* direction);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetReferenceTypeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetIncludeSubtypes(TBHandle otbHandle, bool* includeSubtypes);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetNodeClassMask(TBHandle otbHandle, EnumNodeClass* pNodeClassMask);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseRequestGetResultMask(TBHandle otbHandle, EnumResultMask* pResultMask);

	TBCORE_IF void* OTAPI_CALL OTSReadTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetSubscriptions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetUserGroupIndex(TBHandle otbHandle, OTUInt32* pUserGroupIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetMessageSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* pMessageSecurityMode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetSecurityPolicy(TBHandle otbHandle, OTChar** pSecurityPolicy);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetPreferredLocales(TBHandle otbHandle, OTUInt32 *pPreferredLocaleCount, OTChar*** pppPreferredLocales);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionUserClientId(TBHandle otbHandle, OTChar** pUserClientId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetName(TBHandle otbHandle, OTChar** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetClientPeerInfo(TBHandle otbHandle, OTChar** pPeerInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetId(TBHandle otbHandle, NodeIdStruct* pId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionGetTimeout(TBHandle otbHandle, double *pTimeout);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionSetTimeout(TBHandle otbHandle, double timeout);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionRegisterFileHandle(TBHandle otbHandle, TBHandle fileObject, void * internalFileHandle, OTUInt32* uaFileHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessionUnregisterFileHandle(TBHandle otbHandle, TBHandle fileObjectHandle, OTUInt32 uaFileHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSSessiongetFileHandle(TBHandle otbHandle, TBHandle fileObjectHandle, OTUInt32 uaFileHandle, void** ppInternalFileHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetAttributeId(TBHandle otbHandle, EnumAttributeId* pAttributeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetMinimumSamplingInterval(TBHandle otbHandle, double* pMinimumSamplingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetPreviousState(TBHandle otbHandle, EnumMonitoringState* pPreviousState);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMonitoringChangeGetCurrentState(TBHandle otbHandle, EnumMonitoringState* pCurrentState);
	TBCORE_IF TBHandle OTAPI_CALL OTSReferenceIteratorGetReferenceDescriptionHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetObjectIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetMethodIdHandle(TBHandle otbHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetInputArgumentsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetOutputArguments(TBHandle otbHandle, OTUInt32 argumentCount, void* outputArgumentsHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode _StatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetInputReturns(TBHandle otbHandle, unsigned InputReturnsCount, EnumStatusCode* _InputReturns);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetInputArgumentDiagnosticInfos(TBHandle otbHandle, OTUInt32 diagnosticInfosCount, void* diagnosticInfosHandle);
	TBCORE_IF TBHandle OTAPI_CALL OTSMethodCallRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseNode
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateVariableInstance(const NodeIdStruct* pNodeId, const NodeIdStruct* pTypeDefinitionId,
		TBHandle* hCreatedNode, bool allowNullTypeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateObjectInstance(const NodeIdStruct* pTypeDefinitionId,
		TBHandle* hCreatedNode, bool allowNullTypeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCreateMethodInstance(const NodeIdStruct* pNodeId,
		TBHandle* hCreatedNode);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeAddReference(TBHandle otbHandle,
			NodeIdStruct* pReferenceId,
			TBHandle TargetNode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeAddReferenceEx(TBHandle otbHandle,
		NodeIdStruct* pReferenceId,
		TBHandle TargetNode,
		bool suppressErrorOnDuplicateReference, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemoveReferenceTo(TBHandle otbHandle,
			TBHandle TargetNode,
			NodeIdStruct* pReferenceId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInsert(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemove(TBHandle otbHandle,
			bool includeReferences, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInsertTree(TBHandle otbHandle, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCopyTree(TBHandle otbHandle,
			TBHandle* copiedTreeHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeCopyAttributeValues(TBHandle otbHandle,
			TBHandle targetNodeHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeRemoveReferencesTo(TBHandle otbHandle,
			TBHandle TargetNode, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetReferenceIterator(TBHandle otbHandle,
			EnumBrowseDirection enum_browseDir,
			NodeIdStruct* pPReferenceId,
			bool includeSubtypes,
			EnumNodeClass nodeClassMask,
			EnumResultMask resultMask, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeFindNode(TBHandle otbHandle,
		EnumBrowseDirection browseDirection,
		const NodeIdStruct* pReferenceId,
		bool includeSubtypes,
		const QualifiedNameStruct* pBrowseName , TBHandle** ppNodes, size_t* pNodeCount);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId,
			DataValueStruct* pAttributeValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeHasAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetAttribute(TBHandle otbHandle,
			EnumAttributeId enum_attributeId,
			DataValueStruct* pAttributeValue,
			bool bypassWriteMask, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeInit(TBHandle otbHandle,
			NodeIdStruct* pTypeId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetMethod(TBHandle otbHandle,
			const OTChar* propertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetMethodByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetVariable(TBHandle otbHandle,
			const OTChar* propertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetVariableByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetQualifiedVariable(TBHandle otbHandle,
			const QualifiedNameStruct * pPropertyName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetPropertyValue(TBHandle otbHandle,
			const OTChar* propertyName,
			DataValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeSetPropertyValueByQualifiedName(TBHandle otbHandle,
		const QualifiedNameStruct* pBrowseName, DataValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetObject(TBHandle otbHandle,
			const OTChar* objectName, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetObjectByBrowsePath(TBHandle otbHandle,
			const QualifiedNameStruct** browsePathElements, OTUInt32 browsePathElementsCount, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeIsOfUaType(TBHandle otbHandle,
			NodeIdStruct* pTypeId,
			bool includeSubtypes, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeIsInstanceOfUaType(TBHandle otbHandle,
			NodeIdStruct* pTypeId,
			bool includeSubtypes, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseNodeGetTypeNode(TBHandle otbHandle,
			NodeIdStruct* pTypeId, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AddressSpaceRoot
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetRoot(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetObjectsFolder(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetServerObject(TBHandle otbHandle, TBHandle* pObjectHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootValidate(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootParseDictionaries(TBHandle otbHandle, NodeIdStruct* dictNodeIds, size_t dictCount);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNamespaces(TBHandle otbHandle, TBHandle* namespaceStringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootAddNamespace(TBHandle otbHandle,
			const OTChar* Url,
			unsigned short* index, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootModifyNamespace(TBHandle otbHandle,
		OTUInt16 index,
		const OTChar* Url,EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootUpdateNamespacesArrayNode(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetServerUris(TBHandle otbHandle, TBHandle* serverUriStringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootAddServerUri(TBHandle otbHandle, const OTChar* serverUri, OTUInt16* pIndex, EnumStatusCode* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootUpdateServerArrayNode(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNode(TBHandle otbHandle,
		const NodeIdStruct* pNodeId, TBHandle* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetNodesFromNamespaces(TBHandle otbHandle,
		const OTChar** pNamespaceUris, size_t namespaceUriCount, TBHandle** ppNodes, size_t* pNodeCount);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootCreateObject(TBHandle otbHandle,
			TBHandle typeNode, TBHandle* __pReturn);

#if TB5_ALARMS
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetEvent(TBHandle otbHandle,
			const ByteStringStruct* eventId, TBHandle* __pReturn);
#endif

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootBeginSemanticsChange(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootEndSemanticsChange(TBHandle otbHandle, const LocalizedTextStruct* pMessage, OTUInt16 severity);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootBeginModelChange(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootEndModelChange(TBHandle otbHandle, const LocalizedTextStruct* pMessage, OTUInt16 severity);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceSetVariableDataValues(TBHandle otbHandle, OTUInt32 nodeIdCount, void** nodeIdHandles, const DataValueStruct** dataValues, EnumStatusCode** ppsetVariableDataValuesResults);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceSetVariableDataValuesByVar(TBHandle otbHandle, OTUInt32 nodeIdCount, void** variables, const DataValueStruct** dataValues, EnumStatusCode** ppsetVariableDataValuesResults);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootSetStandardObjectValues(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootAdaptStandardAddressSpace(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetToolkitNamespaceIndex(TBHandle otbHandle, OTUInt16* pNamespaceId);

	TBCORE_IF void* OTAPI_CALL OTSAddressSpaceRootGetHandle(bool addRef);
	TBCORE_IF void OTAPI_CALL OTSAddressSpaceRootReleaseHandle(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootRemoveNodesWithoutChecking(TBHandle otbHandle, OTUInt32 nodeCount, TBHandle* pNodes);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootGetDataTypeDescriptionByValue(TBHandle otbHandle, const ValueStruct* pValue, TBHandle* pDescriptionHandle);

	// Use these functions for testing purposes only
	TBCORE_IF void OTAPI_CALL OTSAddressSpaceRootCreate();
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAddressSpaceRootDestroy();

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataRequestComplete(TBHandle otbHandle, EnumStatusCode* __pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionComplete(TBHandle otbHandle,
			EnumStatusCode enum_requestStatus, EnumStatusCode* __pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetStringTable(TBHandle otbHandle,
		TBHandle* stringTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionSetStringTable(TBHandle otbHandle,
		TBHandle stringTableHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionGetDiagnosticsToReturn(TBHandle otbHandle,
		OTUInt32* pDiagnosticsToReturn);
	TBCORE_IF TBHandle OTAPI_CALL OTSDataTransactionGetServiceDiagnosticsHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTransactionSetServiceDiagnostics(TBHandle otbHandle, void* serviceDiagnosticsHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Variable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableGetUserAccessLevel(TBHandle otbHandle,
			OTUInt32 userGroupIndex, EnumAccessLevel* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSVariable_Internal_Construct(TBHandle apiHandle, bool addRef, EnumApiClassType apiClass);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Object
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSObject_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class File
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFile_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileOpen(TBHandle otbHandle, TBHandle sessionHandle, EnumOpenFileMode mode, OTUInt32* fileHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileClose(TBHandle otbHandle, TBHandle sessionHandle, OTUInt32 fileHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileRead(TBHandle otbHandle, TBHandle sessionHandle, OTUInt32 fileHandle, OTInt32 length, ByteStringStruct* data);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileWrite(TBHandle otbHandle, TBHandle sessionHandle, OTUInt32 fileHandle, const ByteStringStruct* data);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileGetPosition(TBHandle otbHandle, TBHandle sessionHandle, OTUInt32 fileHandle, OTUInt64* position);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileSetPosition(TBHandle otbHandle, TBHandle sessionHandle, OTUInt32 fileHandle, OTUInt64 position);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileGetPath(TBHandle otbHandle, OTChar** pFilePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileSetPath(TBHandle otbHandle, const OTChar* filePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileSetWritable(TBHandle otbHandle, bool writable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileGetWritable(TBHandle otbHandle, bool* pWritable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileSetAccessPatternKey(TBHandle otbHandle, OTUInt32 key);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileGetAccessPatternKey(TBHandle otbHandle, OTUInt32* pKey);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileUpdateSize(TBHandle otbHandle, OTUInt64 fileSize);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FileDirectory
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFileDirectory_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryCreateDirectory(TBHandle otbHandle,
			TBHandle sessionHandle, const OTChar* pDirectoryName, NodeIdStruct* pDirectoryNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryCreateFile(TBHandle otbHandle,
			TBHandle sessionHandle, const OTChar* pFileName, OTBoolean requestFileOpen, NodeIdStruct* pFileNodeId, OTUInt32* pFileHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryDelete(TBHandle otbHandle,
			TBHandle sessionHandle, const NodeIdStruct* pObjectToDelete);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryMoveOrCopy(TBHandle otbHandle,
			TBHandle sessionHandle, const NodeIdStruct* pObjectToMoveOrCopy, const NodeIdStruct* pTargetDirectory, OTBoolean createCopy,
			const OTChar* pNewName, NodeIdStruct* pNewNodeId);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryGetPath(TBHandle otbHandle, OTChar** pDirectoryPath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectorySetPath(TBHandle otbHandle, const OTChar* fullPath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryAddDirectory(TBHandle otbHandle, const OTChar* pDirectoryName, NodeIdStruct* pDirectoryNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryAddFile(TBHandle otbHandle, const OTChar* pFileName, NodeIdStruct* pFileNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectorySetAccessPatternKey(TBHandle otbHandle, OTUInt32 key);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFileDirectoryGetAccessPatternKey(TBHandle otbHandle, OTUInt32* pKey);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Method
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodGetUserExecutable(TBHandle otbHandle,
			OTUInt32 userGroupIndex, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodExecuteRequest(TBHandle otbHandle,
			TBHandle transaction,
			TBHandle request, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSMethod_Internal_Construct(TBHandle apiHandle, bool addRef);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodValidateInputArguments(TBHandle otbHandle,
		OTUInt32 inputArgumentValueSize, const ValueStruct** ppInputArgumentValues,
		OTUInt32* resultSize, EnumStatusCode** ppInputResults);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ObjectType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSObjectTypeGetBaseType(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSObjectType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReferenceType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSReferenceType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DataType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDataType_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeGetDataTypeDescription(TBHandle otbHandle, TBHandle* dataTypeDescriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeSetDataTypeDescription(TBHandle otbHandle, TBHandle dataTypeDescriptionHandle, const NodeIdStruct* pDescriptionId, const NodeIdStruct* pEncodingId, const NodeIdStruct* pDictionaryId, const NodeIdStruct* pEnumValuesId, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDataTypeRemoveDataTypeDescription(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class View
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSView_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class VariableType
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSVariableTypeGetBaseType(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSVariableType_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Endpoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointGetSessions(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointOpen(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointClose(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointAddSecurityConfiguration(TBHandle otbHandle,
			EnumMessageSecurityMode enum_messageSecurityMode,
			const OTChar* securityPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointAddUserTokenPolicy(TBHandle otbHandle,
			UserTokenPolicyStruct* pPolicy, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointIsRestrictedToSingleInterface(TBHandle otbHandle, bool* pIsRestricted);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointSetRestrictToSingleInterface(TBHandle otbHandle, bool restrictToSingleInterface, EnumStatusCode* pResult);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEndpointValidateUserCertificate(TBHandle otbHandle, const ByteStringStruct* x509Certificate, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSEndpoint_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Subscription
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSSubscription_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReadRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSReadRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class WriteRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSWriteRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadRawRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetVariable(TBHandle otbHandle, TBHandle* ppVariable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetDataValues(TBHandle otbHandle, OTUInt32 dataValueCount, const DataValueStruct** ppDataValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadRawRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadProcessedRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetVariable(TBHandle otbHandle, TBHandle* ppVariable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetAggregateType(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetDataValues(TBHandle otbHandle, OTUInt32 dataValueCount, const DataValueStruct** ppDataValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadProcessedRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BrowseBaseRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetReferences(TBHandle otbHandle, OTUInt32 referencesCount, const ReferenceDescriptionStruct** ppReferences);
	TBCORE_IF TBHandle OTAPI_CALL OTSBrowseBaseRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseBaseRequestDeleteContinuationPoint(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TranslateBrowsePathsToNodeIdsRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStartingNodeId(TBHandle otbHandle, NodeIdStruct* pStartingNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStartingNode(TBHandle otbHandle, TBHandle* pStartingNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetRelativePath(TBHandle otbHandle, RelativePathStruct* pRelativePath);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetTargets(TBHandle otbHandle, OTUInt32 targetCount, const BrowsePathTargetStruct** ppTargets);
	TBCORE_IF TBHandle OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadEventRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestHasContinuationPoint(TBHandle otbHandle, bool* pHasContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestCreateContinuationPoint(TBHandle otbHandle, TBHandle* ppContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetContinuationPoint(TBHandle otbHandle, TBHandle pContinuationPoint);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestDeleteContinuationPoint(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetIndexRange(TBHandle otbHandle, NumericRangeStruct* pIndexRange);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetEvents(TBHandle otbHandle, OTUInt32 eventsCount, const HistoryEventFieldListStruct** ppEvents);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);
	TBCORE_IF TBHandle OTAPI_CALL OTSHistoryReadEventRequestGetDiagnosticInfoHandle(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventRequestSetDiagnosticInfo(TBHandle otbHandle, void* diagnosticInfoHandle);
#endif
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReadTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReadTransactionUpdateTimeStamps(TBHandle otbHandle,
			DataValueStruct* pLocalValue,
			EnumAttributeId enum_attributeId, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSReadTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class WriteTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSWriteTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSWriteTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadRawTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionReturnBoundingValues(TBHandle otbHandle, bool* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadRawTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadProcessedTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetProcessingInterval(TBHandle otbHandle, double* pProcessingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetAggregateConfiguration(TBHandle otbHandle, AggregateConfigurationStruct* pAggregateConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadProcessedTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class CreateMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemRequestSetStatusCode(TBHandle otbHandle, EnumStatusCode statusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class CreateMonitoredItemsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSCreateMonitoredItemsTransactionSetServiceResult(TBHandle otbHandle, EnumStatusCode statusCode);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ModifyMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ModifyMonitoredItemsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemsTransactionGetSubscription(TBHandle otbHandle, TBHandle* pSubscriptionHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSModifyMonitoredItemsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteMonitoredItemRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteMonitoredItemRequestGetMonitoredItem(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteMonitoredItemRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteSubscriptionRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSubscriptionRequestGetSubscription(TBHandle otbHandle, TBHandle* pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSubscriptionRequestGetStatusCode(TBHandle otbHandle, EnumStatusCode *pStatusCode);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DeleteSessionRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDeleteSessionRequestGetSession(TBHandle otbHandle, TBHandle* pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BrowseNextTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBrowseNextTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TranslateBrowsePathsToNodeIdsTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTranslateBrowsePathsToNodeIdsTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryReadEventTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetStartTime(TBHandle otbHandle, DateTimeStruct* pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetEndTime(TBHandle otbHandle, DateTimeStruct* pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetFilter(TBHandle otbHandle, EventFilterStruct* pEventFilter, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoryReadEventTransactionGetRequests(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Session
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSSession_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MonitoringChange
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSMonitoringChange_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ReferenceIterator
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceIteratorMoveNext(TBHandle otbHandle);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSReferenceIteratorIsEnd(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSReferenceIterator_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MethodCallRequest
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSMethodCallRequest_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class MethodCallTransaction
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSMethodCallTransactionGetRequests(TBHandle otbHandle, OTUInt32* _pRetCount, TBHandle** __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSMethodCallTransaction_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseEvent
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSBaseEvent_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Condition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionEnable(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionDisable(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionAddBranch(TBHandle otbHandle,
		TBHandle branchHandle, NodeIdStruct* pBranchId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranch(TBHandle otbHandle,
		const NodeIdStruct* pBranchId, TBHandle* pConditionBranchHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionDeleteBranch(TBHandle otbHandle,
		const NodeIdStruct* pBranchId, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetBranches(TBHandle otbHandle,
		OTUInt32* pBranchesCount, NodeIdStruct** ppBranchIds, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSConditionGetTrunk(TBHandle otbHandle,
		TBHandle* pTrunkHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class BaseEventNotification
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSBaseEventNotification_Internal_Construct(TBHandle apiHandle, bool addRef);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationInit(TBHandle otbHandle,
			const NodeIdStruct* pEventType, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationRemoveProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationSetProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName,
			const ValueStruct* pProperty, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSBaseEventNotificationGetProperty(TBHandle otbHandle,
			const QualifiedNameStruct* pPropertyName, ValueStruct* pValue, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSIBaseEventReport(TBHandle otbHandle, NodeIdStruct *reportingNode, EnumStatusCode* __pReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineIsActive(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineDeactivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateMachineActivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSStateVariableReset(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TransitionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTransitionVariableReset(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSTransitionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSFiniteStateMachineChangeState(TBHandle otbHandle,
			TBHandle target, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSFiniteStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteStateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFiniteStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class FiniteTransitionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSFiniteTransitionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TwoStateVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableSetCurrentState(TBHandle otbHandle,
			bool newState, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableActivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableDeactivate(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSTwoStateVariableIsActive(TBHandle otbHandle, bool* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSTwoStateVariable_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableCondition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AlarmCondition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSAlarmConditionSuppress(TBHandle otbHandle,
			bool suppressed, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSAlarmCondition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineShelve(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineTimeShelve(TBHandle otbHandle,
			double duration, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSShelvedStateMachineUnshelve(TBHandle otbHandle, EnumStatusCode* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionEnable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionEnable_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionDisable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionDisable_Internal_Construct(TBHandle apiHandle, bool addRef);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class State
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSState_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class Transition
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSTransition_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class LimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineTimedShelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineTimedShelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineOneShotShelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineOneShotShelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ShelvedStateMachineUnshelve
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSShelvedStateMachineUnshelve_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionAddComment
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionAddComment_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableConditionAcknowledge
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableConditionAcknowledge_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class AcknowledgeableConditionConfirm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSAcknowledgeableConditionConfirm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ConditionRefresh
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSConditionRefresh_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLimitStateMachine
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLimitStateMachine_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveLevelAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveLevelAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveDeviationAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveDeviationAlarmSetSetpointVar(TBHandle otbHandle,
			TBHandle setpoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSExclusiveDeviationAlarmGetSetpointVar(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSExclusiveDeviationAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ExclusiveRateOfChangeAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSExclusiveRateOfChangeAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class DiscreteAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDiscreteAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class OffNormalAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSOffNormalAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class TripAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSTripAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveLimitAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveLimitAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveLevelAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveLevelAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveDeviationAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveDeviationAlarmSetSetpointVar(TBHandle otbHandle,
			TBHandle setpoint, EnumStatusCode* __pReturn);

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSNonExclusiveDeviationAlarmGetSetpointVar(TBHandle otbHandle, TBHandle* __pReturn);

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveDeviationAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class NonExclusiveRateOfChangeAlarm
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSNonExclusiveRateOfChangeAlarm_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointGetType(TBHandle otbHandle, EnumContinuationPointType* pContinuationPointType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointSetContext(TBHandle otbHandle, const void* pContext, OTUInt32 contextLength, EnumStatusCode* pStatusCode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerContinuationPointGetContext(TBHandle otbHandle, void** ppContext, OTUInt32* pContextLength);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerDictionaryVariable
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSDictionaryVariable_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDictionaryVariableRegisterDictionary(TBHandle otbHandle, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDictionaryVariableIsRegistered(TBHandle otbHandle, bool* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSDictionaryVariableGetTargetNamespaceUri(TBHandle otbHandle, OTChar** pResult);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class GetMonitoredItems
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF void* OTAPI_CALL OTSGetMonitoredItems_Internal_Construct(TBHandle apiHandle, bool addRef);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadRawContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pMaxNumberOfValuesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointReturnBoundingValues(TBHandle otbHandle, bool* pBoundingValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadRawContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadProcessedContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetProcessingInterval(TBHandle otbHandle, double* pProcessingInterval);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetAggregateConfigurationHandle(TBHandle otbHandle, AggregateConfigurationStruct** ppAggregateConfiguration);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetAggregateTypeHandle(TBHandle otbHandle, NodeIdStruct** ppAggregateType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadProcessedContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerHistoryReadEventContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetContextAsTimestamp(TBHandle otbHandle, DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointSetContextFromTimestamp(TBHandle otbHandle, const DateTimeStruct* pTimestamp);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetStartTimeHandle(TBHandle otbHandle, DateTimeStruct** pStartTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetEndTimeHandle(TBHandle otbHandle, DateTimeStruct** pEndTime);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetMaxNumberOfValuesPerNode(TBHandle otbHandle, OTUInt32* pMaxNumberOfValuesPerNode);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetFilter(TBHandle otbHandle, EventFilterStruct* pEventFilter, EnumStatusCode* pResult);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerHistoryReadEventContinuationPointGetTimestampsToReturn(TBHandle otbHandle, EnumTimestampsToReturn* pTimestampsToReturn);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class ServerBrowseContinuationPoint
	////////////////////////////////////////////////////////////////////////////////

	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetContextAsByteString(TBHandle otbHandle, ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointSetContextFromByteString(TBHandle otbHandle, const ByteStringStruct* pByteString);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetView(TBHandle otbHandle, ViewDescriptionStruct* pView);
	TBCORE_IF OTUInt32 OTAPI_CALL OTSServerBrowseContinuationPointGetRequestedMaxReferencesPerNode(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetNodeIdToBrowse(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetNodeToBrowse(TBHandle otbHandle, TBHandle* pNodeHandle);
	TBCORE_IF EnumBrowseDirection OTAPI_CALL OTSServerBrowseContinuationPointGetBrowseDirection(TBHandle otbHandle);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSServerBrowseContinuationPointGetReferenceTypeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF bool OTAPI_CALL OTSServerBrowseContinuationPointGetIncludeSubtypes(TBHandle otbHandle);
	TBCORE_IF EnumNodeClass OTAPI_CALL OTSServerBrowseContinuationPointGetNodeClassMask(TBHandle otbHandle);
	TBCORE_IF EnumResultMask OTAPI_CALL OTSServerBrowseContinuationPointGetResultMask(TBHandle otbHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ContentFilterResult
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultClear(ContentFilterResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterResultCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ContentFilterElementResult
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultClear(ContentFilterElementResultStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultSet(ContentFilterElementResultStruct* pTarget, const ContentFilterElementResultStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTContentFilterElementResultCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultGetStatusCode(TBHandle otbHandle, EnumStatusCode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTContentFilterElementResultSetStatusCode(TBHandle otbHandle, EnumStatusCode value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServerDiagnosticsSummaryDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeClear(ServerDiagnosticsSummaryDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServerDiagnosticsSummaryDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetServerViewCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetServerViewCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCurrentSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCurrentSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCumulatedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCumulatedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSecurityRejectedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSecurityRejectedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetRejectedSessionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetRejectedSessionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSessionTimeoutCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSessionTimeoutCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSessionAbortCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSessionAbortCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCurrentSubscriptionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCurrentSubscriptionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetCumulatedSubscriptionCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetCumulatedSubscriptionCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetPublishingIntervalCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetPublishingIntervalCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetSecurityRejectedRequestsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetSecurityRejectedRequestsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeGetRejectedRequestsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerDiagnosticsSummaryDataTypeSetRejectedRequestsCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SubscriptionDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeClear(SubscriptionDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSubscriptionDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetSubscriptionId(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetSubscriptionId(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPriority(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPriority(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishingInterval(TBHandle otbHandle, double* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishingInterval(TBHandle otbHandle, double value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxKeepAliveCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxLifetimeCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxLifetimeCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMaxNotificationsPerPublish(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishingEnabled(TBHandle otbHandle, bool* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishingEnabled(TBHandle otbHandle, bool value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetModifyCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetModifyCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEnableCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEnableCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDisableCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDisableCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishMessageRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishMessageRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetRepublishMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetRepublishMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferredToAltClientCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferredToAltClientCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetTransferredToSameClientCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetTransferredToSameClientCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetPublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetPublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDataChangeNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDataChangeNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEventNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEventNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetNotificationsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetNotificationsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetLatePublishRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetLatePublishRequestCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetCurrentKeepAliveCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetCurrentKeepAliveCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetCurrentLifetimeCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetCurrentLifetimeCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetUnacknowledgedMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetUnacknowledgedMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDiscardedMessageCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDiscardedMessageCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMonitoredItemCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMonitoredItemCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetDisabledMonitoredItemCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetDisabledMonitoredItemCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetMonitoringQueueOverflowCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetMonitoringQueueOverflowCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetNextSequenceNumber(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetNextSequenceNumber(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeGetEventQueueOverFlowCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscriptionDiagnosticsDataTypeSetEventQueueOverFlowCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SessionDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeClear(SessionDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSessionDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetSessionName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetSessionName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetServerUri(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetServerUri(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetEndpointUrl(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetEndpointUrl(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetActualSessionTimeout(TBHandle otbHandle, double* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetActualSessionTimeout(TBHandle otbHandle, double value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetMaxResponseMessageSize(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetMaxResponseMessageSize(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentSubscriptionsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentSubscriptionsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentMonitoredItemsCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentMonitoredItemsCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetCurrentPublishRequestsInQueue(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetCurrentPublishRequestsInQueue(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeGetUnauthorizedRequestCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionDiagnosticsDataTypeSetUnauthorizedRequestCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SessionSecurityDiagnosticsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeClear(SessionSecurityDiagnosticsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetClientUserIdOfSession(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetClientUserIdOfSession(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetAuthenticationMechanism(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetAuthenticationMechanism(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetEncoding(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetEncoding(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetTransportProtocol(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetTransportProtocol(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeGetSecurityPolicyUri(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSessionSecurityDiagnosticsDataTypeSetSecurityPolicyUri(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServiceCounterDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeClear(ServiceCounterDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServiceCounterDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeGetTotalCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSetTotalCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeGetErrorCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServiceCounterDataTypeSetErrorCount(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SemanticChangeStructureDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeClear(SemanticChangeStructureDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSemanticChangeStructureDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSemanticChangeStructureDataTypeCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ModelChangeStructureDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeClear(ModelChangeStructureDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTModelChangeStructureDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeGetVerb(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTModelChangeStructureDataTypeSetVerb(TBHandle otbHandle, OTUInt8 value);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateConfiguration (DataType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationClear(AggregateConfigurationStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTAggregateConfigurationCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetUseServerCapabilitiesDefaults(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetUseServerCapabilitiesDefaults(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetTreatUncertainAsBad(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetTreatUncertainAsBad(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetPercentDataBad(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetPercentDataBad(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetPercentDataGood(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetPercentDataGood(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationGetUseSlopedExtrapolation(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTAggregateConfigurationSetUseSlopedExtrapolation(TBHandle otbHandle, OTBoolean value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateConfiguration (ObjectType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSAggregateConfiguration_Internal_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct HistoricalDataConfiguration
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSHistoricalDataConfiguration_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSHistoricalDataConfigurationGetAggregateConfiguration(TBHandle otbHandle, TBHandle* pAggregateConfigurationHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ReadProcessedDetails
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsClear(ReadProcessedDetailsStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTReadProcessedDetailsCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsGetProcessingInterval(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReadProcessedDetailsSetProcessingInterval(TBHandle otbHandle, OTDouble value);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SignedSoftwareCertificate
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateClear(SignedSoftwareCertificateStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSignedSoftwareCertificateCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTSignedSoftwareCertificateCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct BuildInfo
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoClear(BuildInfoStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTBuildInfoCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetProductUri(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetProductUri(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetManufacturerName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetManufacturerName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetProductName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetProductName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetSoftwareVersion(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetSoftwareVersion(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoGetBuildNumber(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBuildInfoSetBuildNumber(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ServerStatusDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeClear(ServerStatusDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTServerStatusDataTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeGetState(TBHandle otbHandle, EnumServerState* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSetState(TBHandle otbHandle, EnumServerState value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeGetSecondsTillShutdown(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTServerStatusDataTypeSetSecondsTillShutdown(TBHandle otbHandle, OTUInt32 value);

#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct AggregateFunction
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTSAggregateFunction_Internal_Construct(TBHandle apiHandle, bool addRef);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class StringTable
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTBStringTable_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableAppendEntry(TBHandle otbHandle, const OTChar* pEntry, OTInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetEntry(TBHandle otbHandle, OTInt32 index, OTChar** ppEntry);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetIndex(TBHandle otbHandle, const OTChar* pEntry, OTInt32* pIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableRemoveLastEntry(TBHandle otbHandle, OTInt32 lastEntryIndex);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetSize(TBHandle otbHandle, OTUInt32* pSize);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTBStringTableGetContent(TBHandle otbHandle, OTUInt32* pSize, OTChar*** ppStrings);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DiagnosticInfo (DataType)
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoInitialize(DiagnosticInfoStruct* pDiagnosticInfo);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoClear(DiagnosticInfoStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSet(DiagnosticInfoStruct* pTarget, const DiagnosticInfoStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTDiagnosticInfoCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetNamespaceUri(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, OTChar** ppNamespaceUri);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetNamespaceUri(DiagnosticInfoStruct* pDiagnosticInfo, const OTChar* pNamespaceUri, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetSymbolicId(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, OTChar** ppSymbolicId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetSymbolicId(DiagnosticInfoStruct* pDiagnosticInfo, const OTChar* pSymbolicId, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetLocale(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, OTChar** ppLocale);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetLocale(DiagnosticInfoStruct* pDiagnosticInfo, const OTChar* pLocale, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoGetLocalizedText(const DiagnosticInfoStruct* pDiagnosticInfo, TBHandle stringTable, OTChar** ppLocalizedText);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetLocalizedText(DiagnosticInfoStruct* pDiagnosticInfo, const OTChar* pLocalizedText, TBHandle stringTable);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDiagnosticInfoSetInnerDiagnosticInfo(DiagnosticInfoStruct* pDiagnosticInfo, const DiagnosticInfoStruct* pInnerDiagnosticInfo);
	TBCORE_IF OTChar* OTAPI_CALL OTDiagnosticInfoToString(const void* pTarget, TBHandle stringTable);

#if TB5_ALARMS
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class OTContentFilterEvaluator
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSEventFilterEvaluatorEvaluate(const ContentFilterStruct* pContentFilter, void* pApiContentFilterTargetHandle, bool* pFilterAccepted);
#endif


#if TB5_HISTORY
	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryEventFieldList
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListClear(HistoryEventFieldListStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventFieldListCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryEventFieldListCompare(const void* pSource, const void* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class HistoryEvent
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventClear(HistoryEventStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTHistoryEventCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTHistoryEventCompare(const void* pSource, const void* pTarget);
#endif

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class EnumValueType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeClear(EnumValueTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeSet(void* pTarget, const void* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeCopy(const void* pSource, void** pTarget);
	TBCORE_IF int OTAPI_CALL OTEnumValueTypeCompare(const void* pSource, const void* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeGetValue(TBHandle otbHandle, OTInt64* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumValueTypeSetValue(TBHandle otbHandle, OTInt64 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of class KeyValuePairStruct
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTKeyValuePairClear(KeyValuePairStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTKeyValuePairSet(KeyValuePairStruct* pTarget, const KeyValuePairStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTKeyValuePairCopy(const KeyValuePairStruct* pSource, KeyValuePairStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTKeyValuePairCompare(const KeyValuePairStruct* pSource, const KeyValuePairStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class DataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDescriptionType(TBHandle otbHandle, EnumDataTypeDescriptionType* pDescriptionType);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetName(TBHandle otbHandle, OTChar** pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetName(TBHandle otbHandle, const OTChar* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDocumentation(TBHandle otbHandle, OTChar** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetDocumentation(TBHandle otbHandle, const OTChar* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, OTChar*** pAttributeNames, OTUInt32 *pAttributeValuesCount, OTChar*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const OTChar** pAttributeNames, OTUInt32 attributeValuesCount, const OTChar** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetCustomAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, OTChar*** pAttributeNames, OTUInt32 *pAttributeValuesCount, OTChar*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetCustomAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const OTChar** pAttributeNames, OTUInt32 attributeValuesCount, const OTChar** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetVersion(TBHandle otbHandle, OTChar** pVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSetVersion(TBHandle otbHandle, const OTChar* pVersion);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetDataTypeNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionGetEncodingNodeId(TBHandle otbHandle, NodeIdStruct* pNodeId);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class StructuredDataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTStructuredDataTypeDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructuredDataTypeDescriptionGetFields(TBHandle otbHandle, OTUInt32* pRetCount, TBHandle** pReturn);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructuredDataTypeDescriptionSetFields(TBHandle otbHandle, OTUInt32 fieldCount, TBHandle* pFields);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class EnumerationDataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTEnumerationDataTypeDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionGetEnumeratedValues(TBHandle otbHandle, OTUInt32* pValueCount, TBHandle** ppEnumeratedValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionSetEnumeratedValues(TBHandle otbHandle, OTUInt32 valueCount, TBHandle* pEnumeratedValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionIsEnumValue(TBHandle otbHandle, OTInt32 integerRepresentation, bool* pIsEnumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumerationDataTypeDescriptionGetEnumeratedValue(TBHandle otbHandle, OTInt32 integerRepresentation, TBHandle* pEnumeratedValueDescriptionHandle);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class FieldDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTFieldDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetName(TBHandle otbHandle, OTChar** ppName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetName(TBHandle otbHandle, const OTChar* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetLength(TBHandle otbHandle, OTUInt32* pLength);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetLength(TBHandle otbHandle, OTUInt32 length);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetDocumentation(TBHandle otbHandle, OTChar** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetDocumentation(TBHandle otbHandle, const OTChar* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, OTChar*** pAttributeNames, OTUInt32 *pAttributeValuesCount, OTChar*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const OTChar** pAttributeNames, OTUInt32 attributeValuesCount, const OTChar** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetCustomAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, OTChar*** pAttributeNames, OTUInt32 *pAttributeValuesCount, OTChar*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetCustomAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const OTChar** pAttributeNames, OTUInt32 attributeValuesCount, const OTChar** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionGetTypeId(TBHandle otbHandle, NodeIdStruct* pNodeId);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldDescriptionSetTypeId(TBHandle otbHandle, const NodeIdStruct* pNodeId);


	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class EnumeratedValueDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTEnumeratedValueDescription_Internal_Construct(TBHandle apiHandle, bool addRef);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetName(TBHandle otbHandle, OTChar** ppName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetName(TBHandle otbHandle, const OTChar* pName);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetValue(TBHandle otbHandle, OTInt32* pEnumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetValue(TBHandle otbHandle, OTInt32 enumValue);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetDocumentation(TBHandle otbHandle, OTChar** ppDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetDocumentation(TBHandle otbHandle, const OTChar* pDocumentation);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionGetDocumentationAttributes(TBHandle otbHandle, OTUInt32 *pAttributeNamesCount, OTChar*** pAttributeNames, OTUInt32 *pAttributeValuesCount, OTChar*** pAttributeValues);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumeratedValueDescriptionSetDocumentationAttributes(TBHandle otbHandle, OTUInt32 attributeNamesCount, const OTChar** pAttributeNames, OTUInt32 attributeValuesCount, const OTChar** pAttributeValues);

	////////////////////////////////////////////////////////////////////////////////
	// C-Wrapper implementation of class Dictionary
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF void* OTAPI_CALL OTDictionary_Construct(TBHandle apiHandle, bool addRef);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ConfigurationVersionDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeClear(ConfigurationVersionDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeSet(ConfigurationVersionDataTypeStruct* pTarget, const ConfigurationVersionDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeCopy(const ConfigurationVersionDataTypeStruct* pSource, ConfigurationVersionDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTConfigurationVersionDataTypeCompare(const ConfigurationVersionDataTypeStruct* pSource, const ConfigurationVersionDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeGetMajorVersion(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeSetMajorVersion(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeGetMinorVersion(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConfigurationVersionDataTypeSetMinorVersion(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DatagramConnectionTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramConnectionTransportDataTypeClear(DatagramConnectionTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramConnectionTransportDataTypeSet(DatagramConnectionTransportDataTypeStruct* pTarget, const DatagramConnectionTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramConnectionTransportDataTypeCopy(const DatagramConnectionTransportDataTypeStruct* pSource, DatagramConnectionTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDatagramConnectionTransportDataTypeCompare(const DatagramConnectionTransportDataTypeStruct* pSource, const DatagramConnectionTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct NetworkAddressDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressDataTypeClear(NetworkAddressDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressDataTypeSet(NetworkAddressDataTypeStruct* pTarget, const NetworkAddressDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressDataTypeCopy(const NetworkAddressDataTypeStruct* pSource, NetworkAddressDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTNetworkAddressDataTypeCompare(const NetworkAddressDataTypeStruct* pSource, const NetworkAddressDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressDataTypeGetNetworkInterface(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressDataTypeSetNetworkInterface(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DatagramWriterGroupTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeClear(DatagramWriterGroupTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeSet(DatagramWriterGroupTransportDataTypeStruct* pTarget, const DatagramWriterGroupTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeCopy(const DatagramWriterGroupTransportDataTypeStruct* pSource, DatagramWriterGroupTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDatagramWriterGroupTransportDataTypeCompare(const DatagramWriterGroupTransportDataTypeStruct* pSource, const DatagramWriterGroupTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeGetMessageRepeatCount(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeSetMessageRepeatCount(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeGetMessageRepeatDelay(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDatagramWriterGroupTransportDataTypeSetMessageRepeatDelay(TBHandle otbHandle, OTDouble value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetMetaDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetMetaDataTypeClear(DataSetMetaDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetMetaDataTypeSet(DataSetMetaDataTypeStruct* pTarget, const DataSetMetaDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetMetaDataTypeCopy(const DataSetMetaDataTypeStruct* pSource, DataSetMetaDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetMetaDataTypeCompare(const DataSetMetaDataTypeStruct* pSource, const DataSetMetaDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetMetaDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetMetaDataTypeSetName(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetReaderDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeClear(DataSetReaderDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSet(DataSetReaderDataTypeStruct* pTarget, const DataSetReaderDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeCopy(const DataSetReaderDataTypeStruct* pSource, DataSetReaderDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetReaderDataTypeCompare(const DataSetReaderDataTypeStruct* pSource, const DataSetReaderDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetWriterGroupId(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetWriterGroupId(TBHandle otbHandle, OTUInt16 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetDataSetWriterId(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetDataSetWriterId(TBHandle otbHandle, OTUInt16 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetDataSetFieldContentMask(TBHandle otbHandle, EnumDataSetFieldContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetDataSetFieldContentMask(TBHandle otbHandle, EnumDataSetFieldContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetMessageReceiveTimeout(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetMessageReceiveTimeout(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeGetSecurityGroupId(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderDataTypeSetSecurityGroupId(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetWriterDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeClear(DataSetWriterDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSet(DataSetWriterDataTypeStruct* pTarget, const DataSetWriterDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeCopy(const DataSetWriterDataTypeStruct* pSource, DataSetWriterDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetWriterDataTypeCompare(const DataSetWriterDataTypeStruct* pSource, const DataSetWriterDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetDataSetWriterId(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetDataSetWriterId(TBHandle otbHandle, OTUInt16 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetDataSetFieldContentMask(TBHandle otbHandle, EnumDataSetFieldContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetDataSetFieldContentMask(TBHandle otbHandle, EnumDataSetFieldContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetKeyFrameCount(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetKeyFrameCount(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeGetDataSetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterDataTypeSetDataSetName(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionClear(DataTypeDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionSet(DataTypeDescriptionStruct* pTarget, const DataTypeDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeDescriptionCopy(const DataTypeDescriptionStruct* pSource, DataTypeDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataTypeDescriptionCompare(const DataTypeDescriptionStruct* pSource, const DataTypeDescriptionStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataTypeSchemaHeader
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeSchemaHeaderClear(DataTypeSchemaHeaderStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeSchemaHeaderSet(DataTypeSchemaHeaderStruct* pTarget, const DataTypeSchemaHeaderStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataTypeSchemaHeaderCopy(const DataTypeSchemaHeaderStruct* pSource, DataTypeSchemaHeaderStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataTypeSchemaHeaderCompare(const DataTypeSchemaHeaderStruct* pSource, const DataTypeSchemaHeaderStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct EnumDefinition
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDefinitionClear(EnumDefinitionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDefinitionSet(EnumDefinitionStruct* pTarget, const EnumDefinitionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDefinitionCopy(const EnumDefinitionStruct* pSource, EnumDefinitionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTEnumDefinitionCompare(const EnumDefinitionStruct* pSource, const EnumDefinitionStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct EnumDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDescriptionClear(EnumDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDescriptionSet(EnumDescriptionStruct* pTarget, const EnumDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDescriptionCopy(const EnumDescriptionStruct* pSource, EnumDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTEnumDescriptionCompare(const EnumDescriptionStruct* pSource, const EnumDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDescriptionGetBuiltInType(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumDescriptionSetBuiltInType(TBHandle otbHandle, OTUInt8 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct EnumField
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldClear(EnumFieldStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldSet(EnumFieldStruct* pTarget, const EnumFieldStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldCopy(const EnumFieldStruct* pSource, EnumFieldStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTEnumFieldCompare(const EnumFieldStruct* pSource, const EnumFieldStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldGetValue(TBHandle otbHandle, OTInt64* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTEnumFieldSetValue(TBHandle otbHandle, OTInt64 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct FieldMetaData
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataClear(FieldMetaDataStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSet(FieldMetaDataStruct* pTarget, const FieldMetaDataStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataCopy(const FieldMetaDataStruct* pSource, FieldMetaDataStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTFieldMetaDataCompare(const FieldMetaDataStruct* pSource, const FieldMetaDataStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataGetFieldFlags(TBHandle otbHandle, EnumDataSetFieldFlags* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSetFieldFlags(TBHandle otbHandle, EnumDataSetFieldFlags value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataGetBuiltInType(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSetBuiltInType(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataGetValueRank(TBHandle otbHandle, OTInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSetValueRank(TBHandle otbHandle, OTInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataGetMaxStringLength(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldMetaDataSetMaxStringLength(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct FieldTargetDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldTargetDataTypeClear(FieldTargetDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldTargetDataTypeSet(FieldTargetDataTypeStruct* pTarget, const FieldTargetDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTFieldTargetDataTypeCopy(const FieldTargetDataTypeStruct* pSource, FieldTargetDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTFieldTargetDataTypeCompare(const FieldTargetDataTypeStruct* pSource, const FieldTargetDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct NetworkAddressUrlDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeClear(NetworkAddressUrlDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeSet(NetworkAddressUrlDataTypeStruct* pTarget, const NetworkAddressUrlDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeCopy(const NetworkAddressUrlDataTypeStruct* pSource, NetworkAddressUrlDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTNetworkAddressUrlDataTypeCompare(const NetworkAddressUrlDataTypeStruct* pSource, const NetworkAddressUrlDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeGetUrl(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeSetUrl(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeGetNetworkInterface(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTNetworkAddressUrlDataTypeSetNetworkInterface(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PublishedDataItemsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataItemsDataTypeClear(PublishedDataItemsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataItemsDataTypeSet(PublishedDataItemsDataTypeStruct* pTarget, const PublishedDataItemsDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataItemsDataTypeCopy(const PublishedDataItemsDataTypeStruct* pSource, PublishedDataItemsDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPublishedDataItemsDataTypeCompare(const PublishedDataItemsDataTypeStruct* pSource, const PublishedDataItemsDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PublishedDataSetDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetDataTypeClear(PublishedDataSetDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetDataTypeSet(PublishedDataSetDataTypeStruct* pTarget, const PublishedDataSetDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetDataTypeCopy(const PublishedDataSetDataTypeStruct* pSource, PublishedDataSetDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPublishedDataSetDataTypeCompare(const PublishedDataSetDataTypeStruct* pSource, const PublishedDataSetDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetDataTypeSetName(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PublishedEventsDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedEventsDataTypeClear(PublishedEventsDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedEventsDataTypeSet(PublishedEventsDataTypeStruct* pTarget, const PublishedEventsDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedEventsDataTypeCopy(const PublishedEventsDataTypeStruct* pSource, PublishedEventsDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPublishedEventsDataTypeCompare(const PublishedEventsDataTypeStruct* pSource, const PublishedEventsDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PublishedVariableDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeClear(PublishedVariableDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeSet(PublishedVariableDataTypeStruct* pTarget, const PublishedVariableDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeCopy(const PublishedVariableDataTypeStruct* pSource, PublishedVariableDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPublishedVariableDataTypeCompare(const PublishedVariableDataTypeStruct* pSource, const PublishedVariableDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeGetAttributeId(TBHandle otbHandle, EnumAttributeId* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeSetAttributeId(TBHandle otbHandle, EnumAttributeId value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeGetSamplingIntervalHint(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeSetSamplingIntervalHint(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeGetDeadbandType(TBHandle otbHandle, EnumDeadbandType* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeSetDeadbandType(TBHandle otbHandle, EnumDeadbandType value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeGetDeadbandValue(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedVariableDataTypeSetDeadbandValue(TBHandle otbHandle, OTDouble value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PubSubConfigurationDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConfigurationDataTypeClear(PubSubConfigurationDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConfigurationDataTypeSet(PubSubConfigurationDataTypeStruct* pTarget, const PubSubConfigurationDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConfigurationDataTypeCopy(const PubSubConfigurationDataTypeStruct* pSource, PubSubConfigurationDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPubSubConfigurationDataTypeCompare(const PubSubConfigurationDataTypeStruct* pSource, const PubSubConfigurationDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConfigurationDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConfigurationDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PubSubConnectionDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeClear(PubSubConnectionDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeSet(PubSubConnectionDataTypeStruct* pTarget, const PubSubConnectionDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeCopy(const PubSubConnectionDataTypeStruct* pSource, PubSubConnectionDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPubSubConnectionDataTypeCompare(const PubSubConnectionDataTypeStruct* pSource, const PubSubConnectionDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeGetTransportProfileUri(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubConnectionDataTypeSetTransportProfileUri(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PubSubGroupDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeClear(PubSubGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSet(PubSubGroupDataTypeStruct* pTarget, const PubSubGroupDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeCopy(const PubSubGroupDataTypeStruct* pSource, PubSubGroupDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPubSubGroupDataTypeCompare(const PubSubGroupDataTypeStruct* pSource, const PubSubGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeGetSecurityGroupId(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSetSecurityGroupId(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeGetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPubSubGroupDataTypeSetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ReaderGroupDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeClear(ReaderGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSet(ReaderGroupDataTypeStruct* pTarget, const ReaderGroupDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeCopy(const ReaderGroupDataTypeStruct* pSource, ReaderGroupDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTReaderGroupDataTypeCompare(const ReaderGroupDataTypeStruct* pSource, const ReaderGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeGetSecurityGroupId(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSetSecurityGroupId(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeGetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupDataTypeSetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct RolePermissionTypeStruct
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRolePermissionTypeClear(RolePermissionTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRolePermissionTypeSet(RolePermissionTypeStruct* pTarget, const RolePermissionTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRolePermissionTypeCopy(const RolePermissionTypeStruct* pSource, RolePermissionTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTRolePermissionTypeCompare(const RolePermissionTypeStruct* pSource, const RolePermissionTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRolePermissionTypeGetPermissions(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTRolePermissionTypeSetPermissions(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SimpleTypeDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleTypeDescriptionClear(SimpleTypeDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleTypeDescriptionSet(SimpleTypeDescriptionStruct* pTarget, const SimpleTypeDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleTypeDescriptionCopy(const SimpleTypeDescriptionStruct* pSource, SimpleTypeDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTSimpleTypeDescriptionCompare(const SimpleTypeDescriptionStruct* pSource, const SimpleTypeDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleTypeDescriptionGetBuiltInType(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSimpleTypeDescriptionSetBuiltInType(TBHandle otbHandle, OTUInt8 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct StructureDefinition
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDefinitionClear(StructureDefinitionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDefinitionSet(StructureDefinitionStruct* pTarget, const StructureDefinitionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDefinitionCopy(const StructureDefinitionStruct* pSource, StructureDefinitionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTStructureDefinitionCompare(const StructureDefinitionStruct* pSource, const StructureDefinitionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDefinitionGetStructureType(TBHandle otbHandle, EnumStructureType* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDefinitionSetStructureType(TBHandle otbHandle, EnumStructureType value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct StructureDescription
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDescriptionClear(StructureDescriptionStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDescriptionSet(StructureDescriptionStruct* pTarget, const StructureDescriptionStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureDescriptionCopy(const StructureDescriptionStruct* pSource, StructureDescriptionStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTStructureDescriptionCompare(const StructureDescriptionStruct* pSource, const StructureDescriptionStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct StructureField
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldClear(StructureFieldStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldSet(StructureFieldStruct* pTarget, const StructureFieldStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldCopy(const StructureFieldStruct* pSource, StructureFieldStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTStructureFieldCompare(const StructureFieldStruct* pSource, const StructureFieldStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldGetValueRank(TBHandle otbHandle, OTInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldSetValueRank(TBHandle otbHandle, OTInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldGetMaxStringLength(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldSetMaxStringLength(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldGetIsOptional(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTStructureFieldSetIsOptional(TBHandle otbHandle, OTBoolean value);


	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SubscribedDataSetMirrorDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetMirrorDataTypeClear(SubscribedDataSetMirrorDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetMirrorDataTypeSet(SubscribedDataSetMirrorDataTypeStruct* pTarget, const SubscribedDataSetMirrorDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetMirrorDataTypeCopy(const SubscribedDataSetMirrorDataTypeStruct* pSource, SubscribedDataSetMirrorDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTSubscribedDataSetMirrorDataTypeCompare(const SubscribedDataSetMirrorDataTypeStruct* pSource, const SubscribedDataSetMirrorDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetMirrorDataTypeGetParentNodeName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetMirrorDataTypeSetParentNodeName(TBHandle otbHandle, const OTChar* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct TargetVariablesDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTargetVariablesDataTypeClear(TargetVariablesDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTargetVariablesDataTypeSet(TargetVariablesDataTypeStruct* pTarget, const TargetVariablesDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTTargetVariablesDataTypeCopy(const TargetVariablesDataTypeStruct* pSource, TargetVariablesDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTTargetVariablesDataTypeCompare(const TargetVariablesDataTypeStruct* pSource, const TargetVariablesDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct UadpDataSetReaderMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeClear(UadpDataSetReaderMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSet(UadpDataSetReaderMessageDataTypeStruct* pTarget, const UadpDataSetReaderMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeCopy(const UadpDataSetReaderMessageDataTypeStruct* pSource, UadpDataSetReaderMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUadpDataSetReaderMessageDataTypeCompare(const UadpDataSetReaderMessageDataTypeStruct* pSource, const UadpDataSetReaderMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetGroupVersion(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetGroupVersion(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetNetworkMessageNumber(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetDataSetOffset(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetNetworkMessageContentMask(TBHandle otbHandle, EnumUadpNetworkMessageContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetNetworkMessageContentMask(TBHandle otbHandle, EnumUadpNetworkMessageContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetDataSetMessageContentMask(TBHandle otbHandle, EnumUadpDataSetMessageContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetDataSetMessageContentMask(TBHandle otbHandle, EnumUadpDataSetMessageContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetPublishingInterval(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetPublishingInterval(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetReceiveOffset(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetReceiveOffset(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeGetProcessingOffset(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetReaderMessageDataTypeSetProcessingOffset(TBHandle otbHandle, OTDouble value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct UadpDataSetWriterMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeClear(UadpDataSetWriterMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeSet(UadpDataSetWriterMessageDataTypeStruct* pTarget, const UadpDataSetWriterMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeCopy(const UadpDataSetWriterMessageDataTypeStruct* pSource, UadpDataSetWriterMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUadpDataSetWriterMessageDataTypeCompare(const UadpDataSetWriterMessageDataTypeStruct* pSource, const UadpDataSetWriterMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeGetDataSetMessageContentMask(TBHandle otbHandle, EnumUadpDataSetMessageContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeSetDataSetMessageContentMask(TBHandle otbHandle, EnumUadpDataSetMessageContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeGetConfiguredSize(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeSetConfiguredSize(TBHandle otbHandle, OTUInt16 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeGetNetworkMessageNumber(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpDataSetWriterMessageDataTypeGetDataSetOffset(TBHandle otbHandle, OTUInt16* value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct UadpWriterGroupMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeClear(UadpWriterGroupMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeSet(UadpWriterGroupMessageDataTypeStruct* pTarget, const UadpWriterGroupMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeCopy(const UadpWriterGroupMessageDataTypeStruct* pSource, UadpWriterGroupMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTUadpWriterGroupMessageDataTypeCompare(const UadpWriterGroupMessageDataTypeStruct* pSource, const UadpWriterGroupMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeGetGroupVersion(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeSetGroupVersion(TBHandle otbHandle, OTUInt32 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeGetDataSetOrdering(TBHandle otbHandle, EnumDataSetOrderingType* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeSetDataSetOrdering(TBHandle otbHandle, EnumDataSetOrderingType value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeGetNetworkMessageContentMask(TBHandle otbHandle, EnumUadpNetworkMessageContentMask* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeSetNetworkMessageContentMask(TBHandle otbHandle, EnumUadpNetworkMessageContentMask value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeGetSamplingOffset(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTUadpWriterGroupMessageDataTypeSetSamplingOffset(TBHandle otbHandle, OTDouble value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct WriterGroupDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeClear(WriterGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSet(WriterGroupDataTypeStruct* pTarget, const WriterGroupDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeCopy(const WriterGroupDataTypeStruct* pSource, WriterGroupDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTWriterGroupDataTypeCompare(const WriterGroupDataTypeStruct* pSource, const WriterGroupDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetWriterGroupId(TBHandle otbHandle, OTUInt16* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetWriterGroupId(TBHandle otbHandle, OTUInt16 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetPublishingInterval(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetPublishingInterval(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetKeepAliveTime(TBHandle otbHandle, OTDouble* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetKeepAliveTime(TBHandle otbHandle, OTDouble value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetPriority(TBHandle otbHandle, OTUInt8* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetPriority(TBHandle otbHandle, OTUInt8 value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetName(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetName(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetEnabled(TBHandle otbHandle, OTBoolean* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetEnabled(TBHandle otbHandle, OTBoolean value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetSecurityGroupId(TBHandle otbHandle, OTChar** value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetSecurityGroupId(TBHandle otbHandle, const OTChar* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeGetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32* value);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupDataTypeSetMaxNetworkMessageSize(TBHandle otbHandle, OTUInt32 value);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetReaderTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderTransportDataTypeClear(DataSetReaderTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderTransportDataTypeSet(DataSetReaderTransportDataTypeStruct* pTarget, const DataSetReaderTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderTransportDataTypeCopy(const DataSetReaderTransportDataTypeStruct* pSource, DataSetReaderTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetReaderTransportDataTypeCompare(const DataSetReaderTransportDataTypeStruct* pSource, const DataSetReaderTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct PublishedDataSetSourceDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetSourceDataTypeClear(PublishedDataSetSourceDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetSourceDataTypeSet(PublishedDataSetSourceDataTypeStruct* pTarget, const PublishedDataSetSourceDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTPublishedDataSetSourceDataTypeCopy(const PublishedDataSetSourceDataTypeStruct* pSource, PublishedDataSetSourceDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTPublishedDataSetSourceDataTypeCompare(const PublishedDataSetSourceDataTypeStruct* pSource, const PublishedDataSetSourceDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct WriterGroupTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupTransportDataTypeClear(WriterGroupTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupTransportDataTypeSet(WriterGroupTransportDataTypeStruct* pTarget, const WriterGroupTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupTransportDataTypeCopy(const WriterGroupTransportDataTypeStruct* pSource, WriterGroupTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTWriterGroupTransportDataTypeCompare(const WriterGroupTransportDataTypeStruct* pSource, const WriterGroupTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetWriterTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterTransportDataTypeClear(DataSetWriterTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterTransportDataTypeSet(DataSetWriterTransportDataTypeStruct* pTarget, const DataSetWriterTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterTransportDataTypeCopy(const DataSetWriterTransportDataTypeStruct* pSource, DataSetWriterTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetWriterTransportDataTypeCompare(const DataSetWriterTransportDataTypeStruct* pSource, const DataSetWriterTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetWriterMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterMessageDataTypeClear(DataSetWriterMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterMessageDataTypeSet(DataSetWriterMessageDataTypeStruct* pTarget, const DataSetWriterMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetWriterMessageDataTypeCopy(const DataSetWriterMessageDataTypeStruct* pSource, DataSetWriterMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetWriterMessageDataTypeCompare(const DataSetWriterMessageDataTypeStruct* pSource, const DataSetWriterMessageDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct WriterGroupMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupMessageDataTypeClear(WriterGroupMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupMessageDataTypeSet(WriterGroupMessageDataTypeStruct* pTarget, const WriterGroupMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTWriterGroupMessageDataTypeCopy(const WriterGroupMessageDataTypeStruct* pSource, WriterGroupMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTWriterGroupMessageDataTypeCompare(const WriterGroupMessageDataTypeStruct* pSource, const WriterGroupMessageDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ConnectionTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConnectionTransportDataTypeClear(ConnectionTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConnectionTransportDataTypeSet(ConnectionTransportDataTypeStruct* pTarget, const ConnectionTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTConnectionTransportDataTypeCopy(const ConnectionTransportDataTypeStruct* pSource, ConnectionTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTConnectionTransportDataTypeCompare(const ConnectionTransportDataTypeStruct* pSource, const ConnectionTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ReaderGroupTransportDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupTransportDataTypeClear(ReaderGroupTransportDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupTransportDataTypeSet(ReaderGroupTransportDataTypeStruct* pTarget, const ReaderGroupTransportDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupTransportDataTypeCopy(const ReaderGroupTransportDataTypeStruct* pSource, ReaderGroupTransportDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTReaderGroupTransportDataTypeCompare(const ReaderGroupTransportDataTypeStruct* pSource, const ReaderGroupTransportDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct ReaderGroupMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupMessageDataTypeClear(ReaderGroupMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupMessageDataTypeSet(ReaderGroupMessageDataTypeStruct* pTarget, const ReaderGroupMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTReaderGroupMessageDataTypeCopy(const ReaderGroupMessageDataTypeStruct* pSource, ReaderGroupMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTReaderGroupMessageDataTypeCompare(const ReaderGroupMessageDataTypeStruct* pSource, const ReaderGroupMessageDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct DataSetReaderMessageDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderMessageDataTypeClear(DataSetReaderMessageDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderMessageDataTypeSet(DataSetReaderMessageDataTypeStruct* pTarget, const DataSetReaderMessageDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTDataSetReaderMessageDataTypeCopy(const DataSetReaderMessageDataTypeStruct* pSource, DataSetReaderMessageDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTDataSetReaderMessageDataTypeCompare(const DataSetReaderMessageDataTypeStruct* pSource, const DataSetReaderMessageDataTypeStruct* pTarget);

	////////////////////////////////////////////////////////////////////////////////
	// C- Wrapper implementation of struct SubscribedDataSetDataType
	////////////////////////////////////////////////////////////////////////////////
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetDataTypeClear(SubscribedDataSetDataTypeStruct* pTarget);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetDataTypeSet(SubscribedDataSetDataTypeStruct* pTarget, const SubscribedDataSetDataTypeStruct* pSource);
	TBCORE_IF EnumStatusCode OTAPI_CALL OTSubscribedDataSetDataTypeCopy(const SubscribedDataSetDataTypeStruct* pSource, SubscribedDataSetDataTypeStruct** pTarget);
	TBCORE_IF int OTAPI_CALL OTSubscribedDataSetDataTypeCompare(const SubscribedDataSetDataTypeStruct* pSource, const SubscribedDataSetDataTypeStruct* pTarget);


#ifdef COMPILE_FOR_UNITTESTS
		// UnitTest helper functions to precreate singletons
		TBCORE_IF void OTAPI_CALL OTBPrecreateScheduler();
#endif

		TBCORE_IF void* OTAPI_CALL OTPConnection_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetName(TBHandle apiHandle, const OTChar* connectionName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetName(TBHandle apiHandle, OTChar** pConnectionName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetPublisherId(TBHandle apiHandle, const ValueStruct* publisherId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetPublisherId(TBHandle apiHandle, ValueStruct* publisherId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetEnabled(TBHandle apiHandle, bool enabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetEnabled(TBHandle apiHandle, bool* pEnabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetPubSubState(TBHandle apiHandle, EnumPubSubState *pState);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetTransportProfileUri(TBHandle apiHandle, const OTChar* transportProfileUri);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetTransportProfileUri(TBHandle apiHandle, OTChar* *ppTransportProfileUri);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetAddress(TBHandle apiHandle, const NetworkAddressDataTypeStruct* networkAddress);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetAddress(TBHandle apiHandle, NetworkAddressDataTypeStruct* networkAddress);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetTransportSettings(TBHandle apiHandle, const ConnectionTransportDataTypeStruct* transportSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetTransportSettings(TBHandle apiHandle, ConnectionTransportDataTypeStruct* transportSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionSetProperties(TBHandle apiHandle, size_t connectionPropertiesCount, KeyValuePairStruct **ppConnectionProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetProperties(TBHandle apiHandle, size_t *pConnectionPropertiesCount, KeyValuePairStruct **ppConnectionProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionAddWriterGroup(TBHandle apiHandle, TBHandle apiHandleGroup);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionRemoveWriterGroup(TBHandle apiHandle, TBHandle apiHandleGroup);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetWriterGroups(TBHandle apiHandle, size_t *pGroupCount, TBHandle **apiHandelGroup);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionAddReaderGroup(TBHandle apiHandle, TBHandle apiHandleGroup);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionRemoveReaderGroup(TBHandle apiHandle, TBHandle apiHandleGroup);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPConnectionGetReaderGroups(TBHandle apiHandle, size_t *pGroupCount, TBHandle **apiHandelGroup);

		TBCORE_IF void* OTAPI_CALL OTPWriter_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetName(TBHandle apiHandle, const OTChar* name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetName(TBHandle apiHandle, OTChar **name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetEnabled(TBHandle apiHandle, bool enabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetEnabled(TBHandle apiHandle, bool *pEnabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetPubSubState(TBHandle apiHandle, EnumPubSubState *pState);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetId(TBHandle apiHandle, OTUInt16 dataSetWriterId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetId(TBHandle apiHandle, OTUInt16 *dataSetWriterId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetDataSetFieldContentMask(TBHandle apiHandle, OTUInt32 dataSetFieldContentMask);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetDataSetFieldContentMask(TBHandle apiHandle, OTUInt32 *dataSetFieldContentMask);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetKeyFrameCount(TBHandle apiHandle, OTUInt32 keyFrameCount);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetKeyFrameCount(TBHandle apiHandle, OTUInt32 *keyFrameCount);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetDataSet(TBHandle apiHandle, TBHandle* dataSet);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetDataSet(TBHandle apiHandle, TBHandle dataSet);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetProperties(TBHandle apiHandle, size_t pPropertiesCount, KeyValuePairStruct **ppProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetProperties(TBHandle apiHandle, size_t *propertiesCount, KeyValuePairStruct **ppProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterSetMessageSettings(TBHandle apiHandle, const DataSetWriterMessageDataTypeStruct *pMessageSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGetMessageSettings(TBHandle apiHandle, DataSetWriterMessageDataTypeStruct *pMessageSettings);

		TBCORE_IF void* OTAPI_CALL OTPWriterGroup_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetWriterGroupId(TBHandle apiHandle, OTUInt16* groupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetWriterGroupId(TBHandle apiHandle, OTUInt16 _groupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetPublishingInterval(TBHandle apiHandle, OTDouble* publishingInterval);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetPublishingInterval(TBHandle apiHandle, OTDouble _publishingInterval);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetKeepAliveTime(TBHandle apiHandle, OTDouble* keepAliveTime);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetKeepAliveTime(TBHandle apiHandle, OTDouble _keepAliveTime);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetPriority(TBHandle apiHandle, OTUInt8* priority);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetPriority(TBHandle apiHandle, OTUInt8 _priority);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetLocaleIds(TBHandle apiHandle, size_t *pLocaleCount, OTChar*** pppLocales);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetLocaleIds(TBHandle apiHandle, size_t localeCount,  OTChar*const* locales);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupAddDataSetWriter(TBHandle apiHandle, TBHandle apiHandleDataSetWriter);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupRemoveDataSetWriter(TBHandle apiHandle, TBHandle apiHandleDataSetWriter);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetDataSetWriters(TBHandle apiHandle, size_t *pDataSetWriterCount, TBHandle **apiHandelDataSetWriter);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetMessageSettings(TBHandle apiHandle, const WriterGroupMessageDataTypeStruct *pMessageSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetMessageSettings(TBHandle apiHandle, WriterGroupMessageDataTypeStruct *pMessageSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupSetTransportSettings(TBHandle apiHandle, const WriterGroupTransportDataTypeStruct *pTransportSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPWriterGroupGetTransportSettings(TBHandle apiHandle, WriterGroupTransportDataTypeStruct *pTransportSettings);

		TBCORE_IF void* OTAPI_CALL OTPReaderGroup_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGroupAddDataSetReader(TBHandle apiHandle, TBHandle apiHandleDataSetReader);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGroupRemoveDataSetReader(TBHandle apiHandle, TBHandle apiHandleDataSetReader);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGroupGetDataSetReaders(TBHandle apiHandle, size_t *pDataSetReaderCount, TBHandle **apiHandelDataSetReader);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGroupSetTransportSettings(TBHandle apiHandle, const ReaderGroupTransportDataTypeStruct *pTransportSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGroupGetTransportSettings(TBHandle apiHandle, ReaderGroupTransportDataTypeStruct *pTransportSettings);

		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetName(TBHandle apiHandle, const OTChar* groupName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetName(TBHandle apiHandle, OTChar** ppGroupName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetEnabled(TBHandle apiHandle, bool enabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetEnabled(TBHandle apiHandle, bool* pEnabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetPubSubState(TBHandle apiHandle, EnumPubSubState *pState);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode mode);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* mode);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetSecurityGroupId(TBHandle apiHandle, const OTChar* securityGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetSecurityGroupId(TBHandle apiHandle, OTChar** ppSecurityGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetSecurityKeyService(TBHandle apiHandle, size_t securityKeyServicesCount, const EndpointDescriptionStruct* const* ppSecurityKeyServices);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetSecurityKeyService(TBHandle apiHandle, size_t *pSecurityKeyServicesCount, EndpointDescriptionStruct** ppSecurityKeyServices);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetMaxNetworkMessageSize(TBHandle apiHandle, const OTUInt32* pMaxNetworkMessageSize);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetMaxNetworkMessageSize(TBHandle apiHandle, OTUInt32* pMaxNetworkMessageSize);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupSetGroupProperties(TBHandle apiHandle, size_t groupPropertiesCount, KeyValuePairStruct **ppGroupProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPGroupGetGroupProperties(TBHandle apiHandle, size_t *pGroupPropertiesCount, KeyValuePairStruct **ppGroupProperties);

		TBCORE_IF void* OTAPI_CALL OTPPublishedDataSet_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetSetName(TBHandle apiHandle, const OTChar* name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetName(TBHandle apiHandle, OTChar** pName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetConfigurationVersion(TBHandle apiHandle, ConfigurationVersionDataTypeStruct* version);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetDataSetClassId(TBHandle apiHandle, GuidStruct *pClassId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetSetDataSetClassId(TBHandle apiHandle, const GuidStruct *pClassId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetSetMetaData(TBHandle apiHandle, const DataSetMetaDataTypeStruct* metaData);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetMetaData(TBHandle apiHandle, DataSetMetaDataTypeStruct* metaData);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetSetExtensionFields(TBHandle apiHandle, size_t extensionFieldsCount, KeyValuePairStruct **ppExtensionFields);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetExtensionFields(TBHandle apiHandle, size_t *pExtensionFields, KeyValuePairStruct **ppExtensionFields);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetSetSource(TBHandle apiHandle, const PublishedDataSetSourceDataTypeStruct* source);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetSource(TBHandle apiHandle, PublishedDataSetSourceDataTypeStruct* source);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetAddWriter(TBHandle apiHandle, TBHandle apiHandelWriter);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetRemoveWriter(TBHandle apiHandle, TBHandle apiHandelWriter);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetWriters(TBHandle apiHandle, size_t *pGroupCount, TBHandle **apiHandelWriters);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetGetSource(TBHandle apiHandle, PublishedDataSetSourceDataTypeStruct* source);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPPublishedDataSetProvideCurrentValues(TBHandle apiHandle, size_t noOfValues, const DataValueStruct** ppValues);

		TBCORE_IF void* OTAPI_CALL OTPPublishedDataItems_Internal_Construct(TBHandle apiHandle, bool addRef);

		TBCORE_IF void* OTAPI_CALL OTPPublishedEvents_Internal_Construct(TBHandle apiHandle, bool addRef);

		TBCORE_IF void* OTAPI_CALL OTPReader_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetName(TBHandle apiHandle, const OTChar* name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetName(TBHandle apiHandle, OTChar **name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetEnabled(TBHandle apiHandle, bool enabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetEnabled(TBHandle apiHandle, bool *pEnabled);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetPubSubState(TBHandle apiHandle, EnumPubSubState *pState);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetPublisherId(TBHandle apiHandle, const ValueStruct* publisherId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetPublisherId(TBHandle apiHandle, ValueStruct* publisherId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetWriterGroupId(TBHandle apiHandle, OTUInt16 writerGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetWriterGroupId(TBHandle apiHandle, OTUInt16 *writerGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetDataSetWriterId(TBHandle apiHandle, OTUInt16 dataSetWriterId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetDataGetWriterId(TBHandle apiHandle, OTUInt16 *dataSetWriterId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetReceiveTimeout(TBHandle apiHandle, OTDouble messageReceiveTimeout);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetReceiveTimeout(TBHandle apiHandle, OTDouble *messageReceiveTimeout);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetDataSetFieldContentMask(TBHandle apiHandle, OTUInt32 dataSetFieldContentMask);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetDataSetFieldContentMask(TBHandle apiHandle, OTUInt32 *dataSetFieldContentMask);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetDataSet(TBHandle apiHandle, TBHandle* dataSet);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetDataSet(TBHandle apiHandle, TBHandle dataSet);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode mode);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetSecurityMode(TBHandle otbHandle, EnumMessageSecurityMode* mode);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetSecurityGroupId(TBHandle apiHandle, const OTChar* securityGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetSecurityGroupId(TBHandle apiHandle, OTChar** ppSecurityGroupId);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetSecurityKeyService(TBHandle apiHandle, size_t securityKeyServicesCount, const EndpointDescriptionStruct* const * ppSecurityKeyServices);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetSecurityKeyService(TBHandle apiHandle, size_t *pSecurityKeyServicesCount, EndpointDescriptionStruct** ppSecurityKeyServices);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetProperties(TBHandle apiHandle, size_t pPropertiesCount, KeyValuePairStruct **ppProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetProperties(TBHandle apiHandle, size_t *propertiesCount, KeyValuePairStruct **ppProperties);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetMessageSettings(TBHandle apiHandle, const DataSetReaderMessageDataTypeStruct *pMessageSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetMessageSettings(TBHandle apiHandle, DataSetReaderMessageDataTypeStruct *pMessageSettings);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderSetMetaData(TBHandle apiHandle, const DataSetMetaDataTypeStruct *pMetaData);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderGetMetaData(TBHandle apiHandle, DataSetMetaDataTypeStruct *pMetaData);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPReaderRequestMetaData(TBHandle otbHandle, ValueStruct* pPublisherId, OTUInt16 writerId);

		TBCORE_IF void* OTAPI_CALL OTPSubscribedDataSet_Internal_Construct(TBHandle apiHandle, bool addRef);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPSubscribedDataSetSetName(TBHandle apiHandle, const OTChar* name);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPSubscribedDataSetGetName(TBHandle apiHandle, OTChar** pName);
		TBCORE_IF EnumStatusCode OTAPI_CALL OTPSubscribedDataSetGetReader(TBHandle apiHandle, TBHandle *apiHandelReader);

#ifdef __cplusplus
}
#endif

#endif // _C_API_H_
