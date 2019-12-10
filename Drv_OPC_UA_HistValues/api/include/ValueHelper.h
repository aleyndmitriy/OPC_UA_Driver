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

#ifndef VALUEHELPER_H
#define VALUEHELPER_H

#include "QualifiedName.h"
#include "NodeId.h"
#include "DateTime.h"
#include "ByteString.h"
#include "ExpandedNodeId.h"
#include "LocalizedText.h"
#include "DataValue.h"
#include "Guid.h"
#include "ByteString.h"
#include "ReferenceDescription.h"
#include "ApplicationDescription.h"
#include "ServerDiagnosticsSummaryDataType.h"
#include "SubscriptionDiagnosticsDataType.h"
#include "SessionDiagnosticsDataType.h"
#include "SessionSecurityDiagnosticsDataType.h"
#include "ServiceCounterDataType.h"
#include "SemanticChangeStructureDataType.h"
#include "ModelChangeStructureDataType.h"
#include "UserIdentityToken.h"
#include "SignedSoftwareCertificate.h"
#include "BuildInfo.h"
#include "EventFilter.h"
#include "ServerStatusDataType.h"
#include "EnumValueType.h"
#include "Guid.h"
#include "EUInformation.h"
#include "TimeZone.h"
#include "Argument.h"
#include "Range.h"
#include "KeyValuePair.h"
#include "ConfigurationVersionDataType.h"
#include "DataSetMetaDataType.h"
#include "DataSetReaderDataType.h"
#include "DataSetWriterDataType.h"
#include "EnumDefinition.h"
#include "FieldTargetDataType.h"
#include "PubSubConnectionDataType.h"
#include "ReaderGroupDataType.h"
#include "RolePermissionType.h"
#include "StructureDefinition.h"
#include "WriterGroupDataType.h"
#include "PublishedVariableDataType.h"
#include "EndpointDescription.h"
// NEW_SUPPORTED_DATATYPE - add type here

namespace SoftingOPCToolbox5
{
	class ValueHelper
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// DataValue access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getDataValue(const ValueStruct* pValueStruct, DataValue& target);
		static DataValue getDataValue(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataValue(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getDataValueArray(const ValueStruct* pValueStruct, std::vector<DataValue>& arrayDataValue);
		static std::vector<DataValue> getDataValueArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataValueArray(ValueStruct* pValueStruct, const std::vector<DataValue>& arrayDataValue);
		static EnumStatusCode getDataValueMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DataValue>& matrix);
		static EnumStatusCode setDataValueMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DataValue* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ExpandedNodeId access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getExpandedNodeId(const ValueStruct* pValueStruct, ExpandedNodeId& target);
		static ExpandedNodeId getExpandedNodeId(const ValueStruct* pValueStruct);
		static EnumStatusCode setExpandedNodeId(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getExpandedNodeIdArray(const ValueStruct* pValueStruct, std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		static std::vector<ExpandedNodeId> getExpandedNodeIdArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setExpandedNodeIdArray(ValueStruct* pValueStruct, const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		static EnumStatusCode getExpandedNodeIdMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ExpandedNodeId>& matrix);
		static EnumStatusCode setExpandedNodeIdMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ExpandedNodeId* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// LocalizedText access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getLocalizedText(const ValueStruct* pValueStruct, LocalizedText& target);
		static LocalizedText getLocalizedText(const ValueStruct* pValueStruct);
		static EnumStatusCode setLocalizedText(ValueStruct* pValueStruct, const ILocalizedText* localizedText);
		static EnumStatusCode getLocalizedTextArray(const ValueStruct* pValueStruct, std::vector<LocalizedText>& arrayLocalizedText);
		static std::vector<LocalizedText> getLocalizedTextArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setLocalizedTextArray(ValueStruct* pValueStruct, const std::vector<LocalizedText>& arrayLocalizedText);
		static EnumStatusCode getLocalizedTextMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<LocalizedText>& matrix);
		static EnumStatusCode setLocalizedTextMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const LocalizedText* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// QualifiedName access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getQualifiedName(const ValueStruct* pValueStruct, QualifiedName& target);
		static QualifiedName getQualifiedName(const ValueStruct* pValueStruct);
		static EnumStatusCode setQualifiedName(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getQualifiedNameArray(const ValueStruct* pValueStruct, std::vector<QualifiedName>& arrayQualifiedName);
		static std::vector<QualifiedName> getQualifiedNameArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setQualifiedNameArray(ValueStruct* pValueStruct, const std::vector<QualifiedName>& arrayQualifiedName);
		static EnumStatusCode getQualifiedNameMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<QualifiedName>& matrix);
		static EnumStatusCode setQualifiedNameMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const QualifiedName* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// NodeId access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getNodeId(const ValueStruct* pValueStruct, NodeId& target);
		static NodeId getNodeId(const ValueStruct* pValueStruct);
		static EnumStatusCode setNodeId(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getNodeIdArray(const ValueStruct* pValueStruct, std::vector<NodeId>& arrayNodeId);
		static std::vector<NodeId> getNodeIdArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setNodeIdArray(ValueStruct* pValueStruct, const std::vector<NodeId>& arrayNodeId);
		static EnumStatusCode getNodeIdMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<NodeId>& matrix);
		static EnumStatusCode setNodeIdMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const NodeId* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// DiagnosticInfo access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getDiagnosticInfo(const ValueStruct* pValueStruct, DiagnosticInfo& target);
		static DiagnosticInfo getDiagnosticInfo(const ValueStruct* pValueStruct);
		static EnumStatusCode setDiagnosticInfo(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getDiagnosticInfoArray(const ValueStruct* pValueStruct, std::vector<DiagnosticInfo>& arrayDiagnosticInfo);
		static std::vector<DiagnosticInfo> getDiagnosticInfoArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDiagnosticInfoArray(ValueStruct* pValueStruct, const std::vector<DiagnosticInfo>& arrayDiagnosticInfo);
		static EnumStatusCode getDiagnosticInfoMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DiagnosticInfo>& matrix);
		static EnumStatusCode setDiagnosticInfoMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DiagnosticInfo* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// EUInformation access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getEUInformation(const ValueStruct* pValueStruct, EUInformation& target);
		static EUInformation getEUInformation(const ValueStruct* pValueStruct);
		static EnumStatusCode setEUInformation(ValueStruct* pValueStruct, const IEUInformation* pEUInformation);
		static EnumStatusCode getEUInformationArray(const ValueStruct* pValueStruct, std::vector<EUInformation>& arrayEUInformation);
		static std::vector<EUInformation> getEUInformationArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setEUInformationArray(ValueStruct* pValueStruct, const std::vector<EUInformation>& arrayEUInformation);
		static EnumStatusCode getEUInformationMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EUInformation>& matrix);
		static EnumStatusCode setEUInformationMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EUInformation* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// TimeZone access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getTimeZone(const ValueStruct* pValueStruct, TimeZone& target);
		static TimeZone getTimeZone(const ValueStruct* pValueStruct);
		static EnumStatusCode setTimeZone(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getTimeZoneArray(const ValueStruct* pValueStruct, std::vector<TimeZone>& arrayTimeZone);
		static std::vector<TimeZone> getTimeZoneArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setTimeZoneArray(ValueStruct* pValueStruct, const std::vector<TimeZone>& arrayTimeZone);
		static EnumStatusCode getTimeZoneMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<TimeZone>& matrix);
		static EnumStatusCode setTimeZoneMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const TimeZone* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// Argument access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getArgument(const ValueStruct* pValueStruct, Argument& target);
		static Argument getArgument(const ValueStruct* pValueStruct);
		static EnumStatusCode setArgument(ValueStruct* pValueStruct, const IArgument* pArgument);
		static EnumStatusCode getArgumentArray(const ValueStruct* pValueStruct, std::vector<Argument>& arrayArgument);
		static std::vector<Argument> getArgumentArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setArgumentArray(ValueStruct* pValueStruct, const std::vector<Argument>& arrayArgument);
		static EnumStatusCode getArgumentMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<Argument>& matrix);
		static EnumStatusCode setArgumentMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const Argument* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// Range access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getRange(const ValueStruct* pValueStruct, Range& target);
		static Range getRange(const ValueStruct* pValueStruct);
		static EnumStatusCode setRange(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getRangeArray(const ValueStruct* pValueStruct, std::vector<Range>& arrayRange);
		static std::vector<Range> getRangeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setRangeArray(ValueStruct* pValueStruct, const std::vector<Range>& arrayRange);
		static EnumStatusCode getRangeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<Range>& matrix);
		static EnumStatusCode setRangeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const Range* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ReferenceDescription access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getReferenceDescription(const ValueStruct* pValueStruct, ReferenceDescription& target);
		static ReferenceDescription getReferenceDescription(const ValueStruct* pValueStruct);
		static EnumStatusCode setReferenceDescription(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getReferenceDescriptionArray(const ValueStruct* pValueStruct, std::vector<ReferenceDescription>& arrayReferenceDescription);
		static std::vector<ReferenceDescription> getReferenceDescriptionArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setReferenceDescriptionArray(ValueStruct* pValueStruct, const std::vector<ReferenceDescription>& arrayReferenceDescription);
		static EnumStatusCode getReferenceDescriptionMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ReferenceDescription>& matrix);
		static EnumStatusCode setReferenceDescriptionMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ReferenceDescription* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ApplicationDescription access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getApplicationDescription(const ValueStruct* pValueStruct, ApplicationDescription& target);
		static ApplicationDescription getApplicationDescription(const ValueStruct* pValueStruct);
		static EnumStatusCode setApplicationDescription(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getApplicationDescriptionArray(const ValueStruct* pValueStruct, std::vector<ApplicationDescription>& arrayApplicationDescription);
		static std::vector<ApplicationDescription> getApplicationDescriptionArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setApplicationDescriptionArray(ValueStruct* pValueStruct, const std::vector<ApplicationDescription>& arrayApplicationDescription);
		static EnumStatusCode getApplicationDescriptionMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ApplicationDescription>& matrix);
		static EnumStatusCode setApplicationDescriptionMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ApplicationDescription* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ServerDiagnosticsSummaryDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getServerDiagnosticsSummaryDataType(const ValueStruct* pValueStruct, ServerDiagnosticsSummaryDataType& target);
		static ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setServerDiagnosticsSummaryDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		static std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		static EnumStatusCode getServerDiagnosticsSummaryDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ServerDiagnosticsSummaryDataType>& matrix);
		static EnumStatusCode setServerDiagnosticsSummaryDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ServerDiagnosticsSummaryDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// SubscriptionDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getSubscriptionDiagnosticsDataType(const ValueStruct* pValueStruct, SubscriptionDiagnosticsDataType& target);
		static SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setSubscriptionDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		static std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		static EnumStatusCode getSubscriptionDiagnosticsDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<SubscriptionDiagnosticsDataType>& matrix);
		static EnumStatusCode setSubscriptionDiagnosticsDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const SubscriptionDiagnosticsDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// SessionDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getSessionDiagnosticsDataType(const ValueStruct* pValueStruct, SessionDiagnosticsDataType& target);
		static SessionDiagnosticsDataType getSessionDiagnosticsDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setSessionDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getSessionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		static std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setSessionDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		static EnumStatusCode getSessionDiagnosticsDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<SessionDiagnosticsDataType>& matrix);
		static EnumStatusCode setSessionDiagnosticsDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const SessionDiagnosticsDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// SessionSecurityDiagnosticsDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getSessionSecurityDiagnosticsDataType(const ValueStruct* pValueStruct, SessionSecurityDiagnosticsDataType& target);
		static SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setSessionSecurityDiagnosticsDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(const ValueStruct* pValueStruct, std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		static std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(ValueStruct* pValueStruct, const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		static EnumStatusCode getSessionSecurityDiagnosticsDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<SessionSecurityDiagnosticsDataType>& matrix);
		static EnumStatusCode setSessionSecurityDiagnosticsDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const SessionSecurityDiagnosticsDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ServiceCounterDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getServiceCounterDataType(const ValueStruct* pValueStruct, ServiceCounterDataType& target);
		static ServiceCounterDataType getServiceCounterDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setServiceCounterDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getServiceCounterDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		static std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setServiceCounterDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		static EnumStatusCode getServiceCounterDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ServiceCounterDataType>& matrix);
		static EnumStatusCode setServiceCounterDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ServiceCounterDataType* matrix);
#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// SemanticChangeStructureDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getSemanticChangeStructureDataType(const ValueStruct* pValueStruct, SemanticChangeStructureDataType& target);
		static SemanticChangeStructureDataType getSemanticChangeStructureDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setSemanticChangeStructureDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getSemanticChangeStructureDataTypeArray(const ValueStruct* pValueStruct, std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		static std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setSemanticChangeStructureDataTypeArray(ValueStruct* pValueStruct, const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		static EnumStatusCode getSemanticChangeStructureDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<SemanticChangeStructureDataType>& matrix);
		static EnumStatusCode setSemanticChangeStructureDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const SemanticChangeStructureDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// ModelChangeStructureDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getModelChangeStructureDataType(const ValueStruct* pValueStruct, ModelChangeStructureDataType& target);
		static ModelChangeStructureDataType getModelChangeStructureDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setModelChangeStructureDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getModelChangeStructureDataTypeArray(const ValueStruct* pValueStruct, std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
		static std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setModelChangeStructureDataTypeArray(ValueStruct* pValueStruct, const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
		static EnumStatusCode getModelChangeStructureDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ModelChangeStructureDataType>& matrix);
		static EnumStatusCode setModelChangeStructureDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ModelChangeStructureDataType* matrix);
#endif
		////////////////////////////////////////////////////////////////////////////////
		// UserIdentityToken access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getUserIdentityToken(const ValueStruct* pValueStruct, UserIdentityToken& target);
		static UserIdentityToken getUserIdentityToken(const ValueStruct* pValueStruct);
		static EnumStatusCode setUserIdentityToken(ValueStruct* pValueStruct, UserIdentityTokenStruct* pIntHandle);
		static EnumStatusCode getUserIdentityTokenArray(const ValueStruct* pValueStruct, std::vector<UserIdentityToken>& arrayUserIdentityToken);
		static std::vector<UserIdentityToken> getUserIdentityTokenArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setUserIdentityTokenArray(ValueStruct* pValueStruct, const std::vector<UserIdentityToken>& arrayUserIdentityToken);
		static EnumStatusCode getUserIdentityTokenMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<UserIdentityToken>& matrix);
		static EnumStatusCode setUserIdentityTokenMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const UserIdentityToken* matrix);
		////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////
		// SignedSoftwareCertificate access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getSignedSoftwareCertificate(const ValueStruct* pValueStruct, SignedSoftwareCertificate& target);
		static SignedSoftwareCertificate getSignedSoftwareCertificate(const ValueStruct* pValueStruct);
		static EnumStatusCode setSignedSoftwareCertificate(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getSignedSoftwareCertificateArray(const ValueStruct* pValueStruct, std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		static std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setSignedSoftwareCertificateArray(ValueStruct* pValueStruct, const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		static EnumStatusCode setSignedSoftwareCertificateArray(ValueStruct* pValueStruct, const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);
		static EnumStatusCode getSignedSoftwareCertificateMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<SignedSoftwareCertificate>& matrix);
		static EnumStatusCode setSignedSoftwareCertificateMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const SignedSoftwareCertificate* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// BuildInfo access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getBuildInfo(const ValueStruct* pValueStruct, BuildInfo& target);
		static BuildInfo getBuildInfo(const ValueStruct* pValueStruct);
		static EnumStatusCode setBuildInfo(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getBuildInfoArray(const ValueStruct* pValueStruct, std::vector<BuildInfo>& arrayBuildInfo);
		static std::vector<BuildInfo> getBuildInfoArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setBuildInfoArray(ValueStruct* pValueStruct, const std::vector<BuildInfo>& arrayBuildInfo);
		static EnumStatusCode setBuildInfoArray(ValueStruct* pValueStruct, const std::vector<const IBuildInfo*>& arrayBuildInfo);
		static EnumStatusCode getBuildInfoMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<BuildInfo>& matrix);
		static EnumStatusCode setBuildInfoMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const BuildInfo* matrix);
#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// EventFilter access functions
		////////////////////////////////////////////////////////////////////////////////
		// single get EventFilter function with result code
		static EnumStatusCode getEventFilter(const ValueStruct* pValueStruct, EventFilter& target);
		// single get EventFilter function with direct return
		static EventFilter getEventFilter(const ValueStruct* pValueStruct);
		static EnumStatusCode setEventFilter(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getEventFilterArray(const ValueStruct* pValueStruct, std::vector<EventFilter>& arrayEventFilter);
		static std::vector<EventFilter> getEventFilterArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setEventFilterArray(ValueStruct* pValueStruct, const std::vector<EventFilter>& arrayEventFilter);
		static EnumStatusCode setEventFilterArray(ValueStruct* pValueStruct, const std::vector<const IEventFilter*>& arrayEventFilter);
		static EnumStatusCode getEventFilterMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EventFilter>& matrix);
		static EnumStatusCode setEventFilterMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EventFilter* matrix);
#endif
		////////////////////////////////////////////////////////////////////////////////
		// ServerStatusDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getServerStatusDataType(const ValueStruct* pValueStruct, ServerStatusDataType& target);
		static ServerStatusDataType getServerStatusDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setServerStatusDataType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getServerStatusDataTypeArray(const ValueStruct* pValueStruct, std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		static std::vector<ServerStatusDataType> getServerStatusDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setServerStatusDataTypeArray(ValueStruct* pValueStruct, const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		static EnumStatusCode setServerStatusDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IServerStatusDataType*>& arrayServerStatusDataType);
		static EnumStatusCode getServerStatusDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ServerStatusDataType>& matrix);
		static EnumStatusCode setServerStatusDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ServerStatusDataType* matrix);
		////////////////////////////////////////////////////////////////////////////////
		// EnumValueType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getEnumValueType(const ValueStruct* pValueStruct, EnumValueType& target);
		static EnumValueType getEnumValueType(const ValueStruct* pValueStruct);
		static EnumStatusCode setEnumValueType(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getEnumValueTypeArray(const ValueStruct* pValueStruct, std::vector<EnumValueType>& arrayEnumValueType);
		static std::vector<EnumValueType> getEnumValueTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setEnumValueTypeArray(ValueStruct* pValueStruct, const std::vector<EnumValueType>& arrayEnumValueType);
		static EnumStatusCode setEnumValueTypeArray(ValueStruct* pValueStruct, const std::vector<const IEnumValueType*>& arrayEnumValueType);
		static EnumStatusCode getEnumValueTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EnumValueType>& matrix);
		static EnumStatusCode setEnumValueTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EnumValueType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// KeyValuePair access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getKeyValuePair(const ValueStruct* pValueStruct, KeyValuePair& target);
		static KeyValuePair getKeyValuePair(const ValueStruct* pValueStruct);
		static EnumStatusCode setKeyValuePair(ValueStruct* pValueStruct, KeyValuePairStruct* pSource);
		static EnumStatusCode getKeyValuePairArray(const ValueStruct* pValueStruct, std::vector<KeyValuePair>& arrayKeyValuePair);
		static std::vector<KeyValuePair> getKeyValuePairArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setKeyValuePairArray(ValueStruct* pValueStruct, const std::vector<KeyValuePair>& arrayKeyValuePair);
		static EnumStatusCode setKeyValuePairArray(ValueStruct* pValueStruct, const std::vector<const IKeyValuePair*>& arrayKeyValuePair);
		static EnumStatusCode getKeyValuePairMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<KeyValuePair>& matrix);
		static EnumStatusCode setKeyValuePairMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const KeyValuePair* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// ConfigurationVersionDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getConfigurationVersionDataType(const ValueStruct* pValueStruct, ConfigurationVersionDataType& target);
		static ConfigurationVersionDataType getConfigurationVersionDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setConfigurationVersionDataType(ValueStruct* pValueStruct, ConfigurationVersionDataTypeStruct* pSource);
		static EnumStatusCode getConfigurationVersionDataTypeArray(const ValueStruct* pValueStruct, std::vector<ConfigurationVersionDataType>& arrayConfigurationVersionDataType);
		static std::vector<ConfigurationVersionDataType> getConfigurationVersionDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setConfigurationVersionDataTypeArray(ValueStruct* pValueStruct, const std::vector<ConfigurationVersionDataType>& arrayConfigurationVersionDataType);
		static EnumStatusCode setConfigurationVersionDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IConfigurationVersionDataType*>& arrayConfigurationVersionDataType);
		static EnumStatusCode getConfigurationVersionDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ConfigurationVersionDataType>& matrix);
		static EnumStatusCode setConfigurationVersionDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ConfigurationVersionDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// DataSetMetaDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getDataSetMetaDataType(const ValueStruct* pValueStruct, DataSetMetaDataType& target);
		static DataSetMetaDataType getDataSetMetaDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetMetaDataType(ValueStruct* pValueStruct, DataSetMetaDataTypeStruct* pSource);
		static EnumStatusCode getDataSetMetaDataTypeArray(const ValueStruct* pValueStruct, std::vector<DataSetMetaDataType>& arrayDataSetMetaDataType);
		static std::vector<DataSetMetaDataType> getDataSetMetaDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetMetaDataTypeArray(ValueStruct* pValueStruct, const std::vector<DataSetMetaDataType>& arrayDataSetMetaDataType);
		static EnumStatusCode setDataSetMetaDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IDataSetMetaDataType*>& arrayDataSetMetaDataType);
		static EnumStatusCode getDataSetMetaDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetMetaDataType>& matrix);
		static EnumStatusCode setDataSetMetaDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DataSetMetaDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// DataSetReaderDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getDataSetReaderDataType(const ValueStruct* pValueStruct, DataSetReaderDataType& target);
		static DataSetReaderDataType getDataSetReaderDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetReaderDataType(ValueStruct* pValueStruct, DataSetReaderDataTypeStruct* pSource);
		static EnumStatusCode getDataSetReaderDataTypeArray(const ValueStruct* pValueStruct, std::vector<DataSetReaderDataType>& arrayDataSetReaderDataType);
		static std::vector<DataSetReaderDataType> getDataSetReaderDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetReaderDataTypeArray(ValueStruct* pValueStruct, const std::vector<DataSetReaderDataType>& arrayDataSetReaderDataType);
		static EnumStatusCode setDataSetReaderDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IDataSetReaderDataType*>& arrayDataSetReaderDataType);
		static EnumStatusCode getDataSetReaderDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetReaderDataType>& matrix);
		static EnumStatusCode setDataSetReaderDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DataSetReaderDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// DataSetWriterDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getDataSetWriterDataType(const ValueStruct* pValueStruct, DataSetWriterDataType& target);
		static DataSetWriterDataType getDataSetWriterDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetWriterDataType(ValueStruct* pValueStruct, DataSetWriterDataTypeStruct* pSource);
		static EnumStatusCode getDataSetWriterDataTypeArray(const ValueStruct* pValueStruct, std::vector<DataSetWriterDataType>& arrayDataSetWriterDataType);
		static std::vector<DataSetWriterDataType> getDataSetWriterDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDataSetWriterDataTypeArray(ValueStruct* pValueStruct, const std::vector<DataSetWriterDataType>& arrayDataSetWriterDataType);
		static EnumStatusCode setDataSetWriterDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IDataSetWriterDataType*>& arrayDataSetWriterDataType);
		static EnumStatusCode getDataSetWriterDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetWriterDataType>& matrix);
		static EnumStatusCode setDataSetWriterDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DataSetWriterDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// EnumDefinition access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getEnumDefinition(const ValueStruct* pValueStruct, EnumDefinition& target);
		static EnumDefinition getEnumDefinition(const ValueStruct* pValueStruct);
		static EnumStatusCode setEnumDefinition(ValueStruct* pValueStruct, EnumDefinitionStruct* pSource);
		static EnumStatusCode getEnumDefinitionArray(const ValueStruct* pValueStruct, std::vector<EnumDefinition>& arrayEnumDefinition);
		static std::vector<EnumDefinition> getEnumDefinitionArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setEnumDefinitionArray(ValueStruct* pValueStruct, const std::vector<EnumDefinition>& arrayEnumDefinition);
		static EnumStatusCode setEnumDefinitionArray(ValueStruct* pValueStruct, const std::vector<const IEnumDefinition*>& arrayEnumDefinition);
		static EnumStatusCode getEnumDefinitionMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EnumDefinition>& matrix);
		static EnumStatusCode setEnumDefinitionMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EnumDefinition* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// FieldTargetDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getFieldTargetDataType(const ValueStruct* pValueStruct, FieldTargetDataType& target);
		static FieldTargetDataType getFieldTargetDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setFieldTargetDataType(ValueStruct* pValueStruct, FieldTargetDataTypeStruct* pSource);
		static EnumStatusCode getFieldTargetDataTypeArray(const ValueStruct* pValueStruct, std::vector<FieldTargetDataType>& arrayFieldTargetDataType);
		static std::vector<FieldTargetDataType> getFieldTargetDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setFieldTargetDataTypeArray(ValueStruct* pValueStruct, const std::vector<FieldTargetDataType>& arrayFieldTargetDataType);
		static EnumStatusCode setFieldTargetDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IFieldTargetDataType*>& arrayFieldTargetDataType);
		static EnumStatusCode getFieldTargetDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<FieldTargetDataType>& matrix);
		static EnumStatusCode setFieldTargetDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const FieldTargetDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// PubSubConnectionDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getPubSubConnectionDataType(const ValueStruct* pValueStruct, PubSubConnectionDataType& target);
		static PubSubConnectionDataType getPubSubConnectionDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setPubSubConnectionDataType(ValueStruct* pValueStruct, PubSubConnectionDataTypeStruct* pSource);
		static EnumStatusCode getPubSubConnectionDataTypeArray(const ValueStruct* pValueStruct, std::vector<PubSubConnectionDataType>& arrayPubSubConnectionDataType);
		static std::vector<PubSubConnectionDataType> getPubSubConnectionDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setPubSubConnectionDataTypeArray(ValueStruct* pValueStruct, const std::vector<PubSubConnectionDataType>& arrayPubSubConnectionDataType);
		static EnumStatusCode setPubSubConnectionDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IPubSubConnectionDataType*>& arrayPubSubConnectionDataType);
		static EnumStatusCode getPubSubConnectionDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<PubSubConnectionDataType>& matrix);
		static EnumStatusCode setPubSubConnectionDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const PubSubConnectionDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// ReaderGroupDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getReaderGroupDataType(const ValueStruct* pValueStruct, ReaderGroupDataType& target);
		static ReaderGroupDataType getReaderGroupDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setReaderGroupDataType(ValueStruct* pValueStruct, ReaderGroupDataTypeStruct* pSource);
		static EnumStatusCode getReaderGroupDataTypeArray(const ValueStruct* pValueStruct, std::vector<ReaderGroupDataType>& arrayReaderGroupDataType);
		static std::vector<ReaderGroupDataType> getReaderGroupDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setReaderGroupDataTypeArray(ValueStruct* pValueStruct, const std::vector<ReaderGroupDataType>& arrayReaderGroupDataType);
		static EnumStatusCode setReaderGroupDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IReaderGroupDataType*>& arrayReaderGroupDataType);
		static EnumStatusCode getReaderGroupDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ReaderGroupDataType>& matrix);
		static EnumStatusCode setReaderGroupDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ReaderGroupDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// RolePermissionType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getRolePermissionType(const ValueStruct* pValueStruct, RolePermissionType& target);
		static RolePermissionType getRolePermissionType(const ValueStruct* pValueStruct);
		static EnumStatusCode setRolePermissionType(ValueStruct* pValueStruct, RolePermissionTypeStruct* pSource);
		static EnumStatusCode getRolePermissionTypeArray(const ValueStruct* pValueStruct, std::vector<RolePermissionType>& arrayRolePermissionType);
		static std::vector<RolePermissionType> getRolePermissionTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setRolePermissionTypeArray(ValueStruct* pValueStruct, const std::vector<RolePermissionType>& arrayRolePermissionType);
		static EnumStatusCode setRolePermissionTypeArray(ValueStruct* pValueStruct, const std::vector<const IRolePermissionType*>& arrayRolePermissionType);
		static EnumStatusCode getRolePermissionTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<RolePermissionType>& matrix);
		static EnumStatusCode setRolePermissionTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const RolePermissionType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// StructureDefinition access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getStructureDefinition(const ValueStruct* pValueStruct, StructureDefinition& target);
		static StructureDefinition getStructureDefinition(const ValueStruct* pValueStruct);
		static EnumStatusCode setStructureDefinition(ValueStruct* pValueStruct, StructureDefinitionStruct* pSource);
		static EnumStatusCode getStructureDefinitionArray(const ValueStruct* pValueStruct, std::vector<StructureDefinition>& arrayStructureDefinition);
		static std::vector<StructureDefinition> getStructureDefinitionArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setStructureDefinitionArray(ValueStruct* pValueStruct, const std::vector<StructureDefinition>& arrayStructureDefinition);
		static EnumStatusCode setStructureDefinitionArray(ValueStruct* pValueStruct, const std::vector<const IStructureDefinition*>& arrayStructureDefinition);
		static EnumStatusCode getStructureDefinitionMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<StructureDefinition>& matrix);
		static EnumStatusCode setStructureDefinitionMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const StructureDefinition* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// WriterGroupDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getWriterGroupDataType(const ValueStruct* pValueStruct, WriterGroupDataType& target);
		static WriterGroupDataType getWriterGroupDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setWriterGroupDataType(ValueStruct* pValueStruct, WriterGroupDataTypeStruct* pSource);
		static EnumStatusCode getWriterGroupDataTypeArray(const ValueStruct* pValueStruct, std::vector<WriterGroupDataType>& arrayWriterGroupDataType);
		static std::vector<WriterGroupDataType> getWriterGroupDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setWriterGroupDataTypeArray(ValueStruct* pValueStruct, const std::vector<WriterGroupDataType>& arrayWriterGroupDataType);
		static EnumStatusCode setWriterGroupDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IWriterGroupDataType*>& arrayWriterGroupDataType);
		static EnumStatusCode getWriterGroupDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<WriterGroupDataType>& matrix);
		static EnumStatusCode setWriterGroupDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const WriterGroupDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// PublishedVariableDataType access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getPublishedVariableDataType(const ValueStruct* pValueStruct, PublishedVariableDataType& target);
		static PublishedVariableDataType getPublishedVariableDataType(const ValueStruct* pValueStruct);
		static EnumStatusCode setPublishedVariableDataType(ValueStruct* pValueStruct, PublishedVariableDataTypeStruct* pSource);
		static EnumStatusCode getPublishedVariableDataTypeArray(const ValueStruct* pValueStruct, std::vector<PublishedVariableDataType>& arrayPublishedVariableDataType);
		static std::vector<PublishedVariableDataType> getPublishedVariableDataTypeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setPublishedVariableDataTypeArray(ValueStruct* pValueStruct, const std::vector<PublishedVariableDataType>& arrayPublishedVariableDataType);
		static EnumStatusCode setPublishedVariableDataTypeArray(ValueStruct* pValueStruct, const std::vector<const IPublishedVariableDataType*>& arrayPublishedVariableDataType);
		static EnumStatusCode getPublishedVariableDataTypeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<PublishedVariableDataType>& matrix);
		static EnumStatusCode setPublishedVariableDataTypeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const PublishedVariableDataType* matrix);

		////////////////////////////////////////////////////////////////////////////////
		// EndpointDescription access functions
		////////////////////////////////////////////////////////////////////////////////
		static EnumStatusCode getEndpointDescription(const ValueStruct* pValueStruct, EndpointDescription& target);
		static EndpointDescription getEndpointDescription(const ValueStruct* pValueStruct);
		static EnumStatusCode setEndpointDescription(ValueStruct* pValueStruct, EndpointDescriptionStruct* pSource);
		static EnumStatusCode getEndpointDescriptionArray(const ValueStruct* pValueStruct, std::vector<EndpointDescription>& arrayEndpointDescription);
		static std::vector<EndpointDescription> getEndpointDescriptionArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setEndpointDescriptionArray(ValueStruct* pValueStruct, const std::vector<EndpointDescription>& arrayEndpointDescription);
		static EnumStatusCode setEndpointDescriptionArray(ValueStruct* pValueStruct, const std::vector<const IEndpointDescription*>& arrayEndpointDescription);
		static EnumStatusCode getEndpointDescriptionMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EndpointDescription>& matrix);
		static EnumStatusCode setEndpointDescriptionMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EndpointDescription* matrix);
		// NEW_SUPPORTED_DATATYPE - copy the block above and replace tape name

		// primitives
		static EnumStatusCode getBoolean(const ValueStruct* pValueStruct, OTBoolean* pTarget);
		static OTBoolean getBoolean(const ValueStruct* pValueStruct);
		static void setBoolean(ValueStruct* pValueStruct, OTBoolean value);
		static std::vector<OTBoolean> getBooleanArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getBooleanArray(const ValueStruct* pValueStruct, std::vector<OTBoolean>& target);
		static EnumStatusCode setBooleanArray(ValueStruct* pValueStruct, const std::vector<OTBoolean>& arrayBool);
		static EnumStatusCode getBooleanMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTBoolean>& matrix);
		static EnumStatusCode setBooleanMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTBoolean* matrix);

		static EnumStatusCode getInt8(const ValueStruct* pValueStruct, OTInt8* pTarget);
		static OTInt8 getInt8(const ValueStruct* pValueStruct);
		static void setInt8(ValueStruct* pValueStruct, OTInt8 value);
		static std::vector<OTInt8> getInt8Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt8Array(const ValueStruct* pValueStruct, std::vector<OTInt8>& target);
		static EnumStatusCode setInt8Array(ValueStruct* pValueStruct, const std::vector<OTInt8>& arrayInt8);
		static EnumStatusCode getInt8Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt8>& matrix);
		static EnumStatusCode setInt8Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTInt8* matrix);

		static EnumStatusCode getUInt8(const ValueStruct* pValueStruct, OTUInt8* pTarget);
		static OTUInt8 getUInt8(const ValueStruct* pValueStruct);
		static void setUInt8(ValueStruct* pValueStruct, OTUInt8 value);
		static std::vector<OTUInt8> getUInt8Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt8Array(const ValueStruct* pValueStruct, std::vector<OTUInt8>& target);
		static EnumStatusCode setUInt8Array(ValueStruct* pValueStruct, const std::vector<OTUInt8>& arrayUInt8);
		static EnumStatusCode getUInt8Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt8>& matrix);
		static EnumStatusCode setUInt8Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTUInt8* matrix);

		static EnumStatusCode getInt16(const ValueStruct* pValueStruct, OTInt16* pTarget);
		static OTInt16 getInt16(const ValueStruct* pValueStruct);
		static std::vector<OTInt16> getInt16Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt16Array(const ValueStruct* pValueStruct, std::vector<OTInt16>& target);
		static void setInt16(ValueStruct* pValueStruct, OTInt16 value);
		static EnumStatusCode setInt16Array(ValueStruct* pValueStruct, const std::vector<OTInt16>& arrayInt16);
		static EnumStatusCode getInt16Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt16>& matrix);
		static EnumStatusCode setInt16Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTInt16* matrix);

		static EnumStatusCode getUInt16(const ValueStruct* pValueStruct, OTUInt16* pTarget);
		static OTUInt16 getUInt16(const ValueStruct* pValueStruct);
		static void setUInt16(ValueStruct* pValueStruct, OTUInt16 value);
		static std::vector<OTUInt16> getUInt16Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt16Array(const ValueStruct* pValueStruct, std::vector<OTUInt16>& target);
		static EnumStatusCode setUInt16Array(ValueStruct* pValueStruct, const std::vector<OTUInt16>& arrayUInt16);
		static EnumStatusCode getUInt16Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt16>& matrix);
		static EnumStatusCode setUInt16Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTUInt16* matrix);

		static EnumStatusCode getInt32(const ValueStruct* pValueStruct, OTInt32* pTarget);
		static OTInt32 getInt32(const ValueStruct* pValueStruct);
		static void setInt32(ValueStruct* pValueStruct, OTInt32 value);
		static std::vector<OTInt32> getInt32Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt32Array(const ValueStruct* pValueStruct, std::vector<OTInt32>& target);
		static EnumStatusCode setInt32Array(ValueStruct* pValueStruct, const std::vector<OTInt32>& arrayInt32);
		static EnumStatusCode getInt32Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt32>& matrix);
		static EnumStatusCode setInt32Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTInt32* matrix);

		static EnumStatusCode getUInt32(const ValueStruct* pValueStruct, OTUInt32* pTarget);
		static OTUInt32 getUInt32(const ValueStruct* pValueStruct);
		static void setUInt32(ValueStruct* pValueStruct, OTUInt32 value);
		static std::vector<OTUInt32> getUInt32Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt32Array(const ValueStruct* pValueStruct, std::vector<OTUInt32>& target);
		static EnumStatusCode setUInt32Array(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayUInt32);
		static EnumStatusCode getUInt32Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt32>& matrix);
		static EnumStatusCode setUInt32Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTUInt32* matrix);

		static EnumStatusCode getInt64(const ValueStruct* pValueStruct, OTInt64* pTarget);
		static OTInt64 getInt64(const ValueStruct* pValueStruct);
		static void setInt64(ValueStruct* pValueStruct, OTInt64 value);
		static std::vector<OTInt64> getInt64Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getInt64Array(const ValueStruct* pValueStruct, std::vector<OTInt64>& target);
		static EnumStatusCode setInt64Array(ValueStruct* pValueStruct, const std::vector<OTInt64>& arrayInt64);
		static EnumStatusCode getInt64Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt64>& matrix);
		static EnumStatusCode setInt64Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTInt64* matrix);

		static EnumStatusCode getUInt64(const ValueStruct* pValueStruct, OTUInt64* pTarget);
		static OTUInt64 getUInt64(const ValueStruct* pValueStruct);
		static void setUInt64(ValueStruct* pValueStruct, OTUInt64 value);
		static std::vector<OTUInt64> getUInt64Array(const ValueStruct* pValueStruct);
		static EnumStatusCode getUInt64Array(const ValueStruct* pValueStruct, std::vector<OTUInt64>& target);
		static EnumStatusCode setUInt64Array(ValueStruct* pValueStruct, const std::vector<OTUInt64>& arrayUInt64);
		static EnumStatusCode getUInt64Matrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt64>& matrix);
		static EnumStatusCode setUInt64Matrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTUInt64* matrix);

		static EnumStatusCode getFloat(const ValueStruct* pValueStruct, OTFloat* pTarget);
		static OTFloat getFloat(const ValueStruct* pValueStruct);
		static void setFloat(ValueStruct* pValueStruct, OTFloat value);
		static std::vector<OTFloat> getFloatArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getFloatArray(const ValueStruct* pValueStruct, std::vector<OTFloat>& target);
		static EnumStatusCode setFloatArray(ValueStruct* pValueStruct, const std::vector<OTFloat>& arrayFloat);
		static EnumStatusCode getFloatMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTFloat>& matrix);
		static EnumStatusCode setFloatMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTFloat* matrix);

		static EnumStatusCode getDouble(const ValueStruct* pValueStruct, OTDouble* pTarget);
		static OTDouble getDouble(const ValueStruct* pValueStruct);
		static void setDouble(ValueStruct* pValueStruct, OTDouble value);
		static std::vector<OTDouble> getDoubleArray(const ValueStruct* pValueStruct);
		static EnumStatusCode getDoubleArray(const ValueStruct* pValueStruct, std::vector<OTDouble>& target);
		static EnumStatusCode setDoubleArray(ValueStruct* pValueStruct, const std::vector<OTDouble>& arrayDouble);
		static EnumStatusCode getDoubleMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<OTDouble>& matrix);
		static EnumStatusCode setDoubleMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const OTDouble* matrix);

		// structures
		static EnumStatusCode getStatusCode(const ValueStruct* pValueStruct, EnumStatusCode* pTarget);
		static EnumStatusCode getStatusCode(const ValueStruct* pValueStruct);
		static void setStatusCode(ValueStruct* pValueStruct, EnumStatusCode statusCode);
		static EnumStatusCode getStatusCodeArray(const ValueStruct* pValueStruct, std::vector<EnumStatusCode>& arrayStatusCode);
		static std::vector<EnumStatusCode> getStatusCodeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setStatusCodeArray(ValueStruct* pValueStruct, const std::vector<EnumStatusCode>& arrayStatusCode);
		static EnumStatusCode getStatusCodeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<EnumStatusCode>& matrix);
		static EnumStatusCode setStatusCodeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const EnumStatusCode* matrix);

		static EnumStatusCode getString(const ValueStruct* pValueStruct, tstring& target);
		static tstring getString(const ValueStruct* pValueStruct);
		static EnumStatusCode setString(ValueStruct* pValueStruct, const tstring& value);
		static EnumStatusCode getStringArray(const ValueStruct* pValueStruct, std::vector<tstring>& arrayString);
		static std::vector<tstring> getStringArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setStringArray(ValueStruct* pValueStruct, const std::vector<tstring>& arrayString);
		static EnumStatusCode getStringMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<tstring>& matrix);
		static EnumStatusCode setStringMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const tstring* matrix);

		static DateTime getDateTime(const ValueStruct* pValueStruct);
		static EnumStatusCode getDateTime(const ValueStruct* pValueStruct, DateTime& target);
		static EnumStatusCode setDateTime(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getDateTimeArray(const ValueStruct* pValueStruct, std::vector<DateTime>& arrayDateTime);
		static std::vector<DateTime> getDateTimeArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setDateTimeArray(ValueStruct* pValueStruct, const std::vector<DateTime>& arrayDateTime);
		static EnumStatusCode getDateTimeMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<DateTime>& matrix);
		static EnumStatusCode setDateTimeMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const DateTime* matrix);

		static Guid getGuid(const ValueStruct* pValueStruct);
		static EnumStatusCode getGuid(const ValueStruct* pValueStruct, Guid& target);
		static EnumStatusCode setGuid(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getGuidArray(const ValueStruct* pValueStruct, std::vector<Guid>& arrayGuid);
		static std::vector<Guid> getGuidArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setGuidArray(ValueStruct* pValueStruct, const std::vector<Guid>& arrayGuid);
		static EnumStatusCode getGuidMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<Guid>& matrix);
		static EnumStatusCode setGuidMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const Guid* matrix);

		static ByteString getByteString(const ValueStruct* pValueStruct);
		static EnumStatusCode getByteString(const ValueStruct* pValueStruct, ByteString& target);
		static EnumStatusCode setByteString(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getByteStringArray(const ValueStruct* pValueStruct, std::vector<ByteString>& arrayByteString);
		static std::vector<ByteString> getByteStringArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setByteStringArray(ValueStruct* pValueStruct, const std::vector<ByteString>& arrayByteString);
		static EnumStatusCode getByteStringMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& matrix);
		static EnumStatusCode setByteStringMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const ByteString* matrix);

		static XmlElement getXmlElement(const ValueStruct* pValueStruct);
		static EnumStatusCode getXmlElement(const ValueStruct* pValueStruct, XmlElement& target);
		static EnumStatusCode setXmlElement(ValueStruct* pValueStruct, const XmlElement& xmlElement);
		static EnumStatusCode getXmlElementArray(const ValueStruct* pValueStruct, std::vector<XmlElement>& arrayByteString);
		static std::vector<XmlElement> getXmlElementArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setXmlElementArray(ValueStruct* pValueStruct, const std::vector<XmlElement>& arrayXmlElement);
		static EnumStatusCode getXmlElementMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<XmlElement>& matrix);
		static EnumStatusCode setXmlElementMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const XmlElement* matrix);

		static EnumStatusCode getValue(const ValueStruct* pValueStruct, Value& target);
		static EnumStatusCode setValue(ValueStruct* pValueStruct, void* pIntHandle);
		static EnumStatusCode getValueArray(const ValueStruct* pValueStruct, std::vector<Value>& arrayValue);
		static std::vector<Value> getValueArray(const ValueStruct* pValueStruct);
		static EnumStatusCode setValueArray(ValueStruct* pValueStruct, const std::vector<Value>& arrayValue);
		static EnumStatusCode getValueMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& arrayDimensions, std::vector<Value>& matrix);
		static EnumStatusCode setValueMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const Value* matrix);

		static EnumStatusCode getStructuredValue(const ValueStruct* pValueStruct, StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<Value>& fieldValues);
		static EnumStatusCode setStructuredValue(ValueStruct* pValueStruct, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);
		static EnumStatusCode getStructuredValueArray(const ValueStruct* pValueStruct, EnumValueArrayType expectedArrayType,
			StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<std::vector<Value> >& fieldValues, std::vector<OTUInt32>* pDimensions);
		static EnumStatusCode setStructuredValueArray(ValueStruct* pValueStruct, EnumValueArrayType arrayType,
			StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues, const std::vector<OTUInt32>* pDimensions);

		static EnumStatusCode getComplexValueRawArray(const ValueStruct* pValueStruct, EnumValueArrayType expectedArrayType, NodeId& encodingId, std::vector<ByteString>& bodies, std::vector<OTUInt32>* pDimensions);
		static EnumStatusCode setComplexValueRawArray(ValueStruct* pValueStruct, EnumValueArrayType arrayType, const INodeId& encodingId, const std::vector<ByteString>& bodies, const std::vector<OTUInt32>* pDimensions);

		static OTUInt32 getFlatLength(OTUInt32 noOfDimensions, const OTUInt32* pDimensions)
		{
			OTUInt32 result = 1;
			if(noOfDimensions == 0)
			{
				return 0;
			}
			for(size_t i=0; i< noOfDimensions; i++)
			{
				result *= pDimensions[i];
			}
			return result;
		}
		static OTUInt32 getFlatLength(const std::vector<OTUInt32>& arrayDimensions)
		{
			OTUInt32 result = 1;
			if(arrayDimensions.size() == 0)
			{
				return 0;
			}
			for(size_t i=0; i< arrayDimensions.size(); i++)
			{
				result *= arrayDimensions[i];
			}
			return result;
		}
		static EnumStatusCode getArrayDimensions(const ValueStruct* pValueStruct, EnumDataTypeId expectedDataType, std::vector<OTUInt32>& arrayDimensions)
		{
			if(pValueStruct &&
				pValueStruct->dataType  == expectedDataType &&
				pValueStruct->arrayType == EnumValueArrayType_Matrix &&
				pValueStruct->value.Matrix)
			{
				arrayDimensions.reserve(pValueStruct->value.Matrix->NoOfDimensions);
				for(OTUInt32 i=0; i<pValueStruct->value.Matrix->NoOfDimensions; i++)
				{
					arrayDimensions.push_back(pValueStruct->value.Matrix->Dimensions[i]);
				}
				return EnumStatusCode_Good;
			}
			else
			{
				return EnumStatusCode_BadInvalidArgument;
			}
		}

		/*! Utility template method for transforming a vector to an array and calling the OT - C
		* ValueStruct comfort method. */
		template <typename T, typename OTFunc>
		static EnumStatusCode setArray(ValueStruct* pValueStruct, const std::vector<T>& arrayT, OTFunc otFunc)
		{
			T* local_array = (T*)OTAllocateMemoryInitialized(sizeof(T) * arrayT.size());
			if(local_array == NULL)
			{
				return EnumStatusCode_BadInvalidArgument;
			}
			//transform the std::vector to array
			for(OTUInt32 i = 0; i < arrayT.size(); i++)
			{
				local_array[i] = (T)arrayT[i];
			}
			EnumStatusCode result = otFunc(pValueStruct, local_array, (long)arrayT.size());
			OTFreeMemory(local_array);
			return result;
		}

		/*! Utility template method for calling the OT - C matrix function */
		template <typename T, typename OTFunc>
		static EnumStatusCode setMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, T* matrixValues, OTFunc otFunc)
		{
			if(pValueStruct == NULL ||
				matrixValues == NULL ||
				arrayDimensions.size() == 0)
			{
				return EnumStatusCode_BadInvalidArgument;
			}
			return otFunc(pValueStruct, (OTInt32)arrayDimensions.size(), &arrayDimensions[0], matrixValues);
		}

		template <typename T, typename U, typename OTFunc, typename OTFuncClear, typename OTFuncMatrix>
		static EnumStatusCode setStructMatrix(ValueStruct* pValueStruct, const std::vector<OTUInt32>& arrayDimensions, const T* matrix, OTFunc otFuncSet, OTFuncClear otFuncClear, OTFuncMatrix otFuncSetMatrix)
		{
			if(matrix == NULL)
			{
				return EnumStatusCode_BadInvalidArgument;
			}
			OTUInt32 flatLength = getFlatLength(arrayDimensions);
			U* local_array = (U*)OTAllocateMemoryInitialized(sizeof(U) * flatLength);
			if(local_array == NULL)
			{
				return EnumStatusCode_BadOutOfMemory;
			}
			for(OTUInt32 i = 0; i < flatLength; ++i)
			{
				otFuncSet(&local_array[i], (const U*)matrix[i].getInternHandle());
			}
			EnumStatusCode result = otFuncSetMatrix(pValueStruct, local_array, (OTUInt32)arrayDimensions.size(), (arrayDimensions.size() == 0) ? NULL : &arrayDimensions[0]);
			for(OTUInt32 i = 0; i < flatLength; ++i)
			{
				otFuncClear(&local_array[i]);
			}
			OTFreeMemory(local_array);
			return result;
		}

		/*! Copy the primitive array from a ValueStruct to a std::vector.
		*
		*   @param pValueStruct	The source structure, from where the array is copied
		*   @param arrayT		The target array, where the structures will be copied
		*   @param pArray		The array of the ValueStructure, from where the structures are copied
		*   @return an enum code representing the status of the array copy. */
		template <typename T>
		static EnumStatusCode getPrimitiveArray(const ValueStruct* pValueStruct, std::vector<T>& arrayT, T pArray[])
		{
			long length = pValueStruct->value.Array.Length;
			arrayT.reserve(length);
			for(int i = 0; i < length; i++)
			{
				arrayT.push_back(pArray[i]);
			}
			return EnumStatusCode_Good;
		}

		/*! Copy the primitive array from a ValueStruct to a std::vector.
		*
		* @param pValueStruct				The source structure, from where the matrix is copied
		* @param targetArrayDimensions		The array dimensions, that will be filled
		* @param targetMatrix				The matrix values, that will be filled
		* @return an enum code representing	The status of the matrix copy. */
		template <typename T, EnumDataTypeId ID>
		static EnumStatusCode getPrimitiveMatrix(const ValueStruct* pValueStruct, std::vector<OTUInt32>& targetArrayDimensions, std::vector<T>& targetMatrix)
		{
			targetArrayDimensions.clear();
			targetMatrix.clear();

			if(pValueStruct
				&& pValueStruct->dataType  == ID
				&& pValueStruct->arrayType == EnumValueArrayType_Matrix)
			{
				OTUInt32 flatLength = 1;
				targetArrayDimensions.reserve(pValueStruct->value.Matrix->NoOfDimensions);
				for(OTUInt32 i=0; i < pValueStruct->value.Matrix->NoOfDimensions; i++)
				{
					targetArrayDimensions.push_back(pValueStruct->value.Matrix->Dimensions[i]);
					flatLength *= pValueStruct->value.Matrix->Dimensions[i];
				}
				targetMatrix.reserve(flatLength);
				for(OTUInt32 i = 0; i < flatLength; i++)
				{
					targetMatrix.push_back(((T*)(pValueStruct->value.Matrix->Value.Array))[i]);
				}
				return EnumStatusCode_Good;
			}
			else
			{
				return EnumStatusCode_BadInvalidArgument;
			}
		}

		/*! Copy the array from a ValueStruct to a std::vector.
		*
		*   @param pValueStruct	The source structure, from where the array is copied
		*   @param arrayT		The target array, where the structures will be copied
		*   @param ofFunc		The exported OT method, which copy the OT structure from source to target
		*   @param pArray		The array of the ValueStructure, from where the structures are copied
		*   @return an enum code representing the status of the array copy. */
		template <class T, class V, typename OTFunc>
		static EnumStatusCode getArray(const ValueStruct* pValueStruct, std::vector<T>& arrayT, OTFunc otFunc, V pArray[])
		{
			EnumStatusCode result = EnumStatusCode_Good;
			OTUInt32 flatLength;
			switch(pValueStruct->arrayType)
			{
			case EnumValueArrayType_Array:
				flatLength = pValueStruct->value.Array.Length;
				break;
			case EnumValueArrayType_Matrix:
				if(pValueStruct->value.Matrix == NULL)
				{
					return EnumStatusCode_BadInvalidArgument;
				}
				flatLength = getFlatLength(pValueStruct->value.Matrix->NoOfDimensions, pValueStruct->value.Matrix->Dimensions);
				break;
			case EnumValueArrayType_Scalar:
			default:
				return EnumStatusCode_BadInvalidArgument;
			}
			arrayT.reserve(flatLength);
			for(OTUInt32 i = 0; i < flatLength; i++)
			{
				T t;
				result = otFunc((V*)t.getInternHandle(), &pArray[i]);
				if(!StatusCode::isGood(result))
				{
					arrayT.clear();
					return result;
				}
				arrayT.push_back(t);
			}
			return EnumStatusCode_Good;
		}

		/*! Similar with getArray, just call OT functions which return void. */
		template <class T, class V, typename OTFunc>
		static EnumStatusCode getArrayV(const ValueStruct* pValueStruct, std::vector<T>& arrayT, OTFunc otFunc, V pArray[])
		{
			OTUInt32 flatLength;
			switch(pValueStruct->arrayType)
			{
			case EnumValueArrayType_Array:
				flatLength = pValueStruct->value.Array.Length;
				break;
			case EnumValueArrayType_Matrix:
				if(pValueStruct->value.Matrix == NULL)
				{
					return EnumStatusCode_BadInvalidArgument;
				}
				flatLength = getFlatLength(pValueStruct->value.Matrix->NoOfDimensions, pValueStruct->value.Matrix->Dimensions);
				break;
			case EnumValueArrayType_Scalar:
			default:
				return EnumStatusCode_BadInvalidArgument;
			}
			arrayT.reserve(flatLength);
			for(OTUInt32 i = 0; i < flatLength; i++)
			{
				T t;
				otFunc((V*)t.getInternHandle(), &pArray[i]);
				arrayT.push_back(t);
			}
			return EnumStatusCode_Good;
		}

		template<class T, typename OTClearFunc>
		static void clearStructures(T* pStructArray, size_t idx, OTClearFunc otFunc)
		{
			for(size_t i = 0; i < idx; i++)
			{
				otFunc(&pStructArray[i]);
			}
		}


		static tstring toString(const ValueStruct* pValueStruct);
	};
}

#endif	// VALUEHELPER_H
