# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/06 17:41:25 by codespace         #+#    #+#              #
#    Updated: 2025/09/28 22:05:53 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp

OBJS = $(SRC:.cpp=.o)

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) home_shrubbery
	$(RM) Garden_shrubbery

re: fclean all

.PHONY: all clean fclean re