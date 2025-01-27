/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:20 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 12:49:05 by lekix            ###   ########.fr       */
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
    this->setRawBits(int_value);
    std::cout << "Fixed int constructor called" << std::endl;
}

Fixed::Fixed(float const float_value)
{
    std::cout << "Fixed float constructor called" << std::endl;
    this->_fixed = roundf(float_value * (float)(1 << this->_bits));
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

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Fixed copy assignment operator called" << std::endl;
    this->_fixed = rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &rhs)
{    
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs)
{    
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs)
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->_fixed += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old_state;

    old_state = *this;
    this->_fixed += 1;
    return old_state;
}

Fixed &Fixed::operator--(void)
{
    this->_fixed -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old_state;

    old_state = *this;
    this->_fixed -= 1;
    return old_state;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    if (lhs < rhs)
        return lhs;
    return rhs;
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    if (lhs > rhs)
        return lhs;
    return rhs;
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}


bool Fixed::operator<(Fixed const &rhs)
{
    if (this->getRawBits() < rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>(Fixed const &rhs)
{
    if (this->getRawBits() > rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(Fixed const &rhs)
{
    if (this->getRawBits() == rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(Fixed const &rhs)
{
    if (this->getRawBits() != rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(Fixed const &rhs)
{
    if (this->getRawBits() >= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(Fixed const &rhs)
{
    if (this->getRawBits() <= rhs.getRawBits())
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &o, Fixed &rhs)
{
    o << rhs.toFloat();
    return o;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return o;
}
