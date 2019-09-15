/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:32:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 06:24:36 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main( int argc, char* args[] )
{
	const size_t map_w = 16; // map width
	const size_t map_h = 16; // map height
	const char *map =  "0000222222220000"\
										 "1              0"\
										 "1      11111   0"\
										 "1     0        0"\
										 "0     0  1110000"\
										 "0     3        0"\
										 "0   10000      0"\
										 "0   3   11100  0"\
										 "5   4   0      0"\
										 "5   4   1  00000"\
										 "0       1      0"\
										 "2       1      0"\
										 "0       0      0"\
										 "0 0000000      0"\
										 "0              0"\
										 "0002222222200000"; // our game map
	t_sdl				 	*sdl;
	t_framebuff		*frbuf;
	t_gamest			*gstat;

	ft_framebuff_init(1024, 512, pack_color(255, 255, 255));
	ft_game_init();
	ft_init(&sdl);

	ft_drop_map_ppm(map, map_w, map_h, sdl);

	// SDL_BlitSurface( sdl->image, NULL, sdl->screen, NULL );
	// SDL_UpdateWindowSurface( sdl->win );

	while (sdl->run_main)
	{
		while ( SDL_PollEvent( &(sdl->event) ) != 0 )
		{
			if((SDL_QUIT == sdl->event.type) || (SDL_KEYDOWN == sdl->event.type && SDL_SCANCODE_ESCAPE == sdl->event.key.keysym.scancode))
				sdl->run_main = 0;
			if (SDL_KEYUP==event.type)
			{
				if ('a'==event.key.keysym.sym || 'd'==event.key.keysym.sym) gs.player.turn = 0;
				if ('w'==event.key.keysym.sym || 's'==event.key.keysym.sym) gs.player.walk = 0;
			}
			if (SDL_KEYDOWN==event.type)
			{
				if ('a'==event.key.keysym.sym) gs.player.turn = -1;
				if ('d'==event.key.keysym.sym) gs.player.turn =  1;
				if ('w'==event.key.keysym.sym) gs.player.walk =  1;
				if ('s'==event.key.keysym.sym) gs.player.walk = -1;
			}
		}
	}
	ft_close(&sdl);
	return (0);
}
