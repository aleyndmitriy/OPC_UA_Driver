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

#ifndef _SignedSoftwareCertificateStruct_H_
#define _SignedSoftwareCertificateStruct_H_

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

#include "ByteStringStruct.h"

//lint -sem(SignedSoftwareCertificateStruct::clear, cleanup)
//lint -sem(SignedSoftwareCertificateStruct::init, initializer)
typedef struct TBCORE_IF SignedSoftwareCertificateStruct
{
	/*! The DER encoded certificate */
	ByteStringStruct certificateData;

	/*! The signature data */
	ByteStringStruct signature;


	SignedSoftwareCertificateStruct();
	SignedSoftwareCertificateStruct(const SignedSoftwareCertificateStruct&);

	EnumStatusCode set(const SignedSoftwareCertificateStruct&);
	EnumStatusCode get(SignedSoftwareCertificateStruct&) const;

#ifdef OT_COMPILATION
	EnumStatusCode set(const OpcUa_SignedSoftwareCertificate&);
	EnumStatusCode get(OpcUa_SignedSoftwareCertificate&) const;

	EnumStatusCode getOpcUaExtensionObject(OpcUa_ExtensionObject& extensionObject) const;
#endif

	const SignedSoftwareCertificateStruct& operator=(const SignedSoftwareCertificateStruct& cp);
	bool operator==(const SignedSoftwareCertificateStruct& toCompare) const;
	bool operator!=(const SignedSoftwareCertificateStruct& toCompare) const;
	bool operator<(const SignedSoftwareCertificateStruct& toCompare) const;
	bool operator>(const SignedSoftwareCertificateStruct& toCompare) const;

	int compare(const SignedSoftwareCertificateStruct* pTarget) const;

	void clear(void);
	~SignedSoftwareCertificateStruct(void);
} SignedSoftwareCertificateStruct;

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif
