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

#ifndef INNERSIGNATUREDATA_H
#define INNERSIGNATUREDATA_H

#include "ISignatureData.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerSignatureData
	class TBC_EXPORT InnerSignatureData
		: public ISignatureData
	{
	public:
		/*! Destructor */
		virtual ~InnerSignatureData();

		/*! The signatures data */
		virtual ByteString getSignature() const;
		virtual void setSignature(const ByteString& value);

		/*! The algorithm used to create the siganture. */
		virtual tstring getAlgorithm() const;
		virtual void setAlgorithm(const tstring& value);


		// init from otb handle
		void initInner(SignatureDataStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ISignatureData* other) const;
		/*! @overload */
		virtual int compare(const ISignatureData& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ISignatureData& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ISignatureData& other) const;

		// set from interface
		EnumStatusCode set(const ISignatureData* pSrc);
		EnumStatusCode set(const ISignatureData& pSrc);

		// protected:
		// the handle to the related core object
		SignatureDataStruct* m_pSignatureData_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
	};
}
#endif	// INNERSIGNATUREDATA_H
