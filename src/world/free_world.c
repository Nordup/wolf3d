/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:27:38 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:27:39 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void		free_wall(t_wall *wall)
{
	if (wall != NULL)
	{
		if (wall->tex != NULL)
			free(wall->tex);
		free(wall);
	}
}

void		free_world(t_wrld *world)
{
	int	i;

	if (world != NULL)
	{
		if (world->map != NULL)
		{
			if (world->map->box != NULL)
			{
				i = 0;
				while (i < world->map->h)
				{
					if (world->map->box[i] != NULL)
						free(world->map->box[i]);
					i++;
				}
				free(world->map->box);
			}
			free(world->map);
		}
		free_wall(world->wall);
		free(world);
	}
}
