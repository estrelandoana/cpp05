/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by codespace         #+#    #+#             */
/*   Updated: 2025/09/28 22:13:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "===== Test: Bureaucrat with sufficient permission =====" << std::endl;
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

    std::cout << "\n===== Test: Bureaucrat with insufficient grade to sign =====" << std::endl;
    Bureaucrat low("Low", 150);
    ShrubberyCreationForm shrubbery2("garden");
    low.signForm(shrubbery2);

    std::cout << "\n===== Test: Bureaucrat trying to execute unsigned form =====" << std::endl;
    Bureaucrat mid("Mid", 50);
    RobotomyRequestForm robotomy2("R2D2");
    mid.executeForm(robotomy2);

    std::cout << "\n===== Test: Bureaucrat can sign but not execute =====" << std::endl;
    Bureaucrat signOnly("Signer", 72);
    RobotomyRequestForm robotomy3("C3PO");
    signOnly.signForm(robotomy3);
    signOnly.executeForm(robotomy3);

    Intern someRandomIntern;
    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (f1) {
        ana.signForm(*f1);
        ana.executeForm(*f1);
        delete f1;
    }

    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (f2) {
        ana.signForm(*f2);
        ana.executeForm(*f2);
        delete f2;
    }

    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Bob");
    if (f3) {
        ana.signForm(*f3);
        ana.executeForm(*f3);
        delete f3;
    }

    AForm* f4 = someRandomIntern.makeForm("coffee making", "Office");
    if (f4) delete f4;

    return 0;
}
