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

#ifndef INNERCONFIGURATIONVERSIONDATATYPE_H
#define INNERCONFIGURATIONVERSIONDATATYPE_H

#include "IConfigurationVersionDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerConfigurationVersionDataType
		: public IConfigurationVersionDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerConfigurationVersionDataType();

		/*! Gets the MajorVersion member of the class */
		virtual OTUInt32 getMajorVersion() const;
		/*! Sets the MajorVersion member in the class */
		virtual void setMajorVersion(const OTUInt32& majorVersion);

		/*! Gets the MinorVersion member of the class */
		virtual OTUInt32 getMinorVersion() const;
		/*! Sets the MinorVersion member in the class */
		virtual void setMinorVersion(const OTUInt32& minorVersion);

		/*! For internal use only */
		void initInner(ConfigurationVersionDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const IConfigurationVersionDataType* pSrc);
		virtual EnumStatusCode set(const IConfigurationVersionDataType& pSrc);

		virtual int compare(const IConfigurationVersionDataType* other) const;
		virtual int compare(const IConfigurationVersionDataType& other) const;

		virtual bool operator==(const IConfigurationVersionDataType& other) const;
		virtual bool operator!=(const IConfigurationVersionDataType& other) const;

		virtual void* getInternHandle() const;

	private:

		ConfigurationVersionDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
