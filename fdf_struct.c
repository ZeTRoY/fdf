/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 06:00:11 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 20:33:37 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	ft_rotate(t_fdf *fdf, float x, float y, float z)
{
	t_coord	coord;

	coord.x = x * (cos(fdf->rot.y_degree) * cos(fdf->rot.z_degree))
			- y * (sin(fdf->rot.z_degree) * cos(fdf->rot.y_degree))
			+ z * (sin(fdf->rot.y_degree));
	coord.y = x * (sin(fdf->rot.x_degree) * sin(fdf->rot.y_degree) *
	cos(fdf->rot.z_degree) + cos(fdf->rot.x_degree) * sin(fdf->rot.z_degree))
			+ y * (-sin(fdf->rot.x_degree) * sin(fdf->rot.y_degree) *
	sin(fdf->rot.z_degree) + cos(fdf->rot.x_degree) * cos(fdf->rot.z_degree))
			- z * (sin(fdf->rot.x_degree) * cos(fdf->rot.y_degree));
	coord.z = x * (-cos(fdf->rot.x_degree) * sin(fdf->rot.y_degree) *
	cos(fdf->rot.z_degree) - sin(fdf->rot.x_degree) * sin(fdf->rot.z_degree))
			+ y * (cos(fdf->rot.x_degree) * sin(fdf->rot.y_degree) *
	sin(fdf->rot.z_degree) + sin(fdf->rot.x_degree) * cos(fdf->rot.z_degree))
			+ z * cos(fdf->rot.x_degree) * cos(fdf->rot.y_degree);
	return (coord);
}

void			change_coord(t_fdf *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->y)
	{
		i = 0;
		while (i < fdf->x)
		{
			fdf->coord[j][i] = ft_rotate(fdf, fdf->zoom * (i - fdf->x / 2),
				fdf->zoom * (j - fdf->y / 2),
				fdf->zoom * fdf->height * fdf->arr[j][i].z);
			fdf->coord[j][i].x += WIDTH / 2;
			fdf->coord[j][i].y += HEIGHT / 2;
			if (fdf->arr[j][i].color)
				fdf->coord[j][i].color = fdf->arr[j][i].color;
			else if (fdf->arr[j][i].z != 0.0)
				fdf->coord[j][i].color = 0xFF0000;
			else
				fdf->coord[j][i].color = 0xFF00;
			i++;
		}
		j++;
	}
}

static void		create_coord(t_fdf *fdf)
{
	int		i;
	int		j;

	j = -1;
	fdf->coord = (t_coord **)malloc(sizeof(t_coord *) * fdf->y);
	while ((i = -1) && ++j < fdf->y)
	{
		fdf->coord[j] = (t_coord *)malloc(sizeof(t_coord) * fdf->x);
		while (++i < fdf->x)
		{
			fdf->coord[j][i] = ft_rotate(fdf, fdf->zoom * (i - fdf->x / 2),
				fdf->zoom * (j - fdf->y / 2),
				fdf->zoom * fdf->height * fdf->arr[j][i].z);
			fdf->coord[j][i].x += WIDTH / 2;
			fdf->coord[j][i].y += HEIGHT / 2;
			if (fdf->arr[j][i].color)
				fdf->coord[j][i].color = fdf->arr[j][i].color;
			else if (fdf->arr[j][i].z != 0.0)
				fdf->coord[j][i].color = 0xFF0000;
			else
				fdf->coord[j][i].color = 0xFF00;
		}
	}
}

void			ft_create_image(void *mlx, t_img *image)
{
	image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
		&(image->size), &(image->end));
	image->bpp /= 8;
}

t_fdf			*new_fdf(t_color **arr, int x, int y)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	ft_create_image(fdf->mlx, &fdf->img);
	fdf->arr = arr;
	fdf->x = x;
	fdf->y = y;
	fdf->currx = 0.0;
	fdf->curry = 0.0;
	if (HEIGHT > WIDTH)
		fdf->zoom = HEIGHT / fdf->y;
	else
		fdf->zoom = WIDTH / fdf->x;
	fdf->height = 0.1;
	fdf->info = 1;
	fdf->rot.x_degree = 0.0;
	fdf->rot.y_degree = 0.0;
	fdf->rot.z_degree = 0.0;
	fdf->music = 0;
	create_coord(fdf);
	return (fdf);
}
