/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:27:40 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/11 22:35:40 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void     draw_rectangle(uint32_t **img, const size_t img_w, const size_t img_h, const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color)
{
    int size = img_w*img_h;
    for (size_t i=0; i<w; i++) {
        for (size_t j=0; j<h; j++) {
            size_t cx = x+i;
            size_t cy = y+j;
            if (cx>=img_w || cy>=img_h) continue; // no need to check negative values, (unsigned variables)
            (*img)[cx + cy*img_w] = color;
        }
    }
  return ;
}

void    ft_drop_map_ppm(const char *map, const size_t map_w, const size_t map_h, t_sdl *sdl)
{
int i,j;
const size_t win_w = 1024; // image width
const size_t win_h = 512;  // image height
Uint32 *framebuffer; // the image itself, initialized to white
framebuffer = malloc(win_w * win_h * sizeof(Uint32));
/////init with color
i = -1;
while (++i < win_h)
{
  j = -1;
  while (++j < win_w)
    framebuffer[j + i*win_w] = pack_color(255, 255, 255);
}
/////
const size_t ncolors = 10;
uint32_t colors[ncolors];
for (size_t i=0; i<ncolors; i++) {
  colors[i] = pack_color(rand()%255, rand()%255, rand()%255);
}

const size_t rect_w = win_w/(map_w*2);
const size_t rect_h = win_h/map_h;
char **str_frame;
str_frame = (char**)malloc(360 * sizeof(char*));

for (size_t frame=0; frame<360; frame++) {

       ///        !!! std::stringstream ss;
       ///         !!ss << std::setfill('0') << std::setw(5) << frame << ".ppm";
       ////  HADO FREEE //// !!
       str_frame[frame] = ft_strjoin("./frame", ft_strjoin(ft_itoa(frame), ".ppm"));
       sdl->player_a += 2*PI/360;

       /////init with color white (clear)
       i = -1;
       while (++i < win_h)
       {
         j = -1;
         while (++j < win_w)
           framebuffer[j + i*win_w] = pack_color(255, 255, 255);
       }
       /////

       for (size_t j=0; j<map_h; j++) { // draw the map
           for (size_t i=0; i<map_w; i++) {
               if (map[i+j*map_w]==' ') continue; // skip empty spaces
               size_t rect_x = i*rect_w;
               size_t rect_y = j*rect_h;
               size_t icolor = map[i+j*map_w] - '0';
               //assert(icolor<ncolors);
               draw_rectangle(&framebuffer, win_w, win_h, rect_x, rect_y, rect_w, rect_h, colors[icolor]);
           }
    }
}


int frame = 0;
for (size_t i=0; i<win_w/2; i++) { // draw the visibility cone AND the "3D" view
        float angle = sdl->player_a-FOV/2 + FOV*i/(float)(win_w/2);

       for (float t=0; t<20; t+=.01) {
            float cx = sdl->player_x + t*cos(angle);
            float cy = sdl->player_y + t*sin(angle);

            size_t pix_x = cx*rect_w;
            size_t pix_y = cy*rect_h;
            framebuffer[pix_x + pix_y*win_w] = pack_color(160, 160, 160); // this draws the visibility cone

            if (map[(int)(cx)+(int)(cy)*map_w]!=' ') { // our ray touches a wall, so draw the vertical column to create an illusion of 3D
                    size_t icolor = map[(int)(cx)+(int)(cy)*map_w] - '0';
                    //assert(icolor<ncolors);
                    size_t column_height = win_h/t;
                    draw_rectangle(&framebuffer, win_w, win_h, win_w/2+i, win_h/2-column_height/2, 1, column_height, colors[icolor]);
                    break;
          }
        }

      drop_ppm_image(str_frame[frame], framebuffer, win_w, win_h);
      ((frame > 359) ? (frame=359) : (frame++));
   }

drop_ppm_image("./out1.ppm", framebuffer, win_w, win_h);
return ;
}
