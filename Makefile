# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 16:45:19 by chbaek            #+#    #+#              #
#    Updated: 2023/11/01 17:49:48 by chbaek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
NAME_TIME = name_time
OBJ = parsing/main.o parsing/valid.o parsing/util.o

all : $(NAME_TIME)

$(NAME_TIME) : $(OBJ)
	$(RM) $(NAME_TIME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	touch $(NAME_TIME)

$(NAME) : all

clean :
	$(RM) $(OBJ)

fclean :
	make clean
	$(RM) $(NAME) $(NAME_TIME)

re:
	make fclean
	make all

bonus:

.PHONY : all clean fclean re bonus
