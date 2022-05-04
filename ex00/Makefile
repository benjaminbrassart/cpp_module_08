# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 02:22:12 by bbrassar          #+#    #+#              #
#    Updated: 2022/05/04 18:10:55 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= a.out

CXX					= c++
CXXFLAGS			+= -Wall
CXXFLAGS			+= -Werror
CXXFLAGS			+= -Wextra
CXXFLAGS			+= -c
CXXFLAGS			+= -Iinclude
CXXFLAGS			+= -I..
CXXFLAGS			+= -MP -MMD
CXXFLAGS			+= -std=c++98

DIR_SRC				= src
DIR_OBJ				= obj

SRC					= main.cpp
OBJ					= $(SRC:%.cpp=$(DIR_OBJ)/%.o)
DEP					= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					$(CXX) $^ -o $@

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.cpp
					@mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) $< -o $@

-include $(DEP)

all:				$(NAME)

clean:
					$(RM) -r $(DIR_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
