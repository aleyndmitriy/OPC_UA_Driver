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

#ifndef QUALIFIEDNAME_H
#define QUALIFIEDNAME_H

#include "IQualifiedName.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The QualifiedName data type describes a name that is qualified by a namespace.
	* The namespace is identified by an index into the server's NamespaceArray. A QualifiedName
	* is, for example, used as BrowseName of a node.
	*
	* The NamespaceArray is a list of namespace URIs. Each URI identifies the naming authority responsible for
	* assigning the identifier element of the NodeId. A server's NamespaceArray always contains the URI
	* http://opcfoundation.org/UA/ at index 0 which is the OPC UA namespace that contains well-known NodeIds. */
	class TBC_EXPORT QualifiedName
		: public IQualifiedName
	{
	public:
		/*! Default constructor */
		QualifiedName();
		/*! Constructs a QualifiedName from a name that is defined within a certain namespace.
		*
		* @param name				The text portion of the QualifiedName
		* @param namespaceIndex		The index that identifies the namespace that defines the name */
		QualifiedName(const tstring& name, OTUInt16 namespaceIndex);
		/*! Constructs a copy of the given instance */
		QualifiedName(const IQualifiedName*);
		/*! @overload */
		QualifiedName(const IQualifiedName&);
		/*! @overload */
		QualifiedName(const QualifiedName&);

		/*! Destructor */
		virtual ~QualifiedName();

		/*! Assigns the contents of @p cp to this instance */
		QualifiedName& operator=(const IQualifiedName*);
		/*! @overload */
		QualifiedName& operator=(const IQualifiedName&);
		/*! @overload */
		QualifiedName& operator=(const QualifiedName&);

		/* see IQualifiedName::set */
		virtual EnumStatusCode set(const IQualifiedName* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IQualifiedName& pSrc);

		/* see IQualifiedName::compare */
		virtual int compare(const IQualifiedName*) const;
		/*! @overload */
		virtual int compare(const IQualifiedName&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQualifiedName& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQualifiedName& other) const;

		/* see IQualifiedName::setNameAndIndex */
		virtual void setNameAndIndex(const tstring& name, OTUInt16 namespaceIndex);

		/* see IQualifiedName::getNamespaceIndex */
		virtual OTUInt16 getNamespaceIndex() const;
		/* see IQualifiedName::setNamespaceIndex */
		virtual void setNamespaceIndex(OTUInt16 value);

		/* see IQualifiedName::getName */
		virtual tstring getName() const;
		/* see IQualifiedName::setName */
		virtual void setName(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		QualifiedNameStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// QUALIFIEDNAME_H
