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

#ifndef API_MACROS
#define API_MACROS

/* Disable warning C4251: class 'type' needs to have dll-interface to be used by clients of class 'type2'
* which is displayed for all class members that are exported across DLL boundaries and which
* may cause access violations when being accessed from a different DLL. It is safe to ignore this
* warning when the API ensures that the DLL client cannot access the member (because it is private). */
#ifdef _MSC_VER
	#define PRIVATE_EXPORTED_STL_CONTAINER(CONTAINER)	__pragma(warning(push))				\
														__pragma(warning(disable:4251))		\
														CONTAINER;							\
														__pragma(warning(pop))
#else
	#define PRIVATE_EXPORTED_STL_CONTAINER(CONTAINER)	CONTAINER;
#endif

#ifdef _MSC_VER
#define PRIVATE_EXPORTED_STL_CONTAINER2(CONTAINER1, CONTAINER2)	__pragma(warning(push))				\
	__pragma(warning(disable:4251))		\
	CONTAINER1, CONTAINER2;							\
	__pragma(warning(pop))
#else
#define PRIVATE_EXPORTED_STL_CONTAINER2(CONTAINER1, CONTAINER2)	CONTAINER1, CONTAINER2;
#endif

/* The DEPRECATED macro allows methods to be declared as deprecated. Applying this macro
* to methods will cause the compiler to emit a warning whenever the affected
* method is used.
*
* The BEGIN_IGNORE_DEPRECATED and END_IGNORE_DEPRECATED macros allows the API to use
* deprecated code. All function definitions that are enclosed between BEGIN and END will
* cause the compiler to not emit any deprecation warning for their use of deprecated methods. */
// Disabling single GCC warnings is only possible with GCC version 4.2 and above
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
	#define STRINGIFY_ARGS(x)			#x
	#define DEPRECATED(func)			func __attribute__ ((deprecated))
	#define BEGIN_IGNORE_DEPRECATED()	_Pragma(STRINGIFY_ARGS(GCC diagnostic ignored "-Wdeprecated-declarations"))
	#define END_IGNORE_DEPRECATED()		_Pragma(STRINGIFY_ARGS(GCC diagnostic warning "-Wdeprecated-declarations"))
#elif defined(_MSC_VER)
	#define DEPRECATED(func)			__declspec(deprecated) func
	#define BEGIN_IGNORE_DEPRECATED()	__pragma(warning(push))				\
										__pragma(warning(disable:4996))
	#define END_IGNORE_DEPRECATED()		__pragma(warning(pop))
#else
	// Note: You will not receive warnings for deprecated methods with this compiler
	#define DEPRECATED(func) func
	#define BEGIN_IGNORE_DEPRECATED()
	#define END_IGNORE_DEPRECATED()
#endif

#endif // API_MACROS_H
