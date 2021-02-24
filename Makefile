# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 15:57:09 by esormune          #+#    #+#              #
#    Updated: 2021/02/20 16:42:25 by esormune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libft/includes -g 

HEADER = ft_printf.h ./includes/libft.h

LIBFT = libft/libft.a

SRCS = ft_parser.c ft_printf.c ft_split.c ft_convert.c ft_specs.c \
	ft_conflicts.c ft_char.c ft_string.c ft_octal.c ft_hex.c \
	ft_int.c ft_exp.c ft_u_int.c ft_pointer.c ft_binary.c ft_float.c \
	ft_percent.c ft_null_string.c ft_init.c ft_rev_split.c \
	ft_width.c ft_nb.c ft_next.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C ./libft
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) created."

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)
	@echo "Files .o deleted."

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -rf $(NAME)
	@echo "Binary $(NAME) deleted."

re: fclean all

.PHONY = all clean fclean re
