/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 07:05:25 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 07:28:25 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void ft_load_texture(t_sdltexture **tex, char *filename, const uint32_t format)
{
  (*tex)->texture = NULL;
  (*tex)->img_w = 0;
  (*tex)->img_h = 0;
  (*tex)->count = 0;
  (*tex)->size = 0;
  (*tex)->img = 0;
  return;
}

t_sdltexture *init_texwalls()
{
  t_sdltexture    *tex_w;
  tex_w = (t_sdltexture *)ft_memalloc(sizeof(t_sdltexture));
  ft_load_texture(&tex_w, "textures/walltext.xpm", SDL_PIXELFORMAT_ABGR8888);
  return (tex_w);
}

t_sdltexture *init_texmonst()
{
  t_sdltexture    *tex_m;
  tex_m = (t_sdltexture *)ft_memalloc(sizeof(t_sdltexture));
  ft_load_texture(&tex_m, "textures/pacman1.XPM", SDL_PIXELFORMAT_ABGR8888);
  return (tex_m);
}

uint32_t ft_texture_get_p(t_sdltexture    **tex_w, const size_t i, const size_t j, const size_t idx) const; // get the pixel (i,j) from the texture idx
uint32_t *get_scaled_column(t_sdltexture    **tex_w, const size_t texture_id, const size_t tex_coord, const size_t column_height) const; // retrieve one column (tex_coord) from the texture texture_id and scale it to the destination size
