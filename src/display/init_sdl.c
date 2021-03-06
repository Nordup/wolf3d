/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfalkrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 12:25:54 by mfalkrea          #+#    #+#             */
/*   Updated: 2020/09/06 12:25:56 by mfalkrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#define LOADING_IMAGE "./materials/loading/loading.bmp"

void	loading_image(t_sdl *sdl)
{
	SDL_Surface *image;
	SDL_Texture	*texture;

	image = SDL_LoadBMP(LOADING_IMAGE);
	texture = SDL_CreateTextureFromSurface(sdl->ren, image);
	SDL_RenderCopy(sdl->ren, texture, NULL, NULL);
	SDL_RenderPresent(sdl->ren);
}

t_sdl	*init_sdl(void)
{
	t_sdl		*sdl;
	SDL_Surface *image;
	SDL_Texture	*texture;

	sdl = (t_sdl*)malloc(sizeof(t_sdl));
	sdl->image = (Uint32*)malloc(sizeof(Uint32) * WIN_SIZE);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		quit("SDL_Init Error");
	if (!(sdl->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
		quit("SDL_CreateWindow Error");
	if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		SDL_DestroyWindow(sdl->win);
		quit("SDL_CreateRenderer Error");
	}
	loading_image(sdl);
	if (!(sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_W, WIN_H)))
	{
		SDL_DestroyWindow(sdl->win);
		quit("SDL_CreateTexture Error");
	}
	return (sdl);
}
