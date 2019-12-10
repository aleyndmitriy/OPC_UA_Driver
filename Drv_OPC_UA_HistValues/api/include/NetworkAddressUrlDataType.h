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

#ifndef NETWORKADDRESSURLDATATYPE_H
#define NETWORKADDRESSURLDATATYPE_H

#include "INetworkAddressUrlDataType.h"
#include "NetworkAddressUrlDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of NetworkAddressDataType.
	*
	* It is used to store network address information in the form of an URL String.
	*
	* The NetworkInterface member defines the network interface (IP address) which shall be used to send / receive data
	* The URL member defines both the protocol and target / source of the data.
	* Typical URL are
	* @li %opc.udp://<host\>[:/<port\>]
	* @li %amqps://<domain name\>[:<port\>][/<path\>]
	* @li %mqtts://<domain name\>[:<port\>][/<path\>
	* @li %wss://<domain name\>[:<port\>][/<path\>] */
	class TBC_EXPORT NetworkAddressUrlDataType
		: public INetworkAddressUrlDataType
	{
	public:
		/*! Default constructor */
		NetworkAddressUrlDataType();
		/*! Constructs a copy of the given instance @p cp */
		NetworkAddressUrlDataType(const INetworkAddressUrlDataType* cp);
		/*! @overload */
		NetworkAddressUrlDataType(const INetworkAddressUrlDataType& cp);
		/*! @overload */
		NetworkAddressUrlDataType(const NetworkAddressUrlDataType& cp);
		/*! @overload */
		NetworkAddressUrlDataType(const tstring& url, const tstring& networkInterface);

		/*! Destructor */
		virtual ~NetworkAddressUrlDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		NetworkAddressUrlDataType& operator=(const INetworkAddressUrlDataType* cp);
		/*! @overload */
		NetworkAddressUrlDataType& operator=(const INetworkAddressUrlDataType& cp);
		/*! @overload */
		NetworkAddressUrlDataType& operator=(const NetworkAddressUrlDataType& cp);

		/* see INetworkAddressUrlDataType::compare(INetworkAddressDataType*) */
		virtual int compare(const INetworkAddressDataType* other) const;
		/*! @overload */
		virtual int compare(const INetworkAddressDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const INetworkAddressDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const INetworkAddressDataType& other) const;

		/* see INetworkAddressDataType::set(INetworkAddressDataType*) */
		virtual EnumStatusCode set(const INetworkAddressDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const INetworkAddressDataType& pSrc);

		/* see INetworkAddressUrlDataType::setUrl() */
		virtual void setUrl(const tstring& url);
		/* see INetworkAddressUrlDataType::getUrl(*) */
		virtual tstring getUrl() const;

		/* see INetworkAddressDataType::setNetworkInterface() */
		virtual void setNetworkInterface(const tstring& networkInterface);
		/* see INetworkAddressDataType::getNetworkInterface() */
		virtual tstring getNetworkInterface() const;

		/*! For internal use only */
		virtual NetworkAddressDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const NetworkAddressDataTypeStruct* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:

		NetworkAddressUrlDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
