# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbaek <chbaek@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 16:45:19 by chbaek            #+#    #+#              #
#    Updated: 2023/07/01 17:18:54 by chbaek           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = 
NAME_TIME = name_time
OBJ = 

all : $(NAME_TIME)

$(NAME_TIME) : $(OBJ)
	$(RM) $(NAME_TIME)
	
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

.PHONY : all clean fclean re
