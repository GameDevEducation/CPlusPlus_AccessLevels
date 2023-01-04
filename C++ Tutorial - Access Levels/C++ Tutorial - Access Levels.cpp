// C++ Tutorial - Access Levels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Grandparent
{
public: // accessible inside and outside of the class
	int Public1 = 1;

protected: // accessible inside the class and by any descendants
	int Protected1 = 10;

private: // only accessible inside the class
	int Private1 = 100;
};

// forward declaration of ParentC
class ParentC;

class ParentA : public Grandparent
{
	// ParentC is a friend of ParentA - one way friendship
	friend /*class*/ ParentC;

protected:
	int Protected2 = 11;

private:
	int Private2 = 101;

public:
	void DemoFunction1()
	{
		std::cout << Public1 << std::endl;
		std::cout << Protected1 << std::endl;
		//std::cout << Private1 << std::endl; // will not work
	}

	void DemoFunction1A();
};

class ParentB : public Grandparent
{
public:
	void DemoFunction2()
	{
		ParentA variable1;

		std::cout << variable1.Public1 << std::endl;
		//std::cout << variable1.Protected1 << std::endl; // will not work
		//std::cout << variable1.Private1 << std::endl; // will not work
	}

	void DemoFunction4()
	{
		std::cout << Public1 << std::endl;
		std::cout << Protected1 << std::endl;
		//std::cout << Private1 << std::endl; // will not work
	}
};

class ChildA : public ParentB
{
public:
	void DemoFunction5()
	{
		std::cout << Public1 << std::endl;
		std::cout << Protected1 << std::endl;
		//std::cout << Private1 << std::endl; // will not work
	}
};

class ParentC : public Grandparent
{
protected:
	int Protected3 = 12;

public:
	void DemoFunction3()
	{
		ParentA variable1;

		std::cout << variable1.Public1 << std::endl;
		std::cout << variable1.Protected1 << std::endl;
		std::cout << variable1.Protected2 << std::endl;
		//std::cout << variable1.Private1 << std::endl; // will not work
		std::cout << variable1.Private2 << std::endl;
	}
};

void ParentA::DemoFunction1A()
{
	ParentC variable1;
	std::cout << variable1.Public1 << std::endl;
	//std::cout << variable1.Protected3 << std::endl; // will not work
}

int main()
{
	ParentA variable1;
	variable1.DemoFunction1A();
	std::cout << variable1.Public1 << std::endl;
	//std::cout << variable1.Protected1 << std::endl; // will not work
	//std::cout << variable1.Private1 << std::endl; // will not work

	ParentC variable2;
	variable2.DemoFunction3();

	ParentB variable3;
	variable3.DemoFunction4();
	std::cout << variable3.Public1 << std::endl;

	ChildA variable4;
	variable4.DemoFunction5();
}
