/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:43:22 by lekix             #+#    #+#             */
/*   Updated: 2025/05/22 14:51:14 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error\n";
        return -1;
    }
    
    PmergeMe to_sort;
    try
    {
        to_sort.loadContainers(argv + 1);
        std::cout << "Before : ";
        to_sort.printContainer(to_sort.getVecContainer());
        if (!to_sort.isSorted(to_sort.getVecContainer()))
            to_sort.sortContainers();
        std::cout << "After : ";
        to_sort.printContainer(to_sort.getVecContainer());
        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Time to process a range of " << to_sort.getVecContainer().size() << " elements with std::vector : " << to_sort.getVecTime() << " us\n";
        std::cout << "Time to process a range of " << to_sort.getLstContainer().size() << " elements with std::list   : " << to_sort.getLstTime() << " us\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    // std::cout << std::string(argv[1]) << "\n";
}
