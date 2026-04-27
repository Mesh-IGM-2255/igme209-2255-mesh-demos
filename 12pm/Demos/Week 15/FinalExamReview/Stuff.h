#pragma once

template <typename T>
class Stuff
{
public:
	Stuff(T _data)
	{
		data = _data;
		dataPtr = new T(_data);
	}

	// 1
	~Stuff()
	{
		delete dataPtr;
	}

	// 2 - copy const
	// get a SHALLOW one by default - need our own
	Stuff(Stuff& other)
	{
		data = other.data;

		// NO shallow
		// dataPtr = other.dataPtr;

		dataPtr = new T(*(other.dataPtr));
	}

	// 3 
	Stuff& operator=(Stuff& other)
	{
		if (this == &other)
		{
			return *this;
		}

		delete dataPtr;

		data = other.data;
		dataPtr = new T(*(other.dataPtr));
	}

private:
	T data;
	T* dataPtr;
};
