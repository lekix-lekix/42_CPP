/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 14:24:48 by kipouliq         ###   ########.fr       */
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
        ShrubberyCreationForm form("les gens");
        PresidentialPardonForm form1("la france");
        RobotomyRequestForm form2("le peuple");
        std::cout << form;
        std::cout << form1;
        std::cout << form2;
        Bureaucrat macron("Macron", 1);
        Bureaucrat micron("Micron", 2);
        form.beSigned(macron);
        form.execute(macron);
        micron.signForm(form);
        micron.executeForm(form1);
        micron.signForm(form1);
        micron.signForm(form2);
        macron.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}