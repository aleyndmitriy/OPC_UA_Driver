/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for Callback of client of RT Items
*/


#pragma once

#include "IExtensible.h"

#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{

class Tvq;


class ICallbackClientRtItem : public IExtensible
{
public:

	virtual int DataChange(ULONG ulItemId, VOID* pParam, const Tvq* pTvq) = 0;
   /**<
      @brief This function is called by RT Item server when data item states are changed
		       This function will be called in case of communication error also, quality
				 in Tvq will indicate the problem

      @param[in] ulItemId Item id
		@param[in] pParam Parameter that was passed during subscription
      @param[in] pTvq Pointer to Tvq with item information

      @return Error code
   */

	virtual int ReadDone(ULONG ulTransactionId, VOID* pContext, ULONG ulCount,
		const ULONG* pItemIdList, const Tvq* pTvqList, const int* pErrList) = 0;
   /**<
      @brief This function is called when read operation requested by client is complete

      @param[in] ulTransactionId Transaction id, it will have the same info
		                        that was filled during BeginRead() request
		@param[in] pContext Pointer to context tha was passed by client during BeginRead() request
      @param[in] ulCount number of IDs and TVQ structures in the array
      @param[in] pItemIdList Array of item IDs
      @param[in] pTvqList Array of Tvq
      @param[in] pErrList Array with errors, error per item

      @return Error code
   */

   virtual int WriteDone(ULONG ulTransactionId, VOID* pContext, ULONG ulCount,
		const ULONG* pItemIdList, const int* pErrList) = 0;
   /**<
      @brief This function is called when write operation requested by client is complete

      @param[in] ulTransactionId Transaction id, it will have the same info
		                        that was filled during BeginWrite() request
		@param[in] pContext Pointer to context tha was passed by client during BeginWrite() request
      @param[in] ulCount number of item IDs in the array
      @param[in] pItemHandleList Array of IDs of data items  
      @param[in] pErrList Array with errors, error per item ID

      @return Error code
   */
};

}

/**
	@}
*/

#pragma pack()