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

#ifndef UAENCODERSUPPORT_H
#define UAENCODERSUPPORT_H

#include "EncoderContext.h"
#include "DateTime.h"
#include "NodeId.h"
#include "QualifiedName.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			namespace UaEncoderSupport
			{
				/*! Converts the source tstring to the target xmlChar
				* @param pTarget	Pointer to xmlChar*, where the target xmlChar array is allocated
				* @param source		tstring to convert from
				*
				* @note pTarget has to be freed with xmlFree() */
				TBC_EXPORT EnumModelDesignerStatus convertInput(xmlChar** pTarget, tstring source);

				/*! Encodes a boolean value to XML
				* @param value		The boolean value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeBoolean(bool value, EncoderContextPtr context);

				/*! Encodes a DateTime value to XML
				* @param value		The DateTime value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeDateTime(const DateTime& value, EncoderContextPtr context);

				/*! Encodes a float value to XML
				* @param value		The float value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeFloat(float value, EncoderContextPtr context);

				/*! Encodes a double value to XML
				* @param value		The double value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeDouble(double value, EncoderContextPtr context);

				/*! Encodes an Int8 value to XML
				* @param value		The Int8 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeSByte(OTInt8 value, EncoderContextPtr context);
				TBC_EXPORT EnumModelDesignerStatus encodeInt8(OTInt8 value, EncoderContextPtr context);

				/*! Encodes an Int16 value to XML
				* @param value		The Int16 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeInt16(OTInt16 value, EncoderContextPtr context);

				/*! Encodes an Int32 value to XML
				* @param value		The Int32 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeInt32(OTInt32 value, EncoderContextPtr context);

				/*! Encodes an Int64 value to XML
				* @param value		The Int64 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeInt64(OTInt64 value, EncoderContextPtr context);

				/*! Encodes a NodeId value to XML
				* @param value		The NodeId value to encode
				* @param context	The context information required for encoding
				* @param useAliasMap Encodes tha alias instead of the NodeId encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeNodeId(const NodeId& value, EncoderContextPtr context, bool useAliasMap = true);

				/*! Encodes a QualifiedName value to XML
				* @param value		The QualifiedName value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeQualifiedName(const QualifiedName& value, EncoderContextPtr context);

				/*! Encodes a string value to XML
				* @param value		The string value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeString(const tstring& value, EncoderContextPtr context);

				/*! Encodes an UInt8 value to XML
				* @param value		The UInt8 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeByte(OTUInt8 value, EncoderContextPtr context);
				TBC_EXPORT EnumModelDesignerStatus encodeUInt8(OTUInt8 value, EncoderContextPtr context);

				/*! Encodes an UInt16 value to XML
				* @param value		The UInt16 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUInt16(OTUInt16 value, EncoderContextPtr context);

				/*! Encodes an UInt32 value to XML
				* @param value		The UInt32 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUInt32(OTUInt32 value, EncoderContextPtr context);

				/*! Encodes an UInt64 value to XML
				* @param value		The UInt64 value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeUInt64(OTUInt64 value, EncoderContextPtr context);

				/*! Encodes a Guid value to XML
				* @param value		The Guid value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeGuid(const Guid& value, EncoderContextPtr context);

				/*! Encodes a ByteString value to XML
				* @param value		The ByteString value to encode
				* @param context	The context information required for encoding */
				TBC_EXPORT EnumModelDesignerStatus encodeByteString(const ByteString& value, EncoderContextPtr context);

				/** Helper function to encode base64 strings
				 * @param bytes_to_encode
				 * @param in_len */
				tstring base64_encode(OTUInt8 const* bytes_to_encode, OTUInt32 in_len);
			}
		}
	}
}
#endif // UAENCODERSUPPORT_H
