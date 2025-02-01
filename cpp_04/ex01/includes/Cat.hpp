/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:50:13 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 17:19:30 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    private:
        Brain *_my_brain;
        
    public:
        Cat(void);
        Cat(Cat const &rhs);
        ~Cat(void);
        Cat &operator=(Cat const &rhs);

        virtual void makeSound(void) const;
};

#endif