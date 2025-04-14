/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:35 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/14 18:36:54 by lekix            ###   ########.fr       */
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
bool is_impossible(std::string const & literal);
bool is_printable(int c);
bool is_digits(std::string str);
int  occurences(std::string str, char c);
bool test_literal(std::string literal);
bool test_of_int(std::string literal);
bool test_of_float(long double nb);
bool test_of_double(long double nb);

#endif