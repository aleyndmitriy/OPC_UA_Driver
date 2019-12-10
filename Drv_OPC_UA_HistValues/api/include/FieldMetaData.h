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

#ifndef FIELDMETADATA_H
#define FIELDMETADATA_H

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

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The FieldMetaData data type contains the metadata for a field in a PublishedDataSet. */
	class TBC_EXPORT FieldMetaData
		: public IFieldMetaData
	{
	public:
		/*! Default constructor */
		FieldMetaData();
		/*! Constructs a copy of the given instance @p cp */
		FieldMetaData(const IFieldMetaData* cp);
		/*! @overload */
		FieldMetaData(const IFieldMetaData& cp);
		/*! @overload */
		FieldMetaData(const FieldMetaData& cp);

		/*! Destructor */
		virtual ~FieldMetaData();

		/*! Assigns the contents of @p cp to this instance */
		FieldMetaData& operator=(const IFieldMetaData* cp);
		/*! @overload */
		FieldMetaData& operator=(const IFieldMetaData& cp);
		/*! @overload */
		FieldMetaData& operator=(const FieldMetaData& cp);

		/* see IFieldMetaData::compare(IFieldMetaData*) */
		virtual int compare(const IFieldMetaData* other) const;
		/*! @overload */
		virtual int compare(const IFieldMetaData& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IFieldMetaData& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IFieldMetaData& other) const;

		/* see IFieldMetaData::set(IFieldMetaData*) */
		virtual EnumStatusCode set(const IFieldMetaData* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IFieldMetaData& pSrc);

		/* see IFieldMetaData::setName */
		virtual void setName(const tstring& name);
		/* see IFieldMetaData::getName */
		virtual tstring getName() const;

		/* see IFieldMetaData::setDescription */
		virtual EnumStatusCode setDescription(const ILocalizedText* description);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description);
		/* see IFieldMetaData::getDescription */
		virtual const ILocalizedText* getDescription() const;

		/* see IFieldMetaData::setFieldFlags */
		virtual void setFieldFlags(const EnumDataSetFieldFlags& flags);
		/* see IFieldMetaData::getFieldFlags */
		virtual EnumDataSetFieldFlags getFieldFlags() const;

		/* see IFieldMetaData::setBuiltInType */
		virtual void setBuiltInType(const OTUInt8& builtInType);
		/* see IFieldMetaData::getBuiltInType */
		virtual OTUInt8 getBuiltInType() const;

		/* see IFieldMetaData::setDataType */
		virtual EnumStatusCode setDataType(const INodeId* dataType);
		/*! @overload */
		virtual EnumStatusCode setDataType(const NodeId& dataType);
		/* see IFieldMetaData::getDataType */
		virtual const INodeId* getDataType() const;

		/* see IFieldMetaData::setValueRank */
		virtual void setValueRank(const OTInt32& valueRank);
		/* see IFieldMetaData::getValueRank */
		virtual OTInt32 getValueRank() const;

		/* see IFieldMetaData::setArrayDimensions */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions);
		/* see IFieldMetaData::getArrayDimensions */
		virtual std::vector<OTUInt32> getArrayDimensions() const;

		/* see IFieldMetaData::setMaxStringLength */
		virtual void setMaxStringLength(const OTUInt32& maxStringLength);
		/* see IFieldMetaData::getMaxStringLength */
		virtual OTUInt32 getMaxStringLength() const;

		/* see IFieldMetaData::setDataSetFieldId */
		virtual EnumStatusCode setDataSetFieldId(const IGuid* pDataSetFieldId);
		/*! @overload */
		virtual EnumStatusCode setDataSetFieldId(const Guid& dataSetFieldId);
		/* see IFieldMetaData::getDataSetFieldId */
		virtual const IGuid* getDataSetFieldId() const;

		/* see IFieldMetaData::addProperty */
		virtual EnumStatusCode addProperty(const IKeyValuePair& fieldProperty);
		/* see IFieldMetaData::getProperties */
		virtual std::vector<KeyValuePair> getProperties() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerLocalizedText m_description;
		InnerNodeId m_dataType;
		Guid m_dataSetFieldId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerKeyValuePair> m_pProperties)

		FieldMetaDataStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
