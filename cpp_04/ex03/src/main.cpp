/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:46:31 by lekix             #+#    #+#             */
/*   Updated: 2025/02/05 18:18:13 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
    // Character elton("elton");
    // Character john;
    // Character elton2(elton);

    // std::cout << elton.getName() << std::endl;
    // std::cout << john.getName() << std::endl;
    // std::cout << elton2.getName() << std::endl;

    // ICharacter *new_elton = new Character("new elton");
    // ICharacter *new_john = new Character("new john");

    // AMateria *ice_ptr = new Ice();
    // std::cout << ice_ptr << std::endl;
    // AMateria *cure_ptr = new Cure();

    // // ICharacter *new_new_elton = new Character();

    // ice_ptr->use(*new_elton);

    // new_elton->equip(ice_ptr);
    // new_elton->equip(cure_ptr);
    // new_elton->use(0, *new_elton);
    // new_elton->use(1, *new_elton);
    // // new_elton->unequip(0);
    // // new_new_elton = new_elton;
    // // new_new_elton->use(0, *new_elton);

    // // new_elton->equip(ice_ptr);
    // // new_elton->unequip(0);
    // // new_elton->equip(ice_ptr);
    // // new_elton->unequip(0);
    // // new_elton->equip(ice_ptr);
    // // new_elton->unequip(0);
    // // new_elton->equip(ice_ptr);
    // // new_elton->unequip(0);
    // // new_elton->equip(ice_ptr);

    // // Character new_new_elton("new new elton");
    // // new_new_elton.equip(ice_ptr);
    // // new_new_elton.equip(cure_ptr);
    // new_elton->unequip(0);
    // new_elton->unequip(1);

    // std::cout << new_elton->getName() << std::endl;
    // std::cout << new_john->getName() << std::endl;

    // // delete ice_ptr;
    // delete new_elton;
    // // delete new_new_elton;
    // delete new_john;

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}