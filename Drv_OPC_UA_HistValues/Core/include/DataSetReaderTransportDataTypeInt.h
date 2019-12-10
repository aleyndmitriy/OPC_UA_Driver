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

#ifndef _DataSetReaderTransportDataTypeInt_H_
#define _DataSetReaderTransportDataTypeInt_H_

#include "OSCompat.h"
#include "Enums.h"


struct DataSetReaderTransportDataTypeInt
{
	DataSetReaderTransportDataTypeInt() { }
	DataSetReaderTransportDataTypeInt(const DataSetReaderTransportDataTypeInt&) { }
	virtual ~DataSetReaderTransportDataTypeInt() { }

	virtual EnumStatusCode set(const DataSetReaderTransportDataTypeInt &source) = 0;
	virtual DataSetReaderTransportDataTypeInt *clone() const = 0;

	virtual int compare(const DataSetReaderTransportDataTypeInt *pTarget) const = 0;

	virtual void clear() = 0;

	virtual void destroy() = 0;

	virtual OTUInt32 getTypeId() const = 0;

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target)
	{
		OpcUa_ExtensionObject_Clear(&target);
		target.TypeId.NodeId.IdentifierType = OpcUa_IdentifierType_Numeric;
		target.TypeId.NodeId.NamespaceIndex = 0;
		target.Encoding = OpcUa_ExtensionObjectEncoding_EncodeableObject;

		return EnumStatusCode_Good;
	}

	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source) = 0;
	virtual EnumStatusCode get(OpcUa_ExtensionObject& extensionObject) const = 0;
#endif

protected:
};

#endif //_DataSetReaderTransportDataTypeInt_H_