/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:21:40 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/16 18:02:26 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main( void ) 
{
    int arr[] = {0, 1, 2, 3, 4};
    iter(arr, 5, print<int>);

    std::cout << "\n";
    
    char arr2[] = {'c', 'o', 'u', 'c', 'o', 'u'};
    iter(arr2, 6, print<char>);

    std::cout << "\n";
    
    std::string arr3[] = {"quelle", "indignite", "msieur", "pujadas"};
    iter(arr3, 4, print<std::string>);

    int const arr4[] = {4, 5, 6, 7};
    iter(arr4, 4, print<int>);
}