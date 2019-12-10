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

#ifndef IDATAGRAMCONNECTIONTRANSPORTDATATYPE_H
#define IDATAGRAMCONNECTIONTRANSPORTDATATYPE_H

#include "NetworkAddressDataType.h"
#include "INetworkAddressDataType.h"
#include "IConnectionTransportDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The DatagramConnectionTransportDataType is used to store the configuration parameters for the Datagram
	* transport protocol specific settings of PubSubConnections. */
	class TBC_EXPORT IDatagramConnectionTransportDataType : public IConnectionTransportDataType
	{
	public:
		/*! Destructor */
		virtual ~IDatagramConnectionTransportDataType(){};

		/*! Sets the DiscoveryAddress member in the class
		*
		* @param discoveryAddress	The network address information used for the discovery request and response messages. */
		virtual EnumStatusCode setDiscoveryAddress(const INetworkAddressDataType* discoveryAddress) = 0;
		/*! @overload */
		virtual EnumStatusCode setDiscoveryAddress(const NetworkAddressDataType& discoveryAddress) = 0;
		/*! Gets the DiscoveryAddress member of the class */
		virtual NetworkAddressDataType getDiscoveryAddress() const = 0;

		/*! Conversion from IConnectionTransportDataType */
		static const IDatagramConnectionTransportDataType* castFrom(const IConnectionTransportDataType* pSrc);
		/*! Conversion from IConnectionTransportDataType */
		static IDatagramConnectionTransportDataType* castFrom(IConnectionTransportDataType* pSrc);
	}; // end IDatagramConnectionTransportDataType
} // end namespace

#endif
