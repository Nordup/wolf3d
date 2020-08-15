#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"
# define WALL_SIZE 600
# define EPS 0.0001 // epsilon

# define BLACK (Uint32)0x000000
# define WHITE (Uint32)0xffffff
# define RED (Uint32)0xff0000
# define GREEN (Uint32)0x00ff00
# define BLUE (Uint32)0x42c5f5
# define WALL_CLR (Uint32) 0x747a78
# define FLOOR (Uint32) 0x5ab514

enum		cardinal_points {
	North, South, East, West
};

typedef struct s_raycasting {
	float	dis;
	int		cardinal_point; // 1-hor; 0-ver
	t_pnt	cast_pnt;
} t_rcasting;

/** algoritm - https://permadi.com/1996/05/ray-casting-tutorial-7
 * */
t_rcasting	ray_casting(t_map *map, t_pnt pnt, float alp);
float		in_two_pi(float alp);
int 		rendering(Uint32 *img, t_wrld *wrld);

int			set_wall_texture(t_wrld *wrld, t_rcasting rc, int size);
int			wall_draw(Uint32 *img, Uint32 *tex, int wall_size,  int column);

#endif