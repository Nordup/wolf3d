#ifndef WORLD_H
# define WORLD_H

#ifdef __APPLE__
#include <SDL.h>
#else
#include <SDL2/SDL.h> // Uint32
#endif
# include <stdlib.h> // malloc, free
# include <math.h> // cos, sin

# define STEP 0.1 // person step
# define TRUE	1
# define FALSE	0

typedef int		t_bool;

typedef struct s_pnt {
	float	x;
	float	y;
} t_pnt;

typedef struct s_prsn {
	t_pnt	pnt;
	t_pnt	step; // dx, dy
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


	t_texture	*tex;
} t_wrld;


t_tex	*init_tex(void);
t_map	*init_map(void);
t_prsn	*init_person(void);
t_wrld	*init_world(void);
void	free_world(t_wrld *world);


t_pnt	newpnt(float x, float y);
void	update_step(t_prsn *person);
// parsing







#endif