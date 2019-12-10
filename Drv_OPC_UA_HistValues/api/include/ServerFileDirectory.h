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

#ifndef SERVERFILEDIRECTORY_H
#define SERVERFILEDIRECTORY_H
#include "Base.h"
#include "Enums.h"
#include "ServerObject.h"
#include "ServerFile.h"

struct NodeIdStruct;

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		// forward declaration
		class Session;
		typedef ObjectPointer<Session> SessionPtr;

		/*! The FileDirectory class is used to define a node in the servers address space of type FileDirectoryType.
		*
		* A FileDirectory is used to organize File objects and other FileDirectory objects providing a way to represent
		* a whole file system or a part of a file system. The FileDirectory provides methods to create, delete, move or copy
		* files and directories.
		*
		* An application can derive from this class and overwrite the methods (createDirectory, createFile, ...) if
		* the application likes to implement special access (e.g. a file system based on a database).
		* The SDK takes care that the matching methods are invoked when a client calls the appropriate UA method. */
		class TBC_EXPORT FileDirectory
			: public Object
		{
		public:
			/*! Constructs a new FileDirectory instance */
			static ObjectPointer<FileDirectory> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator File factory */
			FileDirectory(TBHandle otbHandle);

		protected:
			/*! For internal use only */
			FileDirectory(bool suppressCoreInstanceCreate);
			FileDirectory();

		public:
			/*! Destructor */
			virtual ~FileDirectory();

			/*! Sets the directory path.
			*
			* Configures a directory node with its corresponding path. For custom implementation of UA method invocation this configuration is not used.
			*
			* Configuration of the path is only necessary for "root" directories. Sub-directories will calculate their path out of the directory name and the parent path.
			*
			* @param fullPath		The absolute path to the directory in the file system.
			*						Relative paths might work as well, but if the current directory is changing during runtime,
			*						access may fail randomly.
			*
			* @note		The directory path can be configured only once. Changing the path will fail. */
			EnumStatusCode setDirectoryPath(const tstring& fullPath);

			/*! @see setDirectoryPath */
			tstring getDirectoryPath() const;

			/*! Adds a new subdirectory node as a component of this directory node in the address space.
			*
			* This method is meant to build up the address space by the UA server application.
			* The sub-directories path is calculated from the current directory and the name of the directory to be created and needs no configuration.
			*
			* @param directoryName		The name of the subdirectory to add. The name is used as BrowseName and DisplayName of the new directory node.
			*							The directory name shall refer to an existing directory directly below the directory path of the current FileDirectory.
			* @param directoryNodeId	The NodeId of the subdirectory node to be created.
			* @param addedDirectory		Returns the newly added directory.
			*
			* @note This method shall be used only if the directory node (and the subdirectory node) are mapped to existing directories in the file system.
			*		For custom storage of directories and files, create a FileDirectory node and add a HasComponent reference to the subdirectory.
			*
			* @note	Invocation adds the subdirectory with the default accessPatternKey 0, which grants full access for any user.
			*		To change this, you need to assign a custom accessPatternKey afterwards.
			*
			* @see deleteFileOrDirectory(), moveOrCopy() */
			EnumStatusCode addSubDirectory(const tstring& directoryName, const NodeId& directoryNodeId, ObjectPointer<FileDirectory> &addedDirectory);
			/*! @overload */
			EnumStatusCode addSubDirectory(const tstring& directoryName, const NodeId& directoryNodeId);

			/*! Adds a new file node as a component of this directory node in the address space.
			*
			* This method is meant to build up the address space by the UA server application.
			* The created file can be accessed via the OPC UA Methods of the FileType.
			*
			* @param fileName			The name of the file to add. The name is used for the BrowseName and DisplayName
			*							of the file node and also for the file in the file system.
			*							The file name shall refer to an existing file directly below the directory path of the current FileDirectory.
			* @param fileNodeId			The NodeId of the created file node.
*			* @param addedFile			Returns the newly added file.
			*
			* @note By default the added file is set to read-only. To change this, you need to call Server::File::setWritable(true) afterwards.
			*
			* @see deleteFileOrDirectory(), moveOrCopy() */
			EnumStatusCode addFile(const tstring& fileName, const NodeId& fileNodeId, ObjectPointer<Server::File> &addedFile);
			/*! @overload */
			EnumStatusCode addFile(const tstring& fileName, const NodeId& fileNodeId);

			/*! Assigns the FileDirectory a previously defined AccessPattern.
			*
			* The bit for EnumAccessLevel_CurrentWrite is used to restrict the rights for different users to create, delete, move or copy a file or directory.
			* All other AccessLevel bits of the AccessPattern are ignored by this Object.
			*
			* @note	This method returns an error if the key is unknown to the server.
			*		Keys are limited to values from 0...0xFFFF.
			* @note The default accessPatternKey 0 allows all operations for any user.
			*
			* @see IAccessPattern Application::setAccessPattern() */
			EnumStatusCode setAccessPatternKey(OTUInt32 accessPatternKey);

			/*! Returns the key of the assigned AccessPattern.
			*
			* @see setAccessPatternKey */
			OTUInt32 getAccessPatternKey() const;

			/*! Create a new FileDirectoryType Object organized by this Object.
			*
			* @param session			The server session, in which context the CreateDirectory UA method is invoked
			* @param directoryName		The name of the directory to create. The name is used for the BrowseName and DisplayName
			*							of the directory object and also for the directory in the file system.
			* @param directoryNodeId	Returns the NodeId of the created directory Object.
			*
			* @note	This method validates that the user assigned to the session has writeAccess.
			*
			* @note	The default implementation creates the subdirectory with the default accessPatternKey 0, which grants full access for any user.
			*		To change this, you can override this method and assign a custom accessPatternKey.
			*
			* @see deleteFileOrDirectory(), moveOrCopy(), setAccessPatternKey() */
			virtual EnumStatusCode createDirectory(SessionPtr session, const tstring& directoryName, NodeId& directoryNodeId);

			/*! Creates a new FileType Object organized by this FileDirectory Object. The default implementation also creates the file in the local file system.
			* The created file can be written using the Write Method of the FileType.
			*
			* @param session			The server session, in which context the createFile is invoked
			* @param fileName			The name of the file to create. The name is used for the BrowseName and DisplayName
			*							of the file object and also for the file in the file system.
			* @param requestFileOpen	Flag indicating if the new file should be opened.
			* @param fileNodeId			Returns the NodeId of the created file Object.
			* @param fileHandle			Returns the fileHandle if the requestFileOpen is set to true.
			*
			* @note	This method validates that the user assigned to the session has writeAccess.
			*
			* @note	The default implementation creates the file with the default accessPatternKey 0, which grants full access for any user.
			*		To change this, you can override this method and assign a custom accessPatternKey.
			*
			* @see deleteFileOrDirectory(), moveOrCopy(), setAccessPatternKey() */
			virtual EnumStatusCode createFile(
				SessionPtr session,
				const tstring& fileName,
				bool requestFileOpen,
				NodeId& fileNodeId,
				OTUInt32& fileHandle);

			/*! Deletes a file or directory organized by this Object.
			*
			* @param session			The server session, in which context the delete is invoked
			* @param objectIdToDelete		The NodeId of the file or directory to delete.
			*
			* @note In the case of a directory, all file and directory Objects below the directory to delete are deleted recursively.
			*
			* @note This method validates that the user assigned to the session has writeAccess.
			*
			* @see setAccessPatternKey() */
			virtual EnumStatusCode deleteFileOrDirectory(SessionPtr session, const NodeId& objectIdToDelete) const;

			/*! Used to move or copy a file or directory organized by this Object to another directory or to rename a file or directory.
			*
			* @param session				The server session, in which context the moveOrCopy is invoked
			* @param objectIdToMoveOrCopy	The NodeId of the file or directory to move or copy.
			* @param targetDirectoryId		The NodeId of the target directory of the move or copy command. For rename it matches
			*								the ObjectId passed to the method call.
			* @param createCopy				A flag indicating if a copy of the file or directory should be created at the target directory.
			* @param newName				The new name of the file or directory in the new location. If the string is empty, the name is unchanged.
			* @param newNodeId				Returns the NodeId of the moved or copied object.
			*
			* @note	This method validates that the user assigned to the session has writeAccess.
			*		A move requires access rights on the current directory and the target directory,
			*		while a copy requires access rights only on the target directory.
			*
			* @see setAccessPatternKey() */
			virtual EnumStatusCode moveOrCopy(
				SessionPtr session,
				const NodeId& objectIdToMoveOrCopy,
				const NodeId& targetDirectoryId,
				bool createCopy,
				const tstring& newName,
				NodeId& newNodeId);

			/*! Requests a NodeId for a sub-node to be created
			* @note In case of FileDirectory objects' creation the SDK will call back this method on the root object.
			*		By providing a custom implementation when creating the root FileDirectory the NodeId generation of sub-objects can be controlled.
			*
			* see Server::BaseNode::generateNodeIdForSubNode */
			virtual EnumStatusCode generateNodeIdForSubNode(const IRelativePath& pathOfNode, INodeId& newNodeId);

		private:
			/*! Forbid use assignment operator */
			FileDirectory& operator=(const FileDirectory&);
			/*! Forbid use of copy constructor */
			FileDirectory(const FileDirectory&);
		};
		typedef ObjectPointer<FileDirectory> FileDirectoryPtr;
		typedef ObjectPointer<const FileDirectory> FileDirectoryConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERFILEDIRECTORY_H
