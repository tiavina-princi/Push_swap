# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiarandr <tiarandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 12:13:29 by tiarandr          #+#    #+#              #
#    Updated: 2025/05/26 11:50:33 by tiarandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CLFAG = -Wall -Werror -Wextra

SRC =	ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_memchr.c\
		ft_atoi.c\
		ft_strdup.c\
		ft_calloc.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		print_nbr.c\
		print_str.c\
		print_char.c\
		print_address.c\
		print_hexadecimal.c\
		print_unsigned_int.c\
		print_hexadecimal_uppercase.c\
		ft_printf.c\
		ft_strcpy.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_stack_new.c\
		ft_clearstack.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strcat.c\
		ft_strjoin_sep.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

.PHONY : all re fclean clean bonus

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CLFAG) -c $^ -o $@

clean :
	rm -fr $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -fr $(NAME)

re : fclean all
