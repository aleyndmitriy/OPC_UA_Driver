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

#ifndef ELEMENTOPERAND_H
#define ELEMENTOPERAND_H
#if TB5_FILTER

#include "IElementOperand.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ElementOperand data type is used in the context of event or node filters (in queries)
	* to link sub-elements within a ContentFilter.
	*
	* The link is in the form of an integer that is used to index into the array of elements
	* contained in the ContentFilter. An index is considered valid if its value is greater than
	* the element index it is part of and it does not reference a non-existent element. Clients
	* shall construct filters in this way to avoid circular and invalid References. */
	class TBC_EXPORT ElementOperand
		: public IElementOperand
	{
	public:
		/*! Default constructor */
		ElementOperand();
		/*! Constructs a copy of the given instance */
		ElementOperand(const IElementOperand*);
		/*! @overload */
		ElementOperand(const IElementOperand&);
		/*! @overload */
		ElementOperand(const ElementOperand&);

		/*! Destructor */
		virtual ~ElementOperand();

		/*! Assigns the contents of @p cp to this instance */
		ElementOperand& operator=(const IElementOperand*);
		/*! @overload */
		ElementOperand& operator=(const IElementOperand&);
		/*! @overload */
		ElementOperand& operator=(const ElementOperand&);

		/* see IElementOperand::set */
		virtual EnumStatusCode set(const IElementOperand* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IElementOperand& pSrc);

		/* see IElementOperand::compare */
		virtual int compare(const IElementOperand*) const;
		/*! @overload */
		virtual int compare(const IElementOperand&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IElementOperand& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IElementOperand& other) const;

		/* see IElementOperand::getIndex */
		virtual OTUInt32 getIndex() const;
		/* see IElementOperand::setIndex */
		virtual void setIndex(OTUInt32 value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		ElementOperandStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// ELEMENTOPERAND_H
