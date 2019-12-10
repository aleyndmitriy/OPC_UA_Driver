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

#ifndef STRUCTUREDDATATYPEDESCRIPTION_H
#define STRUCTUREDDATATYPEDESCRIPTION_H

#include "Base.h"
#include "NodeId.h"
#include "DataTypeDescription.h"
#include "FieldDescription.h"

namespace SoftingOPCToolbox5
{
	/*! This class stores the information of a structured data type, it holds a list of FieldDescriptions.
	*
	* @see FieldDescription */
	class TBC_EXPORT StructuredDataTypeDescription
		: public DataTypeDescription
	{
	public:
		/*! Constructs a new StructuredDataTypeDescription instance */
		static ObjectPointer<StructuredDataTypeDescription> create();

		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		StructuredDataTypeDescription(TBHandle otbHandle);

		/*! Destructor */
		virtual ~StructuredDataTypeDescription();

	protected:
		/*! Default constructor */
		StructuredDataTypeDescription();

	public:
		/*! Returns the list of FieldDescriptions
		*
		* @param	fields	The Fields of the StructuredDataTypeDescription */
		EnumStatusCode getFields(std::vector<FieldDescriptionConstPtr>& fields) const;

		/*! Returns the list of FieldDescriptions
		*
		* @param	fields	The Fields of the StructuredDataTypeDescription
		* @note		The field descriptions must have different names.
		*			If an array field uses another field as LengthField, then the LengthField must precede the array field */
		EnumStatusCode setFields(const std::vector<FieldDescriptionPtr>& fields);

	private:
		/*! StructuredDataTypeDescription cannot be copied */
		StructuredDataTypeDescription(const StructuredDataTypeDescription&);
		/*! StructuredDataTypeDescription cannot be copied */
		StructuredDataTypeDescription& operator=(const StructuredDataTypeDescription&);
	};
	typedef ObjectPointer<StructuredDataTypeDescription> StructuredDataTypeDescriptionPtr;
	typedef ObjectPointer<const StructuredDataTypeDescription> StructuredDataTypeDescriptionConstPtr;
} // end namespace

#endif	// STRUCTUREDDATATYPEDESCRIPTION_H
