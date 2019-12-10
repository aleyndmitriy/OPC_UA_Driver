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

#ifndef SUBSCRIBEDDATASETDATATYPE_H
#define SUBSCRIBEDDATASETDATATYPE_H

#include "ISubscribedDataSetDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	class InnerSubscribedDataSetDataType;

	/*! The SubscribedDataSetDataType is an abstract base type without fields for SubscribedDataSet parameters.
	*
	* Please use concrete derived classes to configure specific parameters.
	* Concrete subclasses are TargetVariablesDataType and SubscribedDataSetMirrorDataType */
	class TBC_EXPORT SubscribedDataSetDataType
	{
	public:
		/*! Default constructor */
		SubscribedDataSetDataType();
		/*! Constructs a copy of the given instance @p cp */
		SubscribedDataSetDataType(const ISubscribedDataSetDataType* cp);
		/*! @overload */
		SubscribedDataSetDataType(const ISubscribedDataSetDataType& cp);
		/*! @overload */
		SubscribedDataSetDataType(const SubscribedDataSetDataType& cp);
		/*! For internal use only */
		SubscribedDataSetDataType(const SubscribedDataSetDataTypeStruct& cp);

		/*! Destructor */
		virtual ~SubscribedDataSetDataType();

		/*! Assigns the contents of @p cp to this instance */
		SubscribedDataSetDataType& operator=(const ISubscribedDataSetDataType* cp);
		/*! @overload */
		SubscribedDataSetDataType& operator=(const ISubscribedDataSetDataType& cp);
		/*! @overload */
		SubscribedDataSetDataType& operator=(const SubscribedDataSetDataType& cp);

		/*! Assigns the contents of @p pSrc to this instance */
		EnumStatusCode set(const ISubscribedDataSetDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const ISubscribedDataSetDataType& pSrc);
		/*! @overload */
		EnumStatusCode set(const SubscribedDataSetDataType* pSrc);
		/*! @overload */
		EnumStatusCode set(const SubscribedDataSetDataType& pSrc);
		/*! For internal use only */
		EnumStatusCode set(const SubscribedDataSetDataTypeStruct* pSrc);
		/*! For internal use only */
		EnumStatusCode set(const SubscribedDataSetDataTypeStruct& pSrc);

		/*! Access the contained object */
		const ISubscribedDataSetDataType& getInterface() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		/*! For internal use only */
		void destroyContent();

		ISubscribedDataSetDataType* m_pContent;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
