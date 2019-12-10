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

#ifndef IQUALIFIEDNAME_H
#define IQUALIFIEDNAME_H

#include "QualifiedNameStruct.h"

namespace SoftingOPCToolbox5
{
	/*! The QualifiedName data type describes a name that is qualified by a namespace.
	* The namespace is identified by an index into the server's NamespaceArray. A QualifiedName
	* is, for example, used as BrowseName of a node.
	*
	* The NamespaceArray is a list of namespace URIs. Each URI identifies the naming authority responsible for
	* assigning the identifier element of the NodeId. A server's NamespaceArray always contains the URI
	* http://opcfoundation.org/UA/ at index 0 which is the OPC UA namespace that contains well-known NodeIds. */
	class TBC_EXPORT IQualifiedName
	{
	public:
		/*! Destructor */
		virtual ~IQualifiedName(){};

		/*! Sets the QualifiedName to a name that is defined within a certain namespace.
		*
		* @param name				The text portion of the QualifiedName
		* @param namespaceIndex		The index that identifies the namespace that defines the name */
		virtual void setNameAndIndex(const tstring& name, OTUInt16 namespaceIndex) = 0;

		/*! Returns the text portion of the QualifiedName.
		*
		* @see getNamespaceIndex() */
		virtual tstring getName() const = 0;
		/*! Sets the text portion of the QualifiedName.
		*
		* @see setNamespaceIndex() */
		virtual void setName(const tstring& value) = 0;

		/*! Returns the index that identifies the namespace that defines the name.
		*
		* @see setNamespaceIndex() */
		virtual OTUInt16 getNamespaceIndex() const = 0;
		/*! Sets the index that identifies the namespace that defines the name.
		* The index is an index into the server's NamespaceArray (see class description of IQualifiedName). */
		virtual void setNamespaceIndex(OTUInt16 value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IQualifiedName* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IQualifiedName& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IQualifiedName* other) const = 0;
		/*! @overload */
		virtual int compare(const IQualifiedName& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQualifiedName& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQualifiedName& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IQualifiedName
} // end namespace
#endif	// IQUALIFIEDNAME_H
