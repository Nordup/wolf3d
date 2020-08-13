#ifndef DRAWING_H
# define DRAWING_H

# include "wolf3d.h"

# define BLACK (Uint32)0x0
# define WHITE (Uint32)0xffffff
# define RED (Uint32)0xff0000
# define GREEN (Uint32)0x00ff00
# define BLUE (Uint32)0x42c5f5
# define WALL_CLR (Uint32) 0x747a78
# define FLOOR (Uint32) 0x5ab514


t_pnt	newpnt(float x, float y); // draw_point.c
int		draw_point(Uint32 *img, t_pnt win_map, t_pnt a, Uint32 clr);
int		fill_square(Uint32 *img, t_pnt a, t_pnt b, Uint32 clr); // draw_map.c
int		draw_map(Uint32 *img, t_map *map);
int		draw_line(Uint32 *img, t_pnt win_map, t_pnt a, float rad, float dis, Uint32 clr);

#endif