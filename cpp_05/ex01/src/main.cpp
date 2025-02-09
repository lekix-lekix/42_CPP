/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:34:32 by lekix             #+#    #+#             */
/*   Updated: 2025/02/09 16:59:48 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Form *cerfa = NULL;
    Form *cerfa2 = NULL;
    Bureaucrat *first = NULL;
    try
    {
        cerfa = new Form("Cerfa 101", 50, 30);
        cerfa2 = new Form("Cerfa 102", 145, 30);
        first = new Bureaucrat("Kojak", 20);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        delete cerfa;
        delete cerfa2;
        delete first;
        return -1;
    }
    
    std::cout << cerfa->getName() << std::endl;
    cerfa->getSignedStatus() ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
    std::cout << cerfa->getSignGrade() << std::endl;
    std::cout << cerfa->getExecGrade() << std::endl;

    first->signForm(*cerfa);
}