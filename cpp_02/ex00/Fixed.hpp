/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:29:29 by lekix             #+#    #+#             */
/*   Updated: 2025/01/31 13:17:08 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

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

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif