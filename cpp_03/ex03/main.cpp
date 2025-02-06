/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/02/06 12:24:26 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ()
{
    DiamondTrap first;
    DiamondTrap second("Kim");
    DiamondTrap third = second;
    DiamondTrap fourth("Arthur");

    std::cout << first.getName() << std::endl;
    std::cout << second.getName() << std::endl;
    std::cout << third.getName() << std::endl;

    std::cout << fourth.getName() << " : " << fourth.getName() << std::endl;
    std::cout << fourth.getName() << " : " << fourth.getHP() << " hit points " << std::endl;
    std::cout << fourth.getName() << " : " << fourth.getNRG() << " energy points" << std::endl;
    std::cout << fourth.getName() << " : " << fourth.getATK() << " attack points" << std::endl;

    second.attack(fourth.getName());
    fourth.takeDamage(second.getATK());
    std::cout << fourth.getName() << " HP = " << fourth.getHP() << std::endl;
    fourth.beRepaired(10);
    std::cout << fourth.getName() << " HP = " << fourth.getHP() << std::endl;
    fourth.guardGate();
    fourth.highFivesGuys();
}