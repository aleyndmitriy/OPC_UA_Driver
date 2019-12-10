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

#ifndef __LITERALOPERANDSTRUCT_H_
#define __LITERALOPERANDSTRUCT_H_
#if TB5_FILTER

#include "ValueStruct.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

/*! Structure defining a 'literalt' operand for the where clauses in the filter. */
//lint -sem(LiteralOperandStruct::clear, cleanup)
//lint -sem(LiteralOperandStruct::init, initializer)
typedef struct TBCORE_IF LiteralOperandStruct
{
	ValueStruct value;


	LiteralOperandStruct();

	EnumStatusCode set(const LiteralOperandStruct&);
	EnumStatusCode get(LiteralOperandStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_LiteralOperand&);
	EnumStatusCode get(OpcUa_LiteralOperand&, const std::vector<tstring>& preferredLocales) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject, const std::vector<tstring>& preferredLocales) const;
#endif


	const LiteralOperandStruct& operator=(const LiteralOperandStruct& cp);
	bool operator==(const LiteralOperandStruct& toCompare) const;
	bool operator!=(const LiteralOperandStruct& toCompare) const;
	bool operator<(const LiteralOperandStruct& toCompare) const;
	bool operator>(const LiteralOperandStruct& toCompare) const;

	int compare(const LiteralOperandStruct* pTarget) const;

	void clear(void);
	~LiteralOperandStruct(void);

}LiteralOperandStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif

#endif
