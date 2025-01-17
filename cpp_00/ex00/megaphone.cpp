/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:09:31 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/16 10:09:42 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        int str_len = str.length();
        for (int i = 0; i < str_len; i++)
        {
            char c = toupper(str[i]);
            std::cout << c;
        }
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
}