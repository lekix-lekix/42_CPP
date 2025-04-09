/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:28:19 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/09 17:11:41 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/****** ORTHODOX CANONICAL FORM ******/

Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(0)
{
    std::cout << "Public Bureaucrat constructor called\n";
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Public destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name)
{
    *this = other;
    std::cout << "Copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & other)
{
    // can't modify name (const)
    this->_grade = other._grade;
    return *this;
}

/*********************/

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat " << name << " of grade " << grade << " is born!\n";
}

std::string Bureaucrat::getName(void)
{
    return this->_name;
}

int Bureaucrat::getGrade(void)
{
    return this->_grade;
}

void Bureaucrat::incGrade(void)
{
    if (this->getGrade() == 1)
        throw GradeTooHighException();
    this->_grade -= 1;
    std::cout << this->getName() << " got promoted! New grade: " << this->getGrade() << "\n";
}

void Bureaucrat::decGrade(void)
{
    if (this->getGrade() == 150)
        throw GradeTooLowException();
    this->_grade += 1;
    std::cout << this->getName() << " got demoted! New grade: " << this->getGrade() << "\n";
}

void Bureaucrat::signForm(AForm & to_sign)
{
    try
    {
        to_sign.beSigned(*this);
        std::cout << this->getName() << " successfully signed " << to_sign.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << to_sign.getName() << " because : " << e.what();
    }
    
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldnt execute the form because : " << e.what();
    }
    
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat exception : grade too high !\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat exception : grade too low !\n");
}

std::ostream & operator<<(std::ostream &os, Bureaucrat & src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n";
    return os;
}