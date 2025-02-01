/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:17:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 18:52:28 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
    // AAnimal *animal_tab[20];

    // for (int i = 0; i < 20; i++)
    // {
    //     if (i < 10)
    //         animal_tab[i] = new Dog();
    //     else
    //         animal_tab[i] = new Cat();
    // }

    // for (int i = 0; i < 20; i++)
    //     delete animal_tab[i];

    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    delete j; // should not create a leak
    delete i;
}
