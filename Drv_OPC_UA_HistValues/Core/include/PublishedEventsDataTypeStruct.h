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

#ifndef _PublishedEventsDataTypeStruct_H_
#define _PublishedEventsDataTypeStruct_H_

#include "PublishedDataSetSourceDataTypeStruct.h"
#include "NodeIdStruct.h"
#include "SimpleAttributeOperandStruct.h"
#include "ContentFilterStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

struct PublishedEventsDataTypeInt;

//lint -sem(PublishedEventsDataTypeStruct::clear, cleanup)
struct TBCORE_IF PublishedEventsDataTypeStruct : public PublishedDataSetSourceDataTypeStruct
{
	PublishedEventsDataTypeStruct();
	PublishedEventsDataTypeStruct(const PublishedEventsDataTypeStruct&);
	PublishedEventsDataTypeStruct(const PublishedDataSetSourceDataTypeStruct& cp, bool copyContent);
	~PublishedEventsDataTypeStruct(void);

	/*! Access the NodeId of the Object in the event notifier tree. */
	NodeIdStruct *getEventNotifier() const;

	/*! Set the NodeId of the Object in the event notifier tree. */
	EnumStatusCode setEventNotifier(const NodeIdStruct &notifier);

	/*! Access the selection of Event fields contained in the DataSet generated for an Event. */
	SimpleAttributeOperandStruct *getSelectedFields(unsigned &count);

	/*! Set the selection of Event fields contained in the DataSet generated for an Event. */
	EnumStatusCode setSelectedFields(const SimpleAttributeOperandStruct *selectedFields, unsigned count);

	EnumStatusCode addSelectedField(const SimpleAttributeOperandStruct &value);

	/*! Access the filter applied to the Events. */
	ContentFilterStruct *getFilter() const;

	/*! Set the filter applied to the Events. */
	EnumStatusCode setFilter(const ContentFilterStruct &filter);


	EnumStatusCode set(const PublishedEventsDataTypeStruct&);
	EnumStatusCode set(const PublishedDataSetSourceDataTypeStruct&);
	EnumStatusCode get(PublishedEventsDataTypeStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_PublishedEventsDataType&);
	EnumStatusCode get(OpcUa_PublishedEventsDataType&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const PublishedEventsDataTypeStruct& operator=(const PublishedEventsDataTypeStruct& cp);
	bool operator==(const PublishedEventsDataTypeStruct& toCompare) const;
	bool operator!=(const PublishedEventsDataTypeStruct& toCompare) const;
	bool operator<(const PublishedEventsDataTypeStruct& toCompare) const;
	bool operator>(const PublishedEventsDataTypeStruct& toCompare) const;

	int compare(const PublishedEventsDataTypeStruct* pTarget) const;

	void clear(void);

protected:
	void init(void);
};

typedef struct PublishedEventsDataTypeStruct PublishedEventsDataTypeStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
