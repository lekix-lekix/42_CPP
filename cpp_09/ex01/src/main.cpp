/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:11:03 by lekix             #+#    #+#             */
/*   Updated: 2025/04/27 21:03:25 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
        return -1;
    RPN calc;
    calc.loadStackAndCalculate(std::string(argv[1]));
}