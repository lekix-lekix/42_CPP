/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:06 by lekix             #+#    #+#             */
/*   Updated: 2025/01/20 15:43:08 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ()
{
    Harl my_harl;

    my_harl.complain("INFO");
    my_harl.complain("DEBUG");
    my_harl.complain("WARNING");
    my_harl.complain("ERROR");
    my_harl.complain("bullshit");
    my_harl.complain("WARNINGG");
}