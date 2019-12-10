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

#ifndef BUILDINFO_H
#define BUILDINFO_H

#include "IBuildInfo.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "InnerDateTime.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The BuildInfo data type contains information that describes the build of the software. */
	class TBC_EXPORT BuildInfo
		: public IBuildInfo
	{
	public:
		/*! Default constructor */
		BuildInfo();
		/*! Constructs a copy of the given instance @p cp */
		BuildInfo(const IBuildInfo* cp);
		/*! @overload */
		BuildInfo(const IBuildInfo& cp);
		/*! @overload */
		BuildInfo(const BuildInfo& cp);

		/*! Destructor */
		virtual ~BuildInfo();

		/*! Assigns the contents of @p cp to this instance */
		BuildInfo& operator=(const IBuildInfo* cp);
		/*! @overload */
		BuildInfo& operator=(const IBuildInfo& cp);
		/*! @overload */
		BuildInfo& operator=(const BuildInfo& cp);

		/* see IBuildInfo::set */
		virtual EnumStatusCode set(const IBuildInfo* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IBuildInfo& pSrc);

		/* see IBuildInfo::compare */
		virtual int compare(const IBuildInfo* other) const;
		/*! @overload */
		virtual int compare(const IBuildInfo& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBuildInfo& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBuildInfo& other) const;

		/* see IBuildInfo::getProductUri */
		virtual tstring getProductUri() const;
		/* see IBuildInfo::setProductUri */
		virtual void setProductUri(const tstring& value);

		/* see IBuildInfo::getManufacturerName */
		virtual tstring getManufacturerName() const;
		/* see IBuildInfo::setManufacturerName */
		virtual void setManufacturerName(const tstring& value);

		/* see IBuildInfo::getProductName */
		virtual tstring getProductName() const;
		/* see IBuildInfo::setProductName */
		virtual void setProductName(const tstring& value);

		/* see IBuildInfo::getSoftwareVersion */
		virtual tstring getSoftwareVersion() const;
		/* see IBuildInfo::setSoftwareVersion */
		virtual void setSoftwareVersion(const tstring& value);

		/* see IBuildInfo::getBuildNumber */
		virtual tstring getBuildNumber() const;
		/* see IBuildInfo::setBuildNumber */
		virtual void setBuildNumber(const tstring& value);

		/* see IBuildInfo::getBuildDate */
		virtual const IDateTime* getBuildDate() const;
		/* see IBuildInfo::setBuildDate */
		virtual EnumStatusCode setBuildDate(const IDateTime* value);
		/*! overload */
		virtual EnumStatusCode setBuildDate(const DateTime& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerDateTime m_buildDate;

		BuildInfoStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// BUILDINFO_H
