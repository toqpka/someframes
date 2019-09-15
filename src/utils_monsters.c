/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_monsters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 06:45:39 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 07:01:55 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sprite   *add_sprite(float x, float y, size_t tex_id, float pl_dist)
{//CHECK if no allocate
  t_sprite   *spr;
  spr = (t_sprite *)ft_memalloc(sizeof(t_sprite);
  spr->x = x;
  spr->y = y;
  spr->tex_id = tex_id;
  spr->player_dist = pl_dist;
  return (spr);
}

t_sprite   **init_monsters()
{//CHECK if no allocate
  int         count_monstr;
  int         i;
  t_sprite    **mon_spr;
  count_monstr = 5;
  mon_spr = (t_sprite **)ft_memalloc(count_monstr * sizeof(t_sprite *));
  i = -1;
  while (++i < count_monstr)
    *mon_spr = (t_sprite *)ft_memalloc(sizeof(t_sprite));
  mon_spr[0] = add_sprite(3.523, 3.812, 2, 0);
  mon_spr[1] = add_sprite(1.834, 8.765, 0, 0);
  mon_spr[2] = add_sprite(5.323, 5.365, 1, 0);
  mon_spr[3] = add_sprite(14.32, 13.36, 3, 0);
  mon_spr[4] = add_sprite(4.123, 10.76, 1, 0);
  return (mon_spr);
}
