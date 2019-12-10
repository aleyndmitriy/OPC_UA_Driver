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

#ifndef DATASETREADERTRANSPORTDATATYPE_H
#define DATASETREADERTRANSPORTDATATYPE_H

#include "IDataSetReaderTransportDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerDataSetReaderTransportDataType;

	/*! The DataSetReaderTransportDataType is an abstract base type for transport specific DataSetReader parameters.
	*
	* Concrete classes exist only for broker transport BrokerDataSetReaderTransportDataType (not yet implemented). */
	class TBC_EXPORT DataSetReaderTransportDataType
	{
	public:
		/*! Default constructor */
		DataSetReaderTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetReaderTransportDataType(const IDataSetReaderTransportDataType* cp);
		/*! @overload */
		DataSetReaderTransportDataType(const IDataSetReaderTransportDataType& cp);
		/*! @overload */
		DataSetReaderTransportDataType(const DataSetReaderTransportDataType& cp);
		/*! For internal use only */
		DataSetReaderTransportDataType(const DataSetReaderTransportDataTypeStruct& cp);

		/*! Destructor */
		virtual ~DataSetReaderTransportDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetReaderTransportDataType& operator=(const IDataSetReaderTransportDataType* cp);
		/*! @overload */
		DataSetReaderTransportDataType& operator=(const IDataSetReaderTransportDataType& cp);
		/*! @overload */
		DataSetReaderTransportDataType& operator=(const DataSetReaderTransportDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IDataSetReaderTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IDataSetReaderTransportDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetReaderTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetReaderTransportDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetReaderTransportDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetReaderTransportDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IDataSetReaderTransportDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IDataSetReaderTransportDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
