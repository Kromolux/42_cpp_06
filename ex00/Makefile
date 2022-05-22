# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 07:06:15 by rkaufman          #+#    #+#              #
#    Updated: 2022/05/22 22:20:07 by rkaufman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	convert

CC			:=	c++

SRCS		:=	main.cpp \
				Converter.cpp

OBJS		:=	$(SRCS:%.cpp=%.o)

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -Wconversion
DFLAG		:=	-g -D DEBUG=1

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

debug: CFLAGS += $(DFLAG)
debug: re
	./$(NAME)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

val:
	valgrind --leak-check=full -s ./$(NAME) 42.0

leak:
	leaks --atExit -- ./$(NAME) 42.0

test:
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 65.0
	./$(NAME) -inff

.PHONY: clean fclean re test
