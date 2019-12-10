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

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Base.h"
#include "Enums.h"
#include "InnerApplicationDescription.h"
#include "ApplicationDescription.h"
#include "InnerMonitoringChange.h"
#include "MonitoringChange.h"
#include "EndpointDescription.h"
#include "InnerAccessPattern.h"
#include "AccessPattern.h"
#include "IDataValue.h"
#include "INodeId.h"
#include "PkiStoreConfiguration.h"
#include "ServerVariable.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	namespace Client
	{
		class Session;
		typedef ObjectPointer<Session> SessionPtr;
		class RedundantSession;
		typedef ObjectPointer<RedundantSession> RedundantSessionPtr;
	}
	namespace Server
	{
		class Endpoint;
		typedef ObjectPointer<Endpoint> EndpointPtr;
		class BaseNode;
	}

	namespace PubSub
	{
		class Connection;
		typedef ObjectPointer<Connection> ConnectionPtr;
		class PublishedDataSet;
		typedef ObjectPointer<PublishedDataSet> PublishedDataSetPtr;
		class SubscribedDataSet;
		typedef ObjectPointer<SubscribedDataSet> SubscribedDataSetPtr;
	}
	/*! Root class for all server and client applications. The Application is a singleton which may exist
	* only once.
	*
	* The application class is used for server implementations as well as for client implementations where the
	* initialization defines whether an application is an OPC UA server, an OPC UA client, or both.
	* After the initialization the application type can not be changed anymore. */
	class TBC_EXPORT Application
		: public Base
	{
	public:
		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		Application(TBHandle otbHandle);

	protected:
		/*! For internal use only */
		Application(bool suppressCoreInstanceCreate);

	public:
		/*! Destructor */
		virtual ~Application();

		/*! Returns the singleton instance */
		static ObjectPointer<Application> instance();
		/*! @overload */
		static ObjectPointer<const Application> constInstance();

		/////////////////////////////////////////////////////////////////////////
		// Common methods of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Initializes the application instance with the given @p description.
		*
		* This method initializes the communication stack as well as SDK-internal static variables.
		* A bad return code signals a principle problem (e.g. DLL can not be loaded) and the installation shall
		* be checked for errors.
		*
		* This shall be the first call on the application object after the configuration of the application object.
		*
		* @param description	An object describing the application instance. The description defines
		*						whether the application is a server or client (or both).
		*
		* @see uninitialize() start() */
		EnumStatusCode initialize(const IApplicationDescription* description);

		/*! Uninitializes the application. This must be the last call on the application instance.
		* Every call on the application after that call (except of initialize()) will return an error.
		*
		* A server application will close all connected Sessions and Endpoints.
		* A client application will disconnect all Sessions and child objects (e.g. Subscriptions).
		*
		* @see initialize() stop() */
		EnumStatusCode uninitialize();

		/*! Starts the application. Please note that you have to initialize the application before
		* this method can be called.
		*
		* @see initialize() stop()
		*
		* @note For server applications, any requests from clients are possible after calling this function. */
		EnumStatusCode start();

		/*! Stops the application. This method shall be called before calling uninitialize() to
		* close all running connections.
		*
		* For server applications, this method closes all open Sessions and Endpoints.
		* For client applications, this method closes all Sessions and Subscriptions.
		*
		* @see uninitialize() start() */
		EnumStatusCode stop();

		/*! Activates the given feature in case of a valid license code.
		*
		* @param product The product feature to activate
		* @param licenseKey The license key for the given @p product feature */
		EnumStatusCode activateLicense(EnumFeature product, const tstring& licenseKey);

		/*! Creates a new self-signed certificate for this application.
		*
		* This certificate is used for authentication in secured connections, no matter whether your
		* application is a client, a server or both.
		*
		* @param securityProfileUri     The security profile used for certificate creation.
		* @param certificateFileName    The path and name of the file to store the certificate (in DER format).
		* @param privateKeyFileName     The path and name of the file to store the private key (in PEM format).
		* @param privateKeyPassword     The password to encrypt the private key.
		* @param validityDuration       The duration of the certificate validity period in seconds.
		*                               The start time of the validity period is the time is the creation time of the certificate.
		* @param productName            The product name to be used as the CommonName (CN) in the certificate.
		* @param organizationName       The name of the organization that executes the server. This is usually not the vendor of the server.
		*                               This name is used as Organization (O) in the certificate.
		* @param hostNames              A comma separated list, containing the IP addresses and host names, that can be used to reach the server.
		*                               Each list entry has to be preceded by "IP:" or "DNS:".
		*                               Example: "DNS:MyMachine.MyDomain, IP:192.168.0.1"
		*
		* @note The initialize() method has to be invoked first, to specify application URI and other information.
		* @note Even though it is intended to create the private key in PEM, it is currently created in the DER format without password.
		*       None the less setInstanceCertificate() is prepared to accept the private key file and the same password parameter as it is used for this method.
		*       The behavior will be fixed at some time, but the usage will stay the same. */
		EnumStatusCode createSelfSignedCertificate(const tstring& securityProfileUri,
			const tstring& certificateFileName,
			const tstring& privateKeyFileName,
			const tstring& privateKeyPassword,
			OTUInt32 validityDuration,
			const tstring& productName,
			const tstring& organizationName,
			const tstring& hostNames) const;

		/*! @deprecated Please use setInstanceCertificate() instead.
		* Sets the location of the application instance certificate. */
		DEPRECATED(EnumStatusCode loadCertificate(const tstring& applicationInstanceCertificate) const);

		/*! @deprecated Please use setInstanceCertificate() instead.
		* Sets the location of the private key of the application instance certificate. */
		DEPRECATED(EnumStatusCode loadPrivateKey(const tstring& privateKeyFile, const tstring& password) const);

		/*! Sets the location of the application instance certificate and its private key file.
		* This certificate is used for authentication in secured connections, no matter whether your
		* application is a client, a server or both. For server applications with secured connections, you need to additionally
		* define the location of the folder that contains the client certificates to accept (see setPkiStoreConfiguration())
		*
		* The certificate is loaded during start().
		*
		* @param applicationInstanceCertificate The location of the application instance certificate.
		* @param privateKeyFile                 The location of the certificate's private key file.
		* @param password                       The pass phrase that was used to protect the private key.
		*
		* @note The location of the application instance certificate must be set before starting a server application. Clients
		* must set this location before trying to create a secure channel, otherwise this call can be left out. */
		EnumStatusCode setInstanceCertificate(const tstring& applicationInstanceCertificate, const tstring& privateKeyFile, const tstring& password) const;

		/*! Sets the location of the discovery server's application instance certificate. The certificate is used
		* to authenticate the discovery server. In client applications, the
		* certificate is used during findServers(). In server applications, the certificate is used
		* for authentication during server registration.
		*
		* @param discoveryServerCertificate The location of the discovery server's application instance certificate
		*
		* @see findServers() enableServerRegistration() */
		EnumStatusCode loadDiscoveryServerCertificate(const tstring& discoveryServerCertificate) const;

		/*! Sets the location of the server's DH parameter file.  The DH parameter file is used
		* by the HTTPS endpoint to generate single use DH keys for each TLS session.
		* The DH parameter file is necessary to ensure Perfect Forward Secrecy.
		*
		* @param dhParamFileLocation The location of the server's DH parameter file
		*
		* @note Setting this file is no longer necessary as the Stack ensures the Perfect Forward Secrecy via Elliptic Curves.
		*       This is only necessary if the Elliptic Curve Implementation of OpenSSL is disabled */
		EnumStatusCode setDhParamFileLocation(const tstring& dhParamFileLocation) const;

#if TB5_CLIENT
		/////////////////////////////////////////////////////////////////////////
		// Client-only methods of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Adds the given Session to the application. The session shall be created and configured before adding it
		* to the application.
		* A Session object can only be used after adding it to the application. A bad result code will be returned
		* in case of an invalid configuration of the given Session.
		*
		* @param session The session to add
		*
		* @see Client::Session
		* @note Client-only method. */
		EnumStatusCode addSession(Client::SessionPtr session);

		/*! Returns the sessions that belong to this application.
		*
		* @see addSession() removeSession() Client::Session
		* @note Client-only method. */
		std::vector<ObjectPointer<Client::Session> > getSessions();
		/*! @overload */
		std::vector<ObjectPointer<const Client::Session> > getSessions() const;

		/*! Removes the given session from the application. All child objects of that session will be also removed
		* and are not available anymore (e.g. Subscriptions).
		*
		* @param session The session to remove. The session must be disconnected from the server.
		*
		* @see Client::Session
		*
		* @note	Please note that the session must be disconnected (see Client::Session::disconnect()) before
		*		it can be removed from the application.
		* @note Client-only method. */
		EnumStatusCode removeSession(Client::SessionPtr session);

		/*! Adds the given RedundantSession to the application. The session shall be created and configured before adding it
		* to the application.
		* A RedundantSession object can only be used after adding it to the application. A bad result code will be returned
		* in case of an invalid configuration of the given RedundantSession.
		*
		* @param redundantSession The RedundantSession to add
		*
		* @see Client::RedundantSession
		* @note Client-only method. */
		EnumStatusCode addRedundantSession(Client::RedundantSessionPtr redundantSession);

		/*! Returns the RedundantSessions that belong to this application.
		*
		* @see addRedundantSession() removeRedundantSession() Client::RedundantSession
		* @note Client-only method. */
		std::vector<ObjectPointer<Client::RedundantSession> > getRedundantSessions();
		/*! @overload */
		std::vector<ObjectPointer<const Client::RedundantSession> > getRedundantSessions() const;

		/*! Removes the given RedundantSession from the application. All child objects of that session will be also removed
		* and are not available anymore (e.g. Subscriptions).
		*
		* @param redundantSession The RedundantSession to remove. The RedundantSession must be disconnected from the server.
		*
		* @see Client::RedundantSession
		*
		* @note	Please note that the RedundantSession must be disconnected (see Client::RedundantSession::disconnect()) before
		*		it can be removed from the application.
		* @note Client-only method. */
		EnumStatusCode removeRedundantSession(Client::RedundantSessionPtr redundantSession);

		/*! Retrieves the list of registered servers from a dedicated discovery server.
		* This method will first establish a connection with the discovery server, and then invokes the "FindServers" service.
		*
		* The establishment of connection is executed synchronously.
		* Keep in mind that this call can block up to the configured network timeout (@see setDefaultNetworkTimeout).
		* Do not invoke this method in a thread context that has to serve other tasks in parallel.
		*
		* @param discoveryServerUrl				The URL of the discovery server
		* @param serverURIs						A list of servers to return. All registered servers are returned if
		*										this list is empty.
		* @param[out] applicationDescriptions	A list of the registered servers.
		* @param pkiStoreConfiguration		The PKI store configuration used for this service (optional, if not specified the general application setting is used)
		* @param pInstanceCertificateFile	The filename of instance certificate used for this service (optional, if not specified the general application setting is used)
		* @param pPrivateKeyFile			The filename private key used for this service (optional, if not specified the general application setting is used)
		* @param pPassword					The password for private key used for this service (optional, if not specified the general application setting is used)
		* @param preferIPv4Resolution		The resolving of hostname part of the URL prefers IPv4 address
		*
		* @note Client-only method. */
		EnumStatusCode findServers(const tstring& discoveryServerUrl, const std::vector<tstring>& serverURIs,
			std::vector<ApplicationDescription>& applicationDescriptions,
			const IPkiStoreConfiguration* pkiStoreConfiguration = NULL,
			const tstring* pInstanceCertificateFile = NULL, const tstring* pPrivateKeyFile = NULL, const tstring* pPassword = NULL,
			bool preferIPv4Resolution = true) const;

		/*! Retrieves the list of endpoints from the server located at @p serverUrl by invoking
		* the server's "GetEndpoints" service.
		*
		* This method will first establish an unsecured connection with the server, and then invoke
		* the "GetEndpoints" service.
		*
		* The establishment of connection is executed synchronously.
		* Keep in mind that this can block up to the configured network timeout (@see setDefaultNetworkTimeout).
		* Do not invoke this method in a thread context that has to serve other tasks in parallel.
		*
		* The returned list of endpoints may be restricted by defining transport profiles which
		* endpoints have to support. The OPC UA specification currently defines the following transport
		* profiles:
		* @li	TransportProfileUri_UaTcp_UaSc_UaBinary
		* @li	TransportProfileUri_Https_UaBinary
		* @li	TransportProfileUri_Https_UaXml
		* @li	TransportProfileUri_SoapHttp_UaSc_UaBinary
		* @li	TransportProfileUri_SoapHttp_WsSc_UaBinary
		* @li	TransportProfileUri_SoapHttp_WsSc_UaXml
		* @note Currently only TransportProfileUri_UaTcp_UaSc_UaBinary and TransportProfileUri_Https_UaBinary are supported.
		*
		* @param serverUrl					The URL of the server to ask for endpoints. You may use findServers() to
		*									determine server URLs.
		* @param transportProfiles			A list of transport profiles that the endpoints should support. An empty
		*									list indicates that no restriction is applied.
		* @param[out] endpointDescriptions	The list of endpoints that the server provides
		* @param pkiStoreConfiguration		The PKI store configuration used for this service (optional, if not specified the general application setting is used)
		* @param pInstanceCertificateFile	The filename of instance certificate used for this service (optional, if not specified the general application setting is used)
		* @param pPrivateKeyFile			The filename private key used for this service (optional, if not specified the general application setting is used)
		* @param pPassword					The password for private key used for this service (optional, if not specified the general application setting is used)
		* @param preferIPv4Resolution		The resolving of hostname part of the URL prefers IPv4 address
		*
		* @note Client-only method. */
		EnumStatusCode getEndpointsFromServer(const tstring& serverUrl, const std::vector<tstring>& transportProfiles,
			std::vector<EndpointDescription>& endpointDescriptions,
			const IPkiStoreConfiguration* pkiStoreConfiguration = NULL,
			const tstring* pInstanceCertificateFile = NULL, const tstring* pPrivateKeyFile = NULL, const tstring* pPassword = NULL,
			bool preferIPv4Resolution = true) const;

#endif	// TB5_CLIENT
		/*! Returns the maximum number of monitored items created at server side per service call.
		*
		* @see setMaxMonitoredItemsPerService() */
		OTUInt32 getMaxMonitoredItemsPerService() const;
		/*! Sets the maximum of monitored items to be created within one service call.
		*
		* The number is limited by the message size, depending on the request size (e.g. filter, NodeId, ...).
		* On the other hand when creating too many monitored items at server side with one single call, the request may take
		* very long and other requests are not invoked.
		*
		* @param maxMonitoredItemsPerService The maximum number of monitored items to be created (see above for further explanation)
		*
		* @note Default value is 1000.
		* @note Client-only method. */
		EnumStatusCode setMaxMonitoredItemsPerService(OTUInt32 maxMonitoredItemsPerService);


		/////////////////////////////////////////////////////////////////////////
		// Server-only methods of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Adds the given endpoint to the application. The endpoint has to be configured properly
		* before it is added to the Application. An Endpoint may be added only once to an application.
		*
		* @param endpoint The Endpoint to add
		*
		* @see Server::Endpoint
		* @note Server-only method. */
		EnumStatusCode addEndpoint(Server::EndpointPtr endpoint);

		/*! Returns the endpoints that belong to this application.
		*
		* @see addEndpoint() removeEndpoint() Server::Endpoint
		* @note Server-only method. */
		std::vector<ObjectPointer<Server::Endpoint> > getEndpoints();
		/*! @overload */
		std::vector<ObjectPointer<const Server::Endpoint> > getEndpoints() const;

		/*! Removes the given endpoint from the application.
		*
		* @param endPoint The Endpoint to remove
		*
		* @see Server::Endpoint
		* @note Server-only method. */
		EnumStatusCode removeEndpoint(Server::EndpointPtr endPoint);

		/*! Callback method that will be called in case of any change in MonitoredItems,
		* e.g. if an item is added, removed or changed. Overriding this method, the server is able to adapt the I/O
		* to external data sources to the new monitoring requirements.
		*
		* For example a server that has to retrieve data also by subscriptions from devices or other servers must
		* be able to adapt these subscriptions to the requirements from the clients.
		*
		* @param nodes		The monitored nodes that are affected by the change.
		* @param changes	Describes the changes regarding monitoring of the affected @p nodes. This vector
		*					has the same size as the @p nodes vector.
		*
		* @note Server-only method. */
		virtual EnumStatusCode handleMonitoringChange(const std::vector<Server::BaseNode*>& nodes, const std::vector<Server::MonitoringChange>& changes);

		/*! Enables the registration of the server with a discovery server. In order to keep
		* the list of registered servers up-to-date, the discovery server requires each registered
		* server to re-register periodically.
		*
		* @param discoveryServerUrl		The URL of the discovery server
		* @param securityPolicy			The security policy used to connect to the discovery server.
		*								See Client::Session::setSecurityPolicy() for further reference on security policies.
		* @param messageSecurityMode	The message security mode used to connect to the discovery server.
		*								See Client::Session::setMessageSecurityMode() for further reference.
		* @param refreshPeriod			The period in milliseconds in which the (re-)registration of the server application
		*								is performed. A period of 10 minutes (i.e. 600000ms) is recommended.
		*
		* @note The first registration operation will be scheduled to be executed immediately.
		* @note Server-only method. */
		EnumStatusCode enableServerRegistration(const tstring& discoveryServerUrl, const tstring& securityPolicy, EnumMessageSecurityMode messageSecurityMode, OTUInt32 refreshPeriod);

		/*! Disables the cyclic registration of the server with a discovery server.
		*
		* @see enableServerRegistration()
		* @note Server-only method. */
		EnumStatusCode disableServerRegistration();

		/*! Adds or updates an access pattern which defines the user access rights for
		* variables and methods.
		*
		* An error is returned if the access pattern's key is invalid or if the
		* application is not a server.
		*
		* @note Server-only method.
		* @note The access field of all set access patterns should always be large enough to handle all user groups,
		*       not configured user groups don't get any user access rights and the SDK will produce log error messages. */
		EnumStatusCode setAccessPattern(const IAccessPattern* accessPattern);

		/*! Returns an array of the currently defined AccessPatterns.
		*
		* @note Server-only method. */
		EnumStatusCode getAccessPatterns(std::vector<AccessPattern>& accessPatterns) const;

		/*! Returns a BYTE value describing the access level of the specified user or users group, within the specified
		* AccessPattern.
		*
		* @note Server-only method. */
		EnumStatusCode getUserAccessLevel(OTUInt16 accessPatternKey, OTUInt32 userGroupIdx, OTUInt8* userAccessLevel) const;

		/*! Returns whether the given group of services is enabled for a
		* server application.
		*
		* @see setEnableServiceGroup()
		* @note Server-only method.
		* @note By default, all services are enabled in a server application. */
		bool isServiceGroupEnabled(EnumServiceGroup serviceGroup) const;
		/*! Enables or disables a specific group of services in a server application.
		* This method can be used to limit the functionality of the server
		* application.
		*
		* @param serviceGroup The group of services to enable/disable
		* @param enable If true, the given group of services is enabled
		*
		* @note Server-only method.
		* @note By default, all services are enabled in a server application. */
		EnumStatusCode setEnableServiceGroup(EnumServiceGroup serviceGroup, bool enable);

		/*! Returns if the creation of the default addresspace shall be suppressed or not.
		*
		* @see suppressAddresspaceCreation()
		* @note Server-only method */
		bool getSuppressAddresspaceCreation() const;
		/*! Suppresses or enables the creation of the default addresspace.
		* The default behavior is that the default addresspace will be created.
		*
		* @note Server-only method
		* @note This method must be called before initialize() */
		EnumStatusCode suppressAddresspaceCreation(bool suppress);

		/////////////////////////////////////////////////////////////////////////
		// Common Attributes of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Returns the application description that has been provided with the initialization
		* of the application.
		*
		* @see initialize() */
		const IApplicationDescription* getDescription() const;

		/*! Returns the list of preferred locales
		*
		* @param[out] preferredLocales	An ordered list of preferred locales
		*
		* @see setPreferredLocales() */
		EnumStatusCode getPreferredLocales(std::vector<tstring>* preferredLocales) const;
		/*! Sets the list of preferred locales. This ordered list contains locales conforming to RFC 3066.
		* The first list entry contains the locale with the highest priority.
		*
		* For client applications, this list is passed to the server to retrieve the best matching
		* localized text value in requests (e.g. when a client reads the DisplayName attribute
		* of a node). The preferred locales in application is used as default for new client session.
		*
		* For server applications, the provided list of preferred locales is used to decide which
		* localized text value to deliver to the client if it has not provided a list of preferred locales
		* or if the server does not have a matching translation for the requested locales.
		*
		* @param preferredLocales	An ordered list of preferred locales. Locales must adhere to RFC 3066.
		*							The first entry contains the locale with the highest priority.
		*
		* @see Client::Session::setPreferredLocales() */
		EnumStatusCode setPreferredLocales(const std::vector<tstring>& preferredLocales);

		/*! Returns the timeout for a service group.
		*
		* @see setServiceTimeout()
		* @note Client-only method. */
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
		* @see EnumTimeoutGroup for mapping of timeout groups and methods
		* @note Client-only method. */
		EnumStatusCode setServiceTimeout(EnumTimeoutGroup group, OTUInt32 timeout);

		/*! Returns the maximum number of piped publish request.
		*
		* @see setMaxPipedPublishRequests() */
		OTUInt32 getMaxPipedPublishRequests() const;
		/*! For client applications the provided number of @p maxPipedPublishRequests limits the number
		* of publish requests the client sends to a server. At any point in time, the client will not fill
		* the server's publish request queue with more than the given number of requests.
		*
		* For server applications @p maxPipedPublishRequests sets the maximum number of received publish requests
		* a server session store in its publish request queue. If this number has been reached and more publish requests
		* are received from a client, the oldest publish requests from the queue will be answered with status
		* code EnumStatusCode_BadTooManyPublishRequests.
		*
		* @param maxPipedPublishRequests The maximum number of publish requests (see above for further explanation)
		*
		* @note Default value is 5. */
		EnumStatusCode setMaxPipedPublishRequests(OTUInt32 maxPipedPublishRequests);

		/*! Returns the major version of the underlying SDK.
		*
		* @see getToolboxMinorVersion() getToolboxPatchVersion() */
		unsigned short getToolboxMajorVersion() const;

		/*! Returns the minor version of the underlying SDK.
		*
		* @see getToolboxMajorVersion() getToolboxPatchVersion() */
		unsigned short getToolboxMinorVersion() const;

		/*! Returns the patch version of the underlying SDK.
		*
		* @see getToolboxMajorVersion() getToolboxMinorVersion() */
		unsigned short getToolboxPatchVersion() const;

		/*! Returns the build number of the underlying SDK. */
		OTUInt32 getToolboxBuildNumber() const;

		/*! Returns the evaluation time (in milliseconds) for unlicensed SDK installations.
		* After the demo time has elapsed, the SDK stops working.
		*
		* @see setDemoTime() */
		OTUInt32 getDemoTime() const;
		/*! Sets the evaluation time (in milliseconds) for unlicensed SDK installations.
		*
		* The demo time is used to stop functionality after demo time (in ms) is expired if no license is activated.
		* The demo time cannot be set to a value greater than 90 minutes (90 * 60 * 1000).
		*
		* @note Default value is 90 * 60 * 1000, i.e. 90 minutes. */
		EnumStatusCode setDemoTime(OTUInt32 demoTime);

		/*! Returns the channel sharing configuration.
		*
		* @see setChannelSharing() */
		bool getChannelSharing() const;
		/*! Sets the channel sharing configuration.
		*
		* The delivered stack has a hard-coded maximum of 50 secure channel. Increasing this limit needs re-compilation of the deliverables.
		*
		* Channel sharing is used to share one secure channel between multiple client sessions.
		* A secure channel can be shared only if URL, security configuration, ... is identical for client sessions.
		*
		* @note The effect at server side is server implementation dependent.
		*       The server can handle each secure channel within a separate thread and increase performance by parallel execution.
		*       However exhausting work at server side should be executed asynchronously in general, so parallel execution can be implemented for a single secure channel as well.
		*
		* @note Default value is false, i.e. channels are not shared. */
		EnumStatusCode setChannelSharing(bool channelSharing);

		/*! Validates an application instance certificate.
		*
		* The certificate is validated with the given PKI store.
		* The PKI store configuration specifies the validation options.
		*
		* @see IPkiStoreConfiguration
		*
		* @param pkiStoreConfiguration	The PKI store configuration used for validation.
		* @param pCertificate			The certificate to be validated.
		* @param pApplicationUri		The application URL of the application the certificate belongs to.
		*								This parameter can be NULL if the PKI store configuration does not request URL check @see IPkiStoreConfiguration::checkUrlMatch()
		* @note The rejected certificates location within @p pkiStoreConfiguration will be ignored by this method. */
		EnumStatusCode validateCertificate(const IPkiStoreConfiguration* pkiStoreConfiguration, const IByteString *pCertificate, const tstring* pApplicationUri);

		/////////////////////////////////////////////////////////////////////////
		// Client-only Attributes of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Returns the default timeout (in milliseconds) to be used when trying to establish connections over the network.
		*
		* @see setDefaultNetworkTimeout()
		* @note Client-only method. */
		OTUInt32 getDefaultNetworkTimeout() const;
		/*! Sets the default timeout to be used when trying to establish connections over the network.
		* This value will be used as default value for all new sessions, but may be overridden for each session.
		*
		* @param defaultNetworkTimeout The default network timeout in milliseconds
		*
		* @see Client::Session::setNetworkTimeout()
		* @note Default value is 60000, i.e. 60s.
		* @note Client-only method. */
		EnumStatusCode setDefaultNetworkTimeout(OTUInt32 defaultNetworkTimeout);

		/*! @deprecated use Application::getServiceTimeout to get service specific timeouts. */
		DEPRECATED(OTUInt32 getDefaultRequestTimeoutHint() const);
		/*! @deprecated use Application::setServiceTimeout to set service specific timeouts.
		*
		* Sets the request timeout (in milliseconds) used for all service calls issued on this session.
		*
		* @param defaultRequestTimeoutHint	Timeout in milliseconds for a service */
		DEPRECATED(EnumStatusCode setDefaultRequestTimeoutHint(OTUInt32 defaultRequestTimeoutHint));

		/*! Returns the default interval in (in ms) when a client tries to re-connect of an interrupted session.
		*
		* @see setDefaultAutoReconnectInterval()
		* @note Client-only method. */
		OTUInt32 getDefaultAutoReconnectInterval() const;
		/*! Sets the default interval (in ms) when a client tries to re-connect of an interrupted session.
		*
		* All client sessions will use this value when created.
		* A value of 0 means no re-connect is done at all. In this case the application is responsible to repair interrupted sessions.
		* Minimum supported interval is 1000 ms, Typical values are e.g. 10000, 20000.
		*
		* @see Client::Session::setAutoReconnectInterval()
		* @note Default value is 0, i.e. automatic re-connect of sessions is disabled.
		* @note Client-only method. */
		EnumStatusCode setDefaultAutoReconnectInterval(OTUInt32 defaultAutoReconnectInterval);

		/*! Returns the default interval (in ms) for testing the connection to a server.
		*
		* @see setDefaultConnectionMonitoringInterval()
		* @note Client-only method. */
		OTUInt32 getDefaultConnectionMonitoringInterval() const;
		/*! Sets the default interval (in ms) for testing the connection to a server.
		*
		* All client sessions will use this value when created.
		* If connection break is recognized, the status of the session changes to disconnected.
		* Interval 0 means no connection test at all.
		* Minimum supported interval is 100 ms, typical intervals are between 5000 and 10000.
		*
		* @see Client::Session::setConnectionMonitoringInterval()
		* @note Default value is 0, i.e. monitoring of connections is disabled.
		* @note Client-only method. */
		EnumStatusCode setDefaultConnectionMonitoringInterval(OTUInt32 defaultConnectionMonitoringInterval);


		/////////////////////////////////////////////////////////////////////////
		// Server-only Attributes of class Application
		/////////////////////////////////////////////////////////////////////////

		/*! Gets the information for certificate validation of client instance certificates.
		*
		* @see setPkiStoreConfiguration() */
		PkiStoreConfiguration getPkiStoreConfiguration() const;
		/*! Sets the information for certificate validation of client instance certificates.
		*
		* @see IPkiStoreConfiguration
		*
		* @note This method must be called for all server and client applications.
		* @note The information must be set before initializing the application.
		*       Changing the information after initialize() has no effect. */
		EnumStatusCode setPkiStoreConfiguration(const IPkiStoreConfiguration* pkiStoreConfiguration);

		/*! Returns the default queue size for DataChange-MonitoredItems.
		*
		* @see setDefaultDataChangeMonitoringQueueSize()
		* @note Server-only method. */
		OTUInt32 getDefaultDataChangeMonitoringQueueSize() const;
		/*! Sets the default queue size for DataChange-MonitoredItems.
		*
		* The queue size determines the number of data value changes that the
		* server may queue. This number is used when a client does not request
		* a specific queue size.
		*
		* @param defaultMonitoringQueueSize The queue size of the MonitoredItems data change queue.
		*
		* @see setMaxDataChangeMonitoringQueueSize()
		* @note Default value is 1.
		* @note Server-only method. */
		EnumStatusCode setDefaultDataChangeMonitoringQueueSize(OTUInt32 defaultMonitoringQueueSize);

		/*! Returns the maximum allowed queue size for DataChange-MonitoredItems.
		*
		* @see setMaxDataChangeMonitoringQueueSize()
		* @note Server-only method. */
		OTUInt32 getMaxDataChangeMonitoringQueueSize() const;
		/*! Sets the maximum allowed queue size for DataChange-MonitoredItems.
		*
		* @param maxMonitoringQueueSize The maximum queue size of the MonitoredItems data change queue
		*
		* @see setDefaultDataChangeMonitoringQueueSize()
		* @note Default value is 1000.
		* @note Server-only method. */
		EnumStatusCode setMaxDataChangeMonitoringQueueSize(OTUInt32 maxMonitoringQueueSize);

		/*! Returns the maximum allowed queue size for Event-MonitoredItems.
		*
		* @see setMaxEventMonitoringQueueSize()
		* @note Server-only method. */
		OTUInt32 getMaxEventMonitoringQueueSize() const;
		/*! Sets the maximum allowed queue size for Event-MonitoredItems. This queue size
		* will be used for all MonitoredItem queues that contain events.
		*
		* @param maxMonitoringQueueSize The maximum queue size of the MonitoredItems data change queue
		*
		* @note Default value is 1000.
		* @note Server-only method. */
		EnumStatusCode setMaxEventMonitoringQueueSize(OTUInt32 maxMonitoringQueueSize);

		/*! Returns the minimum acceptable session timeout (in ms) for new created sessions.
		*
		* @see setMinSessionTimeout()
		* @note Server-only method. */
		OTUInt32 getMinSessionTimeout() const;
		/*! Sets the minimum acceptable session timeout (in ms) for new created sessions.
		*
		* @note Default value is 1000, i.e. 1 second
		* @note Server-only method. */
		EnumStatusCode setMinSessionTimeout(OTUInt32 minSessionTimeout);

		/*! Returns the maximum acceptable session timeout (in ms) for new created sessions.
		*
		* @see setMaxSessionTimeout()
		* @note Server-only method. */
		OTUInt32 getMaxSessionTimeout() const;
		/*! Sets the maximum acceptable session timeout (in ms) for new created sessions.
		*
		* @note Default value is 600000, i.e. 10 minutes
		* @note Server-only method. */
		EnumStatusCode setMaxSessionTimeout(OTUInt32 maxSessionTimeout);

		/*! Returns the minimum interval (in milliseconds) that may be set for updating diagnostic information in the
		* address space of a server.
		*
		* @see setMinDiagnosticsUpdateInterval()
		* @note Server-only method. */
		OTUInt32 getMinDiagnosticsUpdateInterval() const;
		/*! Sets the minimum interval (in milliseconds) that may be set for updating diagnostic information in the
		* address space of a server.
		*
		* @param minDiagnosticsUpdateInterval The minimal update interval in milliseconds for diagnostic information
		*
		* @see Server::Diagnostics
		* @note Default value is 100.
		* @note Server-only method. */
		EnumStatusCode setMinDiagnosticsUpdateInterval(OTUInt32 minDiagnosticsUpdateInterval);

		/*! Returns the maximum interval (in milliseconds) that may be set for updating diagnostic information in the
		* address space of a server.
		*
		* @see setMaxDiagnosticsUpdateInterval()
		* @note Server-only method. */
		OTUInt32 getMaxDiagnosticsUpdateInterval() const;
		/*! Sets the maximum interval (in milliseconds) that may be set for updating diagnostic information in the
		* address space of a server.
		*
		* @param maxDiagnosticsUpdateInterval The maximum update interval in milliseconds for diagnostic information
		*
		* @see Server::Diagnostics
		* @note Default value is 24 * 60 * 60 * 1000, i.e. 24 hours.
		* @note Server-only method. */
		EnumStatusCode setMaxDiagnosticsUpdateInterval(OTUInt32 maxDiagnosticsUpdateInterval);

		/*! Returns the maximum number of continuation points per session for browse services
		*
		* @see setMaxBrowseContinuationPoints()
		* @note Server-only method. */
		OTUInt16 getMaxBrowseContinuationPoints() const;
		/*! Sets the maximum number of continuation points per session for browse services
		*
		* When processing browse requests the client can restrict the number of results per request (see BrowseTransaction).
		* Also the server is allowed to return less results than the maximum requested.
		* In this case a continuation point is returned to the client, which can retrieve further results from the server.
		* Those continuation points can consume memory or other system resources, so the number shall be restricted (per session).
		*
		* @param numberOfBrowseContinuationPoints The maximum number of nodes continuation points per session for browse services.
		*
		* @note Default value is 100.
		*
		* @note Server-only method. */
		EnumStatusCode setMaxBrowseContinuationPoints(OTUInt16 numberOfBrowseContinuationPoints);

		/*! Returns the maximum number of continuation points per session for history read services
		*
		* @see setMaxHistoryContinuationPoints()
		* @note Server-only method. */
		OTUInt16 getMaxHistoryContinuationPoints() const;
		/*! Sets the maximum number of continuation points per session for history read services
		*
		* When processing history read requests the client can restrict the number of results per request.
		* (see HistoryReadRawTransaction, HistoryReadProcessedTransaction, HistoryReadEventTransaction).
		* Also the server is allowed to return less results than the maximum requested.
		* In this case a continuation point is returned to the client, which can retrieve further results from the server.
		* Those continuation points can consume memory or other system resources, so the number shall be restricted (per session).
		*
		* @param numberOfHistoryContinuationPoints The maximum number of nodes continuation points per session for history read services.
		*
		* @note Default value is 100.
		*
		* @note A single history read transaction can consume more than one continuation point.
		* The number of necessary continuation points can be up to the number of nodes within a transaction.
		*
		* @note Server-only method. */
		EnumStatusCode setMaxHistoryContinuationPoints(OTUInt16 numberOfHistoryContinuationPoints);

		/*! Returns the maximum number of continuation points per session for query services
		*
		* @see setMaxQueryContinuationPoints()
		* @note Server-only method. */
		OTUInt16 getMaxQueryContinuationPoints() const;
		/*! Sets the maximum number of continuation points per session for query services
		*
		* When processing a query the client can restrict the number of results per request.
		* Also the server is allowed to return less results than the maximum requested (see setMaxDataSetsToReturn).
		* In this case a continuation point is returned to the client, which can retrieve further results from the server.
		* Those continuation points can consume memory or other system resources, so the number shall be restricted (per session).
		*
		* @param numberOfQueryContinuationPoints The maximum number of nodes continuation points per session for query services.
		*
		* @note Default value is 10.
		*
		* @note A single query can consume more than one continuation point.
		*
		* @note Server-only method. */
		EnumStatusCode setMaxQueryContinuationPoints(OTUInt16 numberOfQueryContinuationPoints);

		/*! Returns the maximum number of data sets a server should return in a response to a query request.
		*
		* @see setMaxDataSetsToReturn()
		* @note Server-only method. */
		OTUInt32 getMaxDataSetsToReturn() const;
		/*! Sets the maximum number of data sets a server should return in a response to a query request.
		*
		* @note Default value is 0, i.e. the server does not limit the number of query data sets to return to a client.
		* @note Server-only method. */
		EnumStatusCode setMaxDataSetsToReturn(OTUInt32 maxDataSetsToReturn);

		/*! Returns the maximum number of references a server should return in a response to a Browse or BrowseNext request.
		*
		* @see setMaxReferencesToReturn()
		* @note Server-only method. */
		OTUInt32 getMaxReferencesToReturn() const;
		/*! Sets the maximum number of references a server should return in a response to a Browse or BrowseNext request.
		*
		* @note Default value is 0, i.e. the server does not limit the number of references to return to a client.
		* @note Server-only method. */
		EnumStatusCode setMaxReferencesToReturn(OTUInt32 maxReferencesToReturn);

		/*! Returns the maximum number of nodes a server shall analyze per query request
		*
		* @see setMaxNodesToAnalyzePerQueryRequest()
		* @note Server-only method. */
		OTUInt32 getMaxNodesToAnalyzePerQueryRequest() const;
		/*! Sets the maximum number of nodes a server shall analyze per query request (QueryFirst/QueryNext).
		*
		* When processing a query request, a server walks over its address space and decides
		* for each encountered node whether is it to be included in the query response or not (depending on the
		* filter provided by a client). This process may be very time consuming and may impose high load on the server.
		* Thus, in order to keep the server responsible, the number of nodes analyzed for each query request
		* should be restricted by a server application.
		*
		* @param numberOfNodesAnalyzedPerQueryRequest The maximum number of nodes in the address space which are to be analyzed per query request. The value 0 is not permitted.
		*
		* @note Default value is 100.
		* @note Server-only method. */
		EnumStatusCode setMaxNodesToAnalyzePerQueryRequest(OTUInt32 numberOfNodesAnalyzedPerQueryRequest);

		/*! Returns the minimum allowed publishing interval (in ms) for Subscriptions.
		*
		* @see setMinPublishingInterval()
		* @note Server-only method. */
		double getMinPublishingInterval() const;

		/*! Sets the minimum allowed publishing interval (in ms) for Subscriptions.
		*
		* The publishing interval requested from a client can be revised by a server. A very small publishing interval may cause high CPU load.
		* The SDK revises the requested publish interval into the defined range set.
		* Allowed range: 1.0 - 1.7976931348623158e+308
		*
		* A server application can revise the publishing interval programmatically when Server::Subscription::onCreate (onModify) is invoked,
		* using Server::Subscription::setPublishingInterval() (within the defined range).
		*
		* @param minPublishingInterval The minimum acceptable publishing interval (in ms) for Subscriptions. The value 0.0 is not permitted.
		*
		* @note Default value is 10.
		* @note Server-only method. */
		EnumStatusCode setMinPublishingInterval(double minPublishingInterval);

		/*! Returns the maximum allowed publishing interval (in ms) for Subscriptions.
		* @see setMaxPublishingInterval()
		* @note Server-only method. */
		double getMaxPublishingInterval() const;

		/*! Sets the maximum allowed publishing interval (in ms) for Subscriptions.
		*
		* The publishing interval requested from a client can be revised by a server. A very small publishing interval may cause high CPU load.
		* The SDK revises the requested publish interval into the defined range set.
		* Allowed range: 1.0 - 1.7976931348623158e+308
		*
		* A server application can revise the publishing interval programmatically when Server::Subscription::onCreate (onModify) is invoked,
		* using Server::Subscription::setPublishingInterval() (within the defined range).
		*
		* @param maxPublishingInterval The maximum acceptable publishing interval (in ms) for Subscriptions. The value 0.0 is not permitted.
		*
		* @note Default value is 10 * 60 * 1000, i.e. 10 minutes.
		* @note Server-only method. */
		EnumStatusCode setMaxPublishingInterval(double maxPublishingInterval);

		/*! Returns the minimum sampling interval (in ms) that shall be accepted for DataChange-MonitoredItems.
		*
		* @see setMinSamplingInterval()
		* @note Server-only method. */
		double getMinSamplingInterval() const;
		/*! Sets the minimum sampling interval (in ms) that shall be accepted for DataChange-MonitoredItems.
		*
		* The sampling interval requested from a client can be revised by a server.
		* The SDK revises the requested sampling interval into the defined range set.
		* Allowed range: 1.0 - 2147483647.0.
		*
		* A server application can revise the sampling interval programmatically when Server::Subscription::handleCreateMonitoredItems (handleModifyMonitoredItems) is invoked,
		* via Server::MonitoredItem::setSamplingInterval() (within the defined range).
		*
		* @param minSamplingInterval The minimum acceptable sampling interval (in ms) for DataChange-MonitoredItems.
		*
		* @note Default value is 0.
		* @note Server-only method. */
		EnumStatusCode setMinSamplingInterval(double minSamplingInterval);

		/*! Returns the maximum sampling interval (in ms) that shall be accepted for DataChange-MonitoredItems.
		*
		* @see setMaxSamplingInterval()
		* @note Server-only method. */
		double getMaxSamplingInterval() const;
		/*! Sets the maximum sampling interval (in ms) that shall be accepted for DataChange-MonitoredItems.
		*
		* The sampling interval requested from a client can be revised by a server.
		* The SDK revises the requested sampling interval into the defined range set.
		* Allowed range: 1.0 - 2147483647.0.
		*
		* A server application can revise the sampling interval programmatically when Server::Subscription::handleCreateMonitoredItems (handleModifyMonitoredItems) is invoked,
		* via Server::MonitoredItem::setSamplingInterval() (within the defined range).
		*
		* @param maxSamplingInterval The maximum acceptable sampling interval (in ms) for DataChange-MonitoredItems.
		*
		* @note Default value is 10000, i.e. 10s.
		* @note Server-only method. */
		EnumStatusCode setMaxSamplingInterval(double maxSamplingInterval);

		/*! Returns whether the server emits certain types of audit events (see setEnableAuditEvents() for details)
		*
		* @see setEnableAuditEvents()
		* @note Server-only method. */
		bool getEnableAuditEvents() const;
		/*! Sets whether the server shall emit the following audit events if the corresponding events occur:
		* @li AuditUrlMismatchEvent:		This audit event is emitted when a client creates a session with the server
		*									and the host part of the client-provided endpoint URL does not match
		*									one of the server's host names.
		* @li AuditCreateSessionEvent:		This audit event is emitted when a client creates a session with the server.
		* @li AuditActivateSessionEvent:	This audit event is emitted when a client activates a session with the server.
		* @li AuditCancelEvent:				This audit event is emitted when the server has processed a 'cancel' request
		*									from the client.
		*
		* @note Server-only method.
		* @note Default value is 'false'. */
		EnumStatusCode setEnableAuditEvents(bool enableAuditEvents);

		/*! Returns the name of the manufacturer of this application
		*
		* @note Server-only method.
		* @see setManufacturerName */
		tstring getManufacturerName() const;
		/*! Sets the name of the manufacturer of this application. This name can be set by the user implementation.
		* The manufacturer name is exposed as "ManufacturerName" variable in the
		* AddressSpace (Server/ServerStatus/BuildInfo/ManufacturerName).
		*
		* @note Default value is an empty string.
		* @note The manufacturer name must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setManufacturerName(const tstring& manufacturerName);

		/*! Returns the major version of this application.
		*
		* @see setMajorVersion()
		* @note Server-only method. */
		unsigned short getMajorVersion() const;
		/*! Sets the major version of this application. This version can be set by the user implementation.
		* The major version is exposed as part of the "SoftwareVersion" variable in the
		* AddressSpace (Server/ServerStatus/BuildInfo/SoftwareVersion).
		*
		* @see setMinorVersion() setPatchVersion()
		* @note Default value is 0.
		* @note The major version must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setMajorVersion(unsigned short majorVersion);

		/*! Returns the minor version of this application.
		*
		* @see setMinorVersion()
		* @note Server-only method. */
		unsigned short getMinorVersion() const;
		/*! Sets the minor version of this application. This version can be set by the user implementation.
		* The minor version is exposed as part of the "SoftwareVersion" variable in the
		* AddressSpace (Server/ServerStatus/BuildInfo/SoftwareVersion).
		*
		* @see setMajorVersion() setPatchVersion()
		* @note Default value is 0.
		* @note The minor version must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setMinorVersion(unsigned short minorVersion);

		/*! Returns the patch version of this application.
		*
		* @see setPatchVersion()
		* @note Server-only method. */
		unsigned short getPatchVersion() const;
		/*! Sets the patch version of this application. This version can be set by the user implementation.
		* The patch version is exposed as part of the "SoftwareVersion" variable in the
		* AddressSpace (Server/ServerStatus/BuildInfo/SoftwareVersion).
		*
		* @see setMajorVersion() setMinorVersion()
		* @note Default value is 0.
		* @note The patch version must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setPatchVersion(unsigned short patchVersion);

		/*! Returns the build number of this application.
		*
		* @see setBuildNumber()
		* @note Server-only method. */
		OTUInt32 getBuildNumber() const;
		/*! Sets the build number of this application. This number can be set by the user implementation.
		* The build number is exposed as "BuildNumber" variable in the
		* AddressSpace (Server/ServerStatus/BuildInfo/BuildNumber).
		*
		* @note Default value is 0.
		* @note The build number must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setBuildNumber(OTUInt32 buildNumber);

		/*! Returns the build date of this application
		*
		* @see setBuildDate()
		* @note Server-only method. */
		DateTime getBuildDate() const;
		/*! Sets the build date of this application. The date can be set by the user implementation.
		* The build date is exposed as "BuildDate" variable in the AddressSpace (Server/ServerStatus/BuildInfo/BuildDate)
		*
		* @note Default value is January 1, 1601, 00:00 (UTC).
		* @note The build date must be set before the application is initialized (see initialize())
		* @note Server-only method. */
		EnumStatusCode setBuildDate(const DateTime& buildDate);

		/*! Returns the redundancy mode (according to OPC UA) that the server provides to clients.
		*
		* @see setServerRedundancyMode()
		* @note Server-only method. */
		EnumRedundancySupport getServerRedundancyMode() const;
		/*! Sets the redundancy mode (according to OPC UA) that the server provides to clients.
		*
		* The supported redundancy mode is exposed as "RedundancySupport" variable in the
		* address space (Server/ServerRedundancy/RedundancySupport).
		*
		* @note Server-only method.
		* @note If any non-transparent redundancy mode is configured, also the application descriptions of all
		* redundancy partners has to be provided @see setRedundantServerArray */
		EnumStatusCode setServerRedundancyMode(EnumRedundancySupport redundancyMode);

		/*! Gets the application description of all servers that are part of the redundant array of servers.
		*
		* @see setRedundantServerArray()
		* @note Server-only method. */
		EnumStatusCode getRedundantServerArray(std::vector<ApplicationDescription>& redundantServerDescriptions) const;
		/*! Sets the application description of all servers that are part of the redundant array of servers.
		*
		* If the redundant array consists of three servers, for example, each server needs to provide
		* the application descriptions of all three servers to this method (including the description of the itself).
		*
		* The SDK uses the provided information for two purposes:
		* @li	The FindServer service of each server in the redundant array returns the provided
		*		list of application descriptions. This allows clients that know the discovery endpoint of only one server
		*		to retrieve the discovery endpoint for any other server in the redundant array.
		* @li 	The application URI contained in each application description is exposed in the address
		*		space as "ServerUriArray" variable (Server/ServerRedundancy/ServerUriArray). This
		*		allows clients to identify the URIs of all servers that are part of the redundant server array.
		*
		* @note This setting applies only servers that support non-transparent redundancy.
		* @note Server-only method. */
		EnumStatusCode setRedundantServerArray(const std::vector<ApplicationDescription>& redundantServerDescriptions);

		/*! Return the configured server profile URIs.
		*
		* @param serverProfilesUris		The profiles / facets the server application supports
		*
		* @see addServerProfileURI */
		EnumStatusCode getServerProfileURIs(std::vector<tstring>& serverProfilesUris) const;
		/*! Adds a supported profile or facet URI to an server application.
		*
		* All supported profiles and facets will be displayed in the ServerCapablities / ServerProfileArray node.
		* A server shall expose all profiles / facets, which are supported by this server
		*
		* Addtitional facets would be e.g.
		* @li	http://opcfoundation.org/UA-Profile/Server/HistoricalRawData
		* @li	http://opcfoundation.org/UA-Profile/Server/AggregateHistorical
		* @li	http://opcfoundation.org/UA-Profile/Server/ACExclusiveAlarming
		* @li	http://opcfoundation.org/UA-Profile/Server/VisibleRedundancy
		* @li	http://opcfoundation.org/UA-Profile/Server/FileAccess
		* @li ...
		*
		* @see https://opcfoundation-onlineapplications.org/ProfileReporting/ for other facets URIs.
		*
		* @param serverProfileUri		A profile / facet the server application supports
		*
		* The SDK adds the full-featured "Standard UA Server Profile", i.e "http://opcfoundation.org/UA-Profile/Server/StandardUA" by default, which is always supported. */
		EnumStatusCode addServerProfileURI(const tstring& serverProfileUri);

		/*! Adds a PubSub connection to the application
		*
		* @param pubSubConnection The connection to add
		*
		* @note The name of the Connection must be valid and unique among all other Connections */
		EnumStatusCode addPubSubConnection(PubSub::ConnectionPtr pubSubConnection);

		/*! Removes a PubSub connection from the application
		*
		* @param pubSubConnection The connection to be removed */
		EnumStatusCode removePubSubConnection(PubSub::ConnectionPtr pubSubConnection);

		/*! Gets all PubSub connections */
		std::vector<PubSub::ConnectionPtr> getPubSubConnections() const;

		/*! Adds a PubSub PublishedDataSet to the application
		*
		* Adding a PublishedDataSet to the application is not mandatory to publish data but it is recommended.
		* Added PublishedDataSets will be kept alive by the SDK and can be exposed in a Server address space,
		* even when the PublishedDataSets are not attached to any DataSetWriter.
		* PublishedDataSets, which are attached to a DataSetWriter will be kept alive and can be exposed in a
		* Server address space, even without being added to the Application.
		*
		* @param publishedDataSet The PublishedDataSet to add
		*
		* @note The name of the PublishedDataSet must be valid and unique among all other PublishedDataSets */
		EnumStatusCode addPubSubPublishedDataSet(PubSub::PublishedDataSetPtr publishedDataSet);

		/*! Removes a PubSub PublishedDataSet from the application
		*
		* @param publishedDataSet The PublishedDataSet to be removed */
		EnumStatusCode removePubSubPublishedDataSet(PubSub::PublishedDataSetPtr publishedDataSet);

		/*! Gets all PubSub PublishedDataSets */
		std::vector<PubSub::PublishedDataSetPtr> getPubSubPublishedDataSets() const;

		/*! Adds a PubSub SubscribedDataSet to the application
		*
		* Adding a SubscribedDataSet to the application is not mandatory to publish data but it is recommended.
		* Added SubscribedDataSets will be kept alive by the SDK and can be exposed in a Server address space,
		* even when the SubscribedDataSets are not attached to any DataSetWriter.
		* SubscribedDataSets, which are attached to a DataSetWriter will be kept alive and can be exposed in a
		* Server address space, even without being added to the Application.
		*
		* @param subscribedDataSet The SubscribedDataSet to add
		*
		* @note The name of the SubscribedDataSet must be valid and unique among all other SubscribedDataSets */
		EnumStatusCode addPubSubSubscribedDataSet(PubSub::SubscribedDataSetPtr subscribedDataSet);

		/*! Removes a PubSub SubscribedDataSet from the application
		*
		* @param subscribedDataSet The SubscribedDataSet to be removed */
		EnumStatusCode removePubSubSubscribedDataSet(PubSub::SubscribedDataSetPtr subscribedDataSet);

		/*! Gets all PubSub SubscribedDataSets */
		std::vector<PubSub::SubscribedDataSetPtr> getPubSubSubscribedDataSets() const;

		/*! Exposes PubSub nodes to the address space
		*
		* All PubSub nodes including their properties, added to the application will be shown at (or hidden from) the address space.
		*
		* @note Server-only method
		* @note Default value is false. */
		void setShowPubSubNodes(bool showNodes);
		/*! Gets the setting
		*
		* @see setShowPubSubNodes */
		bool getShowPubSubNodes();

		/*! Allows to ignore implementation regarding mantis issue (released with Errata 1.04.3)
		*
		* The mantis issue contains the problem that messages can be removed during a roll-over of sequence numbers (at 4.294.966.271).
		* The issue was solved by defining a concrete start of sequence numbers (1023) including after roll-over.
		* Previous specifications allowed all staring sequence numbers less than 1024, so the new definition does not contradict the older specifications.
		* For compatibility reasons sequence numbers less than 1023 and greater than 4.294.966.271 shall be still accepted.
		*
		* @note Ignoring the mantis issue will allow the client or server to communicate with non-compliant OPC UA applications.
		*       This option shall only be used if dealing with a non-compliant UA applications, where the session establishment would fail otherwise.
		*       When ignoring the implementation for the issue, messages can be lost without recognizing. */
		EnumStatusCode ignoreMantis4545(bool bIgnore);


	private:
		/*! Default constructor */
		Application();
		/*! For internal use only */
		void initMembers();

		InnerApplicationDescription m_Description;

		/*! Forbid use assignment operator */
		Application& operator=(const Application&);
		/*! Forbid use of copy constructor */
		Application(const Application&);
	};
	typedef ObjectPointer<Application> ApplicationPtr;
	typedef ObjectPointer<const Application> ApplicationConstPtr;
} // toolbox namespace end

#endif	// APPLICATION_H
