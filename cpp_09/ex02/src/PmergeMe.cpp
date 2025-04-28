/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:44 by lekix             #+#    #+#             */
/*   Updated: 2025/04/29 01:25:26 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & other) { *this = other; }

PmergeMe const & PmergeMe::operator=(PmergeMe const & rhs)
{
    this->_lst = rhs._lst;
    this->_vec = rhs._vec;
    return *this;
}

void PmergeMe::loadContainers(char **args)
{
    std::string nb_str;
    int         nb_int;

    for (int i = 0; args[i]; i++)
    {
        nb_str = args[i];
        if (nb_str.length() == 0 || nb_str.find_first_not_of("0123456789") != nb_str.npos)
            throw ArgsError();
        nb_int = atoi(nb_str.c_str());
        // if (nb_int <= 0)
        if (nb_int < 0)
            throw ArgsError();
        this->_lst.push_back(nb_int);
        this->_vec.push_back(nb_int);
    }
    std::cout << isSorted(this->_vec) << "\n";
}

void PmergeMe::sortVecPairs(std::vector<t_vec_pair> & vec_pairs, int pair_size)
{
    std::vector<t_vec_pair>::iterator   it;
    std::vector<int>::iterator          it2;
    std::vector<int>::iterator          first_pair;
    std::vector<int>::iterator          second_pair;    

    (void) pair_size;
    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        if (pair_size == 2)
            std::sort((*it).pair.begin(), (*it).pair.end());
        else if ((*it).pair[pair_size / 2 - 1] > (*it).pair[pair_size - 1])
        {
            if (static_cast<int>((*it).pair.size()) != pair_size)
                break;
            first_pair = (*it).pair.begin();
            second_pair = (*it).pair.begin() + pair_size / 2;
            std::cout << *second_pair << "\n";
            std::swap_ranges(first_pair, first_pair + pair_size / 2, second_pair);
        }
    }
}

std::vector<int> PmergeMe::copyPairsIntoContainer(std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<int>                    new_container;
    std::vector<t_vec_pair>::iterator   it;
    std::vector<int>::iterator          it2;

    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        for (it2 = (*it).pair.begin(); it2 != (*it).pair.end(); it2++)
            new_container.push_back((*it2));
    }
    return new_container;
}

void PmergeMe::printPairs(std::vector<t_vec_pair> & pairs)
{
    std::vector<t_vec_pair>::iterator it;
    std::vector<int>::iterator        it2;
    int                               i = 0;

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << "pair " << i << " = ";
        for (it2 = (*it).pair.begin(); it2 != (*it).pair.end(); it2++)
            std::cout << (*it2) << " ";
        std::cout << std::endl;
        i++;
    }
}

void PmergeMe::labelPairs(std::vector<t_vec_pair> & pairs, int pair_size)
{
    std::vector<t_vec_pair>::iterator it;
    int                               i = 0;

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        if (static_cast<int>((*it).pair.size()) != pair_size)
            break;
        if (i % 2 == 0)
            (*it).label = "b" + i;
        else
            (*it).label = "a" + i; 
    }
}

void PmergeMe::recursiveVecSort(std::vector<int> & container, int pair_size, int level)
{
    std::cout << "level = " << level << "\n";
    if (container.size() / pair_size <= 1)
    {
        std::cout << "return condition met\n";
        return ;
    }
    
    std::vector<t_vec_pair>     vec_pairs;
    std::vector<int>::iterator  it = container.begin();
    
    while (it != container.end())
    {
        t_vec_pair curr_pair;
        for (int i = 0; i < pair_size && it != container.end(); i++)
        {
            curr_pair.pair.push_back(*it);
            it++;
        }
        vec_pairs.push_back(curr_pair);
    }
    this->printPairs(vec_pairs);
    this->sortVecPairs(vec_pairs, pair_size);
    this->printPairs(vec_pairs);
    container = this->copyPairsIntoContainer(vec_pairs);
    this->printContainers();
    this->recursiveVecSort(container, pair_size * 2, level + 1);
    this->labelPairs(vec_pairs, pair_size);
}

void PmergeMe::sortContainers(void)
{
    this->recursiveVecSort(this->_vec, 2, 1);
}

template<typename T>
bool PmergeMe::isSorted(T container)
{
    typename T::iterator it;

    for (it = container.begin(); it != container.end(); it++)
    {
        if (it != container.end() - 1 && *it > *(it + 1))
            return false;
    }
    return true;
}

void PmergeMe::printContainers(void)
{
    std::vector<int>::iterator vec_it;
    std::list<int>::iterator   lst_it;

    std::cout << "vec = ";
    for (vec_it = this->_vec.begin(); vec_it != this->_vec.end(); vec_it++)
        std::cout << *vec_it << " ";
    std::cout << std::endl << "lst = ";
    for (lst_it = this->_lst.begin(); lst_it != this->_lst.end(); lst_it++)
        std::cout << *lst_it << " ";
    std::cout << std::endl;
}

const char *PmergeMe::ArgsError::what(void) const throw()
{
    return ("Error\n");
}