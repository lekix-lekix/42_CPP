/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:03:17 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 19:32:34 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void)
{
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(Character const &rhs)
{
    *this = rhs;
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_items[i])
            delete this->_items[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(Character const &rhs)
{
    this->_name = rhs._name;
    for (int i = 0; i < 4; i++)
    {
        if (this->_items[i])
            delete this->_items[i];
        if (rhs._items[i])
            this->_items[i] = rhs._items[i]->clone();
        else
            this->_items[i] = NULL;
    }
    return *this;
}

Character::Character(std::string name)
{
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    std::cout << "Character string constructor called" << std::endl;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->_items[i])
        {
            this->_items[i] = m;
            std::cout << m->getType() << " successfully equipped at slot " << i << std::endl;
            return ;
        }
    }
    std::cout << "No slot available! Please unequip." << std::endl;
}

void Character::unequip(int idx)
{
    if (!this->_items[idx])
        std::cout << "Materia slot already empty!" << std::endl;
    else
    {
        std::cout << this->getName() << " drops his " << this->_items[idx]->getType() << " materia" << std::endl;
        this->_items[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (!this->_items[idx])
        return;
    this->_items[idx]->use(target);
}
