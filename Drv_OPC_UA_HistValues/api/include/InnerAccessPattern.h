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

#ifndef INNERACCESSPATTERN_H
#define INNERACCESSPATTERN_H

#include "IAccessPattern.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerAccessPattern
	class TBC_EXPORT InnerAccessPattern
		: public IAccessPattern
	{
	public:
		/*! Destructor */
		virtual ~InnerAccessPattern();

		/*! The field of access defining bytes. Each byte in that field defines in the lowest 5 bits (0..4) the AccessMode
		* used for variables
		* with the same meaning of the bits as defined by the enumeration EnumAccessLevel.
		*
		* For methods the bit 7 is used for marking the method as userExecutable (bit is high) or not (low).
		*
		* The bits 5 and 6 are currently unused and shall be set to 0. */
		virtual ByteString getAccessField() const;
		virtual void setAccessField(const ByteString& value);

		/*! The key of the group.
		* The key is repeated in nodes of type Variable or Method to restrict the access dependent on the current
		* user.
		*
		* Handle values are only allowed from 1...0xFFFF. The value 0 is reserved. */
		virtual OTUInt32 getKey() const;
		virtual void setKey(OTUInt32 value);

		/*! The name of the pattern. The name can be used for a useful management of the patterns by the server implementation. */
		virtual tstring getName() const;
		virtual void setName(const tstring& value);


		// init from otb handle
		void initInner(AccessPatternStruct* pHandle);

		// set from interface
		EnumStatusCode set(const IAccessPattern* pSrc);
		EnumStatusCode set(const IAccessPattern& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAccessPattern* other) const;
		/*! @overload */
		virtual int compare(const IAccessPattern& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAccessPattern& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAccessPattern& other) const;

		// protected:
		// the handle to the related core object
		AccessPatternStruct* m_pAccessPattern_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERACCESSPATTERN_H
