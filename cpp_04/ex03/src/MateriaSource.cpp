/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:18 by lekix             #+#    #+#             */
/*   Updated: 2025/02/18 15:23:28 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->_stock[i] = NULL;
    // std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
    *this = rhs;
    // std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i])
            delete this->_stock[i];
    }
    // std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i])
            delete this->_stock[i];
        if (rhs._stock[i])
            this->_stock[i] = rhs._stock[i];
        else
            this->_stock[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i] == m)
        {
            std::cout << "Materia already in stock ! Aborting.." << std::endl;
            return ;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!this->_stock[i])
        {
            std::cout << "Materia stored in MateriaSource at slot " << i << std::endl;
            this->_stock[i] = m;
            return ;
        }
    }
    std::cout << "No slot available to learn a new Materia. Aborting.." << std::endl;
    delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_stock[i] && this->_stock[i]->getType().compare(type) == 0)
            return this->_stock[i]->clone();
    }
    std::cout << "No materia of this type found !" << std::endl;
    return (0);
}
