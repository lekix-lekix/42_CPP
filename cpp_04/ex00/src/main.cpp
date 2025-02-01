/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:17:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 15:57:22 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    // const Animal *meta = new Animal();
    // const Animal *marcelle = new Dog();

    // std::cout << marcelle->getType() << std::endl;
    // std::cout << meta->getType() << std::endl;

    // meta->makeSound();
    // marcelle->makeSound();

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal *meta_b = new WrongAnimal();
    const WrongAnimal *l = new WrongCat();
    std::cout << l->getType() << " " << std::endl;
    l->makeSound(); // will output the cat sound!
    meta_b->makeSound();

    delete meta;
    delete meta_b;
    delete i;
    delete j;
    delete l;
}
