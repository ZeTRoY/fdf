/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:43:31 by aroi              #+#    #+#             */
/*   Updated: 2018/07/29 12:41:13 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_by_x(t_fdf *fdf, t_bresenham br1, t_bresenham br2,
					t_color coord)
{
	int i;

	i = 0;
	while (i++ <= br1.dx)
	{
		if (coord.z >= 0 && coord.color >= 0 &&
			coord.z < WIDTH && coord.color < HEIGHT)
			*(int *)(fdf->img.addr + coord.color * fdf->img.size + coord.z
	* fdf->img.bpp) = ft_grad(br1.color, br2.color,
	ft_percent(coord.z, br1.x, br2.x));
		coord.z += br2.x >= br1.x ? 1 : -1;
		if (br1.d > 0)
		{
			br1.d += br1.d2;
			coord.color += br2.y >= br1.y ? 1 : -1;
		}
		else
			br1.d += br1.d1;
	}
}

void			ft_draw_by_y(t_fdf *fdf, t_bresenham br1, t_bresenham br2,
					t_color coord)
{
	int i;

	i = 0;
	while (i++ <= br1.dy)
	{
		if (coord.z >= 0 && coord.color >= 0
			&& coord.z < WIDTH && coord.color < HEIGHT)
			*(int *)(fdf->img.addr + coord.color * fdf->img.size + coord.z *
				fdf->img.bpp) = ft_grad(br1.color, br2.color,
					ft_percent(coord.color, br1.y, br2.y));
		coord.color += br2.y >= br1.y ? 1 : -1;
		if (br1.d > 0)
		{
			br1.d += br1.d2;
			coord.z += br2.x >= br1.x ? 1 : -1;
		}
		else
			br1.d += br1.d1;
		if (coord.z >= 0 && coord.color >= 0 &&
				coord.z < WIDTH && coord.color < HEIGHT)
			*(int *)(fdf->img.addr + coord.color * fdf->img.size + coord.z *
				fdf->img.bpp) = ft_grad(br1.color, br2.color,
					ft_percent(coord.color, br1.y, br2.y));
	}
}

void			ft_draw_line(t_fdf *fdf, t_bresenham br1, t_bresenham br2)
{
	t_color		coord;

	br1.dx = abs(br2.x - br1.x);
	br1.dy = abs(br2.y - br1.y);
	coord.z = br1.x + (br2.x >= br1.x ? 1 : -1);
	coord.color = br1.y;
	if (br1.dy <= br1.dx)
	{
		br1.d = 2 * br1.dy - br1.dx;
		br1.d1 = 2 * br1.dy;
		br1.d2 = 2 * (br1.dy - br1.dx);
		ft_draw_by_x(fdf, br1, br2, coord);
	}
	else
	{
		br1.d = 2 * br1.dx - br1.dy;
		br1.d1 = 2 * br1.dx;
		br1.d2 = 2 * (br1.dx - br1.dy);
		ft_draw_by_y(fdf, br1, br2, coord);
	}
}

void			draw_a_circle(t_img img, int r)
{
	int		x;
	int		y;
	int		delta;

	x = 0;
	y = r;
	delta = 1 - 2 * y;
	while (y >= 0)
	{
		*(int *)(img.addr + (WIDTH / 2 + x) * img.bpp\
			+ img.size * (HEIGHT / 2 + y)) = 0x700000;
		*(int *)(img.addr + (WIDTH / 2 + x) * img.bpp\
			+ img.size * (HEIGHT / 2 - y)) = 0x700000;
		*(int *)(img.addr + (WIDTH / 2 - x) * img.bpp\
			+ img.size * (HEIGHT / 2 + y)) = 0x700000;
		*(int *)(img.addr + (WIDTH / 2 - x) * img.bpp\
			+ img.size * (HEIGHT / 2 - y)) = 0x700000;
		if (delta < 0 && 2 * (delta + y) - 1 <= 0)
			delta += 2 * ++x + 1;
		else if (delta > 0 && 2 * (delta + y) - 1 > 0)
			delta -= 2 * --y + 1;
		else
			delta += 2 * (++x - y--);
	}
}
