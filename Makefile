# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miclandr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 19:49:10 by miclandr          #+#    #+#              #
#    Updated: 2024/11/13 14:24:05 by miclandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MY_SOURCES = ft_utils.c\
			ft_ptr.c\
			ft_printf.c\

OBJS = $(MY_SOURCES:.c=.o)

$(NAME) : $(OBJS)
		ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c Makefile ft_printf.h
		$(CC) $(CCFLAGS) -c -o $@ $<

clean:
		$(RM) $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
