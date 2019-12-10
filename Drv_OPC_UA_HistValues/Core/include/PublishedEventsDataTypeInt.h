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

#ifndef _PublishedEventsDataTypeInt_H_
#define _PublishedEventsDataTypeInt_H_

#include "PublishedDataSetSourceDataTypeInt.h"
#include "PublishedVariableDataTypeStruct.h"

//lint -sem(PublishedEventsDataTypeInt::clearInternal, cleanup)
struct PublishedEventsDataTypeInt : public PublishedDataSetSourceDataTypeInt
{
	PublishedEventsDataTypeInt();
	PublishedEventsDataTypeInt(const PublishedEventsDataTypeInt& cp);
	virtual ~PublishedEventsDataTypeInt();

	/*! Access the NodeId of the Object in the event notifier tree. */
	NodeIdStruct &getEventNotifier();

	/*! Set the NodeId of the Object in the event notifier tree. */
	EnumStatusCode setEventNotifier(const NodeIdStruct &notifier);

	/*! Access the selection of Event fields contained in the DataSet generated for an Event. */
	SimpleAttributeOperandStruct *getSelectedFields(unsigned &count);

	/*! Set the selection of Event fields contained in the DataSet generated for an Event. */
	EnumStatusCode setSelectedFields(const SimpleAttributeOperandStruct *selectedFields, unsigned count);

	EnumStatusCode addSelectedField(const SimpleAttributeOperandStruct &value);

	/*! Access the filter applied to the Events. */
	ContentFilterStruct &getFilter();

	/*! Set the filter applied to the Events. */
	EnumStatusCode setFilter(const ContentFilterStruct &value);


	EnumStatusCode set(const PublishedEventsDataTypeInt &source);

	virtual int compare(const PublishedDataSetSourceDataTypeInt* pTarget) const;
	virtual EnumStatusCode set(const PublishedDataSetSourceDataTypeInt &source);
	virtual PublishedDataSetSourceDataTypeInt *clone() const;


	virtual void clear();

	virtual OTUInt32 getTypeId() const;

#ifdef OT_COMPILATION
	static EnumStatusCode prepareExtensionObject(OpcUa_ExtensionObject& target);
	virtual EnumStatusCode set(const OpcUa_ExtensionObject& source);
	virtual EnumStatusCode get(OpcUa_ExtensionObject& target) const;

	EnumStatusCode set(const OpcUa_PublishedEventsDataType &source);
	EnumStatusCode get(OpcUa_PublishedEventsDataType &target) const;
#endif

	/*! Defines the NodeId of the Object in the event notifier tree. */
	NodeIdStruct eventNotifier;

	/*! Defines the selection of Event fields contained in the DataSet generated for an Event. */
	SimpleAttributeOperandStruct* pSelectedFields;
	unsigned pSelectedFields_count;

	/*! The parameter Filter defines the filter applied to the Events. */
	ContentFilterStruct filter;

protected:
	void clearInternal();
};

#endif //_PublishedEventsDataTypeInt_H_