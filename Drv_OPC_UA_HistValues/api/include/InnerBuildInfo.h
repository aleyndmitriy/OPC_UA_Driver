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

#ifndef INNERBUILDINFO_H
#define INNERBUILDINFO_H

#include "IBuildInfo.h"
#include "DateTime.h"
#include "IDateTime.h"
#include "InnerDateTime.h"

namespace SoftingOPCToolbox5
{
	/*! Information that describes the build of the software. */
	class TBC_EXPORT InnerBuildInfo
		: public IBuildInfo
	{
	public:
		/*! Destructor */
		virtual ~InnerBuildInfo();

		virtual tstring getProductUri() const;
		virtual void setProductUri(const tstring& value);

		virtual tstring getManufacturerName() const;
		virtual void setManufacturerName(const tstring& value);

		virtual tstring getProductName() const;
		virtual void setProductName(const tstring& value);

		virtual tstring getSoftwareVersion() const;
		virtual void setSoftwareVersion(const tstring& value);

		virtual tstring getBuildNumber() const;
		virtual void setBuildNumber(const tstring& value);

		virtual const IDateTime* getBuildDate() const;
		virtual EnumStatusCode setBuildDate(const IDateTime* value);
		virtual EnumStatusCode setBuildDate(const DateTime& value);

		/*! For internal use only */
		void initInner(BuildInfoStruct* pHandle);

		/*! @see IBuildInfo::set(const IBuildInfo*) */
		EnumStatusCode set(const IBuildInfo* pSrc);
		/*! @see IBuildInfo::set(const IBuildInfo&) */
		EnumStatusCode set(const IBuildInfo& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBuildInfo* other) const;
		/*! @overload */
		virtual int compare(const IBuildInfo& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBuildInfo& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBuildInfo& other) const;

		/*! @see IBuildInfo::getInternHandle() */
		virtual void* getInternHandle() const;

	private:
		InnerDateTime m_buildDate;

		BuildInfoStruct* m_pContent;
	};
} // end namespace

#endif	// INNERBUILDINFO_H
