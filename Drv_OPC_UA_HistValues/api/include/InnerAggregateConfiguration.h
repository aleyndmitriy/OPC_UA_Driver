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

#ifndef INNERAGGREGATECONFIGURATION_H
#define INNERAGGREGATECONFIGURATION_H
#if TB5_HISTORY

#include "IAggregateConfiguration.h"

namespace SoftingOPCToolbox5
{
	/*! @copydoc IAggregateConfiguration */
	class TBC_EXPORT InnerAggregateConfiguration
		: public IAggregateConfiguration
	{
	public:
		/*! Destructor */
		virtual ~InnerAggregateConfiguration();

		virtual OTBoolean getUseServerCapabilitiesDefaults() const;
		virtual void setUseServerCapabilitiesDefaults(const OTBoolean& value);

		virtual OTBoolean getTreatUncertainAsBad() const;
		virtual void setTreatUncertainAsBad(const OTBoolean& value);

		virtual OTUInt8 getPercentDataBad() const;
		virtual void setPercentDataBad(const OTUInt8& value);

		virtual OTUInt8 getPercentDataGood() const;
		virtual void setPercentDataGood(const OTUInt8& value);

		virtual OTBoolean getUseSlopedExtrapolation() const;
		virtual void setUseSlopedExtrapolation(const OTBoolean& value);

		/*! For internal use only */
		void initInner(AggregateConfigurationStruct* pHandle);

		/*! @see IAggregateConfiguration::set(const IAggregateConfiguration*) */
		EnumStatusCode set(const IAggregateConfiguration* pSrc);
		/*! @see IAggregateConfiguration::set(const IAggregateConfiguration&) */
		EnumStatusCode set(const IAggregateConfiguration& pSrc);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IAggregateConfiguration* other) const;
		/*! @overload */
		virtual int compare(const IAggregateConfiguration& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IAggregateConfiguration& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IAggregateConfiguration& other) const;

		/*! @see IAggregateConfiguration::getInternHandle() */
		virtual void* getInternHandle() const;

	private:

		AggregateConfigurationStruct* m_pContent;
	};
} // end namespace

#endif
#endif	// INNERAGGREGATECONFIGURATION_H
