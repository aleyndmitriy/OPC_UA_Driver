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

#ifndef SERVER_DIAGNOSTICS_H
#define SERVER_DIAGNOSTICS_H
#include "Base.h"
#include "Enums.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class controls the collection of diagnostic information in the server.
		* Diagnostic information is exposed to clients through the Server object in the
		* server's address space.
		*
		* By default, collecting of diagnostic information is disabled and can only
		* be enabled by a server application.
		*
		* @note	Enabling diagnostics will increase the server load. */
		class TBC_EXPORT Diagnostics
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory. */
			Diagnostics(TBHandle otbHandle);

		public:
			/*! Destructor */
			virtual ~Diagnostics();

			/*! Returns the global Diagnostics instance */
			static ObjectPointer<Diagnostics> instance();
			/*! @overload */
			static ObjectPointer<const Diagnostics> constInstance();

			/*! Returns whether the server collects diagnostic information. */
			bool isEnabled() const;
			/*! Enables or disables collecting of diagnostic information in the server.
			* Diagnostics are disabled by default.
			*
			* @param enable	If true, the server collects diagnostic information. */
			EnumStatusCode setEnabled(bool enable);

			/*! Allows clients to enable or disable collecting of diagnostic information.
			*
			* @param writable	If true, clients may enable or disable diagnostics by writing
			*					to the "EnabledFlag" property of the diagnostics object in the address space. */
			EnumStatusCode setEnabledFlagWritable(bool writable);

			/*! Returns the interval (in milliseconds) that the server uses
			* to update diagnostic information in the address space. */
			OTUInt32 getUpdateInterval() const;
			/*! Sets the interval (in milliseconds) that the server uses to
			* update diagnostic information in the address space.
			* The default update interval is 5000ms. Please refer to Application for reading
			* or setting minimum and maximum values for this parameter.
			*
			* @param updateInterval The update interval
			*
			* @see Application::setMinDiagnosticsUpdateInterval() Application::setMaxDiagnosticsUpdateInterval() */
			EnumStatusCode setUpdateInterval(OTUInt32 updateInterval);

			/*! Allows clients to change the update interval for diagnostic information.
			*
			* @param writable If true, clients may change the update interval for diagnostic information */
			EnumStatusCode setUpdateIntervalWritable(bool writable);

		private:
			/*! For internal use only */
			void initMembers();

			/*! Diagnostics instance is created by the SDK core */
			Diagnostics();
			/*! Forbid use assignment operator */
			Diagnostics& operator=(const Diagnostics&);
			/*! Forbid use of copy constructor */
			Diagnostics(const Diagnostics&);
		};
		typedef ObjectPointer<Diagnostics> DiagnosticsPtr;
		typedef ObjectPointer<const Diagnostics> DiagnosticsConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVER_DIAGNOSTICS_H
