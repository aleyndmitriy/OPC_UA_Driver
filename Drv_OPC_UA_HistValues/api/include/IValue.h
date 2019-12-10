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

#ifndef IVALUE_H
#define IVALUE_H

#include "Base.h"

namespace SoftingOPCToolbox5
{
	// Forward declarations
	class INodeId;
	class IDateTime;
	class IGuid;
	class IExpandedNodeId;
	class ILocalizedText;
	class IQualifiedName;
	class IDataValue;
	class NodeId;
	class ExpandedNodeId;
	class QualifiedName;
	class DateTime;
	class Guid;
	class LocalizedText;
	class DataValue;
	class EUInformation;
	class IEUInformation;
	class TimeZone;
	class ITimeZone;
	class Range;
	class IRange;
	class Argument;
	class Value;
	class IDiagnosticInfo;
	class DiagnosticInfo;
	class IArgument;
	class INumericRange;
	class ReferenceDescription;
	class IReferenceDescription;
	class ApplicationDescription;
	class IApplicationDescription;
	class ServerDiagnosticsSummaryDataType;
	class IServerDiagnosticsSummaryDataType;
	class SubscriptionDiagnosticsDataType;
	class ISubscriptionDiagnosticsDataType;
	class SessionDiagnosticsDataType;
	class ISessionDiagnosticsDataType;
	class SessionSecurityDiagnosticsDataType;
	class ISessionSecurityDiagnosticsDataType;
	class ServiceCounterDataType;
	class IServiceCounterDataType;
	class SemanticChangeStructureDataType;
	class ISemanticChangeStructureDataType;
	class ModelChangeStructureDataType;
	class IModelChangeStructureDataType;
	class UserIdentityToken;
	class IUserIdentityToken;
	class AnonymousIdentityToken;
	class IAnonymousIdentityToken;
	class UserNameIdentityToken;
	class IUserNameIdentityToken;
	class X509IdentityToken;
	class IX509IdentityToken;
	class IssuedIdentityToken;
	class IIssuedIdentityToken;
	class SignedSoftwareCertificate;
	class ISignedSoftwareCertificate;
	class BuildInfo;
	class IBuildInfo;
	class EventFilter;
	class IEventFilter;
	class ServerStatusDataType;
	class IServerStatusDataType;
	class EnumValueType;
	class IEnumValueType;
	class KeyValuePair;
	class IKeyValuePair;
	class ConfigurationVersionDataType;
	class IConfigurationVersionDataType;
	class DataSetMetaDataType;
	class IDataSetMetaDataType;
	class DataSetReaderDataType;
	class IDataSetReaderDataType;
	class DataSetWriterDataType;
	class IDataSetWriterDataType;
	class EnumDefinition;
	class IEnumDefinition;
	class FieldTargetDataType;
	class IFieldTargetDataType;
	class PubSubConnectionDataType;
	class IPubSubConnectionDataType;
	class ReaderGroupDataType;
	class IReaderGroupDataType;
	class RolePermissionType;
	class IRolePermissionType;
	class StructureDefinition;
	class IStructureDefinition;
	class WriterGroupDataType;
	class IWriterGroupDataType;
	class PublishedVariableDataType;
	class IPublishedVariableDataType;
	class EndpointDescription;
	class IEndpointDescription;
	// NEW_SUPPORTED_DATATYPE - forward declarations (class AND interface)
	class StructuredDataTypeDescription;
	typedef ObjectPointer<const StructuredDataTypeDescription> StructuredDataTypeDescriptionConstPtr;
	class EnumerationDataTypeDescription;
	typedef ObjectPointer<const EnumerationDataTypeDescription> EnumerationDataTypeDescriptionConstPtr;

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
	class TBC_EXPORT IValue
	{
	public:
		/*! Destructor */
		virtual ~IValue() {};

		/*! Returns the data type of the value contained in the variant. */
		virtual EnumDataTypeId getDataType() const = 0;

		/*! Returns the array type of the value contained in the variant.
		*
		* The variant may use one of the following array types:
		* @li EnumValueArrayType_Scalar:	A single value of the specified data type
		* @li EnumValueArrayType_Array:		An array of values of the specified data type
		* @li EnumValueArrayType_Matrix:	A matrix of values of the specified data type */
		virtual EnumValueArrayType getArrayType() const = 0;

		/*! Returns a subset of an array, a matrix, a ByteString, or a string value.
		*
		* @param[out]	result		The extracted subset of the array, matrix, ByteString, or string value
		* @param[in]	indexRange	The range that defines the subset to extract */
		virtual EnumStatusCode getSubset(IValue& result, const INumericRange* indexRange) const = 0;
		/*! Replaces a subset of an array, a matrix, a ByteString, or a string value.
		*
		* @param value		The array, matrix, ByteString or string value that shall replace a
		*					certain range of the value stored in the variant
		* @param indexRange	The range that defines the subset of the variant to replace */
		virtual EnumStatusCode setSubset(const IValue& value, const INumericRange* indexRange) = 0;

		/*! Returns whether and how the value in the variant can be converted to another data type.
		*
		* If this method returns EnumValueCastType_NotDefined, then no conversion between the source
		* and the target data type exists. Any other result defines whether explicit (EnumValueCastType_Explicit)
		* or implicit (EnumValueCastType_Implicit) conversion is required or if no conversion is required at all
		* (EnumValueCastType_Identity).
		*
		* @param dataType	The target data type to which the variant's value is to be converted. */
		virtual EnumValueCastType canCastTo(EnumDataTypeId dataType) const = 0;
		/*! Converts the value to the provided data type if such conversion exists.
		*
		* The method IValue::canCastTo() can be used to determine if a conversion between the
		* variant's source data type and the provided target data type exists.
		*
		* @param dataType		The target data type to which the variant's value is to be converted.
		* @param castedValue	The variant containing the casted value. */
		virtual EnumStatusCode castTo(EnumDataTypeId dataType, IValue& castedValue) const = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Boolean content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. If DataType does not match OTBoolean or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getBoolean(OTBoolean* target) const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTBoolean getBoolean() const = 0;
		/*! Sets the value to a scalar of type OTBoolean. */
		virtual void setBoolean(OTBoolean value) = 0;

		/*! Returns the content of the Value. If DataType does not match OTBoolean or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getBooleanArray(std::vector<OTBoolean>& target) const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTBoolean> getBooleanArray() const = 0;
		/*! Sets the value to an array of type OTBoolean. */
		virtual EnumStatusCode setBooleanArray(const std::vector<OTBoolean>& arrayBool) = 0;

		/*! Returns the content of the Value. If DataType does not match OTBoolean or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getBooleanMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTBoolean>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTBoolean.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setBooleanMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTBoolean* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt8 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt8 getUInt8() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt8 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt8(OTUInt8* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt8. */
		virtual void setUInt8(OTUInt8 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt8> getUInt8Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt8 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt8Array(std::vector<OTUInt8>& target) const = 0;
		/*! Sets the value to an array of type OTUInt8. */
		virtual EnumStatusCode setUInt8Array(const std::vector<OTUInt8>& arrayUInt8) = 0;

		/*! Returns the content of the Value. If DataType does not match OTUInt8 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getUInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt8>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTUInt8.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setUInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt8* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int8 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt8 getInt8() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt8 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt8(OTInt8* target) const = 0;
		/*! Sets the value to a scalar of type OTInt8. */
		virtual void setInt8(OTInt8 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt8> getInt8Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt8 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt8Array(std::vector<OTInt8>& target) const = 0;
		/*! Sets the value to an array of type OTInt8. */
		virtual EnumStatusCode setInt8Array(const std::vector<OTInt8>& arrayInt8) = 0;

		/*! Returns the content of the Value. If DataType does not match OTInt8 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getInt8Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt8>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTInt8.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setInt8Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt8* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt16 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt16 getUInt16() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt16 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt16(OTUInt16* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt16. */
		virtual void setUInt16(OTUInt16 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt16> getUInt16Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt16 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt16Array(std::vector<OTUInt16>& target) const = 0;
		/*! Sets the value to an array of type OTUInt16. */
		virtual EnumStatusCode setUInt16Array(const std::vector<OTUInt16>& arrayUInt16) = 0;

		/*! Returns the content of the Value. If DataType does not match OTUInt16 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getUInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt16>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTUInt16.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setUInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt16* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int16 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt16 getInt16() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt16 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt16(OTInt16* target) const = 0;
		/*! Sets the value to a scalar of type OTInt16. */
		virtual void setInt16(OTInt16 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt16> getInt16Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt16 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt16Array(std::vector<OTInt16>& target) const = 0;
		/*! Sets the value to an array of type OTInt16. */
		virtual EnumStatusCode setInt16Array(const std::vector<OTInt16>& arrayInt16) = 0;

		/*! Returns the content of the Value. If DataType does not match OTInt16 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getInt16Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt16>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTInt16.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setInt16Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt16* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt32 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt32 getUInt32() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt32(OTUInt32* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt32. */
		virtual void setUInt32(OTUInt32 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt32> getUInt32Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt32Array(std::vector<OTUInt32>& target) const = 0;
		/*! Sets the value to an array of type OTUInt32. */
		virtual EnumStatusCode setUInt32Array(const std::vector<OTUInt32>& arrayUInt32) = 0;

		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getUInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt32>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTUInt32.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setUInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt32* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int32 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt32 getInt32() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt32(OTInt32* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt32. */
		virtual void setInt32(OTInt32 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt32> getInt32Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt32 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt32Array(std::vector<OTInt32>& target) const = 0;
		/*! Sets the value to an array of type OTUInt32. */
		virtual EnumStatusCode setInt32Array(const std::vector<OTInt32>& arrayInt32) = 0;

		/*! Returns the content of the Value. If DataType does not match OTInt32 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getInt32Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt32>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTInt32.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setInt32Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt32* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UInt64 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTUInt64 getUInt64() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt64 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getUInt64(OTUInt64* target) const = 0;
		/*! Sets the value to a scalar of type OTUInt64. */
		virtual void setUInt64(OTUInt64 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTInt64> getInt64Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTUInt64 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getInt64Array(std::vector<OTInt64>& target) const = 0;
		/*! Sets the value to an array of type OTUInt64. */
		virtual EnumStatusCode setUInt64Array(const std::vector<OTUInt64>& arrayUInt64) = 0;

		/*! Returns the content of the Value. If DataType does not match OTUInt64 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getUInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTUInt64>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTUInt64.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setUInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTUInt64* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Int64 content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTInt64 getInt64() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt64 or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getInt64(OTInt64* target) const = 0;
		/*! Sets the value to a scalar of type OTInt64. */
		virtual void setInt64(OTInt64 value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTUInt64> getUInt64Array() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTInt64 or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getUInt64Array(std::vector<OTUInt64>& target) const = 0;
		/*! Sets the value to an array of type OTInt64. */
		virtual EnumStatusCode setInt64Array(const std::vector<OTInt64>& arrayInt64) = 0;

		/*! Returns the content of the Value. If DataType does not match OTInt64 or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getInt64Matrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTInt64>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTInt64.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setInt64Matrix(const std::vector<OTUInt32>& arrayDimensions, const OTInt64* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Float content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTFloat getFloat() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTFloat or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getFloat(OTFloat* target) const = 0;
		/*! Sets the value to a scalar of type OTFloat. */
		virtual void setFloat(OTFloat value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTFloat> getFloatArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTFloat or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getFloatArray(std::vector<OTFloat>& target) const = 0;
		/*! Sets the value to an array of type OTFloat. */
		virtual EnumStatusCode setFloatArray(const std::vector<OTFloat>& arrayFloat) = 0;

		/*! Returns the content of the Value. If DataType does not match OTFloat or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getFloatMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTFloat>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTFloat.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setFloatMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTFloat* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Double content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual OTDouble getDouble() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTDouble or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDouble(OTDouble* target) const = 0;
		/*! Sets the value to a scalar of type OTDouble. */
		virtual void setDouble(OTDouble value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<OTDouble> getDoubleArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match OTDouble or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDoubleArray(std::vector<OTDouble>& target) const = 0;
		/*! Sets the value to an array of type OTDouble. */
		virtual EnumStatusCode setDoubleArray(const std::vector<OTDouble>& arrayDouble) = 0;

		/*! Returns the content of the Value. If DataType does not match OTDouble or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDoubleMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<OTDouble>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type OTDouble.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDoubleMatrix(const std::vector<OTUInt32>& arrayDimensions, const OTDouble* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DateTime content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DateTime getDateTime() const = 0;
		/*! Returns the content of the Value. If DataType does not match DateTime or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDateTime(DateTime& target) const = 0;
		/*! Sets the value to a scalar of type DateTime. */
		virtual EnumStatusCode setDateTime(const IDateTime* pDateTime) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DateTime> getDateTimeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DateTime or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDateTimeArray(std::vector<DateTime>& target) const = 0;
		/*! Sets the value to an array of type DateTime. */
		virtual EnumStatusCode setDateTimeArray(const std::vector<DateTime>& arrayDateTime) = 0;

		/*! Returns the content of the Value. If DataType does not match DateTime or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDateTimeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DateTime>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DateTime.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDateTimeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DateTime* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for String content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual tstring getString() const = 0;
		/*! Returns the content of the Value. If DataType does not match tstring or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getString(tstring& target) const = 0;
		/*! Sets the value to a scalar of type tstring. */
		virtual EnumStatusCode setString(const tstring& value) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<tstring> getStringArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match tstring or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getStringArray(std::vector<tstring>& target) const = 0;
		/*! Sets the value to an array of type tstring. */
		virtual EnumStatusCode setStringArray(const std::vector<tstring>& arrayString) = 0;

		/*! Returns the content of the Value. If DataType does not match tstring or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<tstring>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type tstring.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const tstring* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Guid content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Guid getGuid() const = 0;
		/*! Returns the content of the Value. If DataType does not match Guid or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getGuid(Guid& target) const = 0;
		/*! Sets the value to a scalar of type Guid. */
		virtual EnumStatusCode setGuid(const IGuid* pGuid) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Guid> getGuidArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Guid or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getGuidArray(std::vector<Guid>& target) const = 0;
		/*! Sets the value to an array of type Guid. */
		virtual EnumStatusCode setGuidArray(const std::vector<Guid>& arrayGuid) = 0;

		/*! Returns the content of the Value. If DataType does not match Guid or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getGuidMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Guid>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type Guid.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setGuidMatrix(const std::vector<OTUInt32>& arrayDimensions, const Guid* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for NodeId content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual NodeId getNodeId() const = 0;
		/*! Returns the content of the Value. If DataType does not match NodeId or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getNodeId(NodeId& target) const = 0;
		/*! Sets the value to a scalar of type NodeId. */
		virtual EnumStatusCode setNodeId(const INodeId* pNodeId) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<NodeId> getNodeIdArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match NodeId or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getNodeIdArray(std::vector<NodeId>& target) const = 0;
		/*! Sets the value to an array of type NodeId. */
		virtual EnumStatusCode setNodeIdArray(const std::vector<NodeId>& arrayNodeId) = 0;

		/*! Returns the content of the Value. If DataType does not match NodeId or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<NodeId>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type NodeId.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const NodeId* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ExpandedNodeId content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ExpandedNodeId getExpandedNodeId() const = 0;
		/*! Returns the content of the Value. If DataType does not match ExpandedNodeId or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getExpandedNodeId(ExpandedNodeId& target) const = 0;
		/*! Sets the value to a scalar of type ExpandedNodeId. */
		virtual EnumStatusCode setExpandedNodeId(const IExpandedNodeId* pNodeId) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ExpandedNodeId> getExpandedNodeIdArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ExpandedNodeId or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getExpandedNodeIdArray(std::vector<ExpandedNodeId>& target) const = 0;
		/*! Sets the value to an array of type ExpandedNodeId. */
		virtual EnumStatusCode setExpandedNodeIdArray(const std::vector<ExpandedNodeId>& arrayExpandedNodeId) = 0;

		/*! Returns the content of the Value. If DataType does not match ExpandedNodeId or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getExpandedNodeIdMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ExpandedNodeId>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ExpandedNodeId.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setExpandedNodeIdMatrix(const std::vector<OTUInt32>& arrayDimensions, const ExpandedNodeId* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for StatusCode content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. If DataType does not match EnumStatusCode or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getStatusCode() const = 0;
		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EnumStatusCode getStatusCode(EnumStatusCode* target) const = 0;
		/*! Sets the value to a scalar of type EnumStatusCode. */
		virtual void setStatusCode(EnumStatusCode statusCode) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EnumStatusCode> getStatusCodeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumStatusCode or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getStatusCodeArray(std::vector<EnumStatusCode>& target) const = 0;
		/*! Sets the value to an array of type EnumStatusCode. */
		virtual EnumStatusCode setStatusCodeArray(const std::vector<EnumStatusCode>& arrayStatusCode) = 0;

		/*! Returns the content of the Value. If DataType does not match EnumStatusCode or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getStatusCodeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumStatusCode>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EnumStatusCode.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setStatusCodeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumStatusCode* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for QualifiedName content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual QualifiedName getQualifiedName() const = 0;
		/*! Returns the content of the Value. If DataType does not match QualifiedName or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getQualifiedName(QualifiedName& target) const = 0;
		/*! Sets the value to a scalar of type QualifiedName. */
		virtual EnumStatusCode setQualifiedName(const IQualifiedName*  pQualifiedName) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<QualifiedName> getQualifiedNameArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match QualifiedName or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getQualifiedNameArray(std::vector<QualifiedName>& target) const = 0;
		/*! Sets the value to an array of type QualifiedName. */
		virtual EnumStatusCode setQualifiedNameArray(const std::vector<QualifiedName>& arrayQualifiedName) = 0;

		/*! Returns the content of the Value. If DataType does not match QualifiedName or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getQualifiedNameMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<QualifiedName>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type QualifiedName.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setQualifiedNameMatrix(const std::vector<OTUInt32>& arrayDimensions, const QualifiedName* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DiagnosticInfo content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match.
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual DiagnosticInfo getDiagnosticInfo() const = 0;
		/*! Returns the content of the Value. If DataType does not match DiagnosticInfo or ArrayType is not EnumValueArrayType_Scalar an error is returned.
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode getDiagnosticInfo(DiagnosticInfo& target) const = 0;
		/*! Sets the value to a scalar of type DiagnosticInfo
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode setDiagnosticInfo(const IDiagnosticInfo* pInfo) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match.
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual std::vector<DiagnosticInfo> getDiagnosticInfoArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DiagnosticInfo or ArrayType is not EnumValueArrayType_Array an error is returned.
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode getDiagnosticInfoArray(std::vector<DiagnosticInfo>& target) const = 0;
		/*! Sets the value to an array of type DiagnosticInfo.
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode setDiagnosticInfoArray(const std::vector<DiagnosticInfo>& arrayDiagnosticInfo) = 0;

		/*! Returns the content of the Value. If DataType does not match DiagnosticInfo or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a>
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode getDiagnosticInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DiagnosticInfo>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DiagnosticInfo.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a>
		*
		* @note A DiagnosticInfo within a value s only allowed for structured data types to represent an elements value.
		* @note This data type is not allowed as a data type of a node. */
		virtual EnumStatusCode setDiagnosticInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const DiagnosticInfo* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EUInformation content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EUInformation getEUInformation() const = 0;
		/*! Returns the content of the Value. If DataType does not match EUInformation or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEUInformation(EUInformation& target) const = 0;
		/*! Sets the value to a scalar of type EUInformation. */
		virtual EnumStatusCode setEUInformation(const IEUInformation*  pEUInformation) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EUInformation> getEUInformationArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EUInformation or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEUInformationArray(std::vector<EUInformation>& target) const = 0;
		/*! Sets the value to an array of type EUInformation. */
		virtual EnumStatusCode setEUInformationArray(const std::vector<EUInformation>& arrayEUInformation) = 0;

		/*! Returns the content of the Value. If DataType does not match EUInformation or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getEUInformationMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EUInformation>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EUInformation.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setEUInformationMatrix(const std::vector<OTUInt32>& arrayDimensions, const EUInformation* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for LocalizedText content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual LocalizedText getLocalizedText() const = 0;
		/*! Returns the content of the Value. If DataType does not match LocalizedText or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getLocalizedText(LocalizedText& target) const = 0;
		/*! Sets the value to a scalar of type LocalizedText. */
		virtual EnumStatusCode setLocalizedText(const ILocalizedText* pLocalizedText) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<LocalizedText> getLocalizedTextArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match LocalizedText or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getLocalizedTextArray(std::vector<LocalizedText>& target) const = 0;
		/*! Sets the value to an array of type LocalizedText. */
		virtual EnumStatusCode setLocalizedTextArray(const std::vector<LocalizedText>& arrayLocalizedText) = 0;

		/*! Returns the content of the Value. If DataType does not match LocalizedText or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getLocalizedTextMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<LocalizedText>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type LocalizedText.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setLocalizedTextMatrix(const std::vector<OTUInt32>& arrayDimensions, const LocalizedText* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ByteString content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ByteString getByteString() const = 0;
		/*! Returns the content of the Value. If DataType does not match ByteString or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getByteString(ByteString& target) const = 0;
		/*! Sets the value to a scalar of type ByteString. */
		virtual EnumStatusCode setByteString(const ByteString& pByteString) = 0;
		/*! @overload */
		virtual EnumStatusCode setByteString(const unsigned char* pData, unsigned length) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ByteString> getByteStringArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ByteString or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getByteStringArray(std::vector<ByteString>& target) const = 0;
		/*! Sets the value to an array of type ByteString. */
		virtual EnumStatusCode setByteStringArray(const std::vector<ByteString>& arrayByteString) = 0;

		/*! Returns the content of the Value. If DataType does not match ByteString or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getByteStringMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ByteString.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setByteStringMatrix(const std::vector<OTUInt32>& arrayDimensions, const ByteString* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for XmlElement content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual XmlElement getXmlElement() const = 0;
		/*! Returns the content of the Value. If DataType does not match XmlElement or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getXmlElement(XmlElement& target) const = 0;
		/*! Sets the value to a scalar of type XmlElement. */
		virtual EnumStatusCode setXmlElement(const XmlElement& pXmlElement) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<XmlElement> getXmlElementArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match XmlElement or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getXmlElementArray(std::vector<XmlElement>& target) const = 0;
		/*! Sets the value to an array of type XmlElement. */
		virtual EnumStatusCode setXmlElementArray(const std::vector<XmlElement>& arrayXmlElement) = 0;

		/*! Returns the content of the Value. If DataType does not match XmlElement or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getXmlElementMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<XmlElement>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type XmlElement.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setXmlElementMatrix(const std::vector<OTUInt32>& arrayDimensions, const XmlElement* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataValue content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DataValue getDataValue() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataValue or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDataValue(DataValue& target) const = 0;
		/*! Sets the value to a scalar of type DataValue. */
		virtual EnumStatusCode setDataValue(const IDataValue* pDataValue) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DataValue> getDataValueArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataValue or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDataValueArray(std::vector<DataValue>& target) const = 0;
		/*! Sets the value to an array of type DataValue. */
		virtual EnumStatusCode setDataValueArray(const std::vector<DataValue>& arrayDataValue) = 0;

		/*! Returns the content of the Value. If DataType does not match DataValue or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDataValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataValue>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DataValue.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDataValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataValue* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Argument content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Argument getArgument() const = 0;
		/*! Returns the content of the Value. If DataType does not match Argument or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getArgument(Argument& target) const = 0;
		/*! Sets the value to a scalar of type Argument. */
		virtual EnumStatusCode setArgument(const IArgument* pArgument) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Argument> getArgumentArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Argument or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getArgumentArray(std::vector<Argument>& target) const = 0;
		/*! Sets the value to an array of type Argument. */
		virtual EnumStatusCode setArgumentArray(const std::vector<Argument>& arrayArgument) = 0;

		/*! Returns the content of the Value. If DataType does not match Argument or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getArgumentMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Argument>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type Argument.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setArgumentMatrix(const std::vector<OTUInt32>& arrayDimensions, const Argument* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for TimeZone content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual TimeZone getTimeZone() const = 0;
		/*! Returns the content of the Value. If DataType does not match TimeZone or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getTimeZone(TimeZone& target) const = 0;
		/*! Sets the value to a scalar of type TimeZone. */
		virtual EnumStatusCode setTimeZone(const ITimeZone* pTimeZone) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<TimeZone> getTimeZoneArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match TimeZone or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getTimeZoneArray(std::vector<TimeZone>&) const = 0;
		/*! Sets the value to an array of type TimeZone. */
		virtual EnumStatusCode setTimeZoneArray(const std::vector<TimeZone>& arrayTimeZone) = 0;

		/*! Returns the content of the Value. If DataType does not match TimeZone or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getTimeZoneMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<TimeZone>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type TimeZone.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setTimeZoneMatrix(const std::vector<OTUInt32>& arrayDimensions, const TimeZone* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for Range content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual Range getRange() const = 0;
		/*! Returns the content of the Value. If DataType does not match Range or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getRange(Range& target) const = 0;
		/*! Sets the value to a scalar of type Range. */
		virtual EnumStatusCode setRange(const IRange*  pRange) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Range> getRangeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match Range or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getRangeArray(std::vector<Range>& target) const = 0;
		/*! Sets the value to an array of type Range. */
		virtual EnumStatusCode setRangeArray(const std::vector<Range>& arrayRange) = 0;

		/*! Returns the content of the Value. If DataType does not match Range or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getRangeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Range>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type Range.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setRangeMatrix(const std::vector<OTUInt32>& arrayDimensions, const Range* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReferenceDescription content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ReferenceDescription getReferenceDescription() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReferenceDescription or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getReferenceDescription(ReferenceDescription& target) const = 0;
		/*! Sets the value to a scalar of type ReferenceDescription. */
		virtual EnumStatusCode setReferenceDescription(const IReferenceDescription* pReferenceDescription) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ReferenceDescription> getReferenceDescriptionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReferenceDescription or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getReferenceDescriptionArray(std::vector<ReferenceDescription>& target) const = 0;
		/*! Sets the value to an array of type ReferenceDescription. */
		virtual EnumStatusCode setReferenceDescriptionArray(const std::vector<ReferenceDescription>& arrayReferenceDescription) = 0;

		/*! Returns the content of the Value. If DataType does not match ReferenceDescription or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getReferenceDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReferenceDescription>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ReferenceDescription.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setReferenceDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReferenceDescription* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ApplicationDescription content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ApplicationDescription getApplicationDescription() const = 0;
		/*! Returns the content of the Value. If DataType does not match ApplicationDescription or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getApplicationDescription(ApplicationDescription& target) const = 0;
		/*! Sets the value to a scalar of type ApplicationDescription. */
		virtual EnumStatusCode setApplicationDescription(const IApplicationDescription* pApplicationDescription) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ApplicationDescription> getApplicationDescriptionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ApplicationDescription or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getApplicationDescriptionArray(std::vector<ApplicationDescription>& target) const = 0;
		/*! Sets the value to an array of type ApplicationDescription. */
		virtual EnumStatusCode setApplicationDescriptionArray(const std::vector<ApplicationDescription>& arrayApplicationDescription) = 0;

		/*! Returns the content of the Value. If DataType does not match ApplicationDescription or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getApplicationDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ApplicationDescription>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ApplicationDescription.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setApplicationDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const ApplicationDescription* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerDiagnosticsSummary content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServerDiagnosticsSummaryDataType getServerDiagnosticsSummaryDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerDiagnosticsSummaryDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataType(ServerDiagnosticsSummaryDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServerDiagnosticsSummaryDataType. */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataType(const IServerDiagnosticsSummaryDataType* pServerDiagnosticsSummaryDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServerDiagnosticsSummaryDataType> getServerDiagnosticsSummaryDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerDiagnosticsSummaryDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeArray(std::vector<ServerDiagnosticsSummaryDataType>& target) const = 0;
		/*! Sets the value to an array of type ServerDiagnosticsSummaryDataType. */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeArray(const std::vector<ServerDiagnosticsSummaryDataType>& arrayServerDiagnosticsSummaryDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ServerDiagnosticsSummaryDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getServerDiagnosticsSummaryDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerDiagnosticsSummaryDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ServerDiagnosticsSummaryDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setServerDiagnosticsSummaryDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerDiagnosticsSummaryDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SubscriptionDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SubscriptionDiagnosticsDataType getSubscriptionDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SubscriptionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataType(SubscriptionDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SubscriptionDiagnosticsDataType. */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataType(const ISubscriptionDiagnosticsDataType* pSubscriptionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SubscriptionDiagnosticsDataType> getSubscriptionDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SubscriptionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeArray(std::vector<SubscriptionDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SubscriptionDiagnosticsDataType. */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeArray(const std::vector<SubscriptionDiagnosticsDataType>& arraySubscriptionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match SubscriptionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getSubscriptionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SubscriptionDiagnosticsDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type SubscriptionDiagnosticsDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setSubscriptionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SubscriptionDiagnosticsDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SessionDiagnosticsDataType getSessionDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSessionDiagnosticsDataType(SessionDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SessionDiagnosticsDataType. */
		virtual EnumStatusCode setSessionDiagnosticsDataType(const ISessionDiagnosticsDataType* pSessionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SessionDiagnosticsDataType> getSessionDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeArray(std::vector<SessionDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SessionDiagnosticsDataType. */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeArray(const std::vector<SessionDiagnosticsDataType>& arraySessionDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match SessionDiagnosticsDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getSessionDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionDiagnosticsDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type SessionDiagnosticsDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setSessionDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionDiagnosticsDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SessionSecurityDiagnostics content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SessionSecurityDiagnosticsDataType getSessionSecurityDiagnosticsDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionSecurityDiagnosticsDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataType(SessionSecurityDiagnosticsDataType& target) const = 0;
		/*! Sets the value to a scalar of type SessionSecurityDiagnosticsDataType. */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataType(const ISessionSecurityDiagnosticsDataType* pSessionSecurityDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SessionSecurityDiagnosticsDataType> getSessionSecurityDiagnosticsDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SessionSecurityDiagnosticsDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeArray(std::vector<SessionSecurityDiagnosticsDataType>& target) const = 0;
		/*! Sets the value to an array of type SessionSecurityDiagnosticsDataType. */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeArray(const std::vector<SessionSecurityDiagnosticsDataType>& arraySessionSecurityDiagnosticsDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match SessionSecurityDiagnosticsDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getSessionSecurityDiagnosticsDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SessionSecurityDiagnosticsDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type SessionSecurityDiagnosticsDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setSessionSecurityDiagnosticsDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SessionSecurityDiagnosticsDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServiceCounter content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServiceCounterDataType getServiceCounterDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServiceCounterDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServiceCounterDataType(ServiceCounterDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServiceCounterDataType. */
		virtual EnumStatusCode setServiceCounterDataType(const IServiceCounterDataType* pServiceCounterDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServiceCounterDataType> getServiceCounterDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServiceCounterDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServiceCounterDataTypeArray(std::vector<ServiceCounterDataType>& target) const = 0;
		/*! Sets the value to an array of type ServiceCounterDataType. */
		virtual EnumStatusCode setServiceCounterDataTypeArray(const std::vector<ServiceCounterDataType>& arrayServiceCounterDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ServiceCounterDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getServiceCounterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServiceCounterDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ServiceCounterDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setServiceCounterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServiceCounterDataType* matrixValues) = 0;

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for SemanticChangeStructure content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SemanticChangeStructureDataType getSemanticChangeStructureDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match SemanticChangeStructureDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSemanticChangeStructureDataType(SemanticChangeStructureDataType& target) const = 0;
		/*! Sets the value to a scalar of type SemanticChangeStructureDataType. */
		virtual EnumStatusCode setSemanticChangeStructureDataType(const ISemanticChangeStructureDataType* pSemanticChangeStructureDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SemanticChangeStructureDataType> getSemanticChangeStructureDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SemanticChangeStructureDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeArray(std::vector<SemanticChangeStructureDataType>& target) const = 0;
		/*! Sets the value to an array of type SemanticChangeStructureDataType. */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeArray(const std::vector<SemanticChangeStructureDataType>& arraySemanticChangeStructureDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match SemanticChangeStructureDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getSemanticChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SemanticChangeStructureDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type SemanticChangeStructureDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setSemanticChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const SemanticChangeStructureDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ModelChangeStructure content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ModelChangeStructureDataType getModelChangeStructureDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ModelChangeStructureDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getModelChangeStructureDataType(ModelChangeStructureDataType& target) const = 0;
		/*! Sets the value to a scalar of type ModelChangeStructureDataType. */
		virtual EnumStatusCode setModelChangeStructureDataType(const IModelChangeStructureDataType* pModelChangeStructureDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ModelChangeStructureDataType> getModelChangeStructureDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ModelChangeStructureDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getModelChangeStructureDataTypeArray(std::vector<ModelChangeStructureDataType>& target) const = 0;
		/*! Sets the value to an array of type ModelChangeStructureDataType. */
		virtual EnumStatusCode setModelChangeStructureDataTypeArray(const std::vector<ModelChangeStructureDataType>& arrayModelChangeStructureDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ModelChangeStructureDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getModelChangeStructureDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ModelChangeStructureDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ModelChangeStructureDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setModelChangeStructureDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ModelChangeStructureDataType* matrixValues) = 0;
#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for UserIdentityToken content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match.
		*
		* @note getDataType() returns the data type of the concrete subtype */
		virtual UserIdentityToken getUserIdentityToken() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserIdentityToken or ArrayType is not EnumValueArrayType_Scalar an error is returned.
		*
		* @note getDataType() returns the data type of the concrete subtype */
		virtual EnumStatusCode getUserIdentityToken(UserIdentityToken& target) const = 0;
		/*! Sets the value to a scalar of type UserIdentityToken.
		*
		* @note getDataType() returns the data type of the concrete subtype */
		virtual EnumStatusCode setUserIdentityToken(const IUserIdentityToken* pUserIdentityToken) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match.
		* @note getDataType() returns the data type of the concrete subtype */
		virtual std::vector<UserIdentityToken> getUserIdentityTokenArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match UserIdentityToken or ArrayType is not EnumValueArrayType_Array an error is returned.
		*
		* @note getDataType() returns the data type of the concrete subtype */
		virtual EnumStatusCode getUserIdentityTokenArray(std::vector<UserIdentityToken>& target) const = 0;
		/*! Sets the value to an array of type UserIdentityToken.
		*
		* @note getDataType() returns the data type of the concrete subtype
		* @note all values in the array must be of the same concrete subtype */
		virtual EnumStatusCode setUserIdentityTokenArray(const std::vector<UserIdentityToken>& arrayUserIdentityToken) = 0;

		/*! Returns the content of the Value. If DataType does not match UserIdentityToken or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @note getDataType() returns the data type of the concrete subtype
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getUserIdentityTokenMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<UserIdentityToken>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type UserIdentityToken.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @note getDataType() returns the data type of the concrete subtype
		* @note all values in the array must be of the same concrete subtype
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setUserIdentityTokenMatrix(const std::vector<OTUInt32>& arrayDimensions, const UserIdentityToken* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for SignedSoftwareCertificate content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual SignedSoftwareCertificate getSignedSoftwareCertificate() const = 0;
		/*! Returns the content of the Value. If DataType does not match SignedSoftwareCertificate or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getSignedSoftwareCertificate(SignedSoftwareCertificate& target) const = 0;
		/*! Sets the value to a scalar of type SignedSoftwareCertificate. */
		virtual EnumStatusCode setSignedSoftwareCertificate(const ISignedSoftwareCertificate* pSignedSoftwareCertificate) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<SignedSoftwareCertificate> getSignedSoftwareCertificateArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match SignedSoftwareCertificate or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getSignedSoftwareCertificateArray(std::vector<SignedSoftwareCertificate>& target) const = 0;
		/*! Sets the value to an array of type SignedSoftwareCertificate. */
		virtual EnumStatusCode setSignedSoftwareCertificateArray(const std::vector<SignedSoftwareCertificate>& arraySignedSoftwareCertificate) = 0;

		/*! Returns the content of the Value. If DataType does not match SignedSoftwareCertificate or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getSignedSoftwareCertificateMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<SignedSoftwareCertificate>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type SignedSoftwareCertificate.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setSignedSoftwareCertificateMatrix(const std::vector<OTUInt32>& arrayDimensions, const SignedSoftwareCertificate* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for BuildInfo content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual BuildInfo getBuildInfo() const = 0;
		/*! Returns the content of the Value. If DataType does not match BuildInfo or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getBuildInfo(BuildInfo& target) const = 0;
		/*! Sets the value to a scalar of type BuildInfo. */
		virtual EnumStatusCode setBuildInfo(const IBuildInfo* pBuildInfo) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<BuildInfo> getBuildInfoArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match BuildInfo or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getBuildInfoArray(std::vector<BuildInfo>& target) const = 0;
		/*! Sets the value to an array of type BuildInfo. */
		virtual EnumStatusCode setBuildInfoArray(const std::vector<BuildInfo>& arrayBuildInfo) = 0;

		/*! Returns the content of the Value. If DataType does not match BuildInfo or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getBuildInfoMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<BuildInfo>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type BuildInfo.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setBuildInfoMatrix(const std::vector<OTUInt32>& arrayDimensions, const BuildInfo* matrixValues) = 0;

#if TB5_ALARMS
		////////////////////////////////////////////////////////////////////////////////
		// Value access for EventFilter content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EventFilter getEventFilter() const = 0;
		/*! Returns the content of the Value. If DataType does not match EventFilter or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEventFilter(EventFilter& target) const = 0;
		/*! Sets the value to a scalar of type EventFilter. */
		virtual EnumStatusCode setEventFilter(const IEventFilter* pEventFilter) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EventFilter> getEventFilterArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EventFilter or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEventFilterArray(std::vector<EventFilter>& target) const = 0;
		/*! Sets the value to an array of type EventFilter. */
		virtual EnumStatusCode setEventFilterArray(const std::vector<EventFilter>& arrayEventFilter) = 0;

		/*! Returns the content of the Value. If DataType does not match EventFilter or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getEventFilterMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EventFilter>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EventFilter.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setEventFilterMatrix(const std::vector<OTUInt32>& arrayDimensions, const EventFilter* matrixValues) = 0;

#endif

		////////////////////////////////////////////////////////////////////////////////
		// Value access for ServerStatus content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ServerStatusDataType getServerStatusDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerStatusDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getServerStatusDataType(ServerStatusDataType& target) const = 0;
		/*! Sets the value to a scalar of type ServerStatusDataType. */
		virtual EnumStatusCode setServerStatusDataType(const IServerStatusDataType* pServerStatusDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ServerStatusDataType> getServerStatusDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ServerStatusDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getServerStatusDataTypeArray(std::vector<ServerStatusDataType>& target) const = 0;
		/*! Sets the value to an array of type ServerStatusDataType. */
		virtual EnumStatusCode setServerStatusDataTypeArray(const std::vector<ServerStatusDataType>& arrayServerStatusDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ServerStatusDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getServerStatusDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ServerStatusDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ServerStatusDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setServerStatusDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ServerStatusDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumValueType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EnumValueType getEnumValueType() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumValueType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEnumValueType(EnumValueType& target) const = 0;
		/*! Sets the value to a scalar of type EnumValueType. */
		virtual EnumStatusCode setEnumValueType(const IEnumValueType* pEnumValueType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EnumValueType> getEnumValueTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumValueType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEnumValueTypeArray(std::vector<EnumValueType>& target) const = 0;
		/*! Sets the value to an array of type EnumValueType. */
		virtual EnumStatusCode setEnumValueTypeArray(const std::vector<EnumValueType>& arrayEnumValueType) = 0;

		/*! Returns the content of the Value. If DataType does not match EnumValueType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getEnumValueTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumValueType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EnumValueType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setEnumValueTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumValueType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for KeyValuePair content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual KeyValuePair getKeyValuePair() const = 0;
		/*! Returns the content of the Value. If DataType does not match KeyValuePair or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getKeyValuePair(KeyValuePair& target) const = 0;
		/*! Sets the value to a scalar of type KeyValuePair. */
		virtual EnumStatusCode setKeyValuePair(const IKeyValuePair* pKeyValuePair) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<KeyValuePair> getKeyValuePairArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match KeyValuePair or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getKeyValuePairArray(std::vector<KeyValuePair>& target) const = 0;
		/*! Sets the value to an array of type KeyValuePair. */
		virtual EnumStatusCode setKeyValuePairArray(const std::vector<KeyValuePair>& arrayKeyValuePair) = 0;

		/*! Returns the content of the Value. If DataType does not match KeyValuePair or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getKeyValuePairMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<KeyValuePair>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type KeyValuePair.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setKeyValuePairMatrix(const std::vector<OTUInt32>& arrayDimensions, const KeyValuePair* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for ConfigurationVersionDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ConfigurationVersionDataType getConfigurationVersionDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ConfigurationVersionDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getConfigurationVersionDataType(ConfigurationVersionDataType& target) const = 0;
		/*! Sets the value to a scalar of type ConfigurationVersionDataType. */
		virtual EnumStatusCode setConfigurationVersionDataType(const IConfigurationVersionDataType* pConfigurationVersionDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ConfigurationVersionDataType> getConfigurationVersionDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ConfigurationVersionDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getConfigurationVersionDataTypeArray(std::vector<ConfigurationVersionDataType>& target) const = 0;
		/*! Sets the value to an array of type ConfigurationVersionDataType. */
		virtual EnumStatusCode setConfigurationVersionDataTypeArray(const std::vector<ConfigurationVersionDataType>& arrayConfigurationVersionDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ConfigurationVersionDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getConfigurationVersionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ConfigurationVersionDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ConfigurationVersionDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setConfigurationVersionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ConfigurationVersionDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetMetaDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DataSetMetaDataType getDataSetMetaDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetMetaDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDataSetMetaDataType(DataSetMetaDataType& target) const = 0;
		/*! Sets the value to a scalar of type DataSetMetaDataType. */
		virtual EnumStatusCode setDataSetMetaDataType(const IDataSetMetaDataType* pDataSetMetaDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DataSetMetaDataType> getDataSetMetaDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetMetaDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDataSetMetaDataTypeArray(std::vector<DataSetMetaDataType>& target) const = 0;
		/*! Sets the value to an array of type DataSetMetaDataType. */
		virtual EnumStatusCode setDataSetMetaDataTypeArray(const std::vector<DataSetMetaDataType>& arrayDataSetMetaDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match DataSetMetaDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDataSetMetaDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetMetaDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DataSetMetaDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDataSetMetaDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetMetaDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetReaderDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DataSetReaderDataType getDataSetReaderDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetReaderDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDataSetReaderDataType(DataSetReaderDataType& target) const = 0;
		/*! Sets the value to a scalar of type DataSetReaderDataType. */
		virtual EnumStatusCode setDataSetReaderDataType(const IDataSetReaderDataType* pDataSetReaderDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DataSetReaderDataType> getDataSetReaderDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetReaderDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDataSetReaderDataTypeArray(std::vector<DataSetReaderDataType>& target) const = 0;
		/*! Sets the value to an array of type DataSetReaderDataType. */
		virtual EnumStatusCode setDataSetReaderDataTypeArray(const std::vector<DataSetReaderDataType>& arrayDataSetReaderDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match DataSetReaderDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDataSetReaderDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetReaderDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DataSetReaderDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDataSetReaderDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetReaderDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for DataSetWriterDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual DataSetWriterDataType getDataSetWriterDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetWriterDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getDataSetWriterDataType(DataSetWriterDataType& target) const = 0;
		/*! Sets the value to a scalar of type DataSetWriterDataType. */
		virtual EnumStatusCode setDataSetWriterDataType(const IDataSetWriterDataType* pDataSetWriterDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<DataSetWriterDataType> getDataSetWriterDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match DataSetWriterDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getDataSetWriterDataTypeArray(std::vector<DataSetWriterDataType>& target) const = 0;
		/*! Sets the value to an array of type DataSetWriterDataType. */
		virtual EnumStatusCode setDataSetWriterDataTypeArray(const std::vector<DataSetWriterDataType>& arrayDataSetWriterDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match DataSetWriterDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getDataSetWriterDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<DataSetWriterDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type DataSetWriterDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setDataSetWriterDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const DataSetWriterDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for EnumDefinition content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EnumDefinition getEnumDefinition() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumDefinition or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEnumDefinition(EnumDefinition& target) const = 0;
		/*! Sets the value to a scalar of type EnumDefinition. */
		virtual EnumStatusCode setEnumDefinition(const IEnumDefinition* pEnumDefinition) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EnumDefinition> getEnumDefinitionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EnumDefinition or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEnumDefinitionArray(std::vector<EnumDefinition>& target) const = 0;
		/*! Sets the value to an array of type EnumDefinition. */
		virtual EnumStatusCode setEnumDefinitionArray(const std::vector<EnumDefinition>& arrayEnumDefinition) = 0;

		/*! Returns the content of the Value. If DataType does not match EnumDefinition or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getEnumDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EnumDefinition>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EnumDefinition.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setEnumDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EnumDefinition* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for FieldTargetDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual FieldTargetDataType getFieldTargetDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match FieldTargetDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getFieldTargetDataType(FieldTargetDataType& target) const = 0;
		/*! Sets the value to a scalar of type FieldTargetDataType. */
		virtual EnumStatusCode setFieldTargetDataType(const IFieldTargetDataType* pFieldTargetDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<FieldTargetDataType> getFieldTargetDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match FieldTargetDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getFieldTargetDataTypeArray(std::vector<FieldTargetDataType>& target) const = 0;
		/*! Sets the value to an array of type FieldTargetDataType. */
		virtual EnumStatusCode setFieldTargetDataTypeArray(const std::vector<FieldTargetDataType>& arrayFieldTargetDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match FieldTargetDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getFieldTargetDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<FieldTargetDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type FieldTargetDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setFieldTargetDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const FieldTargetDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for PubSubConnectionDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual PubSubConnectionDataType getPubSubConnectionDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match PubSubConnectionDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getPubSubConnectionDataType(PubSubConnectionDataType& target) const = 0;
		/*! Sets the value to a scalar of type PubSubConnectionDataType. */
		virtual EnumStatusCode setPubSubConnectionDataType(const IPubSubConnectionDataType* pPubSubConnectionDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<PubSubConnectionDataType> getPubSubConnectionDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match PubSubConnectionDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getPubSubConnectionDataTypeArray(std::vector<PubSubConnectionDataType>& target) const = 0;
		/*! Sets the value to an array of type PubSubConnectionDataType. */
		virtual EnumStatusCode setPubSubConnectionDataTypeArray(const std::vector<PubSubConnectionDataType>& arrayPubSubConnectionDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match PubSubConnectionDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getPubSubConnectionDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PubSubConnectionDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type PubSubConnectionDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setPubSubConnectionDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PubSubConnectionDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for ReaderGroupDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual ReaderGroupDataType getReaderGroupDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReaderGroupDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getReaderGroupDataType(ReaderGroupDataType& target) const = 0;
		/*! Sets the value to a scalar of type ReaderGroupDataType. */
		virtual EnumStatusCode setReaderGroupDataType(const IReaderGroupDataType* pReaderGroupDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<ReaderGroupDataType> getReaderGroupDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match ReaderGroupDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getReaderGroupDataTypeArray(std::vector<ReaderGroupDataType>& target) const = 0;
		/*! Sets the value to an array of type ReaderGroupDataType. */
		virtual EnumStatusCode setReaderGroupDataTypeArray(const std::vector<ReaderGroupDataType>& arrayReaderGroupDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match ReaderGroupDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getReaderGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<ReaderGroupDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type ReaderGroupDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setReaderGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const ReaderGroupDataType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for RolePermissionType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual RolePermissionType getRolePermissionType() const = 0;
		/*! Returns the content of the Value. If DataType does not match RolePermissionType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getRolePermissionType(RolePermissionType& target) const = 0;
		/*! Sets the value to a scalar of type RolePermissionType. */
		virtual EnumStatusCode setRolePermissionType(const IRolePermissionType* pRolePermissionType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<RolePermissionType> getRolePermissionTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match RolePermissionType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getRolePermissionTypeArray(std::vector<RolePermissionType>& target) const = 0;
		/*! Sets the value to an array of type RolePermissionType. */
		virtual EnumStatusCode setRolePermissionTypeArray(const std::vector<RolePermissionType>& arrayRolePermissionType) = 0;

		/*! Returns the content of the Value. If DataType does not match RolePermissionType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getRolePermissionTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<RolePermissionType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type RolePermissionType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setRolePermissionTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const RolePermissionType* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for StructureDefinition content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual StructureDefinition getStructureDefinition() const = 0;
		/*! Returns the content of the Value. If DataType does not match StructureDefinition or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getStructureDefinition(StructureDefinition& target) const = 0;
		/*! Sets the value to a scalar of type StructureDefinition. */
		virtual EnumStatusCode setStructureDefinition(const IStructureDefinition* pStructureDefinition) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<StructureDefinition> getStructureDefinitionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match StructureDefinition or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getStructureDefinitionArray(std::vector<StructureDefinition>& target) const = 0;
		/*! Sets the value to an array of type StructureDefinition. */
		virtual EnumStatusCode setStructureDefinitionArray(const std::vector<StructureDefinition>& arrayStructureDefinition) = 0;

		/*! Returns the content of the Value. If DataType does not match StructureDefinition or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getStructureDefinitionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<StructureDefinition>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type StructureDefinition.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setStructureDefinitionMatrix(const std::vector<OTUInt32>& arrayDimensions, const StructureDefinition* matrixValues) = 0;


		////////////////////////////////////////////////////////////////////////////////
		// Value access for WriterGroupDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual WriterGroupDataType getWriterGroupDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match WriterGroupDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getWriterGroupDataType(WriterGroupDataType& target) const = 0;
		/*! Sets the value to a scalar of type WriterGroupDataType. */
		virtual EnumStatusCode setWriterGroupDataType(const IWriterGroupDataType* pWriterGroupDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<WriterGroupDataType> getWriterGroupDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match WriterGroupDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getWriterGroupDataTypeArray(std::vector<WriterGroupDataType>& target) const = 0;
		/*! Sets the value to an array of type WriterGroupDataType. */
		virtual EnumStatusCode setWriterGroupDataTypeArray(const std::vector<WriterGroupDataType>& arrayWriterGroupDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match WriterGroupDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getWriterGroupDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<WriterGroupDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type WriterGroupDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setWriterGroupDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const WriterGroupDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for PublishedVariableDataType content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual PublishedVariableDataType getPublishedVariableDataType() const = 0;
		/*! Returns the content of the Value. If DataType does not match PublishedVariableDataType or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getPublishedVariableDataType(PublishedVariableDataType& target) const = 0;
		/*! Sets the value to a scalar of type PublishedVariableDataType. */
		virtual EnumStatusCode setPublishedVariableDataType(const IPublishedVariableDataType* pPublishedVariableDataType) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<PublishedVariableDataType> getPublishedVariableDataTypeArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match PublishedVariableDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getPublishedVariableDataTypeArray(std::vector<PublishedVariableDataType>& target) const = 0;
		/*! Sets the value to an array of type PublishedVariableDataType. */
		virtual EnumStatusCode setPublishedVariableDataTypeArray(const std::vector<PublishedVariableDataType>& arrayPublishedVariableDataType) = 0;

		/*! Returns the content of the Value. If DataType does not match PublishedVariableDataType or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getPublishedVariableDataTypeMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<PublishedVariableDataType>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type PublishedVariableDataType.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setPublishedVariableDataTypeMatrix(const std::vector<OTUInt32>& arrayDimensions, const PublishedVariableDataType* matrixValues) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for EndpointDescription content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual EndpointDescription getEndpointDescription() const = 0;
		/*! Returns the content of the Value. If DataType does not match EndpointDescription or ArrayType is not EnumValueArrayType_Scalar an error is returned. */
		virtual EnumStatusCode getEndpointDescription(EndpointDescription& target) const = 0;
		/*! Sets the value to a scalar of type EndpointDescription. */
		virtual EnumStatusCode setEndpointDescription(const IEndpointDescription* pEndpointDescription) = 0;

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<EndpointDescription> getEndpointDescriptionArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match EndpointDescription or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getEndpointDescriptionArray(std::vector<EndpointDescription>& target) const = 0;
		/*! Sets the value to an array of type EndpointDescription. */
		virtual EnumStatusCode setEndpointDescriptionArray(const std::vector<EndpointDescription>& arrayEndpointDescription) = 0;

		/*! Returns the content of the Value. If DataType does not match EndpointDescription or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getEndpointDescriptionMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<EndpointDescription>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type EndpointDescription.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setEndpointDescriptionMatrix(const std::vector<OTUInt32>& arrayDimensions, const EndpointDescription* matrixValues) = 0;
		// NEW_SUPPORTED_DATATYPE - copy the block above and replace tape name

		////////////////////////////////////////////////////////////////////////////////
		// Value access for structured data types
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of a user defined structured value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Scalar, an error is returned.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type including the descriptions of the fields
		* @param [out]	fieldValues			Returns the values of the single fields of the structured data type
		*
		* @note	The amount, type and order of @p fieldValues matches to the field descriptions in @p dataTypeDescription.
		*		The field values of nested custom structures are returned as one single value of the type ValueArray.
		*		The field values of arrays of nested structures are returned as one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode getStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<Value>& fieldValues) const = 0;
		/*! Sets the value to a scalar of a user defined structured value.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type
		* @param [in]	fieldValues			The values of the single fields of the structured data type
		*
		* @note	The amount, type and order of @p fieldValues have to match to the field descriptions of @p dataTypeDescription.
		*		The field values of nested custom structures have to be set via one single value of the type ValueArray.
		*		The field values of arrays of nested structures have to be set via one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode setStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues) = 0;

		/*! @deprecated Use setStructuredValue(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<Value>& fieldValues) instead.
		* @overload */
		virtual EnumStatusCode setStructuredValue(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<Value>& fieldValues) = 0;

		/*! Returns the content of a user defined structured value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Array, an error is returned.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type including the descriptions of the fields
		* @param [out]	fieldValues			Returns the values of the single fields of the structured data type for every array element
		*
		* @note	The amount, type and order of @p fieldValues of every array element matches to the field descriptions in @p dataTypeDescription.
		*		The field values of nested custom structures are returned as one single value of the type ValueArray.
		*		The field values of arrays of nested structures are returned as one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode getStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<std::vector<Value> >& fieldValues) const = 0;
		/*! Sets the value to an array of a user defined structured value.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type
		* @param [in]	fieldValues			The values of the single fields of the structured data type for every array element
		*
		* @note	The amount, type and order of @p fieldValues for every array element have to match to the field descriptions of @p dataTypeDescription.
		*		The field values of nested custom structures have to be set via value of the type ValueArray.
		*		The field values of arrays of nested structures have to be set via one single value of the type ValueArray of ValueArray.
		* @see	StructuredDataTypeDescription::getFields() */
		virtual EnumStatusCode setStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues) = 0;
		/*! @deprecated Use setStructuredValueArray(StructuredDataTypeDescriptionConstPtr dataTypeDescription, const std::vector<std::vector<Value> >& fieldValues) instead.
		* @overload */
		virtual EnumStatusCode setStructuredValueArray(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<std::vector<Value> >& fieldValues) = 0;

		/*! Returns the matrix content of a user defined structured value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Matrix, an error is returned.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type including the descriptions of the fields
		* @param [out]	arrayDimensions		Returns the number and sizes of the array dimensions of the value.
		* @param [out]	fieldValues			Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			std::vector<OTUInt32>& arrayDimensions, std::vector<std::vector<Value> >& fieldValues) const = 0;
		/*! Sets the value to a matrix of user defined structured value.
		*
		* @param [in]	dataTypeDescription	The description for the current structured data type
		* @param [in]	arrayDimensions		The number and sizes of the array dimensions of the value.
		* @param [in]	fieldValues			The values of the single fields of the structured data type of the matrix in a flat array.
		*									The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues) = 0;
		/*! @deprecated Use setStructuredValueMatrix(StructuredDataTypeDescriptionConstPtr dataTypeDescription,
		* const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues) instead.
		* @overload */
		virtual EnumStatusCode setStructuredValueMatrix(const INodeId& dataTypeId, StructuredDataTypeDescriptionConstPtr dataTypeDescription,
			const std::vector<OTUInt32>& arrayDimensions, const std::vector<std::vector<Value> >& fieldValues) = 0;

		/*! Returns the encoded value of a user defined complex value.
		* If DataType is not a user defined complex data type (simple data type or a well known complex data type)
		* or ArrayType is not EnumValueArrayType_Scalar, an error is returned.
		*
		* @param [out]	encodingId		The NodeId to identify the data type encoding
		* @param [out]	body			The encoded body of the complex data type
		*
		* @note	The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode getComplexValueRaw(NodeId& encodingId, ByteString& body) const = 0;
		/*! Sets the encoded value of a user defined complex value.
		*
		* @param [in]	encodingId		The NodeId to identify the data type encoding
		* @param [in]	body			The encoded body of the complex data type
		*
		* @note	There are no checks for the content of @p body, so the application has to take care that this represents a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode setComplexValueRaw(const INodeId& encodingId, const IByteString& body) = 0;

		/*! Returns the contents of a user defined complex value array.
		* If DataType is not a user defined complex data type (simple data type or a well known structured data type)
		* or ArrayType is not EnumValueArrayType_Array, an error is returned.
		*
		* @param [out]	encodingId	The NodeIds to identify the data type encodings of the encoded values
		* @param [out]	bodies		The encoded bodies of all complex data type values
		*
		* @note	There are no checks for the contents of @p bodies, so the application has to take care that they represent a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode getComplexValueRawArray(NodeId& encodingId, std::vector<ByteString>& bodies) const = 0;
		/*! Sets an array of encoded user defined complex values.
		*
		* @param [in]	encodingId	The NodeId to identify the data type encodings of the encoded values
		* @param [in]	bodies		The encoded bodies for all complex data type values
		*
		* @note	There are no checks for the contents of @p bodies, so the application has to take care that they represent a valid decodable value.
		*		The @p encodingId is the NodeId, which is sent on the wire and it is different to the NodeId of the data type. */
		virtual EnumStatusCode setComplexValueRawArray(const INodeId& encodingId, const std::vector<ByteString>& bodies) = 0;

		/*! Returns the matrix content of a user defined complex value.
		* If DataType is not a user defined data type (simple data type, a well known structured data type or an unknown type)
		* or ArrayType is not EnumValueArryType_Matrix, an error is returned.
		*
		* @param [in]	encodingId		The NodeId to identify the data type encodings of the encoded values
		* @param [out]	arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param [out]	bodies			Returns the encoded bodies of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getComplexValueRawMatrix(NodeId& encodingId, std::vector<OTUInt32>& arrayDimensions, std::vector<ByteString>& bodies) const = 0;
		/*! Sets the value to a matrix of user defined structured value.
		*
		* @param [in]	encodingId		The NodeId to identify the data type encodings of the encoded values
		* @param [in]	arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param [in]	bodies			The encoded bodies of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setComplexValueRawMatrix(const INodeId& encodingId, const std::vector<OTUInt32>& arrayDimensions, const std::vector<ByteString>& bodies) = 0;

		////////////////////////////////////////////////////////////////////////////////
		// Value access for variant content
		////////////////////////////////////////////////////////////////////////////////

		/*! Returns the content of the Value. This access should be used only if DataType and ArrayType are known to match. */
		virtual std::vector<Value> getValueArray() const = 0;
		/*! Returns the content of the Value. If DataType does not match BaseDataType or ArrayType is not EnumValueArrayType_Array an error is returned. */
		virtual EnumStatusCode getValueArray(std::vector<Value>& target) const = 0;
		/*! Sets the value to an array of variants (DataType BaseDataType). */
		virtual EnumStatusCode setValueArray(const std::vector<Value>& arrayValue) = 0;

		/*! Returns the content of the Value. If DataType does not match Value or ArrayType is not EnumValueArrayType_Matrix an error is returned.
		*
		* @param arrayDimensions	Returns the number and sizes of the array dimensions of the value.
		* @param matrixValues		Returns the values of the matrix in a flat array.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode getValueMatrix(std::vector<OTUInt32>& arrayDimensions, std::vector<Value>& matrixValues) const = 0;
		/*! Sets the value to a matrix of type Value.
		*
		* @param arrayDimensions	The number and sizes of the array dimensions of the value.
		* @param matrixValues		The values of the matrix in a flat array. The total amount of elements must be the multiplied amount of all array dimension sizes.
		*
		* @see <a href="matrix_serialization.htm">Matrix Serialization</a> */
		virtual EnumStatusCode setValueMatrix(const std::vector<OTUInt32>& arrayDimensions, const Value* matrixValues) = 0;


		/*! Returns a string representation of the value */
		virtual tstring toString() const = 0;

		/*! Clears the contents of this object to enable its re-use. */
		virtual void clear() = 0;

		/*! Copies the content of @p cp to this instance */
		virtual EnumStatusCode set(const IValue* cp) = 0;
		/*! @overload */
		virtual EnumStatusCode set(const IValue& cp) = 0;

		/*! Compares this instance to the given @p other instance.
		*
		* @li Returns <0, if "this < other"
		* @li Returns 0, if "this == other"
		* @li Returns >0, if "this > other" */
		virtual int compare(const IValue* other) const = 0;
		/*! @overload */
		virtual int compare(const IValue& other) const = 0;

		/*! Compares two instances for equality */
		virtual bool operator==(const IValue& other) const = 0;
		/*! Compares two instances for inequality */
		virtual bool operator!=(const IValue& other) const = 0;

		/*! For internal use only */
		virtual void* getInternHandle() const = 0;
	}; // end IValue
} // end namespace
#endif	// IVALUE_H
