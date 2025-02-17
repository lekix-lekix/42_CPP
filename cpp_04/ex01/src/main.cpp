/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:17:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/17 17:48:37 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
    try {
        
        Dog basic;
        Dog tmp = basic;
        
        Cat other_basic;
        Cat tmp2 = other_basic;
        
        Brain basic2;
        Brain tmp3 = basic2;

        Animal *animal_tab[20];

        for (int i = 0; i < 20; i++)
        {
            if (i < 10)
                animal_tab[i] = new Dog();
            else
                animal_tab[i] = new Cat();
        }
        for (int i = 0; i < 20; i++)
            delete animal_tab[i];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Bad alloc" << std::endl;
        return -1;
    }
    try
    {
        const Animal *j = new Dog();
        delete j; // should not create a leak
    }
    catch (std::bad_alloc)
    {
        return -1;
    }
    try
    {
        const Animal *i = new Cat();
        delete i;
    }
    catch (std::bad_alloc)
    {
        return -1;
    }
}
