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

typedef struct s_wall {
	Uint32	*tex; // column
	int		size;
} t_wall;

typedef struct s_texture {
	char				*name;
	int					w;
	int					h;
	int					**clr;
	struct s_texture	*next;
} t_texture;

/**
 * link to texture
 * 
typedef struct s_wall_type {
	int					type;
	t_texture			*north;
	t_texture			*south;
	t_texture			*east;
	t_texture			*west;
	struct s_wall_type	*next;
} t_wall_type;*/

// name of texture
typedef struct s_wall_type {
	int					type;
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	struct s_wall_type	*next;
} t_wall_type;

typedef struct s_wrld {
	t_prsn		*prsn;
	t_map		*map;
	t_wall		*wall;
	t_wall_type	*type;
	t_texture	*tex;
} t_wrld;

t_map	*init_map(void);
t_prsn	*init_person(void);
t_wrld	*init_world(void);
int		free_world(t_wrld *world);


t_pnt	newpnt(float x, float y);
void	update_step(t_prsn *person);
void	set_wall_size(t_wrld *wrld, float size);


// parsing
int			*get_int_array(char *line, int size);
char		*get_content(char *line);
int			**read_map(char *file);
t_texture	*read_textures_list(void);
t_wall_type	*read_wall_types(void);

#endif