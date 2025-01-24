/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:42:05 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/24 18:27:25 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
    std::cout << "Point default operator called" << std::endl;
}

Point::Point(Point const &rhs)
{
    *this = rhs;
    std::cout << "Point copy constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
    std::cout << "Float x y constructor called" << std::endl;
}

Point::~Point(void)
{
    std::cout << "Point destructor called" << std::endl;
}

Point &Point::operator=(Point const &rhs)
{
    (void) rhs;
    return *this;
}