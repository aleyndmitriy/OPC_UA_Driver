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

#ifndef SERVERADDRESSSPACEROOT_H
#define SERVERADDRESSSPACEROOT_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ByteString.h"

#include "ImportNodeDescription.h"
#include "ModelCompiler/ErrorEnums.h"
#include "ServerExportCustomNodesTransaction.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class DataTypeDescription;
	typedef ObjectPointer<const DataTypeDescription> DataTypeDescriptionConstPtr;

	namespace Server
	{
		class Object;
		class BaseNode;
		typedef ObjectPointer<BaseNode> BaseNodePtr;
		class ObjectType;
	}

	namespace Server
	{
		namespace ModelDesigner
		{
			class ModelDesignerRoot;
		}
		/*! The AddressSpaceRoot provides methods to manage the address space of an OPC UA server.
		*
		* This class is a singleton. Please use AddressSpaceRoot::instance() to retrieve an instance
		* of this class. */
		class TBC_EXPORT AddressSpaceRoot
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AddressSpaceRoot(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			AddressSpaceRoot(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~AddressSpaceRoot();

			/*! Returns the singleton instance */
			static ObjectPointer<AddressSpaceRoot> instance();
			/*! @overload */
			static ObjectPointer<const AddressSpaceRoot> constInstance();

			/*! Creates the singleton instance */
			static EnumStatusCode create();

			/*! Destroys the singleton instance */
			static EnumStatusCode destroy();

			//////////////////////////////////////////////////////////////////////////
			// Namespace management methods
			//////////////////////////////////////////////////////////////////////////

			/*! Returns a string table containing all known namespaces and their corresponding namespace indices.
			*
			* @see addNamespace() */
			ObjectPointer<const StringTable> getNamespaces() const;
			/*! Adds a new namespace to the server's list of namespaces. It is recommended to
			* add all required namespaces before exposing the address space to clients.
			*
			* A namespace is identified by a URI and defines the scope for node identifiers (NodeIds)
			* and browse names. Namespaces are numbered consecutively, starting with zero.
			* The list of defined namespaces is exposed to clients as variable (EnumNumericNodeId_Server_NamespaceArray).
			*
			* The following namespaces are reserved and are always defined when the server application starts:
			* @li	The namespace "http://opcfoundation.org/UA/" is reserved for identifiers defined by the
			*		OPC UA standard informations models and is always assigned the index 0.
			* @li	The namespace "urn:Softing/UA Toolkit" is reserved for identifiers that are
			*		defined by the SDK. It is always assigned the index 1.
			*
			* @param[in]	namespaceUri	The URI identifying the namespace
			* @param[out]	pIndex			The index that the SDK assigned to this namespace.
			*								Clients use the index rather than the URI to refer to a namespace. */
			EnumStatusCode addNamespace(const tstring& namespaceUri, OTUInt16* pIndex);

			/*! Returns a string table containing all known server URIs and their corresponding indices.
			*
			* @see addServerUri() */
			ObjectPointer<const StringTable> getServerUris() const;
			/*! Adds a new server URI to the array of known servers array. It is recommended to
			* add all required server URIs before exposing the address space to clients.
			*
			* The server URIs are used to identify nodes of different servers using ExpandedNodeIds.
			* Server URIs are numbered consecutively, starting with zero where the zero index always identifies the local server.
			* The list of defined server URIs is exposed to clients as variable (EnumNumericNodeId_Server_ServerArray).
			*
			* @param[in]	serverUri	The URI identifying the server
			* @param[out]	pIndex		The index that the SDK assigned to this server URI */
			EnumStatusCode addServerUri(const tstring& serverUri, OTUInt16* pIndex);


			/*! Returns the index of the SDK namespace
			*
			* @param[out]	pIndex		The index of the SDK namespace */
			void getToolkitNamespaceIndex(OTUInt16* pIndex) const;

			//////////////////////////////////////////////////////////////////////////
			// Node management methods
			//////////////////////////////////////////////////////////////////////////

			/*! Creates a NodeId.
			*
			* @param newNodeId		The nodeId to be created
			* @param identifierType	The type of NodeId to create
			* @param namespaceIndex	The namespace index of the created NodeId */
			virtual EnumStatusCode createNodeId(NodeId& newNodeId, EnumIdentifierType identifierType, OTUInt16 namespaceIndex);
			/*! Creates and assigns a NodeId to the given @p targetNode.
			*
			* @param targetNode		The targetNode to which the new NodeId is assigned
			* @param identifierType	The type of NodeId to create
			* @param namespaceIndex	The namespace index of the created NodeId */
			virtual EnumStatusCode createNodeId(Server::BaseNode* targetNode, EnumIdentifierType identifierType, OTUInt16 namespaceIndex);

			/*! @deprecated Please use the create() method of the most matching API class instead */
			DEPRECATED(virtual EnumStatusCode createObjectInstance(Server::ObjectType* typeNode, ObjectPointer<Server::Object>& objectNode));

			/*! Returns the root node of the address space. */
			ObjectPointer<Server::Object> getRoot();
			/*! @overload */
			ObjectPointer<const Server::Object> getRoot() const;

			/*! Returns the server's "Objects" folder. The "Objects" folder is the browse entry point
			* for all objects of an OPC UA server application. */
			ObjectPointer<Server::Object> getObjectsFolder();
			/*! @overload */
			ObjectPointer<const Server::Object> getObjectsFolder() const;

			/*! Returns the server's "Server" object. The "Server" object is the browse entry point
			* for all information about the server itself. */
			ObjectPointer<Server::Object> getServerObject();
			/*! @overload */
			ObjectPointer<const Server::Object> getServerObject() const;

			/*! Returns the node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space. */
			ObjectPointer<Server::BaseNode> getNode(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNode(const INodeId* nodeId) const;

			/*! Returns the object node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_Object. */
			ObjectPointer<Server::Object> getObject(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::Object> getObject(const INodeId* nodeId) const;

			/*! Returns the variable node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_Variable. */
			ObjectPointer<Server::Variable> getVariable(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::Variable> getVariable(const INodeId* nodeId) const;

			/*! Returns the method node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_Method. */
			ObjectPointer<Server::Method> getMethod(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::Method> getMethod(const INodeId* nodeId) const;

			/*! Returns the object type node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_ObjectType. */
			ObjectPointer<Server::ObjectType> getObjectType(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::ObjectType> getObjectType(const INodeId* nodeId) const;

			/*! Returns the variable type node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_VariableType. */
			ObjectPointer<Server::VariableType> getVariableType(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::VariableType> getVariableType(const INodeId* nodeId) const;

			/*! Returns the reference type node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_ReferenceType. */
			ObjectPointer<Server::ReferenceType> getReferenceType(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::ReferenceType> getReferenceType(const INodeId* nodeId) const;

			/*! Returns the data type node with the given @p nodeId. This method returns NULL if the requested node
			* does not exist in the server's address space or the node is not of node class EnumNodeClass_DataType. */
			ObjectPointer<Server::DataType> getDataType(const INodeId* nodeId);
			/*! @overload */
			ObjectPointer<const Server::DataType> getDataType(const INodeId* nodeId) const;

			/*! Returns the description for a custom data type.
			*
			* The custom data types are those types which don't belong to the well known data types of the OPC Foundation.
			* The custom data types are typically defined by some companion specification, the server or a third party.
			*
			* @note	If the NodeId does not refer to a data type node or the data type node does not have
			*		a data type description, then NULL is returned.
			* @see DataTypeDescription, DataType::setDataTypeDescription() */
			DataTypeDescriptionConstPtr getDataTypeDescription(const INodeId& dataTypeId) const;

			/*! Returns the description for a custom data type (does not work for enumerations).
			*
			* The custom data types are those types which don't belong to the well known data types of the OPC Foundation.
			* The custom data types are typically defined by some companion specification, the server or a third party.
			*
			* @param [in]	value				The value containing a structured value The nodeId of the data type.
			* @param [out]	dataTypeDescription	The DataTypeDescription, describing the kind of custom data type and its fields.
			*
			* @see DataTypeDescription, DataType::setDataTypeDescription() */
			EnumStatusCode getDataTypeDescription(const IValue* value, DataTypeDescriptionConstPtr& dataTypeDescription) const;

			/*! starts the validation of the AddressSpace
			 * The UAObjects and UAVariables are checked if they reference to the as mandatory specified properties.
			 * If a reference is missing the onValidateError callback method is called
			 * @see onValidateError() */
			EnumStatusCode validate();
			/*! Imports all nodes that are defined in an XML file which complies with
			* the NodeSet2 XML schema defined by the OPC Foundation.
			*
			* @param xmlBuffer					A buffer containing the NodeSet2 XML as string.
			*									If xmlBuffer is NULL, the file fileName must exists and contain the NodeSet2 XML.
			* @param fileName					The path to the NodeSet2 XML file which contains a set of OPC UA node definitions.
			*									If xmlBuffer is not NULL, this name is just used for error reporting.
			* @param apiObjectCreationOption	Defines whether to create an API object for imported nodes directly after they
			*									were imported using the SoftingOPCToolbox5::Creator or to create them only on demand.
			*									The default value is EnumApiObjectCreation_AllExceptDefaultNodes.
			* @param extensions					A vector of XmlElements containing the XML content of the global custom extensions of the node set.
			* @param nodeSetVersion				The version of the imported node set.
			* @param lastModified				The date and time of the node set's last modification.
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file.
			*		The SoftingOPCToolbox5::Creator usually creates API object on demand e.g. during a AddressSpaceRoot::getNode() call. The
			*		parameter @p apiObjectCreationOption allows to automatically call the creator for example to initialize a
			*		underlying system in a derived class as soon as a related node is created. */
			EnumModelDesignerStatus importNodes(const char* xmlBuffer, const tstring& fileName, EnumApiObjectCreation apiObjectCreationOption, std::vector<XmlElement>& extensions, tstring& nodeSetVersion, DateTime& lastModified);
			/*! @overload */
			EnumModelDesignerStatus importNodes(const tstring& fileName, EnumApiObjectCreation apiObjectCreationOption, std::vector<XmlElement>& extensions, tstring& nodeSetVersion, DateTime& lastModified);
			/*! @overload */
			EnumModelDesignerStatus importNodes(const tstring& fileName, EnumApiObjectCreation apiObjectCreationOption);
			/*! @overload */
			EnumModelDesignerStatus importNodes(const tstring& fileName);

			/*! Creates a NodeSet2 XML file that contains the nodes of the specified namespaces
			*
			* @param namespaceUris	The namespaces to export
			* @param filename		The location and name of the NodeSet2 XML file to generate
			* @param extensions		The global extensions to be exported
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			EnumModelDesignerStatus exportNodes(const std::vector<tstring>& namespaceUris, const tstring& filename, const std::vector<XmlElement>& extensions);
			/*! @overload */
			EnumModelDesignerStatus exportNodes(const std::vector<tstring>& namespaceUris, const tstring& filename);

			/*! This callback method is triggered whenever an export of the AddressSpace is executed.
			 *
			 * Application shall override this method to iterate over the dynamic Nodes and call the
			 * corresponding exportCustom[NodeType] method on the provided transaction
			 *
			 * @param transactionPtr	NodeSet2Export::ExportCustomNodesTransaction the transaction providing the customExport methods
			 *
			 * @note	This function is only available if the SDK was configured with model designer support.
			 *		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			virtual void handleExportCustomNodes(NodeSet2Export::ExportCustomNodesTransactionPtr transactionPtr);

			/*! This callback method is triggered whenever the XML importer encounters an error condition.
			*
			* Applications can override this method in order to process errors which are encountered
			* during the import of an XML node set definition.
			*
			* A trace message for the trace group EnumTraceGroup_ModelDesigner is produced in any case.
			*
			* @param fileName		The path to the XML file which contains a set of OPC UA node definitions
			* @param lineNumber		The line number at which the error was encountered or -1 if the line number is unknown
			* @param severity		Indicates the severity of the encountered error
			* @param errorCode		Indicates the reason for the error
			* @param errorMessage	Contains a descriptive text of the error condition
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			virtual void onImportNodesError(const tstring& fileName, int lineNumber, EnumTraceLevel severity, EnumModelDesignerStatus errorCode, const tstring& errorMessage);

			/*! This callback method is triggered whenever the XML importer encounters a duplicate Node.
			*
			* Applications can override this method in order to change the handling of duplicate Nodes.
			* The Application has the possibilities to ignore the importing node, merge attributes of the existing node
			* or even remove the existing node and let the import create the new node.
			*
			* @param existingNode				The already existing Node
			* @param pImportedNodeDescription	A description for the current import node. This parameter can be cast to a
			*									matching subtype, depending on the current node class.
			* @param xmlTag						The xml tag of the imported Node
			* @return							A bad result rejects the duplicate node and causes the NodeSet2Import
			*									to fail. A good status code indicates that the node was successfully handled.
			*
			* @note	If the NodeSet2Import fails, the Application has the responsibility to perform an appropriate rollback
			*		for attribute modifications of modified or replaced nodes, which were done by this callback.
			*		The references are correctly rolled back by the SDK.
			* @note	An overridden method doesn't have to handle the references, they will be added by the NodeSet2Import
			*		and even references of a deleted node will be reestablished to the imported node.
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			virtual EnumModelDesignerStatus onImportDuplicateNode(BaseNodePtr existingNode, const NodeSet2Import::ImportUANodeDescription* pImportedNodeDescription, const XmlElement &xmlTag);

			/*! This method enables the model designer back end.
			*
			* The model designed can be used to modify an address space.
			* The model designer back end uses OPC UA methods to alter the address space, where the methods are located below a model designer root object.
			* @param parentNode					The parent node where the model designer root object shall be located.
			* @param accessPatternKey			Set the user access rights for the method nodes, which are defined by an AccessPattern.
			*									The default AccessPattern 0 grants full access for all users.
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file.
			* @note	This method returns an error if the accessPatternKey is unknown to the server.
			*		Keys are limited to values from 0...0xFFFF.
			*
			* @see IAccessPattern Application::setAccessPattern() */
			EnumModelDesignerStatus enableModeling(BaseNodePtr parentNode, OTUInt32 accessPatternKey = 0);

			/*! This method disables the model designer back end.
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			EnumModelDesignerStatus disableModeling();

			/*! returns the modelDesignerRoot */
			ObjectPointer<Server::ModelDesigner::ModelDesignerRoot> modelDesignerRootInstance();

			/*! This callback method is triggered whenever a model designer method is called.
			*
			* Applications can override this method in order to deny the method call
			*
			* @param methodId		The NodeId of the called method
			* @param inputArguments	The input arguments of the called method
			* @return				A bad result stops the execution of the method
			*
			* @note	This function is only available if the SDK was configured with model designer support.
			*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			virtual EnumModelDesignerStatus onModelDesignerMethod(const INodeId* methodId, const std::vector<Value>& inputArguments);

			/*! This callback method is invoked by the model designer resetAddressSpace method
			 *
			 * Application should reset the address space to be as after starting the server
			 * @note	This function is only available if the SDK was configured with model designer support.
			 *		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			virtual EnumModelDesignerStatus onResetAddressSpace();

			/*! Modifies some nodes of the standard namespace to match the supported features of the SDK
			*
			* The modifications include
			* @li Expose the supported modeling rules in the folder Server_ServerCapabilities_ModellingRules by adding references.
			* @li Remove the optional properties LocalTime/CurrentTimeZone and EstimatedReturnTime from the Server object, as they are not maintained by the SDK.
			* @li Remove the default Role nodes, as their functionality is not supported by the SDK.
			* @li Remove the nodes for the not supported encoding types "Default XML" and "Default JSON".
			*
			* @note	It is possible to reference different modeling rules, even though they are not automatically handled by the SDK.
			*		If such modeling rules are used, then the modeling rule should be added manually to the folder Server_ServerCapabilities_ModellingRules */
			void adaptStandardAddressSpace();

			//////////////////////////////////////////////////////////////////////////
			// Bulk variable access
			//////////////////////////////////////////////////////////////////////////

			/*! Bulk access to a list of variables.
			*
			* All DataValues are set consistently.
			*
			* @param variables			A vector of node IDs of variables.
			* @param dataValues			A vector of data values matching the number of variables
			* @param[out] pSetResults	A vector of results matching the set data value of each variable.
			*							This parameter can be set to NULL if the caller is not interested in the results. */
			EnumStatusCode setVariableDataValues(const std::vector<const INodeId*>& variables,
				const std::vector<const IDataValue*>& dataValues,
				std::vector<EnumStatusCode>* pSetResults);
			/*! @overload */
			EnumStatusCode setVariableDataValues(const std::vector<Server::Variable*>& variables,
				const std::vector<const IDataValue*>& dataValues,
				std::vector<EnumStatusCode> *pSetResults);


#if TB5_ALARMS
			//////////////////////////////////////////////////////////////////////////
			// Event management methods
			//////////////////////////////////////////////////////////////////////////

			/*! Returns the event identified by the given @p eventId. */
			ObjectPointer<Server::Object> getEvent(const ByteString& eventId);
			/*! @overload */
			ObjectPointer<const Server::Object> getEvent(const ByteString& eventId) const;

#endif

			//////////////////////////////////////////////////////////////////////////
			// Localization-related methods
			//////////////////////////////////////////////////////////////////////////

			/*! This method is called when the application is initialized (see Application::initialize())
			* and allows server applications to provide translations for localized texts. */
			virtual EnumStatusCode defineTranslations();


#if TB5_ALARMS
			//////////////////////////////////////////////////////////////////////////
			// Methods to report semantic changes in the address space
			//////////////////////////////////////////////////////////////////////////

			/*! @brief Indicates the beginning of a series of semantic changes to nodes.
			*
			* Usually, semantic changes (i.e. changes to values of properties which have the
			* SemanticsChanged bit set in their AccessLevel) trigger SemanticChange events
			* for each affected node individually. For example, if you change the value of
			* an AnalogItem's EngineeringUnit and EURange property, two SemanticChange events
			* will be emitted, each containing the NodeId of the AnalogItem. Also, if you
			* change the EngineeringUnit properties of two different AnalogItems, two separate
			* SemanticChange events will be emitted.
			*
			* Using beginSemanticsChange() and endSemanticsChange(), a server may emit only one
			* SemanticChange event for all semantic changes that occur in between both method calls. */
			void beginSemanticsChange();

			/*! Indicates the end of a series of semantic changes to nodes. This method
			* raises a SemanticChange event that contains the given message and severity.
			*
			* @param pMessage		The message contained in the SemanticChange event
			* @param severity		The severity of the SemanticChange event
			*
			*
			* @see beginSemanticsChange() */
			EnumStatusCode endSemanticsChange(const ILocalizedText* pMessage, OTUInt16 severity);


			//////////////////////////////////////////////////////////////////////////
			// Methods to report changes of the address space structure
			//////////////////////////////////////////////////////////////////////////

			/*! @brief Indicates the beginning of a series of changes to the address space.
			*
			* Whenever the server
			* @li adds or deletes nodes that have the NodeVersion property,
			* @li adds or deletes references between nodes that have the NodeVersion property, or
			* @li changes the data type of a node that has the NodeVersion property,
			* the server automatically emits a ModelChange event for the affected nodes. For example,
			* if you remove two nodes (each having the NodeVersion property) from the address space,
			* two ModelChange events of type GeneralModelChange will be emitted that describe
			* the changes to the address space.
			*
			* This behavior is suitable for simple reconfiguration scenarios where only
			* few changes to the address space are made and where clients are able to
			* apply incremental changes to the address space configuration. However, if the server
			* adds or removes more than a few nodes or references, or clients wish to receive
			* changes to nodes that belong together semantically at one go, the server may decide
			* to notify a series of changes using beginModelChange() and endModelChange().
			*
			* Once the server calls beginModelChange(), all relevant changes to the address space are collected
			* and reported upon calling endModelChange().
			*
			* @note Only nodes which have a NodeVersion property qualify for ModelChange events.
			*
			* @see endModelChange() BaseNode::setVersioned() BaseNode::isVersioned() */
			void beginModelChange();

			/*! Indicates the end of a series of changes to the address space. This method
			* raises a ModelChange event that contains the given message and severity.
			*
			* @param pMessage		The message contained in the ModelChange event
			* @param severity		The severity of the ModelChange event
			*
			* @see beginModelChange() */
			EnumStatusCode endModelChange(const ILocalizedText* pMessage, OTUInt16 severity);
#endif

			/*! Whenever a ModelChange event is to be emitted, the server has to increment the
			* NodeVersion of the nodes that affected the model change. This allows clients
			* that subscribe only to the NodeVersion property of a node to be notified
			* on model changes. For that purpose, the SDK core calls this method whenever
			* ModelChange events are to be emitted for the provided @p changedNodes.
			*
			* A server should override this method to apply its own versioning scheme for nodes.
			* The default implementation does nothing.
			*
			* @see beginModelChange() BaseNode::setNodeVersion() BaseNode::getNodeVersion() */
			virtual void onIncrementNodeVersion(const std::vector<Server::BaseNode*>& changedNodes);

			/*! Whenever a error is detected while validating the addressSpace this function
			* is called. So there can be more than one validation errors
			*
			* A server should override this method to apply its own handling of validation errors.
			* The default implementation does nothing.
			*
			* @param nodeId			The NodeId which causes the validation error
			* @param severity		Indicates the severity of the encountered error (at the moment always 1)
			* @param errorMessage	Contains a descriptive text of the error condition
			*
			* @see onImportNodesError() */
			virtual void onValidateError(const INodeId* nodeId, OTUInt16 severity, const tstring& errorMessage);

			//////////////////////////////////////////////////////////////////////////
			// Methods related to server redundancy
			//////////////////////////////////////////////////////////////////////////

			/*! Sets the service level of this server. The service level is exposed as "ServiceLevel" variable in the
			* address space of the server (Server -> ServiceLevel).
			*
			* The service level describes the ability of the server to provide its data to the client. The value range is
			* from 0 to 255, where 0 indicates the worst and 255 indicates the best. The concrete values are
			* vendor-specific. The intent is to provide the clients an indication of availability among redundant servers. */
			EnumStatusCode setServiceLevel(OTUInt8 serviceLevel);

			//////////////////////////////////////////////////////////////////////////
			// Methods to lock the address space
			//////////////////////////////////////////////////////////////////////////

			/*! Locks the address space and restricts read and write access to nodes and references to the calling thread.
			*
			* @note This lock should only be used for creating condition branches (see Condition::createBranch()). */
			void lock();

			/*! Unlocks the AddressSpace.
			*
			* @see lock() */
			void unlock();

		private:
			/*! For internal use only */
			void initMembers();

			/*! Use instance() to get an AddressSpaceRoot instance */
			AddressSpaceRoot();
			/*! Forbid use assignment operator */
			AddressSpaceRoot& operator=(const AddressSpaceRoot&);
			/*! Forbid use of copy constructor */
			AddressSpaceRoot(const AddressSpaceRoot&);
			EnumModelDesignerStatus initializeImport();
			void uninitializeImport();
			PRIVATE_EXPORTED_STL_CONTAINER(ObjectPointer<SoftingOPCToolbox5::Server::ModelDesigner::ModelDesignerRoot> m_modelDesignerRoot)
		};
		typedef ObjectPointer<AddressSpaceRoot> AddressSpaceRootPtr;
		typedef ObjectPointer<const AddressSpaceRoot> AddressSpaceRootConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERADDRESSSPACEROOT_H
