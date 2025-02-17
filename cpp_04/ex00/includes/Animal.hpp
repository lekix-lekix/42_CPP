/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:08:42 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/14 12:51:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
    private:
        std::string _type;

    public:
        Animal(void);
        Animal(Animal const &rhs);
        virtual ~Animal(void);
        Animal &operator=(Animal const &rhs);

        virtual void makeSound(void) const;
        void setType(std::string type);
        std::string getType(void) const;
};

#endif