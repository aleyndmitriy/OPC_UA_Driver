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

#ifndef SERVERVARIABLETYPE_H
#define SERVERVARIABLETYPE_H
#include "Base.h"
#include "Enums.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "ServerBaseNode.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! The VariableType class is used to define a VariableType node in the address space of a server.
		*
		* A VariableType provides definitions for a Variable in the address space, i.e. it defines
		* a blueprint for variables (instances of the VariableType). Clients use the VariableType
		* to learn about the properties of a variable.
		*
		* All variable types finally derive from the variable type "BaseVariableType".
		* The well-known "BaseDataVariableType" is the base type for all variables that represent
		* values of objects. The well-known "PropertyType" is the base type for all variables
		* that describe the characteristics of a node ("properties").
		*
		* @note Each Variable must be assigned to a VariableType using BaseNode::init(). */
		class TBC_EXPORT VariableType
			: public BaseNode
		{
		public:
			/*! Constructs a new VariableType instance */
			static ObjectPointer<VariableType> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			VariableType(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			VariableType();
			/*! For internal use only */
			VariableType(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~VariableType();

			/*! Returns the base type of this variable type. If there is no base type, a NULL pointer is returned. */
			ObjectPointer<Server::VariableType> getBaseType();
			/*! @overload */
			ObjectPointer<const Server::VariableType> getBaseType() const;

			/*! If true, indicates that variables of this type may NOT be exposed in the address space of the server. */
			bool getIsAbstract() const;
			/*! Defines whether variables of this type may be exposed in the address space of the server. */
			EnumStatusCode setIsAbstract(bool isAbstract);

			/*! Returns the NodeId of the data type for the variable type's 'value' attribute.
			*
			* @see setDataType() */
			const INodeId* getDataType() const;
			/*! Sets the NodeId of the data type for the variable type's 'value' attribute.
			* This setting is mandatory for all variable types and must be defined before inserting
			* the variable in the address space of the server. */
			EnumStatusCode setDataType(const INodeId* dataType);
			/*! @overload */
			EnumStatusCode setDataType(const INodeId& dataType);

			/*! Returns the value of the VariableType.
			*
			* @see setDataValue() */
			const IDataValue* getDataValue() const;
			/*! Sets the value of the VariableType. This value is used as default value for new instances of
			* this variable type.
			*
			* @note	The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			*		mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			*		be set, but will not be reported by a subscription.
			* @see IDataValue::setServerTimestamp() */
			EnumStatusCode setDataValue(const IDataValue* dataValue);
			/*! @overload */
			EnumStatusCode setDataValue(const IDataValue& dataValue);

			/*! Returns whether the variable's value is an array and if, how many dimensions the array has.
			*
			* Possible return values:
			* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
			* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
			* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
			* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
			* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array
			*
			* @see setValueRank() */
			OTInt32 getValueRank() const;
			/*! Sets whether the variable's value is an array and if, how many dimensions the array has.
			*
			* Possible values:
			* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
			* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
			* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
			* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
			* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array
			*
			* @note If the array dimensions don't match to the new value rank, then the array dimension are
			*       automatically updated to matching dimensions without length limitation. @see setArrayDimensions */
			EnumStatusCode setValueRank(OTInt32 valueRank);

			/*! Returns a field of integer values describing the length of each array dimension if
			* the variable has an array value. The number of elements is equal to the result
			* of getValueRank() if getValueRank() returns a positive number. A vector entry with
			* value 0 indicates that the dimension has variable length.
			*
			* @note This method returns an empty vector for scalar values or variable sized dimensions. */
			std::vector<OTUInt32> getArrayDimensions() const;
			/*! Sets a field of integer values describing the length of each array dimension if
			* the variable has an array value. The number of elements must be equal to the result
			* of getValueRank() if getValueRank() returns a positive number. A vector entry with
			* value 0 indicates that the dimension has variable length.
			*
			* @note The array dimensions attribute must not be set for scalar variable values or variable sized dimensions.
			*       If the value rank does not match to the new array dimensions, then the value rank is automatically updated
			*       to the exact dimension. @see setValueRank */
			EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			mutable InnerDataValue m_DataValue;
			mutable InnerNodeId m_DataType;

			/*! Forbid use assignment operator */
			VariableType& operator=(const VariableType&);
			/*! Forbid use of copy constructor */
			VariableType(const VariableType&);
		};
		typedef ObjectPointer<VariableType> VariableTypePtr;
		typedef ObjectPointer<const VariableType> VariableTypeConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERVARIABLETYPE_H
