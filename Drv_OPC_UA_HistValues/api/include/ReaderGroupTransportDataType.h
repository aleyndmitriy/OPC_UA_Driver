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

#ifndef READERGROUPTRANSPORTDATATYPE_H
#define READERGROUPTRANSPORTDATATYPE_H

#include "IReaderGroupTransportDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerReaderGroupTransportDataType;
	/*! The ReaderGroupTransportDataType is an abstract base type for transport mapping specific ReaderGroup parameters. */
	class TBC_EXPORT ReaderGroupTransportDataType
	{
	public:
		/*! Default constructor */
		ReaderGroupTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		ReaderGroupTransportDataType(const IReaderGroupTransportDataType* cp);
		/*! @overload */
		ReaderGroupTransportDataType(const IReaderGroupTransportDataType& cp);
		/*! @overload */
		ReaderGroupTransportDataType(const ReaderGroupTransportDataType& cp);
		/*! For internal use only */
		ReaderGroupTransportDataType(const ReaderGroupTransportDataTypeStruct& cp);

		/*! Destructor */
		virtual ~ReaderGroupTransportDataType();

		/*! Assigns the contents of @p cp to this instance */
		ReaderGroupTransportDataType& operator=(const IReaderGroupTransportDataType* cp);
		/*! @overload */
		ReaderGroupTransportDataType& operator=(const IReaderGroupTransportDataType& cp);
		/*! @overload */
		ReaderGroupTransportDataType& operator=(const ReaderGroupTransportDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IReaderGroupTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IReaderGroupTransportDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const ReaderGroupTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const ReaderGroupTransportDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ReaderGroupTransportDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ReaderGroupTransportDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IReaderGroupTransportDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IReaderGroupTransportDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
