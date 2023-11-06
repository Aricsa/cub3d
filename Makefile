NAME=cub3D
CC=cc
CFLAGS=-Wall -Werror -Wextra -g

LIB=libft.a
LIB_PATH=libft
LIBMLX=libmlx.dylib
DYLD_LIBRARY_PATH=minilibx_mms_20200219

RM=rm -rf

SRCS= $(addprefix srcs/, main.c)
OBJS=$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(DYLD_LIBRARY_PATH)
	cp $(DYLD_LIBRARY_PATH)/$(LIBMLX) ./
	$(CC) $(OBJS) -I. -I$(DYLD_LIBRARY_PATH) $(DYLD_LIBRARY_PATH)/$(LIBMLX) -framework OpenGL -framework Appkit -o $(NAME)

%.o:%.c
	$(CC) -I. -I$(DYLD_LIBRARY_PATH) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(NAME) $(LIBMLX)

re :
	make fclean
	make all

.PHONY : all clean fclean re
