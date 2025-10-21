/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 20:13:12 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
