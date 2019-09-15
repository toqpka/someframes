/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:08 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 05:27:37 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static uint8_t init_sdl(t_sdl **sdl)
{
  	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
  	{
  		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
  		return (0);
  	}
  	else
  	{
  		if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
  			printf( "Warning: Linear texture filtering not enabled!" );
  		(*sdl)->win = SDL_CreateWindow( WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN );
  		if ( (*sdl)->win == NULL )
  		{
  			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
  			return (0);
  		}
  		else
  		{
        //(*sdl)->screen = SDL_GetWindowSurface( (*sdl)->win );
  			(*sdl)->render = SDL_CreateRenderer( (*sdl)->win, -1, SDL_RENDERER_ACCELERATED );
  			if ( (*sdl)->render == NULL )
  			{
  				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
  				return (0);
  			}
  			else
  				SDL_SetRenderDrawColor( (*sdl)->render, 0xFF, 0xFF, 0xFF, 0xFF );
  		}
  	}
  	return (1);
}

void ft_init(t_sdl **sdl)
{
  if (!((*sdl) = ft_memalloc(sizeof(t_sdl))))
		ft_print_error_exit(&ft_putendl, "Error_memalloc_sdl");
  if (!((*sdl)->tex = ft_memalloc(sizeof(t_sdltexture))))
  	ft_print_error_exit(&ft_putendl, "Error_memalloc_sdltextr");
  (*sdl)->win = NULL;
  (*sdl)->screen = NULL;
  (*sdl)->image = NULL;
  (*sdl)->render = NULL;
  (*sdl)->run_main = 1;
  (*sdl)->player_x = PLAYER_BEGIN_X;
  (*sdl)->player_y = PLAYER_BEGIN_Y;
  (*sdl)->player_a = PLAYER_BEGIN_A;
  (*sdl)->tex->texture = NULL;
  (*sdl)->tex->textr_w = 0;
  (*sdl)->tex->textr_h = 0;
  if (!(init_sdl(sdl)))
    ft_print_error_exit(&ft_putendl, "Error_sdl");
  return ;
}

void ft_close(t_sdl **sdl)
{
  SDL_DestroyTexture((*sdl)->tex->texture);
	SDL_DestroyRenderer((*sdl)->render);
	SDL_DestroyWindow((*sdl)->win);
	(*sdl)->win = NULL;
	(*sdl)->render = NULL;
	IMG_Quit();
	SDL_Quit();
  return ;
}
