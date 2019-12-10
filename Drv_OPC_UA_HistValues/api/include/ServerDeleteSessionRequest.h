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

#ifndef SERVER_DELETE_SESSION_REQUEST_H
#define SERVER_DELETE_SESSION_REQUEST_H

#include "Base.h"
#include "Enums.h"
#include "ServerDataRequest.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// Forward declarations
		class Session;
		typedef ObjectPointer<Session> SessionPtr;
		typedef ObjectPointer<const Session> SessionConstPtr;

		/*! The DeleteSessionRequest class encapsulates client requests for deletion of sessions.
		*
		* This request has no status since the request shall always succeed */
		class TBC_EXPORT DeleteSessionRequest
			: public DataRequest
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			DeleteSessionRequest(TBHandle otbHandle);

			/*! Destructor */
			virtual ~DeleteSessionRequest();

			/*! Returns the session that shall be deleted. */
			SessionPtr getSession() const;

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			// Requests are always created by the SDK core.
			DeleteSessionRequest();

			/*! Forbid use assignment operator */
			DeleteSessionRequest& operator=(const DeleteSessionRequest&);
			/*! Forbid use of copy constructor */
			DeleteSessionRequest(const DeleteSessionRequest&);
		};
		typedef ObjectPointer<DeleteSessionRequest> DeleteSessionRequestPtr;
		typedef ObjectPointer<const DeleteSessionRequest> DeleteSessionRequestConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVER_DELETE_SESSION_REQUEST_H
