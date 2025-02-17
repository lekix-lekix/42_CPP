/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:12:10 by lekix             #+#    #+#             */
/*   Updated: 2025/02/14 13:03:03 by kipouliq         ###   ########.fr       */
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

        void makeSound(void) const;
};

#endif