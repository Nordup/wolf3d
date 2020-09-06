/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:27:45 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:27:49 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "wolf3d.h"

t_wall	*init_wall(void)
{
	int		size;
	t_wall	*wall;

	size = WIN_H + 1;
	wall = (t_wall*)malloc(sizeof(t_wall));
	wall->tex = (Uint32*)malloc(sizeof(Uint32) * size);
	wall->size = size;
	return (wall);
}

t_wrld	*init_world(void)
{
	t_wrld	*world;

	world = (t_wrld*)malloc(sizeof(t_wrld));
	world->wall = init_wall();
	ft_putendl("Map reading...");
	world->map = read_map_list();
	print_maps(world->map);
	ft_putendl("Texture reading...");
	world->tex = read_texture_list();
	print_textures(world->tex);
	ft_putendl("Wall types reading...");
	world->type = read_wall_types(world->tex);
	print_wall_types(world->type);
	return (world);
}
