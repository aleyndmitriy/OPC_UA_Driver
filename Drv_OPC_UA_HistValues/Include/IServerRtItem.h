/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for RT Item server class
*/


#pragma once

#include "IDsServer.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class ICallbackClientRtItem;
class ItemAddress;
class Tvq;


/**
	This interface represents Real time Item client. The object with this interface
	has to be supported in Drv_XYZ_RtItem.dll which is a driver for RT items
*/
class IServerRtItem : public IDsServer
{
public:

	virtual int RegisterCallback(ICallbackClientRtItem* pCallback) = 0;
	/**<
		@brief Register callback that will be used for notifications

		@param[in] pCallback Pointer to client callback that will be called

		@return Error code
	*/

	virtual int UnregisterCallback() = 0;
	/**<
		@brief Unregister callback

		@return Error code
	*/

	virtual int AddItems(ULONG ulCount, const ItemAddress* pItemAddrList,
		const ULONG* pItemIdList, int* pErrList) = 0;
   /**<
      @brief This function is called in order to add items

      @param[in] ulCount Number of items in the array
      @param[in] pItemAddrList Array of item addresses to be added
      @param[in] pItemIdList Array of item ids to be added
      @param[out] pErrList Array of errors, per item

      @return Error code
   */

   virtual int RemoveItems(ULONG ulCount, const ULONG* pItemIdList, int* pErrList) = 0;
   /**<
      @brief This function is called in order to remove items

      @param[in] ulCount Number of items in the array
      @param[in] pItemIdList Array of item ids removed
      @param[out] pErrList Array of errors, per item

      @return Error code
   */

   virtual int Subscribe(ULONG ulItemId, VOID* pParam) = 0;
   /**<
      @brief This function is called in order to subscribe for item value changes

      @param[in] ulItemId Item ID for subscription
		@param[in] pParam Parameter to be passed to client callback

      @return Error code
   */

   virtual int Unsubscribe(ULONG ulItemId) = 0;
   /**<
      @brief This function is called in order to unsubscribe from item value changes

      @param[in] ulItemId Item id to unsubscribe

      @return Error code
   */

	virtual int Read(ULONG ulCount, const ULONG* pItemIdList, Tvq* pTvqList, int* pErrList) = 0;
   /**<
      @brief This function is called to read items values in synchronous mode

      @param[in] ulCount Number of items to read
      @param[in] pItemIdList Array of item ids to read
      @param[out] pTvqList Pointer to array where items values will be saved
      @param[out] pErrList Pointer to array that will be filled with errors, per item handle

      @return Error code
   */

	virtual int Write(ULONG ulCount, const ULONG* pItemIdList, const Tvq* pTvqList, int* pErrList) = 0;
   /**<
      @brief This function is called to write items values in synchronous mode

      @param[in] ulCount Number of items to write
      @param[in] pItemidList Array of item ids to write
      @param[in] pTvqList Pointer to array with item values
      @param[out] pErrList Pointer to array that will be filled with errors, per item handle

      @return Error code
   */

	virtual int BeginRead(ULONG ulCount, const ULONG* pItemIdList, VOID* pContext,
		ULONG* pulTransactionId, int* pErrList) = 0;
   /**<
      @brief This function is called in order to start asynchronous read
             of item values

      @param[in] ulCount Number of items to read
      @param[in] pItemIdList Array of item ids to read
      @param[in] pContext Pointer that is used to pass any caller's context data. It will be used in callback to client
      @param[out] pulTransactionId Pointer will be filled with transaction id
      @param[out] pErrList Pointer to array to be filled with errors, per item

      @return Error code
   */

	virtual int CancelRead(ULONG ulTransactionId) = 0;
   /**<
      @brief This function is called in order to cancel asynchronous read of item values

      @param[in] ulTransactionId Transaction id is used to identify transaction

      @return Error code
   */

   virtual int BeginWrite(ULONG ulCount, const ULONG* pItemIdList, const Tvq* pTvqList,
		VOID* pContext, ULONG* pulTransactionId, int* pErrList) = 0;
   /**<
      @brief This function is called in order to start asynchronous write of item values

      @param[in] ulCount Number of items to write
      @param[in] pItemIdList Array of item ids to write
      @param[in] pTvqList Array that contains values to write, per item. If timestamp is 0 the current timestamp is taken
      @param[in] pContext Pointer that is used to pass any caller's context data. It will be used in callback to client
      @param[out] pulTransactionId Pointer will be filled with transaction information
      @param[out] pErrList Pointer to array to be filled with errors, per item

      @return Error code
   */

   virtual int CancelWrite(ULONG ulTransactionId) = 0;
   /**<
      @brief This function is called in order to abort asynchronous write

      @param[in] ulTransactionId Transaction id is used to identify transaction

      @return Error code
   */
};

}

/**
	@}
*/

#pragma pack()