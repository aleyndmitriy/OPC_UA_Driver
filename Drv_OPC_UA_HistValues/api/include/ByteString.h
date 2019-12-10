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

#ifndef BYTESTRING_H
#define BYTESTRING_H

#include "IByteString.h"
#include "ByteStringStruct.h"
#include "Enums.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ByteString data type contains a sequence of bytes. */
	class TBC_EXPORT ByteString
		: public IByteString
	{
	public:
		/*! Constructs a byte string with zero bytes length and
		* a data pointer pointing to NULL. */
		ByteString();
		/*! Constructs a byte string containing the content of the given @p data
		* pointer. The provided @p data is copied to an internal buffer.
		*
		* @param size The length in bytes to copy
		* @param data The memory contents to copy */
		ByteString(OTUInt32 size, const OTUInt8* data);
		/*! Constructs a byte string containing an UTF-8 encoded string.
		* The UTF8-encoded string in the byte string the is not(!) null-terminated.
		*
		* @param string The string that is stored as UTF-8 encoded string
		*
		* @see getStringFromUtf8() setUtf8String() */
		ByteString(const tstring& string);
		/*! Constructs a copy of the given instance @p cp */
		ByteString(const IByteString* cp);
		/*! @overload */
		ByteString(const ByteString& cp);

		/*! Destructor */
		virtual ~ByteString();

		/*! Assigns the contents of @p cp to this instance */
		const ByteString& operator=(const ByteString& cp);

		/* see IByteString::set */
		virtual EnumStatusCode set(const IByteString*);
		/*! @overload */
		virtual EnumStatusCode set(const IByteString&);

		/* see IByteString::compare */
		virtual bool compare(const IByteString& other) const;
		/*! @overload */
		virtual bool compare(const IByteString* other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IByteString& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IByteString& other) const;

		/*! Clears any existing content of this byte string and
		* copies the given @p data to an internal buffer.
		*
		* @param size	The length in bytes to copy
		* @param data	The memory contents to copy */
		bool init(OTUInt32 size, const OTUInt8* data);

		/* see IByteString::getSize */
		virtual OTUInt32 getSize() const;

		/* see IByteString::getDataPointer */
		virtual const OTUInt8* getDataPointer() const;

		/* see IByteString::getStringFromUtf8 */
		virtual tstring getStringFromUtf8() const;
		/* see IByteString::setUtf8String */
		virtual EnumStatusCode setUtf8String(const tstring& string);

		/* see IByteString::toString */
		virtual tstring toString() const;

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		ByteStringStruct m_content;
	};

	/*! The XmlElement data type is used to define XML elements. */
	typedef ByteString XmlElement;
}

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BYTESTRING_H
