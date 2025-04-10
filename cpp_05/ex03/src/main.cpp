/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 14:26:47 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

int main ()
{
    AForm *shrubbery = NULL;
    AForm *presidential = NULL;
    AForm *robotomy = NULL;
    AForm *un_autre = NULL;
    try 
    {
        Intern jonas;
        shrubbery = jonas.make_form("shrubbery creation", "Moi");
        std::cout << *shrubbery;
        presidential = jonas.make_form("presidential pardon", "Moi");
        std::cout << *presidential;
        robotomy = jonas.make_form("robotomy request", "moi");
        std::cout << *robotomy;
        AForm *un_autre = jonas.make_form("ta gueule", "connard");

        delete shrubbery;
        delete presidential;
        delete robotomy;
        delete un_autre;
    }
    catch (std::exception &e)
    {
        if (shrubbery)
            delete shrubbery;
        if (presidential)
            delete presidential;
        if (robotomy)
            delete robotomy;
        if (un_autre)
            delete un_autre;
        std::cout << e.what();
    }
}