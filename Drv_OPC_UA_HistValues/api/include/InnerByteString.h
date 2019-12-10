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

#ifndef INNERBYTESTRING_H
#define INNERBYTESTRING_H

#include "ByteStringStruct.h"
#include "IByteString.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerByteString
	class TBC_EXPORT InnerByteString
		: public IByteString
	{
	public:
		/*! Destructor */
		virtual ~InnerByteString();

		virtual unsigned getSize() const;
		virtual const unsigned char* getDataPointer() const;

		virtual tstring getStringFromUtf8() const;
		virtual EnumStatusCode setUtf8String(const tstring& string);

		virtual bool compare(const IByteString& other) const;
		virtual bool compare(const IByteString* other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IByteString& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IByteString& other) const;

		virtual tstring toString(void) const;

		virtual EnumStatusCode set(const IByteString*);
		virtual EnumStatusCode set(const IByteString&);

		// init from otb handle
		void initInner(ByteStringStruct* pHandle);

		/*! For internal use only */
		virtual void* getInternHandle() const;

	protected:
		// the handle to the related core object
		ByteStringStruct* m_pByteString_Data;
	};
}
#endif	// INNERBYTESTRING_H
