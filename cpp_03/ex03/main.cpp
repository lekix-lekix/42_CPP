/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:17:04 by lekix             #+#    #+#             */
/*   Updated: 2025/01/30 18:21:23 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main ()
{
    DiamondTrap first;
    DiamondTrap second("Alberto");

    std::cout << first.getATK() << std::endl;
    std::cout << first.getHP() << std::endl;
    first.attack("someone");
    second.attack("someone else");
    second.attack("someone else else");
    first.whoAmI();
    second.whoAmI();
}