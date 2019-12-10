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

#ifndef UANODESET2ENCODER_H
#define UANODESET2ENCODER_H

#include "EncoderContext.h"
#include "ServerBaseNode.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			namespace UANodeSet2Encoder
			{
				/*! Encodes the ArrayDimensions
				*
				* @param value		The array dimensions to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeArrayDimensions(const tstring& name, const std::vector<OTUInt32>& value, EncoderContextPtr context);

				/*! Encodes a list of Models
				*
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeListOfModels(const std::vector<XmlElement>& models, EncoderContextPtr context);

				/*! Encodes a list of Extensions
				*
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeListOfExtensions(const std::vector<XmlElement>& extensions, EncoderContextPtr context);

				/*! Encodes a list of References
				*
				* @param node		The input node
				* @param context	The context information required for encoding
				*
				* @note	Skips backward references for certain reference types
				*		Encodes nothing if there are no references */
				TBC_EXPORT EnumModelDesignerStatus encodeListOfReferences(const std::vector<ReferenceDescription> &references, EncoderContextPtr context);
				/*! Encodes a LocalizedText as a sequence of elements (one element per translation)
				*
				* @param name		The name of the LocalizedText element
				* @param value		The value to encode
				* @param context	The context information required for encoding
				*
				* @note It Encodes nothing, if the LocalizedText has no translations */
				TBC_EXPORT EnumModelDesignerStatus encodeLocalizedTextSequence(const tstring& name, const LocalizedText& value, EncoderContextPtr context);

				/*! Encodes UaNode Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaNodeAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, EncoderContextPtr context);

				/*! Encodes UaNode Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaNodeElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions, EncoderContextPtr context);

				/*! Encodes UADataType Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaDataTypeElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions, EncoderContextPtr context);

				/*! Encodes UaInstance Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaInstanceAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId, EncoderContextPtr context);

				/*! Encodes UaMethod Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaMethodAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					bool executable, EncoderContextPtr context);

				/*! Encodes UaObject Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaObjectAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					OTUInt8 eventNotifier, EncoderContextPtr context);

				/*! Encodes UaReferenceType Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaReferenceTypeAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					bool isAbstract, bool isSymmetric, EncoderContextPtr context);

				/*! Encodes UaReferenceType Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaReferenceTypeElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions, const LocalizedText &inverseName, EncoderContextPtr context);

				/*! Encodes UaType Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaTypeAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					bool isAbstract, EncoderContextPtr context);

				/*! Encodes UaVariable Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaVariableAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					EnumAccessLevel accessLevel, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, double minimumSamplingInterval, bool isHistorizing,
					EncoderContextPtr context);

				/*! Encodes UaVariable Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaVariableElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					const IValue *pValue, EncoderContextPtr context);

				/*! Encodes UaVariableType Attributes
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaVariableTypeAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					bool isAbstract, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, EncoderContextPtr context);

				/*! Encodes UaVariableType Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaVariableTypeElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					const IValue *pValue, EncoderContextPtr context);

				/*! Encodes UaVariableType Attributes
				*bool isAbstract,
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaViewAttributes(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					bool containsNoLoops, OTUInt8 eventNotifier, EncoderContextPtr context);

				/*! Encodes UaView Elements
				*
				* @param node		The input node
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUaViewElements(const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions, EncoderContextPtr context);

				/*! Encodes the Value element
				*
				* @param value		The array dimensions to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeValue(const IValue* value, EncoderContextPtr context);

			}
		}
	}
}
#endif // UANODESET2ENCODER_H
