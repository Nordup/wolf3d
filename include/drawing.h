#ifndef DRAWING_H
# define DRAWING_H

int		draw_point(Uint32 *img, t_pnt win_map, t_pnt a, Uint32 clr);
int		draw_line(Uint32 *img, t_pnt win_map, t_pnt a, float rad, float dis, Uint32 clr);
int		fill_square(Uint32 *img, t_pnt a, t_pnt b, Uint32 clr); // draw_map.c
int		draw_map(Uint32 *img, t_map *map);

#endif