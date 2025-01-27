/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:14 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 19:10:44 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed get_orientation(Point const &a, Point const &b, Point const &c)
{
    return (a.getXFixed() - c.getXFixed()) * (b.getYFixed() - c.getYFixed()) - (b.getXFixed() - c.getXFixed()) * (a.getYFixed() - c.getYFixed());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed o1 = get_orientation(point, a, b);
    Fixed o2 = get_orientation(point, b, c);
    Fixed o3 = get_orientation(point, c, a);

    std::cout << o1 << " " << o2 << " " << o3 << std::endl;
    if ((o1 < 0 && o2 < 0 && o3 < 0) || (o1 > 0 && o2 > 0 && o3 > 0))
        return true;
    return false;
}
