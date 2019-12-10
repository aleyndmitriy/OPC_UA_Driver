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

#ifndef UADPWRITERGROUPMESSAGEDATATYPE_H
#define UADPWRITERGROUPMESSAGEDATATYPE_H

#include "IUadpWriterGroupMessageDataType.h"
#include "UadpWriterGroupMessageDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of WriterGroupMessageDataType.
	*
	* It is used to store the UADP NetworkMessage mapping specific WriterGroup parameters. */
	class TBC_EXPORT UadpWriterGroupMessageDataType
		: public IUadpWriterGroupMessageDataType
	{
	public:
		/*! Default constructor */
		UadpWriterGroupMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		UadpWriterGroupMessageDataType(const IUadpWriterGroupMessageDataType* cp);
		/*! @overload */
		UadpWriterGroupMessageDataType(const IUadpWriterGroupMessageDataType& cp);
		/*! @overload */
		UadpWriterGroupMessageDataType(const UadpWriterGroupMessageDataType& cp);

		/*! Destructor */
		virtual ~UadpWriterGroupMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		UadpWriterGroupMessageDataType& operator=(const IUadpWriterGroupMessageDataType* cp);
		/*! @overload */
		UadpWriterGroupMessageDataType& operator=(const IUadpWriterGroupMessageDataType& cp);
		/*! @overload */
		UadpWriterGroupMessageDataType& operator=(const UadpWriterGroupMessageDataType& cp);

		/* see IUadpWriterGroupMessageDataType::compare(IWriterGroupMessageDataType*) */
		virtual int compare(const IWriterGroupMessageDataType* other) const;
		/*! @overload */
		virtual int compare(const IWriterGroupMessageDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IWriterGroupMessageDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IWriterGroupMessageDataType& other) const;

		/* see IWriterGroupMessageDataType::set(IWriterGroupMessageDataType*) */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IWriterGroupMessageDataType& pSrc);

		/* see IUadpWriterGroupMessageDataType::setGroupVersion() */
		virtual void setGroupVersion(const OTUInt32& versionTime);
		/* see IUadpWriterGroupMessageDataType::getGroupVersion() */
		virtual OTUInt32 getGroupVersion() const;

		/* see IUadpWriterGroupMessageDataType::setDataSetOrdering() */
		virtual void setDataSetOrdering(const EnumDataSetOrderingType& ordering);
		/* see IUadpWriterGroupMessageDataType::getDataSetOrdering() */
		virtual EnumDataSetOrderingType getDataSetOrdering() const;

		/* see IUadpWriterGroupMessageDataType::setNetworkMessageContentMask() */
		virtual void setNetworkMessageContentMask(const EnumUadpNetworkMessageContentMask& contentMask);
		/* see IUadpWriterGroupMessageDataType::getNetworkMessageContentMask() */
		virtual EnumUadpNetworkMessageContentMask getNetworkMessageContentMask() const;

		/* see IUadpWriterGroupMessageDataType::setSamplingOffset() */
		virtual void setSamplingOffset(const OTDouble& samplingOffset);
		/* see IUadpWriterGroupMessageDataType::getSamplingOffset() */
		virtual OTDouble getSamplingOffset() const;

		/* see IUadpWriterGroupMessageDataType::setPublishingOffset() */
		virtual EnumStatusCode setPublishingOffset(const std::vector<OTDouble>& publishingOffsets);
		/* see IUadpWriterGroupMessageDataType::getPublishingOffset() */
		virtual std::vector<OTDouble> getPublishingOffset() const;

		/*! For internal use only */
		virtual WriterGroupMessageDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const WriterGroupMessageDataTypeStruct* getInternHandle() const;

		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:

		UadpWriterGroupMessageDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
