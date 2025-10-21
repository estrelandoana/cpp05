/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:49:57 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "Bureaucrat with sufficient permission" << std::endl;
    Bureaucrat ana("Ana", 1);
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Alice");
    std::cout << ana << std::endl;
    std::cout << shrubbery << std::endl;
    ana.signForm(shrubbery);
    ana.executeForm(shrubbery);
    std::cout << robotomy << std::endl;
    ana.signForm(robotomy);
    ana.executeForm(robotomy);
    std::cout << pardon << std::endl;
    ana.signForm(pardon);
    ana.executeForm(pardon);

    std::cout << "\nBureaucrat with insufficient grade to sign" << std::endl;
    Bureaucrat low("Low", 150);
    ShrubberyCreationForm shrubbery2("garden");
    low.signForm(shrubbery2);

    std::cout << "\nBureaucrat trying to execute unsigned form" << std::endl;
    Bureaucrat mid("Mid", 50);
    RobotomyRequestForm robotomy2("R2D2");
    mid.executeForm(robotomy2);

    std::cout << "\nBureaucrat can sign but not execute" << std::endl;
    Bureaucrat signOnly("Signer", 72);
    RobotomyRequestForm robotomy3("C3PO");
    signOnly.signForm(robotomy3);
    signOnly.executeForm(robotomy3);

    return 0;
}
