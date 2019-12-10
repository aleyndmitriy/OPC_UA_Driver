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

#ifndef __RELATIVEPATHSTRUCT_H_
#define __RELATIVEPATHSTRUCT_H_

#include "RelativePathElementStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure that defines a sequence of References and BrowseNames to follow. */
//lint -sem(RelativePathStruct::clear, cleanup)
//lint -sem(RelativePathStruct::init, initializer)
typedef struct TBCORE_IF RelativePathStruct
{
	/*! A sequence of References and BrowseNames to follow.
	* Each element in the sequence is processed by finding the targets and then using those targets as the starting
	* nodes for the next element. The targets of the final element are the target of the RelativePath. */
	OTUInt32 elements_count;
	RelativePathElementStruct* pElements;


	RelativePathStruct();
	EnumStatusCode addElement(const RelativePathElementStruct* pRelativePathElement);

	EnumStatusCode set(const RelativePathStruct&);
	EnumStatusCode get(RelativePathStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_RelativePath&);
	EnumStatusCode get(OpcUa_RelativePath&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	static EnumStatusCode parse(const tstring& reader, RelativePathStruct& target, void* context = NULL);

	const RelativePathStruct& operator=(const RelativePathStruct& cp);
	bool operator==(const RelativePathStruct& toCompare) const;
	bool operator!=(const RelativePathStruct& toCompare) const;
	bool operator<(const RelativePathStruct& toCompare) const;
	bool operator>(const RelativePathStruct& toCompare) const;

	int compare(const RelativePathStruct* pTarget) const;

	void clear(void);
	~RelativePathStruct(void);

}RelativePathStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
