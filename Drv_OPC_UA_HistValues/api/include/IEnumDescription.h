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

#ifndef IENUMDESCRIPTION_H
#define IENUMDESCRIPTION_H

#include "EnumDescriptionStruct.h"
#include "EnumDefinition.h"
#include "IEnumDefinition.h"
#include "NodeId.h"
#include "INodeId.h"
#include "QualifiedName.h"
#include "IQualifiedName.h"

namespace SoftingOPCToolbox5
{
	/*! The EnumDescription data type provides the concrete DataTypeDescription for Enumeration DataTypes. */
	class TBC_EXPORT IEnumDescription
	{
	public:
		/*! Destructor */
		virtual ~IEnumDescription(){};

		/*! Sets the EnumDefinition member in the class */
		virtual EnumStatusCode setEnumDefinition(const IEnumDefinition* enumDefinition) = 0;
		/*! @overload */
		virtual EnumStatusCode setEnumDefinition(const EnumDefinition& enumDefinition) = 0;
		/*! Gets the EnumDefinition member of the class */
		virtual const IEnumDefinition* getEnumDefinition() const = 0;

		/*! Sets the BuiltInType member in the class
		* @param builtInType		The builtInType indicates if the DataType is an Enumeration or an OptionSet (not yet supported).
		*							If the builtInType is Int32, the DataType is an Enumeration.
		*							If the builtInType is one of the UInteger DataTypes or ExtensionObject, the DataType is an OptionSet. */
		virtual void setBuiltInType(const OTUInt8& builtInType) = 0;
		/*! Gets the BuiltInType member of the class */
		virtual OTUInt8 getBuiltInType() const = 0;

		/*! Sets the DataTypeId member in the class
		*
		* @param dataTypeId		The NodeId of the DataType. */
		virtual EnumStatusCode setDataTypeId(const INodeId* dataTypeId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataTypeId(const NodeId& dataTypeId) = 0;
		/*! Gets the DataTypeId member of the class */
		virtual const INodeId* getDataTypeId() const = 0;

		/*! Sets the Name member in the class
		*
		* @param name	A unique name for the data type. */
		virtual EnumStatusCode setName(const IQualifiedName* name) = 0;
		/*! @overload */
		virtual EnumStatusCode setName(const QualifiedName& name) = 0;
		/*! Gets the Name member of the class */
		virtual const IQualifiedName* getName() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IEnumDescription* other) const = 0;
		/*! @overload */
		virtual int compare(const IEnumDescription& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEnumDescription& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEnumDescription& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEnumDescription* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEnumDescription& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEnumDescription
} // end namespace

#endif
