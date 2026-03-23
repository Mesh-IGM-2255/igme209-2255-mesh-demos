#pragma once

// THIS IS ALSO a BAD smart pointer!! Just for demo!!

template <class T>
class SmartPointer
{
public:
	SmartPointer(T* _ptr = nullptr)
	{
		ptr = _ptr;
	}

	~SmartPointer()
	{
		delete ptr;
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
};

