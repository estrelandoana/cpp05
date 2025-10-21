/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:35:41 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:29:10 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int grade) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(grade) {
    if(gradeToSign < 1 || grade < 1)
        throw AForm::GradeTooHighException();
    if(gradeToSign > 150 || grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copied) : name(copied.name), isSigned(copied.isSigned), gradeToSign(copied.gradeToSign), gradeToExecute(copied.gradeToExecute) {}

AForm& AForm::operator=(const AForm& copied) {
    if(this != &copied) {
        this->isSigned = copied.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSign() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm \"" << f.getName()
        << "\", signed: " << (f.getIsSign() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return os;
}