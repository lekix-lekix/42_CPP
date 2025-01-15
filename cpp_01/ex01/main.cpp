/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:16:03 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 16:47:18 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies1;
    Zombie *zombies2;
    Zombie *zombies3;

    zombies1 = zombieHorde(5, "Georges");
    zombies2 = zombieHorde(3, "Jean-Francis");
    zombies3 = zombieHorde(6, "Roger");

    for (int i = 0; i < 5; i++)
        zombies1[i].announce();
    for (int i = 0; i < 3; i++)
        zombies2[i].announce();
    for (int i = 0; i < 6; i++)
        zombies3[i].announce();
    delete [] zombies1;
    delete [] zombies2;
    delete [] zombies3;
}