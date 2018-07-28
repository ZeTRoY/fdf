/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:43:31 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 16:57:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
void	ft_draw_line(t_fdf *fdf, t_bresenham br1, t_bresenham br2)
{
	int dx = abs(br2.x - br1.x);
	int dy = abs(br2.y - br1.y);
	int sx = br2.x >= br1.x ? 1 : -1;
	int sy = br2.y >= br1.y ? 1 : -1;
	int x = br1.x + sx;
	int y = br1.y;
	int i = 0;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		while(i++ <= dx)
		{
			if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
			// mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
				*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(br1.color, br2.color, ft_percent(x, br1.x, br2.x));
			x += sx;
			if (d >0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		// mlx_pixel_put(fdf->mlx, fdf->win, br1.x, br1.y, color);
			*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(br1.color, br2.color, ft_percent(y, br1.y, br2.y));
		while(i++ <= dy)
		{
			if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
			// mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(br1.color, br2.color, ft_percent(y, br1.y, br2.y));
		y += sy;
		if (d >0)
		{
			d += d2;
			x += sx;
		}
		else
			d += d1;
		if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
			// mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
			*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(br1.color, br2.color, ft_percent(y, br1.y, br2.y));
		}
	}
}

void			draw_a_circle(t_img img, int r)
{
	int x = 0;
	int y = r;
	int delta = 1 - 2 * y;
	int error = 0;
	while (y >= 0)
	{
		*(int *)(img.addr + (WIDTH / 2 + x) * img.bpp 
			+ img.size * (HEIGHT / 2 + y)) = 0x700000;
   		*(int *)(img.addr + (WIDTH / 2 + x) * img.bpp 
			+ img.size * (HEIGHT / 2 - y)) = 0x700000;
   		*(int *)(img.addr + (WIDTH / 2 - x) * img.bpp 
			+ img.size * (HEIGHT / 2 + y)) = 0x700000;
   		*(int *)(img.addr + (WIDTH / 2 - x) * img.bpp 
			+ img.size * (HEIGHT / 2 - y)) = 0x700000;
		error = 2 * (delta + y) - 1;
		if (delta < 0 && error <= 0)
			delta += 2 * ++x + 1;
		else if (delta > 0 && error > 0)
			delta -= 2 * --y + 1;
		else
			delta += 2 * (++x - y--);
	}
}