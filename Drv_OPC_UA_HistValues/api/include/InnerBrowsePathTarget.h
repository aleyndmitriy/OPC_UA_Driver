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

#ifndef INNERBROWSEPATHTARGET_H
#define INNERBROWSEPATHTARGET_H

#include "IBrowsePathTarget.h"
#include "InnerExpandedNodeId.h"
#include "ExpandedNodeId.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerBrowsePathTarget
	class TBC_EXPORT InnerBrowsePathTarget
		: public IBrowsePathTarget
	{
	public:
		/*! Destructor */
		virtual ~InnerBrowsePathTarget();

		virtual const IExpandedNodeId* getTargetId() const;
		virtual IExpandedNodeId* getTargetId();
		virtual void setTargetId(const IExpandedNodeId* value);
		virtual void setTargetId(const ExpandedNodeId& value);

		virtual OTUInt32 getRemainingPathIndex() const;
		virtual void setRemainingPathIndex(OTUInt32 value);


		// init from otb handle
		void initInner(BrowsePathTargetStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IBrowsePathTarget* other) const;
		/*! @overload */
		virtual int compare(const IBrowsePathTarget& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IBrowsePathTarget& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IBrowsePathTarget& other) const;

		// set from interface
		EnumStatusCode set(const IBrowsePathTarget* pSrc);
		EnumStatusCode set(const IBrowsePathTarget& pSrc);

		virtual void* getInternHandle() const;


	private:
		// the handle to the related core object
		BrowsePathTargetStruct* m_pBrowsePathTarget_Data;

		InnerExpandedNodeId m_TargetId;
	};
}
#endif	// INNERBROWSEPATHTARGET_H
