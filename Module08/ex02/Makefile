# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 22:22:33 by minjungk          #+#    #+#              #
#    Updated: 2023/08/26 15:41:30 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD -MP

NAME	= main

SRCS = \
	$(NAME).cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)

$(NAME): $(OBJS)
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

all: $(NAME)

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
