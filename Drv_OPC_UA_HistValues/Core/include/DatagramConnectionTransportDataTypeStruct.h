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

#ifndef _DatagramConnectionTransportDataTypeStruct_H_
#define _DatagramConnectionTransportDataTypeStruct_H_

#include "ConnectionTransportDataTypeStruct.h"
#include "NetworkAddressDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct DatagramConnectionTransportDataTypeInt;

//lint -sem(DatagramConnectionTransportDataTypeStruct::clear, cleanup)
//lint -sem(DatagramConnectionTransportDataTypeStruct::init, initializer)
struct TBCORE_IF DatagramConnectionTransportDataTypeStruct : public ConnectionTransportDataTypeStruct
{

	/*! Access network address of the datagram connection. */
	NetworkAddressDataTypeStruct *getDiscoveryAddress();

	/*! Set network address of the datagram connection. */
	EnumStatusCode setDiscoveryAddress(const NetworkAddressDataTypeStruct &address);

	DatagramConnectionTransportDataTypeStruct();
	DatagramConnectionTransportDataTypeStruct(const DatagramConnectionTransportDataTypeStruct&);
	DatagramConnectionTransportDataTypeStruct(const ConnectionTransportDataTypeStruct& cp, bool copyContent);

	EnumStatusCode set(const DatagramConnectionTransportDataTypeStruct&);
	EnumStatusCode set(const ConnectionTransportDataTypeStruct&);
	EnumStatusCode get(DatagramConnectionTransportDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_DatagramConnectionTransportDataType&);
	EnumStatusCode get(OpcUa_DatagramConnectionTransportDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const DatagramConnectionTransportDataTypeStruct& operator=(const DatagramConnectionTransportDataTypeStruct& cp);
	bool operator==(const DatagramConnectionTransportDataTypeStruct& toCompare) const;
	bool operator!=(const DatagramConnectionTransportDataTypeStruct& toCompare) const;
	bool operator<(const DatagramConnectionTransportDataTypeStruct& toCompare) const;
	bool operator>(const DatagramConnectionTransportDataTypeStruct& toCompare) const;

	int compare(const DatagramConnectionTransportDataTypeStruct* pTarget) const;

	void clear(void);
	~DatagramConnectionTransportDataTypeStruct(void);

protected:
	void init(void);
};

typedef struct DatagramConnectionTransportDataTypeStruct DatagramConnectionTransportDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
