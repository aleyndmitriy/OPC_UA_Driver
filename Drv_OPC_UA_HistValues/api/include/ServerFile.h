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

#ifndef SERVERFILE_H
#define SERVERFILE_H
#include "Base.h"
#include "Enums.h"
#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		class Session;

		/*! The File class is used to define a node in the servers address space of type FileType.
		*
		* A File is used to represent systems, system components, real-world Files and software
		* Files in the address space of a server. A File consists of properties and methods to access the file.
		*
		* Each File node has mandatory and optional properties
		* @li Size					The size of the file. The default implementation of the SDK
		*							updates this property automatically after a client closes the file for writing.
		* @li Writable				The file object is writable.
		* @li UserWritable			The user credentials of the session allow writing to the file.
		* @li OpenCount				The number of valid file handles on this file.
		*							This property is automatically updated by the SDK.
		* @li MimeType (optional)	The media type of the file based on RFC 2046.
		*
		* If an application wants to expose data as UA file objects which are not represented as physical files (e.g. database content, ...),
		* it can derive from this class and overwrite the file access methods (open, read, ...) to implement special access.
		* The SDK takes care that the matching methods are invoked when a client calls the appropriate UA method.
		* In this case, the properties Size and OpenCountave to be updated by the application as well.
		*
		* @note When using a File object via Nodeset2 XML import, an application has to link the file instance via setFilePath
		*		to a physical file. Otherwise accessing the file is not possible.
		*		An application can store the file path either in the (string) NodeId, an extension (see BaseNode::getExtensions), ...*/
		class TBC_EXPORT File
			: public Object
		{
		public:
			/*! Constructs a new File instance */
			static ObjectPointer<File> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator File factory */
			File(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			File(bool suppressCoreInstanceCreate);
			File();

		public:
			/*! Destructor */
			virtual ~File();

			/*! Initialize the File object and create properties
			*
			* @param typeId							Can be NULL if type is of Static::ObjectTypeId_FileType
			* @param sizePropertyNodeId				The NodeId of the Size property (mandatory)
			* @param writablePropertyNodeId			The NodeId of the Writable property (mandatory)
			* @param userWriteablePropertyNodeId	The NodeId of the UserWritable property (mandatory)
			* @param openCountPropertyNodeId		The NodeId of the OpenCount property (mandatory)
			* @param mimeTypePropertyNodeId			The NodeId of the MimeType property (optional)
			*										If a NULL nodeId is provided (as default) the property is not created. */
			virtual EnumStatusCode initEx(
				const INodeId* typeId,
				const NodeId& sizePropertyNodeId,
				const NodeId& writablePropertyNodeId,
				const NodeId& userWriteablePropertyNodeId,
				const NodeId& openCountPropertyNodeId,
				const NodeId& mimeTypePropertyNodeId = NodeId());

			/*! Initialize the File object and create properties
			*
			* The NodeIds of the property nodes are generated by the SDK. An application provide own NodeIds by overwriting
			* the method generateNodeIdForSubNode. Default implementation will provide unique NodeIds for the properties generated by SDK. */
			virtual EnumStatusCode init(const INodeId* typeId);

			/*! Sets the path to the physical file on the disk.
			*
			* @note	The default implementation uses this platform specific file for the open() method.
			*		A custom implementation that overrides open() method can use the file path as a different source identifier,
			*		e.g. as a key for a data base */
			EnumStatusCode setFilePath(const tstring& filePath);

			/*! Returns the currently configured file path */
			tstring getFilePath() const;

			/*! Sets the Writable property of this file.
			*
			* @param writable	Indicates whether the file can be accessed for writing.
			*					Default: false */
			EnumStatusCode setWritable(bool writable);

			/*! Returns the value of the Writable property. */
			bool getWritable() const;

			/*! Opens a file to be usable for the access operations. returns a file handle for the client, .
			*
			* Clients shall use the Close Method to release the handle when they do not need access to the file anymore.
			* Multiple clients can open the same file concurrently multiple times for read.
			* A request to open for writing returns Bad_NotWritable when the file is already opened.
			* A request to open for reading returns Bad_NotReadable when the file is already opened for writing.
			*
			* @param session	The server session, in which context the open is invoked
			* @param mode		A bit mask for the desired file access modes
			* @param fileHandle	Returns a handle to access the file. The file handle is valid until it is used in a close() call
			*					and while the server session is open.
			*
			* @see Server::Session::registerOpenFileHandle
			* @see close(), read(), write(), getPosition(), setPosition()
			*
			* @note Multiple concurrent opening of a file to read does not work on VxWorks.
			*       If you need this feature, you can implement all methods of this class by your own. */
			virtual EnumStatusCode open(ObjectPointer<Session> session, EnumOpenFileMode mode, OTUInt32& fileHandle);

			/*! Closes a file handle, which was previously opened.
			*
			* @param session	The server session, in which context the close is invoked
			* @param fileHandle	The file handle from a related open() method call. The provided file handle becomes invalid.
			*
			* @note	When overriding this method then the implementation should update the Size property when the file was modified
			*		before close.
			* @see open() */
			virtual EnumStatusCode close(ObjectPointer<Session> session, OTUInt32 fileHandle);

			/*! Reads a part of the file starting from the current file position.
			* The file position is advanced by the number of bytes read.
			*
			* @param session	The server session, in which context the read is invoked
			* @param fileHandle	The file handle from a related open() method call.
			* @param length		The amount of bytes to read.
			* @param data		Returns the read bytes of the file */
			virtual EnumStatusCode read(ObjectPointer<Session> session, OTUInt32 fileHandle, OTInt32 length, ByteString& data) const;

			/*! Writes a part of the file starting from the current file position.
			* The file position is advanced by the number of bytes written.
			*
			* @param session	The server session, in which context the write is invoked
			* @param fileHandle	The file handle from a related open() method call.
			* @param data		The bytes to write */
			virtual EnumStatusCode write(ObjectPointer<Session> session, OTUInt32 fileHandle, const ByteString& data);

			/*! Provides the current file position of the file handle.
			*
			* @param session	The server session, in which context the getPosition is invoked
			* @param fileHandle	The file handle from a related open() method call.
			* @param position	Returns the current position of the file handle */
			virtual EnumStatusCode getPosition(ObjectPointer<Session> session, OTUInt32 fileHandle, OTUInt64& position) const;

			/*! Sets the current file position of the file handle.
			*
			* @param session	The server session, in which context the setPosition is invoked
			* @param fileHandle	The file handle from a related open() method call.
			* @param position	The current position for the file handle */
			virtual EnumStatusCode setPosition(ObjectPointer<Session> session, OTUInt32 fileHandle, OTUInt64 position);

			/*! Updates the size property of this file.
			* This method is meant to be used when the file size was changed by an external operation (e.g. the file was changed by another program).
			* The size is updated automatically when the file is closed after a write operation.
			*
			* @param fileSize	The size displayed in the Size property. If 0 is provided, the file is accessed to get the actual size.
			*
			* @note This shall be invoked only, if SDK is responsible for internal file handles. */
			EnumStatusCode updateSizeProperty(OTUInt64 fileSize = 0);

			/*! Returns the value of the MimeType property. */
			EnumStatusCode getMimeType(tstring &mimeType) const;
			/*! Sets the MimeType property of this file.
			*
			* The MimeType property is optional and shall be used only if the file represents a media file
			*
			* @param mimeType	Describes the mime type (Multipurpose Internet Mail Extensions) of the file. */
			EnumStatusCode setMimeType(const tstring &mimeType);

			/*! Assigns the file a previously defined AccessPattern.
			*
			* The bits for EnumAccessLevel_CurrentRead and EnumAccessLevel_CurrentWrite are used to restrict read / write access
			* access to the file for a user group. All other bits are ignored.
			*
			* @note	This method returns an error if the key is unknown to the server.
			*		Keys are limited to values from 0...0xFFFF.
			* @note	The default accessPatternKey 0 allows all operations for any user.
			*
			* @see IAccessPattern Application::setAccessPattern() */
			EnumStatusCode setAccessPatternKey(OTUInt32 accessPatternKey);

			/*! Returns the key of the assigned AccessPattern.
			*
			* @see setAccessPatternKey */
			OTUInt32 getAccessPatternKey() const;

			/*! Requests a NodeId for a sub-node to be created
			*
			* see Server::BaseNode::generateNodeIdForSubNode */
			virtual EnumStatusCode generateNodeIdForSubNode(const IRelativePath& pathOfNode, INodeId& newNodeId);

		private:
			/*! For internal use only */
			EnumStatusCode initPropertyId(const tstring& name, const NodeId& nodeId);

			/*! Forbid use assignment operator */
			File& operator=(const File&);
			/*! Forbid use of copy constructor */
			File(const File&);
		};
		typedef ObjectPointer<File> FilePtr;
		typedef ObjectPointer<const File> FileConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERFILE_H
