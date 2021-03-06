/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:28:53 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:28:55 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_wall_type	*find_wall_type(t_wall_type *wtype, int type)
{
	if (wtype)
		while (1)
		{
			if (wtype->type == type)
				return (wtype);
			if (wtype->next != NULL)
				wtype = wtype->next;
			else
				break ;
		}
	return (NULL);
}

t_texture	*cardinal_tex(t_wall_type *wtype, int c_point)
{
	if (wtype == NULL)
		return (NULL);
	if (c_point == North)
		return (wtype->north);
	else if (c_point == South)
		return (wtype->south);
	else if (c_point == East)
		return (wtype->east);
	else
		return (wtype->west);
}

float		get_width(t_rcasting rc)
{
	if (rc.cardinal_point == North)
		return (1 - (rc.cast_pnt.x - (int)rc.cast_pnt.x));
	else if (rc.cardinal_point == South)
		return (rc.cast_pnt.x - (int)rc.cast_pnt.x);
	else if (rc.cardinal_point == East)
		return (1 - (rc.cast_pnt.y - (int)rc.cast_pnt.y));
	else
		return (rc.cast_pnt.y - (int)rc.cast_pnt.y);
}

int			get_color(t_texture *tex, int w, int i, int size)
{
	float win_wall;
	float h;
	float x;

	if (size < WIN_H)
	{
		win_wall = (float)i / size;
	}
	else
	{
		x = (size - WIN_H) / 2 + i;
		win_wall = x / size;
	}
	win_wall = 1 - win_wall;
	h = tex->h * win_wall;
	if (w >= tex->w || h >= tex->h || tex->w < 0 || tex->h < 0)
		return (RED);
	else
		return (tex->clr[(int)h][w]);
}

int			set_wall_texture(t_wrld *wrld, t_rcasting rc)
{
	t_wall_type	*wtype;
	t_texture	*tex;
	float		w;
	int			i;

	wtype = find_wall_type(wrld->type, rc.type);
	tex = cardinal_tex(wtype, rc.cardinal_point);
	w = get_width(rc);
	i = 0;
	if (tex == NULL || tex->clr == NULL || tex->name == NULL)
		while (i < wrld->wall->size && i < WIN_H)
		{
			wrld->wall->tex[i] = BLACK;
			i++;
		}
	else
	{
		w = w * tex->w;
		while (i < wrld->wall->size && i < WIN_H)
		{
			wrld->wall->tex[i] = get_color(tex, (int)w, i, wrld->wall->size);
			i++;
		}
	}
	return (0);
}
