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

#ifndef INNERVALUE_H
#define INNERVALUE_H

#include "IValue.h"

namespace SoftingOPCToolbox5
{
	/*! Utility class which stands as the 'Inner' class of the
	* ValueStruct. Implements the IValue interface.
	* Used in DataValue class, as the inner variant member. */
	class TBC_EXPORT InnerValue
		: public IValue
	{
	public:
		InnerValue(void* handle);
		InnerValue(void);

		/*! Destructor */
		virtual ~InnerValue();

		virtual EnumStatusCode getBoolean(OTBoolean* target) const;
		virtual OTBoolean getBoolean() const;
		virtual void setBoolean(OTBoolean value);
		virtual EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const;
		virtual std::vector<OTBoolean> getBooleanArray() const;
		virtual EnumStatusCode setBooleanArray(const std::vector<OTBoolean>& arrayBool);
		virtual EnumStatusCode getBooleanMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTBoolean>& matrixValues) const;
		virtual EnumStatusCode setBooleanMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTBoolean* matrixValues);

		virtual EnumStatusCode getInt8(OTInt8* target) const;
		virtual OTInt8 getInt8() const;
		virtual void setInt8(OTInt8 value);
		virtual EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const;
		virtual std::vector<OTInt8> getInt8Array() const;
		virtual EnumStatusCode setInt8Array(const std::vector<OTInt8>& arrayInt8);
		virtual EnumStatusCode getInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt8>& matrixValues) const;
		virtual EnumStatusCode setInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt8* matrixValues);

		virtual EnumStatusCode getUInt8(OTUInt8* target) const;
		virtual OTUInt8 getUInt8() const;
		virtual void setUInt8(OTUInt8 value);
		virtual EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const;
		virtual std::vector<OTUInt8> getUInt8Array() const;
		virtual EnumStatusCode setUInt8Array(const std::vector<OTUInt8>& arrayUInt8);
		virtual EnumStatusCode getUInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt8>& matrixValues) const;
		virtual EnumStatusCode setUInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt8* matrixValues);

		virtual EnumStatusCode getInt16(OTInt16* target) const;
		virtual OTInt16 getInt16() const;
		virtual void setInt16(OTInt16 value);
		virtual EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const;
		virtual std::vector<OTInt16> getInt16Array() const;
		virtual EnumStatusCode setInt16Array(const std::vector<OTInt16>& arrayInt16);
		virtual EnumStatusCode getInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt16>& matrixValues) const;
		virtual EnumStatusCode setInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt16* matrixValues);

		virtual EnumStatusCode getUInt16(OTUInt16* target) const;
		virtual OTUInt16 getUInt16() const;
		virtual void setUInt16(OTUInt16 value);
		virtual EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const;
		virtual std::vector<OTUInt16> getUInt16Array() const;
		virtual EnumStatusCode setUInt16Array(const std::vector<OTUInt16>& arrayUInt16);
		virtual EnumStatusCode getUInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt16>& matrixValues) const;
		virtual EnumStatusCode setUInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt16* matrixValues);

		virtual EnumStatusCode getInt32(OTInt32* target) const;
		virtual OTInt32 getInt32() const;
		virtual void setInt32(OTInt32 value);
		virtual EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const;
		virtual std::vector<OTInt32> getInt32Array() const;
		virtual EnumStatusCode setInt32Array(const std::vector<OTInt32>& arrayInt32);
		virtual EnumStatusCode getInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt32>& matrixValues) const;
		virtual EnumStatusCode setInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt32* matrixValues);

		virtual EnumStatusCode getUInt32(OTUInt32* target) const;
		virtual OTUInt32 getUInt32() const;
		virtual void setUInt32(OTUInt32 value);
		virtual EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const;
		virtual std::vector<OTUInt32> getUInt32Array() const;
		virtual EnumStatusCode setUInt32Array(const std::vector<OTUInt32>& arrayUInt32);
		virtual EnumStatusCode getUInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt32>& matrixValues) const;
		virtual EnumStatusCode setUInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt32* matrixValues);

		virtual EnumStatusCode getInt64(OTInt64* target) const;
		virtual OTInt64 getInt64() const;
		virtual void setInt64(OTInt64 value);
		virtual EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const;
		virtual std::vector<OTInt64> getInt64Array() const;
		virtual EnumStatusCode setInt64Array(const std::vector<OTInt64>& arrayInt64);
		virtual EnumStatusCode getInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt64>& matrixValues) const;
		virtual EnumStatusCode setInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt64* matrixValues);

		virtual EnumStatusCode getUInt64(OTUInt64* target) const;
		virtual OTUInt64 getUInt64() const;
		virtual void setUInt64(OTUInt64 value);
		virtual EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const;
		virtual std::vector<OTUInt64> getUInt64Array() const;
		virtual EnumStatusCode setUInt64Array(const std::vector<OTUInt64>& arrayUInt64);
		virtual EnumStatusCode getUInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt64>& matrixValues) const;
		virtual EnumStatusCode setUInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt64* matrixValues);

		virtual EnumStatusCode getFloat(OTFloat* target) const;
		virtual OTFloat getFloat() const;
		virtual void setFloat(OTFloat value);
		virtual EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const;
		virtual std::vector<OTFloat> getFloatArray() const;
		virtual EnumStatusCode setFloatArray(const std::vector<OTFloat>& arrayFloat);
		virtual EnumStatusCode getFloatMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTFloat>& matrixValues) const;
		virtual EnumStatusCode setFloatMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTFloat* matrixValues);

		virtual EnumStatusCode getDouble(OTDouble* target) const;
		virtual OTDouble getDouble() const;
		virtual void setDouble(OTDouble value);
		virtual EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const;
		virtual std::vector<OTDouble> getDoubleArray() const;
		virtual EnumStatusCode setDoubleArray(const std::vector<OTDouble>& arrayDouble);
		virtual EnumStatusCode getDoubleMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTDouble>& matrixValues) const;
		virtual EnumStatusCode setDoubleMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTDouble* matrixValues);

		virtual EnumStatusCode getString(tstring& target) const;
		virtual tstring getString() const;
		virtual EnumStatusCode setString(const tstring& string);
		virtual EnumStatusCode getStringArray(std::vector<tstring>& target) const;
		virtual std::vector<tstring> getStringArray() const;
		virtual EnumStatusCode setStringArray(const std::vector<tstring>& arrayString);
		virtual EnumStatusCode getStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<tstring>& matrixValues) const;
		virtual EnumStatusCode setStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const tstring* matrixValues);

		virtual EnumStatusCode getDateTime(DateTime& target) const;
		virtual DateTime getDateTime() const;
		virtual EnumStatusCode setDateTime(const IDateTime* pdateTime);
		virtual EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const;
		virtual std::vector<DateTime> getDateTimeArray() const;
		virtual EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime);
		virtual EnumStatusCode getDateTimeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DateTime>& matrixValues) const;
		virtual EnumStatusCode setDateTimeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DateTime* matrixValues);

		virtual EnumStatusCode getGuid(Guid& target) const;
		virtual Guid getGuid() const;
		virtual EnumStatusCode setGuid(const IGuid* pGuid);
		virtual EnumStatusCode getGuidArray(std::vector<Guid>& target) const;
		virtual std::vector<Guid> getGuidArray() const;
		virtual EnumStatusCode setGuidArray(const std::vector<Guid>& arrayGuid);
		virtual EnumStatusCode getGuidMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Guid>& matrixValues) const;
		virtual EnumStatusCode setGuidMatrix(const std::vector<OTUInt32>& arrayDimensions, const Guid* matrixValues);

		virtual EnumStatusCode getByteString(ByteString& target) const;
		virtual ByteString getByteString() const;
		virtual EnumStatusCode setByteString(const ByteString& byteString);
		virtual EnumStatusCode setByteString(const unsigned char* pData, unsigned length);
		virtual EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const;
		virtual std::vector<ByteString> getByteStringArray() const;
		virtual EnumStatusCode setByteStringArray(const std::vector<ByteString>& arrayByteString);
		virtual EnumStatusCode getByteStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& matrixValues) const;
		virtual EnumStatusCode setByteStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const ByteString* matrixValues);

		virtual EnumStatusCode getXmlElement(XmlElement& target) const;
		virtual XmlElement getXmlElement() const;
		virtual EnumStatusCode setXmlElement(const XmlElement& xmlElement);
		virtual EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const;
		virtual std::vector<XmlElement> getXmlElementArray() const;
		virtual EnumStatusCode setXmlElementArray(const std::vector<XmlElement>& arrayXmlElement);
		virtual EnumStatusCode getXmlElementMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<XmlElement>& matrixValues) const;
		virtual EnumStatusCode setXmlElementMatrix(const std::vector<OTUInt32>& arrayDimensions, const XmlElement* matrixValues);

		virtual EnumStatusCode getNodeId(NodeId& target) const;
		virtual NodeId getNodeId() const;
		virtual EnumStatusCode setNodeId(const INodeId* pNodeId);
		virtual EnumStatusCode getNodeIdArray(std::vector<NodeId>& target) const;
		virtual std::vector<NodeId> getNodeIdArray() const;
		virtual EnumStatusCode setNodeIdArray(const std::vector<NodeId>& arrayNodeId);
		virtual EnumStatusCode getNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<NodeId>& matrixValues) const;
		virtual EnumStatusCode setNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const NodeId* matrixValues);

		virtual EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const;
		virtual ExpandedNodeId getExpandedNodeId() const;
		virtual EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pNodeId);
		virtual EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>& target) const;
		virtual std::vector<ExpandedNodeId> getExpandedNodeIdArray() const;
		virtual EnumStatusCode setExpandedNodeIdArray(const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		virtual EnumStatusCode getExpandedNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ExpandedNodeId>& matrixValues) const;
		virtual EnumStatusCode setExpandedNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const ExpandedNodeId* matrixValues);

		virtual EnumStatusCode getStatusCode(EnumStatusCode* target) const;
		virtual EnumStatusCode getStatusCode() const;
		virtual void setStatusCode(EnumStatusCode statusCode);
		virtual EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const;
		virtual std::vector<EnumStatusCode> getStatusCodeArray() const;
		virtual EnumStatusCode setStatusCodeArray(const std::vector<EnumStatusCode>& arrayStatusCode);
		virtual EnumStatusCode getStatusCodeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumStatusCode>& matrixValues) const;
		virtual EnumStatusCode setStatusCodeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumStatusCode* matrixValues);

		virtual EnumStatusCode getQualifiedName(QualifiedName& target) const;
		virtual QualifiedName getQualifiedName() const;
		virtual EnumStatusCode setQualifiedName(const IQualifiedName* pQualifiedName);
		virtual EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>& target) const;
		virtual std::vector<QualifiedName> getQualifiedNameArray() const;
		virtual EnumStatusCode setQualifiedNameArray(const std::vector<QualifiedName>& arrayQualifiedName);
		virtual EnumStatusCode getQualifiedNameMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<QualifiedName>& matrixValues) const;
		virtual EnumStatusCode setQualifiedNameMatrix(const std::vector<OTUInt32>& arrayDimensions, const QualifiedName* matrixValues);

		virtual EnumStatusCode getLocalizedText(LocalizedText& target) const;
		virtual LocalizedText getLocalizedText() const;
		virtual EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText);
		virtual EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>& target) const;
		virtual std::vector<LocalizedText> getLocalizedTextArray() const;
		virtual EnumStatusCode setLocalizedTextArray(const std::vector<LocalizedText>& arrayLocalizedText);
		virtual EnumStatusCode getLocalizedTextMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<LocalizedText>& matrixValues) const;
		virtual EnumStatusCode setLocalizedTextMatrix(const std::vector<OTUInt32>& arrayDimensions, const LocalizedText* matrixValues);

		virtual EnumStatusCode getDataValue(DataValue& target) const;
		virtual DataValue getDataValue() const;
		virtual EnumStatusCode setDataValue(const IDataValue* pDataValue);
		virtual EnumStatusCode getDataValueArray(std::vector<DataValue>& target) const;
		virtual std::vector<DataValue> getDataValueArray() const;
		virtual EnumStatusCode setDataValueArray(const std::vector<DataValue>& arrayDataValue);
		virtual EnumStatusCode getDataValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataValue>& matrixValues) const;
		virtual EnumStatusCode setDataValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataValue* matrixValues);

		virtual EnumStatusCode getValueArray(std::vector<Value>& target) const;
		virtual std::vector<Value> getValueArray() const;
		virtual EnumStatusCode setValueArray(const std::vector<Value>& arrayValue);
		virtual EnumStatusCode getValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Value>& matrixValues) const;
		virtual EnumStatusCode setValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const Value* matrixValues);

		virtual DiagnosticInfo getDiagnosticInfo() const;
		virtual EnumStatusCode getDiagnosticInfo(DiagnosticInfo& target) const;
		virtual EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* pInfo);
		virtual std::vector<DiagnosticInfo> getDiagnosticInfoArray() const;
		virtual EnumStatusCode getDiagnosticInfoArray(std::vector<DiagnosticInfo>& target) const;
		virtual EnumStatusCode setDiagnosticInfoArray(const std::vector<DiagnosticInfo>& arrayDiagnosticInfo);
		virtual EnumStatusCode getDiagnosticInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DiagnosticInfo>& matrixValues) const;
		virtual EnumStatusCode setDiagnosticInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const DiagnosticInfo* matrixValues);

		virtual EnumStatusCode getArgument(Argument& target) const;
		virtual Argument getArgument() const;
		virtual EnumStatusCode setArgument(const IArgument* pArgument);
		virtual EnumStatusCode getArgumentArray(std::vector<Argument>& target) const;
		virtual std::vector<Argument> getArgumentArray() const;
		virtual EnumStatusCode setArgumentArray(const std::vector<Argument>& arrayArgument);
		virtual EnumStatusCode getArgumentMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Argument>& matrixValues) const;
		virtual EnumStatusCode setArgumentMatrix(const std::vector<OTUInt32>& arrayDimensions, const Argument* matrixValues);

		virtual EnumStatusCode getApplicationDescription(ApplicationDescription& target) const;
		virtual ApplicationDescription getApplicationDescription() const;
		virtual EnumStatusCode setApplicationDescription(const IApplicationDescription* pApplicationDescription);
		virtual EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>& target) const;
		virtual std::vector<ApplicationDescription> getApplicationDescriptionArray() const;
		virtual EnumStatusCode setApplicationDescriptionArray(const std::vector<ApplicationDescription>& arrayApplicationDescription);
		virtual EnumStatusCode getApplicationDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ApplicationDescription>& matrixValues) const;
		virtual EnumStatusCode setApplicationDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ApplicationDescription* matrixValues);

		virtual EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const;
		virtual UserIdentityToken getUserIdentityToken() const;
		virtual EnumStatusCode setUserIdentityToken(const IUserIdentityToken* pUserIdentityToken);
		virtual EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>& target) const;
		virtual std::vector<UserIdentityToken> getUserIdentityTokenArray() const;
		virtual EnumStatusCode setUserIdentityTokenArray(const std::vector<UserIdentityToken>& arrayUserIdentityToken);
		virtual EnumStatusCode getUserIdentityTokenMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<UserIdentityToken>& matrixValues) const;
		virtual EnumStatusCode setUserIdentityTokenMatrix(const std::vector<OTUInt32>& arrayDimensions, const UserIdentityToken* matrixValues);

		virtual EnumStatusCode getBuildInfo(BuildInfo& target) const;
		virtual BuildInfo getBuildInfo() const;
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* pBuildInfo);
		virtual EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>& target) const;
		virtual std::vector<BuildInfo> getBuildInfoArray() const;
		virtual EnumStatusCode setBuildInfoArray(const std::vector<BuildInfo>& arrayBuildInfo);
		virtual EnumStatusCode getBuildInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<BuildInfo>& matrixValues) const;
		virtual EnumStatusCode setBuildInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const BuildInfo* matrixValues);

		virtual EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const;
		virtual SignedSoftwareCertificate getSignedSoftwareCertificate() const;
		virtual EnumStatusCode setSignedSoftwareCertificate(const ISignedSoftwareCertificate* pSignedSoftwareCertificate);
		virtual EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>& target) const;
		virtual std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray() const;
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		virtual EnumStatusCode getSignedSoftwareCertificateMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SignedSoftwareCertificate>& matrixValues) const;
		virtual EnumStatusCode setSignedSoftwareCertificateMatrix(const std::vector<OTUInt32>& arrayDimensions, const SignedSoftwareCertificate* matrixValues);

		virtual EnumStatusCode getReferenceDescription(ReferenceDescription& target) const;
		virtual ReferenceDescription getReferenceDescription() const;
		virtual EnumStatusCode setReferenceDescription(const IReferenceDescription* pReferenceDescription);
		virtual EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>& target) const;
		virtual std::vector<ReferenceDescription> getReferenceDescriptionArray() const;
		virtual EnumStatusCode setReferenceDescriptionArray(const std::vector<ReferenceDescription>& arrayReferenceDescription);
		virtual EnumStatusCode getReferenceDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReferenceDescription>& matrixValues) const;
		virtual EnumStatusCode setReferenceDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReferenceDescription* matrixValues);

#if TB5_ALARMS
		virtual EnumStatusCode getEventFilter(EventFilter& target) const;
		virtual EventFilter getEventFilter() const;
		virtual EnumStatusCode setEventFilter(const IEventFilter* pEventFilter);
		virtual EnumStatusCode getEventFilterArray(std::vector<EventFilter>& target) const;
		virtual std::vector<EventFilter> getEventFilterArray() const;
		virtual EnumStatusCode setEventFilterArray(const std::vector<EventFilter>& arrayEventFilter);
		virtual EnumStatusCode getEventFilterMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EventFilter>& matrixValues) const;
		virtual EnumStatusCode setEventFilterMatrix(const std::vector<OTUInt32>& arrayDimensions, const EventFilter* matrixValues);
#endif

		virtual EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const;
		virtual ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType() const;
		virtual EnumStatusCode setServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>& target) const;
		virtual std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray() const;
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerDiagnosticsSummaryDataType>& matrixValues) const;
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerDiagnosticsSummaryDataType* matrixValues);

		virtual EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const;
		virtual ServerStatusDataType getServerStatusDataType() const;
		virtual EnumStatusCode setServerStatusDataType(const IServerStatusDataType* pServerStatusDataType);
		virtual EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>& target) const;
		virtual std::vector<ServerStatusDataType> getServerStatusDataTypeArray() const;
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		virtual EnumStatusCode getServerStatusDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerStatusDataType>& matrixValues) const;
		virtual EnumStatusCode setServerStatusDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerStatusDataType* matrixValues);

		virtual EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const;
		virtual SessionDiagnosticsDataType getSessionDiagnosticsDataType() const;
		virtual EnumStatusCode setSessionDiagnosticsDataType(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);
		virtual EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>& target) const;
		virtual std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray() const;
		virtual EnumStatusCode setSessionDiagnosticsDataTypeArray(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		virtual EnumStatusCode getSessionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionDiagnosticsDataType>& matrixValues) const;
		virtual EnumStatusCode setSessionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionDiagnosticsDataType* matrixValues);

		virtual EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const;
		virtual SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType() const;
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>& target) const;
		virtual std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray() const;
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionSecurityDiagnosticsDataType>& matrixValues) const;
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionSecurityDiagnosticsDataType* matrixValues);

		virtual EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const;
		virtual ServiceCounterDataType getServiceCounterDataType() const;
		virtual EnumStatusCode setServiceCounterDataType(const IServiceCounterDataType* pServiceCounterDataType);
		virtual EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>& target) const;
		virtual std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray() const;
		virtual EnumStatusCode setServiceCounterDataTypeArray(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		virtual EnumStatusCode getServiceCounterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServiceCounterDataType>& matrixValues) const;
		virtual EnumStatusCode setServiceCounterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServiceCounterDataType* matrixValues);

		virtual EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const;
		virtual SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType() const;
		virtual EnumStatusCode setSubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>& target) const;
		virtual std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray() const;
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SubscriptionDiagnosticsDataType>& matrixValues) const;
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SubscriptionDiagnosticsDataType* matrixValues);

#if TB5_ALARMS
		virtual EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const;
		virtual ModelChangeStructureDataType getModelChangeStructureDataType() const;
		virtual EnumStatusCode setModelChangeStructureDataType(const IModelChangeStructureDataType* pModelChangeStructureDataType);
		virtual EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>& target) const;
		virtual std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray() const;
		virtual EnumStatusCode setModelChangeStructureDataTypeArray(const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);
		virtual EnumStatusCode getModelChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ModelChangeStructureDataType>& matrixValues) const;
		virtual EnumStatusCode setModelChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ModelChangeStructureDataType* matrixValues);
#endif

		virtual EnumStatusCode getRange(Range& target) const;
		virtual Range getRange() const;
		virtual EnumStatusCode setRange(const IRange* pRange);
		virtual EnumStatusCode getRangeArray(std::vector<Range>& target) const;
		virtual std::vector<Range> getRangeArray() const;
		virtual EnumStatusCode setRangeArray(const std::vector<Range>& arrayRange);
		virtual EnumStatusCode getRangeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Range>& matrixValues) const;
		virtual EnumStatusCode setRangeMatrix(const std::vector<OTUInt32>& arrayDimensions, const Range* matrixValues);

		virtual EnumStatusCode getEUInformation(EUInformation& target) const;
		virtual EUInformation getEUInformation() const;
		virtual EnumStatusCode setEUInformation(const IEUInformation* pEUInformation);
		virtual EnumStatusCode getEUInformationArray(std::vector<EUInformation>& target) const;
		virtual std::vector<EUInformation> getEUInformationArray() const;
		virtual EnumStatusCode setEUInformationArray(const std::vector<EUInformation>& arrayEUInformation);
		virtual EnumStatusCode getEUInformationMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EUInformation>& matrixValues) const;
		virtual EnumStatusCode setEUInformationMatrix(const std::vector<OTUInt32>& arrayDimensions, const EUInformation* matrixValues);

#if TB5_ALARMS
		virtual EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const;
		virtual SemanticChangeStructureDataType getSemanticChangeStructureDataType() const;
		virtual EnumStatusCode setSemanticChangeStructureDataType(const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType);
		virtual EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>& target) const;
		virtual std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray() const;
		virtual EnumStatusCode setSemanticChangeStructureDataTypeArray(const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);
		virtual EnumStatusCode getSemanticChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SemanticChangeStructureDataType>& matrixValues) const;
		virtual EnumStatusCode setSemanticChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SemanticChangeStructureDataType* matrixValues);
#endif
		// Support for EnumValueType
		virtual EnumStatusCode getEnumValueType(EnumValueType& target) const;
		virtual EnumValueType getEnumValueType() const;
		virtual EnumStatusCode setEnumValueType(const IEnumValueType* pEnumValueType);
		virtual EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>& target) const;
		virtual std::vector<EnumValueType> getEnumValueTypeArray() const;
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<EnumValueType>& arrayEnumValueType);
		virtual EnumStatusCode getEnumValueTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumValueType>& matrixValues) const;
		virtual EnumStatusCode setEnumValueTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumValueType* matrixValues);

		// Support for KeyValuePair
		virtual EnumStatusCode getKeyValuePair(KeyValuePair& target) const;
		virtual KeyValuePair getKeyValuePair() const;
		virtual EnumStatusCode setKeyValuePair(const IKeyValuePair* pKeyValuePair);
		virtual EnumStatusCode getKeyValuePairArray(std::vector<KeyValuePair>& target) const;
		virtual std::vector<KeyValuePair> getKeyValuePairArray() const;
		virtual EnumStatusCode setKeyValuePairArray(const std::vector<KeyValuePair>& arrayKeyValuePair);
		virtual EnumStatusCode getKeyValuePairMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<KeyValuePair>& matrixValues) const;
		virtual EnumStatusCode setKeyValuePairMatrix(const std::vector<OTUInt32>& arrayDimensions, const KeyValuePair* matrixValues);

		// Support for ConfigurationVersionDataType
		virtual EnumStatusCode getConfigurationVersionDataType(ConfigurationVersionDataType& target) const;
		virtual ConfigurationVersionDataType getConfigurationVersionDataType() const;
		virtual EnumStatusCode setConfigurationVersionDataType(const IConfigurationVersionDataType* pConfigurationVersionDataType);
		virtual EnumStatusCode getConfigurationVersionDataTypeArray(std::vector<ConfigurationVersionDataType>& target) const;
		virtual std::vector<ConfigurationVersionDataType> getConfigurationVersionDataTypeArray() const;
		virtual EnumStatusCode setConfigurationVersionDataTypeArray(const std::vector<ConfigurationVersionDataType>& arrayConfigurationVersionDataType);
		virtual EnumStatusCode getConfigurationVersionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ConfigurationVersionDataType>& matrixValues) const;
		virtual EnumStatusCode setConfigurationVersionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ConfigurationVersionDataType* matrixValues);

		// Support for DataSetMetaDataType
		virtual EnumStatusCode getDataSetMetaDataType(DataSetMetaDataType& target) const;
		virtual DataSetMetaDataType getDataSetMetaDataType() const;
		virtual EnumStatusCode setDataSetMetaDataType(const IDataSetMetaDataType* pDataSetMetaDataType);
		virtual EnumStatusCode getDataSetMetaDataTypeArray(std::vector<DataSetMetaDataType>& target) const;
		virtual std::vector<DataSetMetaDataType> getDataSetMetaDataTypeArray() const;
		virtual EnumStatusCode setDataSetMetaDataTypeArray(const std::vector<DataSetMetaDataType>& arrayDataSetMetaDataType);
		virtual EnumStatusCode getDataSetMetaDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetMetaDataType>& matrixValues) const;
		virtual EnumStatusCode setDataSetMetaDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetMetaDataType* matrixValues);

		// Support for DataSetReaderDataType
		virtual EnumStatusCode getDataSetReaderDataType(DataSetReaderDataType& target) const;
		virtual DataSetReaderDataType getDataSetReaderDataType() const;
		virtual EnumStatusCode setDataSetReaderDataType(const IDataSetReaderDataType* pDataSetReaderDataType);
		virtual EnumStatusCode getDataSetReaderDataTypeArray(std::vector<DataSetReaderDataType>& target) const;
		virtual std::vector<DataSetReaderDataType> getDataSetReaderDataTypeArray() const;
		virtual EnumStatusCode setDataSetReaderDataTypeArray(const std::vector<DataSetReaderDataType>& arrayDataSetReaderDataType);
		virtual EnumStatusCode getDataSetReaderDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetReaderDataType>& matrixValues) const;
		virtual EnumStatusCode setDataSetReaderDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetReaderDataType* matrixValues);

		// Support for DataSetWriterDataType
		virtual EnumStatusCode getDataSetWriterDataType(DataSetWriterDataType& target) const;
		virtual DataSetWriterDataType getDataSetWriterDataType() const;
		virtual EnumStatusCode setDataSetWriterDataType(const IDataSetWriterDataType* pDataSetWriterDataType);
		virtual EnumStatusCode getDataSetWriterDataTypeArray(std::vector<DataSetWriterDataType>& target) const;
		virtual std::vector<DataSetWriterDataType> getDataSetWriterDataTypeArray() const;
		virtual EnumStatusCode setDataSetWriterDataTypeArray(const std::vector<DataSetWriterDataType>& arrayDataSetWriterDataType);
		virtual EnumStatusCode getDataSetWriterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetWriterDataType>& matrixValues) const;
		virtual EnumStatusCode setDataSetWriterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetWriterDataType* matrixValues);

		// Support for EnumDefinition
		virtual EnumStatusCode getEnumDefinition(EnumDefinition& target) const;
		virtual EnumDefinition getEnumDefinition() const;
		virtual EnumStatusCode setEnumDefinition(const IEnumDefinition* pEnumDefinition);
		virtual EnumStatusCode getEnumDefinitionArray(std::vector<EnumDefinition>& target) const;
		virtual std::vector<EnumDefinition> getEnumDefinitionArray() const;
		virtual EnumStatusCode setEnumDefinitionArray(const std::vector<EnumDefinition>& arrayEnumDefinition);
		virtual EnumStatusCode getEnumDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumDefinition>& matrixValues) const;
		virtual EnumStatusCode setEnumDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumDefinition* matrixValues);

		// Support for FieldTargetDataType
		virtual EnumStatusCode getFieldTargetDataType(FieldTargetDataType& target) const;
		virtual FieldTargetDataType getFieldTargetDataType() const;
		virtual EnumStatusCode setFieldTargetDataType(const IFieldTargetDataType* pFieldTargetDataType);
		virtual EnumStatusCode getFieldTargetDataTypeArray(std::vector<FieldTargetDataType>& target) const;
		virtual std::vector<FieldTargetDataType> getFieldTargetDataTypeArray() const;
		virtual EnumStatusCode setFieldTargetDataTypeArray(const std::vector<FieldTargetDataType>& arrayFieldTargetDataType);
		virtual EnumStatusCode getFieldTargetDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<FieldTargetDataType>& matrixValues) const;
		virtual EnumStatusCode setFieldTargetDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const FieldTargetDataType* matrixValues);

		// Support for PubSubConnectionDataType
		virtual EnumStatusCode getPubSubConnectionDataType(PubSubConnectionDataType& target) const;
		virtual PubSubConnectionDataType getPubSubConnectionDataType() const;
		virtual EnumStatusCode setPubSubConnectionDataType(const IPubSubConnectionDataType* pPubSubConnectionDataType);
		virtual EnumStatusCode getPubSubConnectionDataTypeArray(std::vector<PubSubConnectionDataType>& target) const;
		virtual std::vector<PubSubConnectionDataType> getPubSubConnectionDataTypeArray() const;
		virtual EnumStatusCode setPubSubConnectionDataTypeArray(const std::vector<PubSubConnectionDataType>& arrayPubSubConnectionDataType);
		virtual EnumStatusCode getPubSubConnectionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PubSubConnectionDataType>& matrixValues) const;
		virtual EnumStatusCode setPubSubConnectionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PubSubConnectionDataType* matrixValues);

		// Support for ReaderGroupDataType
		virtual EnumStatusCode getReaderGroupDataType(ReaderGroupDataType& target) const;
		virtual ReaderGroupDataType getReaderGroupDataType() const;
		virtual EnumStatusCode setReaderGroupDataType(const IReaderGroupDataType* pReaderGroupDataType);
		virtual EnumStatusCode getReaderGroupDataTypeArray(std::vector<ReaderGroupDataType>& target) const;
		virtual std::vector<ReaderGroupDataType> getReaderGroupDataTypeArray() const;
		virtual EnumStatusCode setReaderGroupDataTypeArray(const std::vector<ReaderGroupDataType>& arrayReaderGroupDataType);
		virtual EnumStatusCode getReaderGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReaderGroupDataType>& matrixValues) const;
		virtual EnumStatusCode setReaderGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReaderGroupDataType* matrixValues);

		// Support for RolePermissionType
		virtual EnumStatusCode getRolePermissionType(RolePermissionType& target) const;
		virtual RolePermissionType getRolePermissionType() const;
		virtual EnumStatusCode setRolePermissionType(const IRolePermissionType* pRolePermissionType);
		virtual EnumStatusCode getRolePermissionTypeArray(std::vector<RolePermissionType>& target) const;
		virtual std::vector<RolePermissionType> getRolePermissionTypeArray() const;
		virtual EnumStatusCode setRolePermissionTypeArray(const std::vector<RolePermissionType>& arrayRolePermissionType);
		virtual EnumStatusCode getRolePermissionTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<RolePermissionType>& matrixValues) const;
		virtual EnumStatusCode setRolePermissionTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const RolePermissionType* matrixValues);

		// Support for StructureDefinition
		virtual EnumStatusCode getStructureDefinition(StructureDefinition& target) const;
		virtual StructureDefinition getStructureDefinition() const;
		virtual EnumStatusCode setStructureDefinition(const IStructureDefinition* pStructureDefinition);
		virtual EnumStatusCode getStructureDefinitionArray(std::vector<StructureDefinition>& target) const;
		virtual std::vector<StructureDefinition> getStructureDefinitionArray() const;
		virtual EnumStatusCode setStructureDefinitionArray(const std::vector<StructureDefinition>& arrayStructureDefinition);
		virtual EnumStatusCode getStructureDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<StructureDefinition>& matrixValues) const;
		virtual EnumStatusCode setStructureDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const StructureDefinition* matrixValues);

		// Support for WriterGroupDataType
		virtual EnumStatusCode getWriterGroupDataType(WriterGroupDataType& target) const;
		virtual WriterGroupDataType getWriterGroupDataType() const;
		virtual EnumStatusCode setWriterGroupDataType(const IWriterGroupDataType* pWriterGroupDataType);
		virtual EnumStatusCode getWriterGroupDataTypeArray(std::vector<WriterGroupDataType>& target) const;
		virtual std::vector<WriterGroupDataType> getWriterGroupDataTypeArray() const;
		virtual EnumStatusCode setWriterGroupDataTypeArray(const std::vector<WriterGroupDataType>& arrayWriterGroupDataType);
		virtual EnumStatusCode getWriterGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<WriterGroupDataType>& matrixValues) const;
		virtual EnumStatusCode setWriterGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const WriterGroupDataType* matrixValues);

		// Support for PublishedVariableDataType
		virtual EnumStatusCode getPublishedVariableDataType(PublishedVariableDataType& target) const;
		virtual PublishedVariableDataType getPublishedVariableDataType() const;
		virtual EnumStatusCode setPublishedVariableDataType(const IPublishedVariableDataType* pPublishedVariableDataType);
		virtual EnumStatusCode getPublishedVariableDataTypeArray(std::vector<PublishedVariableDataType>& target) const;
		virtual std::vector<PublishedVariableDataType> getPublishedVariableDataTypeArray() const;
		virtual EnumStatusCode setPublishedVariableDataTypeArray(const std::vector<PublishedVariableDataType>& arrayPublishedVariableDataType);
		virtual EnumStatusCode getPublishedVariableDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PublishedVariableDataType>& matrixValues) const;
		virtual EnumStatusCode setPublishedVariableDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PublishedVariableDataType* matrixValues);

		// Support for EndpointDescription
		virtual EnumStatusCode getEndpointDescription(EndpointDescription& target) const;
		virtual EndpointDescription getEndpointDescription() const;
		virtual EnumStatusCode setEndpointDescription(const IEndpointDescription* pEndpointDescription);
		virtual EnumStatusCode getEndpointDescriptionArray(std::vector<EndpointDescription>& target) const;
		virtual std::vector<EndpointDescription> getEndpointDescriptionArray() const;
		virtual EnumStatusCode setEndpointDescriptionArray(const std::vector<EndpointDescription>& arrayEndpointDescription);
		virtual EnumStatusCode getEndpointDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EndpointDescription>& matrixValues) const;
		virtual EnumStatusCode setEndpointDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EndpointDescription* matrixValues);

		// NEW_SUPPORTED_DATATYPE - copy the block above and replace type name

		virtual EnumStatusCode getTimeZone(TimeZone& target) const;
		virtual TimeZone getTimeZone() const;
		virtual EnumStatusCode setTimeZone(const ITimeZone* pTimeZone);
		virtual EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const;
		virtual std::vector<TimeZone> getTimeZoneArray() const;
		virtual EnumStatusCode setTimeZoneArray(const std::vector<TimeZone>& arrayTimeZone);
		virtual EnumStatusCode getTimeZoneMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<TimeZone>& matrixValues) const;
		virtual EnumStatusCode setTimeZoneMatrix(const std::vector<OTUInt32>& arrayDimensions, const TimeZone* matrixValues);

		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const;
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body);
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const;
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies);
		virtual EnumStatusCode getComplexValueRawMatrix(NodeId& encodingId, std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& bodies) const;
		virtual EnumStatusCode setComplexValueRawMatrix(const INodeId& encodingId, const std::vector<OTUInt32>& arrayDimensions, const std::vector<ByteString>& bodies);

		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<Value>& fieldValues) const;
		virtual EnumStatusCode setStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);
		virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription, std::vector<std::vector<Value> >& fieldValues) const;
		virtual EnumStatusCode setStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues);
		virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues);
		virtual EnumStatusCode getStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<OTUInt32>& arrayDimensions, std::vector<std::vector<Value> >& fieldValues) const;
		virtual EnumStatusCode setStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues);
		virtual EnumStatusCode setStructuredValueMatrix(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues);

		// set from interface
		EnumStatusCode set(const IValue* pSrc);
		EnumStatusCode set(const IValue& rValue);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IValue* other) const;
		/*! @overload */
		virtual int compare(const IValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other) const;

		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const;
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const;

		/*! For internal use only */
		void initInner(void* handle);
		virtual EnumDataTypeId getDataType() const;
		virtual EnumValueArrayType getArrayType() const;
		void* getInternHandle() const{ return m_otbHandle; }
		tstring toString(void) const;
		EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const;
		EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange);
		void clear(void);
	protected:
		// the handle to the related core object
		void* m_otbHandle;
	};
}
#endif	// INNERVALUE_H
