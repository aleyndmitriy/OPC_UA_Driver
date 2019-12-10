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

#ifndef IWRITERGROUPMESSAGEDATATYPE_H
#define IWRITERGROUPMESSAGEDATATYPE_H

struct WriterGroupMessageDataTypeStruct;

namespace SoftingOPCToolbox5
{
	/*! Interface to the abstract data type WriterGroupMessageDataType, which is used for message mapping specific WriterGroup parameters.
	*
	* Concrete subtypes are IUadpDataSetWriterMessageDataType and IJsonDataSetWriterMessageDataType (not yet supported) */
	class TBC_EXPORT IWriterGroupMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~IWriterGroupMessageDataType(){};

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns -1, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns 1, if "this > other" */
		virtual int compare(const IWriterGroupMessageDataType* other) const = 0;
		/*! @overload */
		virtual int compare(const IWriterGroupMessageDataType& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriterGroupMessageDataType& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriterGroupMessageDataType& other) const = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType& cp) = 0;

		/*! For internal use only */
		virtual WriterGroupMessageDataTypeStruct* getInternHandle() = 0;
		/*! For internal use only */
		virtual const WriterGroupMessageDataTypeStruct* getInternHandle() const = 0;
	}; // end IWriterGroupMessageDataType
} // end namespace

#endif
