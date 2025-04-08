/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:41 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/08 21:38:27 by lekix            ###   ########.fr       */
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
        const std::string _name;
        bool              _signed;
        const int         _sign_grade;
        const int         _exec_grade;

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

std::ostream & operator<<(std::ostream & o, Form const &src);

#endif