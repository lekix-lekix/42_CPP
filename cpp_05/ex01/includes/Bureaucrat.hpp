/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:06:20 by lekix             #+#    #+#             */
/*   Updated: 2025/02/09 16:27:27 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "../includes/Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &rhs);
        ~Bureaucrat(void);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        

        Bureaucrat(std::string const name, int grade);

        std::string const &getName(void) const;
        int const &getGrade(void) const;

        void incGrade(void);
        void decGrade(void);
        void signForm(Form &to_sign);

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Bureaucrat grade can not be higher than 1 or negative !";
            }
        void triggerException(void);
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Bureaucrat grade too low !";
            }
        void triggerException(void);
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#endif