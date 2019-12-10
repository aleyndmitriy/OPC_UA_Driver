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

#ifndef UADPDATASETWRITERMESSAGEDATATYPE_H
#define UADPDATASETWRITERMESSAGEDATATYPE_H

#include "IUadpDataSetWriterMessageDataType.h"
#include "UadpDataSetWriterMessageDataTypeStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! This class is a concrete subclass of DataSetWriterMessageDataType.
	*
	* It is used to store UADP DataSetMessage mapping specific DataSetWriter parameters. */
	class TBC_EXPORT UadpDataSetWriterMessageDataType
		: public IUadpDataSetWriterMessageDataType
	{
	public:
		/*! Default constructor */
		UadpDataSetWriterMessageDataType();
		/*! Constructs a copy of the given instance @p cp */
		UadpDataSetWriterMessageDataType(const IUadpDataSetWriterMessageDataType* cp);
		/*! @overload */
		UadpDataSetWriterMessageDataType(const IUadpDataSetWriterMessageDataType& cp);
		/*! @overload */
		UadpDataSetWriterMessageDataType(const UadpDataSetWriterMessageDataType& cp);

		/*! Destructor */
		virtual ~UadpDataSetWriterMessageDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Assigns the contents of @p cp to this instance */
		UadpDataSetWriterMessageDataType& operator=(const IUadpDataSetWriterMessageDataType* cp);
		/*! @overload */
		UadpDataSetWriterMessageDataType& operator=(const IUadpDataSetWriterMessageDataType& cp);
		/*! @overload */
		UadpDataSetWriterMessageDataType& operator=(const UadpDataSetWriterMessageDataType& cp);

		/* see IUadpDataSetWriterMessageDataType::compare(IDataSetWriterMessageDataType*) */
		virtual int compare(const IDataSetWriterMessageDataType* other) const;
		/*! @overload */
		virtual int compare(const IDataSetWriterMessageDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IDataSetWriterMessageDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IDataSetWriterMessageDataType& other) const;

		/* see IDataSetWriterMessageDataType::set(IDataSetWriterMessageDataType*) */
		virtual EnumStatusCode set(const IDataSetWriterMessageDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IDataSetWriterMessageDataType& pSrc);

		/* see IUadpDataSetWriterMessageDataType::setDataSetMessageContentMask() */
		virtual void setDataSetMessageContentMask(const EnumUadpDataSetMessageContentMask& contentMask);
		/* see IUadpDataSetWriterMessageDataType::getDataSetMessageContentMask() */
		virtual EnumUadpDataSetMessageContentMask getDataSetMessageContentMask() const;

		/* see IUadpDataSetWriterMessageDataType::setConfiguredSize() */
		virtual void setConfiguredSize(const OTUInt16& configuredSize);
		/* see IUadpDataSetWriterMessageDataType::getConfiguredSize() */
		virtual OTUInt16 getConfiguredSize() const;

		/* see IUadpDataSetWriterMessageDataType::getNetworkMessageNumber() */
		virtual OTUInt16 getNetworkMessageNumber() const;

		/* see IUadpDataSetWriterMessageDataType::getDataSetOffset() */
		virtual OTUInt16 getDataSetOffset() const;

		/*! For internal use only */
		virtual DataSetWriterMessageDataTypeStruct* getInternHandle();
		/*! For internal use only */
		virtual const DataSetWriterMessageDataTypeStruct* getInternHandle() const;

		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:

		UadpDataSetWriterMessageDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
