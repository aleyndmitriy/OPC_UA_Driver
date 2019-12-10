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

#ifndef INNERDATATYPESCHEMAHEADER_H
#define INNERDATATYPESCHEMAHEADER_H

#include "IDataTypeSchemaHeader.h"
#include "StructureDescription.h"
#include "IStructureDescription.h"
#include "InnerStructureDescription.h"
#include "EnumDescription.h"
#include "IEnumDescription.h"
#include "InnerEnumDescription.h"
#include "SimpleTypeDescription.h"
#include "ISimpleTypeDescription.h"
#include "InnerSimpleTypeDescription.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataTypeSchemaHeader
		: public IDataTypeSchemaHeader
	{
	public:
		/*! Destructor */
		virtual ~InnerDataTypeSchemaHeader();

		/*! Gets the Namespaces member of the class */
		virtual std::vector<tstring> getNamespaces() const;
		/*! Sets the Namespaces member in the class */
		virtual EnumStatusCode setNamespaces(const std::vector<tstring>& values);

		/*! Gets the StructureDataTypes member of the class */
		virtual std::vector<StructureDescription> getStructureDataTypes() const;
		/*! Adds a StructureDataType to the StructureDataTypes member of the class */
		virtual EnumStatusCode addStructureDataType(const IStructureDescription& structureType);

		/*! Gets the EnumDataTypes member of the class */
		virtual std::vector<EnumDescription> getEnumDataTypes() const;
		/*! Adds a EnumDataType to the EnumDataTypes member of the class */
		virtual EnumStatusCode addEnumDataType(const IEnumDescription& enumType);

		/*! Gets the SimpleDataTypes member of the class */
		virtual std::vector<SimpleTypeDescription> getSimpleDataTypes() const;
		/*! Adds a SimpleDataType to the SimpleDataTypes member of the class */
		virtual EnumStatusCode addSimpleDataType(const ISimpleTypeDescription& simpleType);

		/*! For internal use only */
		void initInner(DataTypeSchemaHeaderStruct* pHandle);

		virtual EnumStatusCode set(const IDataTypeSchemaHeader* pSrc);
		virtual EnumStatusCode set(const IDataTypeSchemaHeader& pSrc);

		virtual int compare(const IDataTypeSchemaHeader* other) const;
		virtual int compare(const IDataTypeSchemaHeader& other) const;

		virtual bool operator==(const IDataTypeSchemaHeader& other) const;
		virtual bool operator!=(const IDataTypeSchemaHeader& other) const;

		virtual void* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerStructureDescription> m_pStructureDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEnumDescription> m_pEnumDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleTypeDescription> m_pSimpleDataTypes)

		DataTypeSchemaHeaderStruct* m_pContent;
	};
} // end namespace

#endif
