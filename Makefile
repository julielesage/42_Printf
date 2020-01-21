# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlesage <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/11 16:03:42 by jlesage           #+#    #+#              #
#    Updated: 2020/01/21 15:40:18 by jlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
I_FLAG = -Iinclude

SRCS_PATH = ./srcs/
LIBFT_PATH = ./libft/
INCLUDE_PATH = ./include/

OBJS_PATH = objs
OBJLIB_PATH = objs


SRCS_NAMES =  ft_printf.c\
				conversion1.c\
				field.c\

LIBFT_NAMES = ft_putstr_fd.c\
				ft_bzero.c\
				ischar.c\
				ft_strlen.c\
				ft_putnbr_fd.c\
				ft_strncmp.c\
				ft_itoa_base.c\
				ft_substr.c\
				ft_strcat.c\
				ft_strdup.c\
				ft_atoi.c\
				ft_strndup.c\

INCLUDE_NAME = ft_printf.h
OBJS_NAME = $(SRCS_NAMES:.c=.o)
OBJLIB_NAME = $(LIBFT_NAMES:.c=.o)

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAMES))
LIBFT = $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAMES))
INCLUDE = $(addprefix $(INCLUDE_PATH)/, $(INCLUDE_NAME))
OBJS = $(addprefix $(OBJS_PATH)/,$(OBJS_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(OBJLIB)
	ar rc $(NAME) $(OBJS) $(OBJLIB)
	ranlib $(NAME)
	@echo "__, ___      __, __, _ _, _ ___ __,"
	@echo "|_   |       |_) |_) | |\ |  |  |_ "
	@echo "|    |       |   | \ | | \|  |  |  "
	@echo "~    ~  ~~~~ ~   ~ ~ ~ ~  ~  ~  ~  "
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIBFT_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(NAME)
	$(CC) $(CFLAGS) $(I_FLAG) main.c $(SCRS) $(LIBFT) -L. -lftprintf


clean:
	@rm -rf $(OBJS) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRCS) $(LIBFT) $(INCLUDE)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"

.PHONY: all clean fclean re norme
