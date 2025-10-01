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
    std::cout << "===== Teste de construção válida e increment/decrement =====" << std::endl;
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
        std::cerr << "Exception em construtor válido: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste de construção com nota inválida (0) =====" << std::endl;
    try {
        Bureaucrat c("Zero", 0);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste de construção com nota inválida (151) =====" << std::endl;
    try {
        Bureaucrat d("CentoCinquentaEUm", 151);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
