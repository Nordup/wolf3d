# ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // malloc
# include <stdlib.h> // free
# include <math.h>
# include <fcntl.h> // read/write flags

typedef int		t_bool;
# define TRUE	1
# define FALSE	0

# include "libft.h"
# include "display.h"
# include "world.h"
# include "render.h"
# include "drawing.h"

# define FOV 70

int		movement(t_wrld *world, SDL_Event *e);
int		game(t_sdl *sdl, t_wrld *world);

# endif