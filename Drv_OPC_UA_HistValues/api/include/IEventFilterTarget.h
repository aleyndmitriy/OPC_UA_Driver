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

#ifndef IEVENTFILTERTARGET_H
#define IEVENTFILTERTARGET_H

#include "Enums.h"
#include "NodeId.h"
#include "QualifiedName.h"
#include "Value.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This interface shall be implemented by classes that provide information
		* about an historical event. The interface is used by the EventFilterEvaluator
		* to decide whether a historical event is included in a HistoryRead response
		* or not.
		*
		* @see EventFilterEvaluator Server::HistoryReadEventTransaction */
		class IEventFilterTarget
		{
		public:
			virtual ~IEventFilterTarget() {}

			/*! Returns the NodeId of the event's type.
			*
			* @param[out] typeDefinitionId	The NodeId of the event's type
			*
			* @note Returning a non-good status code will cause the filter evaluation to fail. */
			virtual EnumStatusCode getTypeDefinitionId(NodeId& typeDefinitionId) = 0;

			/*! Returns the attribute value of a node identified by the given @p browsePath.
			* The browse path is given relative to the historical event.
			* If the browse path cannot be resolved and/or information for the @p attributeId is
			* not available in the historian, the @p value should be set to type StatusCode with
			* the value EnumStatusCode_BadNoData.
			*
			* @param[in]	browsePath		The browse path that identifies the node
			* @param[in]	attributeId		The attribute that the caller is interested in
			* @param[out]	attributeValue	The requested attribute value or EnumStatusCode_BadNoData
			*								if the value is unavailable
			*
			* @note Returning a non-good status code will cause the filter evaluation to fail. */
			virtual EnumStatusCode getAttributeValue(const std::vector<QualifiedName>& browsePath, EnumAttributeId attributeId,
				Value& attributeValue) = 0;
		};
	}
}

#endif // IEVENTFILTERTARGET_H
