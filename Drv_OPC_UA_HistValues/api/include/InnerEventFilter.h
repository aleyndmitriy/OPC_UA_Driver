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

#ifndef INNEREVENTFILTER_H
#define INNEREVENTFILTER_H
#if TB5_ALARMS

#include "IEventFilter.h"
#include "InnerSimpleAttributeOperand.h"
#include "SimpleAttributeOperand.h"
#include "InnerContentFilter.h"
#include "ContentFilter.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerEventFilter
	class TBC_EXPORT InnerEventFilter
		: public IEventFilter
	{
	public:
		/*! Destructor */
		virtual ~InnerEventFilter();

		virtual OTUInt32 getSelectClauseCount() const;
		virtual const ISimpleAttributeOperand* getSelectClause(OTUInt32 index) const;
		virtual std::vector<SimpleAttributeOperand> getSelectClauses() const;
		virtual EnumStatusCode addSelectClause(const ISimpleAttributeOperand* pValue);
		virtual EnumStatusCode addSelectClause(const SimpleAttributeOperand& value);

		virtual const IContentFilter* getWhereClause() const;
		virtual IContentFilter* getWhereClause();
		virtual void setWhereClause(const IContentFilter* value);
		virtual void setWhereClause(const ContentFilter& value);


		// init from otb handle
		void initInner(EventFilterStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEventFilter* other) const;
		/*! @overload */
		virtual int compare(const IEventFilter& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEventFilter& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEventFilter& other) const;

		// set from interface
		EnumStatusCode set(const IEventFilter* pSrc);
		EnumStatusCode set(const IEventFilter& pSrc);

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		// the handle to the related core object
		EventFilterStruct* m_pEventFilter_Data;

		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerSimpleAttributeOperand> m_SelectClauses)
		InnerContentFilter m_WhereClause;
	};
}
#endif
#endif	// INNEREVENTFILTER_H
