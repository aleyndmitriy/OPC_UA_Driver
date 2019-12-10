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

#ifndef __QUALIFIEDNAMESTRUCT_H_
#define __QUALIFIEDNAMESTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! A name with an additional namespace index. This type of name is used for specifying BrowseNames (that
* must contain the namespace). */
//lint -sem(QualifiedNameStruct::clear, cleanup)
//lint -sem(QualifiedNameStruct::init, initializer)
typedef struct TBCORE_IF QualifiedNameStruct
{
	/*! String containing the name without namespaceindex. */
	OTChar* pName;

	/*! The namespaceindex to use building a BrowsePath. */
	unsigned short namespaceIndex;


	QualifiedNameStruct();
	EnumStatusCode setName(const OTChar* pValue);

	EnumStatusCode set(const QualifiedNameStruct&);
	EnumStatusCode get(QualifiedNameStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_QualifiedName&);
	EnumStatusCode get(OpcUa_QualifiedName&) const;
#endif
	QualifiedNameStruct(const OTChar* name, unsigned short namespecIndex);
	void setNameAndIndex_API(const OTChar* name, unsigned short index);
	tstring toString(void) const;
	static EnumStatusCode parse(const tstring& reader,
			bool isReferenceName,
			QualifiedNameStruct& name,
			size_t &sizeConsumed);
	QualifiedNameStruct(const QualifiedNameStruct& cp);

	const QualifiedNameStruct& operator=(const QualifiedNameStruct& cp);
	bool operator==(const QualifiedNameStruct& toCompare) const;
	bool operator!=(const QualifiedNameStruct& toCompare) const;
	bool operator<(const QualifiedNameStruct& toCompare) const;
	bool operator>(const QualifiedNameStruct& toCompare) const;

	int compare(const QualifiedNameStruct* pTarget) const;

	void clear(void);
	~QualifiedNameStruct(void);

}QualifiedNameStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
