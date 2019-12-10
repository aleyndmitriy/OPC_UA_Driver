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

#ifndef MC_ERROR_ENUMS_H
#define MC_ERROR_ENUMS_H

#include "OSCompat.h"
#include "ErrorReportExports.h"

#ifdef __cplusplus
extern "C"
{
#endif
/*! @file ErrorEnums.h */

/*! Enumeration type used for status information. */
typedef enum tagEnumModelDesignerStatus
{
	//! Everything is as expected.
	EnumModelDesignerStatus_Good,
	//! An error occurred.
	EnumModelDesignerStatus_Bad = 1,
	//! One or more arguments are invalid.
	EnumModelDesignerStatus_BadInvalidArgument = 3,
	//! Not enough memory to complete the operation.
	EnumModelDesignerStatus_BadOutOfMemory = 4,
	//! The operation cannot be completed because the object is closed, uninitialized or in some other invalid state.
	EnumModelDesignerStatus_BadInvalidState = 5,
	//! An internal error occurred as a result of a programming or configuration error.
	EnumModelDesignerStatus_BadInternalError = 6,
	//! The parser failed to parse the input.
	EnumModelDesignerStatus_BadParserError = 7,
	//! The libxml2 writer operation returned an unexpected error.
	EnumModelDesignerStatus_BadWriterError = 8,
	//! The parser encountered an unsupported OPC UA data type.
	EnumModelDesignerStatus_BadDataTypeUnsupported = 9,
	//! Requested operation is not implemented.
	EnumModelDesignerStatus_BadNotImplemented = 10,
	//! A file could not be opened.
	EnumModelDesignerStatus_BadFileOpenError = 11,
	//! The requested operation is not supported.
	EnumModelDesignerStatus_BadNotSupported = 12,
	//! The requested node id is already used by another node.
	EnumModelDesignerStatus_BadNodeIdExists = 13,
	//! The requested operation has no match to return.
	EnumModelDesignerStatus_BadNoMatch = 14,
	//! The import failed due to some OPC UA specification restriction.
	EnumModelDesignerStatus_BadImportError = 15,
	//! The specified namespace does not exist.
	EnumModelDesignerStatus_BadNamespaceUnknown = 16,
	//! The data type attribute does not evaluate to a node of class DataType.
	EnumModelDesignerStatus_BadDataTypeInvalid = 17,
	//! The node id refers to a node that does not exist in the server address space.
	EnumModelDesignerStatus_BadNodeIdUnknown = 18,
	//! The value supplied for the attribute is not of the same type as the attribute's value.
	EnumModelDesignerStatus_BadTypeMismatch = 19,
	//! The client did not specify all of the input arguments for the method.
	EnumModelDesignerStatus_BadArgumentsMissing = 20,
	//! The provided NodeId was not a type definition NodeId.
	EnumModelDesignerStatus_BadNotTypeDefinition = 21,
	//! The type definition node id does not reference an appropriate type node.
	EnumModelDesignerStatus_BadTypeDefinitionInvalid = 22,
	//! The node class is not valid.
	EnumModelDesignerStatus_BadNodeClassInvalid = 23,
	//! The reference type id does not refer to a valid reference type node.
	EnumModelDesignerStatus_BadReferenceTypeIdInvalid = 24,
	//! The requested node id was reject because it was either invalid or server does not allow node ids to be specified by the client.
	EnumModelDesignerStatus_BadNodeIdRejected = 25,
	//! The browse name is invalid.
	EnumModelDesignerStatus_BadBrowseNameInvalid = 26,
	//! The method call was denied by the application.
	EnumModelDesignerStatus_BadDenied = 27,
	//! The existing type cannot be modified, because it is already instantiated.
	EnumModelDesignerStatus_BadTypeModificationRejected = 28,
	//! A mandatory Attribute for type or instance creation is missing.
	EnumModelDesignerStatus_BadMandatoryAttributeMissing = 29,
	//! The parent node id does not to refer to a valid node.
	EnumModelDesignerStatus_BadParentNodeIdInvalid = 30,
	//! The source node id does not reference a valid node.
	EnumModelDesignerStatus_BadSourceNodeIdInvalid = 31,
	//! The target node id does not reference a valid node.
	EnumModelDesignerStatus_BadTargetNodeIdInvalid = 32,
	//! The reference could not be created because it violates constraints imposed by the data model.
	EnumModelDesignerStatus_BadReferenceNotAllowed = 33,
	//! The reference type between the nodes is already defined.
	EnumModelDesignerStatus_BadDuplicateReferenceNotAllowed = 34,
	//! The server does not allow this type of self reference on this node.
	EnumModelDesignerStatus_BadInvalidSelfReference = 35,
	//! A mandatory component cannot be removed or moved.
	EnumModelDesignerStatus_BadMandatoryComponent = 36,
	//! The attribute is not supported for the specified Node.
	EnumModelDesignerStatus_BadAttributeIdInvalid = 37,
	//! The string is not a valid URI.
	EnumModelDesignerStatus_BadUriInvalid = 38,
	//! The node is already exported.
	EnumModelDesignerStatus_BadAlreadyExported = 39,
	//! The namespace index of the node is not within the export URIs.
	EnumModelDesignerStatus_BadUriMismatch = 40

	//Adapt EnumModelDesignerStatusMax when new EnumCompilerSatusCodes are added
}
EnumModelDesignerStatus;

/*! Min value of EnumModelDesignerStatus */
const OTInt32 EnumModelDesignerStatusMin = EnumModelDesignerStatus_Good;
/*! Max value of EnumModelDesignerStatus */
const OTInt32 EnumModelDesignerStatusMax = EnumModelDesignerStatus_BadUriMismatch;

/*! Returns the status code value as string */
MC_ERROR_REPORT_EXPORT const OTChar* MC_ERROR_REPORT_CALL MCGetEnumModelDesignerStatusString(EnumModelDesignerStatus status);
/*! Returns a description of a status code */
MC_ERROR_REPORT_EXPORT const OTChar* MC_ERROR_REPORT_CALL MCGetEnumModelDesignerStatusDescription(EnumModelDesignerStatus status);

/*! Enumeration type to distinguish the available error context types. */
typedef enum tagEnumMCErrorContextType
{
	//! Context information related to a XML file
	EnumMCErrorContextType_XmlContext,
	//! Failure occurred during rollback due to a previous error
	EnumMCErrorContextType_RollbackContext
}
EnumMCErrorContextType;

/*! Returns the error context type as string */
MC_ERROR_REPORT_EXPORT const OTChar* MC_ERROR_REPORT_CALL MCGetEnumMCErrorContextTypeString(EnumMCErrorContextType contextType);

#ifdef __cplusplus
}
#endif

/*! Returns the enumeration value as string
*
* @note	This function is only available if the SDK was configured with model designer support.
*		This feature can be enabled or disabled in the %ToolkitConfig.h header file. (Source code delivery only) */
TBC_EXPORT const OTChar* getEnumModelDesignerStatusString(EnumModelDesignerStatus value);

#endif	// MC_ERROR_ENUMS_H
