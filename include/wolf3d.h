# ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // malloc
# include <stdlib.h> // free
# include <math.h>
# include <fcntl.h> // read/write flags

# include "world.h"
# include "libft.h"
# include "display.h"
# include "render.h"

typedef int		t_bool;
# define TRUE	1
# define FALSE	0

int		game(t_sdl *sdl, t_wrld *world);

# endif