/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:59:04 by lekix             #+#    #+#             */
/*   Updated: 2025/02/10 14:53:25 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool              _signed;
        int const         _sign_grade;        
        int const         _exec_grade;

    public:
        AForm(void);
        AForm(AForm const &rhs);
        ~AForm(void);
        AForm &operator=(AForm const &rhs);

        AForm(std::string name, int sign_grade, int exec_grade);

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