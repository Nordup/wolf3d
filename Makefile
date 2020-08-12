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
MKDIR_BUILD =	$(DIR_BUILD) $(DIR_BUILD)display/ $(DIR_BUILD)render/ \
				$(DIR_BUILD)world/ $(DIR_BUILD)drawing/
DIR_INCLUDE = ./include/
DIR_LIB = ./libraries/
DIR_SRC = ./src/

DIR_LIBFT = $(DIR_LIB)libft/
DIR_SDL2_HEAD = $(DIR_LIB)SDL2-2.0.12/include/

# source and object files
SOURCES =	main.c game.c movement.c \
			$(addprefix display/, init_sdl.c quit.c quit_sdl.c) \
			$(addprefix render/, rendering.c ray_casting.c) \
			$(addprefix world/, delete_world.c init_world.c create_box.c) \
			$(addprefix drawing/, draw_point.c draw_map.c draw_line.c) \

OBJECTS = $(SOURCES:%.c=%.o)
C_FLS = $(addprefix $(DIR_SRC), $(SOURCES))
O_FLS = $(addprefix $(DIR_BUILD), $(OBJECTS))

# libraries and headers
HEAD = $(DIR_INCLUDE)*
LIB = $(DIR_LIB)libft/libft.a
INCLUDES = -I $(DIR_INCLUDE) -I $(DIR_LIBFT) -I $(DIR_SDL2_HEAD)

# flags
ifeq ($(SYSTEM), $(MACOS))
	FLAGS = -framework SDL2 -F $(DIR_LIB) -rpath $(DIR_LIB) -lm
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
	# for libSDL2-2.0.so.3 library
	export LD_LIBRARY_PATH="/usr/local/lib"

# compile bins and move them into dir
 $(DIR_BUILD)%.o: $(DIR_SRC)%.c $(HEAD)
	$(CC) $(WWW) -c $(INCLUDES) $< -o $@

$(MKDIR_BUILD):
	mkdir -p $(MKDIR_BUILD)

# clean, fclean, re
clean:
	rm -f $(NAME)
	rm -rf $(DIR_BUILD)

fclean: clean
	make fclean -C  $(DIR_LIB)

re: clean all

.PHONY: all clean fclean re