#############################
#        variables:         #
#############################
NAME = wolf3d
HEAD = ./header/
MAKEFILE = ./Makefile

SRC = ./src/*

#############################
#        tasks:             #
#############################
all: $(NAME)

$(NAME): $(SRC) $(MAKEFILE)
	gcc -o $(NAME) $(SRC) -I $(HEAD)

.PHONY: all