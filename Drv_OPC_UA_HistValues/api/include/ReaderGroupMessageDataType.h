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

#ifndef READERGROUPMESSAGEDATATYPE_H
#define READERGROUPMESSAGEDATATYPE_H

#include "IReaderGroupMessageDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerReaderGroupMessageDataType;

	/*! The ReaderGroupMessageDataType is an abstract base type without fields for message mapping specific ReaderGroup parameters.
	*
	* Currently no concrete subclasses are defined, so it cannot be used at all.
	*
	* The data type is used as member of ReaderGroupDataType. */
	class TBC_EXPORT ReaderGroupMessageDataType
	{
	public:
		/*! Default constructor */
		ReaderGroupMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		ReaderGroupMessageDataType(const IReaderGroupMessageDataType* cp);
		/*! @overload */
		ReaderGroupMessageDataType(const IReaderGroupMessageDataType& cp);
		/*! @overload */
		ReaderGroupMessageDataType(const ReaderGroupMessageDataType& cp);
		/*! For internal use only */
		ReaderGroupMessageDataType(const ReaderGroupMessageDataTypeStruct& cp);

		/*! Destructor */
		virtual ~ReaderGroupMessageDataType();

		/*! Assigns the contents of @p cp to this instance */
		ReaderGroupMessageDataType& operator=(const IReaderGroupMessageDataType* cp);
		/*! @overload */
		ReaderGroupMessageDataType& operator=(const IReaderGroupMessageDataType& cp);
		/*! @overload */
		ReaderGroupMessageDataType& operator=(const ReaderGroupMessageDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const IReaderGroupMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const IReaderGroupMessageDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const ReaderGroupMessageDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const ReaderGroupMessageDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ReaderGroupMessageDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const ReaderGroupMessageDataTypeStruct& pSrc);

		/*! Access the contained object */
		const IReaderGroupMessageDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		IReaderGroupMessageDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
