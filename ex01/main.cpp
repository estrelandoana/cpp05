/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:55:39 by codespace         #+#    #+#             */
/*   Updated: 2025/09/19 00:10:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat ana("Ana", 1);
        Form taxForm( "Tax Form", 5, 3);

        std::cout << ana << std::endl;
        std::cout << taxForm << std::endl;

        ana.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
}
