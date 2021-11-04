# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 10:59:58 by aricholm          #+#    #+#              #
#    Updated: 2021/08/24 22:51:51 by aricholm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
NAME = push_swap
BONUS = checker

MAIN	=	./src/push_swap.o

OBJS	=	./src/linked_list.o\
			./src/utils1.o\
			./src/ft_atoi.o\
			./src/libft.o\
			./src/operations_utils.o\
			./src/operations1.o\
			./src/operations2.o\
			./src/operations3.o\
			./src/iterate.o\
			./src/valid.o\
			./src/renumber.o\
			./src/slow_solve.o\
			./src/solve_3.o\
			./src/solve_right_x.o\
			./src/push_lowest_x.o\
			./src/checker_operations1.o\
			./src/checker_operations2.o\
			./src/checker_operations3.o\
			./src/stealth_push_lowest_x.o\
			./src/stealth_slow_solve.o\
			./src/stealth_solve_right_x.o\
			./src/stealth_solve.o


CHECKER=	./src/checker.o\
			./src/checker_gnl.o\
			./src/checker_gnl_utils.o\

IDIR	=	./header

HEAD	= 	./header/push_swap.h\
			./header/linked_list.h\
			./header/utilities.h\
			./header/operations.h\
			./header/checker.h\
			./header/stealth.h

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) -o $(NAME) 

$(BONUS): $(OBJS) $(CHECKER)
	$(CC) $(CFLAGS) $(CHECKER) $(OBJS) -o $(BONUS)
	
%.o: %.c $(HEAD)
	$(CC) -c $(CFLAGS)  -I $(IDIR) -o $@  $<

clean:
	echo "Remove .o  ..."
	rm -f $(OBJS) $(CHECKER) $(MAIN)

fclean: clean
	echo "Remove lib ..."
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus