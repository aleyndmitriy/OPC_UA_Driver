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

#ifndef STRUCTUREFIELD_H
#define STRUCTUREFIELD_H

#include "IStructureField.h"
#include "LocalizedText.h"
#include "ILocalizedText.h"
#include "InnerLocalizedText.h"
#include "NodeId.h"
#include "INodeId.h"
#include "InnerNodeId.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The StructureField data type contains the metadata for a field of a custom Structure DataType. */
	class TBC_EXPORT StructureField
		: public IStructureField
	{
	public:
		/*! Default constructor */
		StructureField();
		/*! Constructs a copy of the given instance @p cp */
		StructureField(const IStructureField* cp);
		/*! @overload */
		StructureField(const IStructureField& cp);
		/*! @overload */
		StructureField(const StructureField& cp);

		/*! Destructor */
		virtual ~StructureField();

		/*! Assigns the contents of @p cp to this instance */
		StructureField& operator=(const IStructureField* cp);
		/*! @overload */
		StructureField& operator=(const IStructureField& cp);
		/*! @overload */
		StructureField& operator=(const StructureField& cp);

		/* see IStructureField::compare(IStructureField*) */
		virtual int compare(const IStructureField* other) const;
		/*! @overload */
		virtual int compare(const IStructureField& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IStructureField& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IStructureField& other) const;

		/* see IStructureField::set(IStructureField*) */
		virtual EnumStatusCode set(const IStructureField* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IStructureField& pSrc);

		/* see IStructureField::setName() */
		virtual void setName(const tstring& name);
		/* see IStructureField::getName() */
		virtual tstring getName() const;

		/* see IStructureField::setDescription() */
		virtual EnumStatusCode setDescription(const ILocalizedText* description);
		/*! @overload */
		virtual EnumStatusCode setDescription(const LocalizedText& description);
		/* see IStructureField::getDescription() */
		virtual const ILocalizedText* getDescription() const;

		/* see IStructureField::setDataType() */
		virtual EnumStatusCode setDataType(const INodeId* dataType);
		/*! @overload */
		virtual EnumStatusCode setDataType(const NodeId& dataType);
		/* see IStructureField::getDataType() */
		virtual const INodeId* getDataType() const;

		/* see IStructureField::setValueRank() */
		virtual void setValueRank(const OTInt32& valueRank);
		/* see IStructureField::getValueRank() */
		virtual OTInt32 getValueRank() const;

		/* see IStructureField::setArrayDimensions() */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions);
		/* see IStructureField::getArrayDimensions() */
		virtual std::vector<OTUInt32> getArrayDimensions() const;

		/* see IStructureField::setMaxStringLength() */
		virtual void setMaxStringLength(const OTUInt32& maxStringLength);
		/* see IStructureField::getMaxStringLength() */
		virtual OTUInt32 getMaxStringLength() const;

		/* see IStructureField::setIsOptional() */
		virtual void setIsOptional(const OTBoolean& isOptional);
		/* see IStructureField::getIsOptional() */
		virtual OTBoolean getIsOptional() const;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		InnerLocalizedText m_description;
		InnerNodeId m_dataType;

		StructureFieldStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
