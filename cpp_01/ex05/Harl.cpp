/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:33:31 by lekix             #+#    #+#             */
/*   Updated: 2025/01/20 15:42:37 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Harl created !" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "Harl destroyed !" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "Debug mode activated !" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info mode activated !" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Info mode activated !" << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error mode activated !" << std::endl;
}

void Harl::complain(std::string level)
{
    t_func harl_funcs[4] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    for (int i = 0; i < 4; i++)
    {
        if (harl_funcs[i].func_name.compare(level) == 0)
        {
            (this->*harl_funcs[i].func_ptr)();
            return;
        }
    }
    std::cout << "No mode found !" << std::endl;
}
