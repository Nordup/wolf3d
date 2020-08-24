#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"

enum		cardinal_points {
	North, South, East, West
};

typedef struct s_raycasting {
	float	dis;
	int		cardinal_point; // 1-north;2-south;3-east;4-west;
	int		type;
	t_pnt	cast_pnt;
} t_rcasting;

/** algoritm - https://permadi.com/1996/05/ray-casting-tutorial-7
 * */
t_rcasting	ray_casting(t_map *map, t_pnt pnt, float alp);
float		in_two_pi(float alp);
int 		rendering(Uint32 *img, t_wrld *wrld);

int			set_wall_texture(t_wrld *wrld, t_rcasting rc);
int			wall_draw(Uint32 *img, t_wall *wall,  int column);

#endif