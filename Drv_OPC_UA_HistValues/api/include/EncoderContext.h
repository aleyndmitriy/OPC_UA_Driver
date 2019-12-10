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

#ifndef ENCODERCONTEXT_H
#define ENCODERCONTEXT_H

#include "libxml/xmlwriter.h"
#include <map>
#include "NodeId.h"
#include "Base.h"
#include "ApiMacros.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		namespace NodeSet2Export
		{
			/*! The EncoderSontext class is used for storing the xml writer, namspaceTranslation map etc */
			class TBC_EXPORT EncoderContext : public Base
			{
			public:
				/*! Constructs a new EncoderContext instance */
				static ObjectPointer<EncoderContext> create();
				virtual ~EncoderContext();

				/*! Accesses the xmlTestWriter member */
				xmlTextWriterPtr getWriter() const;
				/*! Sets the xmlTestWriter member */
				void setWriter(xmlTextWriterPtr val);
				/*! Accesses the namespace translation map member */
				const std::map<OTUInt16, OTUInt16>& getNamespaceTranslationHandle() const;
				/*! Adds a namespace index to the translation map */
				void addNamespace(OTUInt16 namespaceIndex);
				/*! Accesses the alias map member */
				const std::map<NodeId, tstring>& getAliasMapHandle() const;
				/*! Adds an alias to the alias map */
				EnumModelDesignerStatus addAlias(const NodeId& nodeId, const tstring& alias);

			private:
				EncoderContext();

				xmlTextWriterPtr m_writer;
				PRIVATE_EXPORTED_STL_CONTAINER2(std::map<OTUInt16, OTUInt16> m_namespaceTranslation)
				PRIVATE_EXPORTED_STL_CONTAINER2(std::map<NodeId, tstring> m_aliasMap)
			};
			typedef ObjectPointer<EncoderContext> EncoderContextPtr;
			typedef ObjectPointer<const EncoderContext> EncoderContextConstPtr;
		}
	}
}
#endif // ENCODERCONTEXT_H
