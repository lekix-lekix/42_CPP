/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:21:40 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 13:24:32 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

template<typename U>
void my_print(U const & to_print)
{
    std::cout << to_print << "\n";
}

int main( void ) 
{
    int arr[] = {0, 1, 2, 3, 4};
    iter(arr, 5, my_print<int>);

    std::cout << "\n";
    
    char arr2[] = {'c', 'o', 'u', 'c', 'o', 'u'};
    iter(arr2, 6, my_print<char>);

    std::cout << "\n";
    
    std::string arr3[] = {"quelle", "indignite", "msieur", "pujadas"};
    iter(arr3, 4, my_print<std::string>);
}
