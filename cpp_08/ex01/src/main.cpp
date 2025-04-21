/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:33:48 by lekix             #+#    #+#             */
/*   Updated: 2025/04/21 20:09:59 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <ctime>
#include <cstdlib>

int randomNb() { return std::rand() % 100; }

int main ()
{
    srand(time(0));
    
    Span first;
    try
    {
        first.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }

    Span second(10);
    try
    {
        second.shortestSpan();
        second.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    for (int i = 0; i < 10; i++)
        second.addNumber(i);
    second.printSpan();
    try
    {
        second.addNumber(1000);
    }
    catch(std::exception const & e)
    {
        std::cerr << e.what();
    }

    Span third(1000000);
    third.addNumbers(randomNb);
    third.printSpan();
    std::cout << "third shortest = " << third.shortestSpan() << "\n";
    std::cout << "third longest = " << third.longestSpan() << "\n";

    Span fourth(5);
    fourth.addNumber(0);
    fourth.addNumber(10);
    fourth.addNumber(100);
    fourth.addNumber(1000);
    fourth.addNumber(10000);

    std::cout << "fourth shortest = " << fourth.shortestSpan() << "\n";
    std::cout << "fourth largest = " << fourth.longestSpan() << "\n";
}