#############################
#        variables:         #
#############################
NAME = wolf3d
CC = gcc
WWW = -Wall -Wextra -Werror

# directories
DIR_BUILD = ./build/
DIR_INCLUDE = ./include/
DIR_SRC = ./src/
MAKEFILE = ./Makefile

# source and object files
SOURCES = main.c
OBJECTS = $(SOURCES:%.c=%.o)

# final variables
C_FLS = $(addprefix $(DIR_SRC), $(SOURCES))
O_FLS = $(addprefix $(DIR_BUILD), $(OBJECTS))
HEAD = $(DIR_INCLUDE)*
FLAGS = -lm #math library

#############################
#        tasks:             #
#############################
all: $(NAME)

# build libs and compile wolf3d
$(NAME): $(C_FLS) $(MAKEFILE) $(HEAD) $(O_FLS)
	make -C ./libraries/
	$(CC) -o $(NAME) $(O_FLS) $(FLAGS)

# compile bins and move them into dir
$(O_FLS): $(DIR_BUILD)
	$(CC) $(WWW) -c $(C_FLS) -I $(DIR_INCLUDE)
	mv $(OBJECTS) $(DIR_BUILD)

$(DIR_BUILD):
	mkdir $(DIR_BUILD)

# clean, fclean, re
clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(DIR_BUILD)
	make fclean -C ./libraries/

re: fclean all

.PHONY: all clean fclean re