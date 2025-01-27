/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:41:47 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/27 13:22:55 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point(void);
    Point(Point const &rhs);
    Point(float const x, float const y);
    ~Point(void);

    float getXFloat(void) const;
    float getYFloat(void) const;
    void printRawValues(void);
    
    bool bsp(Point const a, Point const b, Point const c, Point const point);

    Point &operator=(Point const &rhs);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif