/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:21:40 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/18 13:18:05 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myFirstTemplate.hpp"

int main()
{
	{	
		int a = 1, b = 2;
		
		std::cout << a << " " << b << std::endl;
		std::cout << min(a, b) << std::endl;
		std::cout << max(a, b) << std::endl;
		swap(a, b);
		std::cout << a << " " << b << std::endl;
	}
	{
		char a = 'a', b = 'b';
		
		std::cout << a << " " << b << std::endl;
		std::cout << min(a, b) << std::endl;
		std::cout << max(a, b) << std::endl;
		std::cout << a << " " << b << std::endl;
		swap(a, b);	
	}
	{
		std::string a = "is dead", b = "harry potter";
		std::cout << a << " " << b << std::endl;
		std::cout << ::min(a, b) << std::endl;
		std::cout << ::max(a, b) << std::endl;
		::swap(a, b);
		std::cout << a << " " << b << std::endl;
	}	
}