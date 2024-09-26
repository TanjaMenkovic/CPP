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