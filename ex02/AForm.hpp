/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:52:35 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:44:18 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int grade);
        AForm(const AForm& copied);
        AForm& operator=(const AForm& copied);
        virtual ~AForm();

        const std::string& getName() const;
        bool getIsSign() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
