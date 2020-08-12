#include "world.h"

int		delete_world(t_wrld	*world) {
	if (world->map != NULL)
		free(world->map);
	if (world->prsn != NULL)
		free(world->prsn);
	if (world != NULL)
		free(world);
}