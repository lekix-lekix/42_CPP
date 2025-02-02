/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:46:31 by lekix             #+#    #+#             */
/*   Updated: 2025/02/02 19:36:58 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"

int main ()
{
    AMateria *first = new Ice();
    AMateria *second = new Cure() ;

    AMateria *m = first->clone(); 
    AMateria *n = second->clone(); 

    std::cout << first->getType() << std::endl;
    std::cout << second->getType() << std::endl;
    std::cout << m->getType() << std::endl;
    std::cout << n->getType() << std::endl;

    Character champ;
    Character champ2("Elton");
    champ2.equip(m);
    champ2.equip(m);
    champ2.equip(m);
    champ2.equip(m);
    champ2.equip(n);

    delete first;
    delete second;
}