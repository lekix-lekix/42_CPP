/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:43:22 by lekix             #+#    #+#             */
/*   Updated: 2025/05/09 17:24:48 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
        return -1;
    
    PmergeMe to_sort;
    try
    {
        to_sort.loadContainers(argv + 1);
        to_sort.sortContainers();
        to_sort.printContainers();
        if (to_sort.isSorted(to_sort.getVecContainer()))
            std::cout << "Its sorted baby!\n";
        else
            std::cout << "Its not sorted dumbass\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    // std::cout << std::string(argv[1]) << "\n";
}
