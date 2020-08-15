#include "world.h"

int		free_world(t_wrld *world) {

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

		// free person
		if (world->prsn != NULL)
			free(world->prsn);
			
		// free texture
		if (world->tex != NULL) {
			if (world->tex->clmn != NULL)
				free(world->tex->clmn);
			free(world->tex);
		}
		free(world);
	}
}