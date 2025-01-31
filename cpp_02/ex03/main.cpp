/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:11:16 by lekix             #+#    #+#             */
/*   Updated: 2025/01/31 14:22:26 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void) argc;
    Point a(1, 1);
    Point b(5, 1);
    Point c(3, 4);
    Point in(atoi(argv[1]), atoi(argv[2]));
    
    bool is_in = bsp(a, b, c, in);
    is_in ? std::cout << "It's in !" << std::endl : std::cout << "It's out !" << std::endl;
    return 0;
}