#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"
# define WALL_SIZE 600
# define WALL_STEP (FOV * RD) / WIN_W

typedef struct s_traycasting {
	float	dis;
	t_bool	hor_ver; // 1-hor; 0-ver
	int		wall_type;
} t_tcasting;

int 	rendering(Uint32 *img, t_wrld *wrld);
/** algoritm - https://permadi.com/1996/05/ray-casting-tutorial-7
 * */
t_tcasting	ray_casting(t_map *map, t_pnt pnt, float alp);
int			wall_draw(Uint32 *img, float dist, t_bool hor_ver, int wall_type,  int column);

#endif