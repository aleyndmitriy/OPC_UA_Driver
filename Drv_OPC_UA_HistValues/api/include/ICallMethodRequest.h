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

#ifndef ICALLMETHODREQUEST_H
#define ICALLMETHODREQUEST_H

#include "CallMethodRequestStruct.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerValue.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	/*! The CallMethodRequest data type is used by the Call service (see Client::Session::callMethods())
	* to specify the OPC UA method to call. */
	class TBC_EXPORT ICallMethodRequest
	{
	public:
		/*! Destructor */
		virtual ~ICallMethodRequest(){};

		/*! Returns the NodeId of the object node that contains the method. */
		virtual const INodeId* getObjectId() const = 0;
		/*! @overload */
		virtual INodeId* getObjectId() = 0;
		/*! Sets the NodeId of the Object (or ObjectType) node that contains the method.
		* The Object defines the context for the method execution. */
		virtual void setObjectId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setObjectId(const NodeId& value) = 0;

		/*! Returns the NodeId of the method to invoke. */
		virtual const INodeId* getMethodId() const = 0;
		/*! @overload */
		virtual INodeId* getMethodId() = 0;
		/*! Sets the NodeId of the method to invoke.
		*
		* If the ObjectId is the NodeId of an Object, it is allowed to use the NodeId of a method that is defined
		* in the ObjectType of that Object. */
		virtual void setMethodId(const INodeId* value) = 0;
		/*! @overload */
		virtual void setMethodId(const NodeId& value) = 0;

		/*! The methods getInputArgumentCount() and getInputArgument() are provided for efficient access to data.
		* The semantics of these methods are documented in getInputArguments(). */
		virtual OTUInt32 getInputArgumentCount() const = 0;
		/*! The methods getInputArgumentCount() and getInputArgument() are provided for efficient access to data.
		* The semantics of these methods are documented in getInputArguments(). */
		virtual const IValue* getInputArgument(OTUInt32 index) const = 0;
		/*! Returns the list of input argument values. An empty list indicates that there are no input arguments.
		*
		* @see addInputArgument() */
		virtual std::vector<Value> getInputArguments() const = 0;
		/*! Adds an input argument to the list of input argument values.
		*
		* The size and order of this list matches the size and order of the input arguments defined by the
		* InputArguments Property of the Method. The name, a description and the data type of each argument are
		* defined by the Argument data type in each element of the method's InputArguments property. */
		virtual EnumStatusCode addInputArgument(const IValue* pValue) = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const ICallMethodRequest* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const ICallMethodRequest& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const ICallMethodRequest* other) const = 0;
		/*! @overload */
		virtual int compare(const ICallMethodRequest& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const ICallMethodRequest& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const ICallMethodRequest& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end ICallMethodRequest
} // end namespace
#endif	// ICALLMETHODREQUEST_H
