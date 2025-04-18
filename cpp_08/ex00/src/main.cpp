/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:57 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 17:47:00 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main ()
{
    std::vector<int> arr;
    std::list<int> lst;
    std::vector<int>::const_iterator it;
    std::list<int>::const_iterator it2;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);


    it = easyfind(arr, 3);
    if (it != arr.end())
        std::cout << *(it = easyfind(arr, 3)) << "\n";
    it = easyfind(arr, 0);
    if (it != arr.end())
        std::cout << *(it = easyfind(arr, 10)) << "\n";

    it2 = easyfind(lst, 3);
    if (it2 != lst.end())
        std::cout << *(it2 = easyfind(lst, 3)) << "\n";
    it2 = easyfind(lst, 0);
    if (it2 != lst.end())
        std::cout << *(it2 = easyfind(lst, 10)) << "\n";
}