/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:46:31 by lekix             #+#    #+#             */
/*   Updated: 2025/02/17 18:33:03 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

// Subject main
// int main()
// {
//     IMateriaSource *src = NULL;
//     ICharacter *me = NULL;
//     AMateria *tmp = NULL;
//     ICharacter *bob = NULL;
//     try
//     {
//         src = new MateriaSource();
//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());
//         throw(std::bad_alloc());
//         me = new Character("me");
//         tmp = src->createMateria("ice");
//         me->equip(tmp);
//         tmp = src->createMateria("cure");
//         me->equip(tmp);
//         bob = new Character("bob");
//         me->use(0, *bob);
//         me->use(1, *bob);
//         delete bob;
//         delete me;
//         delete src;
//         return 0;
//     }
//     catch (std::bad_alloc &e)
//     {
//         std::cerr << "Bad alloc" << std::endl;
//         delete bob;
//         delete me;
//         delete src;
//         return (-1);
//     }
// }

// My main
int main()
{
    Ice my_ice;
    Ice other_ice = my_ice;  // testing normal init class, although they are supposed to be new'd
    Cure my_cure;
    Cure other_cure = my_cure;

    Character my_char;
    Character other_char = my_char;
    Character john("john");

    std::cout << "my char : " << my_char.getName() << "; other char : " << other_char.getName() << "\n";
    std::cout << "john's name : " << john.getName() << "\n";
    
    AMateria *ice_clone = NULL;
    AMateria *cure_clone = NULL;
    ICharacter *alberto = NULL;
    
    try
    {
        ice_clone = my_ice.clone();
        std::cout << "clone type = " << ice_clone->getType() << std::endl;
        delete ice_clone;
        cure_clone = my_cure.clone();
        std::cout << "clone type = " << cure_clone->getType() << std::endl;
        delete cure_clone;

        alberto = new Character("Alberto");
        std::cout << alberto->getName() << "\n";
        delete alberto;
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "bad alloc" << std::endl;
        delete ice_clone;
        delete cure_clone;
        delete alberto;
        return (-1);
    }

    AMateria *ice = NULL;
    AMateria *cure = NULL;
    ICharacter *arthur = NULL;

    try
    {
        arthur = new Character("Arthur");
        cure = new Cure();
        ice = new Ice();
    }
    catch (std::bad_alloc &e)
    {
        delete ice;
        delete cure;
        delete arthur;
    }
}