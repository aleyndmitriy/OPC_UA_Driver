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

#ifndef NETWORKADDRESSDATATYPE_H
#define NETWORKADDRESSDATATYPE_H

#include "INetworkAddressDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerNetworkAddressDataType;

	/*! Subtypes of this abstract data type are used to store network address information.
	*
	* Please use concrete derived classes to configure transport specific parameters.
	* The currently only defined concrete class is NetworkAddressUrlDataType. */
	class TBC_EXPORT NetworkAddressDataType
	{
	public:
		/*! Default constructor */
		NetworkAddressDataType();
		/*! Constructs a copy of the given instance @p cp */
		NetworkAddressDataType(const INetworkAddressDataType* cp);
		/*! @overload */
		NetworkAddressDataType(const INetworkAddressDataType& cp);
		/*! @overload */
		NetworkAddressDataType(const NetworkAddressDataType& cp);
		/*! For internal use only */
		NetworkAddressDataType(const NetworkAddressDataTypeStruct& cp);

		/*! Destructor */
		virtual ~NetworkAddressDataType();

		/*! Assigns the contents of @p cp to this instance */
		NetworkAddressDataType& operator=(const INetworkAddressDataType* cp);
		/*! @overload */
		NetworkAddressDataType& operator=(const INetworkAddressDataType& cp);
		/*! @overload */
		NetworkAddressDataType& operator=(const NetworkAddressDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const INetworkAddressDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const INetworkAddressDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const NetworkAddressDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const NetworkAddressDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const NetworkAddressDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const NetworkAddressDataTypeStruct& pSrc);

		/*! Access the contained object */
		const INetworkAddressDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		INetworkAddressDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
