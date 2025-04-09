/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/09 17:12:34 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main ()
{
    try 
    {
        PresidentialPardonForm form;
        Bureaucrat macron("Macron", 1);
        Bureaucrat micron("Micron", 150);
        form.beSigned(macron);
        macron.executeForm(form);
        micron.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}