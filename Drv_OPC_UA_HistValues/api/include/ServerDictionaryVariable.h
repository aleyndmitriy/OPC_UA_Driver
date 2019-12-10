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

#ifndef SERVER_DICTIONARY_VARIABLE_H
#define SERVER_DICTIONARY_VARIABLE_H

#include "ServerVariable.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents a variable containing a DataTypeDictionary.
		*
		* The DataTypeDictionary variable can contain several DataTypeDescription variables, which describe the single data types.
		*
		* @note The value of this variable type should not be changed manually */
		class TBC_EXPORT DictionaryVariable
			: public Variable
		{
		public:
			/*! Constructs a new DictionaryVariable instance */
			static ObjectPointer<DictionaryVariable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DictionaryVariable(TBHandle otbHandle);

			/*! Destructor */
			virtual ~DictionaryVariable();

			/*! @see BaseNode::init() */
			EnumStatusCode init(const INodeId* typeId);

			/*! Registers the stored data type dictionary, to be able to use all stored data type descriptions
			* to encode and decode the related data types.
			* Once activated, all newly added data type descriptions can be used at once.
			* Calling this method also inserts this data type dictionary variable to the address space
			*
			* @note	The basic node attributes NodeId, BrowseName, DisplayName and Description need to
			*		be set before calling this method.
			*		The ValueRank and DataType will be set to Scalar and ByteString and the AccessLevel is
			*		extended by 'CurrentRead' access.
			*		To unregister the dictionary, remove the DictionaryVariable node from the address space.
			* @see	BaseNode::setNodeId(), BaseNode::setBrowseName(), BaseNode::setDisplayName(),
			*		BaseNode::setDescription(), BaseNode::remove() BaseNode::removeTree */
			EnumStatusCode registerDictionary();

			/*! Returns whether the data type dictionary is already registered, which means that it can
			* be used to encode and decode the related data types.
			*
			* @see registerDictionary() */
			bool isRegistered();

			/*! Returns the DataTypeVersion of this data type dictionary.
			*
			* @note	An empty string is returned when the responsible property does not exist
			* @see addDataTypeVersion(), setDataTypeVersion() */
			tstring getDataTypeVersion() const;
			/*! Adds the optional property "DataTypeVersion" to this data type dictionary variable and sets the version.
			* This property is used to notice any data type changes on this dictionary by subscribing to this node.
			* If this property already exists (e.g. from a previous init() call) with a different NodeId, then it will be replaced.
			*
			* @param dataTypeVersionId	The NodeId for the DataTypeVersion property
			* @param version			A string, uniquely describing the version of the data type dictionary.
			* @note						A existing "DataTypeVersion" property should not be replaced during runtime, because
			*							Clients rely that this NodeId stays the same.
			*							This property shall be added, when the data type dictionary is expected to change
			*							during runtime.
			*							This shall only be called when the dictionary variable is inserted to the address space
			* @see	setDataTypeVersion() BaseNode::init() */
			EnumStatusCode addDataTypeVersion(const INodeId& dataTypeVersionId, const tstring& version);
			/*! Sets the DataTypeVersion property node.
			* This indicates clients, that any of the DataTypes have changed, which are described by this data type dictionary.
			*
			* @param version	A string, uniquely describing the version of the data type dictionary.
			* @note				This property shall be added, when the data type dictionary is expected to change
			*					during runtime.
			*					Before invoking this method, the "DataTypeVersion" property must already exist,
			*					see addDataTypeVersion()
			*					This shall only be called when the dictionary variable is inserted to the address space
			* @see	setDataTypeVersion() */
			EnumStatusCode setDataTypeVersion(const tstring& version);

			/*! Returns the NamespaceUri of this data type dictionary.
			*
			* @note	An empty string is returned when the responsible property does not exist
			* @see addNamespaceUri() */
			tstring getNamespaceUri() const;
			/*! Adds the optional property "NamespaceUri" to this data type dictionary variable and initializes its value
			* according to the namespace of this data type dictionary variable.
			* If this property already exists (e.g. from a previous init() call) with a different NodeId, then it will be replaced.
			*
			* @param namespaceUriId	The NodeId for the "NamespaceUri" property
			* @note	This shall only be called when the dictionary variable is inserted to the address space */
			EnumStatusCode addNamespaceUri(const INodeId& namespaceUriId);

		private:
			/*! Forbid use assignment operator */
			DictionaryVariable& operator=(const DictionaryVariable&);
			/*! Forbid use default constructor */
			DictionaryVariable();
			/*! Forbid use of copy constructor */
			DictionaryVariable(const DictionaryVariable&);
		};

		typedef ObjectPointer<DictionaryVariable> DictionaryVariablePtr;
		typedef ObjectPointer<const DictionaryVariable> DictionaryVariableConstPtr;
	} // end Server namespace
}

#endif	// SERVER_DICTIONARY_VARIABLE_H
