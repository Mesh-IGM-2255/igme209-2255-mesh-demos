#pragma once

class Singleton
{
public:
	static Singleton* getInstance();
	void instanceInfo();

private:
	static Singleton instance;
	unsigned short instanceGets;
	Singleton();
};

