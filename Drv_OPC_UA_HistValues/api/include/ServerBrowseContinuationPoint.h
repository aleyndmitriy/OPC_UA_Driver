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

#ifndef SERVERBROWSECONTINUATIONPOINT_H
#define SERVERBROWSECONTINUATIONPOINT_H

#include "Base.h"
#include "ServerBaseNode.h"
#include "ServerContinuationPoint.h"
#include "ByteString.h"
#include "ViewDescription.h"
#include "NodeId.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! A continuation point for Browse requests.
		*
		* @see ContinuationPoint BrowseTransaction BrowseRequest BrowseNextTransaction BrowseNextRequest */
		class TBC_EXPORT BrowseContinuationPoint
			: public ContinuationPoint
		{
		public:
			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			BrowseContinuationPoint(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			BrowseContinuationPoint(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~BrowseContinuationPoint();

			/*! Returns the type of this continuation point (Browse).
			*
			* @return The continuation point type */
			virtual EnumContinuationPointType getType() const;

			/*! Interprets and returns the context information as ByteString.
			*
			* @return The context information interpreted as ByteString */
			ByteString getContextAsByteString() const;
			/*! Stores the provided @p byteString as context information for this
			* continuation point.
			*
			* Any previously stored context information is deleted. */
			EnumStatusCode setContextFromByteString(const ByteString& byteString);

			/*! Returns the description of the view to browse.
			*
			* The view describes if the browse shall be performed on the entire address space or with certain
			* restriction, where only a part of the address space is visible.
			* An empty ViewDescription value indicates the entire address space.
			*
			* @see IViewDescription, Server::View */
			EnumStatusCode getView(ViewDescription& view) const;

			/*! Returns the maximum number of references to return for each starting node.
			* This value applies for every request of this transaction.
			*
			* A client application can request this to restrict the number of returned references.
			* When the number of requests is reached, a ContinuationPoint shall be created so that the client
			* can continue the request via the 'BrowseNext' service.
			*
			* The value 0 indicates that the client is imposing no limitation.
			*
			* @see Server::ContinuationPoint, Server::BrowseNextTransaction */
			OTUInt32 getRequestedMaxReferencesPerNode() const;

			/*! Returns the NodeId of the node from where the browse shall be performed. */
			EnumStatusCode getNodeIdToBrowse(NodeId& nodeId) const;

			/*! Returns a pointer to the Node from where the browse shall be performed. */
			ObjectPointer<Server::BaseNode> getNodeToBrowse();
			/*! @overload */
			ObjectPointer<const Server::BaseNode> getNodeToBrowse() const;

			/*! Returns the direction of references to follow, whether to search in forward, backward
			* or both directions.
			*
			* @see	EnumBrowseDirection */
			EnumBrowseDirection getBrowseDirection() const;

			/*! Returns the NodeId of the reference type to follow.
			* Only found instances of this type or its subtypes shall be returned.
			*
			* @see	getIncludeSubtypes() */
			EnumStatusCode getReferenceTypeId(NodeId& nodeId) const;

			/*! Returns whether to follow subtypes of the provided reference type.
			*
			* @see	getReferenceTypeId() */
			bool getIncludeSubtypes() const;

			/*! Returns the node classes that are to be followed.
			* This option restricts the returned results to certain node classes.
			*
			* @note	This value is a bit mask and it may be an combination of several values.
			* @see	EnumNodeClass */
			EnumNodeClass getNodeClassMask() const;

			/*! Returns the result mask that is to be applied to the followed nodes.
			* The result mask describes, which information shall be returned for the found nodes additional to their NodeId.
			*
			* @note	This value is a bit mask and it may be an combination of several values.
			* @see	EnumResultMask */
			EnumResultMask getResultMask() const;

		private:
			/*! For internal use only */
			void initMembers();

			/*! Continuation points are provided by the SDK core */
			BrowseContinuationPoint();

			/*! Forbid use assignment operator */
			BrowseContinuationPoint& operator=(const BrowseContinuationPoint&);
			/*! Forbid use of copy constructor */
			BrowseContinuationPoint(const BrowseContinuationPoint&);
		};
		typedef ObjectPointer<Server::BrowseContinuationPoint> BrowseContinuationPointPtr;
		typedef ObjectPointer<const Server::BrowseContinuationPoint> BrowseContinuationPointConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERBROWSECONTINUATIONPOINT_H
