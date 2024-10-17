#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			throw " Invalid number of arguments";
		}

		RPN result;
        try
        {
            result.rpn(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() <<  std::endl;
        }
	}
	catch (const char *error)
	{
		std::cerr << "Error:" << error << std::endl;
	}
}