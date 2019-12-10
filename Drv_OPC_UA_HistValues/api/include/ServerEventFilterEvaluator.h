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

#ifndef SERVEREVENTFILTEREVALUATOR_H
#define SERVEREVENTFILTEREVALUATOR_H
#if TB5_ALARMS

#include "ContentFilter.h"
#include "IEventFilterTarget.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class provides means to evaluate whether a (historical) event passes
		* an event filter provided by the client or not. It is meant to be used by server
		* applications in the context of a HistoryReadTransaction.
		*
		* @see HistoryReadEventTransaction */
		class TBC_EXPORT EventFilterEvaluator
		{
		public:
			/*! Evaluates whether a (historical) event passes an event filter.
			*
			* @param[in]	eventFilter			The event filter under which the historical event is to be evaluated
			* @param[in]	historicalEvent		The historical event that is to be evaluated
			* @param[out]	eventPassesFilter	If true, the historical event passes the event filter.
			*
			* @note		A bad status code indicates that an error occurred during filter evaluation. In this case,
			*			the value of @p eventPassesFilter is undefined! */
			static EnumStatusCode evaluate(const ContentFilter& eventFilter, IEventFilterTarget& historicalEvent,
				bool& eventPassesFilter);
		};
	}
}

#endif
#endif	// SERVEREVENTFILTEREVALUATOR_H
