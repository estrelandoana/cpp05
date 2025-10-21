/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaula-l <apaula-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:06:29 by apaula-l          #+#    #+#             */
/*   Updated: 2025/10/21 19:32:20 by apaula-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& copied);
    Intern& operator=(const Intern& copied);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
