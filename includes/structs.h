/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:54 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 06:47:59 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCTS_H
# define WOLF3D_STRUCTS_H

typedef struct		s_framebuff
{
  size_t      w; // image dimensions
  size_t      h;
  uint32_t    *img; // storage container
}                 t_framebuff;

typedef struct		s_map
{
  size_t        w;
  size_t        h; // overall map dimensions
  const char    *map;
}                 t_map;

typedef struct		s_player
{
  float   x;
  float   y; // position
  float   a;    // view direction
  float   fov;  // field of view
  int     turn;
  int     walk;
}                 t_player;

typedef struct		s_sprite
{
  float     x;
  float     y;
  size_t    tex_id;
  float     player_dist;
  //uint8_t   operator;
}                 t_sprite;

typedef struct		s_sdltexture
{
  SDL_Texture    *texture;
  size_t         img_w;
  size_t         img_h; // overall image dimensions
  size_t         count;
  size_t         size;  // number of textures and size in pixels
  uint32_t       *img; // textures storage container
}                 t_sdltexture;

typedef struct		s_gamest
{
  t_map           *map;
  t_player        *player;
  t_sprite        **monsters;
  t_sdltexture    *tex_walls;
  t_sdltexture    *tex_monst;
}                 t_gamest;

typedef struct		s_sdl
{
  SDL_Window      *win;
  SDL_Surface     *screen;
  SDL_Surface     *image;
  SDL_Event       event;
  SDL_Renderer    *render;
  uint8_t         run_main;
  float           player_x;
  float           player_y;
  float           player_a;
  t_sdltexture    *tex;
}                 t_sdl;

#endif
