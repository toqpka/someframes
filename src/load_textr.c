/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:06:52 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 03:41:35 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

uint32_t *texture_column(uint32_t **img, const size_t texsize, const size_t ntextures, const size_t texid, const size_t texcoord, const size_t column_height)
{
    const size_t img_w = texsize*ntextures;
    const size_t img_h = texsize;
    uint32_t *column;
    //assert(img.size()==img_w*img_h && texcoord<texsize && texid<ntextures);
    column = (uint32_t *)malloc(column_height * sizeof(uint32_t));
    // DELENIE na 0
    for (size_t y=0; y<column_height; y++) {
        size_t pix_x = texid*texsize + texcoord;
        size_t pix_y = (y*texsize)/column_height;
        column[y] = (*img)[pix_x + pix_y*img_w];
    }
    return column;
  }

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}



uint8_t load_texture(char *filename, uint32_t **texture, size_t *text_size, size_t *text_cnt, t_sdl **sdl)
{
  SDL_Surface     *pixmap;
  SDL_PixelFormat *fmt;
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
  uint8_t a = 0;
  uint8_t *p;
  uint32_t data;


  SDL_RWops *rwop;
  rwop=SDL_RWFromFile(filename, "rb");
  pixmap=IMG_LoadXPM_RW(rwop);
  if(!pixmap) {
  printf("IMG_LoadXPM_RW: %s\n", IMG_GetError());
  // handle error
  }
  *text_cnt = pixmap->w/pixmap->h;
  *text_size = pixmap->w/(*text_cnt);
  if (pixmap->w != pixmap->h*(int)(*text_cnt))
  {
    SDL_FreeSurface(pixmap);
    ft_print_error_exit(&ft_putendl, "Error: the texture file must contain N square textures packed horizontally");
  }

  Uint32 *framebuffer; // the image itself, initialized to white
  Uint32 temp;
  framebuffer = malloc(pixmap->w*pixmap->h * sizeof(Uint32));
  *texture = framebuffer;
  for (int j=0; j<pixmap->h; j++) {
    for (int i=0; i<pixmap->w; i++) {
      data = getpixel(pixmap, i, j);
      SDL_GetRGB(data, pixmap->format, &r, &g, &b);
      //p = (Uint8 *)pixmap->pixels + (i+j*pixmap->w)*4;  //(png)  bitpp (4)   bytestpp (32) worcked!!!
      //p = (Uint8 *)pixmap->pixels + (i+j*pixmap->w)*pixmap->format->BytesPerPixel;  //(xpm)   bitpp (1)  bitpp (8)worcked!!!
      // //GOOD checked
      // r = p[2];
      // g = p[1];
      // b = p[0];
  // index = *((Uint8 *)pixmap->pixels + (i+j*pixmap->w)*pixmap->format->BytesPerPixel);
  // color=&fmt->palette->colors[index];
      (*texture)[i+j*pixmap->w] = pack_color(r, g, b);
    }
  }
  SDL_FreeSurface(pixmap);
  return (1);
}
