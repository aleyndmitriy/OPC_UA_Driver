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

#ifndef ISTRUCTUREFIELD_H
#define ISTRUCTUREFIELD_H

#include "StructureFieldStruct.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "NodeId.h"
#include "INodeId.h"

namespace SoftingOPCToolbox5
{
	/*! The StructureField data type contains the metadata for a field of a custom Structure DataType. */
	class TBC_EXPORT IStructureField
	{
	public:
		/*! Destructor */
		virtual ~IStructureField(){};

		/*! Sets the Name member in the class */
		virtual void setName(const tstring& name) = 0;
		/*! Gets the Name member of the class */
		virtual tstring getName() const = 0;

		/*! Sets the Description member in the class */
		virtual EnumStatusCode setDescription(const ILocalizedText* description) = 0;
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description) = 0;
		/*! Gets the Description member of the class */
		virtual const ILocalizedText* getDescription() const = 0;

		/*! Sets the DataType member in the class */
		virtual EnumStatusCode setDataType(const INodeId* dataType) = 0;
		/*! @overload */
		virtual EnumStatusCode setDataType(const NodeId& dataType) = 0;
		/*! Gets the DataType member of the class */
		virtual const INodeId* getDataType() const = 0;

		/*! Sets the ValueRank member in the class */
		virtual void setValueRank(const OTInt32& valueRank) = 0;
		/*! Gets the ValueRank member of the class */
		virtual OTInt32 getValueRank() const = 0;

		/*! Sets the ArrayDimensions member in the class */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions) = 0;
		/*! Gets the ArrayDimensions member of the class */
		virtual std::vector<OTUInt32> getArrayDimensions() const = 0;

		/*! Sets the MaxStringLength member in the class */
		virtual void setMaxStringLength(const OTUInt32& maxStringLength) = 0;
		/*! Gets the MaxStringLength member of the class */
		virtual OTUInt32 getMaxStringLength() const = 0;

		/*! Sets the IsOptional member in the class */
		virtual void setIsOptional(const OTBoolean& isOptional) = 0;
		/*! Gets the IsOptional member of the class */
		virtual OTBoolean getIsOptional() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IStructureField* other) const = 0;
		/*! @overload */
		virtual int compare(const IStructureField& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IStructureField& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IStructureField& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IStructureField* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IStructureField& cp) = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IStructureField
} // end namespace

#endif
