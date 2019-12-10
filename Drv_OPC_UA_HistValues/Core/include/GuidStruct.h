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

#ifndef _GUIDSTRUCT_H_
#define _GUIDSTRUCT_H_

#ifdef SOOS_WINDOWS
#pragma pack(push,8)
#endif

/*!
	@brief Correspond to OpcUa_Guid.
	Should work on both Windows and Linux. On Linux the
	UUID structure is identical with the GUID from Windows.
*/
//lint -sem(GuidStruct::clear, cleanup)
//lint -sem(GuidStruct::init, initializer)
typedef struct TBCORE_IF GuidStruct
{
	OTUInt32 data1;
	OTUInt16 data2;
	OTUInt16 data3;
	OTUInt8  data4[8];

	GuidStruct(void);

	EnumStatusCode set(const GuidStruct&);
	EnumStatusCode get(GuidStruct& target) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_Guid& cp);
	EnumStatusCode get(OpcUa_Guid& target) const;
#endif

	const GuidStruct& operator=(const GuidStruct& cp);
	bool operator==(const GuidStruct& cp) const;
	bool operator!=(const GuidStruct& cp) const;

	int compare(const GuidStruct* with) const;
	int compare(const GuidStruct & with) const;

	/*! Generate a Guid.*/
	EnumStatusCode generateGuid(void);
	static EnumStatusCode parse(const tstring& pString, GuidStruct& pGuid);

	bool isNull() const;

	void clear(void);
	~GuidStruct(void);
	tstring toString() const;

}GuidStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif // _GUIDSTRUCT_H_


