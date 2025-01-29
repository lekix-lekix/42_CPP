/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/01/29 18:33:25 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FrapTrap.hpp"

int main ()
{
    FragTrap first("Georges");
    FragTrap second = first;

    first.attack(second.getName());
    second.takeDamage(first.getATK());
    std::cout << second.getName() << " HP = " << second.getHP() << std::endl;
    second.beRepaired(10);
    std::cout << second.getName() << " HP = " << second.getHP() << std::endl;
    second.highFivesGuys();
}