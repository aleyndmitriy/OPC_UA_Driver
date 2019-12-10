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

#ifndef INNERUADPDATASETREADERMESSAGEDATATYPE_H
#define INNERUADPDATASETREADERMESSAGEDATATYPE_H

#include "IUadpDataSetReaderMessageDataType.h"
#include "Guid.h"
#include "IGuid.h"
#include "Guid.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerUadpDataSetReaderMessageDataType
		: public IUadpDataSetReaderMessageDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerUadpDataSetReaderMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the GroupVersion member of the class */
		virtual OTUInt32 getGroupVersion() const;
		/*! Sets the GroupVersion member in the class */
		virtual void setGroupVersion(const OTUInt32& value);

		/* see IUadpDataSetReaderMessageDataType::setNetworkMessageNumber */
		virtual void setNetworkMessageNumber(const OTUInt16& value);
		/*! Gets the NetworkMessageNumber member of the class */
		virtual OTUInt16 getNetworkMessageNumber() const;

		/* see IUadpDataSetReaderMessageDataType::setDataSetOffset */
		virtual void setDataSetOffset(const OTUInt16& value);
		/*! Gets the DataSetOffset member of the class */
		virtual OTUInt16 getDataSetOffset() const;

		/*! Gets the DataSetClassId member of the class */
		virtual const IGuid* getDataSetClassId() const;
		/*! Sets the DataSetClassId member in the class */
		virtual EnumStatusCode setDataSetClassId(const IGuid* pDataSetClassId);
		/*! @overload */
		virtual EnumStatusCode setDataSetClassId(const Guid& dataSetClassId);

		/*! Gets the NetworkMessageContentMask member of the class */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;
		/*! Sets the NetworkMessageContentMask member in the class */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& value);

		/*! Gets the DataSetMessageContentMask member of the class */
		virtual EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;
		/*! Sets the DataSetMessageContentMask member in the class */
		virtual void setDataSetMessageContentMask(const EnumUadpDataSetMessageContentMask& value);

		/*! Gets the PublishingInterval member of the class */
		virtual OTDouble getPublishingInterval() const;
		/*! Sets the PublishingInterval member in the class */
		virtual void setPublishingInterval(const OTDouble& value);

		/*! Gets the ReceiveOffset member of the class */
		virtual OTDouble getReceiveOffset() const;
		/*! Sets the ReceiveOffset member in the class */
		virtual void setReceiveOffset(const OTDouble& value);

		/*! Gets the ProcessingOffset member of the class */
		virtual OTDouble getProcessingOffset() const;
		/*! Sets the ProcessingOffset member in the class */
		virtual void setProcessingOffset(const OTDouble& value);

		/*! For internal use only */
		void initInner(UadpDataSetReaderMessageDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IDataSetReaderMessageDataType* pSrc);
		virtual EnumStatusCode set(const IDataSetReaderMessageDataType& pSrc);

		virtual int compare(const IDataSetReaderMessageDataType* other) const;
		virtual int compare(const IDataSetReaderMessageDataType& other) const;

		virtual bool operator==(const IDataSetReaderMessageDataType& other) const;
		virtual bool operator!=(const IDataSetReaderMessageDataType& other) const;

		virtual DataSetReaderMessageDataTypeStruct* getInternHandle();
		virtual const DataSetReaderMessageDataTypeStruct* getInternHandle() const;

	private:
		Guid m_dataSetClassId;

		UadpDataSetReaderMessageDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
