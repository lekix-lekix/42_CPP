/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:34:32 by lekix             #+#    #+#             */
/*   Updated: 2025/02/07 19:21:02 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat *tom;
    try
    {
        tom = new Bureaucrat("tomi", -24);
        // Bureaucrat tom("Tom", 148);
        std::cout << tom << std::endl;
        tom->decGrade();
        tom->decGrade();
        tom->decGrade();
    }
    catch (const std::exception &e)
    {
        delete tom;
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat tommy("Tommy", 2);
        tommy.incGrade();
        tommy.incGrade();
        tommy.incGrade();
        tommy.incGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}