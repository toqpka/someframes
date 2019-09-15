/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_ppm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:27:40 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 04:09:05 by gwaymar-         ###   ########.fr       */
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


Uint32 *walltext; // textures for the walls
size_t walltext_size;  // texture dimensions (it is a square)
size_t walltext_cnt;   // number of different textures in the image
if (!load_texture("./textures/walltext.xpm", &walltext, &walltext_size, &walltext_cnt, &sdl))
  ft_print_error_exit(&ft_putendl, "Error_load_texture");

  char **str_frame;
  str_frame = (char**)malloc(360 * sizeof(char*));

  char **str_frame_bmp;
  str_frame_bmp = (char**)malloc(360 * sizeof(char*));

const size_t rect_w = win_w/(map_w*2);
const size_t rect_h = win_h/map_h;
for (size_t j=0; j<map_h; j++) { // draw the map
  for (size_t i=0; i<map_w; i++) {
            if (map[i+j*map_w]==' ') continue; // skip empty spaces
            size_t rect_x = i*rect_w;
            size_t rect_y = j*rect_h;
            size_t texid = map[i+j*map_w] - '0';
            //   assert(icolor<ncolors);
            draw_rectangle(&framebuffer, win_w, win_h, rect_x, rect_y, rect_w, rect_h, walltext[texid*walltext_size]);
  }
}

for (size_t i=0; i<win_w/2; i++) { // draw the visibility cone AND the "3D" view
  float angle = sdl->player_a-FOV/2 + FOV*i/(float)(win_w/2);
  for (float t=0; t<20; t+=.01) {
    float cx = sdl->player_x + t*cos(angle);
    float cy = sdl->player_y + t*sin(angle);

    int pix_x = cx*rect_w;
    int pix_y = cy*rect_h;
    framebuffer[pix_x + pix_y*win_w] = pack_color(160, 160, 160); // this draws the visibility cone

    if (map[(int)(cx)+(int)(cy)*map_w]!=' ') { // our ray touches a wall, so draw the vertical column to create an illusion of 3D
        size_t texid = map[(int)(cx)+(int)(cy)*map_w] - '0';
//        assert(texid<walltext_cnt);
        size_t column_height = win_h/(t*cos(angle-sdl->player_a));

        float hitx = cx - floor(cx+.5); // hitx and hity contain (signed) fractional parts of cx and cy,
        float hity = cy - floor(cy+.5); // they vary between -0.5 and +0.5, and one of them is supposed to be very close to 0
        int x_texcoord = hitx*walltext_size;
        if (fabs(hity)>fabs(hitx)) { // we need to determine whether we hit a "vertical" or a "horizontal" wall (w.r.t the map)
             x_texcoord = hity*walltext_size;
        }
        if (x_texcoord<0) x_texcoord += walltext_size; // do not forget x_texcoord can be negative, fix that
        //assert(x_texcoord>=0 && x_texcoord<(int)walltext_size);

        uint32_t *column = texture_column(&walltext, walltext_size, walltext_cnt, texid, x_texcoord, column_height);
        pix_x = win_w/2+i;
        for (size_t j=0; j<column_height; j++) {
            pix_y = j + win_h/2-column_height/2;
            if (pix_y<0 || pix_y>=(int)win_h) continue;
            framebuffer[pix_x + pix_y*win_w] = column[j];
        }
        break;
    }
}
}


// тест отрисовки куска текстуры
    // const size_t texid = 1; // draw the 4th texture on the screen
    // for (size_t i=0; i<walltext_size; i++) {
    //     for (size_t j=0; j<walltext_size; j++) {
    //         framebuffer[i+j*win_w] = walltext[i + texid*walltext_size + j*walltext_size*walltext_cnt];
    //     }
    // }

    drop_ppm_image("./out.ppm", framebuffer, win_w, win_h);


       // drop_ppm_image(str_frame[frame], framebuffer, win_w, win_h);
       // SDL_Surface *image = IMG_Load (str_frame[frame]);
       // str_frame_bmp[frame] = ft_strjoin("./framesBMP/frame", ft_strjoin(ft_itoa(frame), ".png"));
       // IMG_SavePNG(image, str_frame_bmp[frame]);
       // SDL_FreeSurface(image);

return ;
}
