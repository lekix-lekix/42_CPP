/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:11:16 by lekix             #+#    #+#             */
/*   Updated: 2025/01/31 14:16:28 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed const b(123);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = b;

    a < b ? std::cout << true << std::endl : std::cout << false << std::endl;
    a > b ? std::cout << true << std::endl : std::cout << false << std::endl;
    a == b ? std::cout << true << std::endl : std::cout << false << std::endl;
    a <= b ? std::cout << true << std::endl : std::cout << false << std::endl;
    a >= b ? std::cout << true << std::endl : std::cout << false << std::endl;
    a < c ? std::cout << true << std::endl : std::cout << false << std::endl;
    a > c ? std::cout << true << std::endl : std::cout << false << std::endl;

    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;

    // Fixed a;
    // Fixed const b(Fixed(5.05f) * Fixed(2));
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}