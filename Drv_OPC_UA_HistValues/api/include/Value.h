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

#ifndef VALUE_H
#define VALUE_H

#include "ValueStruct.h"
#include "IValue.h"
#include "Enums.h"
#include "ApiMacros.h"

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class NodeId;
	class ExpandedNodeId;
	class LocalizedText;
	class DataValue;
	class IDataValue;
	class IDateTime;
	class IApplicationDescription;
	class IServerDiagnosticsSummaryDataType;
	class ISubscriptionDiagnosticsDataType;
	class ISessionDiagnosticsDataType;
	class ISessionSecurityDiagnosticsDataType;
	class IServiceCounterDataType;
	class ISemanticChangeStructureDataType;
	class IModelChangeStructureDataType;
	class DateTime;
	class IGuid;
	class ByteString;
	class Guid;
	class QualifiedName;
	class IQualifiedName;
	class INodeId;
	class ILocalizedtext;
	class IExpandedNodeId;
	class ILocalizedText;
	class IArgument;
	class IReferenceDescription;
	class EnumerationDataTypeDescription;

	/*! The Value data type is a variant that can hold any of the other data types
	* provided by the SDK.
	*
	* The Value data type contains the following information:
	* @li	The array type (see IValue::getArrayType()) which indicates whether the variant
	*		holds a scalar, array, or matrix value
	* @li	The data type (see IValue::getDataType()) indicating the data type of the
	*		value stored in the variant
	* @li	The actual value
	*
	* The class provides additional features to simplify handling of index ranges. The methods
	* IValue::getSubset() and IValue::setSubset() enable applications to extract and modify
	* a subset of any array value.
	*
	* The method IValue::castTo() can be used to cast the value stored in the variant between
	* different data types. */
	class TBC_EXPORT Value
		: public IValue
	{
	public:
		/*! Default constructor which initializes the value to null.
		* The array type is set to EnumValueArrayType_Scalar, the data type is
		* set to EnumDataTypeId_Null. */
		Value();
		/*! Constructs a copy of the given instance */
		Value(const Value& cp);
		/*! @overload */
		Value(const IValue*);
		/*! Constructor that initializes the variant with the given value. */
		Value(const std::vector<Value>& arrayValue);
		/*! @overload */
		Value(OTBoolean value);
		/*! @overload */
		Value(const std::vector<OTBoolean>& arrayBool);
		/*! @overload */
		Value(OTUInt8 value);
		/*! @overload */
		Value(const std::vector<OTUInt8>& arrayUInt8);
		/*! @overload */
		Value(OTInt8 value);
		/*! @overload */
		Value(const std::vector<OTInt8>& arrayInt8);
		/*! @overload */
		Value(OTUInt16 value);
		/*! @overload */
		Value(const std::vector<OTUInt16>& arrayUInt16);
		/*! @overload */
		Value(OTInt16 value);
		/*! @overload */
		Value(const std::vector<OTInt16>& arrayInt16);
		/*! @overload */
		Value(OTUInt32 value);
		/*! @overload */
		Value(const std::vector<OTUInt32>& arrayUInt32);
		/*! @overload */
		Value(OTInt32 value);
		/*! @overload */
		Value(const std::vector<OTInt32>& arrayInt32);
		/*! @overload */
		Value(OTUInt64 value);
		/*! @overload */
		Value(const std::vector<OTUInt64>& arrayUInt64);
		/*! @overload */
		Value(OTInt64 value);
		/*! @overload */
		Value(const std::vector<OTInt64>& arrayInt64);
		/*! @overload */
		Value(OTFloat value);
		/*! @overload */
		Value(const std::vector<OTFloat>& arrayFloat);
		/*! @overload */
		Value(OTDouble value);
		/*! @overload */
		Value(const std::vector<OTDouble>& arrayDouble);
		/*! @overload */
		Value(const OTChar* value);
		/*! @overload */
		Value(const tstring& value);
		/*! @overload */
		Value(const std::vector<tstring>& arrayString);
		/*! @overload */
		Value(const IDateTime* value);
		/*! @overload */
		Value(const std::vector<DateTime>& arrayDateTime);
		/*! @overload */
		Value(const unsigned char* pData, unsigned length);
		/*! @overload */
		Value(const IByteString* pByteString);
		/*! @overload */
		Value(const std::vector<ByteString>& arrayByteString);
		/*! @overload */
		Value(const IGuid* pGuid);
		/*! @overload */
		Value(const std::vector<Guid>& arrayGuid);
		/*! @overload */
		Value(const INodeId* pNodeId);
		/*! @overload */
		Value(const std::vector<NodeId>& arrayNodeId);
		/*! @overload */
		Value(const IExpandedNodeId* pNodeId);
		/*! @overload */
		Value(const std::vector<ExpandedNodeId>& arrayExpandedNodeId);
		/*! @overload */
		Value(EnumStatusCode statusCode);
		/*! @overload */
		Value(const std::vector<EnumStatusCode>& arrayStatusCode);
		/*! @overload */
		Value(const IQualifiedName*  pQualifiedName);
		/*! @overload */
		Value(const std::vector<QualifiedName>& arrayQualifiedName);
		/*! @overload */
		Value(const ILocalizedText* pLocalizedText);
		/*! @overload */
		Value(const std::vector<LocalizedText>& arrayLocalizedText);
		/*! @overload */
		Value(const IDataValue*	pDataValue);
		/*! @overload */
		Value(const std::vector<DataValue>& arrayDataValue);
		/*! @overload */
		Value(const IArgument* pArgument);
		/*! @overload */
		Value(const std::vector<Argument>& arrayArgument);
		/*! @overload */
		Value(const IRange*	pRange);
		/*! @overload */
		Value(const std::vector<Range>& arrayRange);
		/*! @overload */
		Value(const IReferenceDescription* pReferenceDescription);
		/*! @overload */
		Value(const std::vector<ReferenceDescription>& arrayReferenceDescription);
		/*! @overload */
		Value(const IApplicationDescription* pApplicationDescription);
		/*! @overload */
		Value(const std::vector<ApplicationDescription>& arrayApplicationDescription);
		/*! @overload */
		Value(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);
		/*! @overload */
		Value(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);
		/*! @overload */
		Value(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);
		/*! @overload */
		Value(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);
		/*! @overload */
		Value(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);
		/*! @overload */
		Value(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);
		/*! @overload */
		Value(const IServiceCounterDataType* pServiceCounterDataType);
		/*! @overload */
		Value(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);
		/*! @overload */
		Value(const IEUInformation* pEUInformation);
		/*! @overload */
		Value(const std::vector<EUInformation>& arrayEUInformation);
		/*! @overload */
		Value(const ITimeZone* pTimeZone);
		/*! @overload */
		Value(const std::vector<TimeZone>& arrayTimeZone);
		/*! @overload */
		Value(const IUserIdentityToken* pUserIdentityToken);
		/*! @overload */
		Value(const std::vector<UserIdentityToken>& arrayUserIdentityToken);
		/*! @overload */
		Value(const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);
		/*! @overload */
		Value(const ISignedSoftwareCertificate* pSignedSoftwareCertificate);
		/*! @overload */
		Value(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		/*! @overload */
		Value(const IBuildInfo* pBuildInfo);
		/*! @overload */
		Value(const std::vector<BuildInfo>& arrayBuildInfo);
		/*! @overload */
		Value(const IEventFilter* pEventFilter);
		/*! @overload */
		Value(const std::vector<EventFilter>& arrayEventFilter);
		/*! @overload */
		Value(const IServerStatusDataType* pServerStatusDataType);
		/*! @overload */
		Value(const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		/*! @overload */
		Value(const IEnumValueType* pEnumValueType);
		/*! @overload */
		Value(const std::vector<EnumValueType>& arrayEnumValueType);

		/*! Destructor */
		virtual ~Value();

		/*! Assigns the contents of @p cp to this instance */
		Value& operator=(const IValue* cp);
		/*! @overload */
		Value& operator=(const IValue& cp);
		/*! @overload */
		Value& operator=(const Value& cp);

		/* see IValue::set */
		virtual EnumStatusCode set(const IValue* pSrc);
		/*! @overload */
		virtual EnumStatusCode set(const IValue& pSrc);

		/* see IValue::compare */
		virtual int compare(const IValue* other) const;
		/*! @overload */
		virtual int compare(const IValue& other) const;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other) const;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other) const;

		/*! Returns whether two Value instances are equal.
		*
		* If this method is applied to two instances @p value1 and @p value2, the result
		* is equivalent to value1.compare(value2) == 0. */
		static bool areEqual(const Value& value1, const Value& value2);

		/* see IValue::getDataType */
		virtual EnumDataTypeId getDataType() const;

		/* see IValue::getArrayType */
		virtual EnumValueArrayType getArrayType() const;

		/* see IValue::getSubset */
		virtual EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const;
		/* see IValue::setSubset */
		virtual EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange);

		/* see IValue::canCastTo */
		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const;
		/* see IValue::castTo */
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const;

		/* see IValue::toString */
		virtual tstring toString() const;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Boolean content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getBoolean */
		virtual EnumStatusCode getBoolean(OTBoolean* target) const;
		/*! @overload */
		virtual OTBoolean getBoolean() const;
		/* see IValue::setBoolean */
		virtual void setBoolean(OTBoolean value);

		/* see IValue::getBooleanArray */
		virtual std::vector<OTBoolean> getBooleanArray() const;
		/*! @overload */
		virtual EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const;
		/* see IValue::setBooleanArray */
		virtual EnumStatusCode setBooleanArray(const std::vector<OTBoolean>& arrayBool);

		/* see IValue::getBooleanMatrix */
		virtual EnumStatusCode getBooleanMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTBoolean>& matrixValues) const;
		/* see IValue::setBooleanMatrix */
		virtual EnumStatusCode setBooleanMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTBoolean* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt8 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt8 */
		virtual EnumStatusCode getUInt8(OTUInt8* target) const;
		/*! @overload */
		virtual OTUInt8 getUInt8() const;
		/* see IValue::setUInt8 */
		virtual void setUInt8(OTUInt8 value);

		/* see IValue::getUInt8Array */
		virtual EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt8> getUInt8Array() const;
		/* see IValue::setUInt8Array */
		virtual EnumStatusCode setUInt8Array(const std::vector<OTUInt8>& arrayUInt8);

		/* see IValue::getUInt8Matrix */
		virtual EnumStatusCode getUInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt8>& matrixValues) const;
		/* see IValue::setUInt8Matrix */
		virtual EnumStatusCode setUInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt8* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int8 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt8 */
		virtual EnumStatusCode getInt8(OTInt8* target) const;
		/*! @overload */
		virtual OTInt8 getInt8() const;
		/* see IValue::setInt8 */
		virtual void setInt8(OTInt8 value);

		/* see IValue::getInt8Array */
		virtual EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const;
		/*! @overload */
		virtual std::vector<OTInt8> getInt8Array() const;
		/* see IValue::setInt8Array */
		virtual EnumStatusCode setInt8Array(const std::vector<OTInt8>& arrayInt8);

		/* see IValue::getInt8Matrix */
		virtual EnumStatusCode getInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt8>& matrixValues) const;
		/* see IValue::setInt8Matrix */
		virtual EnumStatusCode setInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt8* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt16 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt16 */
		virtual EnumStatusCode getUInt16(OTUInt16* target) const;
		/*! @overload */
		virtual OTUInt16 getUInt16() const;
		/* see IValue::setUInt16 */
		virtual void setUInt16(OTUInt16 value);

		/* see IValue::getUInt16Array */
		virtual EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt16> getUInt16Array() const;
		/* see IValue::setUInt16Array */
		virtual EnumStatusCode setUInt16Array(const std::vector<OTUInt16>& arrayUInt16);

		/* see IValue::getUInt16Matrix */
		virtual EnumStatusCode getUInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt16>& matrixValues) const;
		/* see IValue::setUInt16Matrix */
		virtual EnumStatusCode setUInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt16* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int16 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt16 */
		virtual EnumStatusCode getInt16(OTInt16* target) const;
		/*! @overload */
		virtual OTInt16 getInt16() const;
		/* see IValue::setInt16 */
		virtual void setInt16(OTInt16 value);

		/* see IValue::getInt16Array */
		virtual EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const;
		/*! @overload */
		virtual std::vector<OTInt16> getInt16Array() const;
		/* see IValue::setInt16Array */
		virtual EnumStatusCode setInt16Array(const std::vector<OTInt16>& arrayInt16);

		/* see IValue::getInt16Matrix */
		virtual EnumStatusCode getInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt16>& matrixValues) const;
		/* see IValue::setInt16Matrix */
		virtual EnumStatusCode setInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt16* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt32 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt32 */
		virtual EnumStatusCode getUInt32(OTUInt32* target) const;
		/*! @overload */
		virtual OTUInt32 getUInt32() const;
		/* see IValue::setUInt32 */
		virtual void setUInt32(OTUInt32 value);

		/* see IValue::getInt32Array */
		virtual EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const;
		/*! @overload */
		virtual std::vector<OTInt32> getInt32Array() const;
		/* see IValue::setInt32Array */
		virtual EnumStatusCode setUInt32Array(const std::vector<OTUInt32>& arrayUInt32);

		/* see IValue::getUInt32Matrix */
		virtual EnumStatusCode getUInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt32>& matrixValues) const;
		/* see IValue::setUInt32Matrix */
		virtual EnumStatusCode setUInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt32* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int32 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt32 */
		virtual EnumStatusCode getInt32(OTInt32* target) const;
		/*! @overload */
		virtual OTInt32 getInt32() const;
		/* see IValue::setInt32 */
		virtual void setInt32(OTInt32 value);

		/* see IValue::getUInt32Array */
		virtual EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt32> getUInt32Array() const;
		/* see IValue::setUInt32Array */
		virtual EnumStatusCode setInt32Array(const std::vector<OTInt32>& arrayInt32);

		/* see IValue::getInt32Matrix */
		virtual EnumStatusCode getInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt32>& matrixValues) const;
		/* see IValue::setInt32Matrix */
		virtual EnumStatusCode setInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt32* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt64 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUInt64 */
		virtual EnumStatusCode getUInt64(OTUInt64* target) const;
		/*! @overload */
		virtual OTUInt64 getUInt64() const;
		/* see IValue::setUInt64 */
		virtual void setUInt64(OTUInt64 value);

		/* see IValue::getUInt64Array */
		virtual EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const;
		/*! @overload */
		virtual std::vector<OTUInt64> getUInt64Array() const;
		/* see IValue::setUInt64Array */
		virtual EnumStatusCode setUInt64Array(const std::vector<OTUInt64>& arrayUInt64);

		/* see IValue::getUInt64Matrix */
		virtual EnumStatusCode getUInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt64>& matrixValues) const;
		/* see IValue::setUInt64Matrix */
		virtual EnumStatusCode setUInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt64* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int64 content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getInt64 */
		virtual EnumStatusCode getInt64(OTInt64* target) const;
		/*! @overload */
		virtual OTInt64 getInt64() const;
		/* see IValue::setInt64 */
		virtual void setInt64(OTInt64 value);

		/* see IValue::getInt64Array */
		virtual EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const;
		/*! @overload */
		virtual std::vector<OTInt64> getInt64Array() const;
		/* see IValue::setInt64Array */
		virtual EnumStatusCode setInt64Array(const std::vector<OTInt64>& arrayInt64);

		/* see IValue::getInt64Matrix */
		virtual EnumStatusCode getInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt64>& matrixValues) const;
		/* see IValue::setInt64Matrix */
		virtual EnumStatusCode setInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt64* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Float content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getFloat */
		virtual EnumStatusCode getFloat(OTFloat* target) const;
		/*! @overload */
		virtual OTFloat getFloat() const;
		/* see IValue::setFloat */
		virtual void setFloat(OTFloat value);

		/* see IValue::getFloatArray */
		virtual EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const;
		/*! @overload */
		virtual std::vector<OTFloat> getFloatArray() const;
		/* see IValue::setFloatArray */
		virtual EnumStatusCode setFloatArray(const std::vector<OTFloat>& arrayFloat);

		/* see IValue::getFloatMatrix */
		virtual EnumStatusCode getFloatMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTFloat>& matrixValues) const;
		/* see IValue::setFloatMatrix */
		virtual EnumStatusCode setFloatMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTFloat* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Double content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDouble */
		virtual EnumStatusCode getDouble(OTDouble* target) const;
		/*! @overload */
		virtual OTDouble getDouble() const;
		/* see IValue::setDouble */
		virtual void setDouble(OTDouble value);

		/* see IValue::getDoubleArray */
		virtual EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const;
		/*! @overload */
		virtual std::vector<OTDouble> getDoubleArray() const;
		/* see IValue::setDoubleArray */
		virtual EnumStatusCode setDoubleArray(const std::vector<OTDouble>& arrayDouble);

		/* see IValue::getDoubleMatrix */
		virtual EnumStatusCode getDoubleMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTDouble>& matrixValues) const;
		/* see IValue::setDoubleMatrix */
		virtual EnumStatusCode setDoubleMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTDouble* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DateTime content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDateTime */
		virtual EnumStatusCode getDateTime(DateTime& target) const;
		/*! @overload */
		virtual DateTime getDateTime() const;
		/* see IValue::setDateTime */
		virtual EnumStatusCode setDateTime(const IDateTime* dateTime);

		/* see IValue::getDateTimeArray */
		virtual EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const;
		/*! @overload */
		virtual std::vector<DateTime> getDateTimeArray() const;
		/* see IValue::setDateTimeArray */
		virtual EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime);

		/* see IValue::getDateTimeMatrix */
		virtual EnumStatusCode getDateTimeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DateTime>& matrixValues) const;
		/* see IValue::setDateTimeMatrix */
		virtual EnumStatusCode setDateTimeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DateTime* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for String content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getString */
		virtual EnumStatusCode getString(tstring& target) const;
		/*! @overload */
		virtual tstring getString() const;
		/* see IValue::setString */
		virtual EnumStatusCode setString(const tstring& value);

		/* see IValue::getStringArray */
		virtual EnumStatusCode getStringArray(std::vector<tstring>& target) const;
		/*! @overload */
		virtual std::vector<tstring> getStringArray() const;
		/* see IValue::setStringArray */
		virtual EnumStatusCode setStringArray(const std::vector<tstring>& arrayString);

		/* see IValue::getStringMatrix */
		virtual EnumStatusCode getStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<tstring>& matrixValues) const;
		/* see IValue::setStringMatrix */
		virtual EnumStatusCode setStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const tstring* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Guid content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getGuid */
		virtual EnumStatusCode getGuid(Guid& target) const;
		/*! @overload */
		virtual Guid getGuid() const;
		/* see IValue::setGuid */
		virtual EnumStatusCode setGuid(const IGuid* guid);

		/* see IValue::getGuidArray */
		virtual EnumStatusCode getGuidArray(std::vector<Guid>& target) const;
		/*! @overload */
		virtual std::vector<Guid> getGuidArray() const;
		/* see IValue::setGuidArray */
		virtual EnumStatusCode setGuidArray(const std::vector<Guid>& arrayGuid);
		/* see IValue::getGuidMatrix */
		virtual EnumStatusCode getGuidMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Guid>& matrixValues) const;
		/* see IValue::setGuidMatrix */
		virtual EnumStatusCode setGuidMatrix(const std::vector<OTUInt32>& arrayDimensions, const Guid* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumStatusCode content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getStatusCode */
		virtual EnumStatusCode getStatusCode(EnumStatusCode* target) const;
		/*! @overload */
		virtual EnumStatusCode getStatusCode() const;
		/* see IValue::setStatusCode */
		virtual void setStatusCode(EnumStatusCode statusCode);

		/* see IValue::getStatusCodeArray */
		virtual EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const;
		/*! @overload */
		virtual std::vector<EnumStatusCode> getStatusCodeArray() const;
		/* see IValue::setStatusCodeArray */
		virtual EnumStatusCode setStatusCodeArray(const std::vector<EnumStatusCode>& arrayStatusCode);

		/* see IValue::getStatusCodeMatrix */
		virtual EnumStatusCode getStatusCodeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumStatusCode>& matrixValues) const;
		/* see IValue::setStatusCodeMatrix */
		virtual EnumStatusCode setStatusCodeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumStatusCode* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ByteString content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getByteString */
		virtual EnumStatusCode getByteString(ByteString& target) const;
		/*! @overload */
		virtual ByteString getByteString() const;
		/* see IValue::setByteString */
		virtual EnumStatusCode setByteString(const unsigned char* pData, unsigned length);
		/*! @overload */
		virtual EnumStatusCode setByteString(const ByteString& byteString);
		/*! @overload */
		virtual EnumStatusCode setByteString(const IByteString* byteString);

		/* see IValue::getByteStringArray */
		virtual EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const;
		/*! @overload */
		virtual std::vector<ByteString> getByteStringArray() const;
		/* see IValue::setByteStringArray */
		virtual EnumStatusCode setByteStringArray(const std::vector<ByteString>& arrayByteString);

		/* see IValue::getByteStringMatrix */
		virtual EnumStatusCode getByteStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& matrixValues) const;
		/* see IValue::setByteStringMatrix */
		virtual EnumStatusCode setByteStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const ByteString* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for XmlElement content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getXmlElement */
		virtual EnumStatusCode getXmlElement(XmlElement& target) const;
		/*! @overload */
		virtual XmlElement getXmlElement() const;
		/* see IValue::setXmlElement */
		virtual EnumStatusCode setXmlElement(const XmlElement& xmlElement);

		/* see IValue::getXmlElementArray */
		virtual EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const;
		/*! @overload */
		virtual std::vector<XmlElement> getXmlElementArray() const;
		/* see IValue::setXmlElementArray */
		virtual EnumStatusCode setXmlElementArray(const std::vector<XmlElement>& arrayXmlElement);

		/* see IValue::getXmlElementMatrix */
		virtual EnumStatusCode getXmlElementMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<XmlElement>& matrixValues) const;
		/* see IValue::setXmlElementMatrix */
		virtual EnumStatusCode setXmlElementMatrix(const std::vector<OTUInt32>& arrayDimensions, const XmlElement* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Value content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getValueArray */
		virtual EnumStatusCode getValueArray(std::vector<Value>& target) const;
		/*! @overload */
		virtual std::vector<Value> getValueArray() const;
		/* see IValue::setValueArray */
		virtual EnumStatusCode setValueArray(const std::vector<Value>& arrayValue);

		/* see IValue::getValueMatrix */
		virtual EnumStatusCode getValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Value>& matrixValues) const;
		/* see IValue::setValueMatrix */
		virtual EnumStatusCode setValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const Value* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataValue content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDataValue */
		virtual EnumStatusCode getDataValue(DataValue& target) const;
		/*! @overload */
		virtual DataValue getDataValue() const;
		/* see IValue::setDataValue */
		virtual EnumStatusCode setDataValue(const IDataValue* pDataValue);

		/* see IValue::getDataValueArray */
		virtual std::vector<DataValue> getDataValueArray() const;
		/*! @overload */
		virtual EnumStatusCode getDataValueArray(std::vector<DataValue>&) const;
		/* see IValue::setDataValueArray */
		virtual EnumStatusCode setDataValueArray(const std::vector<DataValue>& arrayDataValue);

		/* see IValue::getDataValueMatrix */
		virtual EnumStatusCode getDataValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataValue>& matrixValues) const;
		/* see IValue::setDataValueMatrix */
		virtual EnumStatusCode setDataValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataValue* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ExpandedNodeId content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getExpandedNodeId */
		virtual EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const;
		/*! @overload */
		virtual ExpandedNodeId getExpandedNodeId() const;
		/* see IValue::setExpandedNodeId */
		virtual EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pExpandedNodeId);

		/*! @overload */
		virtual EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>&) const;
		/* see IValue::getExpandedNodeIdArray */
		virtual std::vector<ExpandedNodeId> getExpandedNodeIdArray() const;
		/* see IValue::setExpandedNodeIdArray */
		virtual EnumStatusCode setExpandedNodeIdArray(const std::vector<ExpandedNodeId>& arrayExpandedNodeId);

		/* see IValue::getExpandedNodeIdMatrix */
		virtual EnumStatusCode getExpandedNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ExpandedNodeId>& matrixValues) const;
		/* see IValue::setExpandedNodeIdMatrix */
		virtual EnumStatusCode setExpandedNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const ExpandedNodeId* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for LocalizedText content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getLocalizedText */
		virtual EnumStatusCode getLocalizedText(LocalizedText& target) const;
		/*! @overload */
		virtual LocalizedText getLocalizedText() const;
		/* see IValue::setLocalizedText */
		virtual EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText);

		/* see IValue::getLocalizedTextArray */
		virtual std::vector<LocalizedText> getLocalizedTextArray() const;
		/*! @overload */
		virtual EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>&) const;
		/* see IValue::setLocalizedTextArray */
		virtual EnumStatusCode setLocalizedTextArray(const std::vector<LocalizedText>& arrayLocalizedText);

		/* see IValue::getLocalizedTextMatrix */
		virtual EnumStatusCode getLocalizedTextMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<LocalizedText>& matrixValues) const;
		/* see IValue::setLocalizedTextMatrix */
		virtual EnumStatusCode setLocalizedTextMatrix(const std::vector<OTUInt32>& arrayDimensions, const LocalizedText* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for QualifiedName content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getQualifiedName */
		virtual EnumStatusCode getQualifiedName(QualifiedName& target) const;
		/*! @overload */
		virtual QualifiedName getQualifiedName() const;
		/* see IValue::setQualifiedName */
		virtual EnumStatusCode setQualifiedName(const IQualifiedName* pQualifiedName);

		/* see IValue::getQualifiedNameArray */
		virtual std::vector<QualifiedName> getQualifiedNameArray() const;
		/*! @overload */
		virtual EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>&) const;
		/* see IValue::setQualifiedNameArray */
		virtual EnumStatusCode setQualifiedNameArray(const std::vector<QualifiedName>& arrayQualifiedName);

		/* see IValue::getQualifiedNameMatrix */
		virtual EnumStatusCode getQualifiedNameMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<QualifiedName>& matrixValues) const;
		/* see IValue::setQualifiedNameMatrix */
		virtual EnumStatusCode setQualifiedNameMatrix(const std::vector<OTUInt32>& arrayDimensions, const QualifiedName* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for NodeId content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getNodeId */
		virtual EnumStatusCode getNodeId(NodeId& target) const;
		/*! @overload */
		virtual NodeId getNodeId() const;
		/* see IValue::setNodeId */
		virtual EnumStatusCode setNodeId(const INodeId* pNodeId);

		/* see IValue::getNodeIdArray */
		virtual std::vector<NodeId> getNodeIdArray() const;
		/*! @overload */
		virtual EnumStatusCode getNodeIdArray(std::vector<NodeId>&) const;
		/* see IValue::setNodeIdArray */
		virtual EnumStatusCode setNodeIdArray(const std::vector<NodeId>& arrayNodeId);

		/* see IValue::getNodeIdMatrix */
		virtual EnumStatusCode getNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<NodeId>& matrixValues) const;
		/* see IValue::setNodeIdMatrix */
		virtual EnumStatusCode setNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const NodeId* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DiagnosticInfo content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDiagnosticInfo */
		virtual DiagnosticInfo getDiagnosticInfo() const;
		/* see IValue::getDiagnosticInfo */
		virtual EnumStatusCode getDiagnosticInfo(DiagnosticInfo& target) const;
		/* see IValue::setDiagnosticInfo */
		virtual EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* pInfo);

		/* see IValue::getDiagnosticInfoArray */
		virtual std::vector<DiagnosticInfo> getDiagnosticInfoArray() const;
		/* see IValue::getDiagnosticInfoArray */
		virtual EnumStatusCode getDiagnosticInfoArray(std::vector<DiagnosticInfo>& target) const;
		/* see IValue::setDiagnosticInfoArray */
		virtual EnumStatusCode setDiagnosticInfoArray(const std::vector<DiagnosticInfo>& arrayDiagnosticInfo);

		/* see IValue::getDiagnosticInfoMatrix */
		virtual EnumStatusCode getDiagnosticInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DiagnosticInfo>& matrixValues) const;
		/* see IValue::setDiagnosticInfoMatrix */
		virtual EnumStatusCode setDiagnosticInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const DiagnosticInfo* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EUInformation content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEUInformation */
		virtual EnumStatusCode getEUInformation(EUInformation& target) const;
		/*! @overload */
		virtual EUInformation getEUInformation() const;
		/* see IValue::setEUInformation */
		virtual EnumStatusCode setEUInformation(const IEUInformation* pEUInformation);

		/* see IValue::getEUInformationArray */
		virtual std::vector<EUInformation> getEUInformationArray() const;
		/*! @overload */
		virtual EnumStatusCode getEUInformationArray(std::vector<EUInformation>&) const;
		/* see IValue::setEUInformationArray */
		virtual EnumStatusCode setEUInformationArray(const std::vector<EUInformation>& arrayEUInformation);

		/* see IValue::getEUInformationMatrix */
		virtual EnumStatusCode getEUInformationMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EUInformation>& matrixValues) const;
		/* see IValue::setEUInformationMatrix */
		virtual EnumStatusCode setEUInformationMatrix(const std::vector<OTUInt32>& arrayDimensions, const EUInformation* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for TimeZone content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getTimeZone */
		virtual EnumStatusCode getTimeZone(TimeZone& target) const;
		/*! @overload */
		virtual TimeZone getTimeZone() const;
		/* see IValue::setTimeZone */
		virtual EnumStatusCode setTimeZone(const ITimeZone* pTimeZone);

		/* see IValue::getTimeZoneArray */
		virtual std::vector<TimeZone> getTimeZoneArray() const;
		/*! @overload */
		virtual EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const;
		/* see IValue::setTimeZoneArray */
		virtual EnumStatusCode setTimeZoneArray(const std::vector<TimeZone>& arrayTimeZone);

		/* see IValue::getTimeZoneMatrix */
		virtual EnumStatusCode getTimeZoneMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<TimeZone>& matrixValues) const;
		/* see IValue::setTimeZoneMatrix */
		virtual EnumStatusCode setTimeZoneMatrix(const std::vector<OTUInt32>& arrayDimensions, const TimeZone* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Argument content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getArgument */
		virtual EnumStatusCode getArgument(Argument& target) const;
		/*! @overload */
		virtual Argument getArgument() const;
		/* see IValue::setArgument */
		virtual EnumStatusCode setArgument(const IArgument* pArgument);

		/* see IValue::getArgumentArray */
		virtual std::vector<Argument> getArgumentArray() const;
		/*! @overload */
		virtual EnumStatusCode getArgumentArray(std::vector<Argument>&) const;
		/* see IValue::setArgumentArray */
		virtual EnumStatusCode setArgumentArray(const std::vector<Argument>& arrayArgument);

		/* see IValue::getArgumentMatrix */
		virtual EnumStatusCode getArgumentMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Argument>& matrixValues) const;
		/* see IValue::setArgumentMatrix */
		virtual EnumStatusCode setArgumentMatrix(const std::vector<OTUInt32>& arrayDimensions, const Argument* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Range content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getRange */
		virtual EnumStatusCode getRange(Range& target) const;
		/*! @overload */
		virtual Range getRange() const;
		/* see IValue::setRange */
		virtual EnumStatusCode setRange(const IRange* pRange);

		/* see IValue::getRangeArray */
		virtual std::vector<Range> getRangeArray() const;
		/*! @overload */
		virtual EnumStatusCode getRangeArray(std::vector<Range>&) const;
		/* see IValue::setRangeArray */
		virtual EnumStatusCode setRangeArray(const std::vector<Range>& arrayRange);

		/* see IValue::getRangeMatrix */
		virtual EnumStatusCode getRangeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Range>& matrixValues) const;
		/* see IValue::setRangeMatrix */
		virtual EnumStatusCode setRangeMatrix(const std::vector<OTUInt32>& arrayDimensions, const Range* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReferenceDescription content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getReferenceDescription */
		virtual EnumStatusCode getReferenceDescription(ReferenceDescription& target) const;
		/*! @overload */
		virtual ReferenceDescription getReferenceDescription() const;
		/* see IValue::setReferenceDescription */
		virtual EnumStatusCode setReferenceDescription(const IReferenceDescription* pReferenceDescription);

		/* see IValue::getReferenceDescriptionArray */
		virtual std::vector<ReferenceDescription> getReferenceDescriptionArray() const;
		/*! @overload */
		virtual EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>&) const;
		/* see IValue::setReferenceDescriptionArray */
		virtual EnumStatusCode setReferenceDescriptionArray(const std::vector<ReferenceDescription>& arrayReferenceDescription);

		/* see IValue::getReferenceDescriptionMatrix */
		virtual EnumStatusCode getReferenceDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReferenceDescription>& matrixValues) const;
		/* see IValue::setReferenceDescriptionMatrix */
		virtual EnumStatusCode setReferenceDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReferenceDescription* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ApplicationDescription content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getApplicationDescription */
		virtual EnumStatusCode getApplicationDescription(ApplicationDescription& target) const;
		/*! @overload */
		virtual ApplicationDescription getApplicationDescription() const;
		/* see IValue::setApplicationDescription */
		virtual EnumStatusCode setApplicationDescription(const IApplicationDescription* pApplicationDescription);

		/* see IValue::getApplicationDescriptionArray */
		virtual std::vector<ApplicationDescription> getApplicationDescriptionArray() const;
		/*! @overload */
		virtual EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>&) const;
		/* see IValue::setApplicationDescriptionArray */
		virtual EnumStatusCode setApplicationDescriptionArray(const std::vector<ApplicationDescription>& arrayApplicationDescription);

		/* see IValue::getApplicationDescriptionMatrix */
		virtual EnumStatusCode getApplicationDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ApplicationDescription>& matrixValues) const;
		/* see IValue::setApplicationDescriptionMatrix */
		virtual EnumStatusCode setApplicationDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ApplicationDescription* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerDiagnosticsSummaryDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServerDiagnosticsSummaryDataType */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const;
		/*! @overload */
		virtual ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType() const;
		/* see IValue::setServerDiagnosticsSummaryDataType */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType);

		/* see IValue::getServerDiagnosticsSummaryDataTypeArray */
		virtual std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>&) const;
		/* see IValue::setServerDiagnosticsSummaryDataTypeArray */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType);

		/* see IValue::getServerDiagnosticsSummaryDataTypeMatrix */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerDiagnosticsSummaryDataType>& matrixValues) const;
		/* see IValue::setServerDiagnosticsSummaryDataTypeMatrix */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerDiagnosticsSummaryDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SubscriptionDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSubscriptionDiagnosticsDataType */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType() const;
		/* see IValue::setSubscriptionDiagnosticsDataType */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType);

		/* see IValue::getSubscriptionDiagnosticsDataTypeArray */
		virtual std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>&) const;
		/* see IValue::setSubscriptionDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType);

		/* see IValue::getSubscriptionDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SubscriptionDiagnosticsDataType>& matrixValues) const;
		/* see IValue::setSubscriptionDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SubscriptionDiagnosticsDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSessionDiagnosticsDataType */
		virtual EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SessionDiagnosticsDataType getSessionDiagnosticsDataType() const;
		/* see IValue::setSessionDiagnosticsDataType */
		virtual EnumStatusCode setSessionDiagnosticsDataType(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType);

		/* see IValue::getSessionDiagnosticsDataTypeArray */
		virtual std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>&) const;
		/* see IValue::setSessionDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeArray(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType);

		/* see IValue::getSessionDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionDiagnosticsDataType>& matrixValues) const;
		/* see IValue::setSessionDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionDiagnosticsDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionSecurityDiagnosticsDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSessionSecurityDiagnosticsDataType */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const;
		/*! @overload */
		virtual SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType() const;
		/* see IValue::setSessionSecurityDiagnosticsDataType */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType);

		/* see IValue::getSessionSecurityDiagnosticsDataTypeArray */
		virtual std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>&) const;
		/* see IValue::setSessionSecurityDiagnosticsDataTypeArray */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType);

		/* see IValue::getSessionSecurityDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionSecurityDiagnosticsDataType>& matrixValues) const;
		/* see IValue::setSessionSecurityDiagnosticsDataTypeMatrix */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionSecurityDiagnosticsDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServiceCounterDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServiceCounterDataType */
		virtual EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const;
		/*! @overload */
		virtual ServiceCounterDataType getServiceCounterDataType() const;
		/* see IValue::setServiceCounterDataType */
		virtual EnumStatusCode setServiceCounterDataType(const IServiceCounterDataType* pServiceCounterDataType);

		/* see IValue::getServiceCounterDataTypeArray */
		virtual std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>&) const;
		/* see IValue::setServiceCounterDataTypeArray */
		virtual EnumStatusCode setServiceCounterDataTypeArray(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType);

		/* see IValue::getServiceCounterDataTypeMatrix */
		virtual EnumStatusCode getServiceCounterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServiceCounterDataType>& matrixValues) const;
		/* see IValue::setServiceCounterDataTypeMatrix */
		virtual EnumStatusCode setServiceCounterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServiceCounterDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getUserIdentityToken */
		virtual EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const;
		/*! @overload */
		virtual UserIdentityToken getUserIdentityToken() const;
		/* see IValue::setUserIdentityToken */
		virtual EnumStatusCode setUserIdentityToken(const IUserIdentityToken* pUserIdentityToken);

		/* see IValue::getUserIdentityTokenArray */
		virtual std::vector<UserIdentityToken> getUserIdentityTokenArray() const;
		/*! @overload */
		virtual EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>&) const;
		/* see IValue::setUserIdentityTokenArray */
		virtual EnumStatusCode setUserIdentityTokenArray(const std::vector<UserIdentityToken>& arrayUserIdentityToken);

		/* see IValue::getUserIdentityTokenMatrix */
		virtual EnumStatusCode getUserIdentityTokenMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<UserIdentityToken>& matrixValues) const;
		/* see IValue::setUserIdentityTokenMatrix */
		virtual EnumStatusCode setUserIdentityTokenMatrix(const std::vector<OTUInt32>& arrayDimensions, const UserIdentityToken* matrixValues);


		////////////////////////////////////////////////////////////////////////////////
		// Value access for SignedSoftwareCertificate content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSignedSoftwareCertificate */
		virtual EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const;
		/*! @overload */
		virtual SignedSoftwareCertificate getSignedSoftwareCertificate() const;
		/* see IValue::setSignedSoftwareCertificate */
		virtual EnumStatusCode setSignedSoftwareCertificate(const ISignedSoftwareCertificate* pSignedSoftwareCertificate);

		/* see IValue::getSignedSoftwareCertificateArray */
		virtual std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray() const;
		/*! @overload */
		virtual EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>&) const;
		/* see IValue::setSignedSoftwareCertificateArray */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate);
		/*! @overload */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<const ISignedSoftwareCertificate*>& arraySignedSoftwareCertificate);

		/* see IValue::getSignedSoftwareCertificateMatrix */
		virtual EnumStatusCode getSignedSoftwareCertificateMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SignedSoftwareCertificate>& matrixValues) const;
		/* see IValue::setSignedSoftwareCertificateMatrix */
		virtual EnumStatusCode setSignedSoftwareCertificateMatrix(const std::vector<OTUInt32>& arrayDimensions, const SignedSoftwareCertificate* matrixValues);

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for SemanticChangeStructureDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getSemanticChangeStructureDataType */
		virtual EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const;
		/*! @overload */
		virtual SemanticChangeStructureDataType getSemanticChangeStructureDataType() const;
		/* see IValue::setSemanticChangeStructureDataType */
		virtual EnumStatusCode setSemanticChangeStructureDataType(const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType);

		/* see IValue::getSemanticChangeStructureDataTypeArray */
		virtual std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>&) const;
		/* see IValue::setSemanticChangeStructureDataTypeArray */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeArray(const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType);

		/* see IValue::getSemanticChangeStructureDataTypeMatrix */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SemanticChangeStructureDataType>& matrixValues) const;
		/* see IValue::setSemanticChangeStructureDataTypeMatrix */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SemanticChangeStructureDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ModelChangeStructureDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getModelChangeStructureDataType */
		virtual EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const;
		/*! @overload */
		virtual ModelChangeStructureDataType getModelChangeStructureDataType() const;
		/* see IValue::setModelChangeStructureDataType */
		virtual EnumStatusCode setModelChangeStructureDataType(const IModelChangeStructureDataType* pModelChangeStructureDataType);

		/* see IValue::getModelChangeStructureDataTypeArray */
		virtual std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>&) const;
		/* see IValue::setModelChangeStructureDataTypeArray */
		virtual EnumStatusCode setModelChangeStructureDataTypeArray(const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType);

		/* see IValue::getModelChangeStructureDataTypeMatrix */
		virtual EnumStatusCode getModelChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ModelChangeStructureDataType>& matrixValues) const;
		/* see IValue::setModelChangeStructureDataTypeMatrix */
		virtual EnumStatusCode setModelChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ModelChangeStructureDataType* matrixValues);
#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for BuildInfo content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getBuildInfo */
		virtual EnumStatusCode getBuildInfo(BuildInfo& target) const;
		/*! @overload */
		virtual BuildInfo getBuildInfo() const;
		/* see IValue::setBuildInfo */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* pBuildInfo);

		/* see IValue::getBuildInfoArray */
		virtual std::vector<BuildInfo> getBuildInfoArray() const;
		/*! @overload */
		virtual EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>&) const;
		/* see IValue::setBuildInfoArray */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<BuildInfo>& arrayBuildInfo);
		/*! @overload */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<const IBuildInfo*>& arrayBuildInfo);

		/* see IValue::getBuildInfoMatrix */
		virtual EnumStatusCode getBuildInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<BuildInfo>& matrixValues) const;
		/* see IValue::setBuildInfoMatrix */
		virtual EnumStatusCode setBuildInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const BuildInfo* matrixValues);

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for EventFilter content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEventFilter */
		virtual EnumStatusCode getEventFilter(EventFilter& target) const;
		/*! @overload */
		virtual EventFilter getEventFilter() const;
		/* see IValue::setEventFilter */
		virtual EnumStatusCode setEventFilter(const IEventFilter* pEventFilter);

		/* see IValue::getEventFilterArray */
		virtual std::vector<EventFilter> getEventFilterArray() const;
		/*! @overload */
		virtual EnumStatusCode getEventFilterArray(std::vector<EventFilter>&) const;
		/* see IValue::setEventFilterArray */
		virtual EnumStatusCode setEventFilterArray(const std::vector<EventFilter>& arrayEventFilter);
		/*! @overload */
		virtual EnumStatusCode setEventFilterArray(const std::vector<const IEventFilter*>& arrayEventFilter);

		/* see IValue::getEventFilterMatrix */
		virtual EnumStatusCode getEventFilterMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EventFilter>& matrixValues) const;
		/* see IValue::setEventFilterMatrix */
		virtual EnumStatusCode setEventFilterMatrix(const std::vector<OTUInt32>& arrayDimensions, const EventFilter* matrixValues);

#endif
		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerStatusDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getServerStatusDataType */
		virtual EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const;
		/*! @overload */
		virtual ServerStatusDataType getServerStatusDataType() const;
		/* see IValue::setServerStatusDataType */
		virtual EnumStatusCode setServerStatusDataType(const IServerStatusDataType* pServerStatusDataType);

		/* see IValue::getServerStatusDataTypeArray */
		virtual std::vector<ServerStatusDataType> getServerStatusDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>&) const;
		/* see IValue::setServerStatusDataTypeArray */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<ServerStatusDataType>& arrayServerStatusDataType);
		/*! @overload */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<const IServerStatusDataType*>& arrayServerStatusDataType);

		/* see IValue::getServerStatusDataTypeMatrix */
		virtual EnumStatusCode getServerStatusDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerStatusDataType>& matrixValues) const;
		/* see IValue::setServerStatusDataTypeMatrix */
		virtual EnumStatusCode setServerStatusDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerStatusDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumValueType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEnumValueType */
		virtual EnumStatusCode getEnumValueType(EnumValueType& target) const;
		/*! @overload */
		virtual EnumValueType getEnumValueType() const;
		/* see IValue::setEnumValueType */
		virtual EnumStatusCode setEnumValueType(const IEnumValueType* pEnumValueType);

		/* see IValue::getEnumValueTypeArray */
		virtual std::vector<EnumValueType> getEnumValueTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>&) const;
		/* see IValue::setEnumValueTypeArray */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<EnumValueType>& arrayEnumValueType);
		/*! @overload */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<const IEnumValueType*>& arrayEnumValueType);

		/* see IValue::getEnumValueTypeMatrix */
		virtual EnumStatusCode getEnumValueTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumValueType>& matrixValues) const;
		/* see IValue::setEnumValueTypeMatrix */
		virtual EnumStatusCode setEnumValueTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumValueType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for KeyValuePair content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getKeyValuePair */
		virtual EnumStatusCode getKeyValuePair(KeyValuePair& target) const;
		/*! @overload */
		virtual KeyValuePair getKeyValuePair() const;
		/* see IValue::setKeyValuePair */
		virtual EnumStatusCode setKeyValuePair(const IKeyValuePair* pKeyValuePair);

		/* see IValue::getKeyValuePairArray */
		virtual std::vector<KeyValuePair> getKeyValuePairArray() const;
		/*! @overload */
		virtual EnumStatusCode getKeyValuePairArray(std::vector<KeyValuePair>&) const;
		/* see IValue::setKeyValuePairArray */
		virtual EnumStatusCode setKeyValuePairArray(const std::vector<KeyValuePair>& arrayKeyValuePair);
		/*! @overload */
		virtual EnumStatusCode setKeyValuePairArray(const std::vector<const IKeyValuePair*>& arrayKeyValuePair);

		/* see IValue::getKeyValuePairMatrix */
		virtual EnumStatusCode getKeyValuePairMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<KeyValuePair>& matrixValues) const;
		/* see IValue::setKeyValuePairMatrix */
		virtual EnumStatusCode setKeyValuePairMatrix(const std::vector<OTUInt32>& arrayDimensions, const KeyValuePair* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ConfigurationVersionDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getConfigurationVersionDataType */
		virtual EnumStatusCode getConfigurationVersionDataType(ConfigurationVersionDataType& target) const;
		/*! @overload */
		virtual ConfigurationVersionDataType getConfigurationVersionDataType() const;
		/* see IValue::setConfigurationVersionDataType */
		virtual EnumStatusCode setConfigurationVersionDataType(const IConfigurationVersionDataType* pConfigurationVersionDataType);

		/* see IValue::getConfigurationVersionDataTypeArray */
		virtual std::vector<ConfigurationVersionDataType> getConfigurationVersionDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getConfigurationVersionDataTypeArray(std::vector<ConfigurationVersionDataType>&) const;
		/* see IValue::setConfigurationVersionDataTypeArray */
		virtual EnumStatusCode setConfigurationVersionDataTypeArray(const std::vector<ConfigurationVersionDataType>& arrayConfigurationVersionDataType);
		/*! @overload */
		virtual EnumStatusCode setConfigurationVersionDataTypeArray(const std::vector<const IConfigurationVersionDataType*>& arrayConfigurationVersionDataType);

		/* see IValue::getConfigurationVersionDataTypeMatrix */
		virtual EnumStatusCode getConfigurationVersionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ConfigurationVersionDataType>& matrixValues) const;
		/* see IValue::setConfigurationVersionDataTypeMatrix */
		virtual EnumStatusCode setConfigurationVersionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ConfigurationVersionDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetMetaDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDataSetMetaDataType */
		virtual EnumStatusCode getDataSetMetaDataType(DataSetMetaDataType& target) const;
		/*! @overload */
		virtual DataSetMetaDataType getDataSetMetaDataType() const;
		/* see IValue::setDataSetMetaDataType */
		virtual EnumStatusCode setDataSetMetaDataType(const IDataSetMetaDataType* pDataSetMetaDataType);

		/* see IValue::getDataSetMetaDataTypeArray */
		virtual std::vector<DataSetMetaDataType> getDataSetMetaDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getDataSetMetaDataTypeArray(std::vector<DataSetMetaDataType>&) const;
		/* see IValue::setDataSetMetaDataTypeArray */
		virtual EnumStatusCode setDataSetMetaDataTypeArray(const std::vector<DataSetMetaDataType>& arrayDataSetMetaDataType);
		/*! @overload */
		virtual EnumStatusCode setDataSetMetaDataTypeArray(const std::vector<const IDataSetMetaDataType*>& arrayDataSetMetaDataType);

		/* see IValue::getDataSetMetaDataTypeMatrix */
		virtual EnumStatusCode getDataSetMetaDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetMetaDataType>& matrixValues) const;
		/* see IValue::setDataSetMetaDataTypeMatrix */
		virtual EnumStatusCode setDataSetMetaDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetMetaDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetReaderDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDataSetReaderDataType */
		virtual EnumStatusCode getDataSetReaderDataType(DataSetReaderDataType& target) const;
		/*! @overload */
		virtual DataSetReaderDataType getDataSetReaderDataType() const;
		/* see IValue::setDataSetReaderDataType */
		virtual EnumStatusCode setDataSetReaderDataType(const IDataSetReaderDataType* pDataSetReaderDataType);

		/* see IValue::getDataSetReaderDataTypeArray */
		virtual std::vector<DataSetReaderDataType> getDataSetReaderDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getDataSetReaderDataTypeArray(std::vector<DataSetReaderDataType>&) const;
		/* see IValue::setDataSetReaderDataTypeArray */
		virtual EnumStatusCode setDataSetReaderDataTypeArray(const std::vector<DataSetReaderDataType>& arrayDataSetReaderDataType);
		/*! @overload */
		virtual EnumStatusCode setDataSetReaderDataTypeArray(const std::vector<const IDataSetReaderDataType*>& arrayDataSetReaderDataType);

		/* see IValue::getDataSetReaderDataTypeMatrix */
		virtual EnumStatusCode getDataSetReaderDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetReaderDataType>& matrixValues) const;
		/* see IValue::setDataSetReaderDataTypeMatrix */
		virtual EnumStatusCode setDataSetReaderDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetReaderDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetWriterDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getDataSetWriterDataType */
		virtual EnumStatusCode getDataSetWriterDataType(DataSetWriterDataType& target) const;
		/*! @overload */
		virtual DataSetWriterDataType getDataSetWriterDataType() const;
		/* see IValue::setDataSetWriterDataType */
		virtual EnumStatusCode setDataSetWriterDataType(const IDataSetWriterDataType* pDataSetWriterDataType);

		/* see IValue::getDataSetWriterDataTypeArray */
		virtual std::vector<DataSetWriterDataType> getDataSetWriterDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getDataSetWriterDataTypeArray(std::vector<DataSetWriterDataType>&) const;
		/* see IValue::setDataSetWriterDataTypeArray */
		virtual EnumStatusCode setDataSetWriterDataTypeArray(const std::vector<DataSetWriterDataType>& arrayDataSetWriterDataType);
		/*! @overload */
		virtual EnumStatusCode setDataSetWriterDataTypeArray(const std::vector<const IDataSetWriterDataType*>& arrayDataSetWriterDataType);

		/* see IValue::getDataSetWriterDataTypeMatrix */
		virtual EnumStatusCode getDataSetWriterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetWriterDataType>& matrixValues) const;
		/* see IValue::setDataSetWriterDataTypeMatrix */
		virtual EnumStatusCode setDataSetWriterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetWriterDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumDefinition content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEnumDefinition */
		virtual EnumStatusCode getEnumDefinition(EnumDefinition& target) const;
		/*! @overload */
		virtual EnumDefinition getEnumDefinition() const;
		/* see IValue::setEnumDefinition */
		virtual EnumStatusCode setEnumDefinition(const IEnumDefinition* pEnumDefinition);

		/* see IValue::getEnumDefinitionArray */
		virtual std::vector<EnumDefinition> getEnumDefinitionArray() const;
		/*! @overload */
		virtual EnumStatusCode getEnumDefinitionArray(std::vector<EnumDefinition>&) const;
		/* see IValue::setEnumDefinitionArray */
		virtual EnumStatusCode setEnumDefinitionArray(const std::vector<EnumDefinition>& arrayEnumDefinition);
		/*! @overload */
		virtual EnumStatusCode setEnumDefinitionArray(const std::vector<const IEnumDefinition*>& arrayEnumDefinition);

		/* see IValue::getEnumDefinitionMatrix */
		virtual EnumStatusCode getEnumDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumDefinition>& matrixValues) const;
		/* see IValue::setEnumDefinitionMatrix */
		virtual EnumStatusCode setEnumDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumDefinition* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for FieldTargetDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getFieldTargetDataType */
		virtual EnumStatusCode getFieldTargetDataType(FieldTargetDataType& target) const;
		/*! @overload */
		virtual FieldTargetDataType getFieldTargetDataType() const;
		/* see IValue::setFieldTargetDataType */
		virtual EnumStatusCode setFieldTargetDataType(const IFieldTargetDataType* pFieldTargetDataType);

		/* see IValue::getFieldTargetDataTypeArray */
		virtual std::vector<FieldTargetDataType> getFieldTargetDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getFieldTargetDataTypeArray(std::vector<FieldTargetDataType>&) const;
		/* see IValue::setFieldTargetDataTypeArray */
		virtual EnumStatusCode setFieldTargetDataTypeArray(const std::vector<FieldTargetDataType>& arrayFieldTargetDataType);
		/*! @overload */
		virtual EnumStatusCode setFieldTargetDataTypeArray(const std::vector<const IFieldTargetDataType*>& arrayFieldTargetDataType);

		/* see IValue::getFieldTargetDataTypeMatrix */
		virtual EnumStatusCode getFieldTargetDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<FieldTargetDataType>& matrixValues) const;
		/* see IValue::setFieldTargetDataTypeMatrix */
		virtual EnumStatusCode setFieldTargetDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const FieldTargetDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for PubSubConnectionDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getPubSubConnectionDataType */
		virtual EnumStatusCode getPubSubConnectionDataType(PubSubConnectionDataType& target) const;
		/*! @overload */
		virtual PubSubConnectionDataType getPubSubConnectionDataType() const;
		/* see IValue::setPubSubConnectionDataType */
		virtual EnumStatusCode setPubSubConnectionDataType(const IPubSubConnectionDataType* pPubSubConnectionDataType);

		/* see IValue::getPubSubConnectionDataTypeArray */
		virtual std::vector<PubSubConnectionDataType> getPubSubConnectionDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getPubSubConnectionDataTypeArray(std::vector<PubSubConnectionDataType>&) const;
		/* see IValue::setPubSubConnectionDataTypeArray */
		virtual EnumStatusCode setPubSubConnectionDataTypeArray(const std::vector<PubSubConnectionDataType>& arrayPubSubConnectionDataType);
		/*! @overload */
		virtual EnumStatusCode setPubSubConnectionDataTypeArray(const std::vector<const IPubSubConnectionDataType*>& arrayPubSubConnectionDataType);

		/* see IValue::getPubSubConnectionDataTypeMatrix */
		virtual EnumStatusCode getPubSubConnectionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PubSubConnectionDataType>& matrixValues) const;
		/* see IValue::setPubSubConnectionDataTypeMatrix */
		virtual EnumStatusCode setPubSubConnectionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PubSubConnectionDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReaderGroupDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getReaderGroupDataType */
		virtual EnumStatusCode getReaderGroupDataType(ReaderGroupDataType& target) const;
		/*! @overload */
		virtual ReaderGroupDataType getReaderGroupDataType() const;
		/* see IValue::setReaderGroupDataType */
		virtual EnumStatusCode setReaderGroupDataType(const IReaderGroupDataType* pReaderGroupDataType);

		/* see IValue::getReaderGroupDataTypeArray */
		virtual std::vector<ReaderGroupDataType> getReaderGroupDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getReaderGroupDataTypeArray(std::vector<ReaderGroupDataType>&) const;
		/* see IValue::setReaderGroupDataTypeArray */
		virtual EnumStatusCode setReaderGroupDataTypeArray(const std::vector<ReaderGroupDataType>& arrayReaderGroupDataType);
		/*! @overload */
		virtual EnumStatusCode setReaderGroupDataTypeArray(const std::vector<const IReaderGroupDataType*>& arrayReaderGroupDataType);

		/* see IValue::getReaderGroupDataTypeMatrix */
		virtual EnumStatusCode getReaderGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReaderGroupDataType>& matrixValues) const;
		/* see IValue::setReaderGroupDataTypeMatrix */
		virtual EnumStatusCode setReaderGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReaderGroupDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for RolePermissionType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getRolePermissionType */
		virtual EnumStatusCode getRolePermissionType(RolePermissionType& target) const;
		/*! @overload */
		virtual RolePermissionType getRolePermissionType() const;
		/* see IValue::setRolePermissionType */
		virtual EnumStatusCode setRolePermissionType(const IRolePermissionType* pRolePermissionType);

		/* see IValue::getRolePermissionTypeArray */
		virtual std::vector<RolePermissionType> getRolePermissionTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getRolePermissionTypeArray(std::vector<RolePermissionType>&) const;
		/* see IValue::setRolePermissionTypeArray */
		virtual EnumStatusCode setRolePermissionTypeArray(const std::vector<RolePermissionType>& arrayRolePermissionType);
		/*! @overload */
		virtual EnumStatusCode setRolePermissionTypeArray(const std::vector<const IRolePermissionType*>& arrayRolePermissionType);

		/* see IValue::getRolePermissionTypeMatrix */
		virtual EnumStatusCode getRolePermissionTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<RolePermissionType>& matrixValues) const;
		/* see IValue::setRolePermissionTypeMatrix */
		virtual EnumStatusCode setRolePermissionTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const RolePermissionType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for StructureDefinition content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getStructureDefinition */
		virtual EnumStatusCode getStructureDefinition(StructureDefinition& target) const;
		/*! @overload */
		virtual StructureDefinition getStructureDefinition() const;
		/* see IValue::setStructureDefinition */
		virtual EnumStatusCode setStructureDefinition(const IStructureDefinition* pStructureDefinition);

		/* see IValue::getStructureDefinitionArray */
		virtual std::vector<StructureDefinition> getStructureDefinitionArray() const;
		/*! @overload */
		virtual EnumStatusCode getStructureDefinitionArray(std::vector<StructureDefinition>&) const;
		/* see IValue::setStructureDefinitionArray */
		virtual EnumStatusCode setStructureDefinitionArray(const std::vector<StructureDefinition>& arrayStructureDefinition);
		/*! @overload */
		virtual EnumStatusCode setStructureDefinitionArray(const std::vector<const IStructureDefinition*>& arrayStructureDefinition);

		/* see IValue::getStructureDefinitionMatrix */
		virtual EnumStatusCode getStructureDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<StructureDefinition>& matrixValues) const;
		/* see IValue::setStructureDefinitionMatrix */
		virtual EnumStatusCode setStructureDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const StructureDefinition* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for WriterGroupDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getWriterGroupDataType */
		virtual EnumStatusCode getWriterGroupDataType(WriterGroupDataType& target) const;
		/*! @overload */
		virtual WriterGroupDataType getWriterGroupDataType() const;
		/* see IValue::setWriterGroupDataType */
		virtual EnumStatusCode setWriterGroupDataType(const IWriterGroupDataType* pWriterGroupDataType);

		/* see IValue::getWriterGroupDataTypeArray */
		virtual std::vector<WriterGroupDataType> getWriterGroupDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getWriterGroupDataTypeArray(std::vector<WriterGroupDataType>&) const;
		/* see IValue::setWriterGroupDataTypeArray */
		virtual EnumStatusCode setWriterGroupDataTypeArray(const std::vector<WriterGroupDataType>& arrayWriterGroupDataType);
		/*! @overload */
		virtual EnumStatusCode setWriterGroupDataTypeArray(const std::vector<const IWriterGroupDataType*>& arrayWriterGroupDataType);

		/* see IValue::getWriterGroupDataTypeMatrix */
		virtual EnumStatusCode getWriterGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<WriterGroupDataType>& matrixValues) const;
		/* see IValue::setWriterGroupDataTypeMatrix */
		virtual EnumStatusCode setWriterGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const WriterGroupDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for PublishedVariableDataType content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getPublishedVariableDataType */
		virtual EnumStatusCode getPublishedVariableDataType(PublishedVariableDataType& target) const;
		/*! @overload */
		virtual PublishedVariableDataType getPublishedVariableDataType() const;
		/* see IValue::setPublishedVariableDataType */
		virtual EnumStatusCode setPublishedVariableDataType(const IPublishedVariableDataType* pPublishedVariableDataType);

		/* see IValue::getPublishedVariableDataTypeArray */
		virtual std::vector<PublishedVariableDataType> getPublishedVariableDataTypeArray() const;
		/*! @overload */
		virtual EnumStatusCode getPublishedVariableDataTypeArray(std::vector<PublishedVariableDataType>&) const;
		/* see IValue::setPublishedVariableDataTypeArray */
		virtual EnumStatusCode setPublishedVariableDataTypeArray(const std::vector<PublishedVariableDataType>& arrayPublishedVariableDataType);
		/*! @overload */
		virtual EnumStatusCode setPublishedVariableDataTypeArray(const std::vector<const IPublishedVariableDataType*>& arrayPublishedVariableDataType);

		/* see IValue::getPublishedVariableDataTypeMatrix */
		virtual EnumStatusCode getPublishedVariableDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PublishedVariableDataType>& matrixValues) const;
		/* see IValue::setPublishedVariableDataTypeMatrix */
		virtual EnumStatusCode setPublishedVariableDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PublishedVariableDataType* matrixValues);

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EndpointDescription content
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getEndpointDescription */
		virtual EnumStatusCode getEndpointDescription(EndpointDescription& target) const;
		/*! @overload */
		virtual EndpointDescription getEndpointDescription() const;
		/* see IValue::setEndpointDescription */
		virtual EnumStatusCode setEndpointDescription(const IEndpointDescription* pEndpointDescription);

		/* see IValue::getEndpointDescriptionArray */
		virtual std::vector<EndpointDescription> getEndpointDescriptionArray() const;
		/*! @overload */
		virtual EnumStatusCode getEndpointDescriptionArray(std::vector<EndpointDescription>&) const;
		/* see IValue::setEndpointDescriptionArray */
		virtual EnumStatusCode setEndpointDescriptionArray(const std::vector<EndpointDescription>& arrayEndpointDescription);
		/*! @overload */
		virtual EnumStatusCode setEndpointDescriptionArray(const std::vector<const IEndpointDescription*>& arrayEndpointDescription);

		/* see IValue::getEndpointDescriptionMatrix */
		virtual EnumStatusCode getEndpointDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EndpointDescription>& matrixValues) const;
		/* see IValue::setEndpointDescriptionMatrix */
		virtual EnumStatusCode setEndpointDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EndpointDescription* matrixValues);

		// NEW_SUPPORTED_DATATYPE - copy the block above and replace tape name

		////////////////////////////////////////////////////////////////////////////////
		// Value access for structured data types
		////////////////////////////////////////////////////////////////////////////////

		/* see IValue::getStructuredValue */
		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<Value>& fieldValues) const;
		/* see IValue::setStructuredValue */
		virtual EnumStatusCode setStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues);
		/* see IValue::setStructuredValue */
		DEPRECATED(virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues));

		/* see IValue::setStructuredValue */
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<std::vector<Value> >& fieldValues) const;
		/* see IValue::setStructuredValueArray */
		virtual EnumStatusCode setStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<std::vector<Value> >& fieldValues);
		/* see IValue::setStructuredValueArray */
		DEPRECATED(virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues));

		/* see IValue::getStructuredValueMatrix */
		virtual EnumStatusCode getStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<OTUInt32>& arrayDimensions, std::vector<std::vector<Value> >& fieldValues) const;
		/* see IValue::setStructuredValueMatrix */
		virtual EnumStatusCode setStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues);
		/* see IValue::setStructuredValueMatrix */
		DEPRECATED(virtual EnumStatusCode setStructuredValueMatrix(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues));

		/* see IValue::getComplexValueRaw */
		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const;
		/* see IValue::setComplexValueRaw */
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body);

		/* see IValue::getComplexValueRawArray */
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const;
		/* see IValue::setComplexValueRawArray */
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies);

		/* see IValue::getComplexValueRawMatrix */
		virtual EnumStatusCode getComplexValueRawMatrix(NodeId& encodingId, std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& bodies) const;
		/* see IValue::setComplexValueRawMatrix */
		virtual EnumStatusCode setComplexValueRawMatrix(const INodeId& encodingId, const std::vector<OTUInt32>& arrayDimensions, const std::vector<ByteString>& bodies);

		/* see IValue::clear */
		virtual void clear();

		/* see IValue::getInternHandle */
		void* getInternHandle() const;

	private:
		ValueStruct m_content;
	};
} // end namespace

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif

#endif	// VALUE_H
