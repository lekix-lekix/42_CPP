/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:58:34 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 18:20:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AllClasses.hpp"
#include "../include/utils.h"

int main()
{
    srand(time(0));
    
    Base *random = generate();
    if (!random)
        return -1;
    
    delete random;
}