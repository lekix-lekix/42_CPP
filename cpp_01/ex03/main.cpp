/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:32:39 by lekix             #+#    #+#             */
/*   Updated: 2025/01/16 14:20:45 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon sword("very sharp sword");
    Weapon toilets("good old toilets");
    HumanA first_human("bob", sword);
    HumanB second_human("janis");

    first_human.attack();
    sword.setType("not so sharp sword");
    first_human.attack();
    second_human.attack();
    second_human.setWeapon(toilets);
    second_human.attack();
    toilets.setType("HUGE KATANA");
    second_human.attack();  
}