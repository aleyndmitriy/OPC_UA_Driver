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

#ifndef CALLMETHODREQUEST_H
#define CALLMETHODREQUEST_H

#include "ICallMethodRequest.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerValue.h"
#include "Value.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! The CallMethodRequest data type is used by the Call service (see Client::Session::callMethods())
	* to specify the OPC UA method to call. */
	class TBC_EXPORT CallMethodRequest
		: public ICallMethodRequest
	{
	public:
		/*! Default constructor */
		CallMethodRequest();
		/*! Constructs a copy of the given instance */
		CallMethodRequest(const ICallMethodRequest*);
		/*! @overload */
		CallMethodRequest(const ICallMethodRequest&);
		/*! @overload */
		CallMethodRequest(const CallMethodRequest&);

		/*! Destructor */
		virtual ~CallMethodRequest();

		/*! Assigns the contents of @p cp to this instance */
		CallMethodRequest& operator=(const ICallMethodRequest* cp);
		/*! @overload */
		CallMethodRequest& operator=(const ICallMethodRequest& cp);
		/*! @overload */
		CallMethodRequest& operator=(const CallMethodRequest& cp);

		/* see ICallMethodRequest::set */
		virtual EnumStatusCode set(const ICallMethodRequest* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const ICallMethodRequest& pSrc);

		/* see ICallMethodRequest::compare */
		virtual int compare(const ICallMethodRequest*) const;
		/*! @overload */
		virtual int compare(const ICallMethodRequest&) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const ICallMethodRequest& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ICallMethodRequest& other) const;

		/* see ICallMethodRequest::getObjectId */
		virtual const INodeId* getObjectId() const;
		/*! @overload */
		virtual INodeId* getObjectId();
		/* see ICallMethodRequest::setObjectId */
		virtual void setObjectId(const INodeId* value);
		/*! @overload */
		virtual void setObjectId(const NodeId& value);

		/* see ICallMethodRequest::getMethodId */
		virtual const INodeId* getMethodId() const;
		/*! @overload */
		virtual INodeId* getMethodId();
		/* see ICallMethodRequest::setMethodId */
		virtual void setMethodId(const INodeId* value);
		/*! @overload */
		virtual void setMethodId(const NodeId& value);

		/* see ICallMethodRequest::getInputArgumentCount */
		virtual OTUInt32 getInputArgumentCount() const;
		/* see ICallMethodRequest::getInputArgument */
		virtual const IValue* getInputArgument(OTUInt32 index) const;
		/* see ICallMethodRequest::getInputArguments */
		virtual std::vector<Value> getInputArguments() const;
		/* see ICallMethodRequest::addInputArgument */
		virtual EnumStatusCode addInputArgument(const IValue* pValue);

		/*! Clears the contents of this object to enable its re-use. */
		void clear();

		/*! For internal use only */
		virtual void* getInternHandle() const;

	private:
		/*! For internal use only */
		void initMembers();

		InnerNodeId m_ObjectId;
		InnerNodeId m_MethodId;
		PRIVATE_EXPORTED_STL_CONTAINER(std::vector<InnerValue> m_InputArguments)
		CallMethodRequestStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// CALLMETHODREQUEST_H
