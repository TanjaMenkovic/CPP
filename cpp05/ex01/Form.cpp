#include "Form.hpp"

Form::Form(): name("Unnamed"), isSigned(false), gradeSign(HIGHTEST), gradeExec(HIGHTEST) {}

Form::Form(std::string &name, int &gradeSign, int &gradeExec): name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{

	if (this->gradeSign < HIGHTEST)
	    throw Form::GradeTooHighException();
	else if (this->gradeSign > LOWEST)
	    throw Form::GradeTooLowException();

	if (this->gradeExec < HIGHTEST)
	    throw Form::GradeTooHighException();
	else if (this->gradeExec > LOWEST)
	    throw Form::GradeTooLowException();

	this->isSigned = false;
}

Form::Form(const Form &copy): name(copy.getName() + "_copy"), isSigned(copy.isSigned), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
	*this = copy;
}

Form::~Form() {}

Form	&Form::operator =(const Form &src)
{
	if (this != &src)
	{
		this->isSigned = src.getIsSigned();
	}
	return *this;
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}

int	Form::getGradeSign() const
{
	return this->gradeSign;
}

int	Form::getGradeExec() const
{
	return this->gradeExec;
}

void	Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->gradeSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
	std::cout << "Bureaucrat " << bur.getName() << " successfully signed " << this->name << std::endl;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low!");
}

std::ostream	&operator <<(std::ostream &o, const Form &bur)
{
	o << "Form name: " << bur.getName() <<  std::endl;
	o << "Signed: " << bur.getIsSigned() << std::endl;
	o << "Grade to sign: " << bur.getGradeSign() << std::endl;
	o << "Grade to execute: " << bur.getGradeExec() << std::endl;

	return o;
}
