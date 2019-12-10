/*
	Copyright (c) Ocean Data Systems Ltd.
	All rights reserved

	USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT THE PRIOR
	EXPRESS WRITTEN PERMISSION OF OCEAN DATA SYSTEMS LTD.
*/

/**
	@file
	@brief Interfaces for AlarmFilter
*/


#pragma once

#include <tchar.h>

#include "OdsCoreLib.h"


#pragma pack(8)

/**
	@addtogroup ods_sdk
	@{
*/

namespace ODS
{
/**
Alarm Filters can be static or dynamic. Static Alarm Filter is a filter that was
predefined either in the driver or in the underlaying data source. It has a name
that is used for its identification. Dynamic Alarm Filter is a filter that can
be composed dynamically in UI and used for alarm requests. It has a set of property
ranges that are used for filtering
*/
class ODS_CORE_LIB_EXP AlarmFilter
{
	struct AlarmFilterBody;
	
public:

	static const int FT_CUSTOM   = 0;  /**< custom filter defined in the driver,
														 identified by name, always AlarmFilterStatic */

	static const int FT_EXTERNAL = 1;  /**< external filter provided by underlaying data source,
														 identified by name, always AlarmFilterStatic */

	static const int FT_DYNAMIC  = 2;  /**< dynamic filter, contains data for filtering,
														 always AlarmFilterDynamic*/
	
	virtual ~AlarmFilter();
	AlarmFilter& operator = (const AlarmFilter& rOther);
	
	int GetType() const;
	/**<
		@brief Retrieve type of the filter
		
		@return Filter type
	*/
	
	void SetType(int nType);
	/**<
		@brief Set the type of the filter
		
		@param[in] nType Filter type
		
		@return VOID
	*/

	virtual AlarmFilter* Clone() const = 0;
	/**
		@brief Used to clone the object without knowing what is exact derived type
		@return Pointer to new created object
	*/

	static void DestroyClone(AlarmFilter* pFilter);
	/**
		@brief Used to destroy the object that was cloned
		       The reason for this function is memory management,
				 it will be destroyed where it was allocated
		@return Pointer object to destroy
	*/

protected:
	AlarmFilter(); /** pure AlarmFilter cannot be built, only derived classes */
	AlarmFilter(const AlarmFilter& rOther);
	
private:

	AlarmFilterBody* m_pBody;

};

/**
Static alarm filter is defined in the external system or in the driver and cannot be changed.
It is identified by name and it's a task of driver to understand what is inside such filter
*/
class ODS_CORE_LIB_EXP AlarmFilterStatic : public AlarmFilter
{
	struct AlarmFilterStaticBody;
	
public:
	AlarmFilterStatic();
	~AlarmFilterStatic();
	AlarmFilterStatic(const AlarmFilterStatic& rOther);
	AlarmFilterStatic& operator = (const AlarmFilterStatic& rOther);

	virtual AlarmFilterStatic* Clone() const;
	/**
		@brief Used to clone the object without knowing what is exact derived type
		@return Pointer to new created object
	*/
	
	int GetName(TCHAR** pszName) const;
	/**<
		@brief Retrieve name of static (predefined) alarm filter, string will be
		       allocated inside
		
		@param[out] pszName Pointer filled on output with null terminated string
		
		@return Error code
	*/
	
	int DestroyString(TCHAR* szValue) const;
	/**<
		@brief Destroy allocated string
		
		@param[in] Pointer to string to destroy
		
		@return Error code
	*/
	
	void SetName(const TCHAR* szValue);
	/**<
		@brief Set name for the filter
		
		@param[in] szValue Value to be set
		
		@return VOID
	*/

private:
		
	AlarmFilterStaticBody* m_pBody;
};

class AlarmFilterComponent; // forward declaration

/**
Dynamics alarm filter is a filter that was created dynamically in UI of DreamReport studio. It's passed 
to driver in order to request alarms. It contains all filtering data in form of AlarmFilterComponent list
AlarmFilterComponent is a range of some property (from - to). Dynamic filter also has a filtering
operation. It can be OR / AND. OR means that alarm will pass the filter if any of AlarmFilterComponent
passes alarm. AND means that all AlarmFilterComponent have to pass through the alarm
*/
class ODS_CORE_LIB_EXP AlarmFilterDynamic : public AlarmFilter
{
	struct AlarmFilterDynamicBody;
	
public:

	static const int FILTER_OP_OR = 0;   /** filter will use OR operation between components */
	static const int FILTER_OP_AND = 1;  /** filter will use AND operation between components */
	
	AlarmFilterDynamic();
	~AlarmFilterDynamic();
	AlarmFilterDynamic(const AlarmFilterDynamic& rOther);
	AlarmFilterDynamic& operator = (const AlarmFilterDynamic& rOther);

	virtual AlarmFilterDynamic* Clone() const;
	/**
		@brief Used to clone the object without knowing what is exact derived type
		@return Pointer to new created object
	*/
	
	int GetFilterComponentList(AlarmFilterComponent** ppList, int* pnCount) const;
	/**<
		@brief Retrieve list of filter components, list will be allocated inside
		
		@param[out] ppList Pointer filled with allocated inside list of filter components
		@param[out] pnCount Pointer filled with number of components in the list
		
		@return Error code
	*/
	
	int DestroyFilterComponentList(AlarmFilterComponent* pList, int nCount) const;
	/**<
		@brief Destroy allocated list
		
		@param[in] pList Pointer to allocated list
		@param[in] nCount Number of elements in the list
		
		@return Error code
	*/
	
	int GetFilterOperation() const;
	/**<
		@brief Retrieve filter operation
		
		@return Operation type
	*/
	
	int SetFilterComponentList(const AlarmFilterComponent* pList, int nCount);
	/**<
		@brief Set list of filter components

		@param[in] pList Pointer to filter components
		@param[in] nCount Number of components in the list

		@return Error code
	*/

	void SetFilterOperation(int nOp);
	/**<
		@brief Set filter operation
		
		@param[in] Operation type
		
		@return VOID
	*/
	
private:
	AlarmFilterDynamicBody* m_pBody;	
};


class Property; // forward declaration

/**
	Filter component is a building block for dynamic alarm filter. It has a range
	which is defined with help of two Property objects. Property objects has to be
	with the same ID and name, it will be filled with one of the property id
	that came from alarm browser via property info for alarms.
*/
class ODS_CORE_LIB_EXP AlarmFilterComponent
{
	struct AlarmFilterComponentBody;
	
public:
	AlarmFilterComponent();
	~AlarmFilterComponent();
	AlarmFilterComponent(const AlarmFilterComponent& rOther);
	AlarmFilterComponent& operator = (const AlarmFilterComponent& rOther);
	
	void GetRange(Property* pFrom, Property* pTo) const;
	/**<
		@brief Retrieve range defined in filter component
		
		@param[out] pFrom Pointer filled with property that has From value
		@param[out] pTo Pointer filled with property that has To value
		
		@return VOID
	*/
	
	int SetRange(const Property* pFrom, const Property* pTo);
	/**<
		@brief Set the range into filter component
		
		@param[in] pFrom Pointer to property with From value
		@param[in] pTo Pointer to property with To value
		
		@return Error code
	*/
private:
	AlarmFilterComponentBody* m_pBody;
};

}

/**
	@}
*/


#pragma pack()