/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:17:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/17 16:49:51 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include <new>

int main()
{
    const Animal *first = new(std::nothrow) Animal();
    if (!first)
        return (-1);
    std::cout << "first : " << first->getType() << std::endl;
    first->makeSound();

    const Animal *second = new(std::nothrow) Cat();
    if (!second)
        return (delete(first), -1);
    std::cout << "second : " << second->getType() << std::endl;
    second->makeSound();

    const Animal *third = new(std::nothrow) Dog();
    if (!third)
        return (delete(first), delete(second), -1);
    std::cout << "third : " << third->getType() << std::endl;
    third->makeSound();

    const WrongAnimal *fourth = new(std::nothrow) WrongCat();
    if (!fourth)
        return (delete(first), delete(second), delete(third), -1);
    std::cout << "fourth : " << fourth->getType() << std::endl;
    fourth->makeSound();

    delete first;
    delete second;
    delete third;
    delete fourth;
}

// int main()
// {
//     const Animal *meta = new(std::nothrow) Animal();
//     if (!meta)
//         return (-1); 
//     const Animal *j = new(std::nothrow) Dog();
//     if (!j)
//         return (delete(meta), -1);
//     const Animal *i = new Cat();
//     if (!i)
//         return (delete(meta), delete(j), -1);
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     j->makeSound();
//     i->makeSound(); // will output the cat sound!
//     meta->makeSound();

//     delete meta;
//     delete j;
//     delete i;
//     return 0;
// }
