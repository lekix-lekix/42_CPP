/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:43:48 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 12:47:08 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include "../include/Serializer.hpp"

int main ()
{
    Data my_data_obj;

    my_data_obj.data_int = 10;
    my_data_obj.data_string = "coucou les amis";

    std::cout << "addr pre conversion = " << &my_data_obj << "\n";
    uintptr_t addr = Serializer::serialize(&my_data_obj);
    std::cout << "addr post conversion = " << addr << "\n";

    Data *my_data_obj_ptr = Serializer::deserialize(addr);
    std::cout << "int = " << my_data_obj_ptr->data_int << "\n";
    std::cout << "string = " << my_data_obj_ptr->data_string << "\n";
}
