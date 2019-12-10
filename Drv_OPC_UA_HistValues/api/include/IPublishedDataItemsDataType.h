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

#ifndef IPUBLISHEDDATAITEMSDATATYPE_H
#define IPUBLISHEDDATAITEMSDATATYPE_H

#include "PublishedVariableDataType.h"
#include "IPublishedVariableDataType.h"
#include "IPublishedDataSetSourceDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The PublishedDataItemsDataType is used to store PublishedDataItems specific parameters.
	*
	* This structure is used e.g. in
	* @li structure class PublishedDataSetDataType */
	class TBC_EXPORT IPublishedDataItemsDataType : public IPublishedDataSetSourceDataType
	{
	public:
		/*! Destructor */
		virtual ~IPublishedDataItemsDataType(){};
		/*! Gets the PublishedData member of the class */
		virtual std::vector<PublishedVariableDataType> getPublishedData() const = 0;
		/*! Adds a PublishedVariable to the PublishedData member of the class
		*
		* The parameter PublishedData defines the sources of a PublishedDataSet created from variable values
		* and thus the content of the DataSetMessage sent by a DataSetWriter.
		* Each published value is described by a PublishedVariableDataType.
		*
		* The PublishedData parameter is closely related to the DataSetMetaData configured in a PublishedDataSet.
		* The order in the PublishedData shall match the order of the fields in the DataSetMetaData.
		* @see PublishedDataSet::setDataSetMetaData.
		* The fields of the DataSetMetaData (data type, value rank, array dimensions) shall match the published variable.
		*
		* Whenever information of the PublishedData changes, the DataSetMetaData has to be adapted as well.
		* The ConfigurationVersion within the DataSetMetaData represents the time of last change.
		*
		* @see PublishedDataSet::setDataSetMetaData
		* @see ConfigurationVersionDataType */
		virtual EnumStatusCode addPublishedData(const IPublishedVariableDataType& publishedData) = 0;

		/*! Conversion from IPublishedDataSetSourceDataType */
		static const IPublishedDataItemsDataType* castFrom(const IPublishedDataSetSourceDataType* pSrc);
		/*! Conversion from IPublishedDataSetSourceDataType */
		static IPublishedDataItemsDataType* castFrom(IPublishedDataSetSourceDataType* pSrc);
	}; // end IPublishedDataItemsDataType
} // end namespace

#endif
