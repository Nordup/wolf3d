# ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // malloc
# include <stdlib.h> // free
# include <math.h>
# include <fcntl.h> // read/write flags



# include "libft.h"
# include "display.h"
# include "world.h"
# include "render.h"

# define FOV 70

int		movement(t_wrld *world, SDL_Event *e);
int		game(t_sdl *sdl, t_wrld *world);

//mashley
int	ft_open_read(char *name);


# endif