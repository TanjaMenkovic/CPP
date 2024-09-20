/* Header-protection */
#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define HIGHTEST 1
#define LOWEST 150

class Form
{
    private:
        const std::string	name;
        bool                isSigned;
		const int			gradeSign;
        const int			gradeExec;

    public:
        Form();
        Form(std::string name, bool isSigned, int gradeSign, int gradeExec);
        ~Form();

        Form(const Form &copy);
        Form &operator=(const Form &src);

        std::string	getName() const;
        bool        getIsSigned() const;
		int			getGradeSign() const;
        int			getGradeExec() const

        void        beSigned(Bureaucrat bur);

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

std::ostream	&operator <<(std::ostream &o, const Form &form);