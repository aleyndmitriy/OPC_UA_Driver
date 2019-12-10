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

#ifndef CLIENTREDUNDANTSESSION_H
#define CLIENTREDUNDANTSESSION_H
#if TB5_CLIENT

#include "Base.h"
#include "WriteValue.h"
#include "ReadValueId.h"
#include "ViewDescription.h"
#include "BrowseDescription.h"
#include "BrowseResult.h"
#include "BrowsePath.h"
#include "BrowsePathResult.h"
#include "CallMethodRequest.h"
#include "CallMethodResult.h"
#include "NodeId.h"
#include "ReadRawDetails.h"
#include "ReadProcessedDetails.h"
#include "ReadEventDetails.h"
#include "HistoryReadValueId.h"
#include "HistoryReadDataResult.h"
#include "HistoryReadEventResult.h"
#include "NodeTypeDescription.h"
#include "QueryDataSet.h"
#include "ContentFilterResult.h"
#include "ParsingResult.h"
#include "InnerUserIdentityToken.h"
#include "DiagnosticInfo.h"
#include "Constants.h"
#include "IPkiStoreConfiguration.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class DataTypeDescription;
	typedef ObjectPointer<const DataTypeDescription> DataTypeDescriptionConstPtr;

	namespace Client
	{
		class RedundantSubscription;
		typedef ObjectPointer<RedundantSubscription> RedundantSubscriptionPtr;
		typedef ObjectPointer<const RedundantSubscription> RedundantSubscriptionConstPtr;

		class CertificateChangeTransaction;
	}

	namespace Client
	{
		class RedundantSession;
		typedef ObjectPointer<RedundantSession> RedundantSessionPtr;
		typedef ObjectPointer<const RedundantSession> RedundantSessionConstPtr;

		/*! The RedundantSession class represents a connection to an array of redundant servers.
		*
		* One of the servers acts as primary server, the other servers act as secondary (back-up) servers.
		* The role of each server in an array of redundant servers is determined by the "ServiceLevel" variable
		* which each server exposes in its address space. Each "ServiceLevel" variable contains a value
		* ranging from 0 to 255. The server with the highest service level has the role of the primary server.
		* The actual service level of all servers is reported by RedundantSession::onServiceLevelChanged().
		*
		* Upon a failure of the primary server, the client may perform a switchover to a secondary server
		* (see RedundantSession::switchoverAsync()). From the perspective of the client, the switchover changes
		* the role of the designated server from 'secondary' to 'primary'.
		*
		* In order to connect to an array of redundant servers, the application has to create a RedundantSession object,
		* configure it by setting the server URLs, security parameters, etc., and call the connect() method.
		* Please note that redundant session need to be registered at the Application object (see Application::addRedundantSession()).
		*
		* @note	Unless specified otherwise, the session's security- and connection-related attributes cannot be modified
		*		while the session is connected. */
		class TBC_EXPORT RedundantSession
			: public Base
		{
		public:
			/*! Constructs a new RedundantSession instance. */
			static RedundantSessionPtr create();

		protected:
			/*! Default Constructor */
			RedundantSession();

			/*! For internal use only */
			RedundantSession(bool suppressCoreInstanceCreate);

		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory. */
			RedundantSession(TBHandle otbHandle);

			/*! Destructor */
			virtual ~RedundantSession();

			/*! Returns the endpoint URLs of the redundant servers.
			*
			* @param	urls	The URLs of the server endpoints
			*
			* @see	setServerInformation() */
			EnumStatusCode getUrls(std::vector<tstring>& urls) const;

			/*! Returns the configured server certificates.
			*
			* @see	setServerInformation() */
			EnumStatusCode getServerCertificates(std::vector<ByteString>& serverCertificates) const;

			/*! Sets the endpoint URLs and application instance certificates of the redundant servers.
			* The provided number of endpoints URLs must match the number of server certificates.
			*
			* The application can call this method while the redundant session is connected or disconnected.
			* If the redundant session is already connected, connections with servers whose endpoint URL
			* has been removed by this call will be terminated.
			*
			* The server certificate can be obtained by the client
			* @li manually: by copying the certificate file and loading it into a ByteString
			* @li automatically: by using Application::getEndpointsFromServer()
			*
			* @param	urls				The endpoint URLs of the redundant servers which are to be connected
			* @param	serverCertificates	The server certificates belonging to the servers specified by @p urls
			*
			* @note	Please note that the provided endpoint URLs and server certificates must match in size.
			*		Each endpoint URL must be unique within the provided vector of URLs. */
			EnumStatusCode setServerInformation(const std::vector<tstring>& urls, const std::vector<ByteString>& serverCertificates);

			/*! Returns the actual configured setting for hostname resolution.
			*
			* @see setHostnameResolution() */
			bool getHostnameResolution() const;

			/*! Sets the configuration for hostname resolution.
			*
			* The hostname part of the URL can be resolved to IPv4 or IPv6 address.
			* If the setting is true, the host name resolving prefers IPv4 address of the hostname.
			* Only if no IPv4 address is found, then an IPv6 address is used and vice versa.
			*
			* @param preferIPv4Resolution	The setting whether the session prefers IPv4 or IPv6. Default is true (IPv4).
			*
			* @note If a specific IP address is provided in the URL (e.g. "127.0.0.1" or "[::0]") the setting is ignored and the given IP address is used directly. */
			EnumStatusCode setHostnameResolution(bool preferIPv4Resolution);

			/*! Returns the human readable string that identifies the session.
			*
			* @see	setName() */
			tstring getName() const;
			/*! Sets the human readable string that identifies the session. The server expose this name and
			* the SessionId in its AddressSpace for diagnostic purposes. The client should
			* provide a name that is unique for the instance of the client.
			* If this parameter is not specified, the servers shall assign a name for the session.
			*
			* @param name	The name of the session.
			*
			* @note Changed name while session is connected will have no immediate effect.
			*       Please use disconnect() / connect() to use the new name. */
			EnumStatusCode setName(const tstring& name);

			/*! Returns the actually configured session timeout.
			*
			* @see	setSessionTimeout() */
			double getSessionTimeout() const;
			/*! Sets the requested maximum number of milliseconds that a session should remain open without activity.
			* If the client fails to issue a communication within this interval, then the server shall automatically terminate the
			* session. Any further communication using this session is no longer possible until client re-connects the session.
			*
			* The server can revise that timing and return the revised value to the client, which might differ from
			* the initial value requested by the client. The revised value can be obtained
			* by getRevisedSessionTimeout() after the connect() operation has succeeded.
			*
			* The default value is 60000 (1 min.). If a different value is required it must be set before connecting
			* the session.
			*
			* @param sessionTimeout		Timeout in milliseconds
			*
			* @note Changed timeout while session is connected will have no immediate effect.
			*       Please use disconnect() / connect() to use the new timeout. */
			EnumStatusCode setSessionTimeout(double sessionTimeout);

			/*! Returns the maximum number of milliseconds that a session remains open without activity.
			* The server should attempt to honor the client request for this parameter,
			* but may negotiate this value up or down to meet its own constraints.
			*
			* @param [out]	revisedSessionTimeout	Returns the revised session timeout.
			* @param [in]	redundantServerIndex	The affected server.
			*
			* @see	setSessionTimeout() */
			EnumStatusCode getRevisedSessionTimeout(double& revisedSessionTimeout, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;
			/*! @overload
			* @return	Returns the revised session timeout of the primary server */
			double getRevisedSessionTimeout() const;

			/*! Returns the actual configured message security mode.
			*
			* @see	setSecurityConfiguration() */
			EnumMessageSecurityMode getMessageSecurityMode() const;

			/*! Returns the actual configured security policy.
			*
			* @see	setSecurityConfiguration() */
			tstring getSecurityPolicy() const;

			/*! Gets both the message security and security policy for the session to be established.
			*
			* @see setSecurityConfiguration */
			EnumStatusCode getSecurityConfiguration(EnumMessageSecurityMode &messageSecurityMode, tstring& securityPolicy) const;

			/*! Sets both the message security and security policy for the session to be established.
			* Either both are set to none or both are different from none.
			*
			* @param messageSecurityMode		Desired message security mode
			* @param securityPolicy				The security policy URI
			*									Depending on the security a server may choose from one of the following security policies
			*									which define the algorithms that are used to sign and/or encrypt exchanged messages:
			*									@li	SecurityPolicyUri_None
			*									@li	SecurityPolicyUri_Basic128Rsa15 (deprecated - shall no longer be used)
			*									@li	SecurityPolicyUri_Basic256 (deprecated - shall no longer be used)
			*									@li	SecurityPolicyUri_Basic256Sha256
			*									@li	SecurityPolicyUri_Aes128Sha256RsaOaep
			*									@li	SecurityPolicyUri_Aes256Sha256RsaPss
			*
			* @see setSecurityPolicy() setMessageSecurityMode() EndpointDescription Application::getEndpointsFromServer()
			*
			* @note Changed security configuration while session is connected will have no immediate effect.
			*       Please use disconnect() / connect() to use the new security configuration. */
			EnumStatusCode setSecurityConfiguration(EnumMessageSecurityMode messageSecurityMode, const tstring& securityPolicy);

			/*! Returns the user credentials.
			*
			* @see	setUserIdentityToken() */
			UserIdentityToken getUserIdentityToken() const;
			/*! Sets the user credentials that will be used when connecting the session to the server.
			*
			* The credentials are used to identify the connecting user.
			*
			* @see	setUserSecurityPolicy() EndpointDescription Application::getEndpointsFromServer()
			*
			* @note Changed user credentials while session is connected will have no immediate effect.
			*       Please use disconnect() / connect() or impersonateDifferentUser to use user credentials on server. */
			EnumStatusCode setUserIdentityToken(const IUserIdentityToken* userIdentityToken);

			/*! Returns the user token policy.
			*
			* @see	setUserSecurityPolicy() */
			tstring getUserSecurityPolicy() const;
			/*! Sets the security policy for UserIdentityToken encryption.
			*
			* The server's endpoint shall expose a matching security policy in
			* its UserTokenPolicy of the EndpointDescription.
			*
			* @param	userSecurityPolicy	Security policy for user token encryption.
			*
			* @see	EndpointDescription setUserIdentityToken() Application::getEndpointsFromServer() */
			EnumStatusCode setUserSecurityPolicy(const tstring& userSecurityPolicy);

			/*! Allows to connect to a server, which does not send a nonce for an encrypted user token.
			*
			* @note Enabling this option (ignoring the check) is a security risk and contradicts to the OPC UA specification.
			*       This option shall only be used when dealing with a non compliant server, where the session establishment would fail otherwise.
			*       When allowing empty nonces, then the messages are vulnerable for replay attacks. */
			void ignoreMissingNonce(bool ignoreNonce);

			/*! Returns the actual configured network timeout.
			*
			* @see	setNetworkTimeout() */
			OTUInt32 getNetworkTimeout() const;
			/*! Sets the timeout to use when trying to establish a network connection.
			* The default value will be the default network timeout defined in the Application
			* at the time when this session object was created (see Application::setDefaultNetworkTimeout()).
			*
			* @param networkTimeout		Timeout in milliseconds
			*
			* @note The network timeout is used during establishing a connection only. Changing the timeout on a connected session will have no immediate effect. */
			EnumStatusCode setNetworkTimeout(OTUInt32 networkTimeout);

			/*! Returns the actual configured monitoring interval.
			*
			* @see	setConnectionMonitoringInterval() */
			OTUInt32 getConnectionMonitoringInterval() const;
			/*! Sets the interval for verifying the health of the connection to the servers.
			* The connection monitoring also reads the current service levels of the servers which indicates
			* the ability of the servers to provide its data to the client. The service level is the usual
			* indicator for which server shall be the primary server.
			*
			* This is an extended way to monitor the connection status. It is not dependent on timeouts of
			* physical devices like sockets, but performs a regular communication with the server.
			* If the server does not respond, the connection is treated as broken.
			*
			* If a connection break is recognized, the status of the session changes to 'disconnected'
			* and the onStatusChange() callback is invoked.
			* The default interval for newly created sessions is a property of the Application object.
			* The minimum supported interval is 100ms, typical intervals are 5000ms or 10000ms.
			*
			* Every time a service level changes, the onServiceLevelChanged() callback is called.
			*
			* The interval can be changed independent of the connection status. The changed value is applied immediately.
			*
			* @param	connectionMonitoringInterval	The interval in milliseconds. Setting the value to 0
			*											effectively disables connection monitoring.
			*
			* @see	Application::setDefaultConnectionMonitoringInterval() onStatusChange() onServiceLevelChanged() */
			EnumStatusCode setConnectionMonitoringInterval(OTUInt32 connectionMonitoringInterval);

			/*! Returns the actual configured reconnect interval.
			*
			* @see	setAutoReconnectInterval() */
			OTUInt32 getAutoReconnectInterval() const;
			/*! Sets the interval in which to try a re-connect after a broken connection is recognized.
			*
			* The SDK tries to re-establish the connection in the given interval until the connection
			* has been re-established or the application gives up re-connecting by calling disconnect().
			*
			* Initially the interval is set to 10000 milliseconds. The minimum allowed value is 1000 milliseconds
			* The default interval for newly created sessions is a property of the Application object
			* Typical values are e.g. 5000 ms or 10000 ms.
			*
			* The interval can be changed independent on connection status. The changed value is applied immediately.
			*
			* @param	autoReconnectInterval	The interval in milliseconds between re-establishing trials
			*
			* @see	Application::setDefaultAutoReconnectInterval() */
			EnumStatusCode setAutoReconnectInterval(OTUInt32 autoReconnectInterval);

			/*! Returns the actual configured preferred locales.
			*
			* @see	setPreferredLocales() */
			EnumStatusCode getPreferredLocales(std::vector<tstring>& preferredLocales) const;
			/*! Sets an ordered list of preferred locales.
			* This list is passed to server to retrieve the best matching localized text value in client requests.
			* The preferred locales defined in the Application object are used as default when creating a session.
			*
			* @param	preferredLocales	A vector of preferred locales. Locales are described in LocalizedText.
			*
			* @see Application::setPreferredLocales() LocalizedText
			*
			* @note Changed preferred locales while session is connected will have no immediate effect.
			*       Please use disconnect() / connect() or impersonateDifferentUser (also with same credentials) to use preferred locales on server. */
			EnumStatusCode setPreferredLocales(const std::vector<tstring>& preferredLocales);

			/*! Returns the timeout for a service group.
			*
			* @see setServiceTimeout() */
			OTUInt32 getServiceTimeout(EnumTimeoutGroup group) const;
			/*! Sets the timeout for a specific service groups.
			*
			* If a server does not respond to a service within the timeout a EnumStatusCode_BadTimeout is returned.
			*
			* For a server, this timeout is only a hint and can be used to cancel long running operations to free resources.
			*
			* The timeouts set in the Application object are used as default when creating a session.
			*
			* @param group		A specific timeout group
			* @param timeout	The timeout for this group
			*
			* @see EnumTimeoutGroup for mapping of timeout groups and methods */
			EnumStatusCode setServiceTimeout(EnumTimeoutGroup group, OTUInt32 timeout);

			/*! Returns the index of the server which is currently the primary server.
			*
			* @note	When there is currently no primary server, the value OTRedundantServerIndex_Invalid is
			*		returned. Make sure to not use this special index to specify a single server or to use it as an
			*		index of a returned array. */
			OTUInt32 getPrimaryServerIndex() const;

			/*! Sets the redundant server with the specified index as primary server.
			* Depending on the used redundancy mode, some actions are transferred from the old primary to the new primary,
			* e.g. subscribe the events and data changes on the new primary.
			* The usual location to invoke a switchover is the onServiceLevelChanged() callback where the service levels
			* of all redundant servers are available. The service level describes the ability of the server to provide
			* its data to the client.
			*
			* @note	This method starts an asynchronous action and returns immediately. The completion of the switchover
			*		is reported in the onSwitchoverComplete() callback.
			*		If a bad status code is returned, the asynchronous action won't be executed and onSwitchoverComplete()
			*		won't be called.
			* @see	onSwitchoverComplete() onServiceLevelChanged() */
			EnumStatusCode switchoverAsync(void* requestHandle, OTUInt32 primaryServerIndex);

			/*! Callback for the response to an switchover service. This function must be overridden by the application session instance to handle the notification.
			*
			* @param [in]	requestHandle			A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	result					A status code indicating if the switchover succeeded. A bad status code means that the old primary is still set.
			* @param [in]	connectionStatus		The current connection states to all redundant servers.
			* @param [in]	primaryServerIndex		The index of the new primary server.
			*
			* @see	switchover() */
			virtual void onSwitchoverComplete(void* requestHandle, EnumStatusCode result, const std::vector<bool>& connectionStatus, OTUInt32 primaryServerIndex);

			/*! Gets the configured redundancy support which defines the behavior of the RedundantSession, RedundantSubscription and RedundantMonitoredItem to the secondary servers.
			*
			* @see	setRedundancyMode() EnumRedundancySupport */
			EnumRedundancySupport getRedundancyMode() const;
			/*! Sets the desired redundancy support which defines the behavior of the RedundantSession, RedundantSubscription and RedundantMonitoredItem to the secondary servers.
			* The chosen redundancy mode should be less or equal as the configured redundancy mode of the redundant servers.
			* The currently supported redundancy modes are COLD, WARM and HOT.
			*
			* @see	EnumRedundancySupport */
			EnumStatusCode setRedundancyMode(EnumRedundancySupport redundancyMode);

			/*! Returns the session's connection status.
			*
			* @param [out]	connected				Returns true if the connection to the server session is established and communication is possible.
			*										Returns false if the session is not established.
			* @param [in]	redundantServerIndex	The index of the target server.
			*
			* @see	connect() disconnect() onStatusChange() onServiceLevelChanged() */
			EnumStatusCode isConnected(bool& connected, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;
			/*! @overload
			*
			* @return	Returns true if the connection to the primary server is established and communication is possible.
			*			Returns false if the connection to the primary server is not established. */
			bool isConnected();

			/*! Establishes a connection to the redundant servers and determines the primary server by the service levels of the servers.
			*
			* When the connection has been established, the session can be used for any client-server communication.
			* The connect() succeeds when at least the connection to one server can be established.
			* If connect() fails, no connection is established and service calls for this session to the servers will fail.
			*
			* The establishment of connection is executed synchronously, i.e. the call will return after the connection is established or an error is detected.
			* Keep in mind that this call can block up to the configured network timeout (@see setNetworkTimeout).
			* Do not invoke this method in a thread context that has to serve other tasks in parallel.
			*
			* If connect() failed the SDK cyclically tries to re-establish the connections until disconnect() is called.
			* Once the connection is established, the state changes to 'connected' and the change is notified via the onStatusChange() and
			* onServiceLevelChanged() callbacks.
			*
			* @param [in]	deep	If true, all subscriptions and monitored items already added to the session will be connected too.
			* @return				The status code of the service sent to the server.
			*
			* @see	isConnected() disconnect() onStatusChange() setAutoReconnectInterval()
			*
			* @note	A session has to be registered in the Application object before it can
			*		can be connected. See Application::addSession() for further reference. */
			EnumStatusCode connect(bool deep);

			/*! Terminates the connection to the redundant servers. All subscriptions that belong to this session are also disconnected.
			* Communication to the servers is only possible after connecting again using connect().
			*
			* @return	The status code of the service sent to the server.
			*
			* @see	isConnected() connect() onStatusChange()
			*
			* @note	A session must be unregistered in the Application object when it is no longer used.
			*		See Application::removeSession() for further reference. */
			EnumStatusCode disconnect();

			/*! Callback for errors. This function must be overridden to obtain error notifications.
			*
			* @param	status					The status code of the failure. The callback is mainly called for connection-related errors.
			* @param	redundantServerIndex	The index of the server.
			*
			* @note	If an error can't be distributed to a server index, @p redundantServerIndex will return OTRedundantServerIndex_Invalid.
			*		Make sure to not use this special index to specify a single server or to use it as an index of an returned array. */
			virtual void onError(EnumStatusCode status, OTUInt32 redundantServerIndex);

			/*! Callback for connection status changes. This function must be overridden to obtain status change notifications.
			*
			* @param	isConnected				Denotes whether the session is now connected or not.
			* @param	redundantServerIndex	The index of the target server.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	connect() disconnect() isConnected() setServerInformation() */
			virtual void onStatusChange(bool isConnected, OTUInt32 redundantServerIndex);

			/*! Callback for service level changes on any of the redundant servers. This is the usual location to invoke
			* a switchover to set another server as primary server.
			*
			* The service level describes the ability of the server to provide its data to the client. The value range is
			* from 0 to 255 as the datatype UInt8, where 0 indicates the worst and 255 indicates the best.
			* The concrete values are vendor-specific.
			*
			* The service level is read on every connection monitoring interval.
			*
			* Its default implementation performs a switchover every time another server has a higher service level than
			* the primary server. Override this method in order to change its behavior.
			*
			* @param	serviceLevels		The service levels of all redundant servers. The datatype of the DataValues is UInt8.
			* @param	primaryServerIndex	The index of the primary server
			* @note	Changes are also reported when the readability of a service level changes.
			*		When there is currently no valid primary server, @p primaryServerIndex will return
			*		OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify a single server or
			*		to use it as an index of an returned array.
			*		The reported changes are sequentialized so that one call of this method will only occur after the previous
			*		one has returned.
			* @see	setConnectionMonitoringInterval() switchoverAsync() */
			virtual void onServiceLevelChanged(const std::vector<DataValue>& serviceLevels, OTUInt32 primaryServerIndex);

			/*! Callback for change of servers certificate.
			*
			* @param transaction			The transaction which notifies the certificate change.
			* @param redundantServerIndex	The index of the target server which changed its certificate.
			*
			* @return A good status code will accept the changed certificate for this session.
			*
			* @note Returning EnumStatusCode_BadConnectionRejected will store the certificate within the rejected folder.
			* @note Default implementation is to accept certificate changes.
			* @note The SDK does NOT put the new certificate into the trust list. When Security is used, you should override this callback
			*       and store the new certificate into the trust list when you trust this certificate or ensure to have the signing CA in the trust list,
			*       otherwise the connection establishment will fail.
			* @note When this callback is triggered, the session is about to (re-)connect to the server. You always have to complete this transaction to continue the connection progress.
			* @note When rejecting a certificate while the auto reconnect is enabled, it is proposed to disconnect the session, otherwise
			*       this callback will be triggered cyclically for the same changed certificate
			* @see CertificateChangeTransaction */
			virtual void onCertificateChange(ObjectPointer<CertificateChangeTransaction> transaction, OTUInt32 redundantServerIndex);

			/*! Returns the SessionId that is assigned to this session by the server and identifies the
			* session uniquely within the server. If the server supports diagnostics, the SessionId identifies
			* the diagnostic node for this session in the server's address space.
			*
			* @param [out]	sessionId				The ID of the session
			* @param [in]	redundantServerIndex	The index of the target server. */
			EnumStatusCode getSessionId(NodeId& sessionId, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;
			/*! @overload
			* @return	Returns the session ID of the primary server */
			NodeId getSessionId() const;

			/*! Binds the given subscription to the session.
			*
			* The subscription needs to be assigned to a session before it can be connected. The session
			* is responsible for all communication.
			*
			* @param [in]	subscription	The subscription to be added
			*
			* @see	Client::RedundantSubscription */
			EnumStatusCode addSubscription(Client::RedundantSubscriptionPtr subscription);

			/*! Returns the subscriptions that belong to this session. */
			std::vector<Client::RedundantSubscriptionPtr> getSubscriptions();
			/*! @overload */
			std::vector<Client::RedundantSubscriptionConstPtr> getSubscriptions() const;

			/*! Removes the given subscription from the session.
			*
			* If the subscription is connected it will be disconnected as well as all contained monitored items.
			*
			* @param [in]	subscription	The subscription to be removed
			*
			* @see	Client::RedundantSubscription */
			EnumStatusCode removeSubscription(Client::RedundantSubscriptionPtr subscription);

			/*! Impersonates a different user for the redundant session.
			*
			* This method is useful for shift changeover scenarios and allows
			* an existing session to be taken over by another user.
			* The service fails if the primary server rejects impersonating another user.
			*
			* @param	pUserIdentityToken	The user identity of the user that will take over the existing session.
			*								The given identity will replace the session's user identity (see setUserIdentityToken())
			*								when the method returns with a Good status.
			* @param	userSecurityPolicy	The security policy for encryption of identity token.
			*								For successful impersonation the endpoint shall expose a matching security policy in EndpointDescription.
			*
			* @note		If impersonating fails on a secondary server, then the connection to this server is disconnected and tried to be reestablished
			*			asynchronously as the new user */
			EnumStatusCode impersonateDifferentUser(const IUserIdentityToken* pUserIdentityToken, const tstring& userSecurityPolicy);
			/*! @overload
			*
			* @param	pUserIdentityToken	The user identity of the user that will take over the existing session.
			*								The given identity will replace the session's user identity (see getUserIdentity())
			*								when the method returns with a Good status.
			* @param	userSecurityPolicy	The security policy for encryption of identity token.
			*								For successful impersonation the endpoint shall expose a matching security policy in EndpointDescription.
			* @param	preferredLocales	The user's preferred locales (see getPreferredLocales()).
			*
			* @note		If impersonating fails on a secondary server, then the connection to this server is disconnected and tried to be reestablished
			*			asynchronously as the new user */
			EnumStatusCode impersonateDifferentUser(const IUserIdentityToken* pUserIdentityToken, const tstring& userSecurityPolicy, const std::vector<tstring>& preferredLocales);

			/*! Returns a reference to the local cache of the server's namespace table. The namespace table contains an indexed list of
			* all namespace URIs that are defined for the connected server.
			*
			* @param [out]	pNamespaceTable			The string table that contains the namespace URIs and namespace indices of the connected server.
			* @param [in]	redundantServerIndex	The index of the target server.
			* @return								The status code of the service.
			*
			* @see			updateNamespaceTable()
			* @note			The namespace table is fetched from the server and cached when the connection
			*				to the server is established for the first time. If the Session object is
			*				re-used for a different server or the namespace table is updated in the server,
			*				updateNamespaceTable() must be called to update the cache. */
			EnumStatusCode getNamespaceTable(StringTableConstPtr& pNamespaceTable, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;
			/*! @overload
			* @return	Returns the namespace table of the primary server */
			StringTableConstPtr getNamespaceTable() const;
			/*! Re-reads the server's namespace table and updates the local cache.
			*
			* @param	redundantServerIndex	The index of the target server.
			* @return	The status code of the service.
			*
			* @note		This method must be called after the server has changed its namespace configuration during runtime. */
			EnumStatusCode updateNamespaceTable(OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Retrieves custom data types from the server so that they can be used by this client
			*
			* The custom data types are those types which don't belong to the well known data types of the OPC Foundation.
			* The custom data types are typically defined by the server or a third party.
			*
			* @param [in]	redundantServerIndex	The index of the target server.
			* @return		The status code of the update operation.
			*
			* @note			The data types are not automatically retrieved on every connect.
			*				It can be time consuming to retrieve the data types (depending on the server); multiple services need to be invoked.
			*				The data type descriptions will be cached in the session and can be used afterwards.
			*
			* @see getCustomDataTypeIds and getDataTypeDescription */
			EnumStatusCode updateDataTypes(OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Provides user-defined data types of the server.
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	redundantServerIndex	The index of the target server.
			*
			* @return		The status code of the method.
			*
			* @note			The data types are not automatically retrieved on every connect.
			*				It can be time consuming to retrieve the data types (depending on the server); multiple services need to be invoked.
			*				The data type descriptions will be cached in the session and can be used afterwards.
			*				Once the data type descriptions are available, the method onUpdateDataTypesComplete is invoked.
			*
			* @see getCustomDataTypeIds and getDataTypeDescription */
			EnumStatusCode updateDataTypesAsync(void* transactionHandle, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! The cached user-defined data types of the server are updated.
			*
			* @param [in]	transactionHandle		The cookie given on the readAsync call.
			* @param [in]	updateResult			Good, if the update succeeded.
 			* @param [in]	redundantServerIndex	The index of the target server. */
			virtual void onUpdateDataTypesComplete(void* transactionHandle, EnumStatusCode updateResult, OTUInt32 redundantServerIndex);

			/*! Returns the node IDs of all custom data types of the selected server.
			*
			* The custom data types are those types which don't belong to the well known data types of the OPC Foundation.
			* The custom data types are typically defined by the server or a third party.
			*
			* @param [out]	dataTypeIds				A vector of all node IDs of the exposed user defined data types.
			* @param [in]	redundantServerIndex	The index of the target server.
			* @return								The status code of the service.
			*
			* @see  <a href="structured_data_types.htm">Structured data types</a>
			*
			* @note If the cached data type descriptions were never read before, this will be done internally before the method returns. */
			EnumStatusCode getCustomDataTypeIds(std::vector<NodeId>& dataTypeIds, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			/*! Returns the description for a custom data type.
			*
			* The custom data types are those types which don't belong to the well known data types of the OPC Foundation.
			* The custom data types are typically defined by the server or a third party.
			*
			* @param [in]	dataTypeId				The NodeId of the data type.
			* @param [out]	dataTypeDescription		The DataTypeDescription, describing the encoding rule for the data type.
			* @param [in]	redundantServerIndex	The index of the target server.
			*
			* @see	DataTypeDescription
			* @note If the cached data type descriptions were never read before, this will be done internally before the method returns. */
			EnumStatusCode getDataTypeDescription(const INodeId& dataTypeId, DataTypeDescriptionConstPtr& dataTypeDescription, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;
			/*! @overload */
			EnumStatusCode getDataTypeDescription(const IValue* value, DataTypeDescriptionConstPtr& dataTypeDescription, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary) const;

			//////////////////////////////////////////////////////////////////////////
			// OPC UA Services
			//////////////////////////////////////////////////////////////////////////

			/*! Invokes the OPC UA read service, which reads a set of values from the connected server.
			* The service allows to perform several read requests within one transaction.
			* If the return code is bad the complete transaction failed and the values vector is undefined.
			* Single request errors are reported in the @p values output parameter.
			*
			* The read can also be called asynchronously (see readAsync()).
			*
			* @par Note regarding @p maxAge parameter
			* In case of a ReadTransaction containing many requests the server is sometimes not able to fulfill the timing requests
			* completely.
			* It can happen that some Values can be read from the cached values where others have to be read from an
			* extern device.
			* If the read from the extern device takes a long time the already finished request might became older than
			* the max. requested age.
			*
			* @param [in]	returnTimestamps		Defines which timestamps shall be set in the returned Values (see Enumeration for details).
			*										This parameter is used for all requests in the transaction.
			* @param [in]	nodesToRead				A vector of information representing node, attribute and value (see ReadValueId) to be read.
			* @param [in]	maxAge					The maximum age that is allowed for the returned Value in milliseconds.
			*										That allows the server to return a cached value for a request instead of re-reading from an external device.
			*										This parameter is used for all requests in the transaction. The value is given in milliseconds where
			*										@li in case of maxAge = maxInt32 the server is allowed to return any cached value.
			*										@li in case of 0 the server shall always read the value from the device.
			* @param [out]	values					A vector of returned information containing status code, timestamps and value. For each request such an information is returned.
			*										@p nodesToRead and @p values are linked by the same index in the vectors.
			*										In case of a bad request status code, the timestamp and value information is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p values vector is undefined.
			*
			* @see	EnumTimestampsToReturn ReadValueId DataValue readAsync() */
			EnumStatusCode read(EnumTimestampsToReturn returnTimestamps, const std::vector<ReadValueId>& nodesToRead, double maxAge, std::vector<DataValue>& values, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA read service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	returnTimestamps		Defines which timestamps shall be set in the returned Values (see Enumeration for details).
			*										This parameter is used for all requests in the transaction.
			* @param [in]	nodesToRead				A vector of information representing node, attribute and value (see ReadValueId) to be read.
			* @param [in]	maxAge					The maximum age that is allowed for the returned Value in milliseconds.
			*										That allows the server to return a cached value for a request instead of re-reading from an external device.
			*										This parameter is used for all requests in the transaction. The value is given in milliseconds where
			*										@li in case of maxAge = maxInt32 the server is allowed to return any cached value.
			*										@li in case of 0 the server shall always read the value from the device.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	values					A vector of returned information containing status code, timestamps and value. For each request such an information is returned.
			*										@p nodesToRead and @p values are linked by the same index in the vectors.
			*										In case of a bad request status code, the timestamp and value information is undefined.
			* @param [out]	diagnosticInfos			List of diagnostic information. The size and order of this list matches the size and order of
			*										the nodesToRead request parameter. There is one entry in this list for each Node contained in
			*										the nodesToRead parameter. This list is empty if diagnostics information was not requested or
			*										if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p values vector is undefined. */
			EnumStatusCode read(EnumDiagnosticsToReturn diagnosticsToReturn, EnumTimestampsToReturn returnTimestamps, const std::vector<ReadValueId>& nodesToRead, double maxAge,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<DataValue>& values, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA read service asynchronously, which reads a set of values from the connected server.
			* The service allows to perform several read requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onReadComplete() is invoked.
			*
			* The read can also be called synchronously(see read())
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	returnTimestamps		Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	nodesToRead				A vector of information representing node, attribute and value (see ReadValueId) to be read.
			* @param [in]	maxAge					Defines maximum allowed age of the value in the servers cache. This parameter is used for all requests in the transaction.
			* @param [in]	transactionId			A number to group a set of transactions. The ID needs not to be unique and can be any number except 0xFFFFFFFF.
			*										The ID can be used to cancel transactions. In case of multiple transactions sharing the same ID all transactions with this ID
			*										can be canceled using one call (see cancelTransaction()).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	EnumTimestampsToReturn ReadValueId DataValue cancelTransaction() read() */
			EnumStatusCode readAsync(void* transactionHandle, EnumTimestampsToReturn returnTimestamps, const std::vector<ReadValueId>& nodesToRead, double maxAge, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous read service. This function must be overridden by the application session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the readAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the values vector is undefined.
			* @param [in]	values					A vector of returned information containing status code, timestamps and value. For each request such an information is returned.
			*										@p nodesToRead and @p values are linked by the same index in the vectors.
			*										In case of a bad request status code, the timestamp and value information is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	readAsync() DataValue cancelTransaction() setServerInformation() */
			virtual void onReadComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<DataValue>& values, OTUInt32 redundantServerIndex);


			/*! Invokes the OPC UA write service, which writes a set of values to nodes in the connected server.
			* The service allows to perform several write requests within one transaction.
			* If the return code is bad the complete transaction failed and the results vector is undefined.
			* Single request errors are reported in the results output parameter.
			*
			* The write can also be called asynchronously (see writeAsync()).
			*
			* @param [in]	writeValues				A vector of information representing node, attribute and value (see WriteValue) to be written.
			* @param [out]	results					A vector of status codes. For each request a status code is returned.
			*										@p writeValuesRequest and @p results are linked by the same index in the vectors.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p results vector is undefined.
			*
			* @see	writeAsync() WriteValue */
			EnumStatusCode write(const std::vector<WriteValue>& writeValues, std::vector<EnumStatusCode>& results, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA write service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	writeValues				A vector of information representing node, attribute and value (see WriteValue) to be written.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	results					A vector of status codes. For each request a status code is returned.
			*										@p writeValuesRequest and @p results are linked by the same index in the vectors.
			* @param [out]	diagnosticInfos			List of diagnostic information. The size and order of this list matches the size and order of
			*										the writeValues request parameter. There is one entry in this list for each Node contained in
			*										the writeValues parameter. This list is empty if diagnostics information was not requested or
			*										if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p results vector is undefined.
			*
			* @see	writeAsync() WriteValue */
			EnumStatusCode write(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<WriteValue>& writeValues, StringTablePtr stringTable,
				DiagnosticInfo& serviceDiagnostics, std::vector<EnumStatusCode>& results, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA write service asynchronously, which writes a set of values to nodes in the connected server.
			* The service allows to perform several write requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onWriteComplete() is invoked.
			*
			* The write can also be called synchronously (see write()).
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	writeValues				A vector of information representing node, attribute and value (see WriteValue) to be written.
			* @param [in]	transactionId			A number to group a set of transactions. The ID needs not to be unique and can be any number except 0xFFFFFFFF.
			*										The ID can be used to cancel transactions. In case of multiple transactions sharing the same ID all transactions with this ID
			*										can be canceled using one call (see cancelTransaction()).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	onWriteComplete() write() cancelTransaction() WriteValue */
			EnumStatusCode writeAsync(void* transactionHandle, const std::vector<WriteValue>& writeValues, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous write service. This function must be overridden by the application session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the writeAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the results vector is undefined.
			* @param [in]	results					A vector of status codes. For each request a status code is returned.
			*										@p writeValuesRequest and @p results are linked using the same index in the vector.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	writeAsync() cancelTransaction() setServerInformation() */
			virtual void onWriteComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<EnumStatusCode>& results, OTUInt32 redundantServerIndex);

			/*! Invokes the OPC UA history read service, which reads 'raw' historical values from a connected server.
			* The service allows to perform several requests within one transaction.
			*
			* If not all values for a request can be returned in one call, the server additionally specifies a continuation point for that request.
			* The continuation point can be used in a consecutive historyRead call to continue reading results.
			* Continuation points not used for further calls have to be released in a separate call.
			*
			* If the return code is bad the complete transaction failed and the @p values vector is undefined.
			* Single request errors are reported in the @p values output parameter.
			*
			* The historyRead can also be called asynchronously (see historyReadRawAsync()).
			*
			* @param [in]	returnTimestamps			Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadRawDetails		Pointer to ReadRawDetails, which specify exact read information.
			*											This parameter is used for all requests in the transaction.
			* @param [out]	values						A vector of returned information containing status code, continuation point and historical value. (see HistoryReadResult)
			*											For each request such an information is returned.
			*											@p nodesToRead and @p values are linked by the same index in the vectors.
			*											In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and the @p values vector is undefined.
			*
			* @see	EnumTimestampsToReturn HistoryReadValueId ReadRawDetails HistoryReadResult historyReadRawAsync() */
			EnumStatusCode historyReadRaw(EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadRawDetails& historyReadRawDetails, std::vector<HistoryReadDataResult>& values, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA history read 'raw' service.
			*
			* @param [in]	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	returnTimestamps			Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadRawDetails		Pointer to ReadRawDetails, which specify exact read information.
			*											This parameter is used for all requests in the transaction.
			* @param [out]	stringTable					The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics			Diagnostic information for the service invocation.
			* @param [out]	values						A vector of returned information containing status code, continuation point and historical value. (see HistoryReadResult)
			*											For each request such an information is returned.
			*											@p nodesToRead and @p values are linked by the same index in the vectors.
			*											In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [out]	diagnosticInfos				List of diagnostic information. The size and order of this list matches the size and order of
			*											the nodesToRead request parameter. There is one entry in this list for each Node contained in
			*											the nodesToRead parameter. This list is empty if diagnostics information was not requested or
			*											if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and the @p values vector is undefined.
			*
			* @see	EnumTimestampsToReturn HistoryReadValueId ReadRawDetails HistoryReadResult historyReadRawAsync() */
			EnumStatusCode historyReadRaw(EnumDiagnosticsToReturn diagnosticsToReturn, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadRawDetails& historyReadRawDetails,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<HistoryReadDataResult>& values, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA history read service asynchronously, which reads historical values from a connected server.
			* The service allows to perform several requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onHistoryReadRawComplete() is invoked.
			*
			* The historyRead can also be called synchronously (see historyReadRaw())
			*
			* @param [in]	transactionHandle			A cookie specified by the caller. This cookie can be used to identify the service in the
			*											asynchronous response.
			* @param [in]	returnTimestamps			Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadRawDetails		Pointer to ReadRawDetails, which specify exact read information.
			*											This parameter is used for all requests in the transaction.
			* @param [in]	transactionId				A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*											The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*											can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	EnumTimestampsToReturn HistoryReadValueId ReadRawDetails HistoryReadResult cancelTransaction() historyReadRaw() */
			EnumStatusCode historyReadRawAsync(void* transactionHandle, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadRawDetails& historyReadRawDetails, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous history read service. This function must be overridden by the application session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the historyReadRawAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [in]	values					A vector of returned information containing status code, continuation point and historical value. (see HistoryReadResult)
			*										For each request such an information is returned.
			*										@p nodesToRead and @p values are linked by the same index in the vectors.
			*										In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	HistoryReadResult cancelTransaction() historyReadRaw() setServerInformation() */
			virtual void onHistoryReadRawComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<HistoryReadDataResult>& values, OTUInt32 redundantServerIndex);

			/*! Invokes the OPC UA history read service, which reads 'processed' (i.e. aggregated) historical values from a connected server.
			* The service allows to perform several requests within one transaction.
			*
			* If the calculation of aggregates takes too much time or the number of returned aggregate values exceeds
			* server-internal limits, the server may return a continuation point that allows the client to
			* continue a request. Continuation points not used for further calls have to be released in a separate call.
			*
			* If the return code of historyReadProcessed() is bad, the complete transaction failed and the @p values vector is undefined.
			* Single request errors are reported in the @p values output parameter.
			*
			* The historyRead can also be called asynchronously (see historyReadProcessedAsync()).
			*
			* @param [in]	returnTimestamps				Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints		If true, the continuation points provided with @p historyReadProcessedDetails are released and cannot be used any longer.
			* @param [in]	nodesToRead						A vector of information to be read.
			*												The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadProcessedDetails	Pointer to ReadProcessedDetails, which specify exact read information (e.g. which aggregates to calculate).
			*												This parameter is used for all requests in the transaction.
			* @param [out]	values							A vector of returned information containing status code, (optional) continuation point and aggregated values. (see HistoryReadResult)
			*												For each request such an information is returned.
			*												@p nodesToRead and @p values are linked by the same index in the vectors.
			*												In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex			The index of the redundant server where the service is called on.
			* @return										The status code of the service sent to the server.
			*												In case of bad service status code the complete transaction failed and the @p values vector is undefined.
			*
			* @see	HistoryReadValueId ReadProcessedDetails HistoryReadResult historyReadProcessedAsync() */
			EnumStatusCode historyReadProcessed(EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadProcessedDetails& historyReadProcessedDetails, std::vector<HistoryReadDataResult>& values, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA history read 'processed' service.
			*
			* @param [in]	diagnosticsToReturn				Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	returnTimestamps				Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints		If true, the continuation points provided with @p historyReadProcessedDetails are released and cannot be used any longer.
			* @param [in]	nodesToRead						A vector of information to be read.
			*												The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadProcessedDetails	Pointer to ReadProcessedDetails, which specify exact read information (e.g. which aggregates to calculate).
			*												This parameter is used for all requests in the transaction.
			* @param [out]	stringTable						The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics				Diagnostic information for the service invocation.
			* @param [out]	values							A vector of returned information containing status code, (optional) continuation point and aggregated values. (see HistoryReadResult)
			*												For each request such an information is returned.
			*												@p nodesToRead and @p values are linked by the same index in the vectors.
			*												In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [out]	diagnosticInfos					List of diagnostic information. The size and order of this list matches the size and order of
			*												the nodesToRead request parameter. There is one entry in this list for each Node contained in
			*												the nodesToRead parameter. This list is empty if diagnostics information was not requested or
			*												if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex			The index of the redundant server where the service is called on.
			* @return										The status code of the service sent to the server.
			*												In case of bad service status code the complete transaction failed and the @p values vector is undefined. */
			EnumStatusCode historyReadProcessed(EnumDiagnosticsToReturn diagnosticsToReturn, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadProcessedDetails& historyReadProcessedDetails,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<HistoryReadDataResult>& values, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA history read service asynchronously, which reads 'processed' (i.e. aggregated) historical values from
			* a connected server.
			* The service allows to perform several requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onHistoryReadProcessedComplete() is invoked.
			*
			* This service can also be called synchronously (see historyReadProcessed())
			*
			* @param [in]	transactionHandle				A cookie specified by the caller. This cookie can be used to identify the service in the
			*												asynchronous response.
			* @param [in]	returnTimestamps				Defines which timestamps shall be returned from server. This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints		If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead						A vector of information to be read.
			*												The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadProcessedDetails	Pointer to ReadProcessedDetails, which specify exact read information (e.g. which aggregates to calculate).
			*												This parameter is used for all requests in the transaction.
			* @param [in]	transactionId					A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*												The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*												can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex			The index of the redundant server where the service is called on.
			* @return										The status code of the service sent to the server.
			*												In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	EnumTimestampsToReturn HistoryReadValueId ReadProcessedDetails HistoryReadResult cancelTransaction() historyReadProcessed() */
			EnumStatusCode historyReadProcessedAsync(void* transactionHandle, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadProcessedDetails& historyReadProcessedDetails, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous history read 'processed' service. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the historyReadProcessedAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [in]	values					A vector of returned information containing status code, continuation point and historical value. (see HistoryReadResult)
			*										For each request such an information is returned.
			*										@p nodesToRead and @p values are linked by the same index in the vectors.
			*										In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	HistoryReadResult cancelTransaction() historyReadProcessedAsync() setServerInformation() */
			virtual void onHistoryReadProcessedComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<HistoryReadDataResult>& values, OTUInt32 redundantServerIndex);

			/*! Invokes the OPC UA history read service, which reads historical events from a connected server.
			* The service allows to perform several requests within one transaction.
			*
			* If not all events for a request can be returned in one call, the server additionally specifies a continuation point for that request.
			* The continuation point can be used in a consecutive historyRead call to continue reading results.
			* Continuation points that the client will no longer use for further calls have to be released in a separate call.
			*
			* If the return code is bad the complete transaction failed and the content of the @p events vector is undefined.
			* Single request errors are reported in the @p events output parameter.
			*
			* The historyRead can also be called asynchronously (see historyReadEventAsync()).
			*
			* @param [in]	returnTimestamps			Defines which timestamps for event fields of type DataValue shall be returned from server.
			*											This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadEventDetails	Pointer to ReadEventDetails which specifies detailed information for the transaction.
			*											This parameter is used for all requests in the transaction.
			* @param [out]	events						A vector of returned information containing status code, continuation point and events. (see HistoryReadEventResult)
			*											For each request such an information is returned.
			*											@p nodesToRead and @p events are linked by the same index in the vectors.
			*											In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service call sent to the server.
			*											In case of bad service status code the complete transaction failed and the @p events vector is undefined.
			*
			* @see	HistoryReadValueId ReadEventDetails HistoryReadEventResult historyReadEventAsync() */
			EnumStatusCode historyReadEvent(EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadEventDetails& historyReadEventDetails, std::vector<HistoryReadEventResult>& events, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA history read 'event' service.
			*
			* @param [in]	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	returnTimestamps			Defines which timestamps for event fields of type DataValue shall be returned from server.
			*											This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadEventDetails	Pointer to ReadEventDetails which specifies detailed information for the transaction.
			*											This parameter is used for all requests in the transaction.
			* @param [out]	stringTable					The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics			Diagnostic information for the service invocation.
			* @param [out]	events						A vector of returned information containing status code, continuation point and events. (see HistoryReadEventResult)
			*											For each request such an information is returned.
			*											@p nodesToRead and @p events are linked by the same index in the vectors.
			*											In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [out]	diagnosticInfos				List of diagnostic information. The size and order of this list matches the size and order of
			*											the nodesToRead request parameter. There is one entry in this list for each Node contained in
			*											the nodesToRead parameter. This list is empty if diagnostics information was not requested or
			*											if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			*
			* @return									The status code of the service call sent to the server.
			*											In case of bad service status code the complete transaction failed and the @p events vector is undefined. */
			EnumStatusCode historyReadEvent(EnumDiagnosticsToReturn diagnosticsToReturn, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead, const ReadEventDetails& historyReadEventDetails,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<HistoryReadEventResult>& events, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! Invokes the OPC UA history read service asynchronously, which reads historical events from a connected server.
			* The service allows to perform several requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onHistoryReadEventComplete() is invoked.
			*
			* This service can also be called synchronously (see historyReadEvent())
			*
			* @param [in]	transactionHandle			A cookie specified by the caller. This cookie can be used to identify the service in the
			*											asynchronous response.
			* @param [in]	returnTimestamps			Defines which timestamps for event fields of type DataValue shall be returned from server.
			*											This parameter is used for all requests in the transaction.
			* @param [in]	releaseContinuationPoints	If true, the continuation points are released and cannot be used any longer.
			* @param [in]	nodesToRead					A vector of information to be read.
			*											The information contains node, attribute and value (see HistoryReadValueId)
			* @param [in]	historyReadEventDetails	Pointer to ReadEventDetails which specifies detailed information for the transaction.
			*											This parameter is used for all requests in the transaction.
			* @param [in]	transactionId				A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*											The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*											can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	HistoryReadValueId ReadEventDetails HistoryReadResult cancelTransaction() historyReadEvent() */
			EnumStatusCode historyReadEventAsync(void* transactionHandle, EnumTimestampsToReturn returnTimestamps, bool releaseContinuationPoints, const std::vector<HistoryReadValueId>& nodesToRead,
				const ReadEventDetails& historyReadEventDetails, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! Callback for the response to an asynchronous history read 'event' service. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the historyReadEventAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [out]	events					A vector of returned information containing status code, continuation point and events. (see HistoryReadEventResult)
			*										For each request such an information is returned.
			*										@p nodesToRead and @p events are linked by the same index in the vectors.
			*										In case of a bad request status code, the rest of the returned information for this request is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	HistoryReadResult cancelTransaction() historyReadEventAsync() setServerInformation() */
			virtual void onHistoryReadEventComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<HistoryReadEventResult>& events, OTUInt32 redundantServerIndex);

			/*! Issues a query to a server. A query defines what instances of one or more TypeDefinitionNodes in the address space should
			* supply a set of attributes. Results returned by a server are in the form of an array of QueryDataSets. The selected attribute
			* values in each QueryDataSet come from the definition of the selected TypeDefinitionNodes or related TypeDefinitionNodes and
			* appear in results in the same order as the attributes that were passed into the query. Query also supports node filtering on the
			* basis of attribute values, as well as relationships between TypeDefinitionNodes.
			*
			* @param [in]	view					Restricts the query to the given view
			* @param [in]	nodeTypes				The node types which are to be queried
			* @param [in]	filter					A filter which is to be applied to node instances and which restricts the set of nodes returned by the query
			* @param [in]	maxDataSetsToReturn		The maximum number of QueryDataSets that are to be returned. A value of 0 means that no limit is imposed by the client.
			* @param [in]	maxReferencesToReturn	The maximum number of References that are to be returned (see QueryDataSet::getValues()).
			*										A value of 0 means that no limit is imposed by the client.
			* @param [out]	queryDataSets			The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [out]	continuationPoint		The continuation point is used only when the Query results are too large to be returned in a single response.
			*										The continuation point is used in the QueryNext Service. When not used, the value of this parameter is null. If a
			*										continuation point is returned, the Client shall call see queryNext to get the next set of QueryDataSets or to free
			*										the resources for the continuation point in the Server. A continuation point remains active until the Client passes the
			*										continuation point to QueryNext or the session is closed.
			* @param [out]	parsingResults			List of parsing results for QueryFirst. The size and order of the list matches the size and order of the @p nodeTypes
			*										service parameter. This list is populated with any status codes that are related to the processing of the node types
			*										that are part of the query. The array can be empty if no errors where encountered. If any node type encountered an error
			*										all node types have an associated status code.
			* @param [out]	filterResult			Contains any errors associated with the @p filter. This structure is empty if no errors occurred.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			*
			* @see	ContentFilter NodeTypeDescription QueryDataSet queryNext() */
			EnumStatusCode queryFirst(const IViewDescription* view, const std::vector<NodeTypeDescription>& nodeTypes, const IContentFilter* filter, OTUInt32 maxDataSetsToReturn, OTUInt32 maxReferencesToReturn,
				std::vector<QueryDataSet>& queryDataSets, ByteString& continuationPoint, std::vector<ParsingResult>& parsingResults, ContentFilterResult& filterResult, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA QueryFirst service.
			*
			* @param	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param	view						Restricts the query to the given view
			* @param	nodeTypes					The node types which are to be queried
			* @param	filter						A filter which is to be applied to node instances and which restricts the set of nodes returned by the query
			* @param	maxDataSetsToReturn			The maximum number of QueryDataSets that are to be returned. A value of 0 means that no limit is imposed by the client.
			* @param	maxReferencesToReturn		The maximum number of References that are to be returned (see QueryDataSet::getValues()).
			*										A value of 0 means that no limit is imposed by the client.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	queryDataSets			The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [out]	continuationPoint		The continuation point is used only when the Query results are too large to be returned in a single response.
			*										The continuation point is used in the QueryNext Service. When not used, the value of this parameter is null. If a
			*										continuation point is returned, the Client shall call see queryNext to get the next set of QueryDataSets or to free
			*										the resources for the continuation point in the Server. A continuation point remains active until the Client passes the
			*										continuation point to QueryNext or the session is closed.
			* @param [out]	parsingResults			List of parsing results for QueryFirst. The size and order of the list matches the size and order of the @p nodeTypes
			*										service parameter. This list is populated with any status codes that are related to the processing of the node types
			*										that are part of the query. The array can be empty if no errors where encountered. If any node type encountered an error
			*										all node types have an associated status code.
			* @param [out]	filterResult			Contains any errors associated with the @p filter. This structure is empty if no errors occurred.
			* @param [out]	diagnosticInfos			List of diagnostic information for the requested NodeTypeDescription. This list
			*										is empty if diagnostics information was not requested or
			*										if no diagnostic information was encountered in processing of the query request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on. */
			EnumStatusCode queryFirst(EnumDiagnosticsToReturn diagnosticsToReturn, const IViewDescription* view, const std::vector<NodeTypeDescription>& nodeTypes, const IContentFilter* filter, OTUInt32 maxDataSetsToReturn, OTUInt32 maxReferencesToReturn,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<QueryDataSet>& queryDataSets, ByteString& continuationPoint, std::vector<ParsingResult>& parsingResults, ContentFilterResult& filterResult, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA QueryFirst service asynchronously.
			*
			* The service allows to perform several requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onQueryFirstComplete() is invoked.
			*
			* This service can also be called synchronously (see queryFirst()).
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	view					Restricts the query to the given view
			* @param [in]	nodeTypes				The node types which are to be queried
			* @param [in]	filter					A filter which is to be applied to node instances and which restricts the set of nodes returned by the query
			* @param [in]	maxDataSetsToReturn		The maximum number of QueryDataSets that are to be returned. A value of 0 means that no limit is imposed by the client.
			* @param [in]	maxReferencesToReturn	The maximum number of References that are to be returned (see QueryDataSet::getValues()).
			*										A value of 0 means that no limit is imposed by the client.
			* @param [in]	transactionId			A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*										The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*										can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	ContentFilter NodeTypeDescription queryNextAsync() cancelTransaction() queryFirst() */
			EnumStatusCode queryFirstAsync(void* transactionHandle, const IViewDescription* view, const std::vector<NodeTypeDescription>& nodeTypes, const IContentFilter* filter,
				OTUInt32 maxDataSetsToReturn, OTUInt32 maxReferencesToReturn, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous QueryFirst service call. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the queryFirstAsync() call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [in]	queryDataSets			The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [in]	continuationPoint		The continuation point is used only when the Query results are too large to be returned in a single response.
			*										The continuation point is used in the QueryNext Service. When not used, the value of this parameter is null. If a
			*										continuation point is returned, the Client shall call see queryNext to get the next set of QueryDataSets or to free
			*										the resources for the continuation point in the Server. A continuation point remains active until the Client passes the
			*										continuation point to QueryNext or the session is closed.
			* @param [in]	parsingResults			List of parsing results for QueryFirst. The size and order of the list matches the size and order of the @p nodeTypes
			*										service parameter. This list is populated with any status codes that are related to the processing of the node types
			*										that are part of the query. The array can be empty if no errors where encountered. If any node type encountered an error
			*										all node types have an associated status code.
			* @param [in]	filterResult			Contains any errors associated with the @p filter. This structure is empty if no errors occurred.
			* @param [in]	redundantServerIndex	The index of the target server.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	QueryDataSet cancelTransaction() queryFirstAsync() setServerInformation() */
			virtual void onQueryFirstComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<QueryDataSet>& queryDataSets,
				const ByteString& continuationPoint, const std::vector<ParsingResult>& parsingResults, const ContentFilterResult& filterResult, OTUInt32 redundantServerIndex);

			/*! This service is used to request the next set of QueryFirst or QueryNext response information that is
			* too large to be sent in a single response (see queryFirst).
			*
			* A client shall always use or free any continuation point received by the server using this service.
			*
			* @param [in]	releaseContinuationPoint	If true, the passed @p continuationPoint shall be reset to free resources for the continuation point in the Server.
			* @param [in]	continuationPoint			The value of the continuation point that was returned in a previous QueryFirst or QueryNext response.
			*											This value is used to identify the previously processed QueryFirst or QueryNext request that is being
			*											continued, and the point in the result set from which the browse response is to continue.
			* @param [out]	queryDataSets				The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [out]	revisedContinuationPoint	The revised continuation point returned by the server if there are more results or an empty ByteString if
			*											all results have been fetched.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			*
			* @see	QueryDataSet queryFirst() */
			EnumStatusCode queryNext(bool releaseContinuationPoint, const ByteString& continuationPoint, std::vector<QueryDataSet>& queryDataSets, ByteString& revisedContinuationPoint, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA QueryNext service.
			*
			* @param [in]	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	releaseContinuationPoint	If true, the passed @p continuationPoint shall be reset to free resources for the continuation point in the Server.
			* @param [in]	continuationPoint			The value of the continuation point that was returned in a previous QueryFirst or QueryNext response.
			*											This value is used to identify the previously processed QueryFirst or QueryNext request that is being
			*											continued, and the point in the result set from which the browse response is to continue.
			* @param [out]	stringTable					The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics			Diagnostic information for the service invocation.
			* @param [out]	queryDataSets				The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [out]	revisedContinuationPoint	The revised continuation point returned by the server if there are more results or an empty ByteString if
			*											all results have been fetched.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on. */
			EnumStatusCode queryNext(EnumDiagnosticsToReturn diagnosticsToReturn, bool releaseContinuationPoint, const ByteString& continuationPoint,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<QueryDataSet>& queryDataSets, ByteString& revisedContinuationPoint, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA QueryNext service asynchronously.
			*
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onQueryNextComplete() is invoked.
			*
			* This service can also be called synchronously (see queryNext()).
			*
			* @param [in]	transactionHandle			A cookie specified by the caller. This cookie can be used to identify the service in the
			*											asynchronous response.
			* @param [in]	releaseContinuationPoint	If true, the passed @p continuationPoint shall be reset to free resources for the continuation point in the Server.
			* @param [in]	continuationPoint			The value of the continuation point that was returned in a previous QueryFirst or QueryNext response.
			*											This value is used to identify the previously processed QueryFirst or QueryNext request that is being
			*											continued, and the point in the result set from which the browse response is to continue.
			* @param [in]	transactionId				A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*											The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*											can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	QueryDataSet queryFirstAsync() */
			EnumStatusCode queryNextAsync(void* transactionHandle, bool releaseContinuationPoint, const ByteString& continuationPoint, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous QueryFirst service call. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle			The cookie given on the queryFirstAsync() call.
			* @param [in]	serviceResult				The status code of the service sent to the server.
			*											If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [in]	queryDataSets				The array of QueryDataSet. This array is empty if no nodes or references met the nodeTypes criteria.
			* @param [in]	revisedContinuationPoint	The revised continuation point returned by the server if there are more results or an empty ByteString if
			*											all results have been fetched.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	QueryDataSet cancelTransaction() queryFirstAsync() setServerInformation() */
			virtual void onQueryNextComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<QueryDataSet>& queryDataSets, const ByteString& revisedContinuationPoint, OTUInt32 redundantServerIndex);

			/*! This call invokes an OPC UA browse service to discover references of a specified node.
			* Multiple browse requests can be executed in a single call.
			*
			* The returned results may contain continuation points that require one or more browseNext calls to finish
			* the browse request.
			* If no further browsing shall be performed, given continuation points have to be released in an extra call to browseNext.
			*
			* @param [in]	viewDescription			The parameter can be used to limit the browse call to a given view.
			* @param [in]	browseDescriptions		The description of nodes that shall be processed in the browse request (a browse operation can be called
			*										on multiple nodes in one call).
			*										For each node a single description has to be filled with the requested parameters (see BrowseDescription for details).
			* @param [in]	maxReferencesPerNode	Defines the maximum of references returned for each node. Browsing folders with a large number of items
			*										will require a limitation of the returned references
			*										(a response from a server is limited by a maximum message length -- so a browse with a large number of
			*										results may fail due to that limitation).
			* @param [out]	results					The browse results. Each given browse description is linked to a result using the index of the vector
			*										If the status code of a request result is bad, the rest of the information is undefined.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p results vector is undefined. */
			EnumStatusCode browse(const IViewDescription* viewDescription, const std::vector<BrowseDescription>& browseDescriptions, OTUInt32 maxReferencesPerNode, std::vector<BrowseResult>& results, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA browse service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	viewDescription			The parameter can be used to limit the browse call to a given view.
			* @param [in]	browseDescriptions		The description of nodes that shall be processed in the browse request (a browse operation can be called
			*										on multiple nodes in one call).
			*										For each node a single description has to be filled with the requested parameters (see BrowseDescription for details).
			* @param [in]	maxReferencesPerNode	Defines the maximum of references returned for each node. Browsing folders with a large number of items
			*										will require a limitation of the returned references
			*										(a response from a server is limited by a maximum message length -- so a browse with a large number of
			*										results may fail due to that limitation).
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	results					The browse results. Each given browse description is linked to a result using the index of the vector
			*										If the status code of a request result is bad, the rest of the information is undefined.
			* @param [out]	diagnosticInfos			List of diagnostic information for the results. The size and order of the list matches the
			*										size and order of the results response parameter. This list is empty if diagnostics information was not
			*										requested or if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p results vector is undefined. */
			EnumStatusCode browse(EnumDiagnosticsToReturn diagnosticsToReturn, const IViewDescription* viewDescription, const std::vector<BrowseDescription>& browseDescriptions, OTUInt32 maxReferencesPerNode,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<BrowseResult>& results, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA browse service call asynchronously to discover references of a specified node.
			* Multiple browse requests can be executed in a single call.
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	viewDescription			The parameter can be used to limit the browse call to a given view.
			* @param [in]	browseDescriptions		The description of nodes that shall be processed in the browse request (a browse operation can be called
			*										on multiple nodes in one call).
			*										For each node a single description has to be filled with the requested parameters (see BrowseDescription for details).
			* @param [in]	maxReferencesPerNode	Defines the maximum of references returned for each node. Browsing folders with a large number of items
			*										will require a limitation of the returned references
			*										(a response from a server is limited by a maximum message length -- so a browse with a large number of
			*										results may fail due to that limitation).
			* @param [in]	transactionId			A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*										The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*										can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see onBrowseComplete() */
			EnumStatusCode browseAsync(void* transactionHandle, const IViewDescription* viewDescription, const std::vector<BrowseDescription>& browseDescriptions,
				OTUInt32 maxReferencesPerNode, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous browse service call. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle			The cookie given on the browseAsync() call.
			* @param [in]	serviceResult				The status code of the service sent to the server.
			*											If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [out]	results						The browse results. Each given browse description is linked to a result using the index of the vector.
			*											If the status code of a request result is bad, the rest of the information is undefined.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	browseAsync() */
			virtual void onBrowseComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<BrowseResult>& results, OTUInt32 redundantServerIndex);

			/*! Performs a browse starting from a single node defined in the browseDescription parameter.
			*
			* This is a method provided for convenience since continuation points handling is implemented in the SDK.
			* Therefore directly the vector of references can be returned.
			*
			* Only one browse description instead of a vector is supported here.
			*
			* @param [in]	viewDescription			The parameter can be used to limit the browse call to a given view.
			* @param [in]	browseDescription		The description of the node that shall be processed in the browse request (see BrowseDescription for details).
			* @param [out]	results					The descriptions of the found references.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			*
			* @see	IViewDescription BrowseDescription ReferenceDescription */
			EnumStatusCode browseNode(const IViewDescription* viewDescription, const IBrowseDescription* browseDescription, std::vector<ReferenceDescription>& results, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! This call invokes an OPC UA browseNext service.
			* This service is used to continue or abort the previous browse() of browseNext() call which has returned a continuation point.
			* Multiple browseNext requests can be executed in a single call.
			*
			* @param [in]	continuationPoints			A list of continuation points returned by a previous call.
			* @param [in]	releaseContinuationPoints	Flag that indicates whether the server shall use the given ContinuationPoints for the next browse.
			*											If the flag is true the function does not return more results - it only releases the continuation points.
			*											If the flag is false the function continues the browse operation with the given set of continuation points.
			* @param [out]	results						The browse results. Each given continuation point is linked to a result using the index of the vector
			*											If the status code of a request result is bad, the rest of the information is undefined.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete call failed and the @p results vector is undefined.
			*
			* @see	BrowseResult browse() */
			EnumStatusCode browseNext(const std::vector<ByteString>& continuationPoints, bool releaseContinuationPoints, std::vector<BrowseResult>& results, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA BrowseNext service.
			*
			* @param [in]	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	continuationPoints			A list of continuation points returned by a previous call.
			* @param [in]	releaseContinuationPoints	Flag that indicates whether the server shall use the given ContinuationPoints for the next browse.
			*											If the flag is true the function does not return more results - it only releases the continuation points.
			*											If the flag is false the function continues the browse operation with the given set of continuation points.
			* @param [out]	stringTable					The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics			Diagnostic information for the service invocation.
			* @param [out]	results						The browse results. Each given continuation point is linked to a result using the index of the vector
			*											If the status code of a request result is bad, the rest of the information is undefined.
			* @param [out]	diagnosticInfos				List of diagnostic information for the results. The size and order of the list matches the
			*											size and order of the results response parameter. This list is empty if diagnostics information was not
			*											requested or if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete call failed and the @p results vector is undefined. */
			EnumStatusCode browseNext(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<ByteString>& continuationPoints, bool releaseContinuationPoints,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<BrowseResult>& results, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA BrowseNext service call asynchronously.
			* This service is used to continue or abort the previous browse() of browseNext() call which has returned a continuation point.
			* Multiple browseNext requests can be executed in a single call.
			*
			* @param [in]	transactionHandle			A cookie specified by the caller. This cookie can be used to identify the service in the
			*											asynchronous response.
			* @param [in]	continuationPoints			A list of continuation points returned by a previous call.
			* @param [in]	releaseContinuationPoints	Flag that indicates whether the server shall use the given ContinuationPoints for the next browse.
			*											If the flag is true the function does not return more results - it only releases the continuation points.
			*											If the flag is false the function continues the browse operation with the given set of continuation points.
			* @param [in]	transactionId				A number to identify the transaction. The transactionId needs not to be unique. The transactionId can be any number except 0xFFFFFFFF.
			*											The transactionId can be used to cancel transaction. In case of multiple transactions sharing the same ID all transactions with this ID
			*											can be canceled using one call (see cancelTransaction).
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see onBrowseNextComplete() */
			EnumStatusCode browseNextAsync(void* transactionHandle, const std::vector<ByteString>& continuationPoints, bool releaseContinuationPoints,
				OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! Callback for the response to an asynchronous BrowseNext service call. This function must be overridden by the application
			* session instance to handle the notification.
			*
			* @param [in]	transactionHandle			The cookie given on the browseNextAsync() call.
			* @param [in]	serviceResult				The status code of the service sent to the server.
			*											If the service status code is bad the complete transaction failed and the @p values vector is undefined.
			* @param [out]	results						The browse results. Each given continuation point is linked to a result using the index of the vector
			*											If the status code of a request result is bad, the rest of the information is undefined.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service was called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			*
			* @see	browseNextAsync() */
			virtual void onBrowseNextComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<BrowseResult>& results, OTUInt32 redundantServerIndex);

			/*! This call invokes an OPC UA TranslateBrowsePathToNodeIds service.
			* This Service is used to request that the Server translates one or more browse paths to NodeIds.
			* Each browse path is constructed of a starting Node and a RelativePath. The specified starting Node
			* identifies the Node from which the RelativePath is based. The RelativePath contains a sequence of
			* ReferenceTypes and BrowseNames.
			*
			* @param [in]	browsePaths				Vector of BrowsePaths containing a starting node and a relative path for which NodeIds are being requested.
			*										The targetName of the last relativePathElement in the relativePath of browsePath has to be set. All other targetNames can be empty
			*										to accept any targetName.
			* @param [out]	browsePathResults		Vector of results. see BrowsePathResult for detailed information.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p browsePathResult vector is undefined.
			*
			* @see	BrowsePathResult */
			EnumStatusCode translateBrowsePathToNodeIds(const std::vector<BrowsePath>& browsePaths, std::vector<BrowsePathResult>& browsePathResults, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! @overload
			*
			* The relative paths used in this overload follow the following BNF notation:
			*
			* &lt;relative-path&gt;  ::= &lt;reference-type&gt; &lt;browse-name&gt; [relative-path]
			*
			* &lt;reference-type&gt; ::= '/' | '.' | '&lt;' ['#'] ['!'] &lt;browse-name&gt; '&gt;'
			*
			* &lt;browse-name&gt;  ::= [&lt;namespace-index&gt; ':'] &lt;name&gt;
			*
			* where the reference type abbreviations mean
			* @li "/" : Hierarchical references (and sub-types)
			* @li "." : Aggregates references (and sub-types)
			*
			* The optional parts in the explicit reference type syntax mean
			* @li "#" do not follow sub-types of specified reference type
			* @li "!" follow references backwards
			*
			* Example for equivalent relativePaths:
			*
			* "/1:MyFolder.1:MyElement" == "<0:HierarchicalReferences>1:MyFolder<0:Aggregates>1:MyElement"
			*
			* @param [in]	relativePaths			Vector of BNF-string-coded relative paths for which NodeIds are being requested.
			* @param [in]	startingNodes			Vector of string-coded starting nodes for the relative paths.
			* @param [out]	browsePathResults		Vector of results. see BrowsePathResult for detailed information.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p browsePathResult vector is undefined. */
			EnumStatusCode translateBrowsePathToNodeIds(const std::vector<tstring>& relativePaths, const std::vector<tstring>& startingNodes, std::vector<BrowsePathResult>& browsePathResults, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA TranslateBrowsePathToNodeIds service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	relativePaths			Vector of relative paths for which NodeIds are being requested.
			* @param [in]	startingNodes			Vector of starting nodes for the relative paths.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	browsePathResults		Vector of results. see BrowsePathResult for detailed information.
			* @param [out]	diagnosticInfos			List of diagnostic information for the list of browse paths. The size and order of the
			*										list matches the size and order of the browsePath request parameter. This list is empty if diagnostics
			*										information was not requested or if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p browsePathResult vector is undefined. */
			EnumStatusCode translateBrowsePathToNodeIds(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<tstring>& relativePaths, const std::vector<tstring>& startingNodes,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<BrowsePathResult>& browsePathResults, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA TranslateBrowsePathToNodeIds service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	browsePaths				Vector of BrowsePaths containing a starting node and a relative path for which NodeIds are being requested.
			*										The targetName of the last relativePathElement in the relativePath of browsePath has to be set. All other targetNames can be empty
			*										to accept any targetName.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	browsePathResults		Vector of results. see BrowsePathResult for detailed information.
			* @param [out]	diagnosticInfos			List of diagnostic information for the list of browse paths. The size and order of the
			*										list matches the size and order of the browsePath request parameter. This list is empty if diagnostics
			*										information was not requested or if no diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete call failed and the @p browsePathResult vector is undefined. */
			EnumStatusCode translateBrowsePathToNodeIds(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<BrowsePath>& browsePaths,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<BrowsePathResult>& browsePathResults, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! This call invokes an OPC UA method call service.
			* The service allows to perform several method call requests within one transaction.
			*
			* The methods can also be called asynchronously (see callMethodsAsync()).
			*
			* @param [in]	methodCallRequest		A vector of information needed for calling a method.
			*										For detailed information see CallMethodRequest
			* @param [out]	methodCallResult		A vector of information returned from calling a method.
			*										For detailed information see CallMethodResult
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p methodCallResult vector is undefined.
			*
			* @see	CallMethodRequest CallMethodResult callMethodsAsync() */
			EnumStatusCode callMethods(const std::vector<CallMethodRequest>& methodCallRequest, std::vector<CallMethodResult>& methodCallResult, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA call service.
			*
			* @param [in]	diagnosticsToReturn	Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	methodCallRequest		A vector of information needed for calling a method.
			*										For detailed information see CallMethodRequest
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	methodCallResult		A vector of information returned from calling a method.
			*										For detailed information see CallMethodResult
			* @param [out]	diagnosticInfos			List of diagnostic information for the StatusCode of the methodCallResult.
			*										This list is empty if diagnostics information was not requested or if no
			*										diagnostic information was encountered in processing of the request.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and the @p methodCallResult vector is undefined. */
			EnumStatusCode callMethods(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<CallMethodRequest>& methodCallRequest,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<CallMethodResult>& methodCallResult, std::vector<DiagnosticInfo>& diagnosticInfos, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Calls a single method on a server object.
			* This is just a variant of the callMethods method for convenience.
			*
			* @param [in]	objectId				The nodeId of the object where to call the Method. The nodeId can be the nodeId of an object (call on
			*										an instance of an object) or the nodeId
			*										of an objectType to call a static method on that.
			* @param [in]	methodId				The nodeId of the method that shall be called.
			* @param [in]	inputArgs				The input parameters for the method call.
			*										The input arguments must be set in the same order as the input arguments are returned from a browse call
			*										to the method's.
			* @param [out]	outputArgs				The values returned from the server's method call
			* @param [out]	inputArgStatusCodes		The status codes returned for the input arguments. The server implementation returns a StatusCode for
			*										each single input argument to allow error reporting on wrong parameters.
			* @param [out]	callResult				The result returned by the server's method call (= return value of the method).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*
			* @see	callMethods() */
			EnumStatusCode callMethod(const INodeId* objectId, const INodeId* methodId, const std::vector<Value>& inputArgs, std::vector<Value>& outputArgs, std::vector<EnumStatusCode>& inputArgStatusCodes, EnumStatusCode& callResult, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA call service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	objectId				The nodeId of the object where to call the Method. The nodeId can be the nodeId of an object (call on
			*										an instance of an object) or the nodeId
			*										of an objectType to call a static method on that.
			* @param [in]	methodId				The nodeId of the method that shall be called.
			* @param [in]	inputArgs				The input parameters for the method call.
			*										The input arguments must be set in the same order as the input arguments are returned from a browse call
			*										to the method's..
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	outputArgs				The values returned from the server's method call
			* @param [out]	inputArgStatusCodes		The status codes returned for the input arguments. The server implementation returns a StatusCode for
			*										each single input argument to allow error reporting on wrong parameters.
			* @param [out]	inputArgDiagnosticInfos	List of diagnostic information for each input argument in inputArgs. This list is
			*										empty if diagnostics information was not requested or if no diagnostic information was encountered in
			*										processing of the request.
			* @param [out]	diagnosticInfo			Diagnostic information for the callResult.
			* @param [out]	callResult				The result returned by the server's method call (= return value of the method).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server. */
			EnumStatusCode callMethod(EnumDiagnosticsToReturn diagnosticsToReturn, const INodeId* objectId, const INodeId* methodId, const std::vector<Value>& inputArgs,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<Value>& outputArgs, std::vector<EnumStatusCode>& inputArgStatusCodes,
				std::vector<DiagnosticInfo>& inputArgDiagnosticInfos, DiagnosticInfo& diagnosticInfo, EnumStatusCode& callResult, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Invokes the OPC UA method call service asynchronously.
			* The service allows to perform several method call requests within one transaction.
			* The call returns immediately after sending the service to the server.
			* When the response is available, the callback method onCallMethodsComplete() is invoked.
			*
			* The method call can also be called synchronously (see callMethods()).
			*
			* @param [in]	transactionHandle		A cookie specified by the caller. This cookie can be used to identify the service in the
			*										asynchronous response.
			* @param [in]	methodCallRequest		A vector of information needed for calling a method.
			*										For detailed information see CallMethodRequest
			* @param [in]	transactionId			A number to group a set of transactions. The ID needs not to be unique and can be any number except 0xFFFFFFFF.
			*										The ID can be used to cancel transactions. In case of multiple transactions sharing the same ID all transactions with this ID
			*										can be canceled using one call (see cancelTransaction()).
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the complete transaction failed and no callback will be invoked.
			*
			* @see	onCallMethodsComplete() CallMethodRequest callMethods() cancelTransaction() */
			EnumStatusCode callMethodsAsync(void* transactionHandle, const std::vector<CallMethodRequest>& methodCallRequest, OTUInt32 transactionId = 0, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Callback for the response to an asynchronous call methods transaction. This function must be overridden by the application session instance to handle the notification.
			*
			* @param [in]	transactionHandle		The cookie given on the callMethodsAsync call.
			* @param [in]	serviceResult			The status code of the service sent to the server.
			*										If the service status code is bad the complete transaction failed and the @p methodCallResult vector is undefined.
			* @param [in]	methodCallResult		A vector of status codes. For each request a status code is returned.
			*										@p methodCallRequest and @p methodCallResult are linked using the same index in the vector.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			*
			* @note	If a state change can't be distributed to a known server index anymore (e.g. its server information was removed),
			*		@p redundantServerIndex will return OTRedundantServerIndex_Invalid. Make sure to not use this special index to specify
			*		a single server or to use it as an index of an returned array.
			* @see	onCallMethodsAsync() CallMethodResult cancelTransaction() setServerInformation() */
			virtual void onCallMethodsComplete(void* transactionHandle, EnumStatusCode serviceResult, const std::vector<CallMethodResult>& methodCallResult, OTUInt32 redundantServerIndex);

			/*! Cancel transactions.
			* All asynchronous transactions with the given transactionId are canceled on the selected server.
			* They will respond with an EnumStatusCode_BadRequestCancelledByClient service result.
			* The passed requestId can be any number except 0 and 0xFFFFFFFF.
			*
			* @param [in]	transactionId				A number to identify a set of asynchronous transactions.
			*											Any transaction which has been invoked asynchronously using this ID will be canceled.
			* @param [out]	noOfCancelledTransactions	The number of canceled transactions.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete call failed.
			*
			* @see	writeAsync() readAsync() historyReadRawAsync() callMethodsAsync() */
			EnumStatusCode cancelTransaction(OTUInt32 transactionId, OTUInt32& noOfCancelledTransactions, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA cancel service.
			*
			* @param [in]	diagnosticsToReturn			Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	transactionId				A number to identify a set of asynchronous transactions.
			*											Any transaction which has been invoked asynchronously using this ID will be canceled.
			* @param [out]	stringTable					The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics			Diagnostic information for the service invocation.
			* @param [out]	noOfCancelledTransactions	The number of canceled transactions.
			* @param [in]	redundantServerIndex		The index of the redundant server where the service is called on.
			* @return									The status code of the service sent to the server.
			*											In case of bad service status code the complete call failed. */
			EnumStatusCode cancelTransaction(EnumDiagnosticsToReturn diagnosticsToReturn, OTUInt32 transactionId,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, OTUInt32& noOfCancelledTransactions, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Register nodes which are known to be used repeatedly.
			*
			* Registering nodes allows servers to set up anything needed so that the access operations will be more efficient.
			* Registered NodeIds are only guaranteed to be valid within the current session.
			* Clients shall unregister unneeded Ids immediately to free up resources.
			*
			* @param [in]	nodesToRegister			A vector of node IDs to be registered
			* @param [out]	newNodeIds				A vector of aliases for given registered node IDs.
			*										Both original and alias node IDs can be used in subsequent calls.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the @p newNodeIds vector is undefined.
			*
			* @see	unregisterNodes */
			EnumStatusCode registerNodes(const std::vector<NodeId>& nodesToRegister, std::vector<NodeId>& newNodeIds, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA RegisterNodes service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	nodesToRegister			A vector of node IDs to be registered
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [out]	newNodeIds				A vector of aliases for given registered node IDs.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			*										Both original and alias node IDs can be used in subsequent calls.
			* @return								The status code of the service sent to the server.
			*										In case of bad service status code the @p newNodeIds vector is undefined. */
			EnumStatusCode registerNodes(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<NodeId>& nodesToRegister,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, std::vector<NodeId>& newNodeIds, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Unregister nodes that have been previously registered within this session.
			*
			* Registering nodes allows servers to set up anything needed so that the access operations will be more efficient.
			* Registered NodeIds are only guaranteed to be valid within the current session.
			* Clients shall unregister unneeded Ids immediately to free up resources.
			*
			* @param [in]	nodesToUnregister		A vector of node IDs to be unregistered.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server.
			*
			* @see	registerNodes */
			EnumStatusCode unregisterNodes(const std::vector<NodeId>& nodesToUnregister, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);
			/*! This is an overloaded method that clients may use to request diagnostic information when invoking the OPC UA UnregisterNodes service.
			*
			* @param [in]	diagnosticsToReturn		Defines which kind of diagnostic information to return (see EnumDiagnosticsToReturn_ServiceLevel_SymbolicId et al.)
			* @param [in]	nodesToUnregister		A vector of node IDs to be unregistered.
			* @param [out]	stringTable				The string table that contains diagnostic-related strings (see StringTable).
			* @param [out]	serviceDiagnostics		Diagnostic information for the service invocation.
			* @param [in]	redundantServerIndex	The index of the redundant server where the service is called on.
			* @return								The status code of the service sent to the server. */
			EnumStatusCode unregisterNodes(EnumDiagnosticsToReturn diagnosticsToReturn, const std::vector<NodeId>& nodesToUnregister,
				StringTablePtr stringTable, DiagnosticInfo& serviceDiagnostics, OTUInt32 redundantServerIndex = OTRedundantServerIndex_Primary);

			/*! Sets the location of the application instance certificate and its private key file used for this session.
			*
			* This certificate is used for authentication in secured connections within this session.
			* If not specified, the application instance certificate specified in Applcation::setInstanceCertificate() is used.
			*
			* @param applicationInstanceCertificate The location of the application instance certificate.
			* @param privateKeyFile                 The location of the certificate's private key file.
			* @param password                       The pass phrase that was used to protect the private key.
			*
			* @note The location of the application instance certificate must be set before connecting the session. */
			EnumStatusCode setInstanceCertificate(const tstring& applicationInstanceCertificate, const tstring& privateKeyFile, const tstring& password);

			/*! Gets the information for certificate validation of server application instance certificates used in this session.
			*
			* @param pkiStoreConfiguration			The PKI store configuration used for this session.
			* @return								The status code if configuration could be retrieved. */
			EnumStatusCode getPkiStoreConfiguration(IPkiStoreConfiguration* pkiStoreConfiguration) const;

			/*! Sets the information for certificate validation of server application instance certificates used in this session.
			*
			* If not specified, the PKI store configuration specified in Application::setPkiStoreConfiguration() is used.
			*
			* @param pkiStoreConfiguration			The PKI store configuration used for this session.

			* @note This method must be called before connecting this session. */
			EnumStatusCode setPkiStoreConfiguration(const IPkiStoreConfiguration* pkiStoreConfiguration);
		private:
			/*! For internal use only */
			void initMembers();

			//InnerNodeId m_SessionId;
			//InnerUserIdentityToken m_userIdentityToken;

			/*! Forbid use assignment operator */
			RedundantSession& operator=(const RedundantSession&);
			/*! Forbid use of copy constructor */
			RedundantSession(const RedundantSession&);
		};
	} // end Client namespace
} // toolbox namespace end

#endif

#endif	// CLIENTREDUNDANTSESSION_H
