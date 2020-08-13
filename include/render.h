#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"

int 	rendering(Uint32 *img, t_wrld *wrld);
/** algoritm - https://permadi.com/1996/05/ray-casting-tutorial-7
 * */
float	ray_casting(t_map *map, t_pnt pnt, float alp);

#endif