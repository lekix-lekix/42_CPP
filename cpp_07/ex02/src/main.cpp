/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:21:40 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 14:32:30 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <cstdlib>
#include <time.h>

int main ()
{
    srand(time(0));

    Array<int> empty_arr;

    std::cout << "empty arr size = " << empty_arr.size() << "\n";
    try
    {
        std::cout << empty_arr[2] << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }

    Array<int> arr(5);

    for (int i = 0; i < 5; i++)
        arr[i] = i;

    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "\n";

    Array<char> arr2(100);

    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = rand() % 256;
    
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i];
    std::cout << "\n";
    std::cout << "==========\n";
    
    Array<char> arr_cpy = arr2;
    
    for (unsigned int i = 0; i < arr_cpy.size(); i++)
        std::cout << arr2[i];
    std::cout << "\n";
    std::cout << "==========\n";
    for (unsigned int i = 0; i < arr_cpy.size(); i++)
        std::cout << arr_cpy[i];
    std::cout << "\n";

    Array<std::string> arr3(5);
    arr3[0] = "Quelle indignite\n";
    arr3[1] = "msieur pujadas\n";
    arr3[2] = "c'est pas l'idee\n";
    arr3[3] = "que je me faisais\n";
    arr3[4] = "du service public.\n";

    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << "\n";
}
