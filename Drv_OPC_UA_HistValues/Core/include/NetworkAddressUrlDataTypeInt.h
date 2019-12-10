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

#ifndef _NetworkAddressUrlDataTypeInt_H_
#define _NetworkAddressUrlDataTypeInt_H_

#include "NetworkAddressDataTypeInt.h"

//lint -sem(NetworkAddressUrlDataTypeInt::clearInternal, cleanup)
struct NetworkAddressUrlDataTypeInt : public NetworkAddressDataTypeInt
{
	NetworkAddressUrlDataTypeInt();
	NetworkAddressUrlDataTypeInt(const NetworkAddressUrlDataTypeInt &source);
	virtual ~NetworkAddressUrlDataTypeInt();

	/*! Access the name of the network interface used for the communication relation. */
	virtual const OTChar* getNetworkInterface() const;

	/*! Set the name of the network interface used for the communication relation. */
	virtual EnumStatusCode setNetworkInterface(const OTChar* networkInterface);

	/*! Access the address string for the communication relation in the form on an URL String. */
	const OTChar* getUrl() const;

	/*! Set the address string for the communication relation in the form on an URL String. */
	EnumStatusCode setUrl(const OTChar* url);

	virtual NetworkAddressDataTypeInt *clone() const;
	virtual EnumStatusCode set(const NetworkAddressDataTypeInt &source);
	virtual int compare(const NetworkAddressDataTypeInt* pTarget) const;
	virtual void clear();
	virtual OTUInt32 getTypeId() const;

	EnumStatusCode set(const NetworkAddressUrlDataTypeInt &source);

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_NetworkAddressUrlDataType &source);
	EnumStatusCode get(OpcUa_NetworkAddressUrlDataType &target) const;
#endif

protected:
	/*! The address string for the communication relation in the form on an URL String. */
	OTChar* pUrl;

	/*! The name of the network interface used for the communication relation. */
	OTChar* pNetworkInterface;

	void clearInternal();

};

#endif //_NetworkAddressUrlDataTypeInt_H_