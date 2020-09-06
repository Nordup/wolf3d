/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:04:20 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:04:24 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "display.h"
# include "world.h"
# include "render.h"

# define WALL_SIZE 600
# define EPS 0.0001

# define PI 3.14159265359
# define PI_2 PI / 2
# define PI2 PI * 2
# define PI3_2 3 * PI / 2
# define RD PI / 180

# define FOV 70

# define TEXTURES_LIST		"./materials/textures.list"
# define WALL_TYPES_LIST	"./materials/wall_types.list"
# define MAPS_LIST			"./materials/maps.list"

int		movement(t_map *map, SDL_Event *e);
int		game(t_sdl *sdl, t_wrld *world);

#endif
