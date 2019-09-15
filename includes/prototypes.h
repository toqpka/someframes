/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:20:57 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 07:20:30 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_PROTOTYPES_H
# define WOLF3D_PROTOTYPES_H

/*
** Main functions
*/
void      ft_close(t_sdl **sdl);
void      ft_init(t_sdl **sdl);

/*
** Trash functions
*/
uint32_t  pack_color(const uint8_t r, const uint8_t g, const uint8_t b);
void      unpack_color( uint32_t color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a);
void      drop_ppm_image(char *filename, uint32_t *image, size_t w, size_t h);
void      draw_rectangle(uint32_t **img, const size_t img_w, const size_t img_h, const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color);
void      ft_drop_map_ppm(const char *map, const size_t map_w, const size_t map_h, t_sdl *sdl);
/*
** load_textr functions
*/
uint8_t       load_texture(char *filename, uint32_t **texture, size_t *text_size, size_t *text_cnt, t_sdl **sdl);
uint32_t      *texture_column(uint32_t **img, const size_t texsize, const size_t ntextures, const size_t texid, const size_t texcoord, const size_t column_height);
//////////////////////////
/*
** new stuff for  texture;
*/
//uint32_t      *get(const size_t i, const size_t j, const size_t idx);                                          // get the pixel (i,j) from the texture idx
//uint32_t      *get_scaled_column(const size_t texture_id, const size_t tex_coord, const size_t column_height); // retrieve one column (tex_coord) from the texture texture_id and scale it to the destination size

//new textrure
uint32_t      ft_texture_get_p(t_sdltexture    **tex_w, const size_t i, const size_t j, const size_t idx) const; // get the pixel (i,j) from the texture idx
uint32_t      *get_scaled_column(t_sdltexture    **tex_w, const size_t texture_id, const size_t tex_coord, const size_t column_height) const; // retrieve one column (tex_coord) from the texture texture_id and scale it to the destination size


/*
** new stuff framebuffer;
*/
void            clear(const uint32_t color);
void            set_pixel(const size_t x, const size_t y, const uint32_t color);
void            draw_rectangle(const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color);
t_framebuff     *ft_framebuff_init(size_t w, size_t h, uint32_t color);

/*
** new stuff map;
*/
int       map_get(t_map *mp, const size_t i, const size_t j);
uint8_t   map_is_empty(t_map *mp, const size_t i, const size_t j);
#endif
