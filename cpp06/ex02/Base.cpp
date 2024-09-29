#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
    if (rand() % 3 == 0)
		return (new A());
	else if (rand() % 3 == 1)
		return (new B());
	else if (rand() % 3 == 2)
		return (new C());
	else
    {
		perror("Error: generating failed!");
		return (NULL);
    }
}

/*
Pointer casting (dynamic_cast<A*>(p)): When you use dynamic_cast with pointers, 
if the cast fails, it simply returns nullptr. This is safe and doesn't throw an 
exception, allowing you to easily check the result
*/
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "Error: unknown type!" << std::endl;
}

/*
Reference casting (dynamic_cast<A&>(p)): When using dynamic_cast with references, 
if the cast fails, it throws a std::bad_cast exception. This is because references 
must refer to a valid object of the correct type, and there is no "null reference" 
like there is with pointers.
*/
void identify(Base& p)
{
    try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A is the identified type" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B is the identified type" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C is the identified type" << std::endl;
	}
	catch (std::exception &e) {}
}