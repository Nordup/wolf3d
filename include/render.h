/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:09:50 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:17:11 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "wolf3d.h"

typedef enum	s_cardinal_points
{
	North, South, East, West
}				t_card_pnt;

typedef struct	s_raycasting
{
	float	dis;
	int		cardinal_point;
	int		type;
	t_pnt	cast_pnt;
}				t_rcasting;

float			dis(t_pnt a, t_pnt b);
t_rcasting		ret(int cardinal_point, t_pnt cast_pnt, t_pnt per_pnt, int type);
t_rcasting		vertical(t_map *map, t_pnt pnt, float alp);
t_rcasting		horizontal(t_map *map, t_pnt pnt, float alp);
t_rcasting		ray_casting(t_map *map, t_pnt pnt, float alp);
float			in_two_pi(float alp);
int				rendering(Uint32 *img, t_wrld *wrld, t_map *map);
int				set_wall_texture(t_wrld *wrld, t_rcasting rc);
int				wall_draw(Uint32 *img, t_wall *wall, int column);

#endif
