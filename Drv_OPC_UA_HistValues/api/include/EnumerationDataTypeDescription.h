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

#ifndef ENUMERATION_DATATYPE_DESCRIPTION_H
#define ENUMERATION_DATATYPE_DESCRIPTION_H

#include "Base.h"
#include "NodeId.h"
#include "DataTypeDescription.h"
#include "EnumeratedValueDescription.h"

namespace SoftingOPCToolbox5
{
	/*! This class stores the information of an enumeration data type, it holds a list of EnumeratedValueDescriptions.
	*
	* Any enumeration DataType not directly inheriting from the abstract "Enumeration" DataType can only restrict the enumeration values of its super-type.
	*
	* @see EnumeratedValueDescription */
	class TBC_EXPORT EnumerationDataTypeDescription
		: public DataTypeDescription
	{
	public:
		/*! Constructs a new EnumerationDataTypeDescription instance */
		static ObjectPointer<EnumerationDataTypeDescription> create();

		/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
		EnumerationDataTypeDescription(TBHandle otbHandle);

		/*! Destructor */
		virtual ~EnumerationDataTypeDescription();

	protected:
		/*! Default constructor */
		EnumerationDataTypeDescription();

	public:
		/*! Returns the list of EnumeratedValueDescriptions
		*
		* @param	enumeratedValues	The EnumeratedValues of the EnumerationDataTypeDescription */
		EnumStatusCode getEnumeratedValues(std::vector<EnumeratedValueDescriptionConstPtr>& enumeratedValues) const;

		/*! Sets the list of EnumeratedValueDescriptions
		*
		* @param	enumeratedValues	The EnumeratedValues of the EnumerationDataTypeDescription
		* @note		The integer representations of all given EnumeratedValues must be different. */
		EnumStatusCode setEnumeratedValues(const std::vector<EnumeratedValueDescriptionPtr>& enumeratedValues);

		/*! Determines, whether this EnumerationDataTypeDescription has an enumeration representation for the given integer */
		bool isEnumValue(OTInt32 integerRepresentation) const;

		/*! Returns the EnumValueType, that represents the given integer value
		* @note An error is returned, if there is no matching representation */
		EnumStatusCode getEnumeratedValue(OTInt32 integerRepresentation, EnumeratedValueDescriptionConstPtr& enumeratedValue) const;

	private:
		/*! EnumerationDataTypeDescription cannot be copied */
		EnumerationDataTypeDescription(const EnumerationDataTypeDescription&);
		/*! EnumerationDataTypeDescription cannot be copied */
		EnumerationDataTypeDescription& operator=(const EnumerationDataTypeDescription&);
	};
	typedef ObjectPointer<EnumerationDataTypeDescription> EnumerationDataTypeDescriptionPtr;
	typedef ObjectPointer<const EnumerationDataTypeDescription> EnumerationDataTypeDescriptionConstPtr;
} // end namespace

#endif	// ENUMERATED_DATATYPE_DESCRIPTION_H
