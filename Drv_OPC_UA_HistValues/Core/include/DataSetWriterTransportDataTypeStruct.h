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

#ifndef _DataSetWriterTransportDataTypeStruct_H_
#define _DataSetWriterTransportDataTypeStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct DataSetWriterTransportDataTypeInt;

//lint -sem(DataSetWriterTransportDataTypeStruct::clear, cleanup)
//lint -sem(DataSetWriterTransportDataTypeStruct::init, initializer)
typedef struct TBCORE_IF DataSetWriterTransportDataTypeStruct
{
	DataSetWriterTransportDataTypeStruct();
	DataSetWriterTransportDataTypeStruct(const DataSetWriterTransportDataTypeStruct&);

	EnumDataTypeId getDataType() const;

	EnumStatusCode set(const DataSetWriterTransportDataTypeStruct&);
	EnumStatusCode get(DataSetWriterTransportDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExtensionObject& source);
	EnumStatusCode get(OpcUa_ExtensionObject& target) const;
#endif

	const DataSetWriterTransportDataTypeStruct& operator=(const DataSetWriterTransportDataTypeStruct& cp);
	bool operator==(const DataSetWriterTransportDataTypeStruct& toCompare) const;
	bool operator!=(const DataSetWriterTransportDataTypeStruct& toCompare) const;
	bool operator<(const DataSetWriterTransportDataTypeStruct& toCompare) const;
	bool operator>(const DataSetWriterTransportDataTypeStruct& toCompare) const;

	int compare(const DataSetWriterTransportDataTypeStruct* pTarget) const;

	void clear(void);
	~DataSetWriterTransportDataTypeStruct(void);

	DataSetWriterTransportDataTypeInt *getContent() const;
protected:
	// Internal object
	DataSetWriterTransportDataTypeInt *pContent;
	// Flag set in subclasses when the content is not owned
	bool bNoRelease;
} DataSetWriterTransportDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
