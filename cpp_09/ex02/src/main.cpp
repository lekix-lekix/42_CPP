/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:43:22 by lekix             #+#    #+#             */
/*   Updated: 2025/04/28 22:14:45 by lekix            ###   ########.fr       */
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
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    // std::cout << std::string(argv[1]) << "\n";
}
