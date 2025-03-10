/* Header-protection */
#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define HIGHTEST 1
#define LOWEST 150

class Bureaucrat;

class Form
{
    private:
        const std::string	name;
        bool                isSigned;
		const int			gradeSign;
        const int			gradeExec;

    public:
        Form();
        Form(std::string &name, int &gradeSign, int &gradeExec);
        virtual ~Form();

        Form(const Form &copy);
        Form &operator=(const Form &src);

        std::string	getName() const;
        bool        getIsSigned() const;
		int			getGradeSign() const;
        int			getGradeExec() const;

        void        beSigned(const Bureaucrat &bur);

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