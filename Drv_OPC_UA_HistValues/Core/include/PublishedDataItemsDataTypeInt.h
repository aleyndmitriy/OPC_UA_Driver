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

#ifndef _PublishedDataItemsDataTypeInt_H_
#define _PublishedDataItemsDataTypeInt_H_

#include "PublishedDataSetSourceDataTypeInt.h"
#include "PublishedVariableDataTypeStruct.h"

//lint -sem(PublishedDataItemsDataTypeInt::clearInternal, cleanup)
struct PublishedDataItemsDataTypeInt : public PublishedDataSetSourceDataTypeInt
{
	PublishedDataItemsDataTypeInt();
	PublishedDataItemsDataTypeInt(const PublishedDataItemsDataTypeInt &source);
	~PublishedDataItemsDataTypeInt();

	EnumStatusCode getPublishedData(OTUInt32 *pCount, PublishedVariableDataTypeStruct **ppPublishedData);

	EnumStatusCode setPublishedData(const PublishedVariableDataTypeStruct *publishedData, OTUInt32 count);

	EnumStatusCode addPublishedData(const PublishedVariableDataTypeStruct &value);


	virtual int compare(const PublishedDataSetSourceDataTypeInt* pTarget) const;
	virtual EnumStatusCode set(const PublishedDataSetSourceDataTypeInt &source);
	virtual PublishedDataSetSourceDataTypeInt *clone() const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const PublishedDataItemsDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_PublishedDataItemsDataType &source);
	EnumStatusCode get(OpcUa_PublishedDataItemsDataType &target) const;
#endif

	/*! Defines the content of a DataSet created from Variable Values. */
	PublishedVariableDataTypeStruct *pPublishedData;
	OTUInt32 pPublishedData_count;

protected:
	void clearInternal();

};

#endif //_PublishedDataItemsDataTypeInt_H_