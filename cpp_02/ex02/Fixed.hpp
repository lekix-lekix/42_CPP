/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:29 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 11:47:12 by lekix            ###   ########.fr       */
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

    Fixed(int const int_value);
    Fixed(float const float_value);

    Fixed &operator=(Fixed const &rhs);

    bool operator<(Fixed const &rhs);
    bool operator>(Fixed const &rhs);
    bool operator==(Fixed const &rhs);
    bool operator!=(Fixed const &rhs);
    bool operator>=(Fixed const &rhs);
    bool operator<=(Fixed const &rhs);

    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &lhs, Fixed &rhs);
    static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
    static Fixed &max(Fixed &lhs, Fixed &rhs);
    static Fixed const &max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream &operator<<(std::ostream &o, Fixed &rhs);
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif