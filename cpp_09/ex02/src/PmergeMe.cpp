/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:44 by lekix             #+#    #+#             */
/*   Updated: 2025/05/17 20:58:56 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

/************ ORTHODOX CANONICAL FORM ************/

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & other) { *this = other; }

PmergeMe const & PmergeMe::operator=(PmergeMe const & rhs)
{
    this->_lst = rhs._lst;
    this->_vec = rhs._vec;
    return *this;
}

/*************************************************/

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
        if (nb_int <= 0)
            throw ArgsError();
        this->_lst.push_back(nb_int);
        this->_vec.push_back(nb_int);
    }
}

void PmergeMe::recursiveVecSort(std::vector<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::vector<t_vec_pair> vec_pairs;
    
    vec_pairs = makePairs<std::vector, int, t_vec_pair>(container, pair_size);
    if (pair_size != 1)
        this->sortPairs(vec_pairs, pair_size);
    container = this->copyPairsIntoContainer<std::vector, int, t_vec_pair>(vec_pairs);
    this->recursiveVecSort(container, pair_size * 2);
    vec_pairs = makePairs<std::vector, int, t_vec_pair>(container, pair_size);
    this->labelPairs(vec_pairs, pair_size);
    container = jacobsthalInsertion<std::vector, int, t_vec_pair>(vec_pairs);
}

void PmergeMe::recursiveLstSort(std::list<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::list<t_lst_pair> lst_pairs;
    
    lst_pairs = makePairs<std::list, int, t_lst_pair>(container, pair_size);
    if (pair_size != 1)
        this->sortPairs(lst_pairs, pair_size);
    container = this->copyPairsIntoContainer<std::list, int, t_lst_pair>(lst_pairs);
    this->recursiveLstSort(container, pair_size * 2);
    lst_pairs = makePairs<std::list, int, t_lst_pair>(container, pair_size);
    this->labelPairs(lst_pairs, pair_size);
    container = jacobsthalInsertion<std::list, int, t_lst_pair>(lst_pairs);
}

void PmergeMe::sortContainers(void)
{
    std::clock_t start;
    std::clock_t end;
    
    start = std::clock();
    this->recursiveVecSort(this->_vec, 1);
    end = std::clock();
    this->time_vec = double(end - start) / CLOCKS_PER_SEC * 1e6;
    start = std::clock();
    this->recursiveLstSort(this->_lst, 1);
    end = std::clock();
    this->time_lst = double(end - start) / CLOCKS_PER_SEC * 1e6;
}

std::vector<int> & PmergeMe::getVecContainer(void)
{
    return this->_vec;
}

std::list<int> & PmergeMe::getLstContainer(void)
{
    return this->_lst;
}

double PmergeMe::getVecTime(void)
{
    return this->time_vec;
}

double PmergeMe::getLstTime(void)
{
    return this->time_lst;
}

void printVec(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

const char *PmergeMe::ArgsError::what(void) const throw()
{
    return ("Error\n");
}