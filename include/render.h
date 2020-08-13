#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"
# define WALL_SIZE 600
# define WALL_STEP (FOV * RD) / WIN_W

int 	rendering(Uint32 *img, t_wrld *wrld);
/** algoritm - https://permadi.com/1996/05/ray-casting-tutorial-7
 * */
float	ray_casting(t_map *map, t_pnt pnt, float alp);
int		wall_draw(Uint32 *img, float dist, int column, Uint32 clr);

#endif