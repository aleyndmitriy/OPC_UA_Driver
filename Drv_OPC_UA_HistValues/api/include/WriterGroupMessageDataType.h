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

#ifndef WRITERGROUPMESSAGEDATATYPE_H
#define WRITERGROUPMESSAGEDATATYPE_H

#include "IWriterGroupMessageDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The WriterGroupMessageDataType is an abstract base type without fields for message mapping specific WriterGroup parameters.
	*
	* Please use concrete derived classes to configure specific parameters.
	* Concrete subtypes are UadpWriterGroupMessageDataType and JsonWriterGroupMessageDataType (not yet supported) */
	class TBC_EXPORT WriterGroupMessageDataType
	{
	public:
		/*! Default constructor */
		WriterGroupMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		WriterGroupMessageDataType(const IWriterGroupMessageDataType* cp);
		/*! @overload */
		WriterGroupMessageDataType(const IWriterGroupMessageDataType& cp);
		/*! @overload */
		WriterGroupMessageDataType(const WriterGroupMessageDataType& cp);
		/*! For internal use only */
		WriterGroupMessageDataType(const WriterGroupMessageDataTypeStruct& cp);

		/*! Destructor */
		virtual ~WriterGroupMessageDataType();

		/*! Assigns the contents of @p cp to this instance */
		WriterGroupMessageDataType& operator=(const IWriterGroupMessageDataType* cp);
		/*! @overload */
		WriterGroupMessageDataType& operator=(const IWriterGroupMessageDataType& cp);
		/*! @overload */
		WriterGroupMessageDataType& operator=(const WriterGroupMessageDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const WriterGroupMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const WriterGroupMessageDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const WriterGroupMessageDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const WriterGroupMessageDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IWriterGroupMessageDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IWriterGroupMessageDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
