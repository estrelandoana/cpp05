/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by codespace         #+#    #+#             */
/*   Updated: 2025/09/14 23:03:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a("Ana", 2);
        Bureaucrat b("Luke", 149);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;
        
        try {
            a.incrementGrade();
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        b.decrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Exception in constructor: " << e.what() << std::endl;
    }
    return 0;
}
