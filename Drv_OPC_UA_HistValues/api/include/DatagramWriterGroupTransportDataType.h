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

#ifndef DATAGRAMWRITERGROUPTRANSPORTDATATYPE_H
#define DATAGRAMWRITERGROUPTRANSPORTDATATYPE_H

#include "IDatagramWriterGroupTransportDataType.h"
#include "DatagramWriterGroupTransportDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a subclass of WriterGroupTransportDataType.
	*
	* It is used to store the datagram specific transport mapping parameters for WriterGroups. */
	class TBC_EXPORT DatagramWriterGroupTransportDataType
		: public IDatagramWriterGroupTransportDataType
	{
	public:
		/*! Default constructor */
		DatagramWriterGroupTransportDataType();
		/*! Constructs a copy of the given instance @p cp */
		DatagramWriterGroupTransportDataType(const IDatagramWriterGroupTransportDataType* cp);
		/*! @overload */
		DatagramWriterGroupTransportDataType(const IDatagramWriterGroupTransportDataType& cp);
		/*! @overload */
		DatagramWriterGroupTransportDataType(const DatagramWriterGroupTransportDataType& cp);

		/*! Destructor */
		virtual ~DatagramWriterGroupTransportDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		DatagramWriterGroupTransportDataType& operator=(const IDatagramWriterGroupTransportDataType* cp);
		/*! @overload */
		DatagramWriterGroupTransportDataType& operator=(const IDatagramWriterGroupTransportDataType& cp);
		/*! @overload */
		DatagramWriterGroupTransportDataType& operator=(const DatagramWriterGroupTransportDataType& cp);

		/*! @see IDatagramWriterGroupTransportDataType::compare(IWriterGroupTransportDataType*) */
		virtual int compare(const IWriterGroupTransportDataType* other) const;
		/*! @overload */
		virtual int compare(const IWriterGroupTransportDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriterGroupTransportDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriterGroupTransportDataType& other) const;

		/*! @see IWriterGroupTransportDataType::set(IWriterGroupTransportDataType*) */
		virtual EnumStatusCode set(const IWriterGroupTransportDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupTransportDataType& pSrc);

		/*! @see IDatagramWriterGroupTransportDataType::setMessageRepeatCount() */
		virtual void setMessageRepeatCount(const OTUInt8& repeatCount);
		/*! @see IDatagramWriterGroupTransportDataType::getMessageRepeatCount() */
		virtual OTUInt8 getMessageRepeatCount() const;

		/*! @see IDatagramWriterGroupTransportDataType::setMessageRepeatDelay() */
		virtual void setMessageRepeatDelay(const OTDouble& repeatDelay);
		/*! @see IDatagramWriterGroupTransportDataType::getMessageRepeatDelay() */
		virtual OTDouble getMessageRepeatDelay() const;

		/*! For internal use only */
		virtual WriterGroupTransportDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const WriterGroupTransportDataTypeStruct* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:

		DatagramWriterGroupTransportDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
