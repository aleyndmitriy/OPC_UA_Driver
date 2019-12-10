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

#ifndef TOOLBOX_H
#define TOOLBOX_H

// headers required for the toolbox
#include "ToolkitConfig.h"
#include "OSCompat.h"
#include "OTExports.h"
#include "OTTypes.h"
#include "ModelCompiler/ErrorEnums.h"
#include "Enums.h"
#include "ByteString.h"
#include <vector>
#include "Creator.h"
#include "ApiMacros.h"


namespace SoftingOPCToolbox5
{
	class Creator;

#ifdef SOOS_WINDOWS
#define API_CALL __stdcall
#else
#define API_CALL
#endif
	/*! Prototype of a memory function that provides a block of memory
	*
	* Parameters:
	*		sizeInByte: the requested block size in byte
	*
	* Return: The pointer to memory block (NULL if no block can be provided)
	*
	* @note An application can implement a function for this prototype and provide the function to the loadToolbox. */
	typedef void* (API_CALL *Memory_Alloc_Func)(size_t /* sizeInByte */);

	/*! Prototype of a memory function that changes the size of a provided memory block
	*
	* Parameters:
	*		oldBlock:	A block of memory previously provided by the Memory_Alloc_Func function.
	*					The oldBlock can be NULL, i.e. a completely new block has to be provided.
	*		sizeInByte: The new requested block size in byte
	*
	* Return: The pointer to memory block (NULL if no block can be provided)
	*
	* @note An application can implement a function for this prototype and provide the function to the loadToolbox. */
	typedef void* (API_CALL *Memory_ReAlloc_Func)(void* /* oldBlock */, size_t /* sizeInByte */);

	/*! Prototype of a memory function that releases a block of memory
	*
	* Parameters:
	*		oldBlock:	A block of memory previously provided by the Memory_Alloc_Func function.
	*					The oldBlock can be NULL.
	*
	* Return:
	*
	* @note An application can implement a function for this prototype and provide the function to the loadToolbox. */
	typedef void (API_CALL *Memory_Free_Func)(void* /* oldBlock */);

	/*! Cleans up any thread local SSL data. This should be used in UA Client threads. */
	void TBC_EXPORT cleanupUserThreadState();

	/*! Adds new entropy to the pseudo-random-number-generator of openssl. */
	EnumStatusCode TBC_EXPORT seedPrngState(const IByteString& entropy);

	/*! Initialize the toolbox with the given Creator and optional memory management function.
	*
	* This must be the first call from any application using the SDK.
	*
	* @param pCreator	The (sub-classed) Creator instance that is used as object factory.
	*					If this parameter is omitted (i.e. NULL), the default
	*					Creator will be used.
	* @param pAlloc		A function that provides a block of memory.
	*					If this parameter is omitted (i.e. NULL), the process heap will be used.
	* @param pRealloc	A function that changes the size of a provided memory block.
	*					If this parameter is omitted (i.e. NULL), the process heap will be used.
	* @param pFree		A function that releases a block of memory.
	*					If this parameter is omitted (i.e. NULL), the process heap will be used.
	* @param spawnThreadPerSession The UA stack can spawn a new thread for every session (secure channel) or handle all sessions within one thread.
	*                   Some operating systems may have problems, if threads are very often spawned and joined.
	*					If this parameter is omitted the default is
	*                   @li false (VxWorks).
	*                   @li true (Windows, Linux)
	*
	* @return			EnumStatusCode_Good if loadToolbox succeeds.
	*
	* @note Either none of all of the memory functions have to be provided. */
	EnumStatusCode TBC_EXPORT loadToolbox(Creator* pCreator=NULL,
		Memory_Alloc_Func pAlloc = NULL, Memory_ReAlloc_Func pRealloc = NULL, Memory_Free_Func pFree = NULL,
		bool spawnThreadPerSession =
#ifdef SODEVENV_VXWORKS
		false
#else
		true
#endif
		);

	/*! Stop the toolbox library. That must be the final call from any using application */
	EnumStatusCode TBC_EXPORT unloadToolbox();

	/*! @deprecated	Please override Creator::createApplication() to create an instance
	*				of your derived Application class. This method will be removed.
	*
	* Replaces the application instance which has been constructed by
	* Creator::createApplication() with the given instance. */
	DEPRECATED(EnumStatusCode TBC_EXPORT registerApplication(Application* pApplication));

	/*! @deprecated Please provide the Creator with loadToolbox()
	*
	* Registers the given @p pCreator as default object factory. */
	DEPRECATED(EnumStatusCode TBC_EXPORT registerCreator(Creator* pCreator));
}

#endif	// TOOLBOX_H
