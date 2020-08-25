#include "world.h"

void		free_world(t_wrld *world) {

	// free world
	if (world != NULL) {

		// free map
		if (world->map != NULL) {

			// free box
			if (world->map->box != NULL) {
				int	i = 0;
				while (i < world->map->h) {
					if (world->map->box[i] != NULL)
						free(world->map->box[i]);
					i++;
				}
				free(world->map->box);
			}
			free(world->map);
		}
			
		// free texture
		if (world->wall != NULL) {
			if (world->wall->tex != NULL)
				free(world->wall->tex);
			free(world->wall);
		}
		free(world);
	}
}