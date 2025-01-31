/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:20 by lekix             #+#    #+#             */
/*   Updated: 2025/01/31 13:17:20 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default Fixed constuctor called" << std::endl;
    this->_fixed = 0;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Fixed copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Fixed destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed = src.getRawBits();
    return *this;
}

