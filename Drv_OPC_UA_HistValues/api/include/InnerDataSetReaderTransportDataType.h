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

#ifndef INNERDATASETREADERTRANSPORTDATATYPE_H
#define INNERDATASETREADERTRANSPORTDATATYPE_H

#include "IDataSetReaderTransportDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataSetReaderTransportDataType
		: public IDataSetReaderTransportDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerDataSetReaderTransportDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! For internal use only */
		void initInner(DataSetReaderTransportDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IDataSetReaderTransportDataType* pSrc);
		virtual EnumStatusCode set(const IDataSetReaderTransportDataType& pSrc);

		virtual int compare(const IDataSetReaderTransportDataType* other) const;
		virtual int compare(const IDataSetReaderTransportDataType& other) const;

		virtual bool operator==(const IDataSetReaderTransportDataType& other) const;
		virtual bool operator!=(const IDataSetReaderTransportDataType& other) const;

		virtual DataSetReaderTransportDataTypeStruct* getInternHandle();
		virtual const DataSetReaderTransportDataTypeStruct* getInternHandle() const;

	private:

		DataSetReaderTransportDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
