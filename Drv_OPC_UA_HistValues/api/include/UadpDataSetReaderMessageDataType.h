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

#ifndef UADPDATASETREADERMESSAGEDATATYPE_H
#define UADPDATASETREADERMESSAGEDATATYPE_H

#include "IUadpDataSetReaderMessageDataType.h"
#include "Guid.h"
#include "IGuid.h"
#include "UadpDataSetReaderMessageDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of DataSetReaderMessageDataType.
	*
	* It is used to store UADP message mapping specific DataSetReader parameters. */
	class TBC_EXPORT UadpDataSetReaderMessageDataType
		: public IUadpDataSetReaderMessageDataType
	{
	public:
		/*! Default constructor */
		UadpDataSetReaderMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		UadpDataSetReaderMessageDataType(const IUadpDataSetReaderMessageDataType* cp);
		/*! @overload */
		UadpDataSetReaderMessageDataType(const IUadpDataSetReaderMessageDataType& cp);
		/*! @overload */
		UadpDataSetReaderMessageDataType(const UadpDataSetReaderMessageDataType& cp);

		/*! Destructor */
		virtual ~UadpDataSetReaderMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		UadpDataSetReaderMessageDataType& operator=(const IUadpDataSetReaderMessageDataType* cp);
		/*! @overload */
		UadpDataSetReaderMessageDataType& operator=(const IUadpDataSetReaderMessageDataType& cp);
		/*! @overload */
		UadpDataSetReaderMessageDataType& operator=(const UadpDataSetReaderMessageDataType& cp);

		/* see IUadpDataSetReaderMessageDataType::compare(IDataSetReaderMessageDataType*) */
		virtual int compare(const IDataSetReaderMessageDataType* other) const;
		/*! @overload */
		virtual int compare(const IDataSetReaderMessageDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetReaderMessageDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetReaderMessageDataType& other) const;

		/* see IDataSetReaderMessageDataType::set(IDataSetReaderMessageDataType*) */
		virtual EnumStatusCode set(const IDataSetReaderMessageDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetReaderMessageDataType& pSrc);

		/* see IUadpDataSetReaderMessageDataType::setGroupVersion */
		virtual void setGroupVersion(const OTUInt32& groupVersion);
		/* see IUadpDataSetReaderMessageDataType::getGroupVersion */
		virtual OTUInt32 getGroupVersion() const;

		/* see IUadpDataSetReaderMessageDataType::setNetworkMessageNumber */
		virtual void setNetworkMessageNumber(const OTUInt16& value);
		/* see IUadpDataSetReaderMessageDataType::getNetworkMessageNumber */
		virtual OTUInt16 getNetworkMessageNumber() const;

		/* see IUadpDataSetReaderMessageDataType::setDataSetOffset */
		virtual void setDataSetOffset(const OTUInt16& value);
		/* see IUadpDataSetReaderMessageDataType::getDataSetOffset */
		virtual OTUInt16 getDataSetOffset() const;

		/* see IUadpDataSetReaderMessageDataType::setDataSetClassId */
		virtual EnumStatusCode setDataSetClassId(const IGuid* pDataSetClassId);
		/*! @overload */
		virtual EnumStatusCode setDataSetClassId(const Guid& dataSetClassId);
		/* see IUadpDataSetReaderMessageDataType::getDataSetClassId */
		virtual const IGuid* getDataSetClassId() const;

		/* see IUadpDataSetReaderMessageDataType::setNetworkMessageContentMask */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& contentMask);
		/* see IUadpDataSetReaderMessageDataType::getNetworkMessageContentMask */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;

		/* see IUadpDataSetReaderMessageDataType::setDataSetMessageContentMask */
		virtual void setDataSetMessageContentMask(const EnumUadpDataSetMessageContentMask& contentMask);
		/* see IUadpDataSetReaderMessageDataType::getDataSetMessageContentMask */
		virtual EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;

		/* see IUadpDataSetReaderMessageDataType::setPublishingInterval */
		virtual void setPublishingInterval(const OTDouble& publishingInterval);
		/* see IUadpDataSetReaderMessageDataType::getPublishingInterval */
		virtual OTDouble getPublishingInterval() const;

		/* see IUadpDataSetReaderMessageDataType::setReceiveOffset */
		virtual void setReceiveOffset(const OTDouble& receiveOffset);
		/* see IUadpDataSetReaderMessageDataType::getReceiveOffset */
		virtual OTDouble getReceiveOffset() const;

		/* see IUadpDataSetReaderMessageDataType::setProcessingOffset */
		virtual void setProcessingOffset(const OTDouble& processingOfffset);
		/* see IUadpDataSetReaderMessageDataType::getProcessingOffset */
		virtual OTDouble getProcessingOffset() const;

		/*! For internal use only */
		virtual DataSetReaderMessageDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const DataSetReaderMessageDataTypeStruct* getInternHandle() const;

		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:
		Guid m_dataSetClassId;

		UadpDataSetReaderMessageDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
