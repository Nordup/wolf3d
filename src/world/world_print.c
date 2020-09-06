/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:10:19 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 13:10:20 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "wolf3d.h"

void	print_wall_type(t_wall_type *wtype)
{
	ft_putstr("\t");
	ft_putnbr(wtype->type);
	ft_putstr(" ");
	if (wtype->north)
		ft_putstr(wtype->north->name);
	else
		ft_putstr("null");
	ft_putstr(" ");
	if (wtype->south)
		ft_putstr(wtype->south->name);
	else
		ft_putstr("null");
	ft_putstr(" ");
	if (wtype->east)
		ft_putstr(wtype->east->name);
	else
		ft_putstr("null");
	ft_putstr(" ");
	if (wtype->west)
		ft_putstr(wtype->west->name);
	else
		ft_putstr("null");
	ft_putstr("\n");
}

void	print_wall_types(t_wall_type *wtype)
{
	if (wtype != NULL)
	{
		ft_putendl("wtype list:");
		while (1)
		{
			print_wall_type(wtype);
			if (wtype->next == NULL)
				break ;
			wtype = wtype->next;
		}
	}
	else
	{
		ft_putendl("wtype == NULL");
	}
}

void	print_textures(t_texture *tex)
{
	if (tex)
	{
		ft_putendl("textures list:");
		while (1)
		{
			ft_putstr("\t");
			ft_putstr(tex->name);
			ft_putstr(" ");
			ft_putnbr(tex->h);
			ft_putstr(" ");
			ft_putnbr(tex->w);
			ft_putstr("\n");
			if (tex->next == NULL)
				break ;
			tex = tex->next;
		}
	}
	else
	{
		ft_putendl("textures == NULL");
	}
}

void	print_maps(t_map *map)
{
	if (map)
	{
		ft_putendl("maps list:");
		while (1)
		{
			ft_putstr("\t");
			ft_putstr(map->name);
			ft_putstr(" ");
			ft_putnbr(map->h);
			ft_putstr(" ");
			ft_putnbr(map->w);
			ft_putstr(" ");
			ft_putstr(" ");
			ft_putstr("\n");
			if (map->next == NULL)
				break ;
			map = map->next;
		}
	}
	else
	{
		ft_putendl("maps == NULL");
	}
}
