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

#ifndef IBYTESTRING_H
#define IBYTESTRING_H

#include "Enums.h"

namespace SoftingOPCToolbox5
{
	/*! The ByteString data type contains a sequence of bytes. */
	class TBC_EXPORT IByteString
	{
	public:
		/*! Destructor */
		virtual ~IByteString(){}

		/*! Returns the length of the ByteString in bytes. */
		virtual unsigned getSize() const = 0;

		/*! Returns a pointer to the data on which the ByteString operates. */
		virtual const unsigned char* getDataPointer() const = 0;

		/*! Returns a string representation of the ByteString.
		* The caller has to ensure that the ByteString contains a UTF-8 encoded string
		* that is not null terminated. */
		virtual tstring getStringFromUtf8() const = 0;
		/*! Sets the given @p string as UTF-8 encoded string. Any previous content is cleared.
		* The encoded string is not null terminated.
		*
		* @param string		The string that is to be stored as UTF-8 encoded string */
		virtual EnumStatusCode setUtf8String(const tstring& string) = 0;

		/*! Returns a string representation of the ByteString for debugging purposes */
		virtual tstring toString() const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IByteString* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IByteString& cp) = 0;

		/*! Compares two ByteStrings for equality. Two ByteStrings are
		* equal, if they contain the same data(!).
		*
		* @param other	The ByteString which is compared to this ByteString */
		virtual bool compare(const IByteString& other) const = 0;
		/*! @overload */
		virtual bool compare(const IByteString* other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IByteString& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IByteString& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IByteString

	/*! The XmlElement data type is used to define XML elements. */
	typedef IByteString IXmlElement;
} // end namespace

#endif	// IBYTESTRING_H
