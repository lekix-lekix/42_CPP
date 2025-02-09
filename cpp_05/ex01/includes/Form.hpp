/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:04 by lekix             #+#    #+#             */
/*   Updated: 2025/02/09 16:57:56 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "../includes/Bureaucrat.hpp"

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
        Form(Form const &rhs);
        ~Form(void);
        Form &operator=(Form const &rhs);

        Form(std::string name, int sign_grade, int exec_grade);

        std::string const &getName(void) const;
        bool const &getSignedStatus(void) const;
        int const &getSignGrade(void) const;
        int const &getExecGrade(void) const;

        void beSigned(Bureaucrat const &to_check);
    
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Grade is too high or negative!";
            }
            void triggerException(void);
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Grade is too low !";
            }
            void triggerException(void);
    };    
};

#endif