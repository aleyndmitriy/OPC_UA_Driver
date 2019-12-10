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

#ifndef _NetworkAddressDataTypeStruct_H_
#define _NetworkAddressDataTypeStruct_H_

#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct NetworkAddressDataTypeInt;

//lint -sem(NetworkAddressDataTypeStruct::clear, cleanup)
//lint -sem(NetworkAddressDataTypeStruct::init, initializer)
typedef struct TBCORE_IF NetworkAddressDataTypeStruct
{
	NetworkAddressDataTypeStruct();
	NetworkAddressDataTypeStruct(const NetworkAddressDataTypeStruct&);

	EnumDataTypeId getDataType() const;

	/*! Access the name of the network interface used for the communication relation. */
	const OTChar* getNetworkInterface() const;

	/*! Set the name of the network interface used for the communication relation. */
	EnumStatusCode setNetworkInterface(const OTChar* pNetworkInterface);

	EnumStatusCode set(const NetworkAddressDataTypeStruct&);
	EnumStatusCode get(NetworkAddressDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ExtensionObject& source);
	EnumStatusCode get(OpcUa_ExtensionObject& target) const;
#endif

	const NetworkAddressDataTypeStruct& operator=(const NetworkAddressDataTypeStruct& cp);
	bool operator==(const NetworkAddressDataTypeStruct& toCompare) const;
	bool operator!=(const NetworkAddressDataTypeStruct& toCompare) const;
	bool operator<(const NetworkAddressDataTypeStruct& toCompare) const;
	bool operator>(const NetworkAddressDataTypeStruct& toCompare) const;

	int compare(const NetworkAddressDataTypeStruct* pTarget) const;

	void clear(void);
	~NetworkAddressDataTypeStruct(void);

	NetworkAddressDataTypeInt *getContent() const;
protected:
	// Internal object
	NetworkAddressDataTypeInt *pContent;
	// Flag set in subclasses when the content is not owned
	bool bNoRelease;
} NetworkAddressDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
