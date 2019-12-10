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

#ifndef MC_NODESET2IMPORT_H
#define MC_NODESET2IMPORT_H

/*! This is the public interface of the NodeSet2 importer. */

#include "include/ModelCompiler/ModelCompilerExports.h"
#include "include/ModelCompiler/ErrorEnums.h"
#include "OSCompat.h"
#include "Enums.h"

// forward declarations
struct DateTimeStruct;
struct ByteStringStruct;
typedef ByteStringStruct XmlElementStruct;
struct NodeIdStruct;
struct QualifiedNameStruct;
struct LocalizedTextStruct;
struct ValueStruct;
struct ExpandedNodeIdStruct;

namespace ModelDesigner { namespace NodeSet2Import {
	class UaNodeSet2Importer;
}
}

#ifdef __cplusplus
extern "C"
{
#endif

/*! Initializes the NodeSet2 component. */
MODELDESIGNER_EXPORT void MODELDESIGNER_CALL MCNodeSet2ImportInitialize();

/*! Uninitializes the NodeSet2 component. */
MODELDESIGNER_EXPORT void MODELDESIGNER_CALL MCNodeSet2ImportUninitialize();

/*! Parses a node set XML file and imports the node set into the addresspace of the dataFEED OPC UA C++ Server & Client SDK.
*
* @param xmlFilePath				The path of the XML node set file to import.
* @param apiObjectCreationOption	Defines whether to create an API object for imported nodes directly after they were imported or to create them only on demand.
* @param pGlobalExtensions			A pointer to where a string array can be allocated, to return the global extensions of the node set file. The parameter can be NULL.
* @param pGlobalExtensionsCount		A pointer to return the amount of extensions within @p pGlobalExtensions.
*									The parameter can be NULL. The allocated array and strings have to be freed by the caller.
* @param pNodeSetVerion				A pointer to a string to return the version of the imported node set.
*									The parameter can be NULL. The allocated string has to be freed by the caller.
* @param pLastModified				A pointer to return the date and time of the last modification of the imported node set. The parameter can be NULL. */
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCNodeSet2ImportLoadNodeSetXmlFile(const OTChar* xmlFilePath,
	EnumApiObjectCreation apiObjectCreationOption,
	XmlElementStruct** pGlobalExtensions, OTUInt32* pGlobalExtensionsCount,
	XmlElementStruct** pModels, OTUInt32* pModelsCount,
	OTChar** pNodeSetVersion,
	DateTimeStruct* pLastModified);

MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCNodeSet2ImportLoadNodeSetFromBuffer(const char* xmlBuffer,
	const OTChar* xmlFilePath, // for error output only
	EnumApiObjectCreation apiObjectCreationOption,
	XmlElementStruct** pGlobalExtensions, OTUInt32* pGlobalExtensionsCount,
	XmlElementStruct** pModels, OTUInt32* pModelsCount,
	OTChar** pNodeSetVersion,
	DateTimeStruct* pLastModified);

MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCNodeSet2ImportLoadNodeSet(
	ModelDesigner::NodeSet2Import::UaNodeSet2Importer &nodeSetImporter,
	EnumApiObjectCreation apiObjectCreationOption,
	XmlElementStruct** pGlobalExtensions, OTUInt32* pGlobalExtensionsCount,
	XmlElementStruct** pModels, OTUInt32* pModelsCount,
	OTChar** pNodeSetVersion,
	DateTimeStruct* pLastModified);

MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetNodeClass(void* otbHandle, EnumNodeClass* pNodeClass);
MODELDESIGNER_EXPORT NodeIdStruct* MODELDESIGNER_CALL MCXmlParserContextGetNodeIdHandle(void* otbHandle);
MODELDESIGNER_EXPORT QualifiedNameStruct* MODELDESIGNER_CALL MCXmlParserContextGetBrowseNameHandle(void* otbHandle);
MODELDESIGNER_EXPORT LocalizedTextStruct* MODELDESIGNER_CALL MCXmlParserContextGetDescriptionHandle(void* otbHandle);
MODELDESIGNER_EXPORT LocalizedTextStruct* MODELDESIGNER_CALL MCXmlParserContextGetDisplayNameHandle(void* otbHandle);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetWriteMask(void* otbHandle, OTUInt32* pWriteMask);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetUserWriteMask(void* otbHandle, OTUInt32* pUserWriteMask);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetReferenceHandles(void* otbHandle, OTUInt32* pReferenceCount, void*** ppReferences);
MODELDESIGNER_EXPORT NodeIdStruct* MODELDESIGNER_CALL MCXmlParserContextGetParentNodeIdHandle(void* otbHandle);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetEventNotifier(void* otbHandle, OTUInt8* pEventNotifier);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextContainsNoLoops(void* otbHandle, bool* pContainsNoLoops);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextIsAbstract(void* otbHandle, bool* pIsAbstract);
MODELDESIGNER_EXPORT ValueStruct* MODELDESIGNER_CALL MCXmlParserContextGetValueHandle(void* otbHandle);
MODELDESIGNER_EXPORT NodeIdStruct* MODELDESIGNER_CALL MCXmlParserContextGetDataTypeHandle(void* otbHandle);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetValueRank(void* otbHandle, OTInt32* pValueRank);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetArrayDimensionsHandle(void* otbHandle, OTUInt32* pArrayDimensionsCount, OTUInt32** ppArrayDimensions);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetAccessLevel(void* otbHandle, OTUInt8* pAccessLevel);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetUserAccessLevel(void* otbHandle, OTUInt8* pUserAccessLevel);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextGetMinimumSamplingInterval(void* otbHandle, double* pMinimumSamplingInterval);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextIsHistorizing(void* otbHandle, bool* pIsHistorizing);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextIsSymmetric(void* otbHandle, bool* pIsSymmetric);
MODELDESIGNER_EXPORT LocalizedTextStruct* MODELDESIGNER_CALL MCXmlParserContextGetInverseNameHandle(void* otbHandle);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextIsExecutable(void* otbHandle, bool* pIsExecutable);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCXmlParserContextIsUserExecutable(void* otbHandle, bool* pIsUserExecutable);

MODELDESIGNER_EXPORT ExpandedNodeIdStruct* MODELDESIGNER_CALL MCReferenceStructGetNodeIdHandle(void* otbHandle);
MODELDESIGNER_EXPORT ExpandedNodeIdStruct* MODELDESIGNER_CALL MCReferenceStructGetReferenceTypeHandle(void* otbHandle);
MODELDESIGNER_EXPORT EnumModelDesignerStatus MODELDESIGNER_CALL MCReferenceStructIsForward(void* otbHandle, bool* pIsForward);


#ifdef __cplusplus
}
#endif

#endif // MC_NODESET2IMPORT_H
