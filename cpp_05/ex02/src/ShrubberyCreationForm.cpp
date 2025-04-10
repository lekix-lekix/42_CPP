/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:57:16 by lekix             #+#    #+#             */
/*   Updated: 2025/04/10 13:08:05 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", "", 145, 137)
{
    std::cout << "Default shrubbery constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Default shrubbery destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("shrubbery creation", target, 145, 137)
{
    std::cout << "Shrubbery paramm constructor called\n";
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    // nothing to copy
    (void) other;
    return *this;
}

const char *ShrubberyCreationForm::ShrubberyFileError::what(void) const throw()
{
    return ("Shrubbery file opening failed\n");
}

void ShrubberyCreationForm::launch_form_exec(std::string target) const
{
    std::ofstream outfile(std::string(target + "_shrubbery").c_str());
    std::ifstream infile("./tree.txt");
    std::string buffer;
    
    if (!infile.is_open() || !outfile.is_open())
        throw ShrubberyFileError();
    while (getline(infile, buffer))
        outfile << buffer << "\n";
    outfile.close();
    infile.close();
}
