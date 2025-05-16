/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:44 by lekix             #+#    #+#             */
/*   Updated: 2025/05/16 18:08:21 by kipouliq         ###   ########.fr       */
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

std::vector<int> PmergeMe::copyPairsIntoVecContainer(std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<int>                    new_container;
    t_vec_pair_it                       it;
    std::vector<int>::iterator          it2;

    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            new_container.push_back(*it2);
    }
    return new_container;
}

std::list<int> PmergeMe::copyPairsIntoLstContainer(std::list<t_lst_pair> & lst_pairs)
{
    std::list<int>                      new_container;
    std::list<t_lst_pair>::iterator     it;
    std::list<int>::iterator            it2;

    for (it = lst_pairs.begin(); it != lst_pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            new_container.push_back(*it2);
    }
    return new_container;
}

std::vector<int> PmergeMe::getJacobsthalSeqVec(void)
{
    std::vector<int> jacobSeq;

    jacobSeq.push_back(0);
    jacobSeq.push_back(1);
    jacobSeq.push_back(1);
    jacobSeq.push_back(3);
    return jacobSeq;
}

std::list<int> PmergeMe::getJacobsthalSeqLst(void)
{
    std::list<int> jacobSeq;

    jacobSeq.push_back(0);
    jacobSeq.push_back(1);
    jacobSeq.push_back(1);
    jacobSeq.push_back(3);
    return jacobSeq;
}

// std::vector<int> PmergeMe::jacobsthalVecInsertion(std::vector<t_vec_pair> & vec_pairs)
// {
//     std::vector<int>                  jacobsthalSeq = getJacobsthalSeqVec();
//     std::vector<int>                  final_vec;
//     std::vector<t_vec_pair>           pending;
//     std::vector<t_vec_pair>           main;
    
//     this->prepChains(vec_pairs, main, pending);
//     while (pending.size() != 0)
//     {
//         int current_jacob_nb = jacobsthalSeq.back();
//         int prev_nb = jacobsthalSeq[jacobsthalSeq.size() - 2];
        
//         for (int i = 0; i != current_jacob_nb - prev_nb && pending.size(); i++)
//         {
//             t_vec_pair_it it = findPairByLabel(pending, "b", current_jacob_nb - i);
//             t_vec_pair_it bound = findPairByLabel(main, "a", current_jacob_nb - i);
//             if (it == pending.end())
//                 it -= 1;
//             if (bound == main.end())
//                 bound -= 1;
//             if (it->pair.back() < main.begin()->pair.back())
//                 main.insert(main.begin(), *it);
//             else if (it->pair.back() > main.back().pair.back())
//                 main.push_back(*it);
//             else
//                 this->insertMain(main, main.begin(), bound, it, 0);
//             pending.erase(it);
//         }
//         jacobsthalSeq.push_back(current_jacob_nb + 2 * jacobsthalSeq[jacobsthalSeq.size() - 2]);
//     }
//     pushBackPairs(final_vec, main);
//     pushBackPairs(final_vec, vec_pairs);
//     return final_vec;
// }

// std::list<int> PmergeMe::jacobsthalLstInsertion(std::list<t_lst_pair> & vec_pairs)
// {
//     std::list<int>                      jacobsthalSeq = getJacobsthalSeqLst();
//     std::list<int>::reverse_iterator    prev_nb_it;
//     std::list<int>                      final_lst;
//     std::list<t_lst_pair>               pending;
//     std::list<t_lst_pair>               main;

//     this->prepChains(vec_pairs, main, pending);
//     while (pending.size() != 0)
//     {
//         int current_jacob_nb = jacobsthalSeq.back();
//         prev_nb_it = jacobsthalSeq.rbegin();
//         std::advance(prev_nb_it, 1);
//         int prev_nb = *prev_nb_it;

//         for (int i = 0; i != current_jacob_nb - prev_nb && pending.size(); i++)
//         {
//             std::list<t_lst_pair>::iterator it = findPairByLabel(pending, "b", current_jacob_nb - i);
//             std::list<t_lst_pair>::iterator bound = findPairByLabel(main, "a", current_jacob_nb - i); // to fix ?
//             if (it == pending.end())
//                 std::advance(it, -1);
//             if (bound == main.end()) // to opti
//                 std::advance(bound, -1);
//             if (it->pair.back() < main.begin()->pair.back())
//                 main.insert(main.begin(), *it);
//             else if (it->pair.back() > main.back().pair.back())
//                 main.push_back(*it);
//             else
//                 this->insertMain(main, main.begin(), bound, it, 0);
//             pending.erase(it);
//         }
//         jacobsthalSeq.push_back(current_jacob_nb + 2 * prev_nb);
//     }
//     pushBackPairs(final_lst, main);
//     pushBackPairs(final_lst, vec_pairs);
//     return final_lst;
// }

std::vector<t_vec_pair> PmergeMe::makeVecPairs(std::vector<int> & container, int pair_size)
{
    std::vector<t_vec_pair>     vec_pairs;
    std::vector<int>::iterator  it = container.begin();
    
    while (it != container.end())
    {
        t_vec_pair curr_pair;
        for (int i = 0; i < pair_size && it != container.end(); i++)
        {
            curr_pair.pair.push_back(*it);
            curr_pair.bind = NULL;
            it++;
        }
        vec_pairs.push_back(curr_pair);
    }
    return vec_pairs;
}

std::list<t_lst_pair> PmergeMe::makeLstPairs(std::list<int> & container, int pair_size)
{
    std::list<t_lst_pair>              lst_pairs;
    std::list<int>::iterator           it = container.begin();
    
    while (it != container.end())
    {
        t_lst_pair curr_pair;
        for (int i = 0; i < pair_size && it != container.end(); i++)
        {
            curr_pair.pair.push_back(*it);
            curr_pair.bind = NULL;
            it++;
        }
        lst_pairs.push_back(curr_pair);
    }
    return lst_pairs;
}

void PmergeMe::recursiveVecSort(std::vector<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::vector<t_vec_pair> vec_pairs;
    
    vec_pairs = makeVecPairs(container, pair_size);
    if (pair_size != 1)
        this->sortPairs(vec_pairs, pair_size);
    container = this->copyPairsIntoVecContainer(vec_pairs);
    this->recursiveVecSort(container, pair_size * 2);
    vec_pairs = makeVecPairs(container, pair_size);
    this->labelPairs(vec_pairs, pair_size);
    container = jacobsthalInsertion<std::vector, int, t_vec_pair>(vec_pairs);
}

void PmergeMe::recursiveLstSort(std::list<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::list<t_lst_pair> lst_pairs;
    
    lst_pairs = makeLstPairs(container, pair_size);
    if (pair_size != 1)
        this->sortPairs(lst_pairs, pair_size);
    container = this->copyPairsIntoLstContainer(lst_pairs);
    this->recursiveLstSort(container, pair_size * 2);
    lst_pairs = makeLstPairs(container, pair_size);
    this->labelPairs(lst_pairs, pair_size);
    container = jacobsthalInsertion<std::list, int, t_lst_pair>(lst_pairs);
}

void PmergeMe::sortContainers(void)
{
    this->recursiveVecSort(this->_vec, 1);
    this->recursiveLstSort(this->_lst, 1);
}

std::vector<int> PmergeMe::getVecContainer(void)
{
    return this->_vec;
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