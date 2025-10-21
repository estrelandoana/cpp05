/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:39:48 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "Bureaucrat with sufficient permission signing" << std::endl;
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

    std::cout << "\nBureaucrat with low grade trying to sign" << std::endl;
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

    std::cout << "\nCreating form with invalid grade (0)" << std::endl;
    try {
        Form invalidForm1("Invalid1", 0, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nCreating form with invalid grade (151)" << std::endl;
    try {
        Form invalidForm2("Invalid2", 151, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nCreating form with invalid execution grade (0)" << std::endl;
    try {
        Form invalidForm3("Invalid3", 10, 0);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nCreating form with invalid execution grade (151)" << std::endl;
    try {
        Form invalidForm4("Invalid4", 10, 151);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
