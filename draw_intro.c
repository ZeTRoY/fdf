/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:41:31 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 21:40:32 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_draw_upper_part(t_img img)
{
	int i;
	int j;

	j = 0;
	while (j < 70)
	{
		i = 0;
		while (i < WIDTH)
		{
			*(int *)(img.addr + i * img.bpp + img.size * j) = 0x700000;
			i++;
		}
		j++;
	}
	i = 0;
	while (i < WIDTH)
	{
		*(int *)(img.addr + i * img.bpp + img.size * j) = 0xDC143C;
		i++;
	}
}

static void			ft_draw_lower_part(t_img img)
{
	int i;
	int j;

	i = 0;
	j = HEIGHT - 71;
	while (i < WIDTH)
	{
		*(int *)(img.addr + i * img.bpp + img.size * j) = 0xDC143C;
		i++;
	}
	while (++j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			*(int *)(img.addr + i * img.bpp + img.size * j) = 0x700000;
			i++;
		}
	}
}

void				change_music(t_fdf *fdf, int key)
{
	system("killall afplay");
	if (key == MACOS_N)
		fdf->music = fdf->music != 2 ? fdf->music + 1 : 0;
	else
		fdf->music = fdf->music ? fdf->music - 1 : 2;
	if (fdf->music)
	{
		if (fdf->music == 1)
			system("afplay -v 0.8 ./music/Неизвестность_-_Бабосик.mp3 &");
		else
			system("afplay -v 0.8 ./music/Eldjey_-_Hey_Guys.mp3 &");
	}
	else
		system("afplay -v 0.8 ./music/Ludovico_Einaudi_-_Indaco.mp3 &");
	return ;
}

void				ft_show_intro(t_fdf *fdf)
{
	ft_create_image(fdf->mlx, &fdf->img);
	ft_draw_upper_part(fdf->img);
	ft_draw_lower_part(fdf->img);
	draw_a_circle(fdf->img, 130);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, 615, HEIGHT / 2 - 11,
		0xFF7777, "PRESS ANY KEY");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 15, 35 - 11,
		0xFFFFFF, "FdF");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH / 2 - 120, HEIGHT - 35 - 11,
		0xFFFFFF, "Ludovico Einaudi - Indaco");
	ft_draw_info_table(fdf);
}
