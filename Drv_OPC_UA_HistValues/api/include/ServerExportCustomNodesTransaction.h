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

#ifndef SERVEREXPORTCUSTOMNODESTRANSACTION_H
#define SERVEREXPORTCUSTOMNODESTRANSACTION_H

#include "ModelCompiler/ErrorEnums.h"
#include "Base.h"
#include "ReferenceDescription.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{

			/*! A transaction to provide data of custom nodes during a NodeSet2 export.
			* Providing data via this transaction allows to export nodes, which are not stored within the server's address space,
			* or export nodes with a different content.
			*
			* The export of the nodes in the server's address space will take place after the handling of the custom nodes is done.
			* The server application must ensure to always complete this transaction (see complete()).
			*
			* @see Server::AddressSpaceRoot::exportNodes() */
			class TBC_EXPORT ExportCustomNodesTransaction
				: public Base
			{
			public:
				//! Constructor
				ExportCustomNodesTransaction(void* exporter);

				~ExportCustomNodesTransaction();

				/*! Return the namespace URIs, for which the nodes shall be exported */
				const std::vector<tstring>& getNamespacesToExport();

				/*! Marks this transaction as completed, which means that all custom nodes
				* were encoded and the exporter will continue with the nodes of the address space.
				*
				* @return   EnumModelDesignerStatus
				* @param operationStatus A status to indicate, whether an error occurred or everything went good.
				*                        Providing a bad status will abort the export.
				* @note This method should only be called once, every further call has no effect and returns an error. */
				EnumModelDesignerStatus complete(EnumModelDesignerStatus operationStatus);

				/*! exports a method with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported node
				* @param parentNodeId the NodeId of the parent Node
				* @param browseName QualifiedName of the Method
				* @param displayName as LocalizedText of the Method
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param executable executable flag default value is true
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomUaMethod(const NodeId &nodeId, const NodeId &parentNodeId, const QualifiedName &browseName,
					const LocalizedText &displayName, const LocalizedText &description, OTUInt32 writeMask, OTBoolean executable,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a view with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported node
				* @param parentNodeId the NodeId of the parent Node
				* @param browseName QualifiedName of the View
				* @param displayName as LocalizedText of the View
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param eventNotifier as Bit mask see EnumEventNotifier, default value is 0
				* @param containsNoLoops flag if the view contains Loops, default value is false
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomUaView(const NodeId &nodeId, const NodeId &parentNodeId, const QualifiedName &browseName,
					const LocalizedText &displayName, const LocalizedText &description, OTUInt32 writeMask, OTUInt8 eventNotifier, OTBoolean containsNoLoops,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a DataType with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported DataType
				* @param browseName QualifiedName of the DataType
				* @param displayName as LocalizedText of the View
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param isAbstract flag if the DataType is abstract, default value is false
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomDataType(const NodeId &nodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, OTBoolean isAbstract,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a ReferenceType with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported ReferenceType
				* @param browseName QualifiedName of the ReferenceType
				* @param displayName as LocalizedText of the View
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param isAbstract flag if the ReferenceType is abstract, default value is false
				* @param symmetric flag if referenceType is symmetric, default value is false
				* @param inverseName as LocalizedText can be NULL
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomReferenceType(const NodeId &nodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, OTBoolean isAbstract, OTBoolean symmetric, const LocalizedText &inverseName,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a ObjectType with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported ObjectType
				* @param browseName QualifiedName of the ObjectType
				* @param displayName as LocalizedText of the View
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param isAbstract isAbstract flag if the ObjectType is abstract, default value is false
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomObjectType(const NodeId &nodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, OTBoolean isAbstract,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a Object with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported Object
				* @param parentNodeId the NodeId of the parent Node
				* @param browseName QualifiedName of the Object
				* @param displayName as LocalizedText of the View
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param eventNotifier as Bit mask see EnumEventNotifier, default value is 0
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomObject(const NodeId &nodeId, const NodeId &parentNodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, OTUInt8 eventNotifier,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a VariableType with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId NodeId of the exported Variable
				* @param browseName QualifiedName of the Variable
				* @param displayName as LocalizedText of the Variable
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param dataType NodeId of the DataType default value is numericNodeId with ns = 0, i = 24
				* @param valueRank Sets whether the variable's value is an array and if, how many dimensions the array has,
				*			default value is -1
				* @param arrayDimensions Sets a field of integer values describing the length of each array dimension if
				*			the variable has an array value, default value is NULL
				* @param pValue a value of the VariableType, default value is NULL
				* @param isAbstract flag if the VariableType is abstract, default value is false
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomVariableType(const NodeId &nodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, const NodeId &dataType, OTInt32 valueRank, const std::vector<OTUInt32> &arrayDimensions,
					const IValue *pValue, OTBoolean isAbstract, const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

				/*! exports a VariableType with the provided attributes
				*
				* @return   EnumModelDesignerStatus
				*
				* @param nodeId  NodeId of the exported Variable
				* @param parentNodeId the NodeId of the parent Node
				* @param browseName QualifiedName of the Variable
				* @param displayName as LocalizedText of the Variable
				* @param description as LocalizedText can be NULL
				* @param writeMask write mask of the node which indicates the attributes that can be written by a client,
				*			default value is 0 (none of the attributes are writable by default)
				* @param dataType NodeId of the DataType default value is numericNodeId with ns = 0, i = 24
				* @param valueRank Sets whether the variable's value is an array and if, how many dimensions the array has,
				*			default value is -1
				* @param arrayDimensions Sets a field of integer values describing the length of each array dimension if
				*			the variable has an array value, default value is NULL
				* @param pValue a value of the VariableType, default value is NULL
				* @param accessLevel Sets the access level of the variable that indicates how the variable's value can be
				*			accessed and if it contains current and/or historic data, default value is 1
				* @param minimumSamplingInterval Sets the value of the MinimumSamplingInterval attribute, default value is 0
				* @param historizing Sets the Historizing attribute that indicates whether the server is actively collecting
				*			data for the history of the variable, default value is false
				* @param references array of ReferenceDescription
				* @param extensions array of ByteString
				*
				* @note Only the NodeId of the ReferenceType, the isForward flag and the NodeId of the target are used while exporting
				* one ReferenceDescription of the references Array. All other attributes of the ReferenceDescription are not touched. */
				EnumModelDesignerStatus exportCustomVariable(const NodeId &nodeId, const NodeId &parentNodeId, const QualifiedName &browseName, const LocalizedText &displayName,
					const LocalizedText &description, OTUInt32 writeMask, const NodeId &dataType, OTInt32 valueRank, const std::vector<OTUInt32> &arrayDimensions,
					const IValue *pValue, OTUInt8 accessLevel, OTDouble minimumSamplingInterval, OTBoolean historizing,
					const std::vector<ReferenceDescription> &references, const std::vector<ByteString> &extensions);

			private:
				/*! Forbid use assignment operator */
				ExportCustomNodesTransaction& operator=(const ExportCustomNodesTransaction&);
				/*! Forbid use of copy constructor */
				ExportCustomNodesTransaction(const ExportCustomNodesTransaction&);

				void* m_exporter;
				EnumModelDesignerStatus m_completionStatus;
			};
			/*! @typedef ExportCustomNodesTransactionPtr
			 * Smartpointer for ExportCustomNodesTransaction */
			typedef ObjectPointer<ExportCustomNodesTransaction> ExportCustomNodesTransactionPtr;

			/*! @typedef ExportCustomNodesTransactionConstPtr
			 * const Smartpointer for ExportCustomNodesTransaction */
			typedef ObjectPointer<const ExportCustomNodesTransaction> ExportCustomNodesTransactionConstPtr;

		} // end NodeSet2Export
	} // end Server
} // end SoftingOPCToolbox5

#endif // SERVEREXPORTCUSTOMNODESTRANSACTION_H
