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

#ifndef FIELDDESCRIPTION_H
#define FIELDDESCRIPTION_H

#include "Base.h"
#include "NodeId.h"

namespace SoftingOPCToolbox5
{
	/*! This class is used to describe one type component of a DataTypeDescription for a structured data type.
	*
	* @see DataTypeDescription */
	class TBC_EXPORT FieldDescription
		: public Base
	{
	public:
		/*! Constructs a new FieldDescription instance */
		static ObjectPointer<FieldDescription> create();

		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		FieldDescription(TBHandle otbHandle);

		/*! Destructor */
		virtual ~FieldDescription();

	protected:
		/*! Default constructor */
		FieldDescription();

	public:
		/*! Returns the name of the field */
		tstring getName() const;
		/*! Sets the name of the field
		* @note The string must consist of valid UTF8 characters */
		void setName(const tstring& name);

		/*! Returns the number of elements.
		*
		* @see setLength() */
		OTUInt32 getLength() const;
		/*! Sets the number of elements.
		* The default value is 1, which means a scalar value.
		* Any value between 2 and std::numeric_limits<OTInt32>::max() (0x7FFFFFFF) defines a array of fixed length.
		* A value of std::numeric_limits<OTUInt32>::max() (0xFFFFFFFF) means variable length.
		* Other values are not allowed. */
		EnumStatusCode setLength(OTUInt32 length);

		/*! Returns the XML documentation of the field as text.
		* It contains the value of the "Documentation" XML node (plain text and any XML elements) */
		tstring getDocumentation() const;

		/*! Sets the XML documentation of the field as text.
		* It is the value of the "Documentation" XML node (plain text and any XML elements)
		* @note The strings must consist of valid UTF8 characters */
		void setDocumentation(const tstring& documentation);

		/*! Returns the possible documentation attributes.
		* It contains all attributes of the "Documentation" XML node. */
		EnumStatusCode getDocumentationAttributes(std::vector<std::pair<tstring, tstring> >* pDocumentationAttributes) const;
		/*! Sets the possible documentation attributes.
		* these are all attributes of the "Documentation" XML node.
		* @note The strings must consist of valid UTF8 characters */
		EnumStatusCode setDocumentationAttributes(const std::vector<std::pair<tstring, tstring> >& documentationAttributes);

		/*! Returns the user defined Attributes */
		EnumStatusCode getCustomAttributes(std::vector<std::pair<tstring, tstring> >* pCustomAttributes) const;
		/*! Sets the user defined Attributes
		* @note The strings must consist of valid UTF8 characters */
		EnumStatusCode setCustomAttributes(const std::vector<std::pair<tstring, tstring> >& customAttributes);

		/*! Returns the NodeId of the used data type. */
		NodeId getType() const;
		/*! Sets the NodeId of the data type to use.
		*
		* @note	The node of the NodeId must be a DataType node with an encoding rule, which means either well known
		*		or a custom data type with a configured data type description. */
		EnumStatusCode setType(const INodeId& typeId);

	private:
		/*! DataTypeDescription cannot be copied */
		FieldDescription(const FieldDescription&);
		/*! FieldDescription cannot be copied */
		FieldDescription& operator=(const FieldDescription&);
	};
	typedef ObjectPointer<FieldDescription> FieldDescriptionPtr;
	typedef ObjectPointer<const FieldDescription> FieldDescriptionConstPtr;
} // end namespace

#endif	// FIELDDESCRIPTION_H
