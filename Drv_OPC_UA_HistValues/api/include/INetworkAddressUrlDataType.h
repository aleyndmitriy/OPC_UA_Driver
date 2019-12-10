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

#ifndef INETWORKADDRESSURLDATATYPE_H
#define INETWORKADDRESSURLDATATYPE_H

#include "NetworkAddressUrlDataTypeStruct.h"
#include "INetworkAddressDataType.h"

namespace SoftingOPCToolbox5
{
	/*! Interface to the concrete data type NetworkAddressUrlDataType, which is used to store network address information in the form of an URL String. */
	class TBC_EXPORT INetworkAddressUrlDataType : public INetworkAddressDataType
	{
	public:
		/*! Destructor */
		virtual ~INetworkAddressUrlDataType(){};

		/*! Sets the Url member in the class.
		*
		* @param url	The Url defines both the protocol and target / source of the data.
		*		Typical URL are
		*		@li %opc.udp://<host\>[:<port\>]
		*		@li %amqps://<domain name\>[:<port\>][/<path\>]
		*		@li %mqtts://<domain name\>[:<port\>][/<path\>
		*		@li %wss://<domain name\>[:<port\>][/<path\>] */
		virtual void setUrl(const tstring& url) = 0;
		/*! Gets the Url member of the class
		*
		* @see setUrl() */
		virtual tstring getUrl() const = 0;


		/*! Conversion from INetworkAddressDataType */
		static const INetworkAddressUrlDataType* castFrom(const INetworkAddressDataType* pSrc);
		/*! Conversion from INetworkAddressDataType */
		static INetworkAddressUrlDataType* castFrom(INetworkAddressDataType* pSrc);
	}; // end INetworkAddressUrlDataType
} // end namespace

#endif
