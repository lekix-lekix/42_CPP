/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/09 19:06:20 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

int main ()
{
    try 
    {
        Intern jonas;
        AForm *shrubbery = jonas.make_form("shrubbery creation", "Moi");
        std::cout << shrubbery->getName() << "\n";
        shrubbery = jonas.make_form("presidential pardon", "Moi");
        std::cout << shrubbery->getName() << "\n";
        AForm *un_autre = jonas.make_form("ta gueule", "connard");

        (void)un_autre;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}