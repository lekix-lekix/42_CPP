/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:24:19 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/17 17:15:19 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    private:
        Brain *_my_brain;

    public:
        Dog(void);
        Dog(Dog const &rhs);
        ~Dog(void);
        Dog &operator=(Dog const &rhs);

        virtual void makeSound(void) const;
};

#endif