#include "Bureaucrat.hpp"

static void checkBureaucrat(std::string name, int grade)
{
	try
	{
		Bureaucrat	b(name, grade);

		std::cout << b;

        std::cout << std::endl;
        std::cout << "Incrementing the grade: ";
		b.incrementGrade();
        std::cout << b << std::endl;

        std::cout << "Decrementing the grade: ";
		b.decrementGrade();
        std::cout << b << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl <<std::endl;
	}
}

int main(void)
{
    std::string name;
    std::string gradeStr;
    int         grade;

    std::cout << "Name the bureaucrat: " << std::endl;
    getline(std::cin, name);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}

    std::cout << "Grade the bureaucrat: " << std::endl;
    getline(std::cin, gradeStr);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}
    try 
    {
        grade = std::stoi(gradeStr);
    }
    catch (std::invalid_argument const& e) 
    {
        std::cerr << "Error: Invalid input. Please enter a valid number for grade." << std::endl;
        return 1;
    }
    catch (std::out_of_range const& e) 
    {
        std::cerr << "Error: Grade out of range." << std::endl;
        return 1;
    }

    checkBureaucrat(name, grade);

	return (0);
}
