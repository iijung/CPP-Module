# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 00:14:59 by minjungk          #+#    #+#              #
#    Updated: 2023/08/27 16:53:35 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL = all

CXX 		= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 -MMD -MP
CPPFLAGS	= -I.

NAME	= RPN

SRCS = \
	RPN.cpp \
	main.cpp
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
