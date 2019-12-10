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

#ifndef UA_NODE_SET2_EXPORTER_H
#define UA_NODE_SET2_EXPORTER_H

#include "ServerBaseNode.h"
#include "EncoderContext.h"
#include <set>

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			// Forward declaration
			class UaNodeSet2Exporter;
			typedef ObjectPointer<UaNodeSet2Exporter> UaNodeSet2ExporterPtr;
			typedef ObjectPointer<const UaNodeSet2Exporter> UaNodeSet2ExporterConstPtr;

			/*! The UaNodeSet2Exporter creates a NodeSet2 XML file from existing nodes. */
			class TBC_EXPORT UaNodeSet2Exporter
				: public Base
			{
			public:
				/*! Constructs a new UaNodeSet2Exporter instance */
				static UaNodeSet2ExporterPtr create();
				/*! Destructor */
				virtual ~UaNodeSet2Exporter();

				/*! Returns the location and name of the NodeSet2 XML output file */
				tstring getOutputFile() const;
				/*! Sets the location and name of the NodeSet2 XML output file and determines
				* the name for a temporary intermediate file */
				void setOutputFile(const tstring& filename);

				/*! Returns the location and name of the temporary intermediate output file */
				tstring getTempOutputFile() const;

				/*! Returns the namespaces that shall be exported */
				const std::vector<tstring>& getNamespaces() const;
				/*! Sets the namespaces that shall be exported */
				void setNamespaces(const std::vector<tstring>& namespaceUris);

				/*! Returns the global extensions that shall be exported */
				const std::vector<XmlElement>& getGlobalExtensions() const;
				/*! Sets the global extensions that shall be exported */
				void setGlobalExtensions(const std::vector<XmlElement>& globalExtensions);
				/*! Returns the models that shall be exported */
				const std::vector<XmlElement>& getModels() const;
				/*! Sets the models that shall be exported */
				void setModels(const std::vector<XmlElement>& models);

				/*! Create the NodeSet2 XML file with the content of the nodes of the configured namespaces */
				EnumModelDesignerStatus beginExport();

				/*! does the cleanup of the exporter */
				void endExport();

				EnumModelDesignerStatus waitForEnd();

				void setCustomExportResult(EnumModelDesignerStatus exportResult);

				/*! Create the NodeSet2 XML file with the content of the nodes of the configured namespaces */
				EnumModelDesignerStatus exportNodes();

				/*! Verifies that the given nodeID is within the list of exported namespaces */
				EnumStatusCode checkNamespaces(const NodeId &nodeId);

				EnumModelDesignerStatus exportDataType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract);
				/*! Encodes a Method node to the NodeSet file
				* @param node		The Method node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportMethod(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool executable);
				/*! Encodes a Object node to the NodeSet file
				* @param node		The Object node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportObject(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					OTUInt8 eventNotifier);
				/*! Encodes a ObjectType node to the NodeSet file
				* @param node		The ObjectType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportObjectType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract);
				/*! Encodes a ReferenceType node to the NodeSet file
				* @param node		The ReferenceType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportReferenceType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, bool isSymmetric, const LocalizedText &inverseName);
				/*! Encodes a Variable node to the NodeSet file
				* @param node		The Variable node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportVariable(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					EnumAccessLevel accessLevel, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, double minimumSamplingInterval, bool isHistorizing, const IValue *pValue);
				/*! Encodes a VariableType node to the NodeSet file
				* @param node		The VariableType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportVariableType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, const IValue *pValue);
				/*! Encodes a View node to the NodeSet file
				* @param node		The View node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus exportView(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool containsNoLoops, OTUInt8 eventNotifier);


			private:
				/*! Collects the required namespaces and Alias strings.
				*
				* Collected information are:
				* @li referenced namespaces (in NodeId and QualifiedName)
				* @li Alias strings for NodeId (data types, reference types, ...)
				*
				* @param nodeId			The NodeId of the node
				* @param browseName		The BrowseName of the node
				* @param references		The references of the Node */
				EnumModelDesignerStatus collectNamespacesAndAliases_Common(const NodeId& nodeId, const QualifiedName& browseName, const std::vector<ReferenceDescription>& references);
				/*! Collects the namespace and alias of the dataType for Variables and VariableTypes
				* @param dataType		The dataType attribute */
				EnumModelDesignerStatus collectNamespacesAndAliases_DataType(const NodeId& dataType);
				/*! Collects the namespace and alias ParentNodeId for instances
				* @param parentNodeId		The ParentNodeId */
				EnumModelDesignerStatus collectNamespacesAndAliases_ParentNodeId(const NodeId& parentNodeId);

				/*! Collects all nodes from the address space, that belong the the specified namespaces
				* @param nodes			Returns the found nodes */
				EnumModelDesignerStatus collectNodes();
				/*! Default constructor */
				UaNodeSet2Exporter();

				EnumModelDesignerStatus setupWriter(tstring outputFileName);
				/*! Writes the global UANodeSet start element with all attributes */
				EnumModelDesignerStatus writeUaNodeSetStartElement();
				EnumModelDesignerStatus writeNamespaceTable();
				EnumModelDesignerStatus writeServerUris();

				EnumModelDesignerStatus writeAliasTable(bool createAlways = false);
				EnumModelDesignerStatus tearDownWriter();

				/*! Copies the entire content of the temporary file to the target output file, but with an updated namespaces and aliases section */
				EnumModelDesignerStatus writeTargetFile();

				/*! Encodes a DataType node to the NodeSet file
				* @param node		The DataType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaDataType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, EncoderContextPtr context);
				/*! Encodes a Method node to the NodeSet file
				* @param node		The Method node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaMethod(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool executable, EncoderContextPtr context);
				/*! Encodes a Object node to the NodeSet file
				* @param node		The Object node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaObject(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					OTUInt8 eventNotifier, EncoderContextPtr context);
				/*! Encodes a ObjectType node to the NodeSet file
				* @param node		The ObjectType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaObjectType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, EncoderContextPtr context);
				/*! Encodes a ReferenceType node to the NodeSet file
				* @param node		The ReferenceType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaReferenceType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, bool isSymmetric, const LocalizedText &inverseName, EncoderContextPtr context);
				/*! Encodes a Variable node to the NodeSet file
				* @param node		The Variable node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaVariable(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					EnumAccessLevel accessLevel, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, double minimumSamplingInterval, bool isHistorizing, const IValue *pValue,
					EncoderContextPtr context);
				/*! Encodes a VariableType node to the NodeSet file
				* @param node		The VariableType node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaVariableType(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool isAbstract, OTInt32 valueRank, const NodeId &dataType, const std::vector<OTUInt32>& arrayDimensions, const IValue *pValue,
					EncoderContextPtr context);
				/*! Encodes a View node to the NodeSet file
				* @param node		The View node that shall be encoded
				* @param context	The additional information required for encoding */
				EnumModelDesignerStatus encodeUaView(const NodeId &nodeId, const QualifiedName &browseName, EnumWriteMask writeMask, const NodeId &parentNodeId,
					const LocalizedText &displayName, const LocalizedText &description, const std::vector<ReferenceDescription> &references, const std::vector<XmlElement> &extensions,
					bool containsNoLoops, OTUInt8 eventNotifier, EncoderContextPtr context);

				/*! Custom error function for libxml2 to prevent errors printed to stderr */
				static void customErrorFunction(void* ctx, const char * msg, ...);
				PRIVATE_EXPORTED_STL_CONTAINER(std::set<NodeId> m_exportedNodes)
				PRIVATE_EXPORTED_STL_CONTAINER(EncoderContextPtr m_encoderContext)
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<Server::BaseNodePtr> m_nodes)
				/*! The output file */
				PRIVATE_EXPORTED_STL_CONTAINER(tstring m_outputFile)
				PRIVATE_EXPORTED_STL_CONTAINER(tstring m_tempOutputFile)
				/*! The namespaces to export */
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<tstring> m_namespaceUris)
				/*! The global extensions to export */
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<XmlElement> m_globalExtensions)
				/*! The models to export */
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<XmlElement> m_models)

				EnumModelDesignerStatus m_customExportStatus;

				void* m_pCompletionEvent;
			};
		}
	}
}

#endif	// UA_NODE_SET2_EXPORTER_H
