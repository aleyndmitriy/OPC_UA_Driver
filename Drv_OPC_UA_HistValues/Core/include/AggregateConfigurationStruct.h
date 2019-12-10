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

#ifndef AGGREGATECONFIGURATIONSTRUCT_H
#define AGGREGATECONFIGURATIONSTRUCT_H

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


//lint -sem(AggregateConfigurationStruct::clear, cleanup)
//lint -sem(AggregateConfigurationStruct::init, initializer)
typedef struct TBCORE_IF AggregateConfigurationStruct
{
	/*! If true, the server’s default values are used and any values specified for the other parameters are ignored. */
	OTBoolean useServerCapabilitiesDefaults;

	/*! A value of true indicates the server considers the severity equivalent to Bad, a value of false indicates the
	 *  server considers the severity equivalent to Good, unless the aggregate definition says otherwise */
	OTBoolean treatUncertainAsBad;

	/*! Indicates the minimum percentage of bad data in a given interval required for the StatusCode
	 *  for the given interval for processed data request to be set to Bad */
	OTUInt8 percentDataBad;

	/*! indicates the minimum percentage of Good data in a given interval required for the StatusCode
	 *  for the given interval for the processed data requests to be set to Good */
	OTUInt8 percentDataGood;

	/*! indicates how the server interpolates data when no boundary value exists (i.e. extrapolating into
	 * the future from the last known value). A value of False indicates that the server will use a
	 * SteppedExtrapolation format, and hold the last known value constant. A value of True indicates the
	 * server will project the value using UseSlopedExtrapolation mode. */
	OTBoolean useSlopedExtrapolation;


	AggregateConfigurationStruct();
	AggregateConfigurationStruct(const AggregateConfigurationStruct&);

	EnumStatusCode set(const AggregateConfigurationStruct&);
	EnumStatusCode get(AggregateConfigurationStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_AggregateConfiguration&);
	EnumStatusCode get(OpcUa_AggregateConfiguration&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const AggregateConfigurationStruct& operator=(const AggregateConfigurationStruct& cp);
	bool operator==(const AggregateConfigurationStruct& toCompare) const;
	bool operator!=(const AggregateConfigurationStruct& toCompare) const;
	bool operator<(const AggregateConfigurationStruct& toCompare) const;
	bool operator>(const AggregateConfigurationStruct& toCompare) const;

	int compare(const AggregateConfigurationStruct* pTarget) const;

	void clear(void);
	~AggregateConfigurationStruct(void);
} AggregateConfigurationStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// AGGREGATECONFIGURATIONSTRUCT_H
