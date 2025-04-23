/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:32:49 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/23 17:11:44 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

// int main ()
// {
//     MutantStack<int> mstack;
//     mstack.push(1);
//     mstack.push(2);
//     mstack.push(3);
//     mstack.push(4);
//     mstack.push(5);
//     std::cout << "size = " << mstack.size() << "\n";

//     MutantStack<int>::iterator it;
    
//     it = mstack.begin();
//     std::cout << "it = " << *it << "\n";
//     it = mstack.end();
//     it--;
//     std::cout << "it = " << *it << "\n";

//     MutantStack<int>::reverse_iterator rev_it;
//     rev_it = mstack.rbegin();
//     std::cout << "rev begin = " << *rev_it << "\n";
//     rev_it = --mstack.rend();
//     std::cout << "rev end = " << *rev_it << "\n";
    

//     std::deque<int> mydeque (3,100);          // deque with 3 elements
//     std::vector<int> myvector (2,200);        // vector with 2 elements

//     MutantStack<int> first;                    // empty stack
//     MutantStack<int> second (mydeque);         // stack initialized to copy of deque

//     MutantStack<int,std::vector<int> > third;  // empty stack using vector
//     MutantStack<int,std::vector<int> > fourth (myvector);

//     MutantStack<std::vector<std::string> > fifth;
//     std::vector<std::string> sixth;
//     std::vector<std::string> seventh;
    
//     sixth.push_back("quelle");
//     sixth.push_back("indignite");
//     sixth.push_back("monsieur");
//     sixth.push_back("pujadas");

//     seventh.push_back("tout ca");
//     seventh.push_back("sur le");
//     seventh.push_back("service");
//     seventh.push_back("public");

//     fifth.push(sixth);
//     fifth.push(seventh);

//     MutantStack<std::vector<std::string> >::iterator more_it;
//     std::vector<std::string>::iterator vec_it;
//     for (more_it = fifth.begin(); more_it != fifth.end(); more_it++)
//     {
//         for (vec_it = more_it->begin(); vec_it != more_it->end(); vec_it++)
//             std::cout << *vec_it << "\n";        
//     }

//     std::cout << "size of first: " << first.size() << '\n';
//     std::cout << "size of second: " << second.size() << '\n';
//     std::cout << "size of third: " << third.size() << '\n';
//     std::cout << "size of fourth: " << fourth.size() << '\n';
//     std::cout << "size of fifth: " << fifth.size() << '\n';
//     std::cout << "size of sixth: " << sixth.size() << '\n';
//     std::cout << "size of seventh: " << seventh.size() << '\n';
// }

int main () 
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}