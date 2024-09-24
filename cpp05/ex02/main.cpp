#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create a bureaucrat with high enough grade to execute forms
        Bureaucrat Sahra("Sahra", 1);

        // Create and test the ShrubberyCreationForm
        std::cout << "\nTesting ShrubberyCreationForm:\n\n";
        ShrubberyCreationForm shrubberyForm("home");
        Sahra.signForm(shrubberyForm);
        Sahra.executeForm(shrubberyForm);  // Should succeed and create a shrubbery file
        
        std::cout << "\n---------------------------------------\n";

        // Create and test the RobotomyRequestForm
        std::cout << "\nTesting RobotomyRequestForm:\n\n";
        RobotomyRequestForm robotomyForm("target1");
        Sahra.signForm(robotomyForm);
        Sahra.executeForm(robotomyForm);  // Should succeed with 50% chance of successful robotomization
        
        std::cout << "\n---------------------------------------\n";

        // Create and test the PresidentialPardonForm
        std::cout << "\nTesting PresidentialPardonForm:\n\n";
        PresidentialPardonForm pardonForm("Criminal");
        Sahra.signForm(pardonForm);
        Sahra.executeForm(pardonForm);  // Should succeed and print pardon message

        std::cout << "\n---------------------------------------\n";

        // Test with lower-ranked bureaucrats who can't sign/execute the forms
        std::cout << "\nTesting with lower-grade Bureaucrat:\n\n";
        Bureaucrat Emmi("Emmi", 150);
        
        ShrubberyCreationForm anotherShrubberyForm("park");
        Emmi.signForm(anotherShrubberyForm);  // Should throw an exception because grade is too low to sign
        
        // If execution reaches here, that means something went wrong
        Emmi.executeForm(anotherShrubberyForm);  // This should also throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------------------\n";

    // Test with a bureaucrat who can sign but can't execute
    try {
        std::cout << "\nTesting with a mid-grade Bureaucrat:\n\n";
        Bureaucrat Oliver("Oliver", 50);

        RobotomyRequestForm robotomyForm("target2");
        Oliver.signForm(robotomyForm);  // Oliver can sign this form since his grade is higher than 72
        Oliver.executeForm(robotomyForm);  // But this should throw an exception because his grade isn't high enough to execute (requires 45)

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
