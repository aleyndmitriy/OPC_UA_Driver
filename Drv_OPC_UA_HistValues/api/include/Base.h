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

#ifndef BASE_H
#define BASE_H

#ifdef SOOS_WINDOWS
#pragma pack(push, 8)
#endif

namespace SoftingOPCToolbox5
{
	/*! Base class for all reference counted API objects. */
	class TBC_EXPORT Base
	{
	public:
		/*! Default constructor */
		Base();

		/*! Destructor */
		virtual ~Base();

		/*! Increments the reference count of this object by one.
		* Returns the resulting incremented reference count.
		*
		* In general, modifying the reference count manually should be avoided.
		* Please consider using smart pointers (see ObjectPointer) instead.
		*
		* @see ObjectPointer */
		long addRef() const;

		/*! Decrements the reference count of this object by one.
		* Returns the resulting decremented reference count.
		*
		* In general, modifying the reference count manually should be avoided.
		* Please consider using smart pointers (see ObjectPointer) instead.
		*
		* @see ObjectPointer */
		long release() const;


		//////////////////////////////////////////////////////////////////////////
		// SDK-internal members
		//////////////////////////////////////////////////////////////////////////

		/*! For internal use only */
		void* getOTBHandle() const
		{
			return m_OTBHandle;
		}
		/*! For internal use only */
		void setOTBHandle(void* handle)
		{
			m_OTBHandle = handle;
		}
		/*! For internal use only */
		void* getTBCHandle()
		{
			return (void*) this;
		}

		/*! For internal use only */
		Base* m_pNext;
		/*! For internal use only */
		Base* m_pPrevious;

	private:
		/*! Reference counter */
		mutable OTAtomic m_RefCount;

		/*! Handle of core object */
		mutable void* m_OTBHandle;

		mutable bool m_enabledRefCountTracing;
	public:
		/*! Enable debugging of addRef() and release() calls */
		void enableRefCountTracing(bool enable = true) const
		{
			m_enabledRefCountTracing = enable;
		}

	}; // Base

	/*! This smart pointer class template holds a pointer to a dynamically allocated, reference-counted object.
	* Smart pointers of type T are typically obtained by the static method T::create(). */
	template <class T> class ObjectPointer
	{
	public:
		/*! Default Constructor */
		ObjectPointer()
		{
			m_p = NULL;
		}

		/*! Constructs a smart pointer from a raw pointer to a reference-counted object.
		* The type of @p rawPointer must match type T of this ObjectPointer. */
		ObjectPointer(IN T* rawPointer)
		{
			m_p = rawPointer;
			if(m_p != NULL)
			{
				m_p->addRef();
			}
		}

		/*! Constructs a smart pointer from a raw pointer to a reference-counted object.
		* The type of @p rawPointer must be implicitly convertible to type T of this ObjectPointer. */
		template<class Y>
		ObjectPointer(IN Y* rawPointer)
		{
			m_p = rawPointer;
			if(m_p != NULL)
			{
				m_p->addRef();
			}
		}

		/*! Constructs a smart pointer from another smart pointer.
		* The pointer type of @p objectPointer must match type T of this ObjectPointer. */
		ObjectPointer(IN const ObjectPointer& p_)
		{
			m_p = p_.m_p;
			if(m_p != NULL)
			{
				m_p->addRef();
			}
		}

		/*! Constructs a smart pointer from another smart pointer.
		* The type Y of @p objectPointer must be implicitly convertible to type T of this ObjectPointer. */
		template<class Y>
		ObjectPointer(IN const ObjectPointer<Y>& objectPointer)
		{
			m_p = objectPointer.p();
			if(m_p != NULL)
			{
				m_p->addRef();
			}
		}

		/*! For internal use only */
		ObjectPointer(IN T* p_, bool)
		{
			m_p = p_;
		}

		/*! Destructor */
		~ObjectPointer()
		{
			if(m_p)
			{
				m_p->release();
			}
		}

		/*! Relinquishes the object owned by the ObjectPointer.
		* This will effectively reset the ObjectPointer to contain a NULL pointer
		*
		* Post condition: isNull() == true */
		void reset() const
		{
			T* p_ = m_p;
			m_p = NULL;

			if(p_)
			{
				p_->release();
			}
		}

		/*! Cast operator to internal type */
		operator T*() const
		{
			return m_p;
		}

		/*! Dereference operator which provides access to the pointee */
		T& operator*() const
		{
			_ASSERTION(m_p != NULL, _T("Dereferencing NULL pointer"));
			return *m_p;
		}

		/*! Overload of the -> operator which provides pointer semantics */
		T* operator->() const
		{
			return m_p;
		}

		/*! Returns the raw pointer that this ObjectPointer manages */
		inline T* p() const
		{
			return m_p;
		}

		/*! Assigns a raw pointer to this smart pointer. This will perform an addRef() call on the given
		* pointer @p ptr and release any previously stored pointer inside the ObjectPointer. */
		ObjectPointer& operator=(T* ptr)
		{
			// guard against self-assignment
			if(m_p == ptr) // this==&ptr evaluates this==ptr.operator&()
			{
				return *this;
			}
			if(m_p)
			{
				m_p->release();
			}
			m_p = ptr;
			if(m_p)
			{
				m_p->addRef();
			}
			return *this;
		}

		/*! Assigns another smart pointer to this smart pointer. */
		ObjectPointer& operator=(IN const ObjectPointer& ptr)
		{
			return *this = ptr.m_p;
		}
		/*! @overload */
		template<class Y>
		ObjectPointer& operator=(IN const ObjectPointer<Y>& ptr)
		{
			return *this = ptr.p();
		}

		//! Tests whether the contained pointer is accessible
		bool isNotNull() const
		{
			return (m_p != NULL);
		}

		//! Tests whether the contained pointer is inaccessible
		bool isNull() const
		{
			return (m_p == NULL);
		}

	private:
		mutable T* m_p;
	}; // ObjectPointer

	/*! Provides the "=="-operator for smart pointers. This operator provides pointer the
	* same semantic as the "=="-operator for raw pointers. */
	template<class T, class U>
	bool operator==(const ObjectPointer<T>& first, const ObjectPointer<U>& second)
	{
		return first.p() == second.p();
	}

	/*! Provides the "!="-operator for smart pointers. This operator provides pointer the
	* same semantic as the "!="-operator for raw pointers. */
	template<class T, class U>
	bool operator!=(const ObjectPointer<T>& first, const ObjectPointer<U>& second)
	{
		return first.p() != second.p();
	}

	/*! Provides the "<"-operator for smart pointers. This operator provides pointer the
	* same semantic as the "<"-operator for raw pointers. */
	template<class T, class U>
	bool operator<(const ObjectPointer<T>& first, const ObjectPointer<U>& second)
	{
		return first.p() < second.p();
	}

	/*! Provides a static_cast operator for smart pointers.
	*
	* The expression static_cast<T>(objectPointer.p()) must be valid.
	* If an empty (i.e. isNull() == true) smart pointer is provided, the returned
	* smart pointer is also empty.
	*
	* Example: ObjectPointer<Server::Variable> variablePtr = static_pointer_cast<Server::Variable>(baseBaseNodePtr); */
	template<class T, class U>
	ObjectPointer<T> static_pointer_cast(const ObjectPointer<U>& objectPointer)
	{
		return ObjectPointer<T>(static_cast<T*>(objectPointer.p()));
	}

	/*! Provides a const_cast operator for smart pointers.
	*
	* The expression const_cast<T>(objectPointer.p()) must be valid.
	* If an empty (i.e. isNull() == true) smart pointer is provided, the returned
	* smart pointer is also empty.
	*
	* Example: ObjectPointer<Server::Variable> variablePtr = const_pointer_cast<const Server::Variable>(constVariablePtr); */
	template<class T, class U>
	ObjectPointer<T> const_pointer_cast(const ObjectPointer<U>& objectPointer)
	{
		return ObjectPointer<T>(const_cast<T*>(objectPointer.p()));
	}

	/*! Provides a dynamic_cast operator for smart pointers.
	*
	* The expression dynamic_cast<T>(objectPointer.p()) must be valid.
	* If an empty (i.e. isNull() == true) smart pointer is provided, the returned
	* smart pointer is also empty.
	*
	* Example: ObjectPointer<Server::Variable> variablePtr = dynamic_pointer_cast<Server::Variable>(baseBaseNodePtr); */
	template<class T, class U>
	ObjectPointer<T> dynamic_pointer_cast(const ObjectPointer<U>& objectPointer)
	{
		T* pOther = dynamic_cast<T*>(objectPointer.p());
		if(pOther != NULL)
		{
			return ObjectPointer<T>(pOther);
		}
		return ObjectPointer<T>();
	}

	/*! For internal use only */
	inline void* getInnerHandle(Base* pBase)
	{
		if(pBase)
		{
			return pBase->getOTBHandle();
		}
		return 0;
	}
}

#ifdef SOOS_WINDOWS
#pragma pack(pop)
#endif
#endif	// BASE_H
