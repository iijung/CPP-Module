# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 18:06:36 by minjungk          #+#    #+#              #
#    Updated: 2023/08/06 19:48:01 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD -MP

NAME	= main

SRCS	= \
	Bureaucrat.cpp \
	Form.cpp \
	$(NAME).cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)

$(NAME): $(OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

all: $(NAME)

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
