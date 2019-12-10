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

#ifndef IMPORT_NODE_DESCRIPTION_H
#define IMPORT_NODE_DESCRIPTION_H
#include "InnerQualifiedName.h"
#include "InnerLocalizedText.h"
#include "InnerNodeId.h"
#include "InnerValue.h"
#include "InnerExpandedNodeId.h"

namespace SoftingOPCToolbox5
{
	// forward declaration
	namespace Server
	{
		namespace NodeSet2Import
		{
			// forward declaration
			class ImportReferenceDescription;

			/*! Description for a base node, which is currently imported. */
			class TBC_EXPORT ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUANodeDescription();

				/*! Returns the class of the node. The possible node classes are defined by the Enumeration "EnumNodeClass".
				* The set of node classes is fixed and cannot be extended.
				* The returned information can be used to cast the common ImportUANodeDescription to a matching subtype. */
				EnumNodeClass getNodeClass() const;

				/*! Returns the NodeId of the node that uniquely identifies the node in the address space of the server.
				* A NodeId is always defined within a namespace. */
				const INodeId* getNodeId() const;

				/*! Returns the human-readable, non-localized browse name of the node. This name
				* is used by clients to creates paths out of browse names. */
				const IQualifiedName* getBrowseName() const;

				/*! Returns the localized name of the node that shall be used in user interfaces.
				* The DisplayName is localized and can contain more than one language. */
				const ILocalizedText* getDisplayName() const;

				/*! Returns the write mask of the node which indicates the attributes that can be written
				* by a client.
				*
				* The write mask is a bit field. A set bit in that field indicates the writability of
				* a specific attribute (see EnumWriteMask).
				*
				* @note	Access rights on the 'value' attribute of a variable are defined
				*		by its access level attribute (see Variable::setAccessLevel()). */
				EnumWriteMask getWriteMask() const;

				/*! Returns the user write mask of the node which indicates the attributes that can be written
				* by a certain user.
				*
				* @see getWriteMask() */
				EnumWriteMask getUserWriteMask() const;

				/*! Returns a description of the node that indicates the meaning of the node. */
				const ILocalizedText* getDescription() const;

				/*! Returns the references, which are attached to this node.
				*
				* @note Only the references are returned, which are described on this node.
				*       References from different nodes, which point to this node are not included. */
				const std::vector<ImportReferenceDescription>& getReferences();

				/*! init from otb handle */
				void initInner(void* pHandle);

				/*! For internal use only */
				virtual void* getInternHandle() const;

			protected:
				/*! the handle to the related core object */
				void* m_importNodeDescription_Data;

				/*! For internal use only */
				virtual void initMembers();

			private:
				InnerQualifiedName m_browseName;
				InnerLocalizedText m_displayName;
				InnerNodeId m_nodeId;
				InnerLocalizedText m_description;
				PRIVATE_EXPORTED_STL_CONTAINER(std::vector<ImportReferenceDescription> m_references)
			};


			/*! The description for an Object node, which is currently imported. */
			class TBC_EXPORT ImportUAObjectDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAObjectDescription();

				/*! Returns the optional XML attribute ParentNodeId from the NodeSet2 file.
				* @note The method will return the Null NodeId if the optional attribute does not exist */
				const INodeId* getParentNodeId() const;

				/*! Returns the 'EventNotifier' attribute of this object.
				*
				* The EventNotifier attribute is used to indicate if the node can be used
				* to subscribe to events or to read/write historical events.
				*
				* By default, the event notifier attribute contains 0.
				*
				* @see EnumEventNotifier */
				OTUInt8 getEventNotifier() const;
			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerNodeId m_parentNodeId;
			};


			/*! The description for a Variable node, which is currently imported. */
			class TBC_EXPORT ImportUAVariableDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAVariableDescription();

				/*! Returns the optional XML attribute ParentNodeId from the NodeSet2 file.
				* @note The method will return the Null NodeId if the optional attribute does not exist */
				const INodeId* getParentNodeId() const;

				/*! Returns the NodeId of the data type for the variable's 'value' attribute. */
				const INodeId* getDataType() const;

				/*! Returns the cached value stored by this Variable. */
				const IValue* getValue() const;

				/*! Returns whether the variable's value is an array and if, how many dimensions the array has.
				*
				* Possible return values:
				* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
				* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
				* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
				* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
				* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array */
				OTInt32 getValueRank() const;

				/*! Returns a field of integer values describing the length of each array dimension if
				* the variable has an array value. The number of elements is equal to the result
				* of getValueRank() if getValueRank() returns a positive number. A vector entry with
				* value 0 indicates that the dimension has variable length.
				*
				* @note This method returns an empty vector for non-array values. */
				std::vector<OTUInt32> getArrayDimensions() const;

				/*! Returns the access level of the variable that indicates how the variable's value
				* can be accessed and if it contains current and/or historic data.
				*
				* The access level does not take any user access rights into account, i.e. although the variable is writable
				* this may be restricted to a certain user / user group.
				* The value can be a combination of the available values (see EnumAccessLevel). */
				EnumAccessLevel getAccessLevel() const;

				/*! Returns the user access level of the variable that indicates how the variable's value
				* can be accessed by a certain user and if it contains current and/or historic data.
				*
				* @see getAccessLevel() */
				EnumAccessLevel getUserAccessLevel() const;

				/*! Returns the value of the MinimumSamplingInterval attribute. The MinimumSamplingInterval attribute indicates
				* how "current" the value of the Variable is kept. It specifies (in milliseconds) how fast the server can
				* reasonably sample the value for changes. A minimum sampling interval of 0 indicates that the server is to
				* monitor the item continuously. A minimum sampling interval of -1 means indeterminate. */
				double getMinimumSamplingInterval() const;

				/*! Returns the Historizing attribute that indicates whether the server is actively collecting data for the history of
				* the variable.
				*
				* This differs from the AccessLevel Attribute which identifies if the variable has any historical data.
				* A value of 'true' indicates that the server is actively collecting data. A value of 'false' indicates
				* that the server is not actively collecting data. */
				bool isHistorizing() const;

			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerNodeId m_parentNodeId;
				InnerNodeId m_dataTypeId;
				InnerValue m_value;
			};


			/*! The description for a Method node, which is currently imported. */
			class TBC_EXPORT ImportUAMethodDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAMethodDescription();

				/*! Returns the optional XML attribute ParentNodeId from the NodeSet2 file.
				* @note The method will return the Null NodeId if the optional attribute does not exist */
				const INodeId* getParentNodeId() const;

				/*! Returns whether a client is allowed to execute this method. */
				bool isExecutable() const;

				/*! Returns the 'UserExecutable' attribute value of the method that indicates whether the
				* method can be executed by a certain user.
				*
				* @see getExecutable() */
				bool isUserExecutable() const;

			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerNodeId m_parentNodeId;
			};


			/*! The description for a View node, which is currently imported. */
			class TBC_EXPORT ImportUAViewDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAViewDescription();

				/*! Returns the optional XML attribute ParentNodeId from the NodeSet2 file.
				* @note The method will return the Null NodeId if the optional attribute does not exist */
				const INodeId* getParentNodeId() const;

				/*! Returns the 'ContainsNoLoops' attribute of this view.
				*
				* If set to true this attribute indicates that following references in the
				* context of the View contains no loops, i.e. starting from a Node "A"
				* contained in the View and following the forward References in the
				* context of the View Node "A" will not be reached again. It does not
				* specify that there is only one path starting from the View Node to
				* reach a Node contained in the View.
				*
				* If set to false this Attribute indicates that following References in the
				* context of the View may lead to loops.
				*
				* @see EnumEventNotifier */
				OTBoolean containsNoLoops() const;

			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerNodeId m_parentNodeId;
			};


			/*! The description for an ObjectType node, which is currently imported. */
			class TBC_EXPORT ImportUAObjectTypeDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAObjectTypeDescription();

				/*! Indicates whether objects of this type may be exposed in the address space of the server.
				* If the object type is abstract, an object of this type must not be exposed in the address space. */
				bool isAbstract() const;
			};


			/*! The description for a VariableType node, which is currently imported. */
			class TBC_EXPORT ImportUAVariableTypeDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAVariableTypeDescription();

				/*! Indicates whether objects of this type may be exposed in the address space of the server.
				* If the object type is abstract, an object of this type must not be exposed in the address space. */
				bool isAbstract() const;

				/*! Returns the NodeId of the data type for the variable's 'value' attribute. */
				const INodeId* getDataType() const;

				/*! Returns the cached value stored by this Variable. */
				const IValue* getValue() const;

				/*! Returns whether the variable's value is an array and if, how many dimensions the array has.
				*
				* Possible return values:
				* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
				* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
				* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
				* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
				* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array */
				OTInt32 getValueRank() const;

				/*! Returns a field of integer values describing the length of each array dimension if
				* the variable has an array value. The number of elements is equal to the result
				* of getValueRank() if getValueRank() returns a positive number. A vector entry with
				* value 0 indicates that the dimension has variable length.
				*
				* @note This method returns an empty vector for non-array values. */
				std::vector<OTUInt32> getArrayDimensions() const;

			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerNodeId m_dataTypeId;
				InnerValue m_value;
			};


			/*! The description for a ReferenceType node, which is currently imported. */
			class TBC_EXPORT ImportUAReferenceTypeDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUAReferenceTypeDescription();

				/*! Indicates whether objects of this type may be exposed in the address space of the server.
				* If the object type is abstract, an object of this type must not be exposed in the address space. */
				bool isAbstract() const;

				/*! Returns whether the meaning of the reference type is the same as seen from both the source
				* node and the target node. If false, the reference is asymmetric and getInverseName() returns the
				* name of the reference as seen from the target node. */
				bool isSymmetric() const;

				/*! Returns the (localized) inverse name of the reference.
				*
				* The inverse name is the name of the reference as seen from the target node.
				* The inverse name is only used for non-symmetric references. */
				const ILocalizedText* getInverseName() const;

			protected:
				/*! For internal use only */
				virtual void initMembers();
			private:
				InnerLocalizedText m_inverseName;
			};


			/*! The description for a DataType node, which is currently imported. */
			class TBC_EXPORT ImportUADataTypeDescription
				: public ImportUANodeDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportUADataTypeDescription();

				/*! Indicates whether objects of this type may be exposed in the address space of the server.
				* If the object type is abstract, an object of this type must not be exposed in the address space. */
				bool isAbstract() const;
			};


			/*! The description for a Reference between two nodes. */
			class TBC_EXPORT ImportReferenceDescription
			{
			public:
				/*! Destructor */
				virtual ~ImportReferenceDescription();

				/*! Returns the NodeId of the reference type that defines the reference. */
				const IExpandedNodeId* getReferenceTypeId() const;

				/*! Returns true if the current node is the source node. */
				bool isForward() const;

				/*! Returns the NodeId of the referenced node.
				* If isForward is true, then it is the NodeId of the target node, otherwise it
				* describes the source node. If IExpandedNodeId::getServerIndex()
				* returns a server index different from 0, then the target node is located at a
				* remote server. */
				const IExpandedNodeId* getNodeId() const;

				/*! init from otb handle */
				void initInner(void* pHandle);

				/*! For internal use only */
				virtual void* getInternHandle() const;
			private:
				// the handle to the related core object
				void* m_importReferenceDescription_Data;

				InnerExpandedNodeId m_nodeId;
				InnerExpandedNodeId m_referenceTypeId;

				/*! For internal use only */
				void initMembers();
			};
		}
	}
}

#endif	// IMPORT_NODE_DESCRIPTION_H
