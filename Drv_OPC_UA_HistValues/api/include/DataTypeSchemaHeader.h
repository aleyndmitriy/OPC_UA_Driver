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

#ifndef DATATYPESCHEMAHEADER_H
#define DATATYPESCHEMAHEADER_H

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

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataTypeSchemaHeader is the abstract base type used to provide OPC UA DataType definitions
	* for an OPC UA Binary encoded byte blob used outside an OPC UA Server AddressSpace.
	*
	* Concrete subclasses are DataSetMetaDataType and UABinaryFileDataType (not yet implemented). */
	class TBC_EXPORT DataTypeSchemaHeader
		: public IDataTypeSchemaHeader
	{
	public:
		/*! Default constructor */
		DataTypeSchemaHeader();
		/*! Constructs a copy of the given instance @p cp */
		DataTypeSchemaHeader(const IDataTypeSchemaHeader* cp);
		/*! @overload */
		DataTypeSchemaHeader(const IDataTypeSchemaHeader& cp);
		/*! @overload */
		DataTypeSchemaHeader(const DataTypeSchemaHeader& cp);

		/*! Destructor */
		virtual ~DataTypeSchemaHeader();

		/*! Assigns the contents of @p cp to this instance */
		DataTypeSchemaHeader& operator=(const IDataTypeSchemaHeader* cp);
		/*! @overload */
		DataTypeSchemaHeader& operator=(const IDataTypeSchemaHeader& cp);
		/*! @overload */
		DataTypeSchemaHeader& operator=(const DataTypeSchemaHeader& cp);

		/* see IDataTypeSchemaHeader::compare */
		virtual int compare(const IDataTypeSchemaHeader* other) const;
		/*! @overload */
		virtual int compare(const IDataTypeSchemaHeader& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataTypeSchemaHeader& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataTypeSchemaHeader& other) const;

		/* see IDataTypeSchemaHeader::set(IDataTypeSchemaHeader*) */
		virtual EnumStatusCode set(const IDataTypeSchemaHeader* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataTypeSchemaHeader& pSrc);

		/* see IDataTypeSchemaHeader::setNamespaces */
		virtual EnumStatusCode setNamespaces(const std::vector<tstring>& namespaces);
		/* see IDataTypeSchemaHeader::getNamespaces */
		virtual std::vector<tstring> getNamespaces() const;

		/* see IDataTypeSchemaHeader::addStructureDataType */
		virtual EnumStatusCode addStructureDataType(const IStructureDescription& structureDescription);
		/* see IDataTypeSchemaHeader::getStructureDataTypes */
		virtual std::vector<StructureDescription> getStructureDataTypes() const;

		/* see IDataTypeSchemaHeader::addEnumDataType */
		virtual EnumStatusCode addEnumDataType(const IEnumDescription& enumDescription);
		/* see IDataTypeSchemaHeader::getEnumDataTypes */
		virtual std::vector<EnumDescription> getEnumDataTypes() const;

		/* see IDataTypeSchemaHeader::addSimpleDataType */
		virtual EnumStatusCode addSimpleDataType(const ISimpleTypeDescription& simpleTypeDescription);
		/* see IDataTypeSchemaHeader::getSimpleDataTypes */
		virtual std::vector<SimpleTypeDescription> getSimpleDataTypes() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerStructureDescription> m_pStructureDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEnumDescription> m_pEnumDataTypes)
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleTypeDescription> m_pSimpleDataTypes)

		DataTypeSchemaHeaderStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
