/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:21:14 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 18:52:34 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	ft_draw_right_part(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 1240, 80, 0xFFFFFF, "  ZOOM UP: +");
	mlx_string_put(fdf->mlx, fdf->win, 1240, 102, 0xFFFFFF, "ZOOM DOWN: -");
	mlx_string_put(fdf->mlx, fdf->win, 1288, HEIGHT / 2 - 11, 0xFFD700,
	"INFO: H");
	mlx_string_put(fdf->mlx, fdf->win, 1228, HEIGHT / 2 + 11, 0xFFD700,
	"NEXT AUDIO: N");
	mlx_string_put(fdf->mlx, fdf->win, 1228, HEIGHT / 2 + 33, 0xFFD700,
	"PREV AUDIO: P");
	mlx_string_put(fdf->mlx, fdf->win, 1200, HEIGHT - 125, 0xFFFFFF, "RESET: \
	BACKSPACE");
	mlx_string_put(fdf->mlx, fdf->win, 1200, HEIGHT - 103, 0xFFFFFF, " EXIT: \
	ESC");
}

static inline void	ft_draw_left_part(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 80, 0xFFFFFF, "MOVE MAP UP   : W");
	mlx_string_put(fdf->mlx, fdf->win, 10, 103, 0xFFFFFF, "MOVE MAP DOWN : S");
	mlx_string_put(fdf->mlx, fdf->win, 10, 126, 0xFFFFFF, "MOVE MAP LEFT : A");
	mlx_string_put(fdf->mlx, fdf->win, 10, 149, 0xFFFFFF, "MOVE MAP RIGHT: D");
	mlx_string_put(fdf->mlx, fdf->win, 10, 172, 0xFFFFFF, "ALTITUDE UP   : \
	PAGE UP");
	mlx_string_put(fdf->mlx, fdf->win, 10, 195, 0xFFFFFF, "ALTITUDE DOWN : \
	PAGE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 213, 0xFFFFFF, "ROTATE MAP \
	ABOUT X +: ARROW UP");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 191, 0xFFFFFF, "ROTATE MAP \
	ABOUT X -: ARROW DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 169, 0xFFFFFF, "ROTATE MAP \
	ABOUT Y +: ARROW RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 147, 0xFFFFFF, "ROTATE MAP \
	ABOUT Y -: ARROW LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 125, 0xFFFFFF, "ROTATE MAP \
	ABOUT Z +: X");
	mlx_string_put(fdf->mlx, fdf->win, 10, HEIGHT - 103, 0xFFFFFF, "ROTATE MAP \
	ABOUT Z -: Z");
}

void				ft_draw_info_table(t_fdf *fdf)
{
	fdf->info = 1;
	ft_draw_left_part(fdf);
	ft_draw_right_part(fdf);
	if (!fdf->music)
		mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 120, HEIGHT - 35 - 11,
			0xFFFFFF, "Ludovico Einaudi - Indaco");
	else if (fdf->music == 1)
		mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 98, HEIGHT - 35 - 11,
			0xFFFFFF, "Kyivstoner - Babosik");
	else
		mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 80, HEIGHT - 35 - 11,
			0xFFFFFF, "Eldjey - Hey Guys");
}
