/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:35:31 by lekix             #+#    #+#             */
/*   Updated: 2025/05/08 19:25:50 by lekix            ###   ########.fr       */
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
        void                                 recursiveVecSort(std::vector<int> & container, int pair_size, int level);
        void                                 sortVecPairs(std::vector<t_vec_pair> & pairs, int pair_size);
        void                                 sortContainers(void);
        void                                 labelPairs(std::vector<t_vec_pair> & pairs, int pair_size);
        void                                 printPairs(std::vector<t_vec_pair> & pairs);
        void                                 printContainers(void);
        std::vector<int>                     copyPairsIntoContainer(std::vector<t_vec_pair> & vec_pairs);
        std::vector<t_vec_pair>              makePairs(std::vector<int> & container, int pair_size);
        std::vector<t_vec_pair>::iterator    findPairByLabel(std::vector<t_vec_pair> & pending, std::string c, int current_nb);
        void                                 pushBackPairs(std::vector<int> & container, std::vector<t_vec_pair> & vec_pairs);
        void                                 getJacobsthalSeq(std::vector<int> & seq, int nb);
        int                                  jacobSthalRecursive(int nb);
        std::vector<int>                     jacobsthalInsertion(std::vector<t_vec_pair> & vec_pairs);
        void                                 insertMain(std::vector<t_vec_pair> & main, std::vector<t_vec_pair>::iterator to_insert);
        void                                 revInsertMain(std::vector<t_vec_pair> & main, std::vector<t_vec_pair>::iterator to_insert);

        template<typename T>
        bool isSorted(T container);

    class ArgsError : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif