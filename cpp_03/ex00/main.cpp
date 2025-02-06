/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/02/06 11:45:16 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    ClapTrap first;
    ClapTrap second("Kim");
    ClapTrap third = second;
    ClapTrap fourth("Arthur");

    std::cout << first.getName() << std::endl;
    std::cout << second.getName() << std::endl;
    std::cout << third.getName() << std::endl;
    std::cout << fourth.getName() << std::endl;

    std::cout << fourth.getATK() << std::endl;
    std::cout << fourth.getHP() << std::endl;
    std::cout << fourth.getNRG() << std::endl;

    second.attack("Arthur");
    fourth.takeDamage(second.getATK());
    std::cout << fourth.getName() << " has " << fourth.getHP() << " HP !" << std::endl;
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    fourth.beRepaired(3);
    std::cout << fourth.getName() << " has " << fourth.getHP() << " HP !" << std::endl;    
}