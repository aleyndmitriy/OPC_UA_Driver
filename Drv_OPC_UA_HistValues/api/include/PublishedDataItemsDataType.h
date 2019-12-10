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

#ifndef PUBLISHEDDATAITEMSDATATYPE_H
#define PUBLISHEDDATAITEMSDATATYPE_H

#include "IPublishedDataItemsDataType.h"
#include "PublishedVariableDataType.h"
#include "IPublishedVariableDataType.h"
#include "InnerPublishedVariableDataType.h"
#include "PublishedDataItemsDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of PublishedDataSetSourceDataType.
	*
	* It is used to store PublishedDataItems specific parameters.
	*
	* This class is used e.g. in
	* @li structure class PublishedDataSetDataType */
	class TBC_EXPORT PublishedDataItemsDataType
		: public IPublishedDataItemsDataType
	{
	public:
		/*! Default constructor */
		PublishedDataItemsDataType();
		/*! Constructs a copy of the given instance @p cp */
		PublishedDataItemsDataType(const IPublishedDataItemsDataType* cp);
		/*! @overload */
		PublishedDataItemsDataType(const IPublishedDataItemsDataType& cp);
		/*! @overload */
		PublishedDataItemsDataType(const PublishedDataItemsDataType& cp);

		/*! Destructor */
		virtual ~PublishedDataItemsDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		PublishedDataItemsDataType& operator=(const IPublishedDataItemsDataType* cp);
		/*! @overload */
		PublishedDataItemsDataType& operator=(const IPublishedDataItemsDataType& cp);
		/*! @overload */
		PublishedDataItemsDataType& operator=(const PublishedDataItemsDataType& cp);

		/* see IPublishedDataItemsDataType::compare(IPublishedDataSetSourceDataType*) */
		virtual int compare(const IPublishedDataSetSourceDataType* other) const;
		/*! @overload */
		virtual int compare(const IPublishedDataSetSourceDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IPublishedDataSetSourceDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IPublishedDataSetSourceDataType& other) const;

		/* see IPublishedDataSetSourceDataType::set(IPublishedDataSetSourceDataType*) */
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType& pSrc);

		/* see IPublishedDataItemsDataType::getPublishedData */
		virtual std::vector<PublishedVariableDataType> getPublishedData() const;
		/* see IPublishedDataItemsDataType::addPublishedData */
		virtual EnumStatusCode addPublishedData(const IPublishedVariableDataType& publishedData);

		/*! For internal use only */
		virtual PublishedDataSetSourceDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const PublishedDataSetSourceDataTypeStruct* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPublishedVariableDataType> m_pPublishedData)

		PublishedDataItemsDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
