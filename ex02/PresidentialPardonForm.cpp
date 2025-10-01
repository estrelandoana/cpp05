/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 01:29:40 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 02:29:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
void PresidentialPardonForm::executeAction() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
