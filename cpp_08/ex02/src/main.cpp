/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:32:49 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/22 17:26:59 by kipouliq         ###   ########.fr       */
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
//     std::cout << mstack.size() << "\n";

//     MutantStack<int>::iterator it;
 
//     it = mstack.begin();
//     std::cout << *it << "\n";

//     std::deque<int> mydeque (3,100);          // deque with 3 elements
//     std::vector<int> myvector (2,200);        // vector with 2 elements

//     MutantStack<int> first;                    // empty stack
//     MutantStack<int> second (mydeque);         // stack initialized to copy of deque

//     MutantStack<int,std::vector<int> > third;  // empty stack using vector
//     MutantStack<int,std::vector<int> > fourth (myvector);

//     MutantStack<int,std::list<int> > fifh;

//     std::cout << "size of first: " << first.size() << '\n';
//     std::cout << "size of second: " << second.size() << '\n';
//     std::cout << "size of third: " << third.size() << '\n';
//     std::cout << "size of fourth: " << fourth.size() << '\n';
// }

int main () {
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