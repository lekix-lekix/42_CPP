/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:31 by kipouliq          #+#    #+#             */
/*   Updated: 2024/12/13 18:52:36 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        string str = argv[i];
        string::iterator it;
        for(it = str.begin(); it != str.end(); it++)
            std::cout << toupper((char)*it);
    }
}