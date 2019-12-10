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

#ifndef SERVERCONTINUATIONPOINT_H
#define SERVERCONTINUATIONPOINT_H

#include "Base.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! Base class for all continuation points.
		*
		* Some OPC UA services (e.g. HistoryRead to retrieve historical values from a variable)
		* allow clients to restrict the maximum number of results per request. If a server has more
		* results to deliver, it returns a continuation point along with the results which the client
		* can use to request more results. A server application must be able to deliver the remaining
		* result with context information stored within a continuation point. */
		class TBC_EXPORT ContinuationPoint
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			ContinuationPoint(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			ContinuationPoint(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~ContinuationPoint();

			/*! Returns the previously provided context information.
			*
			* @param [out] ppContext	The address of a pointer to point to the context information
			* @return The length of the context information in bytes
			*
			* @note The given pointer will point to the internal storage of the context information,
			*       the context information itself won't be copied.
			* @see setContext() */
			OTUInt32 getContext(void** ppContext) const;
			/*! Sets the application-specific context information to be able to continue
			* the request. The content of @p context is copied to an internal storage.
			*
			* @param context		A pointer to the context information
			* @param contextLength	The length of the context information in bytes */
			EnumStatusCode setContext(const void* context, OTUInt32 contextLength);

			/*! Returns the type of the continuation point.
			*
			* @return The continuation point type */
			virtual EnumContinuationPointType getType() const = 0;

		protected:
			// Continuation points are provided by the SDK core
			ContinuationPoint();

			/*! Forbid use assignment operator */
			ContinuationPoint& operator=(const ContinuationPoint&);
			/*! Forbid use of copy constructor */
			ContinuationPoint(const ContinuationPoint&);
		};
		typedef ObjectPointer<ContinuationPoint> ContinuationPointPtr;
		typedef ObjectPointer<const ContinuationPoint> ContinuationPointConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERCONTINUATIONPOINT_H
