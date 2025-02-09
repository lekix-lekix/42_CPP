/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:06:20 by lekix             #+#    #+#             */
/*   Updated: 2025/02/07 16:48:28 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

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

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Grade can not be higher than 1 or negative !";
            }
        void triggerException();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw() {
                return "Grade too low !";
            }
        void triggerException();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#endif