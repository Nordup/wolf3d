#############################
#        variables:         #
#############################
NAME = wolf3d
CC = gcc
WWW = #-Wall -Wextra -Werror

#SYSTEM:
SYSTEM = $(shell uname)
MACOS = Darwin
LINYX = Linux

# directories
DIR_BUILD = ./build/
MKDIR_BUILD =	$(addprefix $(DIR_BUILD), display/ render/ world/ parsing/)
DIR_LIB = ./libraries/
DIR_SRC = ./src/
DIR_SDL2 = $(DIR_LIB)SDL2.framework/

DIR_INCLUDE = ./include/
DIR_LIBFT = $(DIR_LIB)libft/
DIR_SDL2_HEAD = $(DIR_SDL2)/Headers/

# source and object files
SOURCES =	main.c game.c movement.c \
			$(addprefix display/, init_sdl.c quit_sdl.c) \
			$(addprefix render/, rendering.c ray_casting.c wall_draw.c set_wall_texture.c) \
			$(addprefix world/, free_world.c init_world.c init_map.c newpnt.c) \
			$(addprefix parsing/,  read_map.c read_textures.c read_wall_types.c)

OBJECTS = $(SOURCES:%.c=%.o)
C_FLS = $(addprefix $(DIR_SRC), $(SOURCES))
O_FLS = $(addprefix $(DIR_BUILD), $(OBJECTS))

# libraries and headers
HEAD = $(DIR_INCLUDE)*
LIB = $(DIR_LIB)libft/libft.a
INCLUDES = -I $(DIR_INCLUDE) -I $(DIR_LIBFT) -I $(DIR_SDL2_HEAD)

# flags
ifeq ($(SYSTEM), $(MACOS))
	FLAGS = -F $(DIR_LIB) -rpath $(DIR_LIB) -framework SDL2 -lm
else ifeq ($(SYSTEM), $(LINYX))
	FLAGS = -l SDL2 -lm
endif



#############################
#        tasks:             #
#############################
all: $(NAME)

# build libs and compile wolf3d
$(NAME): $(MKDIR_BUILD) $(O_FLS)
	make -C $(DIR_LIB)
	$(CC) -o $(NAME) $(O_FLS) $(FLAGS) $(LIB)

# compile bins and move them into dir
 $(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEAD)
	$(CC) $(WWW) -c $(INCLUDES) $< -o $@

$(MKDIR_BUILD):
	mkdir -p $(MKDIR_BUILD)

# clean, fclean, re
clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(DIR_BUILD)
	make fclean -C  $(DIR_LIB)

re: fclean all

.PHONY: all clean fclean re