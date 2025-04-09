/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:28:10 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 18:41:13 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern & other);
        Intern & operator=(const Intern & other);
    
    AForm *make_form(std::string form, std::string target);
    
    class NoFormFound : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif