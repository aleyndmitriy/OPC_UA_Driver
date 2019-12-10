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

#ifndef SERVERDATATYPE_H
#define SERVERDATATYPE_H
#include "Base.h"
#include "Enums.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	// forward declaration
	class DataTypeDescription;
	typedef ObjectPointer<DataTypeDescription> DataTypeDescriptionPtr;
	typedef ObjectPointer<const DataTypeDescription> DataTypeDescriptionConstPtr;

	namespace Server
	{
		/*! The DataType class is used to define DataType node in the address space of a server.
		* DataType nodes are used to define the data type of a variable. */
		class TBC_EXPORT DataType
			: public BaseNode
		{
		public:
			/*! Constructs a new DataType instance */
			static ObjectPointer<DataType> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DataType(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			DataType();
			/*! For internal use only */
			DataType(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~DataType();

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class DataType
			/////////////////////////////////////////////////////////////////////////

			/*! Returns true in case of an abstract data type.
			*
			* @see setIsAbstract() */
			bool getIsAbstract() const;
			/*! Sets whether the data type is abstract or not. By default, a data type is not abstract.
			*
			* Abstract data types can be used to define the data type of a variable.
			* The variable's concrete value (i.e. the variant) however can never be of an abstract data type. */
			EnumStatusCode setIsAbstract(bool isAbstract);

			/*! Returns a pointer to the stored user defined DataTypeDescription.
			*
			* @note	When this DataType has no user defined DataTypeDescription, then NULL is returned.
			* @see setDataTypeDescription() */
			DataTypeDescriptionConstPtr getDataTypeDescription() const;
			/*! Sets a DataTypeDescription to specify how this DataType shall be encoded and decoded
			* or respectively, which value representations are available.
			* To make the used encoding rules available in the address space, there are three additional
			* components involved, respectively their node representations:
			* @li DataTypeDescription:	Specifies the type name and the encoding rules for a datatype.
			* @li Encoding node:		The NodeId of this Node is sent with every value of this data type and
			*							is used to uniquely identify the encoding of the used datatype.
			* @li DataTypeDictionary:	Specifies a Namespace and can hold several DataTypeDescriptions within
			*							that namespace. This is represented by the class Server::DictionaryVariable.
			* @li EnumValues			This is an optional property, which only applies for EnumerationDataTypeDescriptions.
			*							It is a convenient way to display all available EnumeratedValues.
			*
			* @param dataTypeDescription		The name and encoding rules for this data type. When the name is empty,
			*									then the string of the browse name of this DataType is used as name.
			*									The optional documentation is used for the description attribute of
			*									the data type description node.
			* @param dataTypeDescriptionNodeId	The NodeId for the data type description node.
			*                                   This node will be visible below the dictionary node.
			* @param encodingNodeId				The NodeId used to encode / decode values of this datatype. The encoding NodeId can be the null NodeId
			*									for Enumeration data types, since they are always encoded as Int32.
			*									Without an encoding NodeId a client may be not able to match the data type to its description.
			* @param dictionaryNodeId			The NodeId of an existing DataTypeDictionary variable, where the
			*									DataTypeDescription shall be stored
			* @param enumValuesId				Optional parameter for the NodeId of the optional EnumValues
			*									property of an Enumeration data type. This parameter is ignored for
			*									Structured data types.
			*
			* @note	When this method isn't called, the encoding rules of the next available parent type with defined encoding rules
			*		will be used to encode and decode values of this type. It can be that no parent type has an encoding rule.
			*		Every data type requires a different NodeId for the encoding node. For performance reasons,
			*		it is proposed to use only numeric NodeId for this Encoding node.
			*		The NodeIds for all mandatory nodes (DataType, DataTypeDescription, Encoding and DataTypeDictionary)
			*		need to have the same namespace index.
			*		The data type description can only be set once or has to be removed first.
			*		When setting an EnumerationDataTypeDescription, the NodeId of the Encoding is ignored, since all enumerations
			*		are encoded as Int32.
			* @see DataTypeDescription, DictionaryVariable */
			EnumStatusCode setDataTypeDescription(DataTypeDescriptionPtr dataTypeDescription, const INodeId& dataTypeDescriptionNodeId, const INodeId& encodingNodeId, const INodeId& dictionaryNodeId, const INodeId& enumValuesId = NodeId());

			/*! Removes the the DataTypeDescription nodes from the AddressSpace */
			EnumStatusCode removeDataTypeDescription();

		private:
			/*! Forbid use assignment operator */
			DataType& operator=(const DataType&);
			/*! Forbid use of copy constructor */
			DataType(const DataType&);
		};
		typedef ObjectPointer<DataType> DataTypePtr;
		typedef ObjectPointer<const DataType> DataTypeConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERDATATYPE_H
