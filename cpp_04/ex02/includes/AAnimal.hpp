/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:08:42 by kipouliq          #+#    #+#             */
/*   Updated: 2025/02/01 18:49:26 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal
{
    private:
        std::string _type;

    public:
        AAnimal(void);
        AAnimal(AAnimal const &rhs);
        virtual ~AAnimal(void);
        AAnimal &operator=(AAnimal const &rhs);

        virtual void makeSound(void) const = 0;
        void    setType(std::string type);
        std::string    getType(void) const;
};

#endif