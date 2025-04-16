/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyFirstTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:24 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 17:04:24 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFIRSTTEMPLATE_HPP
# define MYFIRSTTEMPLATE_HPP

#include <iostream>

template<typename T>
T const & min(T const & x, T const & y)
{
    return (x < y ? x : y);
}

template<typename T>
T const & max(T const & x, T const & y)
{
    return (x > y ? x : y);
}

template<typename T>
void swap(T & x, T & y)
{
    T tmp;
    
    tmp = x;
    x = y;
    y = tmp;
}

#endif