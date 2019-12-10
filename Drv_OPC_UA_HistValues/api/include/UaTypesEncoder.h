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

#ifndef UATYPES_ENCODER_H
#define UATYPES_ENCODER_H

#include <Enums.h>
#include <map>

#include "ModelCompiler/ErrorEnums.h"
#include "EncoderContext.h"

namespace SoftingOPCToolbox5
{
	class LocalizedText;
	class Guid;
	class NodeId;
	class QualifiedName;
	class ExpandedNodeId;
	class NumericRange;
	class ContentFilterElement;
	class TimeZone;
	class Value;
	class AttributeOperand;
	class SimpleAttributeOperand;
}

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			namespace UaTypesEncoder
			{
				/*! Denotes the XML namespace URI that is supported by the parser functions. */
				static const xmlChar namespaceUri[] = "http://opcfoundation.org/UA/2008/02/Types.xsd";

				/*! Encodes the OPC UA type 'LocalizedText'. */
				EnumModelDesignerStatus encodeLocalizedTextContent(const LocalizedText& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'Guid'. */
				EnumModelDesignerStatus encodeGuidContent(const Guid& value, EncoderContextPtr context);

				/*! Encodes the OPC UA data type 'NodeId'. */
				EnumModelDesignerStatus encodeNodeIdContent(const NodeId& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'QualifiedName' */
				EnumModelDesignerStatus encodeQualifiedNameContent(const QualifiedName& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ExpandedNodeId'. */
				EnumModelDesignerStatus encodeExpandedNodeIdContent(const ExpandedNodeId& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'StatusCode'. */
				EnumModelDesignerStatus encodeStatusCodeContent(const EnumStatusCode& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ListOfStatusCode'. */
				EnumModelDesignerStatus encodeListOfStatusCodeContent(const std::vector<EnumStatusCode>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'NumericRange'. */
				EnumModelDesignerStatus encodeNumericRangeContent(const NumericRange& value, EncoderContextPtr context);

#if TB5_FILTER
				/*! Encodes the OPC UA type 'ContentFilterElement' */
				EnumModelDesignerStatus encodeContentFilterElementContent(const ContentFilterElement& value, EncoderContextPtr context);
#endif
				/*! Encodes the OPC UA type 'XmlElement'. */
				EnumModelDesignerStatus encodeXmlElementContent(const XmlElement& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ListOfXmlElement'. */
				EnumModelDesignerStatus encodeListOfXmlElementContent(const std::vector<XmlElement>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'TimeZoneDataContent' */
				EnumModelDesignerStatus encodeTimeZoneDataTypeContent(const TimeZone& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ListOfTimeZoneDataContent' */
				EnumModelDesignerStatus encodeListOfTimeZoneDataTypeContent(const std::vector<TimeZone>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'Variant'. */
				EnumModelDesignerStatus encodeVariantContent(const Value& value, EncoderContextPtr context, bool topLevel = false);

				/*! Encodes the OPC UA type 'ListOfVariant'. */
				EnumModelDesignerStatus encodeListOfVariantContent(const std::vector<Value>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ListOfNodeId' */
				EnumModelDesignerStatus encodeListOfNodeIdContent(const std::vector<NodeId>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'ListOfQualifiedName' */
				EnumModelDesignerStatus encodeListOfQualifiedNameContent(const std::vector<QualifiedName>& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'X509IdentityToken' */
				EnumModelDesignerStatus encodeX509IdentityTokenContent(const X509IdentityToken& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'IssuedIdentityToken' */
				EnumModelDesignerStatus encodeIssuedIdentityTokenContent(const IssuedIdentityToken& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'X509IdentityToken' */
				EnumModelDesignerStatus encodeAttributeIdContent(EnumAttributeId value, EncoderContextPtr context);

#if TB5_FILTER
				/*! Encodes the OPC UA type 'AttributeOperand' */
				EnumModelDesignerStatus encodeAttributeOperandContent(const AttributeOperand& value, EncoderContextPtr context);

				/*! Encodes the OPC UA type 'SimpleAttributeOperand' */
				EnumModelDesignerStatus encodeSimpleAttributeOperandContent(const SimpleAttributeOperand& value, EncoderContextPtr context);
#endif
				/*! structure to hold the name and value of a single enumeration */
				typedef struct EnumValues
				{
					/*! Holds the name of a single enumeration value as it appears in an XML file. */
					const xmlChar* pEnumText;
					/*! Holds the numeric value of a single enumeration value as it appears in an XML File. */
					OTUInt32 enumValue;
				}
				EnumValues;
			}
		}
	}
}

#endif // UATYPES_ENCODER_H
