/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:22:11 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:23:56 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# ifdef __APPLE__
#  include <SDL.h>
# else
#  include <SDL2/SDL.h>
# endif
# include <stdlib.h>
# include <math.h>

# define STEP 0.1

# define TRUE	1
# define FALSE	0

typedef int				t_bool;

typedef struct			s_pnt
{
	float				x;
	float				y;
}						t_pnt;

typedef struct			s_prsn
{
	t_pnt				pnt;
	t_pnt				step;
	float				alp;
}						t_prsn;

typedef struct			s_map
{
	char				*name;
	int					w;
	int					h;
	t_prsn				prsn;
	int					**box;
	struct s_map		*next;
}						t_map;

typedef struct			s_wall
{
	Uint32				*tex;
	int					size;
}						t_wall;

typedef struct			s_texture
{
	char				*name;
	int					w;
	int					h;
	int					**clr;
	struct s_texture	*next;
}						t_texture;

typedef struct			s_wall_type
{
	int					type;
	t_texture			*north;
	t_texture			*south;
	t_texture			*east;
	t_texture			*west;
	struct s_wall_type	*next;
}						t_wall_type;

typedef struct			s_wrld
{
	t_map				*map;
	t_wall				*wall;
	t_wall_type			*type;
	t_texture			*tex;
}						t_wrld;

t_wrld					*init_world(void);
void					free_world(t_wrld *world);
t_pnt					newpnt(float x, float y);
void					update_step(t_prsn *person);
int						*get_clr_array(char *line, int size);
double					*get_double_array(char *line, int size);
int						*get_int_array(char *line, int size);
char					*get_content(char *line);
t_map					*read_map_list(void);
t_texture				*read_texture_list(void);
t_wall_type				*read_wall_types(t_texture *tex);
void					free_int_matrix(int	***matrix, int size);

#endif
