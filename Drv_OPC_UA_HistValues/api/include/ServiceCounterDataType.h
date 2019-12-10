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

#ifndef SERVICECOUNTERDATATYPE_H
#define SERVICECOUNTERDATATYPE_H

#include "IServiceCounterDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ServiceCounterDataType contains diagnostic counters for OPC UA services. */
	class TBC_EXPORT ServiceCounterDataType
		: public IServiceCounterDataType
	{
	public:
		/*! Default constructor */
		ServiceCounterDataType();
		/*! Constructs a copy of the given instance */
		ServiceCounterDataType(const IServiceCounterDataType*);
		/*! @overload */
		ServiceCounterDataType(const IServiceCounterDataType&);
		/*! @overload */
		ServiceCounterDataType(const ServiceCounterDataType&);
		/*! @overload */
		ServiceCounterDataType(OTUInt32 totalCount, OTUInt32 errorCount);

		/*! Destructor */
		virtual ~ServiceCounterDataType();

		/*! Assigns the contents of @p cp to this instance */
		ServiceCounterDataType& operator=(const IServiceCounterDataType* cp);
		/*! @overload */
		ServiceCounterDataType& operator=(const IServiceCounterDataType& cp);
		/*! @overload */
		ServiceCounterDataType& operator=(const ServiceCounterDataType& cp);

		/* see IServiceCounterDataType::set */
		virtual EnumStatusCode set(const IServiceCounterDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IServiceCounterDataType& pSrc);

		/* see IServiceCounterDataType::compare */
		virtual int compare(const IServiceCounterDataType*) const;
		/*! @overload */
		virtual int compare(const IServiceCounterDataType&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IServiceCounterDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IServiceCounterDataType& other) const;

		/* see IServiceCounterDataType::getTotalCount */
		virtual OTUInt32 getTotalCount() const;
		/* see IServiceCounterDataType::setTotalCount */
		virtual void setTotalCount(const OTUInt32& value);

		/* see IServiceCounterDataType::getErrorCount */
		virtual OTUInt32 getErrorCount() const;
		/* see IServiceCounterDataType::setErrorCount */
		virtual void setErrorCount(const OTUInt32& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		ServiceCounterDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SERVICECOUNTERDATATYPE_H
