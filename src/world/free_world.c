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

void		free_world(t_wrld *world)
{
	int	i;

	// free world
	if (world != NULL)
	{
		// free map
		if (world->map != NULL)
		{
			// free box
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
		// free texture
		if (world->wall != NULL)
		{
			if (world->wall->tex != NULL)
				free(world->wall->tex);
			free(world->wall);
		}
		free(world);
	}
}
