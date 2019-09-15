/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stat_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 05:46:25 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 06:46:48 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_gamest    *ft_game_init(void)
{// CHECK for not alloc
  t_gamest    *gstat;
  gstat = (t_gamest *)ft_memalloc(sizeof(t_gamest));
  gstat->map = init_map();
  gstat->player = init_player();
  gstat->monsters = init_monsters();
  gstat->tex_walls = init_texwalls();
  gstat->tex_monst = init_texmonst();
  return (gstat);
}




Texture("../walltext.bmp", SDL_PIXELFORMAT_ABGR8888),  // textures for the walls
Texture("../monsters.bmp", SDL_PIXELFORMAT_ABGR8888)};}
