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

#ifndef UATYPES_ENCODER_GENERATED_H
#define UATYPES_ENCODER_GENERATED_H

#include <Enums.h>
#include <map>

#include "ModelCompiler/ErrorEnums.h"
#include "EncoderContext.h"

namespace SoftingOPCToolbox5
{
	class ByteString;
	class DateTime;
	class ExpandedNodeId;
	class LocalizedText;
	class X509IdentityToken;
	class IssuedIdentityToken;
	class SimpleAttributeOperand;
	class AttributeOperand;
	class ContentFilterElement;
	class DataValue;
	class Argument;
	class EnumValueType;
	class ApplicationDescription;
	class SignedSoftwareCertificate;
	class AnonymousIdentityToken;
	class UserNameIdentityToken;
	class ReferenceDescription;
	class RelativePathElement;
	class RelativePath;
	class ContentFilter;
	class ElementOperand;
	class LiteralOperand;
	class EventFilter;
	class BuildInfo;
	class ServerDiagnosticsSummaryDataType;
	class ServerStatusDataType;
	class SessionDiagnosticsDataType;
	class SessionSecurityDiagnosticsDataType;
	class ServiceCounterDataType;
	class SubscriptionDiagnosticsDataType;
	class ModelChangeStructureDataType;
	class SemanticChangeStructureDataType;
	class Range;
	class EUInformation;
}

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			namespace UaTypesEncoder
			{
				/*! Encodes the OPC UA type 'NodeClass' */
				EnumModelDesignerStatus encodeNodeClassContent(const EnumNodeClass& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ApplicationType' */
				EnumModelDesignerStatus encodeApplicationTypeContent(const EnumApplicationType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'MessageSecurityMode' */
				EnumModelDesignerStatus encodeMessageSecurityModeContent(const EnumMessageSecurityMode& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UserTokenType' */
				EnumModelDesignerStatus encodeUserTokenTypeContent(const EnumUserTokenType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'BrowseDirection' */
				EnumModelDesignerStatus encodeBrowseDirectionContent(const EnumBrowseDirection& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'FilterOperator' */
				EnumModelDesignerStatus encodeFilterOperatorContent(const EnumFilterOperator& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'TimestampsToReturn' */
				EnumModelDesignerStatus encodeTimestampsToReturnContent(const EnumTimestampsToReturn& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'MonitoringMode' */
				EnumModelDesignerStatus encodeMonitoringModeContent(const EnumMonitoringMode& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DataChangeTrigger' */
				EnumModelDesignerStatus encodeDataChangeTriggerContent(const EnumDataChangeTrigger& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DeadbandType' */
				EnumModelDesignerStatus encodeDeadbandTypeContent(const EnumDeadbandType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'RedundancySupport' */
				EnumModelDesignerStatus encodeRedundancySupportContent(const EnumRedundancySupport& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ServerState' */
				EnumModelDesignerStatus encodeServerStateContent(const EnumServerState& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ModelChangeStructureVerbMask' */
				EnumModelDesignerStatus encodeModelChangeStructureVerbMaskContent(const EnumModelChangeStructureVerbMask& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ExceptionDeviationFormat' */
				EnumModelDesignerStatus encodeExceptionDeviationFormatContent(const EnumExceptionDeviationFormat& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Boolean' */
				EnumModelDesignerStatus encodeBooleanContent(const OTBoolean& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SByte' */
				EnumModelDesignerStatus encodeSByteContent(const OTInt8& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Byte' */
				EnumModelDesignerStatus encodeByteContent(const OTUInt8& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Int16' */
				EnumModelDesignerStatus encodeInt16Content(const OTInt16& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UInt16' */
				EnumModelDesignerStatus encodeUInt16Content(const OTUInt16& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Int32' */
				EnumModelDesignerStatus encodeInt32Content(const OTInt32& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UInt32' */
				EnumModelDesignerStatus encodeUInt32Content(const OTUInt32& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Int64' */
				EnumModelDesignerStatus encodeInt64Content(const OTInt64& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UInt64' */
				EnumModelDesignerStatus encodeUInt64Content(const OTUInt64& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Float' */
				EnumModelDesignerStatus encodeFloatContent(const OTFloat& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Double' */
				EnumModelDesignerStatus encodeDoubleContent(const OTDouble& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'String' */
				EnumModelDesignerStatus encodeStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DateTime' */
				EnumModelDesignerStatus encodeDateTimeContent(const DateTime& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ByteString' */
				EnumModelDesignerStatus encodeByteStringContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'InvokeServiceRequest' */
				EnumModelDesignerStatus encodeInvokeServiceRequestContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'InvokeServiceResponse' */
				EnumModelDesignerStatus encodeInvokeServiceResponseContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ImageBMP' */
				EnumModelDesignerStatus encodeImageBMPContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ImageGIF' */
				EnumModelDesignerStatus encodeImageGIFContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ImageJPG' */
				EnumModelDesignerStatus encodeImageJPGContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ImagePNG' */
				EnumModelDesignerStatus encodeImagePNGContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'BitFieldMaskDataType' */
				EnumModelDesignerStatus encodeBitFieldMaskDataTypeContent(const OTUInt64& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'NormalizedString' */
				EnumModelDesignerStatus encodeNormalizedStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DecimalString' */
				EnumModelDesignerStatus encodeDecimalStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DurationString' */
				EnumModelDesignerStatus encodeDurationStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'TimeString' */
				EnumModelDesignerStatus encodeTimeStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DateString' */
				EnumModelDesignerStatus encodeDateStringContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Duration' */
				EnumModelDesignerStatus encodeDurationContent(const OTDouble& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UtcTime' */
				EnumModelDesignerStatus encodeUtcTimeContent(const DateTime& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'LocaleId' */
				EnumModelDesignerStatus encodeLocaleIdContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'IntegerId' */
				EnumModelDesignerStatus encodeIntegerIdContent(const OTUInt32& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ApplicationInstanceCertificate' */
				EnumModelDesignerStatus encodeApplicationInstanceCertificateContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ContinuationPoint' */
				EnumModelDesignerStatus encodeContinuationPointContent(const ByteString& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Counter' */
				EnumModelDesignerStatus encodeCounterContent(const OTUInt32& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Time' */
				EnumModelDesignerStatus encodeTimeContent(const tstring& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Date' */
				EnumModelDesignerStatus encodeDateContent(const DateTime& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfBoolean' */
				EnumModelDesignerStatus encodeListOfBooleanContent(const std::vector<OTBoolean>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSByte' */
				EnumModelDesignerStatus encodeListOfSByteContent(const std::vector<OTInt8>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfByte' */
				EnumModelDesignerStatus encodeListOfByteContent(const std::vector<OTUInt8>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfInt16' */
				EnumModelDesignerStatus encodeListOfInt16Content(const std::vector<OTInt16>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfUInt16' */
				EnumModelDesignerStatus encodeListOfUInt16Content(const std::vector<OTUInt16>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfInt32' */
				EnumModelDesignerStatus encodeListOfInt32Content(const std::vector<OTInt32>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfUInt32' */
				EnumModelDesignerStatus encodeListOfUInt32Content(const std::vector<OTUInt32>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfInt64' */
				EnumModelDesignerStatus encodeListOfInt64Content(const std::vector<OTInt64>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfUInt64' */
				EnumModelDesignerStatus encodeListOfUInt64Content(const std::vector<OTUInt64>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfFloat' */
				EnumModelDesignerStatus encodeListOfFloatContent(const std::vector<OTFloat>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfDouble' */
				EnumModelDesignerStatus encodeListOfDoubleContent(const std::vector<OTDouble>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfString' */
				EnumModelDesignerStatus encodeListOfStringContent(const std::vector<tstring>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfDateTime' */
				EnumModelDesignerStatus encodeListOfDateTimeContent(const std::vector<DateTime>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfByteString' */
				EnumModelDesignerStatus encodeListOfByteStringContent(const std::vector<ByteString>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'DataValue' */
				EnumModelDesignerStatus encodeDataValueContent(const DataValue& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'Argument' */
				EnumModelDesignerStatus encodeArgumentContent(const Argument& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'EnumValueType' */
				EnumModelDesignerStatus encodeEnumValueTypeContent(const EnumValueType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ApplicationDescription' */
				EnumModelDesignerStatus encodeApplicationDescriptionContent(const ApplicationDescription& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SignedSoftwareCertificate' */
				EnumModelDesignerStatus encodeSignedSoftwareCertificateContent(const SignedSoftwareCertificate& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'AnonymousIdentityToken' */
				EnumModelDesignerStatus encodeAnonymousIdentityTokenContent(const AnonymousIdentityToken& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'UserNameIdentityToken' */
				EnumModelDesignerStatus encodeUserNameIdentityTokenContent(const UserNameIdentityToken& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ReferenceDescription' */
				EnumModelDesignerStatus encodeReferenceDescriptionContent(const ReferenceDescription& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'RelativePathElement' */
				EnumModelDesignerStatus encodeRelativePathElementContent(const RelativePathElement& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'RelativePath' */
				EnumModelDesignerStatus encodeRelativePathContent(const RelativePath& value, EncoderContextPtr context);
#if TB5_FILTER
				/*! Encodes the OPC UA type 'ContentFilter' */
				EnumModelDesignerStatus encodeContentFilterContent(const ContentFilter& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ElementOperand' */
				EnumModelDesignerStatus encodeElementOperandContent(const ElementOperand& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'LiteralOperand' */
				EnumModelDesignerStatus encodeLiteralOperandContent(const LiteralOperand& value, EncoderContextPtr context);
#endif
#if TB5_ALARMS
				/*! Encodes the OPC UA type 'EventFilter' */
				EnumModelDesignerStatus encodeEventFilterContent(const EventFilter& value, EncoderContextPtr context);
#endif
				/*! Encodes the OPC UA type 'BuildInfo' */
				EnumModelDesignerStatus encodeBuildInfoContent(const BuildInfo& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ServerDiagnosticsSummaryDataType' */
				EnumModelDesignerStatus encodeServerDiagnosticsSummaryDataTypeContent(const ServerDiagnosticsSummaryDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ServerStatusDataType' */
				EnumModelDesignerStatus encodeServerStatusDataTypeContent(const ServerStatusDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SessionDiagnosticsDataType' */
				EnumModelDesignerStatus encodeSessionDiagnosticsDataTypeContent(const SessionDiagnosticsDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SessionSecurityDiagnosticsDataType' */
				EnumModelDesignerStatus encodeSessionSecurityDiagnosticsDataTypeContent(const SessionSecurityDiagnosticsDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ServiceCounterDataType' */
				EnumModelDesignerStatus encodeServiceCounterDataTypeContent(const ServiceCounterDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SubscriptionDiagnosticsDataType' */
				EnumModelDesignerStatus encodeSubscriptionDiagnosticsDataTypeContent(const SubscriptionDiagnosticsDataType& value, EncoderContextPtr context);
#if TB5_ALARMS
				/*! Encodes the OPC UA type 'ModelChangeStructureDataType' */
				EnumModelDesignerStatus encodeModelChangeStructureDataTypeContent(const ModelChangeStructureDataType& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'SemanticChangeStructureDataType' */
				EnumModelDesignerStatus encodeSemanticChangeStructureDataTypeContent(const SemanticChangeStructureDataType& value, EncoderContextPtr context);
#endif
				/*! Encodes the OPC UA type 'Range' */
				EnumModelDesignerStatus encodeRangeContent(const Range& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'EUInformation' */
				EnumModelDesignerStatus encodeEUInformationContent(const EUInformation& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfExpandedNodeId' */
				EnumModelDesignerStatus encodeListOfExpandedNodeIdContent(const std::vector<ExpandedNodeId>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfLocalizedText' */
				EnumModelDesignerStatus encodeListOfLocalizedTextContent(const std::vector<LocalizedText>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfDataValue' */
				EnumModelDesignerStatus encodeListOfDataValueContent(const std::vector<DataValue>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfArgument' */
				EnumModelDesignerStatus encodeListOfArgumentContent(const std::vector<Argument>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfEnumValueType' */
				EnumModelDesignerStatus encodeListOfEnumValueTypeContent(const std::vector<EnumValueType>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfApplicationDescription' */
				EnumModelDesignerStatus encodeListOfApplicationDescriptionContent(const std::vector<ApplicationDescription>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSignedSoftwareCertificate' */
				EnumModelDesignerStatus encodeListOfSignedSoftwareCertificateContent(const std::vector<SignedSoftwareCertificate>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfReferenceDescription' */
				EnumModelDesignerStatus encodeListOfReferenceDescriptionContent(const std::vector<ReferenceDescription>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfRelativePathElement' */
				EnumModelDesignerStatus encodeListOfRelativePathElementContent(const std::vector<RelativePathElement>& value, EncoderContextPtr context);
#if TB5_FILTER
				/*! Encodes the OPC UA type 'ListOfContentFilterElement' */
				EnumModelDesignerStatus encodeListOfContentFilterElementContent(const std::vector<ContentFilterElement>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfContentFilter' */
				EnumModelDesignerStatus encodeListOfContentFilterContent(const std::vector<ContentFilter>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSimpleAttributeOperand' */
				EnumModelDesignerStatus encodeListOfSimpleAttributeOperandContent(const std::vector<SimpleAttributeOperand>& value, EncoderContextPtr context);
#endif
				/*! Encodes the OPC UA type 'ListOfSessionDiagnosticsDataType' */
				EnumModelDesignerStatus encodeListOfSessionDiagnosticsDataTypeContent(const std::vector<SessionDiagnosticsDataType>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSessionSecurityDiagnosticsDataType' */
				EnumModelDesignerStatus encodeListOfSessionSecurityDiagnosticsDataTypeContent(const std::vector<SessionSecurityDiagnosticsDataType>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSubscriptionDiagnosticsDataType' */
				EnumModelDesignerStatus encodeListOfSubscriptionDiagnosticsDataTypeContent(const std::vector<SubscriptionDiagnosticsDataType>& value, EncoderContextPtr context);
#if TB5_ALARMS
				/*! Encodes the OPC UA type 'ListOfModelChangeStructureDataType' */
				EnumModelDesignerStatus encodeListOfModelChangeStructureDataTypeContent(const std::vector<ModelChangeStructureDataType>& value, EncoderContextPtr context);
				/*! Encodes the OPC UA type 'ListOfSemanticChangeStructureDataType' */
				EnumModelDesignerStatus encodeListOfSemanticChangeStructureDataTypeContent(const std::vector<SemanticChangeStructureDataType>& value, EncoderContextPtr context);
#endif
			}
		}
	}
}

#endif // UATYPES_ENCODER_GENERATED_H
