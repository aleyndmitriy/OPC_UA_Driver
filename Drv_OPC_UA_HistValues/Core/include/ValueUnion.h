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

#ifndef _VALUE_UNION_
#define _VALUE_UNION_

#include "ByteStringStruct.h"
#include "OTTypes.h"
#include "Enums.h"

struct DataValueStruct;
struct ValueStructArrayValue;
struct RangeStruct;
struct ByteStringStruct;
struct GuidStruct;
struct NodeIdStruct;
struct ExpandedNodeIdStruct;
struct QualifiedNameStruct;
struct LocalizedTextStruct;
struct DiagnosticInfoStruct;
struct DateTimeStruct;
struct EUInformationStruct;
struct TimeZoneStruct;
struct ArgumentStruct;
struct ValueStruct;
struct SignedSoftwareCertificateStruct;
struct ReferenceDescriptionStruct;
struct ApplicationDescriptionStruct;
struct ServerDiagnosticsSummaryDataTypeStruct;
struct SubscriptionDiagnosticsDataTypeStruct;
struct SessionDiagnosticsDataTypeStruct;
struct SessionSecurityDiagnosticsDataTypeStruct;
struct ServiceCounterDataTypeStruct;
struct SemanticChangeStructureDataTypeStruct;
struct ModelChangeStructureDataTypeStruct;
struct UserIdentityTokenStruct;
struct BuildInfoStruct;
struct ServerStatusDataTypeStruct;
struct EventFilterStruct;
struct EnumValueTypeStruct;
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
struct OTExtensionObject;

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! @brief Correspond to the OpcUa_VariantArrayUnion. */
typedef union tagValueArrayUnion
{
	void*										Array;
	OTBoolean*									BooleanArray;
	OTInt8*										Int8Array;
	OTUInt8*									UInt8Array;
	OTInt16*									Int16Array;
	OTUInt16*									UInt16Array;
	OTInt32*									Int32Array;
	OTUInt32*									UInt32Array;
	OTInt64*									Int64Array;
	OTUInt64*									UInt64Array;
	OTFloat*									FloatArray;
	OTDouble*									DoubleArray;
	OTChar**									StringArray;
	DateTimeStruct*								DateTimeArray;
	GuidStruct*									GuidArray;
	ByteStringStruct*							ByteStringArray;
	ByteStringStruct*							XmlElementArray;
	EnumStatusCode*								StatusCodeArray;
	NodeIdStruct*								NodeIdArray;
	ExpandedNodeIdStruct*						ExpandedNodeIdArray;
	EUInformationStruct*						EUInformationArray;
	TimeZoneStruct*								TimeZoneArray;
	RangeStruct*								RangeArray;
	ArgumentStruct*								ArgumentArray;
	QualifiedNameStruct*						QualifiedNameArray;
	LocalizedTextStruct*						LocalizedTextArray;
	DataValueStruct*							DataValueArray;
	ValueStruct*								ValueArray;
	DiagnosticInfoStruct*						DiagnosticInfoArray;
	SignedSoftwareCertificateStruct*			SignedSoftwareCertificateArray;
	ReferenceDescriptionStruct*					ReferenceDescriptionArray;
	ApplicationDescriptionStruct*				ApplicationDescriptionArray;
	ServerDiagnosticsSummaryDataTypeStruct*		ServerDiagnosticsSummaryDataTypeArray;
	SubscriptionDiagnosticsDataTypeStruct*		SubscriptionDiagnosticsDataTypeArray;
	SessionDiagnosticsDataTypeStruct*			SessionDiagnosticsDataTypeArray;
	SessionSecurityDiagnosticsDataTypeStruct*	SessionSecurityDiagnosticsDataTypeArray;
	ServiceCounterDataTypeStruct*				ServiceCounterDataTypeArray;
#if TB5_ALARMS
	SemanticChangeStructureDataTypeStruct*		SemanticChangeStructureDataTypeArray;
	ModelChangeStructureDataTypeStruct*			ModelChangeStructureDataTypeArray;
#endif
	UserIdentityTokenStruct*					UserIdentityTokenArray;
	BuildInfoStruct*							BuildInfoArray;
	ServerStatusDataTypeStruct*					ServerStatusDataTypeArray;
#if TB5_ALARMS
	EventFilterStruct*							EventFilterArray;
#endif
	EnumValueTypeStruct*						EnumValueTypeArray;
	KeyValuePairStruct*							KeyValuePairArray;
	ConfigurationVersionDataTypeStruct*			ConfigurationVersionDataTypeArray;
	DataSetMetaDataTypeStruct*					DataSetMetaDataTypeArray;
	DataSetReaderDataTypeStruct*				DataSetReaderDataTypeArray;
	DataSetWriterDataTypeStruct*				DataSetWriterDataTypeArray;
	EnumDefinitionStruct*						EnumDefinitionArray;
	FieldTargetDataTypeStruct*					FieldTargetDataTypeArray;
	PubSubConnectionDataTypeStruct*				PubSubConnectionDataTypeArray;
	ReaderGroupDataTypeStruct*					ReaderGroupDataTypeArray;
	RolePermissionTypeStruct*					RolePermissionTypeArray;
	StructureDefinitionStruct*					StructureDefinitionArray;
	WriterGroupDataTypeStruct*					WriterGroupDataTypeArray;
	PublishedVariableDataTypeStruct*			PublishedVariableDataTypeArray;
	EndpointDescriptionStruct*					EndpointDescriptionArray;
	// NEW_SUPPORTED_DATATYPE - add member for array/matrix
	OTExtensionObject*ExtensionObjectArray; 
}ValueArrayUnion;

/*! Correspond to the OpcUa_VariantArrayValue. */
typedef struct ValueStructArrayValue
{
	/*! @brief Total number of elements in all dimensions. */
	OTInt32 Length;

	/*! @brief data stored in the array */
	ValueArrayUnion Value;

}ValueStructArrayValue;


/*! Correspond to the OpcUa_VariantMatrixValue. */
typedef struct ValueStructMatrixValue
{
	/* The number of dimensions in the array. */
	OTUInt32 NoOfDimensions;

	/* The length of each dimension. */
	OTUInt32* Dimensions;

	/*! @brief data stored in the array */
	ValueArrayUnion Value;

}ValueStructMatrixValue;


#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

/*! Correspond to the OpcUa_VariantUnion. */
typedef union tagValueUnion
{
	OTBoolean										Boolean;
	OTInt8											Int8;
	OTUInt8											UInt8;
	OTInt16											Int16;
	OTUInt16										UInt16;
	OTInt32											Int32;
	OTUInt32										UInt32;
	OTInt64											Int64;
	OTUInt64										UInt64;
	OTFloat											Float;
	OTDouble										Double;
	EnumStatusCode									StatusCode;
	OTChar*											String;
	DateTimeStruct*									DateTime;
	GuidStruct*										Guid;
	ByteStringStruct*								ByteString;
	ByteStringStruct*								XmlElement;
	NodeIdStruct*									NodeId;
	ExpandedNodeIdStruct*							ExpandedNodeId;
	QualifiedNameStruct*							QualifiedName;
	LocalizedTextStruct*							LocalizedText;
	DataValueStruct*								DataValue;
	DiagnosticInfoStruct*							DiagnosticInfo;
	EUInformationStruct*							EUInformation;
	TimeZoneStruct*									TimeZone;
	RangeStruct*									Range;
	ArgumentStruct*									Argument;
	ValueStructArrayValue							Array;
	ValueStructMatrixValue*							Matrix;
	SignedSoftwareCertificateStruct*				SignedSoftwareCertificate;
	ReferenceDescriptionStruct*						ReferenceDescription;
	ApplicationDescriptionStruct*					ApplicationDescription;
	ServerDiagnosticsSummaryDataTypeStruct*			ServerDiagnosticsSummaryDataType;
	SubscriptionDiagnosticsDataTypeStruct*			SubscriptionDiagnosticsDataType;
	SessionDiagnosticsDataTypeStruct*				SessionDiagnosticsDataType;
	SessionSecurityDiagnosticsDataTypeStruct*		SessionSecurityDiagnosticsDataType;
	ServiceCounterDataTypeStruct*					ServiceCounterDataType;
#if TB5_ALARMS
	SemanticChangeStructureDataTypeStruct*			SemanticChangeStructureDataType;
	ModelChangeStructureDataTypeStruct*				ModelChangeStructureDataType;
#endif
	UserIdentityTokenStruct*						UserIdentityToken;
	BuildInfoStruct*								BuildInfo;
	ServerStatusDataTypeStruct*						ServerStatusDataType;
#if TB5_ALARMS
	EventFilterStruct*								EventFilter;
#endif
	EnumValueTypeStruct*							EnumValueType;
	KeyValuePairStruct*								KeyValuePair;
	ConfigurationVersionDataTypeStruct*				ConfigurationVersionDataType;
	DataSetMetaDataTypeStruct*						DataSetMetaDataType;
	DataSetReaderDataTypeStruct*					DataSetReaderDataType;
	DataSetWriterDataTypeStruct*					DataSetWriterDataType;
	EnumDefinitionStruct*							EnumDefinition;
	FieldTargetDataTypeStruct*						FieldTargetDataType;
	PubSubConnectionDataTypeStruct*					PubSubConnectionDataType;
	ReaderGroupDataTypeStruct*						ReaderGroupDataType;
	RolePermissionTypeStruct*						RolePermissionType;
	StructureDefinitionStruct*						StructureDefinition;
	WriterGroupDataTypeStruct*						WriterGroupDataType;
	PublishedVariableDataTypeStruct*				PublishedVariableDataType;
	EndpointDescriptionStruct*						EndpointDescription;
	// NEW_SUPPORTED_DATATYPE - add member for scalar
	OTExtensionObject*ExtensionObject; 
}ValueStructUnion;


#endif
