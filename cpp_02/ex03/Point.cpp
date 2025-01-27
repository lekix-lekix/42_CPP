/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:42:05 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/27 19:04:09 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
    std::cout << "Point default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
    std::cout << "Point float x y constructor called" << std::endl;
}

Point::Point(Point const &rhs) : _x(rhs._x), _y(rhs._y)
{
    std::cout << "Point copy constructor called" << std::endl;
}

Point::~Point(void)
{
    std::cout << "Point destructor called" << std::endl;
}

Fixed Point::getXFixed(void) const
{
    return this->_x;
}

Fixed Point::getYFixed(void) const
{
    return this->_y;
}

void Point::printRawValues(void)
{
    std::cout << "x = " << this->_x.getRawBits();
    std::cout << " y = " << this->_y.getRawBits() << std::endl;
}

Point &Point::operator=(Point const &rhs)
{
    (void) rhs;
    return *this;
}