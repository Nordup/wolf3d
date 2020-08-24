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

# define WALL_SIZE 600
# define EPS 0.0001 // epsilon

# define PI 3.14159265359
# define PI_2 PI / 2
# define PI2 PI * 2
# define PI3_2 3 * PI / 2
# define RD PI / 180 // radians in degree

# define FOV 70

# define TEXTURES_LIST "./materials/textures.list"
# define WALL_TYPES_LIST "./materials/wall_types.list"

int		movement(t_wrld *world, SDL_Event *e);
int		game(t_sdl *sdl, t_wrld *world);

# endif