/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:54:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/08 15:12:12 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main ()
{
    try 
    {
        Bureaucrat first;
        Bureaucrat second("Constantin", 2);
        Bureaucrat third = second;
        std::cout << third;
        second.incGrade();
        std::cout << second;
        second.decGrade();
        std::cout << second;
        Bureaucrat fourth("Hakim", 151);
        Bureaucrat fifth("Hakim", -1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}