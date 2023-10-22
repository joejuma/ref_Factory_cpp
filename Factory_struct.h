#pragma once

#ifndef FACTORY_STRUCT__H
#define FACTORY_STRUCT__H
/* Deps */
#include <vector>

#include <cstdlib>
#include <iostream>

/* Macros */
#define SAFE_DELETE_POINTER(ptr) if(ptr != 0)\
{\
	delete ptr;\
	ptr = 0;\
}

/* Structure */
template <typename T>
struct Factory
{
	/*
		# Factory (struct)

		## Description
		An object which can be used to create and manage objects of a given type, with 
		an internal list of pointers to all objects it manages.

		## To-Do
		1. Object pooling rather than just using an std::vector which dynamically 
		   allocates could improve memory continuity and avoid fragmentation.

		2. Memory management dependency injection would be a good idea, so that 
		   anyone could provide their own memory management structure as long as it fit an interface.
	*/

	/* Elements */
	std::vector<T*> elements;

	/* Methods */

	// Constructors & Destructor
	Factory()
	{
		this->elements.clear();
	};
	virtual ~Factory()
	{
		for (T* element : this->elements)
		{
			SAFE_DELETE_POINTER(element);
		};
		this->elements.clear();
	};

	// Membership
	inline bool in(const T* value)
	{
		return (this->find(value) != -1);
	};
	inline bool in(const int64_t& index)
	{
		return (index >= 0 && index < this->elements.size());
	};

	// Access
	inline T* operator[](const int64_t& index)
	{
		if (this->in(index))
		{
			return this->elements[index];
		};

		return 0;
	};
	inline int64_t getIndex(const T* value)
	{
		auto itr = std::find(this->elements.begin(), this->elements.end(), value);
		if (itr != this->elements.end())
		{
			return (int64_t)std::distance(this->elements.begin(), itr);
		};

		return -1;
	};
	inline int64_t find(const T* value)
	{
		return this->getIndex(value);
	};

	// Creation
	inline T* create()
	{
		T* ptr = new T();
		std::cout << "Creating new value on heap..." << ptr << "\n";
		std::cout << "Pushing to list (" << this->elements.size() << " -> ";
		this->elements.push_back(ptr);
		std::cout << this->elements.size() << ")!\n";
		return ptr;
	};
	inline T* create(const T& source)
	{
		T* ptr = this->create();
		(*ptr) = source; // T must have a valid assignment operator.
		return ptr;
	};
	
	// Destruction
	inline void destroy(const int64_t& i)
	{
		T* ptr = 0;
		if (this->in(i))
		{
			SAFE_DELETE_POINTER(this->elements[i]); // Be careful. Zeroes the pointer copy, not the in-list one.
			this->elements.erase(this->elements.begin() + i);
		};
	};
	inline void destroy(const T* ptr)
	{
		int64_t i = this->getIndex(ptr);
		this->destroy(i);
	};
};
#endif