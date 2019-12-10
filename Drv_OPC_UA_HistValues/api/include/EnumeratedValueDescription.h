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

#ifndef ENUMERATEDVALUEDESCRIPTION_H
#define ENUMERATEDVALUEDESCRIPTION_H

#include "Base.h"
#include "NodeId.h"

namespace SoftingOPCToolbox5
{
	/*! This class is used to describe one value component of a EnumerationDataTypeDescription.
	*
	* @see EnumerationDataTypeDescription */
	class TBC_EXPORT EnumeratedValueDescription
		: public Base
	{
	public:
		/*! Constructs a new EnumeratedValueDescription instance */
		static ObjectPointer<EnumeratedValueDescription> create();

		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		EnumeratedValueDescription(TBHandle otbHandle);

		/*! Destructor */
		virtual ~EnumeratedValueDescription();

	protected:
		/*! Default constructor */
		EnumeratedValueDescription();

	public:
		/*! Returns the descriptive name of the enumerated value */
		tstring getName() const;
		/*! Sets the name of the enumeration
		* @note The string must consist of valid UTF8 characters */
		void setName(const tstring& name);

		/*! Returns the numeric value. */
		OTInt32 getValue() const;
		/*! Sets the numeric value of elements. */
		void setValue(OTInt32 enumValue);

		/*! Returns the XML documentation of the field as text.
		* It contains the value of the "Documentation" XML node (plain text and any XML elements) */
		tstring getDocumentation() const;
		/*! Sets the XML documentation of the enumerated value as text.
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

	private:
		/*! EnumeratedValueDescription cannot be copied */
		EnumeratedValueDescription(const EnumeratedValueDescription&);
		/*! EnumeratedValueDescription cannot be copied */
		EnumeratedValueDescription& operator=(const EnumeratedValueDescription&);
	};
	typedef ObjectPointer<EnumeratedValueDescription> EnumeratedValueDescriptionPtr;
	typedef ObjectPointer<const EnumeratedValueDescription> EnumeratedValueDescriptionConstPtr;
} // end namespace

#endif	// ENUMERATEDVALUEDESCRIPTION_H
