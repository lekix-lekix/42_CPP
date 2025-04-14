/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:21:40 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/14 15:06:44 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
        return 0;
    // double nb = 1e39;
    // ScalarConverter::convert(nb);
    ScalarConverter::convert(argv[1]);
}