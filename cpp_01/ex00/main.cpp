/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:19:45 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 16:48:58 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    Zombie *my_zombie;
    
    my_zombie = new Zombie("Jordan");
    my_zombie->announce();
    randomChump("Marvinzo");
    delete my_zombie;
}