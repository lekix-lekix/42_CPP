/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:20 by lekix             #+#    #+#             */
/*   Updated: 2025/01/22 19:36:49 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_fixed = 0;
    std::cout << "Default Fixed constuctor called" << std::endl;
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

Fixed::Fixed(int const int_value)
{
    this->_fixed = int_value * (1 << this->_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const float_value)
{
    std::cout << "Float constructor called" << std::endl;
    std::cout << float_value << std::endl;
    this->_fixed = roundf(float_value * (float)(1 << this->_bits));
    std::cout << this->_fixed << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixed;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed = roundf(raw << this->_bits);
}

float Fixed::toFloat(void) const
{
    return (float)this->getRawBits() / (float)(1 << this->_bits);
}

int Fixed::toInt(void) const
{
    return this->getRawBits() >> this->_bits;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed = src.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed &src)
{
    o << src.toFloat();
    return o;
}

std::ostream &operator<<(std::ostream &o, Fixed const &src)
{
    o << src.toFloat();
    return o;
}
