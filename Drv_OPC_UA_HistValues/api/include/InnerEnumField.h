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

#ifndef INNERENUMFIELD_H
#define INNERENUMFIELD_H

#include "IEnumField.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerEnumField
		: public IEnumField
	{
	public:
		/*! Destructor */
		virtual ~InnerEnumField();

		/*! Gets the Name member of the class */
		virtual tstring getName() const;
		/*! Sets the Name member in the class */
		virtual void setName(const tstring& value);

		/*! Gets the Value member of the class */
		virtual OTInt64 getValue() const;
		/*! Sets the Value member in the class */
		virtual void setValue(const OTInt64& value);

		/*! Gets the DisplayName member of the class */
		virtual const ILocalizedText* getDisplayName() const;
		/*! Sets the DisplayName member in the class */
		virtual EnumStatusCode setDisplayName(const ILocalizedText* value);
		/*! @overload */
		virtual EnumStatusCode setDisplayName(const LocalizedText& value);

		/*! Gets the Description member of the class */
		virtual const ILocalizedText* getDescription() const;
		/*! Sets the Description member in the class */
		virtual EnumStatusCode setDescription(const ILocalizedText* value);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& value);

		/*! For internal use only */
		void initInner(EnumFieldStruct* pHandle);

		virtual EnumStatusCode set(const IEnumField* pSrc);
		virtual EnumStatusCode set(const IEnumField& pSrc);

		virtual int compare(const IEnumField* other) const;
		virtual int compare(const IEnumField& other) const;

		virtual bool operator==(const IEnumField& other) const;
		virtual bool operator!=(const IEnumField& other) const;

		virtual void* getInternHandle() const;

	private:
		InnerLocalizedText m_displayName;
		InnerLocalizedText m_description;

		EnumFieldStruct* m_pContent;
	};
} // end namespace

#endif
