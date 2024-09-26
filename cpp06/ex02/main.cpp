#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	srand(time(NULL));

	Base *a =  new A;
	Base *b =  new B;
	Base *c =  new C;
	Base *rand = generate();

    std::cout << "\n***Testing identify with pointers***\n" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(rand);

	std::cout << "\n***Testing identify with references***\n" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*rand);

	delete rand;
	delete a;
	delete b;
	delete c;
    return 0;
}