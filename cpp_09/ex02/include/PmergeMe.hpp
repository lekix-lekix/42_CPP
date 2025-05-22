/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:35:31 by lekix             #+#    #+#             */
/*   Updated: 2025/05/22 14:50:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>
#include <exception>

typedef struct s_vec_pair
{
    typedef std::vector<int> pair_type;
    std::vector<int>         pair;
    std::string              label;
    struct s_vec_pair *      bind;
}   t_vec_pair;

typedef struct s_lst_pair
{
    typedef std::list<int>   pair_type;
    std::list<int>           pair;
    std::string              label;
    struct s_lst_pair *      bind;
}   t_lst_pair;

typedef std::vector<t_vec_pair>::iterator t_vec_pair_it;

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::list<int>   _lst;
        double           time_vec;
        double           time_lst;

    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(PmergeMe const & other);
        PmergeMe const &operator=(PmergeMe const & rhs);

        void                                 loadContainers(char **args);
        std::vector<int> &                   getVecContainer(void);
        std::list<int> &                     getLstContainer(void);
        double                               getVecTime(void);
        double                               getLstTime(void);

        void                                 sortContainers(void);
        void                                 recursiveLstSort(std::list<int> & container, int pair_size);
        void                                 recursiveVecSort(std::vector<int> & container, int pair_size);

        template<template<typename, typename> class T, typename U, typename V>
        T<U, std::allocator<U> > jacobsthalInsertion(T<V, std::allocator<V> >& vec_pairs);
        
        template<typename T>
        bool isSorted(T container);

        template<typename T>
        void printPairs(T & pairs);

        template<typename T>
        void printContainer(T & container);

        template<typename T>
        void labelPairs(T & pairs, int pair_size);

        template<typename T>
        void getJacobsthalSeq(T & container);

        template<typename T>
        void prepChains(T & pairs, T & main, T & pending);

        template<template<typename, typename> class T, typename U>
        typename T<U, std::allocator<U> >::iterator findPairByLabel(T<U, std::allocator<U> > & pending, std::string c, int current_nb);

        template<typename T>
        void insertMain(T & main, typename T::iterator begin, typename T::iterator end, typename T::iterator to_insert, int level);

        template<template<typename, typename> class T, typename U, typename V>
        void pushBackPairs(T<U, std::allocator<U> > & container, V & vec_pairs);

        template<template<typename, typename> class T, typename U, typename V>
        T<U, std::allocator<U> > copyPairsIntoContainer(T<V, std::allocator<V> > & pairs);

        template<template<typename, typename> class T, typename U, typename V>
        T<V, std::allocator<V> > makePairs(T<U, std::allocator<U> > & container, int pair_size);
        
        template<typename T>
        void sortPairs(T & pairs, int pair_size);
        
    class ArgsError : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

template<typename T>
bool PmergeMe::isSorted(T container)
{
    typename T::iterator it;
    typename T::iterator next = container.begin();

    for (it = container.begin(); it != container.end(); it++)
    {
        next = it;
        std::advance(next, 1);
        if (next != container.end() && *it > *next)
            return false;
    }
    return true;
}

template<typename T>
void PmergeMe::printPairs(T & pairs)
{
    typename T::iterator it;
    int                  i = 0;
    
    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        std::cout << "pair " << i << " = ";
        typename T::value_type::pair_type::iterator it2;
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            std::cout << *it2 << " ";
        std::cout << "label = " << it->label << std::endl;
        i++;
    }
}

template<typename T>
void PmergeMe::printContainer(T & container)
{
    typename T::iterator it;
    typename T::iterator last = container.end();

    std::advance(last, -1);
    for (it = container.begin(); it != container.end(); it++)
    {
        if (it != last)
            std::cout << *it << " ";
        else
            std::cout << *it << "\n";
    }    
}

template<typename T>
void PmergeMe::labelPairs(T & pairs, int pair_size)
{
    typename T::iterator                  it;
    typename T::value_type *              prev;
    std::ostringstream                    oss;
    int                                   i = 0;
    int                                   j = 1;
    
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

template<typename T>
void PmergeMe::prepChains(T & pairs, T & main, T & pending)
{
    typename T::iterator it = pairs.begin();
    
    while (it != pairs.end())
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
        pairs.erase(it);
        it = pairs.begin();
    }
}

template<template<typename, typename> class T, typename U>
typename T<U, std::allocator<U> >::iterator PmergeMe::findPairByLabel(T<U, std::allocator<U> > & pending, std::string c, int current_nb)
{
    typename T<U, std::allocator<U> >::iterator it;
    std::ostringstream                          oss;
    std::string                                 label;

    oss << current_nb;
    label = c + oss.str();
    for (it = pending.begin(); it != pending.end(); it++)
    {
        if (it->label == label)
            return it;
    }
    return pending.end();
}

template<typename T>
void PmergeMe::insertMain(T & main, typename T::iterator begin, typename T::iterator end, typename T::iterator to_insert, int level)
{
    int size = std::distance(begin, end);
    int middle = size / 2;
    typename T::iterator insert_idx = begin;
    typename T::iterator insert_idx_plus_one = begin;

    std::advance(insert_idx, middle);
    std::advance(insert_idx_plus_one, middle + 1);
    if (to_insert->pair.back() > insert_idx->pair.back() && to_insert->pair.back() < insert_idx_plus_one->pair.back())
    {
        main.insert(insert_idx_plus_one, *to_insert);
        return ;
    }
    if (to_insert->pair.back() < insert_idx->pair.back())
        insertMain(main, main.begin(), insert_idx, to_insert, level + 1);
    else
        insertMain(main, insert_idx, end, to_insert, level + 1);
}

template<template<typename, typename> class T, typename U, typename V>
void PmergeMe::pushBackPairs(T<U, std::allocator<U> > & container, V & vec_pairs)
{
    typename V::iterator                                 it;
    typename T<U, std::allocator<U> >::iterator          it2;

    for (it = vec_pairs.begin(); it != vec_pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            container.push_back((*it2));
    }
}

template<template<typename, typename> class T, typename U, typename V>
T<U, std::allocator<U> > PmergeMe::copyPairsIntoContainer(T<V, std::allocator<V> > & pairs)
{
    T<U, std::allocator<U> >                    new_container;
    typename T<V, std::allocator<V> >::iterator it;
    typename T<U, std::allocator<U> >::iterator it2;

    for (it = pairs.begin(); it != pairs.end(); it++)
    {
        for (it2 = it->pair.begin(); it2 != it->pair.end(); it2++)
            new_container.push_back(*it2);
    }
    return new_container;
}

template<typename T>
void PmergeMe::sortPairs(T & pairs, int pair_size)
{
    typename T::iterator                                 it;
    typename T::value_type::pair_type::iterator          it2;
    typename T::value_type::pair_type::iterator          first_pair;
    typename T::value_type::pair_type::iterator          second_pair;
    int                                                  middle;

    middle = pair_size / 2 - 1;
    for (it = pairs.begin(); it != pairs.end() && pair_size == (int)it->pair.size(); it++)
    {
        first_pair = it->pair.begin();
        second_pair = it->pair.begin();
        std::advance(second_pair, middle);
        if (*second_pair > it->pair.back()) // second_pair == last element of first pair
        {
            if (static_cast<int>(it->pair.size()) != pair_size)
                break;
            std::advance(second_pair, 1); // now first element of second pair
            std::swap_ranges(first_pair, second_pair, second_pair);
        }
    }
}

template<typename T>
void PmergeMe::getJacobsthalSeq(T & container)
{
    container.push_back(0);
    container.push_back(1);
    container.push_back(1);
    container.push_back(3);
}

template<template<typename, typename> class T, typename U, typename V>
T<V, std::allocator<V> > PmergeMe::makePairs(T<U, std::allocator<U> > & container, int pair_size)
{
    T<V, std::allocator<V> >                    pairs;
    typename T<U, std::allocator<U> >::iterator it = container.begin();

    while (it != container.end())
    {
        typename T<V, std::allocator<V> >::value_type curr_pair;
        for (int i = 0; i < pair_size && it != container.end(); i++)
        {
            curr_pair.pair.push_back(*it);
            curr_pair.bind = NULL;
            it++;
        }
        pairs.push_back(curr_pair);
    }
    return pairs;
}

template<template<typename, typename> class T, typename U, typename V>
T<U, std::allocator<U> > PmergeMe::jacobsthalInsertion(T<V, std::allocator<V> >& vec_pairs)
{
    T<U, std::allocator<U> >                                jacobsthalSeq;
    T<U, std::allocator<U> >                                final_container;
    T<V, std::allocator<V> >                                pending;
    T<V, std::allocator<V> >                                main;
    typename T<U, std::allocator<U> >::reverse_iterator     prev_nb_it;
    
    this->getJacobsthalSeq(jacobsthalSeq);
    this->prepChains(vec_pairs, main, pending);
    while (pending.size() != 0)
    {
        int current_jacob_nb = jacobsthalSeq.back();
        prev_nb_it = jacobsthalSeq.rbegin();
        std::advance(prev_nb_it, 1);
        int prev_nb = *prev_nb_it;

        for (int i = 0; i != current_jacob_nb - prev_nb && pending.size(); i++)
        {
            typename T<V, std::allocator<V> >::iterator it = findPairByLabel(pending, "b", current_jacob_nb - i);
            typename T<V, std::allocator<V> >::iterator bound = findPairByLabel(main, "a", current_jacob_nb - i);
            if (it == pending.end())
                std::advance(it, -1);
            if (bound == main.end())
                std::advance(bound, -1);
            if (it->pair.back() < main.begin()->pair.back())
                main.insert(main.begin(), *it);
            else if (it->pair.back() > main.back().pair.back())
                main.push_back(*it);
            else
                this->insertMain(main, main.begin(), bound, it, 0);
            pending.erase(it);
        }
        jacobsthalSeq.push_back(current_jacob_nb + 2 * prev_nb);
    }
    pushBackPairs(final_container, main);
    pushBackPairs(final_container, vec_pairs);
    return final_container;
}

#endif