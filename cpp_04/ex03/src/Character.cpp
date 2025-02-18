/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:03:17 by lekix             #+#    #+#             */
/*   Updated: 2025/02/18 15:29:00 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void)
{
    this->_floor_items = NULL;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(Character const &rhs)
{
    this->_floor_items = NULL;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    *this = rhs;
    // std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_items[i])
            delete this->_items[i];
    }
    if (this->_floor_items)
    {
        for (int i = 0; this->_floor_items[i]; i++)
            delete this->_floor_items[i];
        delete[] this->_floor_items;
        this->_floor_items = NULL;
    }
    // std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(Character const &rhs)
{
    this->_name = rhs._name;
    this->_floor_items = NULL;
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
    this->_floor_items = NULL;
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_items[i] = NULL;
    // std::cout << "Character string constructor called" << std::endl;         
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    if (m->getEquipStatus())
    {
        std::cout << "Materia already equipped by someone else! Aborting.." << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!this->_items[i] && m != this->_items[i])
        {
            this->_items[i] = m;
            std::cout << this->getName() << " successfully equipped Materia " << m->getType() << " at slot " << i << std::endl;
            return;
        }
        if (m == this->_items[i])
            std::cout << "Materia already in the inventory!" << std::endl;
    }
    std::cout << "No slot available! Please unequip." << std::endl;
    delete m;   
}

void Character::floorMateria(AMateria *item)
{
    static int size;

    if (!item)
        return;
    if (!this->_floor_items)
    {
        this->_floor_items = new AMateria *[2];
        this->_floor_items[0] = item;
        this->_floor_items[1] = NULL;
        size = 2;
        return;
    }
    for (int i = 0; this->_floor_items[i]; i++)
    {
        if (this->_floor_items[i] == item)
            return;
    }
    AMateria **new_floor_items = new AMateria *[size + 1];
    for (int i = 0; this->_floor_items[i]; i++)
        new_floor_items[i] = this->_floor_items[i];
    new_floor_items[size - 1] = item;
    new_floor_items[size] = NULL;
    delete[] this->_floor_items;
    this->_floor_items = new_floor_items;
    size++;
}

void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "Incorrect index, must be between 0 and 3" << std::endl;
        return;
    }
    if (!this->_items[idx])
        std::cout << "Materia slot already empty!" << std::endl;
    else
    {
        std::cout << this->getName() << " drops his " << this->_items[idx]->getType() << " materia equipped at slot " << idx << std::endl;
        this->floorMateria(this->_items[idx]);
        this->_items[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "Incorrect index, must be between 0 and 3" << std::endl;
        return;
    }
    if (this == &target)
    {
        std::cout << "A materia can not attack its owner ! Aborting.." << std::endl;
        return;
    }
    if (!this->_items[idx])
        return;
    this->_items[idx]->use(target);
}
