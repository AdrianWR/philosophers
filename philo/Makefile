# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 18:35:11 by aroque            #+#    #+#              #
#    Updated: 2021/07/23 23:59:39 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RM			= rm -f

CC			= clang
CPPFLAGS	=
CFLAGS		= -g -O0 -fsanitize=address
LDFLAGS		= -fsanitize=address
LDLIBS		=

INCLUDE_DIR	= include
override CPPFLAGS	+=	-I$(INCLUDE_DIR)
override CFLAGS		+=	-Wall				\
						-Wextra				\
						-Werror				\
						-pthread
override LDFLAGS	+=	-pthread

INCLUDE	=	philo.h

SRC_DIR	=	src
SRC		=	philo.c		\
			time.c		\
			actions.c	\
			args.c		\
			atoi.c		\
			iterator.c	\
			display.c	\
			monitor.c	\
			init.c		\
			meal.c		\
			clear.c		\
			routine.c

OBJ_DIR	= build
OBJ		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

vpath %.c $(SRC_DIR)
vpath %.h $(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $^

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	mkdir -p $(@D)
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
