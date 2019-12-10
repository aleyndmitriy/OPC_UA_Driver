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

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include "Base.h"

namespace SoftingOPCToolbox5
{
	/*! This class holds a list of unique strings that can be accessed by a numerical index.
	*
	* @see DiagnosticInfo or Client::Session::getNamespaceTable() */
	class TBC_EXPORT StringTable
		: public Base
	{
	public:
		/*! Constructs a new StringTable instance */
		static ObjectPointer<StringTable> create();

		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		StringTable(TBHandle otbHandle);

		/*! Destructor */
		virtual ~StringTable();

	protected:
		/*! Default constructor */
		StringTable();

	public:
		/*! Appends a string to the string table. If the same string already
		* exists in the table, the index of that entry is returned. Otherwise,
		* a new entry is appended.
		*
		* @param entry			The string to append to the table
		* @param [out] index	The position of the appended string in the table */
		EnumStatusCode appendEntry(const tstring& entry, OTInt32& index);

		/*! Returns the string at the given @p index in the table.
		*
		* @param index			The index of the string to return
		* @param [out] entry	The string at the given index
		*
		* @note This method returns EnumStatusCode_BadNotFound if the
		* requested entry is not in the table. */
		EnumStatusCode getEntry(OTInt32 index, tstring& entry) const;

		/*! Returns the index of an entry.
		*
		* @param entry			The string to look up
		* @param [out] index	The index of the given @p entry
		*
		* @note This method returns EnumStatusCode_BadNotFound if the
		* requested entry is not in the table. */
		EnumStatusCode getIndex(const tstring& entry, OTInt32& index) const;
		/*! @overload */
		EnumStatusCode getIndex(const tstring& entry, OTUInt16& index) const;

		/*! Returns the Size of the string table */
		OTUInt32 getSize() const;

		/*! Returns the content string table as vector */
		std::vector<tstring> getContent() const;

	private:
		/*! StringTable cannot be copied */
		StringTable(const StringTable&);
		/*! StringTable cannot be copied */
		StringTable& operator=(const StringTable&);
	};
	typedef ObjectPointer<StringTable> StringTablePtr;
	typedef ObjectPointer<const StringTable> StringTableConstPtr;
} // end namespace

#endif	// STRINGTABLE_H
