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

#ifndef DATAGRAMCONNECTIONTRANSPORTDATATYPE_H
#define DATAGRAMCONNECTIONTRANSPORTDATATYPE_H

#include "IDatagramConnectionTransportDataType.h"
#include "NetworkAddressDataType.h"
#include "INetworkAddressDataType.h"
#include "InnerNetworkAddressDataType.h"
#include "DatagramConnectionTransportDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a subclass of ConnectionTransportDataType.
	*
	* It is used configure parameters for the Datagram transport protocol (e.g UDP) specific settings of PubSubConnections. */
	class TBC_EXPORT DatagramConnectionTransportDataType
		: public IDatagramConnectionTransportDataType
	{
	public:
		/*! Default constructor */
		DatagramConnectionTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		DatagramConnectionTransportDataType(const IDatagramConnectionTransportDataType* cp);
		/*! @overload */
		DatagramConnectionTransportDataType(const IDatagramConnectionTransportDataType& cp);
		/*! @overload */
		DatagramConnectionTransportDataType(const DatagramConnectionTransportDataType& cp);

		/*! Destructor */
		virtual ~DatagramConnectionTransportDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		DatagramConnectionTransportDataType& operator=(const IDatagramConnectionTransportDataType* cp);
		/*! @overload */
		DatagramConnectionTransportDataType& operator=(const IDatagramConnectionTransportDataType& cp);
		/*! @overload */
		DatagramConnectionTransportDataType& operator=(const DatagramConnectionTransportDataType& cp);

		/* see IDatagramConnectionTransportDataType::compare(IConnectionTransportDataType*) */
		virtual int compare(const IConnectionTransportDataType* other) const;
		/*! @overload */
		virtual int compare(const IConnectionTransportDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IConnectionTransportDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IConnectionTransportDataType& other) const;

		/* see IConnectionTransportDataType::set(IConnectionTransportDataType*) */
		virtual EnumStatusCode set(const IConnectionTransportDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IConnectionTransportDataType& pSrc);

		/* see IDatagramConnectionTransportDataType::setDiscoveryAddress() */
		virtual EnumStatusCode setDiscoveryAddress(const INetworkAddressDataType* discoveryAddress);
		/*! @overload */
		virtual EnumStatusCode setDiscoveryAddress(const NetworkAddressDataType& discoveryAddress);
		/* see IDatagramConnectionTransportDataType::getDiscoveryAddress() */
		virtual NetworkAddressDataType getDiscoveryAddress() const;


		/*! For internal use only */
		virtual ConnectionTransportDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const ConnectionTransportDataTypeStruct* getInternHandle() const;

		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerNetworkAddressDataType m_discoveryAddress;

		DatagramConnectionTransportDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
