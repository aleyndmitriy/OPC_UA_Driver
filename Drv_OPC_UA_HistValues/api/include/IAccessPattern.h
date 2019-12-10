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

#ifndef IACCESSPATTERN_H
#define IACCESSPATTERN_H

#include "AccessPatternStruct.h"

namespace SoftingOPCToolbox5
{
	/*! An AccessPattern is used to implement user authorization in an OPC UA server
	* and defines access rights for Variables and Methods for one or more user groups.
	*
	* The SDK uses a matrix to organize user access rights. The AccessPatterns represent the rows
	* and user groups represent the columns of this matrix. The whole matrix is represented as a vector
	* of AccessPatterns which contain an AccessField (ByteString) where each byte is a bit mask for one user group
	* of this pattern.
	*
	* A server may define user rights for accessing the "Value" attribute of Variables and user rights
	* for executing Methods. In the address space, the right of a certain user to access a Variable's value
	* or to execute a Method is made visible by the attributes "UserAccessLevel" resp. "UserExecutable".
	*
	* Each AccessPattern is identified by an arbitrary key and each Variable or Method in the server may use the
	* key to refer to an AccessPattern. The SDK defines a reserved default access pattern (key = 0) that
	* uses the AccessLevel (not UserAccessLevel) attribute of a Variable resp. the Executable
	* (not UserExecutable) attribute of a Method, regardless of the user group.
	*
	* @note	Please note that the SDK defines a default AccessPattern with key "0" that uses
	*		the value of the Variable's AccessLevel resp. the Method's Executable attribute.
	*		This special AccessPattern cannot be overridden. Please note that the ByteStrings for the user
	*		groups of all AccessPatterns shall have the same size.
	*
	* @see	Application::setAccessPattern() Application::getUserAccessLevel() Server::Endpoint::onAuthenticateUser()
	*		Server::Variable::setAccessPatternKey() Server::Method::setAccessPatternKey() */
	class TBC_EXPORT IAccessPattern
	{
	public:
		/*! Destructor */
		virtual ~IAccessPattern(){};

		/*! Returns the key of this AccessPattern. The key is used by Variables and Methods
		* to refer to this AccessPattern.
		*
		* @see setKey() */
		virtual OTUInt32 getKey() const = 0;
		/*! Sets the key of this AccessPattern. The key is used by Variables and Methods
		* to refer to this AccessPattern.
		*
		* Only keys in the range of 1...0xFFFF are allowed. The key value 0 is reserved for
		* the default access pattern which cannot be modified. */
		virtual void setKey(OTUInt32 value) = 0;

		/*! Returns the field of bytes that defines the rights for accessing the "Value" attribute of
		* Variables and the rights for executing Methods.
		*
		* @see setAccessField() */
		virtual ByteString getAccessField() const = 0;
		/*! Sets the field of bytes that defines the rights for accessing the "Value" attribute of
		* Variables and the rights for executing Methods.
		*
		* Each byte in that field defines in the lower 5 bits (0..4) the UserAccessLevel of Variables.
		* Bit 7 of a byte is used for marking a method as executable.
		* The allowed bits and semantics correspond to the enumeration values of EnumAcessLevel.
		* Bits 5 and 6 are currently unused and shall be set to 0.
		*
		* For example, the byte sequence "0x01, 0x03, 0x01" defines the following pattern:
		* @li	Users in the default group (anonymous authentication) are allowed to read the
		*		Variable's value (see EnumAccessLevel_CurrentRead)
		* @li	Users in group 1 are allowed to read and write the value of the Variable
		*		(see EnumAccessLevel_CurrentRead and EnumAccessLevel_CurrentWrite)
		* @li	Users in group 2 are only allowed to read the Variable's value (see EnumAccessLevel_CurrentRead) */
		virtual void setAccessField(const ByteString& value) = 0;

		/*! Returns the name of the pattern.
		*
		* @see setName() */
		virtual tstring getName() const = 0;
		/*! Sets the name of the pattern.
		*
		* Server applications are not forced to provide a name for AccessPatterns. However, it
		* may be useful for management purposes to assign names. */
		virtual void setName(const tstring& value) = 0;

		/*! Copies the content of @p source to this instance */
		virtual EnumStatusCode set(const IAccessPattern* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IAccessPattern& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAccessPattern* other) const = 0;
		/*! @overload */
		virtual int compare(const IAccessPattern& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAccessPattern& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAccessPattern& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IAccessPattern
} // end namespace
#endif	// IACCESSPATTERN_H
