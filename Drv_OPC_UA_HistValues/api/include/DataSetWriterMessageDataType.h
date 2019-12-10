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

#ifndef DATASETWRITERMESSAGEDATATYPE_H
#define DATASETWRITERMESSAGEDATATYPE_H

#include "IDataSetWriterMessageDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The DataSetWriterMessageDataType is an abstract base type for message mapping specific DataSetWriter parameters. */
	class TBC_EXPORT DataSetWriterMessageDataType
	{
	public:
		/*! Default constructor */
		DataSetWriterMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetWriterMessageDataType(const IDataSetWriterMessageDataType* cp);
		/*! @overload */
		DataSetWriterMessageDataType(const IDataSetWriterMessageDataType& cp);
		/*! @overload */
		DataSetWriterMessageDataType(const DataSetWriterMessageDataType& cp);
		/*! For internal use only */
		DataSetWriterMessageDataType(const DataSetWriterMessageDataTypeStruct& cp);

		/*! Destructor */
		virtual ~DataSetWriterMessageDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetWriterMessageDataType& operator=(const IDataSetWriterMessageDataType* cp);
		/*! @overload */
		DataSetWriterMessageDataType& operator=(const IDataSetWriterMessageDataType& cp);
		/*! @overload */
		DataSetWriterMessageDataType& operator=(const DataSetWriterMessageDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		virtual EnumStatusCode set(const IDataSetWriterMessageDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetWriterMessageDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetWriterMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetWriterMessageDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetWriterMessageDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetWriterMessageDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IDataSetWriterMessageDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IDataSetWriterMessageDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
