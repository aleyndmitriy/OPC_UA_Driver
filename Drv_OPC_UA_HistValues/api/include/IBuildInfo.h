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

#ifndef IBUILDINFO_H
#define IBUILDINFO_H

#include "BuildInfoStruct.h"
#include "DateTime.h"
#include "IDateTime.h"

namespace SoftingOPCToolbox5
{
	/*! The BuildInfo data type contains information that describes the build of the software. */
	class TBC_EXPORT IBuildInfo
	{
	public:
		/*! Destructor */
		virtual ~IBuildInfo(){};

		/*! Returns the URI that identifies the software. */
		virtual tstring getProductUri() const = 0;
		/*! Sets the URI that identifies the software.
		*
		* @param value The product URI */
		virtual void setProductUri(const tstring& value) = 0;

		/*! Returns the name of the software manufacturer. */
		virtual tstring getManufacturerName() const = 0;
		/*! Sets the name of the software manufacturer.
		*
		* @param value The name of the software manufacturer */
		virtual void setManufacturerName(const tstring& value) = 0;

		/*! Returns the name of the software */
		virtual tstring getProductName() const = 0;
		/*! Sets the name of the software.
		*
		* @param value The name of the software */
		virtual void setProductName(const tstring& value) = 0;

		/*! Returns the software version */
		virtual tstring getSoftwareVersion() const = 0;
		/*! Sets the name of the software manufacturer.
		*
		* @param value The software manufacturer */
		virtual void setSoftwareVersion(const tstring& value) = 0;

		/*! Returns the build number */
		virtual tstring getBuildNumber() const = 0;
		/*! Sets the build number.
		*
		* @param value The build number */
		virtual void setBuildNumber(const tstring& value) = 0;

		/*! Returns the date and time of the build */
		virtual const IDateTime* getBuildDate() const = 0;
		/*! Sets the date and time of the build.
		*
		* @param value The date and time of the build */
		virtual EnumStatusCode setBuildDate(const IDateTime* value) = 0;
		/*! @overload */
		virtual EnumStatusCode setBuildDate(const DateTime& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IBuildInfo* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IBuildInfo& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBuildInfo* other) const = 0;
		/*! @overload */
		virtual int compare(const IBuildInfo& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBuildInfo& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBuildInfo& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IBuildInfo
} // end namespace

#endif	// IBUILDINFO_H
