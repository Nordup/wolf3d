/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:03:15 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:08:33 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# ifdef __APPLE__
#  include <SDL.h>
# else
#  include <SDL2/SDL.h>
# endif

# define WIN_W 1500
# define WIN_H 900
# define WIN_SIZE WIN_H * WIN_W

# define BLACK (Uint32)0x000000
# define WHITE (Uint32)0xffffff
# define RED (Uint32)0xff0000
# define GREEN (Uint32)0x00ff00
# define BLUE (Uint32)0x42c5f5
# define WALL_CLR (Uint32) 0x747a78
# define FLOOR (Uint32) 0x5ab514

typedef struct		s_sdl
{
	SDL_Renderer	*ren;
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Texture		*tex;
	Uint32			*image;
}					t_sdl;

int					quit(char *s);
int					quit_sdl(t_sdl *sdl);
t_sdl				*init_sdl(void);

#endif
