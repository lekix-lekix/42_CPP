/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:31:24 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 17:37:46 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T *arr, unsigned int size, F func)
{
    for (unsigned int i = 0; i < size; i++)
        func(arr[i]);
}

template<typename U>
void print(U const & to_print)
{
    std::cout << to_print << "\n";
}

#endif