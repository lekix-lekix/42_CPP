/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:44 by lekix             #+#    #+#             */
/*   Updated: 2025/05/08 20:58:32 by lekix            ###   ########.fr       */
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
        // if (nb_int <= 0) // to restore once done
        if (nb_int < 0)
            throw ArgsError();
        this->_lst.push_back(nb_int);
        this->_vec.push_back(nb_int);
    }
    // std::cout << isSorted(this->_vec) << "\n";
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
            std::sort(it->pair.begin(), it->pair.end());
        else if (it->pair[pair_size / 2 - 1] > it->pair[pair_size - 1])
        {
            if (static_cast<int>(it->pair.size()) != pair_size)
                break;
            first_pair = it->pair.begin();
            second_pair = it->pair.begin() + pair_size / 2;
            // std::cout << *second_pair << "\n";
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
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            new_container.push_back(*it2);
    }
    return new_container;
}

void PmergeMe::pushBackPairs(std::vector<int> & container, std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<t_vec_pair>::iterator   it;
    std::vector<int>::iterator          it2;

    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            container.push_back((*it2));
    }
}

void PmergeMe::printPairs(std::vector<t_vec_pair> & pairs)
{
    std::vector<t_vec_pair>::iterator it;
    std::vector<int>::iterator        it2;
    int                               i = 0;

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << "pair " << i << " = ";
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            std::cout << *it2 << " ";
        std::cout << "label = "<< it->label << std::endl;
        i++;
    }
}

void PmergeMe::labelPairs(std::vector<t_vec_pair> & pairs, int pair_size)
{
    std::vector<t_vec_pair>::iterator it;
    std::ostringstream                oss;
    t_vec_pair *                      prev;
    int                               i = 0;
    int                               j = 1;
    
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        if (static_cast<int>(it->pair.size()) != pair_size)
            break;
        oss.str("");
        oss.clear();
        oss << j;
        if (i % 2 == 0)
            it->label = "b" + oss.str();
        else
        {
            it->label = "a" + oss.str();
            it->bind = prev;
            j++;
        }
        i++;
        prev = &(*it);
    }
}

int  PmergeMe::jacobSthalRecursive(int nb)
{
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    return (jacobSthalRecursive(nb - 1) + 2 * jacobSthalRecursive(nb - 2));
}

void PmergeMe::getJacobsthalSeq(std::vector<int> & seq, int nb)
{
    for (int i = 0; i < nb; i++)
        seq.push_back(jacobSthalRecursive(i));
}

void printVec(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::vector<t_vec_pair>::iterator PmergeMe::findPairByLabel(std::vector<t_vec_pair> & pending, std::string c, int current_nb)
{
    std::vector<t_vec_pair>::iterator it;
    std::ostringstream                oss;
    std::string                       label;

    oss << current_nb;
    label = c + oss.str();
    // std::cout << "label = " << label << std::endl;
    for (it = pending.begin(); it != pending.end(); it++)
    {
        if (it->label == label)
            return it;
    }
    return pending.end();
}

void    PmergeMe::insertMain(std::vector<t_vec_pair> & main, std::vector<t_vec_pair>::iterator to_insert)
{
    std::vector<t_vec_pair>::iterator it = main.begin();
    t_vec_pair *                      bound = to_insert->bind;

    while (it != main.end() || &(*it) == bound)
    {
        // std::cout << "in loop it = " << it->pair.back() << std::endl;
        if (it->pair.back() > to_insert->pair.back())
        {
            // std::cout << "match : " << it->pair.back() << "\n";
            main.insert(it, *to_insert);
            return ;
        }
        it++;
    }
}

void PmergeMe::revInsertMain(std::vector<t_vec_pair> & main, std::vector<t_vec_pair>::iterator to_insert)
{
    std::vector<t_vec_pair>::reverse_iterator it = main.rbegin();
    t_vec_pair *                      bound = to_insert->bind;
    
    while (it != main.rend() || &(*it) == bound)
    {
        // std::cout << "in loop it = " << it->pair.back() << std::endl;
        if (it->pair.back() < to_insert->pair.back())
        {
            // std::cout << "match : " << it->pair.back() << "\n";
            main.insert(it.base() - 1, *to_insert);
            return ;
        }
        it++;
    }
}

std::vector<int> PmergeMe::jacobsthalInsertion(std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<int>                  jacobsthalSeq;
    std::vector<int>                  final_vec;
    std::vector<t_vec_pair>           pending;
    std::vector<t_vec_pair>           main;
    std::vector<t_vec_pair>::iterator it = vec_pairs.begin();
    std::ostringstream                oss;
    
    getJacobsthalSeq(jacobsthalSeq, 4); // get that sweet 3 first
    // std::cout << "vec_pair size = " << vec_pairs.size() << "\n";
    while (it != vec_pairs.end())
    {
        // std::cout << "curr = ";
        // printVec((*it).pair);
        // std::cout << std::endl;
        if ((*it).label.size() == 0) 
        {
            it++;
            continue;
        }
        else
        {
            if ((*it).label == "b1" || (*it).label[0] == 'a')
                main.push_back(*it);
            else if ((*it).label[0] == 'b')
                pending.push_back(*it);
        }
        vec_pairs.erase(it);
        it = vec_pairs.begin();
    }
    // std::cout << "MAIN ====\n";
    // printPairs(main);
    // std::cout << "PENDING ====\n";
    // printPairs(pending);
    // std::cout << "NON PARTICIPATING ====\n ";
    // printPairs(vec_pairs);
    while (pending.size() != 0)
    {
        int current_jacob_nb = jacobsthalSeq.back();
        int prev_nb = jacobsthalSeq[jacobsthalSeq.size() - 2];
        int iter = current_jacob_nb - prev_nb;
        // std::cout << "current jaacob nb = " << current_jacob_nb << "prev_nb = " << prev_nb << std::endl;
        for (int i = 0; i != iter && pending.size(); i++)
        {
            std::vector<t_vec_pair>::iterator it = findPairByLabel(pending, "b", current_jacob_nb - i);
            if (it == pending.end()) // not sure about this
            {
                this->revInsertMain(main, pending.begin());
                pending.erase(pending.begin());
            }
            else
            {
                this->insertMain(main, it);
                pending.erase(it);
            }
            // current_nb -= 1;
        }
        // int new_jacob_nb = current_jacob_nb + 2 * prev_nb;
        // std::cout << "new nb = " << new_jacob_nb << "\n";
        jacobsthalSeq.push_back(current_jacob_nb + 2 * jacobsthalSeq[jacobsthalSeq.size() - 2]);
    }
    pushBackPairs(final_vec, main);
    pushBackPairs(final_vec, vec_pairs);
    return final_vec;
}


std::vector<t_vec_pair> PmergeMe::makePairs(std::vector<int> & container, int pair_size)
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

void PmergeMe::recursiveVecSort(std::vector<int> & container, int pair_size, int level)
{
    // std::cout << "level = " << level << "\n";
    if (container.size() / pair_size <= 1)
    {
        // std::cout << "return condition met\n";
        return ;
    }
    std::vector<t_vec_pair> vec_pairs;
    vec_pairs = makePairs(container, pair_size);
    // this->printPairs(vec_pairs);
    // if (pair)
    this->sortVecPairs(vec_pairs, pair_size);
    // this->printPairs(vec_pairs);
    container = this->copyPairsIntoContainer(vec_pairs);
    // this->printContainers();
    this->recursiveVecSort(container, pair_size * 2, level + 1);
    // std::cout << "level = " << level + 1 << "\n";
    vec_pairs = makePairs(container, pair_size);
    this->labelPairs(vec_pairs, pair_size);
    container = jacobsthalInsertion(vec_pairs);
    // std::cout << "coucou\n";
    // vec_pairs = makePairs(container, pair_size);
    // container = copyPairsIntoContainer(vec_pairs);
    // std::cout << "final container ====\n";
    // printVec(container);
}

void PmergeMe::sortContainers(void)
{
    this->recursiveVecSort(this->_vec, 1, 1);
    // this->recursiveVecSort(this->_vec, 1, 1);
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
    // for (lst_it = this->_lst.begin(); lst_it != this->_lst.end(); lst_it++)
    //     std::cout << *lst_it << " ";
    // std::cout << std::endl;
}

const char *PmergeMe::ArgsError::what(void) const throw()
{
    return ("Error\n");
}