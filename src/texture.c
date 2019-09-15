/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 04:56:22 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 05:03:32 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int wall_x_texcoord(const float hitx, const float hity, t_sdltexture **tex_walls) {
    float x = hitx - floor(hitx+.5); // x and y contain (signed) fractional parts of hitx and hity,
    float y = hity - floor(hity+.5); // they vary between -0.5 and +0.5, and one of them is supposed to be very close to 0
    int tex = x * *(tex_walls).size;
    if (fabs(y)>fabs(x)) // we need to determine whether we hit a "vertical" or a "horizontal" wall (w.r.t the map)
        tex = y* (*tex_walls).size;
    if (tex<0) // do not forget x_texcoord can be negative, fix that
        tex += (*tex_walls).size;
    //assert(tex>=0 && tex<(int)tex_walls.size);
    return tex;
}
