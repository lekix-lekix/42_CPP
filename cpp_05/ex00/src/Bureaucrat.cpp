/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:59:02 by lekix             #+#    #+#             */
/*   Updated: 2025/02/09 16:59:11 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Basic Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : _name(rhs._name), _grade(rhs._grade) 
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat string constructor called" << std::endl;
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        this->_grade = grade;
        std::cout << "Bureaucrat successfully instanciated!" << std::endl;
    }
    catch (GradeTooHighException const &e)
    {
        throw e;
    }
    catch (GradeTooLowException const &e)
    {
        throw e;
    }

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) 
{
    this->_grade = rhs._grade;
    std::cout << "As name being const, only a new grade has been assigned." << std::endl; 
    return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrate grade " << rhs.getGrade();
    return o;
}


std::string const &Bureaucrat::getName(void) const
{
    return this->_name;
}

int const &Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::incGrade(void)
{
    try
    {
        if (this->_grade - 1 < 1)
            throw GradeTooHighException();
        this->_grade -= 1;
        std::cout << this->_name << "'s grade succefully updated ! Now grade : " << this->_grade << std::endl;
    }
    catch (GradeTooHighException const &e)
    {
        throw e;
    }
}

void Bureaucrat::decGrade(void)
{
    try
    {
        if (this->_grade + 1 > 150)
            throw GradeTooLowException();
        this->_grade += 1;
        std::cout << this->_name << "'s grade succefully updated ! Now grade : " << this->_grade << std::endl;
    }
    catch (GradeTooLowException const &e)
    {
        throw e;
    }
    
}

void Bureaucrat::GradeTooHighException::triggerException(void)
{
    throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::GradeTooLowException::triggerException(void)
{
    throw Bureaucrat::GradeTooLowException();
}