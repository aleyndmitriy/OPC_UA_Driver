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

#ifndef INNERDATACHANGEFILTER_H
#define INNERDATACHANGEFILTER_H

#include "IDataChangeFilter.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerDataChangeFilter
	class TBC_EXPORT InnerDataChangeFilter
		: public IDataChangeFilter
	{
	public:
		/*! Destructor */
		virtual ~InnerDataChangeFilter();

		/*! Defines the events/changes which can cause the value to be reported. */
		virtual EnumDataChangeTrigger getTrigger() const;
		virtual void setTrigger(EnumDataChangeTrigger value);

		/*! The type of the deadband to apply. */
		virtual EnumDeadbandType getDeadbandType() const;
		virtual void setDeadbandType(EnumDeadbandType value);

		/*! The value of the deadband. */
		virtual double getDeadbandValue() const;
		virtual void setDeadbandValue(double value);


		// init from otb handle
		void initInner(DataChangeFilterStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IDataChangeFilter* other) const;
		/*! @overload */
		virtual int compare(const IDataChangeFilter& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataChangeFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataChangeFilter& other) const;

		// set from interface
		EnumStatusCode set(const IDataChangeFilter* pSrc);
		EnumStatusCode set(const IDataChangeFilter& pSrc);

		// protected:
		// the handle to the related core object
		DataChangeFilterStruct* m_pDataChangeFilter_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERDATACHANGEFILTER_H
