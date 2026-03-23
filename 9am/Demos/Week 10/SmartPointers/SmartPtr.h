#pragma once

// This is a BAD SMART POINTER!!!
// Doesn't keep ref counts, etc!

template <class T>
class SmartPtr
{
public:
	SmartPtr(T* _ptr = nullptr)
	{
		ptr = _ptr;
	};

	~SmartPtr()
	{
		delete ptr;
		ptr = nullptr;
	}

	T& operator *()
	{
		return *ptr;
	}

	T* operator ->()
	{
		return ptr;
	}

private:
	T* ptr;
	// static int refCount; // can't finish without rule of three
};

