# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 11:48:55 by esormune          #+#    #+#              #
#    Updated: 2021/02/19 21:46:40 by esormune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERS = ./includes/libft.h
FLAG = -Wall -Wextra -Werror -g
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_is_whitespace.c ft_min.c ft_max.c ft_isupper.c ft_islower.c \
	ft_lstlast.c ft_lstsize.c ft_lstpush.c ft_calloc.c ft_realloc.c \
	get_next_line.c ft_print_hex.c ft_itoa_base.c ft_print_bits.c \
	ft_numlength.c ft_numlength_neg.c ft_itoa_llong_base.c \
	ft_itoa_ulong_base.c ft_itoa_size_t_base.c ft_itoa_intmax_base.c \
	ft_itoa_uintmax_base.c ft_tolower_str.c ft_toupper_str.c ft_pow.c \
	ft_flitoa.c ft_itoa_exp.c ft_flitoa_ldouble.c ft_neg_pow_ten.c \
	ft_brounding.c ft_print_array.c ft_putnstr.c ft_strndup.c \
	ft_implode.c ft_free_array.c ft_is_neg.c ft_putnstr_fd.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@gcc $(FLAG) -I $(HEADERS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created."

clean:
	@rm -rf $(OBJ)
	@echo "Files .o deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "Binary $(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re
