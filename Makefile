# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 10:47:16 by tiarandr          #+#    #+#              #
#    Updated: 2025/05/22 07:35:16 by tiarandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR=./libft

LINK= -L$(LIBFT_DIR) -lft

LIBFT= $(LIBFT_DIR)/libft.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra -g

SRC= ./main.c ./push.c ./push_swap.c ./ref.c ./reverse_rotate.c ./rotate.c ./swap.c\
	 ./push_swap_utils.c ./push_all_to_b.c ./push_all_to_a.c ./push_all_to_a_utils.c

BONUS_SRC= ./checker_bonus.c ./checker_utils2_bonus.c ./checker_utils_bonus.c ./cheker_utils3_bonus.c\
		  ./get_instruction_bonus.c ./get_sort_bonus.c

OBJ=$(SRC:.c=.o)

BONUS_OBJ=$(BONUS_SRC:.c=.o)

NAME=push_swap

BONUS_NAME=checker

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK) $(CFLAGS) -o $@

$(BONUS_NAME) : $(LIBFT) $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(LINK) $(CFLAGS) -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	make -C $(LIBFT_DIR) clean
	rm -fr $(OBJ) $(BONUS_OBJ)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -fr $(OBJ)  $(BONUS_OBJ)
	rm -fr $(NAME)
	rm -fr $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re bonus
