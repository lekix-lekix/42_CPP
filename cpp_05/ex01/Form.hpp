/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:41 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 12:21:05 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool              _signed;
        int const         _sign_grade;
        int const         _exec_grade;

    public:
        Form(void);
        ~Form(void);
        Form(const Form & other);
        Form(std::string name, int sign_grade, int exec_grade);
        Form & operator=(const Form & other);

        std::string     getName(void);
        bool            getSignStatus(void);
        int             getSignGrade(void);
        int             getExecGrade(void);

        void            beSigned(Bureaucrat & signatory);

        class GradeTooHighException : public std::exception
        {
            const char *what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            const char *what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & os, Form & src);

#endif