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

#ifndef IEUINFORMATION_H
#define IEUINFORMATION_H

#include "EUInformationStruct.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

namespace SoftingOPCToolbox5
{
	/*! The EUInformation data type contains information about the engineering units of an analog value.
	*
	* To facilitate interoperability, OPC UA specifies how to apply the widely accepted
	* "Codes for Units of Measurement (Recommendation No. 20)" published by the "United Nations
	* Centre for Trade Facilitation and Electronic Business". It uses and is based on the International
	* System of Units (SI Units) but in addition provides a fixed code that can be used for automated evaluation.
	* This recommendation has been accepted by many industries on a global basis.
	*
	* @see Server::AnalogItem */
	class TBC_EXPORT IEUInformation
	{
	public:
		/*! Destructor */
		virtual ~IEUInformation(){};

		/*! Returns the NamespaceUri that identifies the organization (company, standards organization)
		* that defines the EUInformation. */
		virtual tstring getNamespaceUri() const = 0;
		/*! Sets the NamespaceUri that identifies the organization (company, standards organization)
		* that defines the EUInformation.
		*
		* It is strongly recommended to use Recommendation No. 20 for specifying engineering units (see class description).
		* In this case, the NamespaceUri "http://www.opcfoundation.org/UA/units/un/cefact" shall be used. */
		virtual void setNamespaceUri(const tstring& value) = 0;

		/*! Returns the identifier of this EngineeringUnit for programmatic evaluation.
		*
		* Please use getUnitIdCode() to retrieve the unit identifier string as specified by Recommendation No. 20
		* if the UnitId is defined within the Recommendation No. 20 namespace (see getNamespaceUri()). */
		virtual OTInt32 getUnitId() const = 0;
		/*! Sets the identifier of this EngineeringUnit for programmatic evaluation.
		*
		* Please consider using setUnitIdCode() if you intend to set a UnitId that is defined by Recommendation No. 20. */
		virtual void setUnitId(OTInt32 value) = 0;
		/*! Returns a unit identifier conforming to Recommendation No. 20 (see class description).
		*
		* This method implements a decoding algorithm specified by the OPC UA specification which transforms
		* a numeric unit identifier to a string identifier specified by Recommendation No. 20.
		* Please use this method to retrieve the UnitId if it conforms to Recommendation No.20. */
		virtual tstring getUnitIdCode() const = 0;
		/*! Sets a unit identifier conforming to Recommendation No. 20 (see class description).
		*
		* This method implements an encoding algorithm specified by the OPC UA specification which transforms
		* a string identifier specified by Recommendation No. 20 to a numeric unit identifier.
		* Please use this method to set the UnitId if it conforms to Recommendation No.20. */
		virtual void setUnitIdCode(tstring code) = 0;

		/*! Returns the display name of the engineering unit.
		*
		* @see setDisplayName() */
		virtual const ILocalizedText* getDisplayName() const = 0;
		/*! @overload */
		virtual ILocalizedText* getDisplayName() = 0;
		/*! Sets the display name of the engineering unit. This is typically the abbreviation
		* of the engineering unit, e.g. "h" for hour or m/s for meter per second. */
		virtual void setDisplayName(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual void setDisplayName(const LocalizedText& value) = 0;

		/*! Returns the full name of the engineering unit such as "hour" or "meter per second". */
		virtual const ILocalizedText* getDescription() const = 0;
		/*! @overload */
		virtual ILocalizedText* getDescription() = 0;
		/*! Sets the full name of the engineering unit such as "hour" or "meter per second". */
		virtual void setDescription(const ILocalizedText* value) = 0;
		/*! @overload */
		virtual void setDescription(const LocalizedText& value) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IEUInformation* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IEUInformation& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IEUInformation* other) const = 0;
		/*! @overload */
		virtual int compare(const IEUInformation& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEUInformation& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEUInformation& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IEUInformation
} // end namespace
#endif	// IEUINFORMATION_H
