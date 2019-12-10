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

#ifndef AGGREGATECONFIGURATION_H
#define AGGREGATECONFIGURATION_H
#if TB5_HISTORY

#include "IAggregateConfiguration.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The AggregateConfiguration data type is used by clients in requests that return
	* aggregated historical data (see Client::Session::historyReadProcessed()) to tell
	* the server whether to use the default or a custom configuration for calculating aggregated values. */
	class TBC_EXPORT AggregateConfiguration
		: public IAggregateConfiguration
	{
	public:
		/*! Default constructor */
		AggregateConfiguration();
		/*! Constructs a copy of the given instance @p cp */
		AggregateConfiguration(const IAggregateConfiguration* cp);
		/*! @overload */
		AggregateConfiguration(const IAggregateConfiguration& cp);
		/*! @overload */
		AggregateConfiguration(const AggregateConfiguration& cp);

		/*! Destructor */
		virtual ~AggregateConfiguration();

		/*! Assigns the contents of @p cp to this instance */
		AggregateConfiguration& operator=(const IAggregateConfiguration* cp);
		/*! @overload */
		AggregateConfiguration& operator=(const IAggregateConfiguration& cp);
		/*! @overload */
		AggregateConfiguration& operator=(const AggregateConfiguration& cp);

		/* see IAggregateConfiguration::set */
		virtual EnumStatusCode set(const IAggregateConfiguration* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IAggregateConfiguration& pSrc);

		/* see IAggregateConfiguration::compare */
		virtual int compare(const IAggregateConfiguration* other) const;
		/*! @overload */
		virtual int compare(const IAggregateConfiguration& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAggregateConfiguration& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAggregateConfiguration& other) const;

		/* see IAggregateConfiguration::getUseServerCapabilitiesDefaults */
		virtual OTBoolean getUseServerCapabilitiesDefaults() const;
		/* see IAggregateConfiguration::setUseServerCapabilitiesDefaults */
		virtual void setUseServerCapabilitiesDefaults(const OTBoolean& value);

		/* see IAggregateConfiguration::getTreatUncertainAsBad */
		virtual OTBoolean getTreatUncertainAsBad() const;
		/* see IAggregateConfiguration::setTreatUncertainAsBad */
		virtual void setTreatUncertainAsBad(const OTBoolean& value);

		/* see IAggregateConfiguration::getPercentDataBad */
		virtual OTUInt8 getPercentDataBad() const;
		/* see IAggregateConfiguration::setPercentDataBad */
		virtual void setPercentDataBad(const OTUInt8& value);

		/* see IAggregateConfiguration::getPercentDataGood */
		virtual OTUInt8 getPercentDataGood() const;
		/* see IAggregateConfiguration::setPercentDataGood */
		virtual void setPercentDataGood(const OTUInt8& value);

		/* see IAggregateConfiguration::getUseSlopedExtrapolation */
		virtual OTBoolean getUseSlopedExtrapolation() const;
		/* see IAggregateConfiguration::setUseSlopedExtrapolation */
		virtual void setUseSlopedExtrapolation(const OTBoolean& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		AggregateConfigurationStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif	// AGGREGATECONFIGURATION_H
