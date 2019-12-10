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

#ifndef INNERWRITERGROUPTRANSPORTDATATYPE_H
#define INNERWRITERGROUPTRANSPORTDATATYPE_H

#include "IWriterGroupTransportDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerWriterGroupTransportDataType
		: public IWriterGroupTransportDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerWriterGroupTransportDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! For internal use only */
		void initInner(WriterGroupTransportDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IWriterGroupTransportDataType* pSrc);
		virtual EnumStatusCode set(const IWriterGroupTransportDataType& pSrc);

		virtual int compare(const IWriterGroupTransportDataType* other) const;
		virtual int compare(const IWriterGroupTransportDataType& other) const;

		virtual bool operator==(const IWriterGroupTransportDataType& other) const;
		virtual bool operator!=(const IWriterGroupTransportDataType& other) const;

		virtual WriterGroupTransportDataTypeStruct* getInternHandle();
		virtual const WriterGroupTransportDataTypeStruct* getInternHandle() const;

	private:

		WriterGroupTransportDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
