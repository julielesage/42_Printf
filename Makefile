# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlesage <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 14:09:19 by jlesage           #+#    #+#              #
#    Updated: 2019/12/12 15:25:58 by jlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = clang

SRCS = 

SRCS_LIBFT = 

OBJS = $(SRCS:.c=.o)

OBJS_LIBFT = $(OBJS_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
	ar -rcs $(NAME) $(OBJS) $(OBJS_LIBFT)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean all re
