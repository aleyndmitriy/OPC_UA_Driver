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

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "IArgument.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The Argument data type describes an input or output parameter of an OPC UA Method. */
	class TBC_EXPORT Argument
		: public IArgument
	{
	public:
		/*! Default constructor */
		Argument();
		/*! Constructs a copy of the given instance */
		Argument(const IArgument*);
		/*! @overload */
		Argument(const IArgument&);
		/*! @overload */
		Argument(const Argument&);

		/*! Destructor */
		virtual ~Argument();

		/*! Assigns the contents of @p cp to this instance */
		Argument& operator=(const IArgument*);
		/*! @overload */
		Argument& operator=(const IArgument&);
		/*! @overload */
		Argument& operator=(const Argument&);

		/* see IArgument::set */
		virtual EnumStatusCode set(const IArgument* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IArgument& pSrc);

		/* see IArgument::compare */
		virtual int compare(const IArgument*) const;
		/*! @overload */
		virtual int compare(const IArgument&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IArgument& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IArgument& other) const;

		/* see IArgument::getDataType */
		virtual const INodeId* getDataType() const;
		/*! @overload */
		virtual INodeId* getDataType();
		/* see IArgument::setDataType */
		virtual void setDataType(const INodeId* value);
		/*! @overload */
		virtual void setDataType(const NodeId& value);

		/* see IArgument::getName */
		virtual tstring getName() const;
		/* see IArgument::setName */
		virtual void setName(const tstring& name);

		/* see IArgument::getValueRank */
		virtual OTInt32 getValueRank() const;
		/* see IArgument::setValueRank */
		virtual void setValueRank(OTInt32 valueRank);

		/* see IArgument::getArrayDimensions */
		virtual std::vector<OTUInt32> getArrayDimensions() const;
		/* see IArgument::setArrayDimensions */
		virtual EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>&);

		/* see IArgument::getDescription */
		virtual const ILocalizedText* getDescription() const;
		/*! @overload */
		virtual ILocalizedText* getDescription();
		/* see IArgument::setDescription */
		virtual void setDescription(const ILocalizedText* value);
		/*! @overload */
		virtual void setDescription(const LocalizedText& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_DataType;
		InnerLocalizedText m_Description;

		ArgumentStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// ARGUMENT_H
