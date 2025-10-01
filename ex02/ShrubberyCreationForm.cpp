/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 01:04:58 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 02:35:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((target + "_shrubbery").c_str());
    file << "ASCII Trees!\n";
    file.close();
}