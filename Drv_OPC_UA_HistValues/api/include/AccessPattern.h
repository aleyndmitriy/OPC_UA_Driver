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

#ifndef ACCESSPATTERN_H
#define ACCESSPATTERN_H

#include "IAccessPattern.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

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
	class TBC_EXPORT AccessPattern
		: public IAccessPattern
	{
	public:
		/*! Default constructor */
		AccessPattern();
		/*! Constructs a copy of the given instance */
		AccessPattern(const IAccessPattern*);
		/*! @overload */
		AccessPattern(const IAccessPattern&);
		/*! @overload */
		AccessPattern(const AccessPattern&);

		/*! Destructor */
		virtual ~AccessPattern();

		/*! Assigns the contents of @p cp to this instance */
		AccessPattern& operator=(const IAccessPattern* cp);
		/*! @overload */
		AccessPattern& operator=(const IAccessPattern& cp);
		/*! @overload */
		AccessPattern& operator=(const AccessPattern& cp);

		/* see IAccessPattern::set */
		virtual EnumStatusCode set(const IAccessPattern* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IAccessPattern& pSrc);

		/* see IAccessPattern::compare */
		virtual int compare(const IAccessPattern*) const;
		/*! @overload */
		virtual int compare(const IAccessPattern&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAccessPattern& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAccessPattern& other) const;

		/* see IAccessPattern::getAccessField */
		virtual ByteString getAccessField() const;
		/* see IAccessPattern::setAccessField */
		virtual void setAccessField(const ByteString& value);

		/* see IAccessPattern::getKey */
		virtual OTUInt32 getKey() const;
		/* see IAccessPattern::setKey */
		virtual void setKey(OTUInt32 value);

		/* see IAccessPattern::getName */
		virtual tstring getName() const;
		/* see IAccessPattern::setName */
		virtual void setName(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_accessField;
		AccessPatternStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ACCESSPATTERN_H
