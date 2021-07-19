# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 18:35:11 by aroque            #+#    #+#              #
#    Updated: 2021/07/18 15:06:46 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RM			= rm -f

CC			= clang
CPPFLAGS	=
CFLAGS		= -g -O0
LDFLAGS		=
LDLIBS		=

INCLUDE_DIR	= include
override CPPFLAGS	+=	-I$(INCLUDE_DIR)
override CFLAGS		+=	-Wall				\
						-Wextra				\
						-Werror				\
						-pthread
override LDFLAGS	+=	-pthread

SRC_DIR	=	src
SRC		=	philo.c		\
			time.c		\
			args.c		\
			atoi.c		\
			wrapper.c	\
			iterator.c	\
			display.c	\
			monitor.c	\
			routine.c

OBJ_DIR	= build
OBJ		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $^

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
