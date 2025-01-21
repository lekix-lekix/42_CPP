/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:19:45 by lekix             #+#    #+#             */
/*   Updated: 2025/01/21 16:15:41 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    Zombie *my_zombie;
    Zombie *another_one;
    
    my_zombie = new Zombie("Jordan");
    my_zombie->announce();
    another_one = newZombie("Jacquot");
    randomChump("Marvinzo");
    delete my_zombie;
    delete another_one;
}