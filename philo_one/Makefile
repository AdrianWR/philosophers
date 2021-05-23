# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 18:35:11 by aroque            #+#    #+#              #
#    Updated: 2021/05/23 19:05:35 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

RM			= rm -f

CC			= clang
CPPFLAGS	= 
CFLAGS		= 
LDFLAGS		=
LDLIBS		=

INCLUDE_DIR	= include
override CFLAGS += -Wall -Wextra -Werror
override CPPFLAGS += -I$(INCLUDE_DIR)

SRC_DIR	= src
SRC		= philo_one.c

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
