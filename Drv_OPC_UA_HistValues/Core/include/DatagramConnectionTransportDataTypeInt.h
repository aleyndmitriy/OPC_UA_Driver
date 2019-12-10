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

#ifndef _DatagramConnectionTransportDataTypeInt_H_
#define _DatagramConnectionTransportDataTypeInt_H_

#include "ConnectionTransportDataTypeInt.h"
#include "NetworkAddressDataTypeStruct.h"

//lint -sem(DatagramConnectionTransportDataTypeInt::clearInternal, cleanup)
struct DatagramConnectionTransportDataTypeInt : public ConnectionTransportDataTypeInt
{
	DatagramConnectionTransportDataTypeInt();
	DatagramConnectionTransportDataTypeInt(const DatagramConnectionTransportDataTypeInt &source);
	virtual ~DatagramConnectionTransportDataTypeInt();

	/*! Access network address of the datagram connection. */
	NetworkAddressDataTypeStruct &getDiscoveryAddress();
	const NetworkAddressDataTypeStruct &getDiscoveryAddress() const;

	/*! Set network address of the datagram connection. */
	EnumStatusCode setDiscoveryAddress(const NetworkAddressDataTypeStruct &address);

	virtual ConnectionTransportDataTypeInt *clone() const;
	virtual EnumStatusCode set(const ConnectionTransportDataTypeInt &source);
	virtual int compare(const ConnectionTransportDataTypeInt* pTarget) const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const DatagramConnectionTransportDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_DatagramConnectionTransportDataType &source);
	EnumStatusCode get(OpcUa_DatagramConnectionTransportDataType &target) const;
#endif

protected:
	/*! Network address of the datagram connection. */
	NetworkAddressDataTypeStruct discoveryAddress;

	void clearInternal();

};

#endif //_DatagramConnectionTransportDataTypeInt_H_