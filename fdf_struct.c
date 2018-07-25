/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 06:00:11 by aroi              #+#    #+#             */
/*   Updated: 2018/07/24 16:26:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*new_fdf(int **arr, int x, int y)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->arr = arr;
	fdf->x = x;
	fdf->y = y;
	fdf->currx = 0.0;
	fdf->curry = 0.0;
	fdf->zoom = 42;
	if (!(fdf->rot = (t_rot *)malloc(sizeof(t_rot))))
	{
		free (fdf);
		return (0);
	}
	fdf->rot->x_degree = 0.0;
	fdf->rot->y_degree = 0.0;
	fdf->rot->z_degree = 0.0;
	return (fdf);
}

void		del_fdf(t_fdf **fdf)
{
	if (!fdf || !*fdf || !(*fdf)->rot)
		return ;
	free((*fdf)->rot);
	free(*fdf);
}
