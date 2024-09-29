#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // Bureaucrat:
    std::string name;
    std::string gradeStr;
    int         grade;
    Bureaucrat* b = nullptr;

    // enter values
    std::cout << "\n\n1. Enter values for bureaucrat:\n\n";
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

    // try to create a Bureaucrat object
    try
    {
        b = new Bureaucrat(name, grade);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
	
    // check bureaucrat
    std::cout << "\n\n2. Check bureaucrat:\n\n";
    try
	{
		std::cout << *b;

        std::cout << std::endl;
        std::cout << "Incrementing the grade: ";
		b->incrementGrade();
        std::cout << *b << std::endl;

        std::cout << "Decrementing the grade: ";
		b->decrementGrade();
        std::cout << *b << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
        delete b;
		std::cerr << e.what() << std::endl << std::endl;
        return 1;
	}

    std::cout << "\n---------------------------------------\n\n";

    // Form:
    std::cout << "\n\n1. Enter values for form:\n\n";

    std::string nameF;
    int         gradeSign;
    int         gradeExec;
    Form*       f = nullptr;

    std::cout << "Name the form: " << std::endl;
    getline(std::cin, nameF);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}

    std::cout << "Grade required to sign the form: " << std::endl;
    getline(std::cin, gradeStr);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}
    try 
    {
        gradeSign = std::stoi(gradeStr);
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

    std::cout << "Grade required to execute the form: " << std::endl;
    getline(std::cin, gradeStr);
    if (std::cin.eof() == true)
	{
		std::cin.clear();
		std::cout << std::endl;
	}
    try 
    {
        gradeExec = std::stoi(gradeStr);
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

    std::cout << "\n\n2. Check form:\n\n";

    // try to create a Form object
    try
    {
        f = new Form(nameF, gradeSign, gradeExec);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        delete b; // clean up dynamically allocated memory
        return 1;
    }

    try
    {
        std::cout << *f << std::endl;
    }
    catch(const std::exception& e)
    {
        delete f;
        delete b;
        std::cerr << e.what() << std::endl << std::endl;
        return 1;
    }

    std::cout << "\n---------------------------------------\n\n";

    // sign the form:
    try
    {
        std::cout << "Sign the form:\n" << *b << std::endl << *f << std::endl;
        b->signForm(*f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete b;
        delete f;
        return 1;
    }
    
    std::cout << "\n---------------------------------------\n\n";

    //write the form:
    std::cout << "Form:\n\n";
    
    try
    {
        std::cout << *f << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl << std::endl;
        delete b;
        delete f;
        return 1;
    }

    delete b;
    delete f;

	return (0);
}
