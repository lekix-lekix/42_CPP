/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/01/27 18:57:31 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    ClapTrap first("Georges");
    ClapTrap second("Kim");
    ClapTrap third = first;

    first.attack("Kim");
    second.takeDamage(first.getATK());
    second.beRepaired(3);
    std::cout << second.getName() << " has " << second.getHP() << " HP !" << std::endl;
    third.attack("the other Georges");
    first.takeDamage(third.getATK());
}