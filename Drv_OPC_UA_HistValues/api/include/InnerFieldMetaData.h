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

#ifndef INNERFIELDMETADATA_H
#define INNERFIELDMETADATA_H

#include "IFieldMetaData.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"
#include "Guid.h"
#include "IGuid.h"
#include "KeyValuePair.h"
#include "IKeyValuePair.h"
#include "InnerKeyValuePair.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerFieldMetaData
		: public IFieldMetaData
	{
	public:
		/*! Destructor */
		virtual ~InnerFieldMetaData();

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the Description member of the class */
		virtual const ILocalizedText* getDescription() const;
		/*! Sets the Description member in the class */
		virtual EnumStatusCode setDescription(const ILocalizedText* value);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& value);

		/*! Gets the FieldFlags member of the class */
		virtual EnumDataSetFieldFlags getFieldFlags() const;
		/*! Sets the FieldFlags member in the class */
		virtual void setFieldFlags(const EnumDataSetFieldFlags& value);

		/*! Gets the BuiltInType member of the class */
		virtual OTUInt8 getBuiltInType() const;
		/*! Sets the BuiltInType member in the class */
		virtual void setBuiltInType(const OTUInt8& value);

		/*! Gets the DataType member of the class */
		virtual const INodeId* getDataType() const;
		/*! Sets the DataType member in the class */
		virtual EnumStatusCode setDataType(const INodeId* value);
		/*! @overload */
		virtual EnumStatusCode setDataType(const NodeId& value);

		/*! Gets the ValueRank member of the class */
		virtual OTInt32 getValueRank() const;
		/*! Sets the ValueRank member in the class */
		virtual void setValueRank(const OTInt32& value);

		/*! Gets the ArrayDimensions member of the class */
		virtual std::vector<OTUInt32> getArrayDimensions() const;
		/*! Sets the ArrayDimensions member in the class */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& values);

		/*! Gets the MaxStringLength member of the class */
		virtual OTUInt32 getMaxStringLength() const;
		/*! Sets the MaxStringLength member in the class */
		virtual void setMaxStringLength(const OTUInt32& value);

		/*! Gets the DataSetFieldId member of the class */
		virtual const IGuid* getDataSetFieldId() const;
		/*! Sets the DataSetFieldId member in the class */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId);
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& dataSetFieldId);

		/*! Gets the Properties member of the class */
		virtual std::vector<KeyValuePair> getProperties() const;
		/*! Adds a Property to the Properties member of the class */
		virtual EnumStatusCode addProperty(const IKeyValuePair& fieldProperty);

		/*! For internal use only */
		void initInner(FieldMetaDataStruct* pHandle);

		virtual EnumStatusCode set(const IFieldMetaData* pSrc);
		virtual EnumStatusCode set(const IFieldMetaData& pSrc);

		virtual int compare(const IFieldMetaData* other) const;
		virtual int compare(const IFieldMetaData& other) const;

		virtual bool operator==(const IFieldMetaData& other) const;
		virtual bool operator!=(const IFieldMetaData& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerLocalizedText m_description;
		InnerNodeId m_dataType;
		Guid m_dataSetFieldId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pProperties)

		FieldMetaDataStruct* m_pContent;
	};
} // end namespace

#endif
