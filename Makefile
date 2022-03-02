# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 14:21:08 by modysseu          #+#    #+#              #
#    Updated: 2021/12/25 17:40:16 by modysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIST	=	error_processing.c \
			funktion_utils.c \
			list_utils.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
			operations_swap.c \
			push_swap.c \
			sort_big_stack_push_b.c \
			sort_big_stack_rotate.c \
			sort_big_stack.c \
			sort_small_stack.c

HEADER	=	push_swap.h
			
OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER) Makefile
	gcc $(FLAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re