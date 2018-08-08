/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:25:38 by aroi              #+#    #+#             */
/*   Updated: 2018/07/29 11:55:59 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			show_help_info(t_fdf *fdf)
{
	if (fdf->info)
	{
		fdf->info = 0;
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
		return ;
	}
	ft_draw_info_table(fdf);
}

static inline void	ft_move_and_rotate_xyz(int key, t_fdf *fdf)
{
	if (key == MACOS_W || key == LINUX_W)
		fdf->curry -= 20;
	else if (key == MACOS_A || key == LINUX_A)
		fdf->currx -= 20;
	else if (key == MACOS_D || key == LINUX_D)
		fdf->currx += 20;
	else if (key == MACOS_S || key == LINUX_S)
		fdf->curry += 20;
	else if (key == MACOS_UP || key == LINUX_UP)
		fdf->rot.x_degree += 0.05 * M_PI;
	else if (key == MACOS_DOWN || key == LINUX_DOWN)
		fdf->rot.x_degree -= 0.05 * M_PI;
	else if (key == MACOS_LEFT || key == LINUX_LEFT)
		fdf->rot.y_degree -= 0.05 * M_PI;
	else if (key == MACOS_RIGHT || key == LINUX_RIGHT)
		fdf->rot.y_degree += 0.05 * M_PI;
	else if (key == MACOS_Z || key == LINUX_Z)
		fdf->rot.z_degree -= 0.05 * M_PI;
	else if (key == MACOS_X || key == LINUX_X)
		fdf->rot.z_degree += 0.05 * M_PI;
}

static inline void	reset(t_fdf *fdf)
{
	fdf->currx = 0.0;
	fdf->curry = 0.0;
	if (fdf->y >= fdf->x)
		fdf->zoom = HEIGHT / fdf->y;
	else
		fdf->zoom = WIDTH / fdf->x;
	fdf->height = 0.1;
	fdf->rot.x_degree = 0.0;
	fdf->rot.y_degree = 0.0;
	fdf->rot.z_degree = 0.0;
}

int					key_mapping(int key, t_fdf *fdf)
{
	system("afplay -v 0.03 ./music/hitbox.mp3 &");
	ft_move_and_rotate_xyz(key, fdf);
	if (key == ESC_BUTTON || key == LINUX_ESC)
		ft_exit();
	else if (key == MACOS_PLUS || key == MACOS_PL || key == LINUX_PLUS)
		fdf->zoom += 1;
	else if (key == MACOS_MINUS || key == MACOS_MIN || key == LINUX_MINUS)
		fdf->zoom -= 1;
	else if (key == MACOS_ARR_UP || key == LINUX_PAGE_UP)
		fdf->height += 0.1;
	else if (key == MACOS_ARR_DOWN || key == LINUX_PAGE_DOWN)
		fdf->height -= 0.1;
	else if (key == MACOS_BACKSPACE || key == LINUX_BACKSPACE)
		reset(fdf);
	else if (key == MACOS_N || key == MACOS_P || key == LINUX_N ||
			key == LINUX_P)
		change_music(fdf, key);
	mlx_clear_window(fdf->mlx, fdf->win);
	ft_bzero((void *)fdf->img.addr, WIDTH * HEIGHT * 4);
	lets_paint(fdf);
	if (key == MACOS_H)
		show_help_info(fdf);
	return (0);
}

int					ft_exit(void)
{
	system("killall afplay");
	exit(0);
}
