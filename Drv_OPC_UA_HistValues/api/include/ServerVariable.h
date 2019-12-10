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

#ifndef SERVERVARIABLE_H
#define SERVERVARIABLE_H
#include "Base.h"
#include "Enums.h"
#include "InnerNodeId.h"
#include "NodeId.h"
#include "InnerDataValue.h"
#include "DataValue.h"
#include "ServerBaseNode.h"


namespace SoftingOPCToolbox5
{

#ifdef __cplusplus
	extern "C"
	{
#endif
	void variableOnDataProviderChanged(SoftingOPCToolbox5::Server::Variable* var, bool useDataProvider);
#ifdef __cplusplus
	}
#endif

	// Forward declarations
	namespace Server
	{
		class HistoryReadRawRequest;
		class HistoryReadRawTransaction;
		class HistoryReadProcessedRequest;
		class HistoryReadProcessedTransaction;
	}

	namespace Server
	{
		/*! The Variable class is used to define a Variable node in the address space of a server.
		* Variables are used to expose values in the address space of a server. */
		class TBC_EXPORT Variable
			: public BaseNode
		{
		public:
			/*! Constructs a new Variable instance */
			static ObjectPointer<Variable> create();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			Variable(TBHandle otbHandle);

		protected:
			/*! Default constructor */
			Variable();
			/*! For internal use only */
			Variable(bool suppressCoreInstanceCreate);

		public:
			/*! Destructor */
			virtual ~Variable();

			/*! Returns the NodeId of the data type for the variable's 'value' attribute.
			*
			* @see setDataType() */
			const INodeId* getDataType() const;
			/*! Sets the NodeId of the data type for the variable's 'value' attribute.
			* This setting is mandatory for all variables and must be defined before inserting
			* the variable in the address space of the server.
			*
			* @note It is recommended to not change the data type of a variable after it has been inserted into the address space. */
			EnumStatusCode setDataType(const INodeId* dataType);
			/*! @overload */
			EnumStatusCode setDataType(const INodeId& dataType);

			/*! Returns the cached value stored by this Variable.
			*
			* @see setDataValue() */
			const IDataValue* getDataValue() const;
			/*! Sets the cache value to be stored by this Variable.
			*
			* If there are subscriptions on this variable value the server application
			* has to call this function regularly to keep the subscriptions up to date.
			*
			* @note	The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			*		mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			*		be set, but will not be reported by a subscription.
			* @see AddressSpaceRoot::setVariableDataValues() Application::handleMonitoringChange() IDataValue::setServerTimestamp() */
			EnumStatusCode setDataValue(const IDataValue* dataValue);
			/*! @overload */
			EnumStatusCode setDataValue(const IDataValue& dataValue);

			/*! Use this method to notify clients that the semantics of the variable's value has changed.
			* For example, if the Engineering Unit of an AnalogItem "velocity" changes from "km/h" to "mph",
			* a client monitoring the velocity should be informed about the changed semantics. Therefore,
			* a server implementation would use this method to set the re-calculated value based on the new
			* semantics and to notify the velocity in "mph" for the first time.
			*
			* A client recognizes the semantic change of a data value by examining the value's status code.
			*
			* @param dataValue The data value with changed semantics
			*
			* @note Variables with semantic information should have set the EnumAccessLevel_SemanticChange in their access level.
			*       If this access level is set, the normal setDataValue automatically adds the according bit to the StatusCode of the notification.
			* @note	The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			*		mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			*		be set, but will not be reported by a subscription.
			* @see setDataValue() StatusCode::isSemanticsChangedBitSet() */
			EnumStatusCode setDataValueWithChangedSemantics(const IDataValue* dataValue);
			/*! @overload */
			EnumStatusCode setDataValueWithChangedSemantics(const IDataValue& dataValue);

			/*! Returns whether the variable's value is an array and if, how many dimensions the array has.
			*
			* Possible return values:
			* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
			* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
			* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
			* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
			* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array
			*
			* @see setValueRank() */
			OTInt32 getValueRank() const;
			/*! Sets whether the variable's value is an array and if, how many dimensions the array has.
			*
			* Possible values:
			* @li >= 1: Indicates that the variable contains an array value with this number of dimensions
			* @li ValueRank_OneOrMoreDimensions: Indicates that the variable contains an array value of one or more dimensions
			* @li ValueRank_Scalar: Indicates that the variable contains a scalar value
			* @li ValueRank_Any: Indicates that the variable contains any value, scalar or array of any dimension
			* @li ValueRank_ScalarOrOneDimension: Indicates that the variable contains a value of scalar or one dimensional array
			*
			* @note If the array dimensions don't match to the new value rank, then the array dimension are
			*       automatically updated to matching dimensions without length limitation. @see setArrayDimensions */
			EnumStatusCode setValueRank(OTInt32 valueRank);

			/*! Returns a field of integer values describing the length of each array dimension if
			* the variable has an array value. The number of elements is equal to the result
			* of getValueRank() if getValueRank() returns a positive number. A vector entry with
			* value 0 indicates that the dimension has variable length.
			*
			* @note This method returns an empty vector for scalar values or variable sized dimensions. */
			std::vector<OTUInt32> getArrayDimensions() const;
			/*! Sets a field of integer values describing the length of each array dimension if
			* the variable has an array value. The number of elements must be equal to the result
			* of getValueRank() if getValueRank() returns a positive number. A vector entry with
			* value 0 indicates that the dimension has variable length.
			*
			* @note The array dimensions attribute must not be set for scalar variable values or variable sized dimensions.
			*       If the value rank does not match to the new array dimensions, then the value rank is automatically updated
			*       to the exact dimension. @see setValueRank */
			EnumStatusCode setArrayDimensions(const std::vector<OTUInt32>& arrayDimensions);

			/*! Returns the access level of the variable that indicates how the variable's value
			* can be accessed and if it contains current and/or historic data.
			*
			* @see getAccessLevel() */
			EnumAccessLevel getAccessLevel() const;
			/*! Sets the access level of the variable that indicates how the variable's value
			* can be accessed and if it contains current and/or historic data.
			*
			* The access level does not take any user access rights into account, i.e. although the variable is writable
			* this may be restricted to a certain user / user group.
			* The value can be a combination of the available values (see EnumAccessLevel).
			*
			* Default for new created variables is EnumAccessLevel_CurrentRead. */
			EnumStatusCode setAccessLevel(EnumAccessLevel accessLevel);

			/*! Returns the user access level of the variable that indicates how the variable's value
			* can be accessed taking user access rights into account.
			*
			* @param userGroupIndex	The 0-based index into the user group
			*
			* @see getAccessLevel() */
			EnumAccessLevel getUserAccessLevel(OTUInt32 userGroupIndex) const;

			/*! Assigns the variable a previously defined AccessPattern.
			*
			* @note	This method returns an error if the key is unknown to the server.
			*		Keys are limited to values from 0...0xFFFF.
			*
			* @see AccessPattern, IAccessPattern Application::setAccessPattern() */
			EnumStatusCode setAccessPatternKey(OTUInt32 accessPatternKey);

			/*! Returns the key of the assigned AccessPattern.
			*
			* @see setAccessPatternKey() */
			OTUInt32 getAccessPatternKey() const;

			/*! Returns the value of the MinimumSamplingInterval attribute. The MinimumSamplingInterval attribute indicates
			* how "current" the value of the Variable is kept. */
			double getMinimumSamplingInterval() const;

			/*! Sets the value of the MinimumSamplingInterval attribute. The MinimumSamplingInterval attribute indicates
			* how "current" the value of the variable is kept. It specifies (in milliseconds) how fast the server can
			* reasonably sample the value for changes. A minimum sampling interval of 0 indicates that the server is to
			* monitor the item continuously. A minimum sampling interval of -1 means indeterminate.
			*
			* Default value is -1.
			*
			* @note	Please note that the value of the attribute has no effect on the sampling interval of
			*		a monitored item created by a client. It serves only as a hint to the server application. */
			EnumStatusCode setMinimumSamplingInterval(double minimumSamplingInterval);

			/*! Returns the Historizing attribute that indicates whether the server is actively collecting data for the history of
			* the variable.
			*
			* @see setIsHistorizing() */
			bool getIsHistorizing() const;
			/*! Sets the Historizing attribute that indicates whether the server is actively collecting data for the history of
			* the variable.
			*
			* This differs from the AccessLevel Attribute which identifies if the variable has any historical data.
			* A value of 'true' indicates that the server is actively collecting data. A value of 'false' indicates
			* that the server is not actively collecting data. Default value is 'false'. */
			EnumStatusCode setIsHistorizing(bool isHistorizing);

			/*! Returns the variable's type definition node.
			*
			* @see setVariableType() */
			const INodeId* getVariableType() const;
			/*! Sets the variable's type definition node.
			*
			* Use of this method is not recommended. The type of a variable is usually
			* assigned by calling BaseNode::init().
			*
			* @param variableType	The NodeId of the variable type. Well-known types are defined
			*							as constants in the Statics namespace (e.g. Statics::VariableTypeId_BaseDataVariableType).
			*
			* @see BaseNode::init() */
			EnumStatusCode setVariableType(const INodeId* variableType);
			/*! @overload */
			EnumStatusCode setVariableType(const INodeId& variableType);

			/*! Callback for a single read request to a value. Override this method to handle device read
			* requests. The default implementation for variables returns the cached value here.
			* An overridden implementation of this function should update the cache value first.
			*
			* @param transaction	The transaction of the request to handle
			* @param request		The request to handle
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleReadRequest(Server::ReadTransaction* transaction, Server::ReadRequest* request);

			/*! Callback for a single write to a value. Override this method to handle device write
			* requests. The default implementation for Variables updates the cached value here.
			* An overridden implementation of this function should perform the device update here.
			*
			* @param transaction	The transaction of the request to handle
			* @param request		The request to handle
			*
			* @note The StatusCode in the request is already preprocessed by the SDK. @see Server::WriteTransaction::handleRequests.
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleWriteRequest(Server::WriteTransaction* transaction, Server::WriteRequest* request);

#if TB5_HISTORY
			/*! Callback method called by the default implementation of Server::HistoryReadRawTransaction::handleRequests().
			*
			* This method may be overridden to provide raw historical values for this node.
			* See Server::HistoryReadRawTransaction for more details.
			*
			* @param transaction	The transaction of the request to handle
			* @param request		The request to handle
			*
			* @note When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication.
			* The subscription timing mechanism is calculated by the server timestamp of the written DataValues. This
			* mechanism expects ascending timestamps to work properly. Values with descending server timestamps can
			* be set, but will not be reported by a subscription. */
			virtual EnumStatusCode handleHistoryReadRawRequest(Server::HistoryReadRawTransaction* transaction, Server::HistoryReadRawRequest* request);

			/*! Callback method called by the default implementation of Server::HistoryReadProcessedTransaction::handleRequests().
			*
			* This method may be overridden to provide aggregated historical values for this node.
			* See Server::HistoryReadProcessedTransaction for more details.
			*
			* @param transaction	The transaction of the request to handle
			* @param request		The request to handle
			*
			* @note	When overriding this method you mustn't use blocking calls within this method since
			* this blocks the UA communication. */
			virtual EnumStatusCode handleHistoryReadProcessedRequest(Server::HistoryReadProcessedTransaction* transaction, Server::HistoryReadProcessedRequest* request);
#endif

			/*! Enables or disabled the onDataValueChanged() callback for this variable.
			*
			* @param enabled	If true, the callback is triggered for every data change
			*
			* @see onDataValueChanged() */
			void setDataValueChangeCallbackEnabled(bool enabled);

			/*! This callback method is called whenever the data value (value attribute) of the variable changes.
			*
			* @param pNewDataValue The changed data value
			*
			* @note	This callback method is disabled by default for performance reasons. Use setDataValueChangeCallbackEnabled()
			*		to enable callbacks for this variable.
			*
			* @see setDataValueChangeCallbackEnabled() */
			virtual void onDataValueChanged(const IDataValue* pNewDataValue);

			/*! Returns whether the variable has the ValueAsText property to display the string representation of an Enumeration data type.
			*
			* @see provideValueAsText() */
			bool hasValueAsText() const;

			/*! Adds the property "ValueAsText" to this node which displays the string representation of an Enumeration value.
			* The property can only be used when the data type of this variable is an Enumeration data type.
			* This optional property is a convenient way for clients, which are only interested in the string representation of
			* an enumeration value, since the Value of this Variable can only display the integer representation of the Enumeration.
			* The SDK will automatically keep update property Value updated to the Variable's Value.
			*
			* @param nodeId The nodeId for the ValueAsText property
			*
			* @note The data type of this Variable must be Enumeration or a subtype */
			EnumStatusCode provideValueAsText(const INodeId& nodeId);

		protected:
			/*! For internal use only */
			void initMembers();

		private:
			mutable InnerNodeId m_DataType;
			mutable InnerNodeId m_VariableType;
			InnerDataValue m_DataValue;

			// if core variable uses a data provider, API variable hast to store a copy of data value.
			bool			m_useDataValueCopy;
			mutable DataValueStruct m_dataValueAsCopy;

			/*! Forbid use assignment operator */
			Variable& operator=(const Variable&);
			/*! Forbid use of copy constructor */
			Variable(const Variable&);
		public:
			/*! for internal use only */
			friend void SoftingOPCToolbox5::variableOnDataProviderChanged(SoftingOPCToolbox5::Server::Variable* var, bool useDataProvider);
		private:
			void onDataProviderChanged(bool useDataProvider);

		};
		typedef ObjectPointer<Variable> VariablePtr;
		typedef ObjectPointer<const Variable> VariableConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif	// SERVERVARIABLE_H
