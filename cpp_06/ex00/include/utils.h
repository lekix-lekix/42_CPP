/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:35 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/13 17:50:10 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>
#include <limits>
#include <sstream>

bool is_char(std::string const & literal);
bool is_int(std::string const & literal);
bool is_float(std::string const & literal);
bool is_double(std::string const & literal);
bool is_printable(int c);
bool is_digits(std::string str);
bool test_of_int(long int nb);
bool test_of_float(long double nb);
bool test_of_double(long double nb);

#endif