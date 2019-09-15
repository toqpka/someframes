/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 06:40:15 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 06:44:58 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player   *init_player()
{
  t_player    *pl;
  pl = (t_player *)ft_memalloc(sizeof(t_player));
  pl->x = 3.456;
  pl->y = 2.345;
  pl->a = 1.523;
  pl->fov = PI/3.;
  pl->turn = 0;
  pl->walk = 0;
  return (mp);
}
