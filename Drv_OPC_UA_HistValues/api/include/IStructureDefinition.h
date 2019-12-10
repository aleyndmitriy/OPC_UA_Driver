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

#ifndef ISTRUCTUREDEFINITION_H
#define ISTRUCTUREDEFINITION_H

#include "StructureDefinitionStruct.h"
#include "NodeId.h"
#include "INodeId.h"
#include "StructureField.h"
#include "IStructureField.h"

namespace SoftingOPCToolbox5
{
	/*! The StructureDefinition data type contains the meta data for a custom Structure DataType. */
	class TBC_EXPORT IStructureDefinition
	{
	public:
		/*! Destructor */
		virtual ~IStructureDefinition(){};

		/*! Gets the DefaultEncodingId member of the class */
		virtual const INodeId* getDefaultEncodingId() const = 0;
		/*! Sets the DefaultEncodingId member in the class.
		*
		* @param encodingId		The NodeId of the default DataTypeEncoding for the DataType. The default
		* depends on the message encoding, Default Binary for UA Binary encoding,
		* Default JSON for JSON encoding and Default XML for XML encoding.
		*
		* @note Currently only "UA Binary" encoding is supported */
		virtual EnumStatusCode setDefaultEncodingId(const INodeId* encodingId) = 0;
		/*! @overload */
		virtual EnumStatusCode setDefaultEncodingId(const NodeId& encodingId) = 0;

		/*! Gets the BaseDataType member of the class */
		virtual const INodeId* getBaseDataType() const = 0;
		/*! Sets the BaseDataType member in the class.
		*
		* @param baseDataType	The NodeId of the direct supertype of the structure. This might be the abstract Structure or the Union data type. */
		virtual EnumStatusCode setBaseDataType(const INodeId* baseDataType) = 0;
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& baseDataType) = 0;

		/*! Gets the StructureType member of the class */
		virtual EnumStructureType getStructureType() const = 0;
		/*! Sets the StructureType member in the class */
		virtual void setStructureType(const EnumStructureType& structureType) = 0;

		/*! Gets the Fields member of the class */
		virtual std::vector<StructureField> getFields() const = 0;
		/*! Adds a Field to the Fields member of the class */
		virtual EnumStatusCode addField(const IStructureField& field) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IStructureDefinition* other) const = 0;
		/*! @overload */
		virtual int compare(const IStructureDefinition& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IStructureDefinition& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IStructureDefinition& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IStructureDefinition* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IStructureDefinition& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IStructureDefinition
} // end namespace

#endif
