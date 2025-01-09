/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:39:33 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/09 18:48:18 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{

public:
    Contact(void);
    ~Contact(void);
    // void setFirstName(std::string first_name);
    // void setLastName(std::string last_name);
    void setName(std::string name_field, std::string content);
    // void setNickName(std::string nickname);
    // void setDarkestSecret(std::string darkest_secret);
    // void setPhoneNumber(std::string phone_number);
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;

private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

#endif