#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), target("null") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->target = copy.target;
	return (*this);
}

void	RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	int	success;

	/* 
    Set Seed: 
    The seed is set using srand(time(0)), which seeds the random 
    number generator with the current time to ensure different results for each 
    run.
    */
	std::srand(time(0));

    /*
    rand() % 2 generates a number between 0 and 1. This is equivalent to a 50% 
    chance for success or failure. 
    */
	success = rand() % 2; 

	(void)bureaucrat;

    std::cout << "*** Makes some driling noises ***" << std::endl;

	if (success)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << "'s robotomization failed" << std::endl;
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getGradeSign() << ", exec grade: " << form.getGradeExec());
}

