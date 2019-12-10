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

#ifndef __EVENTFIELDLISTSTRUCT_H_
#define __EVENTFIELDLISTSTRUCT_H_

#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure to store a list of event fields. This is used when reporting the event notifications from the
* server to the client (in the subscription callback). */
//lint -sem(EventFieldListStruct::clear, cleanup)
//lint -sem(EventFieldListStruct::init, initializer)
typedef struct TBCORE_IF EventFieldListStruct
{
	OTUInt32 eventFields_count;
	ValueStruct* pEventFields;


	EventFieldListStruct();
	EnumStatusCode addEventField(const ValueStruct* pValue);

	EnumStatusCode set(const EventFieldListStruct&);
	EnumStatusCode get(EventFieldListStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_EventFieldList&);
	EnumStatusCode get(OpcUa_EventFieldList&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const EventFieldListStruct& operator=(const EventFieldListStruct& cp);
	bool operator==(const EventFieldListStruct& toCompare) const;
	bool operator!=(const EventFieldListStruct& toCompare) const;
	bool operator<(const EventFieldListStruct& toCompare) const;
	bool operator>(const EventFieldListStruct& toCompare) const;

	int compare(const EventFieldListStruct* pTarget) const;

	void clear(void);
	~EventFieldListStruct(void);

}EventFieldListStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
