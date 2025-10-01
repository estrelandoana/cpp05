/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:35:41 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 00:09:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int grade) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(grade) {
    if(gradeToSign < 1 || grade < 1)
        throw Form::GradeTooHighException();
    if(gradeToSign > 150 || grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copied) : name(copied.name), isSigned(copied.isSigned), gradeToSign(copied.gradeToSign), gradeToExecute(copied.gradeToExecute) {}

Form& Form::operator=(const Form& copied) {
    if(this != &copied) {
        this->isSigned = copied.isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSign() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName()
        << "\", signed: " << (f.getIsSign() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return os;
}