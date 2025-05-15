/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:35:31 by lekix             #+#    #+#             */
/*   Updated: 2025/05/15 18:54:29 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>
#include <exception>

typedef struct s_vec_pair
{
    std::vector<int>        pair;
    std::string             label;
    struct s_vec_pair *     bind;
}   t_vec_pair;

typedef struct s_lst_pair
{
    std::list<int>          pair;
    std::string             label;
    struct s_lst_pair *     bind;
}   t_lst_pair;

typedef std::vector<t_vec_pair>::iterator t_vec_pair_it;

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::list<int> _lst;

    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(PmergeMe const & other);
        PmergeMe const &operator=(PmergeMe const & rhs);

        void                                 loadContainers(char **args);
        std::vector<int>                     getVecContainer(void);

        /********* std::vector *********/
        void                                 recursiveVecSort(std::vector<int> & container, int pair_size);
        void                                 sortVecPairs(std::vector<t_vec_pair> & pairs, int pair_size);
        void                                 sortContainers(void);
        void                                 labelPairs(std::vector<t_vec_pair> & pairs, int pair_size);
        void                                 printPairs(std::vector<t_vec_pair> & pairs);
        void                                 printContainers(void);
        std::vector<int>                     copyPairsIntoVecContainer(std::vector<t_vec_pair> & vec_pairs);
        std::vector<t_vec_pair>              makeVecPairs(std::vector<int> & container, int pair_size);
        t_vec_pair_it                        findPairByLabel(std::vector<t_vec_pair> & pending, std::string c, int current_nb);
        void                                 pushBackPairs(std::vector<int> & container, std::vector<t_vec_pair> & vec_pairs);
        std::vector<int>                     getJacobsthalSeq(void);
        void                                 prepChains(std::vector<t_vec_pair> & vec_pairs, std::vector<t_vec_pair> & main, std::vector<t_vec_pair> & pending);
        std::vector<int>                     jacobsthalInsertion(std::vector<t_vec_pair> & vec_pairs);
        void                                 insertMain(std::vector<t_vec_pair> & main, t_vec_pair_it begin, t_vec_pair_it end, t_vec_pair_it to_insert, int level);

        /********** std::list **********/
        void                                 recursiveLstSort(std::list<int> & container, int pair_size);
        std::list<t_lst_pair>                makeLstPairs(std::list<int> & container, int pair_size);
        void                                 sortLstPairs(std::list<t_lst_pair> & lst_pairs, int pair_size);
        
        template<typename T>
        bool isSorted(T container);

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

    for (it = container.begin(); it != container.end(); it++)
    {
        if (it != container.end() - 1 && *it > *(it + 1))
        {
            std::cout << "problematic item = " << *it << "\n";
            return false;
        }
    }
    return true;
}

#endif