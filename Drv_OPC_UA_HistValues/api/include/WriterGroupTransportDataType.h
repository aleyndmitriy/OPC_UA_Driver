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

#ifndef WRITERGROUPTRANSPORTDATATYPE_H
#define WRITERGROUPTRANSPORTDATATYPE_H

#include "IWriterGroupTransportDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerWriterGroupTransportDataType;

	/*! The ConnectionTransportDataType is an abstract base type for transport mapping specific PubSubConnection parameters.
	*
	* Please use concrete derived classes to configure transport specific parameters.
	* Concrete classes are UadpDataSetWriterMessageDataType and JsonDataSetWriterMessageDataType (not yet supported). */
	class TBC_EXPORT WriterGroupTransportDataType
	{
	public:
		/*! Default constructor */
		WriterGroupTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		WriterGroupTransportDataType(const IWriterGroupTransportDataType* cp);
		/*! @overload */
		WriterGroupTransportDataType(const IWriterGroupTransportDataType& cp);
		/*! @overload */
		WriterGroupTransportDataType(const WriterGroupTransportDataType& cp);
		/*! For internal use only */
		WriterGroupTransportDataType(const WriterGroupTransportDataTypeStruct& cp);

		/*! Destructor */
		virtual ~WriterGroupTransportDataType();

		/*! Assigns the contents of @p cp to this instance */
		WriterGroupTransportDataType& operator=(const IWriterGroupTransportDataType* cp);
		/*! @overload */
		WriterGroupTransportDataType& operator=(const IWriterGroupTransportDataType& cp);
		/*! @overload */
		WriterGroupTransportDataType& operator=(const WriterGroupTransportDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IWriterGroupTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IWriterGroupTransportDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const WriterGroupTransportDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const WriterGroupTransportDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const WriterGroupTransportDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const WriterGroupTransportDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IWriterGroupTransportDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IWriterGroupTransportDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
