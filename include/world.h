#ifndef WORLD_H
# define WORLD_H

# define PI 3.14159265359
# define PI_2 PI / 2
# define PI2 PI * 2
# define PI3_2 3 * PI / 2
# define RD PI / 180 // radians in degree

# define STEP 0.1 // person step

typedef struct s_pnt {
	float	x;
	float	y;
} t_pnt;

typedef struct s_prsn {
	t_pnt	pnt;
	t_pnt	delta; // dx, dy
	float	alp; // direction - alpha angel
} t_prsn;

typedef struct s_map {
	int		w;
	int		h;
	int		**box;
	t_pnt	win_map; // WIN sizes divided by map sizes
} t_map;

typedef struct s_wrld {
	t_prsn	*prsn;
	t_map	*map;
}	t_wrld;

#include "wolf3d.h"

int		create_box(t_map *map);
t_wrld	*init_world(void);
int		delete_world(t_wrld	*world);

#endif