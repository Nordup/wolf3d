# include "display.h"

/**
 * printf("%s: %s\n", s, SDL_GetError());
 * */
int		quit(char *s) {
	ft_putstr(s);
	ft_putstr(": ");
	ft_putstr(SDL_GetError());
	ft_putendl("");
	SDL_Quit();
	exit(1);
}