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

#ifndef ACCESSPATTERNSTRUCT_H
#define ACCESSPATTERNSTRUCT_H

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! An AccessPattern defines by a field of bytes the UserAccessRights for Variable's value access and for
* the Method's UserExecutable flag.
* The pattern is identified by a 16-bit handle and each variable in the server can refer to such a defined
* pattern.
* Such a pattern defines for each UserGroup the access rights for that user group by a bytefield.
* Each session stores a GroupIndex which is - decremented by 1- the index in that array (the GroupIndex
* 0 is reserved and means UserAccessRights = Default-AccessRights).
*
* E.g. a sequence 0x03, 0x01 in the accessField means for variables referring to this pattern:
* Users from group 1 (the index is 1-based) are allowed to read and write the current value .
* Users from group 2 are only allowed to read the current value (write bit is not set).
* Each Variable and each method in the server can define the pattern to use for this variable. */

//lint -sem(AccessPatternStruct::clear, cleanup)
//lint -sem(AccessPatternStruct::init, initializer)
typedef struct TBCORE_IF AccessPatternStruct
{
	/*! The field of access defining bytes. Each byte in that field defines in the lowest 5 bits (0..4) the AccessMode
	* used for variables
	* with the same meaning of the bits as defined by the enumeration EnumAccessLevel.
	*
	* For methods the bit 7 is used for marking the method as userExecutable (bit is high) or not (low).
	*
	* The bits 5 and 6 are currently unused and shall be set to 0. */
	ByteStringStruct accessField;

	/*! The key of the group.
	* The key is repeated in nodes of type Variable or Method to restrict the access dependent on the current
	* user.
	*
	* Handle values are only allowed from 1...0xFFFF. The value 0 is reserved. */
	OTUInt32 key;

	/*! The name of the pattern. The name can be used for a useful management of the patterns by the server implementation. */
	OTChar* pName;


	AccessPatternStruct();
	EnumStatusCode setAccessField(unsigned length, const unsigned char* pValue);
	EnumStatusCode getAccessField(unsigned* pLength, unsigned char** pValue);
	EnumStatusCode setName(const OTChar* pValue);

	EnumStatusCode set(const AccessPatternStruct&);
	EnumStatusCode get(AccessPatternStruct&) const;


	const AccessPatternStruct& operator=(const AccessPatternStruct& cp);
	bool operator==(const AccessPatternStruct& toCompare) const;
	bool operator!=(const AccessPatternStruct& toCompare) const;
	bool operator<(const AccessPatternStruct& toCompare) const;
	bool operator>(const AccessPatternStruct& toCompare) const;

	int compare(const AccessPatternStruct* pTarget) const;

	void clear(void);
	~AccessPatternStruct(void);

}AccessPatternStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ACCESSPATTERNSTRUCT_H
