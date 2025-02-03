/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:46:31 by lekix             #+#    #+#             */
/*   Updated: 2025/02/03 17:36:39 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"

int main ()
{
    Character elton("elton");
    Character john;
    Character elton2(elton);
    
    std::cout << elton.getName() << std::endl;
    std::cout << john.getName() << std::endl;
    std::cout << elton2.getName() << std::endl;

    ICharacter *new_elton = new Character("new elton");
    ICharacter *new_john = new Character("new john");

    AMateria *ice_ptr = new Ice();
    std::cout << ice_ptr << std::endl;
    AMateria *cure_ptr = new Cure();

    ice_ptr->use(*new_elton);

    new_elton->equip(ice_ptr);
    new_elton->equip(cure_ptr);
    new_elton->use(0, *new_elton);
    new_elton->use(1, *new_elton);
    new_elton->unequip(0);
    // new_elton->unequip(1);
    std::cout << new_elton->getName() << std::endl;
    std::cout << new_john->getName() << std::endl;    

    // delete ice_ptr;
    delete new_elton;
    delete new_john;
}