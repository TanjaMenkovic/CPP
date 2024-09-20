#include "Form.hpp"

Form::Form(): name("Unnamed"), isSigned(0), gradeSign(LOWEST), gradeExec(LOWEST) {}

Form::Form(std::string name, bool isSigned, int gradeSign, int gradeExec): name(name)
{

	if (gradeSign < HIGHTEST)
	    throw Form::GradeTooHighException();
	else if (gradeSign > LOWEST)
	    throw Form::GradeTooLowException();
	this->gradeSign = gradeSign;

    if (gradeExec < HIGHTEST)
	    throw Form::GradeTooHighException();
	else if (gradeExec > LOWEST)
		throw Form::GradeTooLowException();
	this->gradeExec = gradeExec;
}

Form::Form(const Form &copy): name(copy.getName() + "_copy")
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

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high! Hightest grade is 1.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low! Lowest grade is 150.");
}

std::ostream	&operator <<(std::ostream &o, const Form &bur)
{
	o << << "Form name: " << bur.getName() << ", form grade " << bur.getGrade() << ".";
	return o;
}
