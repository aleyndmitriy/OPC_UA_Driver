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

#ifndef INNERNETWORKADDRESSURLDATATYPE_H
#define INNERNETWORKADDRESSURLDATATYPE_H

#include "INetworkAddressUrlDataType.h"

namespace SoftingOPCToolbox5
{
	/*! For internal use only */
	class TBC_EXPORT InnerNetworkAddressUrlDataType
		: public INetworkAddressUrlDataType
	{
	public:
		/*! Destructor */
		virtual ~InnerNetworkAddressUrlDataType();

		/*! Returns the concrete data type of an instance of this abstract class. */
		virtual EnumDataTypeId getDataType() const;

		/*! Gets the Url member of the class */
		virtual tstring getUrl() const;
		/*! Sets the Url member in the class */
		virtual void setUrl(const tstring& value);

		/*! Gets the NetworkInterface member of the class */
		virtual tstring getNetworkInterface() const;
		/*! Sets the NetworkInterface member in the class */
		virtual void setNetworkInterface(const tstring& value);

		/*! For internal use only */
		void initInner(NetworkAddressUrlDataTypeStruct* pHandle);

		virtual EnumStatusCode set(const INetworkAddressDataType* pSrc);
		virtual EnumStatusCode set(const INetworkAddressDataType& pSrc);

		virtual int compare(const INetworkAddressDataType* other) const;
		virtual int compare(const INetworkAddressDataType& other) const;

		virtual bool operator==(const INetworkAddressDataType& other) const;
		virtual bool operator!=(const INetworkAddressDataType& other) const;

		virtual NetworkAddressDataTypeStruct* getInternHandle();
		virtual const NetworkAddressDataTypeStruct* getInternHandle() const;

	private:

		NetworkAddressUrlDataTypeStruct* m_pContent;
	};
} // end namespace

#endif
