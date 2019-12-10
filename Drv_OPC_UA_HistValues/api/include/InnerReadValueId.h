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

#ifndef INNERREADVALUEID_H
#define INNERREADVALUEID_H

#include "IReadValueId.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerQualifiedName.h"
#include "InnerNumericRange.h"
#include "QualifiedName.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerReadValueId
	class TBC_EXPORT InnerReadValueId
		: public IReadValueId
	{
	public:
		/*! Destructor */
		virtual ~InnerReadValueId();

		/*! The NodeId from the node to read the value. */
		virtual const INodeId* getNodeId() const;
		virtual INodeId* getNodeId();
		virtual void setNodeId(const INodeId* value);
		virtual void setNodeId(const NodeId& value);

		/*! The attribute that shall be read from the server node (see enumeration type for possible values). Only
		* one attribute can be set (not a bit mask). */
		virtual EnumAttributeId getAttributeId() const;
		virtual void setAttributeId(EnumAttributeId value);

		/*! Defines by a string the index range or a requested value (only required for array values).
		* If empty the parameter is not used.
		* The indices are zero based. */
		virtual const INumericRange* getIndexRange() const;
		virtual void setIndexRange(const INumericRange* value);
		virtual void setIndexRange(const NumericRange& value);

		// init from otb handle
		void initInner(ReadValueIdStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IReadValueId* other) const;
		/*! @overload */
		virtual int compare(const IReadValueId& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IReadValueId& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IReadValueId& other) const;

		// set from interface
		EnumStatusCode set(const IReadValueId* pSrc);
		EnumStatusCode set(const IReadValueId& pSrc);

		// protected:
		// the handle to the related core object
		ReadValueIdStruct* m_pReadValueId_Data;

		/*! For internal use only */
		virtual void* getInternHandle() const;
		InnerNodeId m_NodeId;
		InnerNumericRange m_IndexRange;
	};
}
#endif	// INNERREADVALUEID_H
