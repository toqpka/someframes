/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:30:29 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/09/11 23:13:56 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include "structs.h"
# include "prototypes.h"

# define WIN_TITLE "Wolf3D - SDL"

//# define FOV 70

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

// player position
# define PLAYER_BEGIN_X 3.456
# define PLAYER_BEGIN_Y 2.345
// player view direction (angle)
# define PLAYER_BEGIN_A 1.523
/*
**	Pi value.
*/
# define PI 3.141592
# define FOV PI/3.

/*
**	Absolute value of \param var macros.
*/
# define ABS(var) ((var) < 0) ? -(var) : (var)

/*
**	Convert \param deg value from degrees to radians.
*/
# define RAD(deg) (((deg) * PI) / 180.0)

/*
** Lesser value among the two.
*/
# define MIN(a,b) (((a)<(b))?(a):(b))

/*
** Greatest value among the two.
*/
# define MAX(a,b) (((a)>(b))?(a):(b))

#endif
