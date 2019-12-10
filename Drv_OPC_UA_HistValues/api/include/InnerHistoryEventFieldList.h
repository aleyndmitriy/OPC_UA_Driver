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

#ifndef INNERHISTORYEVENTFIELDLIST_H
#define INNERHISTORYEVENTFIELDLIST_H
#if TB5_HISTORY

#include "IHistoryEventFieldList.h"
#include "Value.h"
#include "IValue.h"
#include "InnerValue.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerHistoryEventFieldList
		: public IHistoryEventFieldList
	{
	public:
		/*! Destructor */
		virtual ~InnerHistoryEventFieldList();

		virtual std::vector<Value> getEventFields() const;
		virtual EnumStatusCode addEventField(const IValue* value);

		/*! For internal use only */
		void initInner(HistoryEventFieldListStruct* pHandle);

		virtual EnumStatusCode set(const IHistoryEventFieldList* pSrc);
		virtual EnumStatusCode set(const IHistoryEventFieldList& pSrc);

		virtual int compare(const IHistoryEventFieldList* other) const;
		virtual int compare(const IHistoryEventFieldList& other) const;

		virtual bool operator==(const IHistoryEventFieldList& other) const;
		virtual bool operator!=(const IHistoryEventFieldList& other) const;

		virtual void* getInternHandle() const;

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_pEventFields)

		HistoryEventFieldListStruct* m_pContent;
	};
} // end namespace

#endif
#endif	// INNERHISTORYEVENTFIELDLIST_H
