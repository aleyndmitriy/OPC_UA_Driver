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

#ifndef _DatagramWriterGroupTransportDataTypeInt_H_
#define _DatagramWriterGroupTransportDataTypeInt_H_

#include "WriterGroupTransportDataTypeInt.h"

//lint -sem(DatagramWriterGroupTransportDataTypeInt::clearInternal, cleanup)
struct DatagramWriterGroupTransportDataTypeInt : public WriterGroupTransportDataTypeInt
{
	DatagramWriterGroupTransportDataTypeInt();
	DatagramWriterGroupTransportDataTypeInt(const DatagramWriterGroupTransportDataTypeInt &source);
	virtual ~DatagramWriterGroupTransportDataTypeInt();

	/*! Access how many times every NetworkMessage is repeated. */
	OTUInt8 getMessageRepeatCount() const;

	/*! Set how many times every NetworkMessage is repeated. */
	EnumStatusCode setMessageRepeatCount(OTUInt8 count);

	/*! Access the time between NetworkMessage repeats in milliseconds. */
	OTDouble getMessageRepeatDelay() const;

	/*! Set the time between NetworkMessage repeats in milliseconds. */
	EnumStatusCode setMessageRepeatDelay(OTDouble delay);

	virtual WriterGroupTransportDataTypeInt *clone() const;
	virtual EnumStatusCode set(const WriterGroupTransportDataTypeInt &source);
	virtual int compare(const WriterGroupTransportDataTypeInt* pTarget) const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const DatagramWriterGroupTransportDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_DatagramWriterGroupTransportDataType &source);
	EnumStatusCode get(OpcUa_DatagramWriterGroupTransportDataType &target) const;
#endif

protected:
	/*! Defines how many times every NetworkMessage is repeated. */
	OTUInt8 messageRepeatCount;

	/*! Defines the time between NetworkMessage repeats in milliseconds. */
	OTDouble messageRepeatDelay;

	void clearInternal();

};

#endif //_DatagramWriterGroupTransportDataTypeInt_H_