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

#ifndef INNERPUBLISHEDDATAITEMSDATATYPE_H
#define INNERPUBLISHEDDATAITEMSDATATYPE_H

#include "IPublishedDataItemsDataType.h"
#include "PublishedVariableDataType.h"
#include "IPublishedVariableDataType.h"
#include "InnerPublishedVariableDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerPublishedDataItemsDataType
		: public IPublishedDataItemsDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerPublishedDataItemsDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the PublishedData member of the class */
		virtual std::vector<PublishedVariableDataType> getPublishedData() const;
		/*! Adds a PublishedData to the PublishedData member of the class */
		virtual EnumStatusCode addPublishedData(const IPublishedVariableDataType& publishedData);

		/*! For internal use only */
		void initInner(PublishedDataItemsDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType* pSrc);
		virtual EnumStatusCode set(const IPublishedDataSetSourceDataType& pSrc);

		virtual int compare(const IPublishedDataSetSourceDataType* other) const;
		virtual int compare(const IPublishedDataSetSourceDataType& other) const;

		virtual bool operator==(const IPublishedDataSetSourceDataType& other) const;
		virtual bool operator!=(const IPublishedDataSetSourceDataType& other) const;

		virtual PublishedDataSetSourceDataTypeStruct* getInternHandle();
		virtual const PublishedDataSetSourceDataTypeStruct* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerPublishedVariableDataType> m_pPublishedData)

		PublishedDataItemsDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
