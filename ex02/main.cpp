/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 01:54:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "===== Teste: Bureaucrat com permissão suficiente =====" << std::endl;
    Bureaucrat ana("Ana", 1);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Alice");
    std::cout << ana << std::endl;
    std::cout << shrubbery << std::endl;
    ana.signForm(shrubbery);
    ana.executeForm(shrubbery);
    ana.signForm(robotomy);
    ana.executeForm(robotomy);
    ana.signForm(pardon);
    ana.executeForm(pardon);

    std::cout << "\n===== Teste: Bureaucrat com graduação insuficiente para assinar =====" << std::endl;
    Bureaucrat low("Low", 150);
    ShrubberyCreationForm shrubbery2("garden");
    low.signForm(shrubbery2);

    std::cout << "\n===== Teste: Bureaucrat tentando executar form não assinado =====" << std::endl;
    Bureaucrat mid("Mid", 50);
    RobotomyRequestForm robotomy2("R2D2");
    mid.executeForm(robotomy2);

    std::cout << "\n===== Teste: Bureaucrat consegue assinar mas não executar =====" << std::endl;
    Bureaucrat signOnly("Signer", 72);
    RobotomyRequestForm robotomy3("C3PO");
    signOnly.signForm(robotomy3);
    signOnly.executeForm(robotomy3);

    return 0;
}
