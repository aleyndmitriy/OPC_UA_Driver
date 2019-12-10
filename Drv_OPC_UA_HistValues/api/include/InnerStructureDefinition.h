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

#ifndef INNERSTRUCTUREDEFINITION_H
#define INNERSTRUCTUREDEFINITION_H

#include "IStructureDefinition.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "StructureField.h"
#include "IStructureField.h"
#include "InnerStructureField.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerStructureDefinition
		: public IStructureDefinition
	{
	public:
		/*! Destructor */
		virtual ~InnerStructureDefinition();

		/*! Gets the DefaultEncodingId member of the class */
		virtual const INodeId* getDefaultEncodingId() const;
		/*! Sets the DefaultEncodingId member in the class */
		virtual EnumStatusCode setDefaultEncodingId(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setDefaultEncodingId(const NodeId& value);

		/*! Gets the BaseDataType member of the class */
		virtual const INodeId* getBaseDataType() const;
		/*! Sets the BaseDataType member in the class */
		virtual EnumStatusCode setBaseDataType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setBaseDataType(const NodeId& value);

		/*! Gets the StructureType member of the class */
		virtual EnumStructureType getStructureType() const;
		/*! Sets the StructureType member in the class */
		virtual void setStructureType(const EnumStructureType& value);

		/*! Gets the Fields member of the class */
		virtual std::vector<StructureField> getFields() const;
		/*! Adds a Field to the Fields member of the class */
		virtual EnumStatusCode addField(const IStructureField& field);

		/*! For internal use only */
		void initInner(StructureDefinitionStruct* pHandle);

		virtual EnumStatusCode set(const IStructureDefinition* pSrc);
		virtual EnumStatusCode set(const IStructureDefinition& pSrc);

		virtual int compare(const IStructureDefinition* other) const;
		virtual int compare(const IStructureDefinition& other) const;

		virtual bool operator==(const IStructureDefinition& other) const;
		virtual bool operator!=(const IStructureDefinition& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerNodeId m_defaultEncodingId;
		InnerNodeId m_baseDataType;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerStructureField> m_pFields)

		StructureDefinitionStruct* m_pContent;
	};
} // end namespace

#endif
