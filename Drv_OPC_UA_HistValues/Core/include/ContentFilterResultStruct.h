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

#ifndef _ContentFilterResultStruct_H_
#define _ContentFilterResultStruct_H_
#if TB5_FILTER

#include "ContentFilterElementResultStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

//lint -sem(ContentFilterResultStruct::clear, cleanup)
//lint -sem(ContentFilterResultStruct::init, initializer)
typedef struct TBCORE_IF ContentFilterResultStruct
{
	/*!
	 * A list of results for individual elements in the filter. The size and order of the list
	 * matches the size and order of the elements in the ContentFilter parameter.
	 */
	ContentFilterElementResultStruct* pElementResults;
	unsigned pElementResults_count;

	DiagnosticInfoStruct* pElementDiagnosticInfos;
	unsigned pElementDiagnosticInfos_count;


	ContentFilterResultStruct();
	ContentFilterResultStruct(const ContentFilterResultStruct&);

	EnumStatusCode set(const ContentFilterResultStruct&);
	EnumStatusCode get(ContentFilterResultStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ContentFilterResult&);
	EnumStatusCode get(OpcUa_ContentFilterResult&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const ContentFilterResultStruct& operator=(const ContentFilterResultStruct& cp);
	bool operator==(const ContentFilterResultStruct& toCompare) const;
	bool operator!=(const ContentFilterResultStruct& toCompare) const;
	bool operator<(const ContentFilterResultStruct& toCompare) const;
	bool operator>(const ContentFilterResultStruct& toCompare) const;

	int compare(const ContentFilterResultStruct* pTarget) const;

	void clear(void);
	~ContentFilterResultStruct(void);
} ContentFilterResultStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
