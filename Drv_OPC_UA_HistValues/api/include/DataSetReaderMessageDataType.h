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

#ifndef DATASETREADERMESSAGEDATATYPE_H
#define DATASETREADERMESSAGEDATATYPE_H

#include "IDataSetReaderMessageDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerDataSetReaderMessageDataType;

	/*! The DataSetReaderMessageDataType is an abstract base type without fields for message mapping specific DataSetReader parameters.
	*
	* Please use concrete derived classes to configure specific parameters.
	* Concrete classes are UadpDataSetReaderMessageDataType and JsonDataSetReaderMessageDataType (not yet supported). */
	class TBC_EXPORT DataSetReaderMessageDataType
	{
	public:
		/*! Default constructor */
		DataSetReaderMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		DataSetReaderMessageDataType(const IDataSetReaderMessageDataType* cp);
		/*! @overload */
		DataSetReaderMessageDataType(const IDataSetReaderMessageDataType& cp);
		/*! @overload */
		DataSetReaderMessageDataType(const DataSetReaderMessageDataType& cp);
		/*! For internal use only */
		DataSetReaderMessageDataType(const DataSetReaderMessageDataTypeStruct& cp);

		/*! Destructor */
		virtual ~DataSetReaderMessageDataType();

		/*! Assigns the contents of @p cp to this instance */
		DataSetReaderMessageDataType& operator=(const IDataSetReaderMessageDataType* cp);
		/*! @overload */
		DataSetReaderMessageDataType& operator=(const IDataSetReaderMessageDataType& cp);
		/*! @overload */
		DataSetReaderMessageDataType& operator=(const DataSetReaderMessageDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IDataSetReaderMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IDataSetReaderMessageDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetReaderMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const DataSetReaderMessageDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetReaderMessageDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const DataSetReaderMessageDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IDataSetReaderMessageDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IDataSetReaderMessageDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
