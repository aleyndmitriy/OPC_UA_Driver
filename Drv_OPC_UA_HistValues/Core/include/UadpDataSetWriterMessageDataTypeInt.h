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

#ifndef _UadpDataSetWriterMessageDataTypeInt_H_
#define _UadpDataSetWriterMessageDataTypeInt_H_

#include "DataSetWriterMessageDataTypeInt.h"

//lint -sem(UadpDataSetWriterMessageDataTypeInt::clearInternal, cleanup)
struct UadpDataSetWriterMessageDataTypeInt : public DataSetWriterMessageDataTypeInt
{
	UadpDataSetWriterMessageDataTypeInt();
	UadpDataSetWriterMessageDataTypeInt(const UadpDataSetWriterMessageDataTypeInt &source);
	virtual ~UadpDataSetWriterMessageDataTypeInt();

	/*! Access the flags for the content of the DataSetMessage header. */
	EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;

	/*! Set the flags for the content of the DataSetMessage header. */
	EnumStatusCode setDataSetMessageContentMask(EnumUadpDataSetMessageContentMask mask);

	/*! Access the fixed size in bytes a DataSetMessage uses inside a NetworkMessage. */
	OTUInt16 getConfiguredSize() const;

	/*! Set the fixed size in bytes a DataSetMessage uses inside a NetworkMessage. */
	EnumStatusCode setConfiguredSize(OTUInt16 size);

	/*! Access parameter for fixed NetworkMessage layout. */
	OTUInt16 getNetworkMessageNumber() const;

	/*! Set parameter for fixed NetworkMessage layout. */
	EnumStatusCode setNetworkMessageNumber(OTUInt16 value);

	/*! Access the offset in bytes inside a NetworkMessage */
	OTUInt16 getDataSetOffset() const;

	/*! Set the offset in bytes inside a NetworkMessage */
	EnumStatusCode setDataSetOffset(OTUInt16 offset);

	virtual DataSetWriterMessageDataTypeInt *clone() const;
	virtual int compare(const DataSetWriterMessageDataTypeInt* pTarget) const;
	virtual EnumStatusCode set(const DataSetWriterMessageDataTypeInt &source);
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const UadpDataSetWriterMessageDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	EnumStatusCode set(const OpcUa_ExtensionObject& source);
	EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_UadpDataSetWriterMessageDataType &source);
	EnumStatusCode get(OpcUa_UadpDataSetWriterMessageDataType &target) const;
#endif

protected:
	/*! The flags for the content of the DataSetMessage header. */
	EnumUadpDataSetMessageContentMask dataSetMessageContentMask;

	/*! The fixed size in bytes a DataSetMessage uses inside a NetworkMessage. */
	OTUInt16 configuredSize;

	/*! Read-only parameter set by the Publisher in the case of a fixed NetworkMessage layout. */
	OTUInt16 networkMessageNumber;

	/*! Offset in bytes inside a NetworkMessage */
	OTUInt16 dataSetOffset;

	void clearInternal();

};

#endif //_UadpDataSetWriterMessageDataTypeInt_H_