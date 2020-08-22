#SYSTEM:
SYSTEM = $(shell uname)
MACOS = Darwin
LINYX = Linux

SDL2_FRAMEWORK = SDL2.framework
DIR_FRAMEWORKS = ~/Library/Frameworks/
DIR_SDL2_FRAMEWORK = $(DIR_FRAMEWORKS)$(SDL2_FRAMEWORK)
DIR_LIBFT = ./libft/

LIBFT = $(DIR_LIBFT)libft.a

all: $(DIR_SDL2_FRAMEWORK) $(LIBFT)

$(LIBFT):
	make -C $(DIR_LIBFT)

$(DIR_SDL2_FRAMEWORK):
    ifeq ($(SYSTEM), $(MACOS))
		cp -rf $(SDL2_FRAMEWORK) $(DIR_FRAMEWORKS)
    endif

fclean:
	make fclean -C $(DIR_LIBFT)
    ifeq ($(SYSTEM), $(MACOS))
		rm -rf $(DIR_SDL2_FRAMEWORK)
    endif

.PHONY: all fclean