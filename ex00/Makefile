# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/22 07:06:15 by rkaufman          #+#    #+#              #
#    Updated: 2022/05/22 23:40:15 by rkaufman         ###   ########.fr        #
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
	./$(NAME) P
	./$(NAME) ZU
	./$(NAME) nan
	./$(NAME) 42.42f
	./$(NAME) 65.65
	./$(NAME) -inff
	./$(NAME) 65489616545.65
	./$(NAME) 15454568454651561653435865488946519616545.65
	./$(NAME) 6548894848994848484865154645454564659616545.65f

.PHONY: clean fclean re test
