/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:23:52 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/09 17:08:58 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "../include/AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;

    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(Bureaucrat const & other);
        Bureaucrat & operator=(Bureaucrat const & other);

        Bureaucrat(std::string name, int grade);

        std::string getName(void);
        int         getGrade(void);

        void        incGrade(void);
        void        decGrade(void);
        void        signForm(AForm & to_sign);
        void        executeForm(AForm const & form);

    class GradeTooHighException : public std::exception
    {
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what(void) const throw();
    };
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & src);

#endif