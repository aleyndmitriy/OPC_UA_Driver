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

#ifndef EUINFORMATION_H
#define EUINFORMATION_H

#include "IEUInformation.h"
#include "InnerLocalizedText.h"
#include "LocalizedText.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The EUInformation data type contains information about the engineering units of an analog value.
	*
	* To facilitate interoperability, OPC UA specifies how to apply the widely accepted
	* "Codes for Units of Measurement (Recommendation No. 20)" published by the "United Nations
	* Centre for Trade Facilitation and Electronic Business". It uses and is based on the International
	* System of Units (SI Units) but in addition provides a fixed code that can be used for automated evaluation.
	* This recommendation has been accepted by many industries on a global basis.
	*
	* @see Server::AnalogItem */
	class TBC_EXPORT EUInformation
		: public IEUInformation
	{
	public:
		/*! Default constructor */
		EUInformation();
		/*! Constructs a copy of the given instance */
		EUInformation(const IEUInformation*);
		/*! @overload */
		EUInformation(const IEUInformation&);
		/*! @overload */
		EUInformation(const EUInformation&);

		/*! Destructor */
		virtual ~EUInformation();

		/*! Assigns the contents of @p cp to this instance */
		EUInformation& operator=(const IEUInformation* cp);
		/*! @overload */
		EUInformation& operator=(const IEUInformation& cp);
		/*! @overload */
		EUInformation& operator=(const EUInformation& cp);

		/* see IEUInformation::set */
		virtual EnumStatusCode set(const IEUInformation* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IEUInformation& pSrc);

		/* see IEUInformation::compare */
		virtual int compare(const IEUInformation*) const;
		/*! @overload */
		virtual int compare(const IEUInformation&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IEUInformation& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IEUInformation& other) const;

		/* see IEUInformation::getNamespaceUri */
		virtual tstring getNamespaceUri() const;
		/* see IEUInformation::setNamespaceUri */
		virtual void setNamespaceUri(const tstring& value);

		/* see IEUInformation::getUnitId */
		virtual OTInt32 getUnitId() const;
		/* see IEUInformation::setUnitId */
		virtual void setUnitId(OTInt32 value);
		/* see IEUInformation::getUnitIdCode */
		virtual tstring getUnitIdCode() const;
		/* see IEUInformation::setUnitIdCode */
		virtual void setUnitIdCode(tstring code);

		/* see IEUInformation::getDisplayName */
		virtual const ILocalizedText* getDisplayName() const;
		/*! @overload */
		virtual ILocalizedText* getDisplayName();
		/* see IEUInformation::setDisplayName */
		virtual void setDisplayName(const ILocalizedText* value);
		/*! @overload */
		virtual void setDisplayName(const LocalizedText& value);

		/* see IEUInformation::getDescription */
		virtual const ILocalizedText* getDescription() const;
		/*! @overload */
		virtual ILocalizedText* getDescription();
		/* see IEUInformation::setDescription */
		virtual void setDescription(const ILocalizedText* value);
		/*! @overload */
		virtual void setDescription(const LocalizedText& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerLocalizedText m_DisplayName;
		InnerLocalizedText m_Description;

		EUInformationStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// EUINFORMATION_H
