/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:25:38 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 21:17:40 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_move_and_rotate_xyz(int key, t_fdf *fdf)
{
	if (key == MACOS_W)
		fdf->curry -= 20;
	else if (key == MACOS_A)
		fdf->currx -= 20;
	else if (key == MACOS_D)
		fdf->currx += 20;
	else if (key == MACOS_S)
		fdf->curry += 20;
	else if (key == MACOS_UP)
		fdf->rot.x_degree += 0.05 * M_PI;
	else if (key == MACOS_DOWN)
		fdf->rot.x_degree -= 0.05 * M_PI;
	else if (key == MACOS_LEFT)
		fdf->rot.y_degree -= 0.05 * M_PI;
	else if (key == MACOS_RIGHT)
		fdf->rot.y_degree += 0.05 * M_PI;
	else if (key == MACOS_Z)
		fdf->rot.z_degree -= 0.05 * M_PI;
	else if (key == MACOS_X)
		fdf->rot.z_degree += 0.05 * M_PI;
}

int			key_mapping(int key, t_fdf *fdf)
{
	if (key == ESC)
		ft_exit(&key);
	if (key == MACOS_W || key == MACOS_A || key == MACOS_D ||
	key == MACOS_S ||key == MACOS_UP || key == MACOS_DOWN || key == MACOS_LEFT
	|| key == MACOS_RIGHT || key == MACOS_Z || key == MACOS_X)
		ft_move_and_rotate_xyz(key, fdf);
	else if (key == MACOS_PLUS || key == MACOS_PL)
		fdf->zoom += 5;
	else if (key == MACOS_MINUS || key == MACOS_MIN)
		fdf->zoom -= 5;
	else if (key == MACOS_ARR_UP)
		fdf->height += 0.25;
	else if (key == MACOS_ARR_DOWN)
		fdf->height -= 0.25;
	// mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero((void *)fdf->img.addr, WIDTH * HEIGHT * 4);
	lets_paint(fdf);
	return (0);
}

int		ft_exit(void *param)
{
	// system("leaks fdf > leaks");
	exit(0);
}