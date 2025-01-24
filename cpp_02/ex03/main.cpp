/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:11:16 by lekix             #+#    #+#             */
/*   Updated: 2025/01/23 16:40:58 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main(void)
{
    // Fixed a(20);
    // Fixed b(20.10f);
    // Fixed c(Fixed(5.05f) * Fixed(2));

    // std::string true_str = "true";
    // std::string false_str = "false";

    // std::cout << "a = " << a << std::endl;
    // std::cout << "b = " << b << std::endl;
    // std::cout << "a + b = " << a + b << std::endl;
    // std::cout << "c = " << c << std::endl;

    // if (a < b)
    //     std::cout << "< : " << true_str << std::endl;
    // else
    //     std::cout << "< : " << false_str << std::endl;

    // if (a > b)
    //     std::cout << "> : " << true_str << std::endl;
    // else
    //     std::cout << "> : " << false_str << std::endl;

    // if (a <= b)
    //     std::cout << "<= : " << true_str << std::endl;
    // else
    //     std::cout << "<= : " << false_str << std::endl;

    // if (a >= b)
    //     std::cout << ">= : " << true_str << std::endl;
    // else
    //     std::cout << ">= : " << false_str << std::endl;

    // if (a == b)
    //     std::cout << "== : " << true_str << std::endl;
    // else
    //     std::cout << "== : " << false_str << std::endl;

    // if (a != b)
    //     std::cout << "!= : " << true_str << std::endl;
    // else
    //     std::cout << "!= : " << false_str << std::endl;

    // Fixed a(0.0f);

    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << --a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a-- << std::endl;
    // std::cout << a << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    std::cout << a / 0 << std::endl;
    return 0;
}