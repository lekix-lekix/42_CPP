/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/09 13:48:44 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main ()
{
    try 
    {
        Form le_form("la demission", 1, 1);
        std::cout << le_form;
        Bureaucrat macron("Macron", 1);
        macron.signForm(le_form);
        Bureaucrat retailleau("Retailleau", 2);
        retailleau.signForm(le_form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}