NAME=cub3D
CC=cc
CFLAGS=-Wall -Werror -Wextra -g

LIB=libft.a
LIB_PATH=libft
LIBMLX=libmlx.dylib
DYLD_LIBRARY_PATH=minilibx_mms_20200219
INCLUDES=includes

RM=rm -rf

SRCS_EXECUTE=$(addprefix srcs/execute/, main.c draw.c event.c key_update.c load_asset.c raycasting_1.c raycasting_2.c util.c init.c) srcs/gnl/get_next_line_utils.c srcs/gnl/get_next_line.c

SRCS_PARSING=$(addprefix srcs/parsing/, con_map.c is_dotcub.c load_map.c load_map_util.c util2.c ft_split.c is_valid_map.c load_map2.c util.c)

OBJS_EXECUTE=$(SRCS_EXECUTE:.c=.o)

OBJS_PARSING=$(SRCS_PARSING:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_EXECUTE) $(OBJS_PARSING)
	make -C $(DYLD_LIBRARY_PATH)
	cp $(DYLD_LIBRARY_PATH)/$(LIBMLX) ./
	$(CC) $(OBJS_EXECUTE) $(OBJS_PARSING) -I. -I$(DYLD_LIBRARY_PATH) $(DYLD_LIBRARY_PATH)/$(LIBMLX) -I$(INCLUDES) -framework OpenGL -framework Appkit -o $(NAME)

%.o:%.c
	$(CC) -I. -I$(DYLD_LIBRARY_PATH) -I$(INCLUDES) -c $< -o $@

$(LIBMLX) :
	make -C $(dir $(LIBMLX))

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

clean :
	$(RM) $(OBJS_EXECUTE) $(OBJS_PARSING)

fclean :
	$(RM) $(OBJS_EXECUTE) $(OBJS_PARSING) $(NAME) $(LIBMLX)

re :
	make fclean
	make all

.PHONY : all clean fclean re
