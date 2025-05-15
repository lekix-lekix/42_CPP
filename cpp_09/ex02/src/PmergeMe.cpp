/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:36:44 by lekix             #+#    #+#             */
/*   Updated: 2025/05/15 19:05:33 by kipouliq         ###   ########.fr       */
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

/************* VECTORS *************/

void PmergeMe::sortVecPairs(std::vector<t_vec_pair> & vec_pairs, int pair_size)
{
    t_vec_pair_it                       it;
    std::vector<int>::iterator          it2;
    std::vector<int>::iterator          first_pair;
    std::vector<int>::iterator          second_pair;
    int                                 middle;

    middle = pair_size / 2 - 1;
    for (it = vec_pairs.begin(); it != vec_pairs.end() && pair_size == (int)it->pair.size(); it++)
    {
        if (*(it->pair.begin() + middle) > it->pair.back())
        {
            if (static_cast<int>(it->pair.size()) != pair_size)
                break;
            first_pair = it->pair.begin();
            second_pair = it->pair.begin() + middle;
            std::swap_ranges(it->pair.begin(), first_pair + pair_size / 2, first_pair + pair_size / 2);
        }
    }
}

void PmergeMe::sortLstPairs(std::list<t_lst_pair> & lst_pairs, int pair_size)
{
    std::list<t_lst_pair>::iterator     it;
    std::list<int>::iterator            it2;
    std::list<int>::iterator            first_pair;
    std::list<int>::iterator            second_pair;
    int                                 middle;

    middle = pair_size / 2 - 1;
    for (it = lst_pairs.begin(); it != lst_pairs.end() && pair_size == (int)it->pair.size(); it++)
    {
        if (*(it->pair.begin() + middle) > it->pair.back())
        {
            if (static_cast<int>(it->pair.size()) != pair_size)
                break;
            first_pair = it->pair.begin();
            second_pair = it->pair.begin() + middle;
            std::swap_ranges(it->pair.begin(), first_pair + pair_size / 2, first_pair + pair_size / 2);
        }
    }
}


std::vector<int> PmergeMe::copyPairsIntoVecContainer(std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<int>                    new_container;
    t_vec_pair_it   it;
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
    t_vec_pair_it   it;
    std::vector<int>::iterator          it2;

    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            container.push_back((*it2));
    }
}

void PmergeMe::labelPairs(std::vector<t_vec_pair> & pairs, int pair_size)
{
    t_vec_pair_it it;
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
        {
            it->label = "b" + oss.str();
            it->bind = prev;
        }
        else
        {
            it->label = "a" + oss.str();
            j++;
        }
        i++;
        prev = &(*it);
    }
}

std::vector<int> PmergeMe::getJacobsthalSeq(void)
{
    std::vector<int> jacobSeq;

    jacobSeq.push_back(0);
    jacobSeq.push_back(1);
    jacobSeq.push_back(1);
    jacobSeq.push_back(3);
    return jacobSeq;
}

t_vec_pair_it PmergeMe::findPairByLabel(std::vector<t_vec_pair> & pending, std::string c, int current_nb)
{
    t_vec_pair_it it;
    std::ostringstream                oss;
    std::string                       label;

    oss << current_nb;
    label = c + oss.str();
    for (it = pending.begin(); it != pending.end(); it++)
    {
        if (it->label == label)
            return it;
    }
    return pending.end();
}

void    PmergeMe::insertMain(std::vector<t_vec_pair> & main, t_vec_pair_it begin, t_vec_pair_it end, t_vec_pair_it to_insert, int level)
{
    int size = std::distance(begin, end);
    int middle = size / 2;
    
    if (to_insert->pair.back() > (begin + middle)->pair.back() && to_insert->pair.back() < (begin + middle + 1)->pair.back())
    {
        main.insert(begin + middle + 1, *to_insert);
        return ;
    }
    if (to_insert->pair.back() < (begin + middle)->pair.back())
    {
        insertMain(main, main.begin(), begin + middle, to_insert, level + 1);
    }
    else
        insertMain(main, begin + middle, end, to_insert, level + 1);
}

void    PmergeMe::prepChains(std::vector<t_vec_pair> & vec_pairs, std::vector<t_vec_pair> & main, std::vector<t_vec_pair> & pending)
{
    t_vec_pair_it it = vec_pairs.begin();
    
    while (it != vec_pairs.end())
    {
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
}

std::vector<int> PmergeMe::jacobsthalInsertion(std::vector<t_vec_pair> & vec_pairs)
{
    std::vector<int>                  jacobsthalSeq = getJacobsthalSeq();
    std::vector<int>                  final_vec;
    std::vector<t_vec_pair>           pending;
    std::vector<t_vec_pair>           main;
    
    this->prepChains(vec_pairs, main, pending);
    while (pending.size() != 0)
    {
        int current_jacob_nb = jacobsthalSeq.back();
        int prev_nb = jacobsthalSeq[jacobsthalSeq.size() - 2];
        
        for (int i = 0; i != current_jacob_nb - prev_nb && pending.size(); i++)
        {
            t_vec_pair_it it = findPairByLabel(pending, "b", current_jacob_nb - i);
            t_vec_pair_it bound = findPairByLabel(main, "a", current_jacob_nb - i);
            if (it == pending.end())
                it -= 1;
            if (bound == main.end())
                bound -= 1;
            if (it->pair.back() < main.begin()->pair.back())
                main.insert(main.begin(), *it);
            else if (it->pair.back() > main.back().pair.back())
                main.push_back(*it);
            else
                this->insertMain(main, main.begin(), bound, it, 0);
            pending.erase(it);
        }
        jacobsthalSeq.push_back(current_jacob_nb + 2 * jacobsthalSeq[jacobsthalSeq.size() - 2]);
    }
    pushBackPairs(final_vec, main);
    pushBackPairs(final_vec, vec_pairs);
    return final_vec;
}

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
}

void PmergeMe::recursiveVecSort(std::vector<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::vector<t_vec_pair> vec_pairs;
    vec_pairs = makeVecPairs(container, pair_size);
    if (pair_size != 1)
        this->sortVecPairs(vec_pairs, pair_size);
    container = this->copyPairsIntoVecContainer(vec_pairs);
    this->recursiveVecSort(container, pair_size * 2);
    vec_pairs = makeVecPairs(container, pair_size);
    this->labelPairs(vec_pairs, pair_size);
    container = jacobsthalInsertion(vec_pairs);
}


void PmergeMe::recursiveLstSort(std::list<int> & container, int pair_size)
{
    if ((container.size() / pair_size < 1) && pair_size != 1)
        return ;

    std::list<t_lst_pair> lst_pairs;
    lst_pairs = makeLstPairs(container, pair_size);
    if (pair_size != 1)
        this->sortLstPairs(lst_pairs, pair_size);
    
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
    // for (lst_it = this->_lst.begin(); lst_it != this->_lst.end(); lst_it++)
    //     std::cout << *lst_it << " ";
    // std::cout << std::endl;
}

void printVec(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printPairs(std::vector<t_vec_pair> & pairs)
{
    t_vec_pair_it it;
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

const char *PmergeMe::ArgsError::what(void) const throw()
{
    return ("Error\n");
}