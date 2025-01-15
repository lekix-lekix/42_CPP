/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:47:11 by lekix             #+#    #+#             */
/*   Updated: 2025/01/15 16:44:07 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Anonymous Zombie created !" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "BANG ! " << this->_name << " killed ! \"zbleeuargg~\"" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}