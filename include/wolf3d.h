# ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // malloc
# include <math.h>
# include <fcntl.h> // read/write flags

# include "libft.h"
# include "mySDL2.h"
# include "raycasting.h"

typedef int		t_bool;
# define TRUE	1
# define FALSE	0

int		rendering_loop(t_sdl *sdl);

# endif