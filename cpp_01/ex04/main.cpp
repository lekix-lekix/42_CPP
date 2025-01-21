/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:06:06 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/21 16:06:10 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int file_error(void)
{
    std::cerr << "File error : " << std::strerror(errno) << std::endl;
    return (-1);
}

int my_own_replace(std::string s1, std::string s2, std::ifstream &infile, std::ofstream &outfile)
{
    std::string line;

    if (!(std::getline(infile, line, '\0')))
    {
        std::cerr << "Getline error : " << std::strerror(errno) << std::endl;
        return (-1);
    }
    for (size_t pos = line.find(s1); pos != (size_t)-1; pos = line.find(s1))
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
    }
    if (!(outfile << line))
    {
        std::cerr << "Writing error : " << std::strerror(errno) << std::endl;
        return (-1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string filename;

    if (argc != 4)
    {
        std::cout << "Wrong number of parameter. Usage : ./my_sed <filename> <str1> <str2>" << std::endl;
        return (-1);
    }
    infile.open(argv[1], std::ios::in);
    if (!infile.is_open())
        return (file_error());
    filename = std::string(argv[1]).append(".replace");
    outfile.open(filename.c_str());
    if (!outfile.is_open())
    {
        file_error();
        infile.close();
        return (-1);
    }
    if (my_own_replace(argv[2], argv[3], infile, outfile) == -1)
        std::cout << "Writing to file failed !" << std::endl;
    infile.close();
    outfile.close();
}
