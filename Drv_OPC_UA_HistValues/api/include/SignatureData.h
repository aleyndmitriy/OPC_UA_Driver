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

#ifndef SIGNATUREDATA_H
#define SIGNATUREDATA_H

#include "ISignatureData.h"
#include "InnerByteString.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The SignatureData data type contains a digital signature created with a certificate. */
	class TBC_EXPORT SignatureData
		: public ISignatureData
	{
	public:
		/*! Default constructor */
		SignatureData();
		/*! Constructs a copy of the given instance */
		SignatureData(const ISignatureData*);
		/*! @overload */
		SignatureData(const ISignatureData&);
		/*! @overload */
		SignatureData(const SignatureData&);

		/*! Destructor */
		virtual ~SignatureData();

		/*! Assigns the contents of @p cp to this instance */
		SignatureData& operator=(const ISignatureData* cp);
		/*! @overload */
		SignatureData& operator=(const ISignatureData& cp);
		/*! @overload */
		SignatureData& operator=(const SignatureData& cp);

		/* see ISignatureData::set */
		virtual EnumStatusCode set(const ISignatureData* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ISignatureData& pSrc);

		/* see ISignatureData::compare */
		virtual int compare(const ISignatureData*) const;
		/*! @overload */
		virtual int compare(const ISignatureData&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISignatureData& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISignatureData& other) const;

		/* see ISignatureData::getSignature */
		virtual ByteString getSignature() const;
		/* see ISignatureData::setSignature */
		virtual void setSignature(const ByteString& value);

		/* see ISignatureData::getAlgorithm */
		virtual tstring getAlgorithm() const;
		/* see ISignatureData::setAlgorithm */
		virtual void setAlgorithm(const tstring& value);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerByteString m_signature;
		SignatureDataStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// SIGNATUREDATA_H
