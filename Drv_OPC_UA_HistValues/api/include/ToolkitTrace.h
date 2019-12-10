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

#ifndef TRACE_H
#define TRACE_H
#include "Base.h"
#include "Enums.h"
#include "Callbacks.h"

namespace SoftingOPCToolbox5
{
	/*! Callback function pointer to receive log messages.
	* @param timeStamp	A string containing the local time when the log was created
	* @param traceLevel	A string describing the severity of the log
	*					The string is the value representation of EnumTraceLevel
	* @param threadId	The id of the thread, where the log was created
	* @param traceGroup	A string describing the group, where the log was created
	*					The string is the value representation of EnumTraceGroup
	* @param location	The file and line number of the log
	* @param message	The message of the log */
	typedef void (OTAPI_CALL *CB_OnLogMessage)(const tstring& timeStamp,
		const tstring& traceLevel,
		OTUInt32 threadId,
		const tstring& traceGroup,
		const tstring& location,
		const tstring& message);

	/*! Trace class that can be used from the user implementation to add items into the trace and also for configuring
	* the trace output.
	*
	* The trace output can be filtered by the different masks (see attributes of this class). Each bit in such
	* a mask represents a source (e.g. the FoundationStack is such a source).
	* The user application can use the unused bits for custom filter issues. */
	class TBC_EXPORT Trace
		: public Base
	{
	public:
		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		Trace(TBHandle otbHandle);

	protected:
		/*! For internal use only */
		Trace(bool suppressCoreInstanceCreate);

	public:
		/*! Destructor */
		virtual ~Trace();

		/////////////////////////////////////////////////////////////////////////
		// Methods of class Trace
		/////////////////////////////////////////////////////////////////////////

		/*! Writes a line into the SDK trace. The line will appear with the given group and level information. */
		void writeLine(EnumTraceLevel level, EnumTraceGroup group, const tstring& message, const tstring& objectID);

		/*! Stops the trace output. */
		void stop();

		/*! Enables logging to a file.
		*
		* @param file			The file name used for tracing. The file name is modified by basename_n.ext for backup
		* @param maxFileSize	If a file exceeds this size the actual file is renamed to the next backup name
		* @param maxBackups		The maximal number of backup files. If this number is exceeded the oldest backup file is deleted.
		* @param bufferSize		The size of a memory buffer in bytes. The trace information is stored in memory up to this buffer size.
		*						Once the buffer is full the content is flushed to the file.
		*						buffer size 0 means system dependent default value (usually 4 kB) */
		EnumStatusCode enableFileLogging(const tstring& file, OTUInt32 maxFileSize, OTUInt32 maxBackups, OTUInt32 bufferSize);

		/*! Disables logging to a file. */
		void disableFileLogging();

		/*! Enables logging to a TCP log listener. */
		EnumStatusCode enableTcpLogging(const tstring& host, unsigned short port, OTUInt32 maxQueueSize);

		/*! Disables logging on TCP. */
		void disableTcpLogging();

		/*! Writes a line into the trace (depending on the given levels) with a source file information (see parameters). */
		void writeSourceLine(EnumTraceLevel level, EnumTraceGroup group, const tstring& message, const tstring& file, OTUInt32 line);

		/*! Enables the trace filter level for a given group (or set of groups). */
		void enableTraceLevel(EnumTraceGroup groups, EnumTraceLevel level);

		/*! Removes the trace filter level for a given group (or set of groups). */
		void disableTraceLevel(EnumTraceGroup groups, EnumTraceLevel level);

		/*! Enables logging to stdout (console). */
		EnumStatusCode enableStdOutLogging();

		/*! Enables logging to stderr (error console). */
		EnumStatusCode enableStdErrLogging();

		/*! Disables logging to stdout (console). */
		void disableStdOutLogging();

		/*! Disables logging to stderr (error console). */
		void disableStdErrLogging();

		/*! Enables logging to the callback.
		* @param callback Pointer to a function or static method, where the logs shall be reported.
		* @note	Only one callback can be registered, every further registration replaces the previous registered callback
		*		Within the callback, no calls to the SDK are allowed, this may lead
		*		to an endless recursion or a deadlock!
		* @see CB_OnLogMessage */
		EnumStatusCode enableCallbackLogging(CB_OnLogMessage callback);

		/*! Disables logging to the callback */
		void disableCallbackLogging();

		// get instance of static object
		/*! Returns the singleton instance */
		static ObjectPointer<Trace> instance();
		/*! @overload */
		static ObjectPointer<const Trace> constInstance();

		/////////////////////////////////////////////////////////////////////////
		// Attributes of class Trace
		/////////////////////////////////////////////////////////////////////////

		/*! Returns the name of the trace output file. */
		tstring getFileName() const;

		/*! Returns the maximum trace file size for a single file. */
		OTUInt32 getFileMaxSize() const;

		/*! Returns the maximum number of trace file backups. */
		OTUInt32 getMaximumBackups() const;

		/*! Returns the socket port for TCP based trace clients. */
		OTUInt32 getSocketPort() const;
		/*! Sets the socket port for TCP based trace clients.
		* By default this value is null.
		* If not null the trace writes any message to connected trace clients. */
		EnumStatusCode setSocketPort(OTUInt32 socketPort);

	private:
		/*! Use instance() to get a Trace instance */
		Trace();
		/*! For internal use only */
		void initMembers();
	};
	typedef ObjectPointer<Trace> TracePtr;
	typedef ObjectPointer<const Trace> TraceConstPtr;
} // toolbox namespace end

#endif	// TRACE_H
