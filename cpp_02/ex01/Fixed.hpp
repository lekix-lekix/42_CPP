/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:29 by lekix             #+#    #+#             */
/*   Updated: 2025/01/31 13:44:13 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixed;
    static const int _bits = 8;

public:
    Fixed(void);
    Fixed(Fixed const &src);
    ~Fixed(void);
    Fixed &operator=(Fixed const &src);

    Fixed(int const int_value);
    Fixed(float const float_value);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed &src);
std::ostream &operator<<(std::ostream &o, Fixed const &src);

#endif