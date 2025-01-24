/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:41:47 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/24 18:22:44 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
        Point(Point const &rhs);
        Point(float const x, float const y);
        ~Point(void);

        Point &operator=(Point const &rhs);
        
};

#endif