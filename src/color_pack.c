/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:05:37 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/11 21:30:39 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b)
{
  uint8_t a;
  a = 255;
  //return (r | g << 8 | b << 16 | a << 24);
  return ((a<<24) + (b<<16) + (g<<8) + r);
}

void unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
  *r = (color >>  0) & 255;
  *g = (color >>  8) & 255;
  *b = (color >> 16) & 255;
  *a = (color >> 24) & 255;
}

void drop_ppm_image(char *filename, uint32_t *image, size_t w, size_t h)
{
  uint8_t r, g, b, a;
  uint32_t image_size = w*h;
  int dimx = w, dimy = h;

  FILE *ofs = fopen(filename, "wb");
  if (ofs == NULL)
    {
      printf("Error! Could not open file\n");
      exit(-1); // must include stdlib.h
    }
    fprintf(ofs, "P6\n%d %d\n255\n", dimx, dimy);
    for (size_t i = 0; i < image_size; ++i)
    {
        r = g = b = a = 0;
        unpack_color(image[i], &r, &g, &b, &a);
        fprintf(ofs, "%c%c%c",r,g,b); // write to file
    }
    fclose (ofs);
    return ;
}
