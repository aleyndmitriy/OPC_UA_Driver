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

#ifndef SERVERSESSION_H
#define SERVERSESSION_H
#include "Base.h"
#include "Enums.h"
#include "NodeId.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Server
	{
		class ContinuationPoint;
		typedef ObjectPointer<ContinuationPoint> ContinuationPointPtr;
		typedef ObjectPointer<const ContinuationPoint> ContinuationPointConstPtr;
		class Subscription;
	}

	namespace Server
	{
		/*! The Session object represents a connection of a client to this server.
		*
		* An object of this type is created when a client successfully invokes the "CreateSession" service. */
		class TBC_EXPORT Session
			: public Base
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Session(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			Session(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Session();

			/////////////////////////////////////////////////////////////////////////
			// Methods of class Session
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the subscriptions that belong to this session */
			std::vector<ObjectPointer<Server::Subscription> > getSubscriptions();
			/*! @overload */
			std::vector<ObjectPointer<const Server::Subscription> > getSubscriptions() const;

			/////////////////////////////////////////////////////////////////////////
			// Attributes of class Session
			/////////////////////////////////////////////////////////////////////////

			/*! Returns the ID of the session. */
			NodeId getId() const;

			/*! Returns a human readable string that identifies the session. The server exposes this name and
			* the SessionId in its address space for diagnostic purposes. The client should
			* provide a name that is unique for the instance of the client. */
			tstring getName() const;

			/*! Returns the session timeout in milliseconds.
			*
			* @see setTimeout() */
			double getTimeout() const;
			/*! Sets the (revised) session timeout in milliseconds.
			*
			* The server should attempt to honor the client request for this parameter,
			* but may negotiate this value up or down to meet its own constraints.
			*
			* @param revisedTimeout		The revised timeout in milliseconds. The provided value is rounded
			*							up to the smallest integral value that is not less revisedTimeout.
			*
			* @note	This method may only be called inside the Server::Endpoint::onCreateSession() callback method
			*		in order to revise the value requested by the client. */
			EnumStatusCode setTimeout(double revisedTimeout);


			/*! Returns the 0-based index of the user group to which the user of
			* this session belongs to.
			*
			* @see Endpoint::onAuthenticateUser() Application::setAccessPattern() */
			OTUInt32 getUserGroupIndex() const;

			/*! Returns the ID (user name) of the user that established the session.
			*
			* If the client has used an EnumUserTokenType_UserName authentication, here the user name is available.
			* In all other cases an empty string is returned.
			*
			* @return username */
			tstring getUserClientId() const;

			/*! Return the ordered list of preferred locales.
			* The client passes this list to the server to retrieve the best matching localized text value in client requests.
			*
			* @param[out] preferredLocales	The list of preferred locales */
			EnumStatusCode getPreferredLocales(std::vector<tstring>* preferredLocales) const;

			/*! Returns the peer information of the client in format "<protocol>://<ip>:<port>". */
			tstring getClientPeerInfo() const;

			/*! Returns the IP address of the connected OPC UA client. */
			tstring getClientIpAddress() const;

			/*! Returns the security mode that is used for messages passed via the SecureChannel. */
			EnumMessageSecurityMode getMessageSecurityMode() const;

			/*! Returns the security policy that is used for messages passed via the SecureChannel. */
			tstring getSecurityPolicy() const;

			//////////////////////////////////////////////////////////////////////////
			// Callbacks
			//////////////////////////////////////////////////////////////////////////

			/*! This callback method is called before a continuation point is deleted. It allows
			* the server application to clean-up any application-specific resources reserved
			* for continuing a request.
			*
			* @param continuationPointType	The type of continuation point which is about to be deleted
			* @param continuationPoint		The continuation point which is about to be deleted */
			virtual void onDeleteContinuationPoint(EnumContinuationPointType continuationPointType, ContinuationPointPtr continuationPoint);

			/*! Register nodes which are known to used repeatedly.
			* It allows Servers to set up anything needed so that the access operations will be more efficient.
			* This callback notifies that the client registers nodes for repeated use.
			* If no optimization is performed for registered nodes, no action is needed here.
			* All registered nodes will be unregistered - latest on closing the session
			*
			* @param	registeredNodes	Node IDs to be registered */
			virtual EnumStatusCode onRegisterNodes(const std::vector<NodeId>& registeredNodes);

			/*! Unregisters nodes which are known to used repeatedly.
			*
			* @see onRegisterNodes() */
			virtual EnumStatusCode onUnregisterNodes(const std::vector<NodeId>& registeredNodes);

			/*! Callback that is called when the client cancels an asynchronous transaction.
			*
			* The default implementation generates an audit event (if enabled).
			* If the application is able to abort a running asynchronous transaction, it can override this callback and implement its own actions.
			*
			* @param	result				The status code of the request
			* @param	clientRequestHandle	Request handle assigned by the client for one or more transactions
			* @param	auditEntryId		The human readable ID given by the client request.
			*
			* @note It is highly recommended that an overwritten callback shall call the callback of the base class.
			* @note	Please note that two or more transactions may share the same client request handle. */
			virtual void onTransactionCancelled(EnumStatusCode result, OTUInt32 clientRequestHandle, tstring auditEntryId);

			/*! Registers a cookie as an internal file handle.
			*
			* A server application can invoke this method, if the file FileType methods are overwritten.
			* Session object takes care that a unique UA file handle is provided and that the file is closed when the session is closed.
			*
			* @param fileObject		The object representing the file
			* @param cookie			A cookie provided by the application. It can be retrieved via the UA file handle
			* @param uaFileHandle	The UA file handle, used in UA methods
			*
			* @note	If an application uses the SDK implemented file operations, this method is not needed to be invoked. */
			EnumStatusCode registerOpenFileHandle(ObjectPointer<Server::File> fileObject, void* cookie, OTUInt32* uaFileHandle);

			/*! Unregisters a file handle.
			*
			* SDK will remove this UA file handle from its list of open files.
			*
			* @param fileObject		The object representing the file
			* @param uaFileHandle	The UA file handle, used in UA methods */
			EnumStatusCode unregisterFileHandle(ObjectPointer<const Server::File> fileObject, OTUInt32 uaFileHandle);

			/*! Get the registered cookie back from the session.
			*
			* @param fileObject				The object representing the file
			* @param uaFileHandle			The UA file handle, used in UA methods
			* @param pInternalFileHandle	The registered internal file handle */
			EnumStatusCode getFileHandle(ObjectPointer<const Server::File> fileObject, OTUInt32 uaFileHandle, void** pInternalFileHandle);

		private:
			/*! For internal use only */
			void initMembers();

			/*! Sessions are always created by the SDK core. */
			Session();
			/*! Forbid use assignment operator */
			Session& operator=(const Session&);
			/*! Forbid use of copy constructor */
			Session(const Session&);
		};
		typedef ObjectPointer<Session> SessionPtr;
		typedef ObjectPointer<const Session> SessionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERSESSION_H
