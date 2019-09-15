/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 05:12:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 05:47:03 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_framebuff   *ft_framebuff_init(size_t w, size_t h, uint32_t color)
{
  // CHECK for not alloc
  t_framebuff *fr;
  fr = (t_framebuff*)ft_memalloc(sizeof(t_framebuff);
  fr->img = malloc(w * h * sizeof(uint32_t));
  fr->w = w;
  fr->h = h;
  return (fr);
}

void    set_pixel(t_framebuff **fbuf, const size_t x, const size_t y, const uint32_t color)
{
    //assert(img.size()==w*h && x<w && y<h);
    (*fbuf)->img[x+y*w] = color;
}

void    draw_rectangle(t_framebuff **fbuf, const size_t rect_x, const size_t rect_y, const size_t rect_w, const size_t rect_h, const uint32_t color)
{
    //assert(img.size()==w*h);
    for (size_t i=0; i<rect_w; i++) {
        for (size_t j=0; j<rect_h; j++) {
            size_t cx = rect_x+i;
            size_t cy = rect_y+j;
            if (cx<w && cy<h) // no need to check for negative values (unsigned variables)
                set_pixel(cx, cy, color);
        }
    }
}

void    clear(t_framebuff **fbuf, const uint32_t color)
{
  int   i;
  int   j;
  Uint32 *framebuffer; // the image itself, initialized to white

  if ((*fbuf)->img)
    free((*fbuf)->img);
  framebuffer = malloc((*fbuf)->w * (*fbuf)->h * sizeof(Uint32));
  (*fbuf)->img = framebuffer;
    /////init with color
    i = -1;
    while (++i < (*fbuf)->h)
    {
      j = -1;
      while (++j < (*fbuf)->w)
        framebuffer[j + i*(*fbuf)->w] = color;
    }
}
