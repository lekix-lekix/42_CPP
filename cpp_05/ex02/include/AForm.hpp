/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:38:41 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 14:01:38 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "../include/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const std::string _target;
        bool              _signed;
        const int         _sign_grade;
        const int         _exec_grade;

    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(const AForm & other);
        AForm(std::string name, std::string target, int sign_grade, int exec_grade);
        AForm & operator=(const AForm & other);

        std::string             getName(void);
        std::string             getTarget(void);
        bool                    getSignStatus(void);
        int                     getSignGrade(void);
        int                     getExecGrade(void);

        void                    beSigned(Bureaucrat & signatory);
        void                    execute(Bureaucrat & executor) const;
        virtual void            launch_form_exec(std::string target) const = 0;

        class GradeTooHighException : public std::exception
        {
            const char *what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            const char *what(void) const throw();
        };

        class FormAlreadySigned : public std::exception
        {
            const char *what(void) const throw();
        };

        class FormNotSigned : public std::exception
        {
            const char *what(void) const throw();
        };
};

std::ostream & operator<<(std::ostream & os, AForm & src);

#endif