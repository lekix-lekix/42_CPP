/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:58:34 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 12:40:46 by kipouliq         ###   ########.fr       */
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
    
    identify(random);
    
    Base *random2 = generate();
    if (!random2)
    {
        delete random;
        return -1;
    }
    Base &random2_ref = *random2;
    identify(random2_ref);
    
    delete random;
    delete random2;
}