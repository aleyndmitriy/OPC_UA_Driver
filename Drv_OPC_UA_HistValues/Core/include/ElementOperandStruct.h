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

#ifndef __ELEMENTOPERANDSTRUCT_H_
#define __ELEMENTOPERANDSTRUCT_H_
#if TB5_FILTER

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif


/*! Structure defining an 'element' operand for the where clauses in the filter. */
//lint -sem(ElementOperandStruct::clear, cleanup)
//lint -sem(ElementOperandStruct::init, initializer)
typedef struct TBCORE_IF ElementOperandStruct
{
	OTUInt32 index;


	ElementOperandStruct();

	EnumStatusCode set(const ElementOperandStruct&);
	EnumStatusCode get(ElementOperandStruct&) const;
#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_ElementOperand&);
	EnumStatusCode get(OpcUa_ElementOperand&) const;
	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif


	const ElementOperandStruct& operator=(const ElementOperandStruct& cp);
	bool operator==(const ElementOperandStruct& toCompare) const;
	bool operator!=(const ElementOperandStruct& toCompare) const;
	bool operator<(const ElementOperandStruct& toCompare) const;
	bool operator>(const ElementOperandStruct& toCompare) const;

	int compare(const ElementOperandStruct* pTarget) const;

	void clear(void);
	~ElementOperandStruct(void);

}ElementOperandStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
#endif
