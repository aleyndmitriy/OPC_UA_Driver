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

#ifndef INNERQUALIFIEDNAME_H
#define INNERQUALIFIEDNAME_H

#include "IQualifiedName.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerQualifiedName
	class TBC_EXPORT InnerQualifiedName
		: public IQualifiedName
	{
	public:
		/*! Destructor */
		virtual ~InnerQualifiedName();

		/* see IQualifiedName::setNameAndIndex */
		virtual void setNameAndIndex(const tstring& name, OTUInt16 namespaceIndex);

		/*! String containing the name without namespaceindex. */
		virtual tstring getName() const;
		virtual void setName(const tstring& value);

		/*! The namespaceindex to use building a BrowsePath. */
		virtual OTUInt16 getNamespaceIndex() const;
		virtual void setNamespaceIndex(OTUInt16 value);


		// init from otb handle
		void initInner(QualifiedNameStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IQualifiedName* other) const;
		/*! @overload */
		virtual int compare(const IQualifiedName& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IQualifiedName& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IQualifiedName& other) const;

		// set from interface
		EnumStatusCode set(const IQualifiedName* pSrc);
		EnumStatusCode set(const IQualifiedName& pSrc);

		// protected:
		// the handle to the related core object
		QualifiedNameStruct* m_pQualifiedName_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERQUALIFIEDNAME_H
