/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:14 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 15:21:22 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float get_orientation(Point const &a, Point const &b, Point const &c)
{
    return (a.getXFloat() - c.getXFloat()) * (b.getYFloat() - c.getYFloat()) - (b.getXFloat() - c.getXFloat()) * (a.getYFloat() - c.getYFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float o1 = get_orientation(point, a, b);
    float o2 = get_orientation(point, b, c);
    float o3 = get_orientation(point, c, a);

    std::cout << o1 << " " << o2 << " " << o3 << std::endl;
    if ((o1 < 0 && o2 < 0 && o3 < 0) || (o1 > 0 && o2 > 0 && o3 > 0))
        return true;
    return false;
}