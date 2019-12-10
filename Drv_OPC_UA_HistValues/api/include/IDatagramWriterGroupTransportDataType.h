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

#ifndef IDATAGRAMWRITERGROUPTRANSPORTDATATYPE_H
#define IDATAGRAMWRITERGROUPTRANSPORTDATATYPE_H

#include "IWriterGroupTransportDataType.h"

namespace SoftingOPCToolbox5
{
	/*! The DatagramWriterGroupTransportDataType is used to store the datagram specific transport
	* mapping parameters for WriterGroups. */
	class TBC_EXPORT IDatagramWriterGroupTransportDataType : public IWriterGroupTransportDataType
	{
	public:
		/*! Destructor */
		virtual ~IDatagramWriterGroupTransportDataType(){};

		/*! Sets the MessageRepeatCount member in the class
		*
		* @param repeatCount	The MessageRepeatCount defines how many times every NetworkMessage is repeated.
		*						The default value is 0 and disables the repeating.
		* @note The MessageRepeatCount is currently not supported. */
		virtual void setMessageRepeatCount(const OTUInt8& repeatCount) = 0;
		/*! Gets the MessageRepeatCount member of the class */
		virtual OTUInt8 getMessageRepeatCount() const = 0;

		/*! Sets the MessageRepeatDelay member in the class
		*
		* @param repeatDelay		The MessageRepeatDelay defines the time between NetworkMessage repeats in milliseconds.
		*							The parameter shall be ignored if the parameter MessageRepeatCount is set to 0. */
		virtual void setMessageRepeatDelay(const OTDouble& repeatDelay) = 0;
		/*! Gets the MessageRepeatDelay member of the class */
		virtual OTDouble getMessageRepeatDelay() const = 0;

		/*! Conversion from IWriterGroupTransportDataType */
		static const IDatagramWriterGroupTransportDataType* castFrom(const IWriterGroupTransportDataType* pSrc);
		/*! Conversion from IWriterGroupTransportDataType */
		static IDatagramWriterGroupTransportDataType* castFrom(IWriterGroupTransportDataType* pSrc);
	}; // end IDatagramWriterGroupTransportDataType
} // end namespace

#endif
