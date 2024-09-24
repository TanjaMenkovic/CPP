#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create an intern
        Intern someRandomIntern;

        // Create a bureaucrat with a high enough grade
        Bureaucrat highLevelBureaucrat("Waleed", 1);

        // Test valid form creation by the intern
        std::cout << "\nCreating valid forms using the intern:\n\n";

        // Intern creates a ShrubberyCreationForm
        AForm* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "home");
        if (shrubberyForm) {
            highLevelBureaucrat.signForm(*shrubberyForm);
            highLevelBureaucrat.executeForm(*shrubberyForm);
            delete shrubberyForm;  // Don't forget to clean up!
        }

        // Intern creates a RobotomyRequestForm
        AForm* robotomyForm = someRandomIntern.makeForm("robotomy request", "target1");
        if (robotomyForm) {
            highLevelBureaucrat.signForm(*robotomyForm);
            highLevelBureaucrat.executeForm(*robotomyForm);
            delete robotomyForm;  // Clean up
        }

        // Intern creates a PresidentialPardonForm
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Simos");
        if (pardonForm) {
            highLevelBureaucrat.signForm(*pardonForm);
            highLevelBureaucrat.executeForm(*pardonForm);
            delete pardonForm;  // Clean up
        }

        std::cout << "\n---------------------------------------\n";

        // Test with an invalid form type
        std::cout << "\nTrying to create an invalid form:\n\n";
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "random target");
        if (!invalidForm) {
            std::cout << "The intern could not create the requested form!" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
