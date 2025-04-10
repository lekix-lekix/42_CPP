/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 12:34:44 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main ()
{
    try 
    {
        // Form le_form("la demission", -1, 150);
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