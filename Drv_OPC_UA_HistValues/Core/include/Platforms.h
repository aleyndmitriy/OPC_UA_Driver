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

#ifndef _TBUTIL_PLATFORMS_H_
#define _TBUTIL_PLATFORMS_H_


#ifdef SODEVENV_VXWORKS
	typedef atomic_t	OTAtomic;
#else
	typedef long		OTAtomic;
#endif

// defined for protection code against parallel access (without semaphore)
#define OT_SECTION_FREE	0
#define OT_SECTION_IN_USE 1

#ifdef SOOS_WINDOWS
	#define interlockedIncrement(a) InterlockedIncrement(a)
	#define interlockedDecrement(a) InterlockedDecrement(a)
	#define interlockedGet(a) InterlockedExchangeAdd(a,0)
	#define interlockedSet(a,v) (void)InterlockedExchange(a,v)
	#define interlockedCompareExchange(a,v,c) (InterlockedCompareExchange(a,v,c) == (c))
#endif

#ifdef SOOS_POSIX
	OTAtomic interlockedIncrement(OTAtomic *lpAddend);
	OTAtomic interlockedDecrement(OTAtomic *lpAddend);
	OTAtomic interlockedGet(OTAtomic *lpAddend);
	void interlockedSet(OTAtomic *lpAddend, OTAtomic value);
	bool interlockedCompareExchange(OTAtomic *lpAtomic, OTAtomic newValue, OTAtomic compareValue);
#endif


#endif // _PLATFORMS_H_
