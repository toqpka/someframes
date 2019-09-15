/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 06:21:26 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/15 06:39:54 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map   *init_map()
{
  const char map22[] =  "0000222222220000"\
                        "1              5"\
                        "1              5"\
                        "1     01111    5"\
                        "0     0        5"\
                        "0     3     1155"\
                        "0   1000       5"\
                        "0   3  0       5"\
                        "5   4  100011  5"\
                        "5   4   1      4"\
                        "0       1      4"\
                        "2       1  44444"\
                        "0     000      4"\
                        "0 111          4"\
                        "0              4"\
                        "0002222244444444";
  t_map    *mp;
  mp = (t_map *)ft_memalloc(sizeof(t_map));
  mp->w = 16;
  mp->h = 16;
  mp->map = map22;
  return (mp);
}

int       map_get(t_map *mp, const size_t i, const size_t j)
{
  //  assert(i<w && j<h && sizeof(map) == w*h+1);
    return (mp->map[i+j*mp->w] - '0');
}

uint8_t   map_is_empty(t_map *mp, const size_t i, const size_t j)
{
//    assert(i<w && j<h && sizeof(map) == w*h+1);
    return (mp->map[i+j*mp->w] == ' ');
}
