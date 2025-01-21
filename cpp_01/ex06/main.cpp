/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:06 by lekix             #+#    #+#             */
/*   Updated: 2025/01/21 16:39:02 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int return_func_code(std::string harl_func)
{
    if (harl_func.compare("DEBUG") == 0) return debug;
    if (harl_func.compare("INFO") == 0) return info;
    if (harl_func.compare("WARNING") == 0) return warning;
    if (harl_func.compare("ERROR") == 0) return error;
    return (-1);
}

int main(int argc, char **argv)
{
    Harl my_harl;
    int which_func;

    if (argc != 2)
    {
        std::cout << "Harl mode must specified, and only one !" << std::endl;
        return (-1);
    }
    which_func = return_func_code(argv[1]);
    switch (which_func)
    {
        case 0:
            my_harl.complain("DEBUG");

        case 1:
            my_harl.complain("INFO");

        case 2:
            my_harl.complain("WARNING");

        case 3:
            my_harl.complain("ERROR");
            break;

        default:
            std::cout << " [ Probably complaining about insignificant problems ]" << std::endl;
    }
}
