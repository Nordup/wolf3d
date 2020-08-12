DIR_SDL2 = ./SDL2-2.0.12/
DIR_LIBFT = ./libft/

DIR_BUILD = $(DIR_SDL2)build/
LIBFT = $(DIR_LIBFT)libft.a

all: $(DIR_BUILD) $(LIBFT)

$(LIBFT):
	make -C $(DIR_LIBFT)

$(DIR_BUILD):
	mkdir $(DIR_BUILD)
	bash SDL2_build.sh

fclean:
	make fclean -C $(DIR_LIBFT)
	rm -rf $(DIR_BUILD)

.PHONY: all fclean