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

#ifndef INNERUADPWRITERGROUPMESSAGEDATATYPE_H
#define INNERUADPWRITERGROUPMESSAGEDATATYPE_H

#include "IUadpWriterGroupMessageDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerUadpWriterGroupMessageDataType
		: public IUadpWriterGroupMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerUadpWriterGroupMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the GroupVersion member of the class */
		virtual OTUInt32 getGroupVersion() const;
		/*! Sets the GroupVersion member in the class */
		virtual void setGroupVersion(const OTUInt32& value);

		/*! Gets the DataSetOrdering member of the class */
		virtual EnumDataSetOrderingType getDataSetOrdering() const;
		/*! Sets the DataSetOrdering member in the class */
		virtual void setDataSetOrdering(const EnumDataSetOrderingType& value);

		/*! Gets the NetworkMessageContentMask member of the class */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;
		/*! Sets the NetworkMessageContentMask member in the class */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& value);

		/*! Gets the SamplingOffset member of the class */
		virtual OTDouble getSamplingOffset() const;
		/*! Sets the SamplingOffset member in the class */
		virtual void setSamplingOffset(const OTDouble& value);

		/*! Gets the PublishingOffset member of the class */
		virtual std::vector<OTDouble> getPublishingOffset() const;
		/*! Sets the PublishingOffset member in the class */
		virtual EnumStatusCode setPublishingOffset(const std::vector<OTDouble>& values);

		/*! For internal use only */
		void initInner(UadpWriterGroupMessageDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IWriterGroupMessageDataType* pSrc);
		virtual EnumStatusCode set(const IWriterGroupMessageDataType& pSrc);

		virtual int compare(const IWriterGroupMessageDataType* other) const;
		virtual int compare(const IWriterGroupMessageDataType& other) const;

		virtual bool operator==(const IWriterGroupMessageDataType& other) const;
		virtual bool operator!=(const IWriterGroupMessageDataType& other) const;

		virtual WriterGroupMessageDataTypeStruct* getInternHandle();
		virtual const WriterGroupMessageDataTypeStruct* getInternHandle() const;

	private:

		UadpWriterGroupMessageDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
