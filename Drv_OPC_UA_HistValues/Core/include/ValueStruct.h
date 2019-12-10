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

#ifndef _VALUESTRUCT_H_
#define _VALUESTRUCT_H_

#include <vector>

#include "ByteStringStruct.h"
#include "ValueUnion.h"
#include "GuidStruct.h"
#include "NodeIdStruct.h"
#include "ExpandedNodeIdStruct.h"
#include "QualifiedNameStruct.h"
#include "LocalizedTextStruct.h"
#include "EUInformationStruct.h"
#include "TimeZoneStruct.h"
#include "NumericRangeStruct.h"
#include "SignedSoftwareCertificateStruct.h"
#include "ReferenceDescriptionStruct.h"
#include "ApplicationDescriptionStruct.h"
#include "ServerDiagnosticsSummaryDataTypeStruct.h"
#include "SubscriptionDiagnosticsDataTypeStruct.h"
#include "SessionDiagnosticsDataTypeStruct.h"
#include "SessionSecurityDiagnosticsDataTypeStruct.h"
#include "ServiceCounterDataTypeStruct.h"
#include "SemanticChangeStructureDataTypeStruct.h"
#include "ModelChangeStructureDataTypeStruct.h"
#include "UserIdentityTokenStruct.h"
#include "BuildInfoStruct.h"
#include "ServerStatusDataTypeStruct.h"
#include "EnumValueTypeStruct.h"
#include <limits>

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif
/* IEEE_FLOAT_IS_NAN returns TRUE if float value is +/- INF or NAN */
#define IEEE_IS_FLOAT_NAN(f) ((*(unsigned*)&(f) & 0x7F800000u) == 0x7F800000u)

/* IEEE_IS_DOUBLE_NAN returns TRUE if double value is +/- INF or NAN */
#ifdef DOUBLESWAP_DWORDS
#define IEEE_IS_DOUBLE_NAN(d) ((*(unsigned long long*)&(d) & 0x000000007FF00000ull) == 0x000000007FF00000ull)
#else
#define IEEE_IS_DOUBLE_NAN(d) ((*(unsigned long long*)&(d) & 0x7FF0000000000000ull) == 0x7FF0000000000000ull)
#endif

/* According to the C-99 standard, the only safe way to access the bits
 * of a floating point value is to cast through an union.
 * this way we are compatible with GCC's -fstrict-aliasing optimization. */
bool isNan(float f);

bool isNan(double d);


struct DataValueStruct;
class OTStructuredDataTypeDescription;
struct KeyValuePairStruct;
struct ConfigurationVersionDataTypeStruct;
struct DataSetMetaDataTypeStruct;
struct DataSetReaderDataTypeStruct;
struct DataSetWriterDataTypeStruct;
struct EnumDefinitionStruct;
struct FieldTargetDataTypeStruct;
struct PubSubConnectionDataTypeStruct;
struct ReaderGroupDataTypeStruct;
struct RolePermissionTypeStruct;
struct StructureDefinitionStruct;
struct WriterGroupDataTypeStruct;
struct PublishedVariableDataTypeStruct;
struct EndpointDescriptionStruct;
// NEW_SUPPORTED_DATATYPE - add forward declaration

#define DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(dataType)\
	EnumStatusCode set##dataType(const dataType##Struct& valueArg);\
	EnumStatusCode set##dataType##Array(const dataType##Struct* arrayValue, OTInt32 length);\
	EnumStatusCode set##dataType##Matrix(const dataType##Struct* arrayValue, OTUInt32 noOfDimensions, const OTUInt32*pDimensions)

#define DECLARE_VALUESTRUCT_METHODS_WITH_MEMBER_OF_NODE_FOR_TYPE(dataType)\
	EnumStatusCode set##dataType(const dataType##Struct& valueArg, bool targetIsMemberOfNode = false);\
	EnumStatusCode set##dataType##Array(const dataType##Struct* arrayValue, OTInt32 length, bool targetIsMemberOfNode = false);\
	EnumStatusCode set##dataType##Matrix(const dataType##Struct* arrayValue, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false)

/*! @brief Correspond to OpcUa_Variant.
*
*   @see OPC UA Part 6 par. 5.1.5 for specs.
*
*   @par Few observations on data types:
*   <ul>
*   <li>Instead of SByte the Int8 should be used.
*   <li>Instead of Byte the UInt8 should be used.
*   <li>XmlElement is in fact a ByteString.
*   <li>Instead of UInt8 array the ByteString should be used.
*   <li>Variants can contain arrays of Variants but they cannot
*       directly contain another Variant.
*   <li>Variants can be empty.
*   </ul> */
//lint -sem(ValueStruct::clear, cleanup)
//lint -sem(ValueStruct::init, initializer)
//lint -sem(ValueStruct::init, initializer)
typedef struct TBCORE_IF ValueStruct
{
	/* @brief the array type can be scalar/array/matrix */
	OTUInt8 arrayType;

	/* @brief the data type currently set. */
	OTUInt16 dataType;

	/* @brief Correspond to the OpcUa_VariantUnion */
	ValueStructUnion value;

	ValueStruct(void);
	ValueStruct(const ValueStruct& copy);

	EnumStatusCode set(const ValueStruct& cp, bool targetIsMemberOfNode = false);
	EnumStatusCode get(ValueStruct& target) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_Variant& cp, OTUInt32 reserved = 0);
	EnumStatusCode get(OpcUa_Variant& target, const std::vector<tstring>& preferredLocales) const;
#endif

	const ValueStruct& operator=(const ValueStruct& cp);

	bool operator==(const ValueStruct &toCompare) const;
	bool operator!=(const ValueStruct &toCompare) const;
	bool operator<(const ValueStruct &toCompare) const;

	static bool supportsDataType(OTUInt16 dataTypeId);
	static OTUInt8 getBuiltInType(const NodeIdStruct &dataTypeId);

	OTInt32 getValueRank(void) const;

	tstring toString(void) const;

	void clear(void);
	void init(void);

	/*! @brief Initializes this structure with default values
	 *
	 * @param dataType the data type
	 * @param arrayType the arrayType (EnumValueArrayType_Scalar, EnumValueArrayType_Array
	 *        or EnumValueArrayType_Matrix) */
	EnumStatusCode init(OTUInt16 dataType, OTUInt8 arrayType);
	void swap(ValueStruct & other);
	~ValueStruct(void);

#ifdef OT_COMPILATION
	// encoding / decoding the value to /from a stream (works for embedded values in a structure only since only contents of embedded structures are encoded / decoded).
	EnumStatusCode encode(struct _OpcUa_Encoder *pEncoder, const std::vector<tstring>& preferredLocales, OTUInt32 arrayLength = std::numeric_limits<OTUInt32>::max()) const ;
	EnumStatusCode decode(struct _OpcUa_Decoder *pDecoder, EnumDataTypeId encodedDataType, EnumValueArrayType encodedArrayType, OTUInt32 arrayLength = std::numeric_limits<OTUInt32>::max());
#endif

	/*! Recursive helper method to test against array dimensions of variables and variable types */
	EnumStatusCode checkArrayDimensions(OTUInt32 arrayDimensionsCount, const OTUInt32 *pArrayDimensions) const;

	/*! Helper method to test against value rank of variables and variable types */
	EnumStatusCode checkValueRank(OTInt32 valueRank) const;

	/*! Helper method to check whether ValueRank and ArrayDimensions fit together */
	static bool valueRankMatchToArrayDimensions(OTInt32 valueRank, OTUInt32 arrayDimensionsCount);

	//////////////////////////////////////////////////////////////////////////
	// Methods for setting values
	//////////////////////////////////////////////////////////////////////////

	// Null
	void setNull();

	// Boolean
	void setBoolean(OTBoolean value);
	EnumStatusCode setBooleanArray(const OTBoolean* arrayBoolean, OTInt32 length);
	EnumStatusCode setBooleanMatrix(const OTBoolean* arrayBoolean, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// UInt8 (Byte)
	void setUInt8(OTUInt8 value);
	EnumStatusCode setUInt8Array(const OTUInt8* arrayUInt8, OTInt32 length);
	EnumStatusCode setUInt8Matrix(const OTUInt8* arrayUInt8, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Int8 (SByte)
	void setInt8(OTInt8 value);
	EnumStatusCode setInt8Array(const OTInt8* arrayInt8, OTInt32 length);
	EnumStatusCode setInt8Matrix(const OTInt8* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// UInt16
	void setUInt16(OTUInt16 value);
	EnumStatusCode setUInt16Array(const OTUInt16* arrayUInt16, OTInt32 length);
	EnumStatusCode setUInt16Matrix(const OTUInt16* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Int16
	void setInt16(OTInt16 value);
	EnumStatusCode setInt16Array(const OTInt16* arrayInt16, OTInt32 length);
	EnumStatusCode setInt16Matrix(const OTInt16* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// UInt32
	void setUInt32(OTUInt32 value);
	EnumStatusCode setUInt32Array(const OTUInt32* arrayUInt32, OTInt32 length);
	EnumStatusCode setUInt32Matrix(const OTUInt32* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Int32
	void setInt32(OTInt32 value);
	EnumStatusCode setInt32Array(const OTInt32* arrayInt32, OTInt32 length);
	EnumStatusCode setInt32Array(const OTInt32* arrayInt32, OTInt32 length, EnumDataTypeId dataTypeId);
	EnumStatusCode setInt32Matrix(const OTInt32* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// UInt64
	void setUInt64(OTUInt64 value);
	EnumStatusCode setUInt64Array(const OTUInt64* arrayUInt64, OTInt32 length);
	EnumStatusCode setUInt64Matrix(const OTUInt64* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Int64
	void setInt64(OTInt64 value);
	EnumStatusCode setInt64Array(const OTInt64* arrayInt64, OTInt32 length);
	EnumStatusCode setInt64Matrix(const OTInt64* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Float
	void setFloat(OTFloat value);
	EnumStatusCode setFloatArray(const OTFloat* arrayFloat, OTInt32 length);
	EnumStatusCode setFloatMatrix(const OTFloat* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Double
	void setDouble(OTDouble value);
	EnumStatusCode setDoubleArray(const OTDouble* arrayDouble, OTInt32 length);
	EnumStatusCode setDoubleMatrix(const OTDouble* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// DateTime
	EnumStatusCode setDateTime(const DateTimeStruct& value);
	EnumStatusCode setDateTimeArray(const DateTimeStruct* arrayDateTime, OTInt32 length);
	EnumStatusCode setDateTimeMatrix(const DateTimeStruct* arrayDateTime, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// String
	EnumStatusCode setString(const OTChar* value);
	EnumStatusCode setStringArray(const std::vector<tstring>& arrayString);
	EnumStatusCode setStringArray(const OTChar* const* arrayString, OTInt32 length);
	EnumStatusCode setStringMatrix(const OTChar* const* arrayString, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// Guid
	EnumStatusCode setGuid(const GuidStruct& value);
	EnumStatusCode setGuidArray(const GuidStruct* arrayGuid, OTInt32 length);
	EnumStatusCode setGuidMatrix(const GuidStruct* arrayGuid, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ByteString
	EnumStatusCode setByteString(const ByteStringStruct& value);
	EnumStatusCode setByteString(OTUInt32 length, const OTUInt8* data);
	EnumStatusCode setByteStringArray(const ByteStringStruct* arrayByteString, OTInt32 length);
	EnumStatusCode setByteStringMatrix(const ByteStringStruct* arrayByteString, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// XmlElement
	EnumStatusCode setXmlElement(const XmlElementStruct& value);
	EnumStatusCode setXmlElementArray(const XmlElementStruct* arrayXmlElement, OTInt32 length);
	EnumStatusCode setXmlElementMatrix(const XmlElementStruct* arrayXmlElement, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// StatusCode
	void setStatusCode(const EnumStatusCode value);
	EnumStatusCode setStatusCodeArray(const EnumStatusCode* arrayStatusCode, OTInt32 length);
	EnumStatusCode setStatusCodeArray(const EnumStatusCode* arrayStatusCode, OTInt32 length, OTInt32 index);
	EnumStatusCode setStatusCodeMatrix(const EnumStatusCode* matrixValue, OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions);

	// Value
	EnumStatusCode setValueArray(const ValueStruct* arrayDataValue, OTInt32 length);
	EnumStatusCode attachToValueArray(const ValueStruct* pValue, OTInt32 length);
	EnumStatusCode setValueMatrix(const ValueStruct* arrayDataValue, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// DataValue
	EnumStatusCode setDataValue(const DataValueStruct& value);
	EnumStatusCode setDataValueArray(const DataValueStruct* arrayDataValue, OTInt32 length);
	EnumStatusCode setDataValueMatrix(const DataValueStruct* arrayDataValue, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// DiagnosticInfoStruct
	EnumStatusCode setDiagnosticInfo(const DiagnosticInfoStruct& value);
	EnumStatusCode setDiagnosticInfoArray(const DiagnosticInfoStruct* arrayDiagnosticInfo, OTInt32 length);
	EnumStatusCode setDiagnosticInfoMatrix(const DiagnosticInfoStruct* arrayDiagnosticInfo, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ExpandedNodeId
	EnumStatusCode setExpandedNodeId(const ExpandedNodeIdStruct& value);
	EnumStatusCode setExpandedNodeIdArray(const ExpandedNodeIdStruct* arrayExpandedNodeId, OTInt32 length);
	EnumStatusCode setExpandedNodeIdMatrix(const ExpandedNodeIdStruct* arrayExpandedNodeId, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// LocalizedText
	EnumStatusCode setLocalizedText(const LocalizedTextStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setLocalizedTextArray(const LocalizedTextStruct* arrayLocalizedText, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setLocalizedTextMatrix(const LocalizedTextStruct* arrayLocalizedText, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false);

	// QualifiedName
	EnumStatusCode setQualifiedName(const QualifiedNameStruct& value);
	EnumStatusCode setQualifiedNameArray(const QualifiedNameStruct* arrayQualifiedName, OTInt32 length);
	EnumStatusCode setQualifiedNameMatrix(const QualifiedNameStruct* arrayQualifiedName, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// NodeId
	EnumStatusCode setNodeId(const NodeIdStruct& value);
	EnumStatusCode setNodeIdArray(const NodeIdStruct* arrayNodeId, OTInt32 length);
	EnumStatusCode setNodeIdMatrix(const NodeIdStruct* arrayNodeId, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// EUInformation
	EnumStatusCode setEUInformation(const EUInformationStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setEUInformationArray(const EUInformationStruct* arrayEUInformation, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setEUInformationMatrix(const EUInformationStruct* arrayEUInformation, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false);

	// TimeZone
	EnumStatusCode setTimeZone(const TimeZoneStruct& value);
	EnumStatusCode setTimeZoneArray(const TimeZoneStruct* arrayTimeZone, OTInt32 length);
	EnumStatusCode setTimeZoneMatrix(const TimeZoneStruct* arrayTimeZone, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// Argument
	EnumStatusCode setArgument(const ArgumentStruct& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setArgumentArray(const ArgumentStruct* arrayArgument, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setArgumentMatrix(const ArgumentStruct* arrayArgument, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false);

	// Range
	EnumStatusCode setRange(const RangeStruct& value);
	EnumStatusCode setRangeArray(const RangeStruct* arrayRange, OTInt32 length);
	EnumStatusCode setRangeMatrix(const RangeStruct* arrayRange, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// SignedSoftwareCertificate
	EnumStatusCode setSignedSoftwareCertificate(const SignedSoftwareCertificateStruct& value);
	EnumStatusCode setSignedSoftwareCertificateArray(const SignedSoftwareCertificateStruct* arrayRange, OTInt32 length);
	EnumStatusCode setSignedSoftwareCertificateMatrix(const SignedSoftwareCertificateStruct* arrayRange, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ReferenceDescription
	EnumStatusCode setReferenceDescription(const ReferenceDescriptionStruct& value);
	EnumStatusCode setReferenceDescriptionArray(const ReferenceDescriptionStruct* arrayReferenceDescription, OTInt32 length);
	EnumStatusCode setReferenceDescriptionMatrix(const ReferenceDescriptionStruct* arrayReferenceDescription, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ApplicationDescription
	EnumStatusCode setApplicationDescription(const ApplicationDescriptionStruct& value);
	EnumStatusCode setApplicationDescriptionArray(const ApplicationDescriptionStruct* arrayApplicationDescription, OTInt32 length);
	EnumStatusCode setApplicationDescriptionMatrix(const ApplicationDescriptionStruct* arrayApplicationDescription, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ServerDiagnosticsSummaryDataType
	EnumStatusCode setServerDiagnosticsSummaryDataType(const ServerDiagnosticsSummaryDataTypeStruct& value);
	EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const ServerDiagnosticsSummaryDataTypeStruct* arrayServerDiagnosticsSummaryDataType, OTInt32 length);
	EnumStatusCode setServerDiagnosticsSummaryDataTypeMatrix(const ServerDiagnosticsSummaryDataTypeStruct* arrayServerDiagnosticsSummaryDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// SubscriptionDiagnosticsDataType
	EnumStatusCode setSubscriptionDiagnosticsDataType(const SubscriptionDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const SubscriptionDiagnosticsDataTypeStruct* arraySubscriptionDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSubscriptionDiagnosticsDataTypeMatrix(const SubscriptionDiagnosticsDataTypeStruct* arraySubscriptionDiagnosticsDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// SessionDiagnosticsDataType
	EnumStatusCode setSessionDiagnosticsDataType(const SessionDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSessionDiagnosticsDataTypeArray(const SessionDiagnosticsDataTypeStruct* arraySessionDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSessionDiagnosticsDataTypeMatrix(const SessionDiagnosticsDataTypeStruct* arraySessionDiagnosticsDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// SessionSecurityDiagnosticsDataType
	EnumStatusCode setSessionSecurityDiagnosticsDataType(const SessionSecurityDiagnosticsDataTypeStruct& value);
	EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const SessionSecurityDiagnosticsDataTypeStruct* arraySessionSecurityDiagnosticsDataType, OTInt32 length);
	EnumStatusCode setSessionSecurityDiagnosticsDataTypeMatrix(const SessionSecurityDiagnosticsDataTypeStruct* arraySessionSecurityDiagnosticsDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// ServiceCounterDataType
	EnumStatusCode setServiceCounterDataType(const ServiceCounterDataTypeStruct& value);
	EnumStatusCode setServiceCounterDataTypeArray(const ServiceCounterDataTypeStruct* arrayServiceCounterDataType, OTInt32 length);
	EnumStatusCode setServiceCounterDataTypeMatrix(const ServiceCounterDataTypeStruct* arrayServiceCounterDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

#if TB5_ALARMS
	// SemanticChangeStructureDataType
	EnumStatusCode setSemanticChangeStructureDataType(const SemanticChangeStructureDataTypeStruct& value);
	EnumStatusCode setSemanticChangeStructureDataTypeArray(const SemanticChangeStructureDataTypeStruct* arraySemanticChangeStructureDataType, OTInt32 length);
	EnumStatusCode setSemanticChangeStructureDataTypeMatrix(const SemanticChangeStructureDataTypeStruct* arraySemanticChangeStructureDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// SemanticChangeStructureDataType
	EnumStatusCode setModelChangeStructureDataType(const ModelChangeStructureDataTypeStruct& value);
	EnumStatusCode setModelChangeStructureDataTypeArray(const ModelChangeStructureDataTypeStruct* arrayModelChangeStructureDataType, OTInt32 length);
	EnumStatusCode setModelChangeStructureDataTypeMatrix(const ModelChangeStructureDataTypeStruct* arrayModelChangeStructureDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);
#endif

	// UserIdentityToken
	EnumStatusCode setUserIdentityToken(const UserIdentityTokenStruct& value);
	EnumStatusCode setUserIdentityTokenArray(const UserIdentityTokenStruct* arrayUserIdentityToken, OTInt32 length);
	EnumStatusCode setUserIdentityTokenMatrix(const UserIdentityTokenStruct* arrayUserIdentityToken, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// BuildInfo
	EnumStatusCode setBuildInfo(const BuildInfoStruct& value);
	EnumStatusCode setBuildInfoArray(const BuildInfoStruct* arrayBuildInfo, OTInt32 length);
	EnumStatusCode setBuildInfoMatrix(const BuildInfoStruct* arrayBuildInfo, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

#if TB5_ALARMS
	// EventFilter
	EnumStatusCode setEventFilter(const EventFilterStruct& valueArg);
	EnumStatusCode setEventFilterArray(const EventFilterStruct* arrayEventFilter, OTInt32 length);
	EnumStatusCode setEventFilterMatrix(const EventFilterStruct* arrayEventFilter, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);
#endif

	// ServerStatusDataType
	EnumStatusCode setServerStatusDataType(const ServerStatusDataTypeStruct& valueArg);
	EnumStatusCode setServerStatusDataTypeArray(const ServerStatusDataTypeStruct* arrayServerStatusDataType, OTInt32 length);
	EnumStatusCode setServerStatusDataTypeMatrix(const ServerStatusDataTypeStruct* arrayServerStatusDataType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions);

	// EnumValueType
	EnumStatusCode setEnumValueType(const EnumValueTypeStruct& valueArg, bool targetIsMemberOfNode = false);
	EnumStatusCode setEnumValueTypeArray(const EnumValueTypeStruct* arrayEnumValueType, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setEnumValueTypeMatrix(const EnumValueTypeStruct* arrayEnumValueType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false);

	DECLARE_VALUESTRUCT_METHODS_WITH_MEMBER_OF_NODE_FOR_TYPE(KeyValuePair);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(ConfigurationVersionDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(DataSetMetaDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(DataSetReaderDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(DataSetWriterDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(EnumDefinition);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(FieldTargetDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(PubSubConnectionDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(ReaderGroupDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(RolePermissionType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(StructureDefinition);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(WriterGroupDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(PublishedVariableDataType);
	DECLARE_VALUESTRUCT_METHODS_FOR_TYPE(EndpointDescription);
	// NEW_SUPPORTED_DATATYPE - add setters for scalar, array and matrix

#ifdef OT_COMPILATION
	// StructureType
	EnumStatusCode setExtensionObject(const OTExtensionObject& value, bool targetIsMemberOfNode = false);
	EnumStatusCode setExtensionObjectArray(const OTExtensionObject* arrayStructureType, OTInt32 length, bool targetIsMemberOfNode = false);
	EnumStatusCode setExtensionObjectMatrix(const OTExtensionObject* arrayStructureType, OTUInt32 noOfDimensions, const OTUInt32*pDimensions, bool targetIsMemberOfNode = false);
#endif

	EnumStatusCode getComplexRaw(NodeIdStruct* encodingId, ByteStringStruct* rawData) const;
	EnumStatusCode setComplexRaw(const NodeIdStruct* encodingId, const ByteStringStruct* rawData);

	EnumStatusCode getComplexRawArray(EnumValueArrayType expectedArrayType, NodeIdStruct* pEncodingId, OTUInt32* pCount, ByteStringStruct** ppRawData,
		OTUInt32* pNoOfArrayDimensions, OTUInt32** ppArrayDimensions) const;
	EnumStatusCode setComplexRawArray(EnumValueArrayType valueArrayType, const NodeIdStruct* encodingId, OTUInt32 valueCount, ByteStringStruct** ppValues,
		OTUInt32 noOfArrayDimensions, const OTUInt32* pArrayDimensions);

#ifdef OT_COMPILATION
	/*! Returns the fields of a custom structured data type
	* @note The caller has to free the returned fieldValues */
	EnumStatusCode getStructureFields(SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, std::vector<ValueStruct*>& values) const;
	EnumStatusCode setStructureFields(SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, const std::vector<const ValueStruct*>& values);

	/*! Returns the fields of a custom structured data type array
	* @note The caller has to free the returned fieldValues */
	EnumStatusCode getStructureFieldsArray(EnumValueArrayType expectedArrayType, SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, std::vector<std::vector<ValueStruct*> >& values,
		OTUInt32* pNoOfArrayDimensions, OTUInt32** ppArrayDimensions) const ;
	EnumStatusCode setStructureFieldsArray(EnumValueArrayType valueArrayType,
		SOCmnPointer<const OTStructuredDataTypeDescription> dataTypeDesc, const std::vector< std::vector<const ValueStruct*> >& values,
		OTUInt32 noOfArrayDimensions, const OTUInt32* pArrayDimensions);
#endif

	//////////////////////////////////////////////////////////////////////////
	// Array-related methods
	//////////////////////////////////////////////////////////////////////////

	/*! @brief Constructs an array from this value.
	 *
	 * This method is useful if you want to convert a scalar value
	 * to an array.
	 *
	 * @warning @p valueArray must be different from the object you are calling this method
	 *
	 * @param[out] target the array that is constructed from the scalar value
	 *             that is stored in this object
	 * @param      true, if the target is a member (C++-wise) of a node object */
	EnumStatusCode toArray(ValueStruct& target, bool targetIsMemberOfNode);
	EnumStatusCode toArray(std::vector<ValueStruct*> nestedValues, bool clearSourceValues);

	/*! @brief Attaches a scalar or array value to an array of values
	 *
	 * @param scalarValue the scalar or array value to attach */

	EnumStatusCode getSubset(ValueStruct* pDst, const NumericRangeStruct& indexRange) const;
	EnumStatusCode setSubset(const ValueStruct* pSrc, const NumericRangeStruct& indexRange);

	//////////////////////////////////////////////////////////////////////////

	int compare(const ValueStruct* pWith) const;
	int compareScalar(const ValueStruct & with) const;
	int compareArray(const ValueStruct & with) const;
	int compareMatrix(const ValueStruct & with) const;

	//////////////////////////////////////////////////////////////////////////
	// Internal helper methods
	//////////////////////////////////////////////////////////////////////////

	static OTUInt32 arrayDimensionsToFlatLength(OTUInt32 numberOfDimensions, const OTUInt32* arrayDimensions);

	static EnumStatusCode getStringRange(OTChar** pTargetString, OTChar* sourceString, const std::pair<OTUInt32, OTUInt32>& range);
	static EnumStatusCode replaceStringRange(OTChar** pTargetString, OTChar* sourceString, const std::pair<OTUInt32, OTUInt32>& range);

	EnumStatusCode copyArraySubset(const ValueStruct& src, OTUInt32 first, OTUInt32 count);
	EnumStatusCode replaceArraySubset(const ValueStruct& src, OTUInt32 first, OTUInt32 count);

	EnumStatusCode copyMatrixSubset(const ValueStruct& src, const NumericRangeStruct& indexRange);
	EnumStatusCode replaceMatrixSubset(const ValueStruct& src, const NumericRangeStruct& indexRange);

	EnumStatusCode copyStringArrayRange(const ValueStruct& src, const NumericRangeStruct& indexRange);
	EnumStatusCode copyByteStringArrayRange(const ValueStruct& src, const NumericRangeStruct& indexRange);
	EnumStatusCode replaceStringArrayRange(const ValueStruct& src, const NumericRangeStruct& indexRange);
	EnumStatusCode replaceByteStringArrayRange(const ValueStruct& src, const NumericRangeStruct& indexRange);


#ifdef OT_COMPILATION
	/*! @brief helper function that copies array values that are to be encoded as extension object to
	 * the Variant OPC UA structure */
	EnumStatusCode setExtensionArrayOrMatrix(OpcUa_VariantArrayUnion& target, OTUInt32 flatLength, const std::vector<tstring>& preferredLocales) const;

	/*! @brief helper function attaching extension objects into an allocated field of variants */
	static EnumStatusCode attachExtensionArray(OTUInt16 extensionDataType, OpcUa_ExtensionObject* pExtensionObject, const ValueArrayUnion source, OTUInt32 flatLength, const std::vector<tstring>& preferredLocales);
#endif

	template<typename T, EnumDataTypeId ID>
	EnumStatusCode setPrimitiveArray(const T* arrayValue, OTInt32 length);

	template<typename T, EnumDataTypeId ID>
	EnumStatusCode setPrimitiveMatrix(OTUInt32 noOfDimensions, const OTUInt32* pArrayDimensions, const T* matrixValue);
}ValueStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _VALUESTRUCT_H_
