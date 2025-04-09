/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:00:43 by lekix             #+#    #+#             */
/*   Updated: 2025/04/09 18:43:01 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern created\n";    
}

Intern::~Intern(void)
{
    std::cout << "Intern destroyed\n";
}

Intern::Intern(const Intern & other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern & other)
{
    (void) other;
    return *this;
}

AForm *Intern::make_form(std::string form, std::string target)
{
    std::string form_names[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    int i = 0;

    while (form_names[i] != form && i < 3)
        i++;
    switch (i)
    {
        case 0:
            return new ShrubberyCreationForm(target);
            break;
        case 1:
            return new PresidentialPardonForm(target);
            break;
        case 2:
            return new RobotomyRequestForm(target);
            break;
        default:
            throw NoFormFound();
    }
}

const char *Intern::NoFormFound::what() const throw()
{
    return ("No form found\n");
}

