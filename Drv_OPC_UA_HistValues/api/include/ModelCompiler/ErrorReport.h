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

#ifndef MC_ERROR_REPORT_H
#define MC_ERROR_REPORT_H

#include "Enums.h"

#include "include/ModelCompiler/ErrorReportExports.h"
#include "include/ModelCompiler/ErrorEnums.h"
#include "ByteStringStruct.h"

/*! A specific error context type which indicates a line of an XML file */
typedef struct _MCXmlContext
{
	//! The null terminated XML file name where the error occurred or NULL if not available
	const OTChar* xmlFileName;
	//! The line number in the XML file where the error occurred or -1 if not available
	OTInt32 lineNumber;
}
MCXmlContext;

typedef struct _MCRollbackContext
{
	// no additional information during rollback
	OTInt32 unused;
}
MCRollbackContext;

/*! A common context which contains and identifies an error specific context type */
typedef struct _MCErrorContext
{
	EnumMCErrorContextType contextType;
	union
	{
		MCXmlContext* pXmlContext;
		MCRollbackContext* pRollbackContext;
	} context;
}
MCErrorContext;

#ifdef __cplusplus
extern "C"
{
#endif

/*! A function pointer which is used to register functions (or static methods) to the error report */
typedef void (MC_ERROR_REPORT_CALL *MCErrorCallback)(EnumTraceLevel severity, EnumTraceGroup group, EnumModelDesignerStatus error, const OTChar* errorMessage, const MCErrorContext* errorContext);

/*! Initializes the error report functionality */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportInitialize();

/*! Uninitializes the error report functionality */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportUninitialize();

/*! Register a function (or static method) to receive information of all errors reported by reportError(). */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportRegisterErrorCallback(MCErrorCallback callback);
/*! Unregister a function (or static method) which has been registered. */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportUnregisterErrorCallback(MCErrorCallback callback);

/*! A function pointer which is used to register functions (or static methods) to the error report */
typedef EnumModelDesignerStatus (MC_ERROR_REPORT_CALL *MCDuplicateNodeCallback)(void* nodeHandle, void* nodeDescriptionHandle, ByteStringStruct* pXmlTag);
/*! Register a function (or static method) to receive information of duplicate Nodes reported. */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportRegisterDuplicateNodeCallback(MCDuplicateNodeCallback callback);
/*! Unregister a function (or static method) which has been registered. */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportUnregisterDuplicateNodeCallback(MCDuplicateNodeCallback callback);

/*! Reports an error with a related error context to all registered callbacks and to trace mechanism used by the dataFEED OPC UA C++ Server & Client SDK.
*
* @param severity		The severity of the error
* @param group			Describes which group (e.g. which software component or user) reports the error
* @param error			An enumeration value describing the error type
* @param errorMessage	A message describing the error.
* @param errorContext Contains some context information to error source, this parameter is allowed to be NULL */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportReportError(EnumTraceLevel severity, EnumTraceGroup group, EnumModelDesignerStatus error, const OTChar* errorMessage, const MCErrorContext* errorContext);

/*! This is a convenience method for MCErrorReportReportError used with an XML context */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportReportXMLError(EnumTraceLevel severity, EnumTraceGroup group, EnumModelDesignerStatus error, const OTChar* errorMessage, const OTChar* fileName, OTInt32 lineNumber);


/*! Reports an import of an already existing Node.
*
* @param nodeHandle				the Handle of the already existing Node
* @param nodeDescriptionHandle	the handle of the imported NodeDescription
* @param xmlTag					the xml tag of the imported Node */
MC_ERROR_REPORT_EXPORT EnumModelDesignerStatus MC_ERROR_REPORT_CALL MCErrorReportReportDuplicateNode(void* nodeHandle, void* nodeDescriptionHandle, ByteStringStruct* xmlTag);

/*! Initializes the MCXmlContext structure with default values. */
MC_ERROR_REPORT_EXPORT void MC_ERROR_REPORT_CALL MCXMLContextInitialize(MCXmlContext* pXmlContext);

/*! Initializes the MCRollbackContext structure with default values. */
MC_ERROR_REPORT_EXPORT void MC_ERROR_REPORT_CALL MCRollbackContextInitialize(MCRollbackContext* pRollbackContext);

#ifdef __cplusplus
}
#endif

#endif	// MC_ERROR_REPORT_H
