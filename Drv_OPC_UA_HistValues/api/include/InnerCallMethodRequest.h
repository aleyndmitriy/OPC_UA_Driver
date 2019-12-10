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

#ifndef INNERCALLMETHODREQUEST_H
#define INNERCALLMETHODREQUEST_H

#include "ICallMethodRequest.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerValue.h"
#include "Value.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	// class declaration for class InnerCallMethodRequest
	class TBC_EXPORT InnerCallMethodRequest
		: public ICallMethodRequest
	{
	public:
		/*! Destructor */
		virtual ~InnerCallMethodRequest();

		virtual const INodeId* getObjectId() const;
		virtual INodeId* getObjectId();
		virtual void setObjectId(const INodeId* value);
		virtual void setObjectId(const NodeId& value);

		virtual const INodeId* getMethodId() const;
		virtual INodeId* getMethodId();
		virtual void setMethodId(const INodeId* value);
		virtual void setMethodId(const NodeId& value);

		virtual OTUInt32 getInputArgumentCount() const;
		virtual const IValue* getInputArgument(OTUInt32 index) const;
		virtual std::vector<Value> getInputArguments() const;
		virtual EnumStatusCode addInputArgument(const IValue* pValue);


		// init from otb handle
		void initInner(CallMethodRequestStruct* pHandle);

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ICallMethodRequest* other) const;
		/*! @overload */
		virtual int compare(const ICallMethodRequest& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ICallMethodRequest& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ICallMethodRequest& other) const;

		// set from interface
		EnumStatusCode set(const ICallMethodRequest* pSrc);
		EnumStatusCode set(const ICallMethodRequest& pSrc);

		// protected:
		// the handle to the related core object
		CallMethodRequestStruct* m_pCallMethodRequest_Data;

	private:
		/*! For internal use only */
		virtual void* getInternHandle() const;

		InnerNodeId m_ObjectId;
		InnerNodeId m_MethodId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_InputArguments)
	};
}
#endif	// INNERCALLMETHODREQUEST_H
