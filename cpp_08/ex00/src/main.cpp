/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:57 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/23 12:30:13 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>

int main ()
{
    std::vector<int> arr;
    std::list<int> lst;
    std::deque<int> deque;
    
    std::vector<int>::const_iterator it;
    std::list<int>::const_iterator it2;
    std::deque<int>::const_iterator it3;

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

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);

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

    it3 = easyfind(deque, 3);
    if (it3 != deque.end())
        std::cout << *(it3 = easyfind(deque, 3)) << "\n";
}