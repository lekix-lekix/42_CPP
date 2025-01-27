/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:11:16 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 15:16:46 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // Point a;
    // Point b(2.546f, 3.432f);
    // Point c = b;
    
    // std::cout << "a : ";
    // a.printRawValues();
    // std::cout << "b : ";
    // b.printRawValues();
    // std::cout << "c : ";
    // c.printRawValues();

    (void) argc;
    Point a(1, 1);
    Point b(5, 1);
    Point c(3, 4);
    Point in(atoi(argv[1]), atoi(argv[2]));
    
    bool is_in = bsp(a, b, c, in);
    if (is_in)
        std::cout << "It's in !" << std::endl;
    else
        std::cout << "It's out !" << std::endl;
    return 0;
}