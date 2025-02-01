/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:12:10 by lekix             #+#    #+#             */
/*   Updated: 2025/02/01 16:03:59 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
    private:
        std::string _type;

    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &rhs);
        virtual ~WrongAnimal(void);
        WrongAnimal &operator=(WrongAnimal const &rhs);

        void setType(std::string type);
        std::string getType(void) const;

        void virtual makeSound(void) const;
};

#endif