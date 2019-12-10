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

#ifndef STRUCTHELPERS_H
#define STRUCTHELPERS_H

#include <errno.h>

#define RETURN_ON_RESULT_NOT_GOOD \
	if(result != EnumStatusCode_Good) \
{ \
	return result; \
}

#define RETURN_OUT_OF_MEMORY_ON_NULL(x) \
	if(NULL == x) \
	return EnumStatusCode_BadOutOfMemory \

#define COPY_UASTRING_OTCSTRING(x, y) \
	if(!OpcUa_String_IsNull((OpcUa_String *)&(y))) \
{ \
	if(UaHelper::OpcUa_StringToOTString((x), (y)) != 0) \
{ \
	return EnumStatusCode_Bad; \
} \
}

//lint -esym(666, COPY_OTCSTRING_UASTRING) Allow expression with side effects to pass to repeated parameter 2 in macro 'COPY_OTCSTRING_UASTRING'
#define COPY_OTCSTRING_UASTRING(x, y) \
	if((y) != NULL) \
{ \
	EnumStatusCode macroResult; \
	macroResult = UaHelper::SetUtf8OpcUa_String((x), (y)); \
	if(macroResult != EnumStatusCode_Good) \
{ \
	return macroResult; \
} \
}


class StructHelpers
{
public:
	static void ReleaseString(OTChar*& string);
	static EnumStatusCode CopyString(OTChar*& target, const OTChar* source);
	static EnumStatusCode CopyString(OTChar*& target, const tstring& source);
	static EnumStatusCode ReplaceString(OTChar*& target, const OTChar* source);
	static bool CompareString(const OTChar* string1, const OTChar* string2);

	static void ReleaseByteString(ByteStringStruct*& cp);
	static EnumStatusCode CopyByteStringStruct(ByteStringStruct*& target, const ByteStringStruct* source);
	static EnumStatusCode CopyByteStringStruct(ByteStringStruct& target, const ByteStringStruct& source);
	static EnumStatusCode ReplaceByteStringStruct(ByteStringStruct*& target, const ByteStringStruct* source);

	static EnumStatusCode MakeHexString(OTChar*& target, unsigned char* buf, OTUInt32 bufSize);
	static EnumStatusCode MakeBufFromHexString(OpcUa_ByteString &taget, const OTChar* source);

	static EnumStatusCode AllocByteBuffer(unsigned char* &target, const void* src, OTUInt32 length);

	/*! Convenience function to convert an array length to an unsigned value with the correct sign handling */
	static OTUInt32 toUnsignedLength(OTInt32 arrayLength);
};

/*! @brief function for allocating typed pointer arrays in the stack.
*	@param pTarget [out] Pointer which will be initialized by OpcUa_Alloc() */
template<class pointerType> pointerType* typedUAlloc(
	pointerType*& pPointer,
	size_t elemCount)
{
	if(elemCount)
	{
		pPointer = (pointerType*) OpcUa_Alloc((OpcUa_UInt32)(sizeof(pointerType) * elemCount));
	}
	else
	{
		pPointer = 0;
	}
	return pPointer;
}


/*! @brief Copy an array of primitives from source to target.
* @attention Use it only for primitive types. */
template<class targetType, class sourceType> EnumStatusCode copyTypedUArray(
	targetType*& pTarget,
	sourceType* pSource,
	size_t length)
{
	if(pSource == NULL && length == 0)
	{
		pTarget = NULL;
		return EnumStatusCode_Good;
	}
	else if(pSource == NULL && length > 0)
	{
		pTarget = NULL;
		return EnumStatusCode_BadInvalidArgument;
	}

	typedUAlloc(
		pTarget,
		length);

	if(pTarget == NULL)
	{
		return EnumStatusCode_BadOutOfMemory;
	}

	// avoid warning...
	OTUInt32 size = sizeof(targetType);

	if(size == sizeof(sourceType))
	{ // then we can make a memcpy!
		memcpy(
			pTarget,
			pSource,
			sizeof(targetType) * length);
	}
	else
	{
		targetType* pTargetLocal = pTarget;
		sourceType* pSourceLocal = pSource;
		while(length--)
		{ // for all array members...
			*pTargetLocal++ = *pSourceLocal++;
		}
	}
	return EnumStatusCode_Good;
}


/*! @brief Copy an extern string into a string member  */
#define COPY_EXTERN_STRING(x, y)\
{\
	EnumStatusCode result = StructHelpers::CopyString(x, y);\
	RETURN_ON_RESULT_NOT_GOOD\
}

/*! @brief Copies a string into the member, returns with an error if failed */
#define COPY_STRING(x)\
{\
	EnumStatusCode result = StructHelpers::CopyString(x, cp.x);\
	RETURN_ON_RESULT_NOT_GOOD\
}

/*! @brief Checks the result of the given expression and returns with a result state in case of an error */
#define CHECK_RESULT(x)\
{\
	EnumStatusCode result = x;\
	if(result != EnumStatusCode_Good)\
	return result;\
}

/*! @brief Compares a string in this and the toCompare struct, returns false in case of a difference */
#define COMPARE_STRINGS(x) if(!StructHelpers::CompareString(x, toCompare.x))\
	return false;

/*! @brief Compares a member in this and the compare struct, returns false if they are different */
#define COMPARE_MEMBER(x) if(x != toCompare.x)\
	return false;

/*! @brief Calls the clear() method on value structures.
@param The structure pointer. */
template<class pointerType> void clearStructure(pointerType* pPointer)
{
	if(pPointer != NULL)
	{
		pPointer->clear();
		OTFreeMemory(pPointer);
	}
}

#endif	// STRUCTHELPERS_H
