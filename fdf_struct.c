/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 06:00:11 by aroi              #+#    #+#             */
/*   Updated: 2018/07/27 15:51:45 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_create_image(void *mlx, t_img *image)
{
	image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp), &(image->size), &(image->end));
	image->bpp /= 8;
}

t_fdf		*new_fdf(t_color **arr, int x, int y)
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
	fdf->zoom = 5.0;
	fdf->height = 1.0;
	fdf->rot.x_degree = 0.0;
	fdf->rot.y_degree = 0.0;
	fdf->rot.z_degree = 0.0;
	return (fdf);
}
