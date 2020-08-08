#############################
#        variables:         #
#############################
NAME = wolf3d
INCLUDE = ./include/
MAKEFILE = ./Makefile

SRC = ./src/*
HEAD = $(INCLUDE)*

FLAGS = -lm # math library

#############################
#        tasks:             #
#############################
all: $(NAME)

$(NAME): $(SRC) $(MAKEFILE) $(HEAD)
	gcc -o $(NAME) $(SRC) -I $(INCLUDE)

.PHONY: all