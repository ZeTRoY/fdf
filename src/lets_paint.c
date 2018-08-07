/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 21:28:34 by aroi              #+#    #+#             */
/*   Updated: 2018/07/29 11:28:03 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline t_bresenham	create_bresenham(int x, int y, int color)
{
	t_bresenham	br;

	br.x = x;
	br.y = y;
	br.color = color;
	return (br);
}

static void					lets_paint_part_two(t_fdf *fdf, t_coord **coord)
{
	int			i;
	int			j;
	t_bresenham	br1;

	j = -1;
	while ((i = -1) && ++j + 1 < fdf->y)
	{
		while (++i + 1 < fdf->x)
		{
			br1 = create_bresenham(fdf->currx + coord[j][i].x, fdf->curry +
	coord[j][i].y, coord[j][i].color);
			ft_draw_line(fdf, br1, create_bresenham(fdf->currx +
	coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, coord[j][i + 1].color));
			ft_draw_line(fdf, br1, create_bresenham(fdf->currx +
	coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, coord[j + 1][i].color));
		}
		ft_draw_line(fdf, create_bresenham(fdf->currx + coord[j][i].x,
fdf->curry + coord[j][i].y, coord[j][i].color), create_bresenham(fdf->currx +
coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, coord[j + 1][i].color));
	}
	while (++i + 1 < fdf->x)
		ft_draw_line(fdf, create_bresenham(fdf->currx + coord[j][i].x,
fdf->curry + coord[j][i].y, coord[j][i].color), create_bresenham(fdf->currx +
coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, coord[j][i + 1].color));
}

void						lets_paint(t_fdf *fdf)
{
	if (fdf->zoom < 0)
		fdf->zoom = 0;
	change_coord(fdf);
	lets_paint_part_two(fdf, fdf->coord);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	if (fdf->info)
		ft_draw_info_table(fdf);
}
