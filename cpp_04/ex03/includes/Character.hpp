/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:03:36 by lekix             #+#    #+#             */
/*   Updated: 2025/02/03 17:12:21 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_items[4];
        AMateria **floor_items;

    public:
        Character(void);
        Character(Character const &rhs);
        ~Character(void);
        Character &operator=(Character const &rhs);

        Character(std::string name);

        std::string const &getName() const;

        void floorMateria(AMateria *item);
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif