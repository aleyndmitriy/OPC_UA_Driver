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

#ifndef MC_ERRORMACROS_H
#define MC_ERRORMACROS_H

/*****************************************************************************
 * MC_ReturnErrorIfNull
 ****************************************************************************/
#define MC_ReturnErrorIfNull(xArg, xResult) \
if((xArg) == NULL) \
{ \
	return xResult; \
}

/*****************************************************************************
 * MC_ReturnErrorIfArgumentNull
 ****************************************************************************/
#define MC_ReturnErrorIfArgumentNull(xArg) \
if((xArg) == NULL) \
{ \
	return EnumModelDesignerStatus_BadInvalidArgument; \
}

/*****************************************************************************
 * MC_ReturnErrorIfArrayArgumentNull
 ****************************************************************************/
#define MC_ReturnErrorIfArrayArgumentNull(xCount, xArg) \
if((xCount) > 0 && (xArg) == NULL) \
{ \
	return EnumModelDesignerStatus_BadInvalidArgument; \
}

/*****************************************************************************
 * MC_ReturnErrorIfAllocFailed
 ****************************************************************************/
#define MC_ReturnErrorIfAllocFailed(xArg) \
if((xArg) == NULL) \
{ \
	return EnumModelDesignerStatus_BadOutOfMemory; \
}

/*****************************************************************************
 * MC_ReturnErrorIfTrue
 ****************************************************************************/
#define MC_ReturnErrorIfTrue(xCondition, xResult) \
if(xCondition) \
{ \
	return xResult; \
}

/*****************************************************************************
 * MC_ReturnErrorIfBad
 ****************************************************************************/
#define MC_ReturnErrorIfBad(xResult) \
{ \
	EnumModelDesignerStatus resultCopy = xResult; \
	if(resultCopy != EnumModelDesignerStatus_Good) \
	{ \
		return resultCopy; \
	} \
}

/*****************************************************************************
 * MC_ReturnErrorIfXmlWriterBad
 ****************************************************************************/
#define MC_ReturnErrorIfXmlWriterBad(xResult) \
if(xResult < 0) \
{ \
	return EnumModelDesignerStatus_BadWriterError; \
}

/*****************************************************************************
 * MC_GotoErrorIfNull
 ****************************************************************************/
#define MC_GotoErrorIfNull(xArg, xResult) \
if(xArg == NULL) \
{ \
	result = xResult; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoErrorIfNull
 ****************************************************************************/
#define MC_GotoErrorIfNotNull(xArg, xResult) \
if(xArg != NULL) \
{ \
	result = xResult; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoErrorIfArgumentNull
 ****************************************************************************/
#define MC_GotoErrorIfArgumentNull(xArg) \
if(xArg == NULL) \
{ \
	result = EnumModelDesignerStatus_BadInvalidArgument; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoErrorIfAllocFailed
 ****************************************************************************/
#define MC_GotoErrorIfAllocFailed(xArg) \
if(xArg == NULL) \
{ \
	result = EnumModelDesignerStatus_BadOutOfMemory; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoErrorIfTrue
 ****************************************************************************/
#define MC_GotoErrorIfTrue(xCondition, xResult) \
if(xCondition) \
{ \
	result = xResult; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoErrorIfBad
 ****************************************************************************/
#define MC_GotoErrorIfBad(xResult) \
{ \
	EnumModelDesignerStatus resultCopy = xResult; \
	if(resultCopy != EnumModelDesignerStatus_Good) \
	{ \
		result = resultCopy; \
		goto MCErrorLabel; \
	}\
}

/*****************************************************************************
 * MC_GotoErrorIfXmlWriterBad
 ****************************************************************************/
#define MC_GotoErrorIfXmlWriterBad(xResult) \
if(xResult < 0) \
{ \
	result = EnumModelDesignerStatus_BadWriterError; \
	goto MCErrorLabel; \
}

/*****************************************************************************
 * MC_GotoError
 ****************************************************************************/
/** @brief Jumps to the beginning of the error handling block. */
#define MC_GotoError goto MCErrorLabel

/*****************************************************************************
 * MC_ReturnErrorWithStatus
 ****************************************************************************/
#define MC_GotoErrorWithStatus(xResult) \
	result = xResult; \
	goto MCErrorLabel

/*****************************************************************************
 * MC_InitializeStatus
 ****************************************************************************/
/** @brief Marks the beginning of an error handling block. */
#define MC_InitializeStatus \
EnumModelDesignerStatus result = EnumModelDesignerStatus_Good; \
_UNUSED(result); \
MC_GotoErrorIfBad(result)

/*****************************************************************************
 * MC_ReturnStatusCode
 ****************************************************************************/
#define MC_ReturnStatusCode \
return result

/*****************************************************************************
 * MC_BeginErrorHandling
 ****************************************************************************/
#define MC_BeginErrorHandling MCErrorLabel:

/*****************************************************************************
 * MC_FinishErrorHandling
 ****************************************************************************/
#define MC_FinishErrorHandling return result

/*****************************************************************************
 * MC_SuppressError
 ****************************************************************************/
#define MC_SuppressError(xResult) result = xResult

#endif	// MC_ERRORMACROS_H
