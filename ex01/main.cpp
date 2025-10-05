/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 00:10:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "===== Test: Bureaucrat with sufficient permission signing =====" << std::endl;
    try {
        Bureaucrat ana("Ana", 1);
        Form taxForm("Tax Form", 5, 3);
        std::cout << ana << std::endl;
        std::cout << taxForm << std::endl;
        ana.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test: Bureaucrat with low grade trying to sign =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form hardForm("Hard Form", 50, 10);
        std::cout << bob << std::endl;
        std::cout << hardForm << std::endl;
        bob.signForm(hardForm);
        std::cout << hardForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test: Creating form with invalid grade (0) =====" << std::endl;
    try {
        Form invalidForm1("Invalid1", 0, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test: Creating form with invalid grade (151) =====" << std::endl;
    try {
        Form invalidForm2("Invalid2", 151, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test: Creating form with invalid execution grade (0) =====" << std::endl;
    try {
        Form invalidForm3("Invalid3", 10, 0);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test: Creating form with invalid execution grade (151) =====" << std::endl;
    try {
        Form invalidForm4("Invalid4", 10, 151);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
