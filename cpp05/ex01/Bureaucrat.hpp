/* Header-protection */
#pragma once

#include <iostream>
#include <string>

#define HIGHTEST 1
#define LOWEST 150

class Bureaucrat
{
    private:
        const std::string	name;
		int			        grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string	name, int grade);
        ~Bureaucrat();

        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &src);

        std::string	getName() const;
		int			getGrade() const;

        void        incrementGrade();
        void        decrementGrade();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);