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

#ifndef SERVERBASENODE_H
#define SERVERBASENODE_H
#include "Base.h"
#include "Enums.h"
#include "InnerQualifiedName.h"
#include "QualifiedName.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "RelativePath.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class WriteTransaction;
		class WriteRequest;
		class ReadTransaction;
		class ReadRequest;
		class ReferenceIterator;
		class Variable;
		class Object;
		class Method;
		class BaseNode;
		typedef ObjectPointer<BaseNode> BaseNodePtr;
	}

	namespace Server
	{
		/*! Base class for all nodes in the address space of a server. This class defines the basic attributes
		* for all nodes classes and cannot be instantiated directly. */
		class TBC_EXPORT BaseNode
			: public Base
		{
		protected:
			/*! For internal use only */
			BaseNode(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BaseNode();

			/*! Initializes a UA object or variable and creates its sub-nodes (components) according to the specified type.
			* The node and the sub-nodes are also inserted in the address space.
			* To remove the whole UA object or variable use removeTree().
			*
			* @param typeId	The type of node which shall be created. NULL can be passed to use a default node type
			*				fitting to the current node
			* @note			The @p typeId must only be specified if the node type doesn't match the type of the used class.
			*				e.g. if it is a subtype with the same properties or a custom type
			*				All new generated sub-nodes get random generated NodeIds */
			virtual EnumStatusCode init(const INodeId* typeId);

			/*! Returns whether this node is an instance of the object or variable type identified by the TypeId.
			* This method checks whether this node has a 'HasTypeDefinition' reference to the given type node.
			*
			* @param typeId				The object or variable type to test. Well-known types are defined
			*							as constants in the Statics namespace (e.g. Statics::ObjectTypeId_BaseObjectType).
			* @param includeSubtypes	If true, sub-types of the given type are considered too */
			bool isInstanceOfUaType(const INodeId* typeId, bool includeSubtypes) const;

			/*! This method applies to type definition nodes (object, variable, reference or data types). It verifies if a given
			* type definition (the node on which this method is called) inherits the type identified by @p typeId.
			*
			* @param typeId				The object or variable type to test. Well-known types are defined
			*							as constants in the Statics namespace (e.g. Statics::ObjectTypeId_BaseObjectType).
			* @param includeSubtypes	This parameter shall always be set to true */
			bool isOfUaType(const INodeId* typeId, bool includeSubtypes) const;

			/*! Adds a reference from this node to the given target node. The type of the
			* reference (e.g. "Organizes" or "HasComponent") is defined by the NodeId of a reference type.
			* Only concrete, i.e. non-abstract reference types may be used.
			*
			* @param referenceId	The NodeId of the reference type. Well-known reference types are defined
			*						as constants in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes).
			* @param targetNode		The node to which the reference shall point. */
			EnumStatusCode addReference(const INodeId* referenceId, Server::BaseNode* targetNode);

			/*! Returns an iterator that allows iterating over all references of the node.
			*
			* @param browseDir			Defines whether references are accessed in forward, backward or both directions
			* @param pReferenceId		The NodeId of the reference type. Well-known reference types are defined
			*							as constants in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes).
			* @param includeSubtypes	Indicates whether only the exact reference type or all subtypes of the given
			*							reference type shall be accessed.
			* @param nodeClassMask		A bit mask indicating which node classes shall be returned
			* @param resultMask			A bit mask indicating which additional result information shall be returned,
			*							additional to the NodeId. */
			ObjectPointer<Server::ReferenceIterator> getReferenceIterator(EnumBrowseDirection browseDir, const INodeId* pReferenceId, bool includeSubtypes, EnumNodeClass nodeClassMask, EnumResultMask resultMask) const;
			/*! @overload */
			ObjectPointer<Server::ReferenceIterator> getReferenceIterator(EnumBrowseDirection browseDir, const INodeId* pReferenceId, bool includeSubtypes) const;

			/*! Returns a node that matches the provided criteria. If no node matches the criteria,
			* this method returns NULL.
			*
			* @param browseDir			Defines whether references are accessed in forward or backward direction.
			*							Please note that EnumBrowseDirection_Both is not a valid parameter for this method.
			* @param pReferenceId		The NodeId of the reference type. Well-known reference types are defined
			*							as constants in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes).
			* @param includeSubtypes	Indicates whether only the exact reference type or all subtypes of the given
			*							reference type shall be accessed.
			* @param pBrowseName		The browse name of the node */
			ObjectPointer<Server::BaseNode> findNode(EnumBrowseDirection browseDir, const INodeId* pReferenceId, bool includeSubtypes, const IQualifiedName* pBrowseName) const;

			/*! Returns an array of nodes that match the provided criteria. If no node matches the criteria,
			* this method returns an empty array.
			*
			* @param browseDir			Defines whether references are accessed in forward or backward direction.
			*							Please note that EnumBrowseDirection_Both is not a valid parameter for this method.
			* @param pReferenceId		The NodeId of the reference type. Well-known reference types are defined
			*							as constants in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes).
			* @param includeSubtypes	Indicates whether only the exact reference type or all subtypes of the given
			*							reference type shall be accessed.
			* @param pBrowseName		The browse name of the node */
			std::vector<ObjectPointer<Server::BaseNode> > findNodes(EnumBrowseDirection browseDir, const INodeId* pReferenceId, bool includeSubtypes, const IQualifiedName* pBrowseName) const;

			/*! Removes a specific reference from this node to another given node. Please note that the exact
			* reference type must be provided. Subtypes of the given reference type are not considered.
			*
			* @param targetNode		The node to which the reference points
			* @param referenceId	The NodeId of the reference type. Well-known reference types are defined
			*						as constants in the Statics namespace (e.g. Statics::ReferenceTypeId_Organizes). */
			EnumStatusCode removeReferenceTo(Server::BaseNodePtr targetNode, const INodeId* referenceId);

			/*! Removes all references to the given node. */
			EnumStatusCode removeReferencesTo(Server::BaseNodePtr targetNode);

			/*! Inserts the node into the server's address space. Returns a bad status code in case of an error. */
			EnumStatusCode insert();

			/*! Inserts the given node and all hierarchically referenced nodes into the address space of the server.
			* This method is provided for inserting a complete node tree with a single call. */
			EnumStatusCode insertTree();

			/*! Removes the node from the server's address space.
			*
			* @li All references from the node itself will be removed i.e. a successive call to insertTree() will not insert any (former) child nodes.
			* @li The referenced nodes will stay in address space if they contain any additional references (including e.g. HasTypeDefinition, ...).
			* @li This can lead to islands of nodes in the address space which cannot be reached.
			* @li Any node staying in address space will not be deleted.
			*
			* @note	Be careful when removing a single node from address space. This can lead to unexpected leaks.
			*		Type nodes can only be removed when neither this type nor any subtype are used. */
			EnumStatusCode remove();

			/*! Removes the node itself and all nodes referenced by hierarchical references from the server's address space.
			*
			* @note		All nodes referenced recursively with any hierarchical reference type are removed.
			*			That includes also reference types like HasEventSource or HasNotifier.
			*			Type nodes can only be removed when neither this type nor any subtype are used. */
			EnumStatusCode removeTree();

			/*! Copies this node and all hierarchically referenced nodes recursively ("deep copy").
			* The copied nodes have the same non-hierarchical references as their original nodes.
			* However if the original target node of a non-hierarchical reference has also been copied in the
			* same method call, the same reference will point to the copied target node.
			*
			* The caller is provided with a pointer to the copied node.
			* Only Objects and Variables can be copied. */
			EnumStatusCode copyTree(ObjectPointer<Server::BaseNode>* copiedTree) const;

			/*! Copies this node's attributes and its type ("shallow copy"). References (except for the
			* HasTypeDefinition reference) are not copied. A new GUID NodeId will be generated and
			* assigned to the target node.
			*
			* The caller has to provide a valid pointer to an "empty" target node. */
			EnumStatusCode copyAttributeValues(Server::BaseNode* targetNode) const;

			/*! Returns the value of the given attribute as DataValue. The timestamps of the DataValue
			* are only defined if the 'value' attribute of a variable or variable type is queried.
			*
			* @param attributeId	The attribute to be returned
			* @param attributeValue	The value of the attribute */
			EnumStatusCode getAttribute(EnumAttributeId attributeId, IDataValue* attributeValue) const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			* @param attributeId	The attribute to be returned
			* @param attributeValue	The value of the attribute
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumStatusCode getAttribute(TBHandle otbHandle, EnumAttributeId attributeId, IDataValue* attributeValue);

			/*! Returns whether the current node has a specified attribute or not. */
			bool hasAttribute(EnumAttributeId attributeId) const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			* @param attributeId	The attribute to check
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static bool hasAttribute(TBHandle otbHandle, EnumAttributeId attributeId);

			/*! Sets a specified value to the given attribute.
			*
			* @param attributeId	The attribute to be set.
			* @param attributeValue The new value of the attribute
			*
			* @note	This method is meant to set the attribute value on client request (e.g. in WriteTransaction::handleRequests)
			*		since this method checks the write mask of the node. Please use the provided overload of this function
			*		that provides an option to bypass write mask checks.
			*		The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			*		mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			*		be set, but will not be reported by a subscription. */
			EnumStatusCode setAttribute(EnumAttributeId attributeId, const IDataValue* attributeValue);
			/*! @overload
			*
			* @param attributeId		The attribute to be set.
			* @param attributeValue		The new value of the attribute
			* @param bypassWriteMask	Indicates whether to bypass the write mask defined by the node */
			EnumStatusCode setAttribute(EnumAttributeId attributeId, const IDataValue* attributeValue, bool bypassWriteMask);

			/*! Updates the 'value' attribute of the variable with given browse name.
			* This method is provided for convenience.
			*
			* @param propertyName	The browse name of the property variable
			* @param value			The data value to set on the given variable */
			EnumStatusCode setPropertyValue(const tstring& propertyName, const IDataValue* value);
			/*! @overload */
			EnumStatusCode setPropertyValue(const QualifiedName& propertyName, const IDataValue* value);

			/*! Returns the variable with the given browse name that is hierarchically related to this node.
			* The method allow an easy generic access to property variables of nodes.
			* NULL is returned if the variable with given browse name has not been found. */
			ObjectPointer<Server::Variable> getVariable(const tstring& propertyName);
			/*! @overload */
			ObjectPointer<Server::Variable> getVariable(const QualifiedName& browseName);
			/*! @overload */
			ObjectPointer<Server::Variable> getVariable(const std::vector<QualifiedName>& browsePath);
			/*! @overload */
			ObjectPointer<const Server::Variable> getVariable(const tstring& propertyName) const;
			/*! @overload */
			ObjectPointer<const Server::Variable> getVariable(const QualifiedName& browseName) const;
			/*! @overload */
			ObjectPointer<const Server::Variable> getVariable(const std::vector<QualifiedName>& browsePath) const;

			/*! Looks up a method by its browse name, and returns it.
			* NULL is returned if the object is not found. */
			ObjectPointer<Server::Method> getMethod(const tstring& methodName);
			/*! @overload */
			ObjectPointer<Server::Method> getMethod(const QualifiedName& browseName);
			/*! @overload */
			ObjectPointer<Server::Method> getMethod(const std::vector<QualifiedName>& browsePath);
			/*! @overload */
			ObjectPointer<const Server::Method> getMethod(const tstring& methodName) const;
			/*! @overload */
			ObjectPointer<const Server::Method> getMethod(const QualifiedName& browseName) const;
			/*! @overload */
			ObjectPointer<const Server::Method> getMethod(const std::vector<QualifiedName>& browsePath) const;

			/*! Looks up an object by its browse name, and returns it.
			* NULL is returned if the object is not found. */
			ObjectPointer<Server::Object> getObject(const tstring& objectName);
			/*! @overload */
			ObjectPointer<Server::Object> getObject(const QualifiedName& browseName);
			/*! @overload */
			ObjectPointer<Server::Object> getObject(const std::vector<QualifiedName>& browsePath);
			/*! @overload */
			ObjectPointer<const Server::Object> getObject(const tstring& objectName) const;
			/*! @overload */
			ObjectPointer<const Server::Object> getObject(const QualifiedName& browseName) const;
			/*! @overload */
			ObjectPointer<const Server::Object> getObject(const std::vector<QualifiedName>& browsePath) const;

			/*! Adds the property "NodeVersion" to this node which indicates that the node is versioned.
			* The NodeVersion property holds the current revision of the node. A node needs to have the NodeVersion
			* property if a server application intends to include changes to the node's components in
			* ModelChange events.
			*
			* @param initialVersion The initial version string that is set as value of the "NodeVersion" property
			*
			* @see AddressSpaceRoot::beginModelChange() AddressSpaceRoot::onIncrementNodeVersion() */
			EnumStatusCode setVersioned(const tstring& initialVersion);

			/*! Returns whether the node is versioned, i.e. whether it has the "NodeVersion" property.
			*
			* @see setVersioned() */
			bool isVersioned() const;

			/*! Returns the current value of the "NodeVersion" property. This requires the node to be versioned.
			*
			* @see setVersioned() */
			EnumStatusCode getNodeVersion(tstring& nodeVersion) const;
			/*! Updates the value of the "NodeVersion" property. This requires the node to be versioned.
			*
			* @see setVersioned() */
			EnumStatusCode setNodeVersion(const tstring& nodeVersion);

			/*! Callback for a single read request to an attribute value of the node. Override this method for handling single read requests.
			*
			* Typically this is only required for Variable nodes. The overridden function
			* shall read the value of the node and copy the value into the request's DataValue member.
			*
			* @param transaction	The whole transaction which contains the single ReadRequest
			* @param request		The single ReadRequest which shall be handled
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleReadRequest(Server::ReadTransaction* transaction, Server::ReadRequest* request);

			/*! Callback for a single write request to an attribute of the node. Override this method for handling single write requests.
			*
			* The overridden method is typically responsible for handling all write requests for non-standard variables.
			*
			* @param transaction	The whole transaction which contains the single WriteRequest
			* @param request		The single WriteRequest which shall be handled
			*
			* @note When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			* mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			* be set, but will not be reported by a subscription. */
			virtual EnumStatusCode handleWriteRequest(Server::WriteTransaction* transaction, Server::WriteRequest* request);

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class BaseNode
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the class of the node. The possible node classes are defined by the Enumeration "EnumNodeClass".
			* The set of node classes is fixed and cannot be extended. */
			EnumNodeClass getNodeClass() const;

			/*! Returns the SDK API class of this node.
			*
			* A static cast to the class is possible without risk. */
			EnumApiClassType getApiClass() const;

			/*! Validates if this node is derived from the given API class.
			*
			* A static cast to this API class is possible without risk.
			*
			* @param apiClass		The API class which shall be verified
			* @return				true: This node is derived from the tested class type */
			bool isOfApiClass(EnumApiClassType apiClass) const;

			/*! Returns the NodeId of the node that uniquely identifies the node in the address space of the server.
			*
			* @see setNodeId() */
			const INodeId* getNodeId() const;
			/*! @overload
			*
			* @param otbHandle	The core handle retrieved from the Creator
			* @param pNodeId	Returns the NodeId of the node
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumStatusCode getNodeId(TBHandle otbHandle, INodeId* pNodeId);
			/*! Sets the NodeId of the node that uniquely identifies the node in the address space of the server.
			* A NodeId is always defined within a namespace.
			*
			* @param nodeId	The unique identifier for the node
			*
			* @see INodeId Server::AddressSpaceRoot::addNamespace() */
			EnumStatusCode setNodeId(const INodeId* nodeId);
			/*! @overload */
			EnumStatusCode setNodeId(const INodeId& nodeId);

			/*! Returns the browse name of the node.
			*
			* @ see setBrowseName() */
			const IQualifiedName* getBrowseName() const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			* @param pBrowseName	Returns the BrowseName of the node
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumStatusCode getBrowseName(TBHandle otbHandle, IQualifiedName* pBrowseName);
			/*! Sets the human-readable, non-localized browse name of the node. This name
			* is used by clients to creates paths out of browse names (see Client::Session::translateBrowsePathToNodeIds()).
			*
			* @param browseName		The browse name for the node.
			*
			* @note	Two nodes 'A' and 'B' that are referenced by another node 'C' may share the same browse name.
			*		However, this is not allowed if the node 'C' is a variable or object type.
			*		Thus, browse names must be unique within a type definition but not within an instance of a type. */
			EnumStatusCode setBrowseName(const IQualifiedName* browseName);
			/*! @overload */
			EnumStatusCode setBrowseName(const IQualifiedName& browseName);

			/*! Returns the localized name of the node that shall be used in user interfaces.
			*
			* @see setDisplayName */
			const ILocalizedText* getDisplayName() const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			* @param pDisplayName	Returns the DisplayName of the node
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumStatusCode getDisplayName(TBHandle otbHandle, ILocalizedText* pDisplayName);
			/*! Sets the localized name of the node that shall be used in user interfaces.
			* The DisplayName is localized and can contain more than one language.
			*
			* @param displayName	The localized name for the node */
			EnumStatusCode setDisplayName(const ILocalizedText* displayName);
			/*! @overload */
			EnumStatusCode setDisplayName(const ILocalizedText& displayName);

			/*! Returns the write mask of the node which indicates the attributes that can be written
			* by a client.
			*
			* The write mask is a bit field. A set bit in that field indicates the writability of
			* a specific attribute (see EnumWriteMask).
			*
			* @note	Access rights on the 'value' attribute of a variable are defined
			*		by its access level attribute (see Variable::setAccessLevel()). */
			EnumWriteMask getWriteMask() const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumWriteMask getWriteMask(TBHandle otbHandle);
			/*! Sets the write mask of the node which indicates the attributes that can be written
			* by a client.
			*
			* The write mask is a bit field. A set bit in that field indicates the writability of
			* a specific attribute (see EnumWriteMask). Usually, a node prevents all its attributes
			* from being written.
			*
			* @param writeMask The write mask bit field
			*
			* @note	Access rights on the 'value' attribute of a variable are defined
			*		by its access level attribute (see Variable::setAccessLevel()). */
			EnumStatusCode setWriteMask(EnumWriteMask writeMask);

			/*! Returns a description of the node that indicates the meaning of the node.
			*
			* @see setDescription() */
			const ILocalizedText* getDescription() const;
			/*! @overload
			*
			* @param otbHandle		The core handle retrieved from the Creator
			* @param pDescription	Returns the Description of the node
			*
			* @note This overloaded method shall only be used in the Creator
			*
			* @see Creator */
			static EnumStatusCode getDescription(TBHandle otbHandle, ILocalizedText* pDescription);
			/*! Returns a description of the node that indicates the meaning of the node.
			*
			* @param description A description of that node
			*
			* @note		Please take into consideration that descriptions will increase the memory consumption! */
			EnumStatusCode setDescription(const ILocalizedText* description);
			/*! @overload */
			EnumStatusCode setDescription(const ILocalizedText& description);

			/*! Returns the pointer to any user-specific data that has been provided by setUserData().
			* If no pointer has been set, this method returns NULL.
			*
			* @see see setUserData() */
			void* getUserData() const;
			/*! Sets a pointer to any user-specific data.
			*
			* @param userData	A pointer to any user-specific data
			*
			* @note		The SDK will not touch the user data. The server application is responsible to
			*			free any allocated memory and to ensure that the pointer is valid when accessed. */
			EnumStatusCode setUserData(void* userData);

			/*! Defines a translation for a localizable attribute value of a node (DisplayName, Description, Value).
			*
			* @param nodeId			The nodeId of the node which contains the LocalizedText to translate
			* @param attributeId	The attributeId of the node to translate
			* @param translation	The translation
			* @param locale			The locale of the translation
			*
			* @note	This method is provided for convenience. Please refer to LocalizedText::defineTranslation() for
			*		more details. */
			static EnumStatusCode defineTranslation(const INodeId& nodeId, EnumAttributeId attributeId, const tstring& translation, const tstring& locale);

			/*! Provides the imported extensions as XmlElement array
			 * @param extensions	the vector of XmlElements containing the XML content of the custom extensions of a imported node.
			 *
			 * @note	A Node can have extensions that can provide additional information for the Object
			 * @note	This function is only available if the SDK was configured with model designer support.
			 *			This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			EnumStatusCode getExtensions(std::vector<XmlElement>& extensions) const;

			/*! Sets the imported extensions as XmlElement array
			 * @param extensions	the vector of XmlElements containing the XML content of the custom extensions of a imported node.
			 *
			 * @note	A Node can have extensions that can provide additional information for the Object
			 * @note	This function is only available if the SDK was configured with model designer support.
			 *			This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			EnumStatusCode setExtensions(const std::vector<XmlElement>& extensions);

			/*! Adds an imported extension to XmlElement array
			 * @param extension		the XmlElement containing the XML content of the custom extensions of a imported node.
			 *
			 * @note	A Node can have extensions that can provide additional information for the Object
			 * @note	This function is only available if the SDK was configured with model designer support.
			 *			This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
			EnumStatusCode addExtension(const XmlElement extension);

			/*! Requests a NodeId for a sub-node to be created
			*
			* This method is invoked e.g. if child nodes are created due to mandatory or optional modeling rule of the nodes type.
			*
			 * @param pathOfNode		The relative path of the child node, starting from the node itself.
			 * @param newNodeId			The node ID of the child node that shall be used
			 *
			 * @return	Returning a bad status code will deny creation of child node (shall be used only for optional children)
			 *			Returning a good status code with a valid node ID will use this NodeId for creation.
			 *			Returning a good status code with a NULL NodeId will allow SDK to generate a NodeId. */
			virtual EnumStatusCode generateNodeIdForSubNode(const IRelativePath& pathOfNode, INodeId& newNodeId);
		protected:
			/*! For internal use only */
			void initMembers();

		private:
			InnerQualifiedName m_browseName;
			InnerLocalizedText m_displayName;
			InnerNodeId m_nodeId;
			InnerLocalizedText m_description;

			PRIVATE_EXPORTED_STL_CONTAINER(std::vector<XmlElement> m_extensions)
			/*! This class cannot not be instantiated. */
			BaseNode();

			/*! Forbid use assignment operator */
			BaseNode& operator=(const BaseNode&);
			/*! Forbid use of copy constructor */
			BaseNode(const BaseNode&);

		};
		typedef ObjectPointer<BaseNode> BaseNodePtr;
		typedef ObjectPointer<const BaseNode> BaseNodeConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERBASENODE_H
