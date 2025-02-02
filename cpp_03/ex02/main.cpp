/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 16:53:24 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main ()
{
    FragTrap first("Georges");
    FragTrap second = first;
    FragTrap third;

    first.attack(second.getName());
    second.takeDamage(first.getATK());
    std::cout << second.getName() << " HP = " << second.getHP() << std::endl;
    second.beRepaired(10);
    std::cout << second.getName() << " HP = " << second.getHP() << std::endl;
    second.highFivesGuys();
}