/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:34:36 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "Valid construction and increment/decrement" << std::endl;
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

        try {
            b.decrementGrade();
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    } catch (std::exception& e) {
    std::cerr << "Exception in valid constructor: " << e.what() << std::endl;
    }

    std::cout << "\nInvalid grade (0)" << std::endl;
    try {
        Bureaucrat c("Zero", 0);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nInvalid grade (151)" << std::endl;
    try {
        Bureaucrat d("CentoCinquentaEUm", 151);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
