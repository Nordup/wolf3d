SDL2 = ./SDL2-2.0.12/

DIR_BUILD = $(SDL2)build/

all: $(DIR_BUILD)

$(DIR_BUILD):
	mkdir $(DIR_BUILD)
	bash SDL2_build.sh

fclean:
	rm -rf $(DIR_BUILD)

.PHONY: all fclean