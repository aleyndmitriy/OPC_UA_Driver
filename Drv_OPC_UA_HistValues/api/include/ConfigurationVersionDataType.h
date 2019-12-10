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

#ifndef CONFIGURATIONVERSIONDATATYPE_H
#define CONFIGURATIONVERSIONDATATYPE_H

#include "IConfigurationVersionDataType.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The ConfigurationVersionDataType is used to indicate configuration changes
	* in the information published for a PublishedDataSet.
	*
	* Both members MajorVersion and MinorVersion represent the.time in seconds since the year 2000.
	* The epoch date is midnight UTC (00:00) on January 1, 2000.
	*
	* The MajorVersion reflects the time of the last major change of the DataSet content.
	* Removing fields from the DataSet content, reordering fields, adding fields in between other
	* fields or a DataType change in fields shall result in an update of the MajorVersion.
	* If at least one Property value of a DataSetMetaData field changes, the MajorVersion shall be updated.
	*
	* The MinorVersion reflects the time of the last change.
	* Only the MinorVersion shall be updated if fields are added at the end of the DataSet content.
	* If the MajorVersion version is updated, the MinorVersion is updated to the same value as MajorVersion. */
	class TBC_EXPORT ConfigurationVersionDataType
		: public IConfigurationVersionDataType
	{
	public:
		/*! Default constructor */
		ConfigurationVersionDataType();
		/*! Constructs a copy of the given instance @p cp */
		ConfigurationVersionDataType(const IConfigurationVersionDataType* cp);
		/*! @overload */
		ConfigurationVersionDataType(const IConfigurationVersionDataType& cp);
		/*! @overload */
		ConfigurationVersionDataType(const ConfigurationVersionDataType& cp);
		/*! @overload */
		ConfigurationVersionDataType(OTUInt32 majorVersion, OTUInt32 minorVersion);

		/*! Destructor */
		virtual ~ConfigurationVersionDataType();

		/*! Assigns the contents of @p cp to this instance */
		ConfigurationVersionDataType& operator=(const IConfigurationVersionDataType* cp);
		/*! @overload */
		ConfigurationVersionDataType& operator=(const IConfigurationVersionDataType& cp);
		/*! @overload */
		ConfigurationVersionDataType& operator=(const ConfigurationVersionDataType& cp);

		/* see IConfigurationVersionDataType::compare(IConfigurationVersionDataType*) */
		virtual int compare(const IConfigurationVersionDataType* other) const;
		/*! @overload */
		virtual int compare(const IConfigurationVersionDataType& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IConfigurationVersionDataType& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IConfigurationVersionDataType& other) const;

		/* see IConfigurationVersionDataType::set(IConfigurationVersionDataType*) */
		virtual EnumStatusCode set(const IConfigurationVersionDataType* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IConfigurationVersionDataType& pSrc);

		/*! Gets the MajorVersion member of the class */
		virtual OTUInt32 getMajorVersion() const;
		/*! Sets the MajorVersion member in the class */
		virtual void setMajorVersion(const OTUInt32& majorVersion);

		/*! Gets the MinorVersion member of the class */
		virtual OTUInt32 getMinorVersion() const;
		/*! Sets the MinorVersion member in the class */
		virtual void setMinorVersion(const OTUInt32& minorVersion);

		/*! For internal use only */
		virtual void* getInternHandle() const;
		/*! For internal use only */
		void initMembers();
		/*! Clears the contents of this object to enable its re-use. */
		void clear();

	private:

		ConfigurationVersionDataTypeStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
