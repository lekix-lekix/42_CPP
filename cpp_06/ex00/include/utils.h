/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:35 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/11 19:06:33 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>
#include <limits>

bool is_char(std::string const & literal);
bool is_int(std::string str, double decimal);
bool is_printable(int c);
bool is_digits(std::string str);
bool test_of_int(long int nb);
bool test_of_float(long int nb);
bool test_of_double(long int nb);

#endif