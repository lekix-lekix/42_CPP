/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/10 12:35:48 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main ()
{
    try 
    {
        Bureaucrat first;
        Bureaucrat second("Constantin", 12);
        Bureaucrat third = second;
        std::cout << third;
        second.incGrade();
        std::cout << second;
        second.decGrade();
        std::cout << second;
        Bureaucrat fourth("Hakim", 150);
        fourth.decGrade();
        Bureaucrat fifth("Hakim", 1);
        fifth.incGrade();
        // Bureaucrat fifth("Hakim", -1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}