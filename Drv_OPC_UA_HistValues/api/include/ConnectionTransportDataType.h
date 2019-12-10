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

#ifndef CONNECTIONTRANSPORTDATATYPE_H
#define CONNECTIONTRANSPORTDATATYPE_H

#include "IConnectionTransportDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerConnectionTransportDataType;

	/*! The ConnectionTransportDataType is an abstract base type for transport mapping specific PubSubConnection parameters.
	*
	* Please use concrete derived classes to configure specific parameters.
	* Concrete classes are DatagramConnectionTransportDataType and BrokerConnectionTransportDataType (not yet supported). */
	class TBC_EXPORT ConnectionTransportDataType
	{
	public:
		/*! Default constructor */
		ConnectionTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		ConnectionTransportDataType(const IConnectionTransportDataType* cp);
		/*! @overload */
		ConnectionTransportDataType(const IConnectionTransportDataType& cp);
		/*! @overload */
		ConnectionTransportDataType(const ConnectionTransportDataType& cp);
		/*! For internal use only */
		ConnectionTransportDataType(const ConnectionTransportDataTypeStruct& cp);

		/*! Destructor */
		virtual ~ConnectionTransportDataType();

		/*! Assigns the contents of @p cp to this instance */
		ConnectionTransportDataType& operator=(const IConnectionTransportDataType* cp);
		/*! @overload */
		ConnectionTransportDataType& operator=(const IConnectionTransportDataType& cp);
		/*! @overload */
		ConnectionTransportDataType& operator=(const ConnectionTransportDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IConnectionTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IConnectionTransportDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const ConnectionTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const ConnectionTransportDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ConnectionTransportDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ConnectionTransportDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IConnectionTransportDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IConnectionTransportDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
