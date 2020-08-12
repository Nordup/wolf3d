#ifndef WORLD_H
# define WORLD_H

# include <stdio.h> // malloc
# include <stdlib.h> // free

# define PI 3.14159265359

typedef struct s_prsn {
	float	px;
	float	py;
	float	dir;
} t_prsn;

typedef struct s_map {
	int		w;
	int		h;
	int		**box; // for now
} t_map;

typedef struct s_wrld {
	t_prsn	*prsn;
	t_map	*map;
}	t_wrld;


t_wrld	*init_world(void);
int		delete_world(t_wrld	*world);

#endif