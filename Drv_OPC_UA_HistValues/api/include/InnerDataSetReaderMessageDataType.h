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

#ifndef INNERDATASETREADERMESSAGEDATATYPE_H
#define INNERDATASETREADERMESSAGEDATATYPE_H

#include "IDataSetReaderMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerDataSetReaderMessageDataType
		: public IDataSetReaderMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerDataSetReaderMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! For internal use only */
		void initInner(DataSetReaderMessageDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IDataSetReaderMessageDataType* pSrc);
		virtual EnumStatusCode set(const IDataSetReaderMessageDataType& pSrc);

		virtual int compare(const IDataSetReaderMessageDataType* other) const;
		virtual int compare(const IDataSetReaderMessageDataType& other) const;

		virtual bool operator==(const IDataSetReaderMessageDataType& other) const;
		virtual bool operator!=(const IDataSetReaderMessageDataType& other) const;

		virtual DataSetReaderMessageDataTypeStruct* getInternHandle();
		virtual const DataSetReaderMessageDataTypeStruct* getInternHandle() const;

	private:

		DataSetReaderMessageDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
