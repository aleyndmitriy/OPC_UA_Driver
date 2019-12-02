/*	Copyright (c) Ocean Data Systems
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR 
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS INC.
*/

/**
	@file
	@brief Uuid class.
*/


#pragma once

#include "OdsCoreLib.h"
#include "OdsString.h"


namespace ODS
{

namespace Core
{

UUID ODS_CORE_LIB_EXP UuidFromString(const OdsString& rUuidStr);

class ODS_CORE_LIB_EXP Uuid
{
	struct UuidBody;

public:

	Uuid();
	
	Uuid(const Uuid& rOther);

	Uuid(const UUID& rUuid);
	
	Uuid(const OdsString& rUuidStr);

	Uuid& operator = (const Uuid& rOther);

	~Uuid();

	void SetId(const UUID& rUuid);

	const UUID& GetId() const;

	// return string in form: 33221100-5544-7766-8899-aabbccddeeff
	OdsString ToString() const;
	
	// takes string like 33221100-5544-7766-8899-aabbccddeeff and creates UUID 
	int FromString(const OdsString& rUuidStr);

	bool operator == (const Uuid& rRight) const;

	bool operator != (const Uuid& rRight) const;

	bool operator < (const Uuid& rRight) const;

	bool operator > (const Uuid& rRight) const;

	bool operator <= (const Uuid& rRight) const;

	bool operator >= (const Uuid& rRight) const;

	bool IsEmpty() const;

	static Uuid EmptyUuid();

private:

	UuidBody* m_pBody;
};

}} // namespace