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

#ifndef ENUMDEFINITION_H
#define ENUMDEFINITION_H

#include "IEnumDefinition.h"
#include "EnumField.h"
#include "IEnumField.h"
#include "InnerEnumField.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EnumDefinition data type contains the metadata for a custom Enumeration or OptionSet DataType. */
	class TBC_EXPORT EnumDefinition
		: public IEnumDefinition
	{
	public:
		/*! Default constructor */
		EnumDefinition();
		/*! Constructs a copy of the given instance @p cp */
		EnumDefinition(const IEnumDefinition* cp);
		/*! @overload */
		EnumDefinition(const IEnumDefinition& cp);
		/*! @overload */
		EnumDefinition(const EnumDefinition& cp);

		/*! Destructor */
		virtual ~EnumDefinition();

		/*! Assigns the contents of @p cp to this instance */
		EnumDefinition& operator=(const IEnumDefinition* cp);
		/*! @overload */
		EnumDefinition& operator=(const IEnumDefinition& cp);
		/*! @overload */
		EnumDefinition& operator=(const EnumDefinition& cp);

		/* see IEnumDefinition::compare(IEnumDefinition*) */
		virtual int compare(const IEnumDefinition* other) const;
		/*! @overload */
		virtual int compare(const IEnumDefinition& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEnumDefinition& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEnumDefinition& other) const;

		/* see IEnumDefinition::set(IEnumDefinition*) */
		virtual EnumStatusCode set(const IEnumDefinition* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEnumDefinition& pSrc);

		/*! Gets the Fields member of the class */
		virtual std::vector<EnumField> getFields() const;
		/*! Adds a Field to the Fields member of the class */
		virtual EnumStatusCode addField(const IEnumField& field);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerEnumField> m_pFields)

		EnumDefinitionStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
