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
CLIB = -lm -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
NAME = cub3D
NAME_TIME = name_time
LIBMLX = mlx/libmlx.dylib
SRCS = parsing/main.c parsing/valid.c parsing/util.c
OBJS = $(SRCS:.c=.o)
HEADER = parsing/parsing.h
INCLUDE = parsing

all : $(NAME_TIME)

$(NAME_TIME) : $(HEADER) $(OBJS) $(LIBMLX)
	$(RM) $(NAME_TIME)
	$(CC) $(CFLAGS) $(CLIB) $(OBJS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	touch $(NAME_TIME)

$(NAME) : all

$(LIBMLX)   :
    make -C $(dir $(LIBMLX))

%.o : %.c
    $(CC) $(CFLAGS) -I$(INCLUDE) -o $@ -c $<

clean :
	$(RM) $(OBJS)
	make -C $(dir $(LIBMLX)) clean

fclean :
	$(RM) $(OBJS)
	make -C $(dir $(LIBMLX)) fclean
	$(RM) $(NAME) $(NAME_TIME)

re:
	make fclean
	make all

bonus:

.PHONY : all clean fclean re bonus
