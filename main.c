/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 01:14:30 by aroi              #+#    #+#             */
/*   Updated: 2018/07/25 19:43:19 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "printf.h"

// void				ft_rotate_x(t_fdf *fdf, float *x, float *y, float *z)
// {
// 	float y1;

// 	y1 = *y;
// 	*x = *x;
// 	*y = *y * cos(fdf->rot->x_degree) - *z * sin(fdf->rot->x_degree);
// 	*z = y1 * sin(fdf->rot->x_degree) + *z * cos(fdf->rot->x_degree);
// }

// void				ft_rotate_y(t_fdf *fdf, float *x, float *y, float *z)
// {
// 	float x1;

// 	x1 = *x;
// 	*x = *x * cos(fdf->rot->y_degree) + *z * sin(fdf->rot->y_degree);;
// 	*y = *y;
// 	*z = - x1 * sin(fdf->rot->y_degree) + *z * cos(fdf->rot->y_degree);
// }

// void				ft_rotate_z(t_fdf *fdf, float *x, float *y, float *z)
// {
// 	float x1;

// 	x1 = *x;
// 	*x = *x * cos(fdf->rot->z_degree) - *z * sin(fdf->rot->z_degree);
// 	*y = *y * cos(fdf->rot->z_degree) + x1 * sin(fdf->rot->z_degree);
// 	*z = *z;
// }








// void			ft_rotate(t_fdf *fdf, float *x, float *y, float *z)
// {
// 	float x1;
// 	float y1;
// 	float z1;

// 	// printf("degrees: x: %f, y: %f, z: %f\n", fdf->rot->x_degree, fdf->rot->y_degree, fdf->rot->z_degree);
// 	x1 = *x;
// 	y1 = *y;
// 	z1 = *z;
// 	*x = x1 * cos(fdf->rot->x_degree) * cos(fdf->rot->z_degree) + y1 *
// 		(sin(fdf->rot->x_degree) * sin(fdf->rot->x_degree) *
// 		cos(fdf->rot->z_degree) - cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->z_degree)) + z1 * (cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) +
// 		sin(fdf->rot->x_degree) * sin(fdf->rot->z_degree));
// 	// printf("x: %f\n", coord.x);
// 	*y = x1 * cos(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + y1 *
// 		(sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) *
// 		sin(fdf->rot->z_degree) + cos(fdf->rot->x_degree) *
// 		cos(fdf->rot->z_degree)) + z1 * (cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) -
// 		sin(fdf->rot->x_degree) * cos(fdf->rot->z_degree));
// 	// printf("y: %f\n", coord.y);
// 	*z = - x1 * sin(fdf->rot->y_degree) + y1 * sin(fdf->rot->x_degree) *
// 		cos(fdf->rot->y_degree) + z1 * cos(fdf->rot->x_degree) *
// 		cos(fdf->rot->y_degree);
// 	// printf("z: %f\n", coord.y);
// }









//ox, oy, oz

// t_coord			ft_rotate(t_fdf *fdf, float x, float y, float z)
// {
// 	t_coord	coord;

// 	printf("degrees: x: %f, y: %f, z: %f\n", fdf->rot->x_degree, fdf->rot->y_degree, fdf->rot->z_degree);
// 	coord.x = 600 + x * (cos(fdf->rot->y_degree) * cos(fdf->rot->z_degree))
// 			- y * (sin(fdf->rot->z_degree) * cos(fdf->rot->y_degree))
// 			+ z * (sin(fdf->rot->y_degree));
// 	printf("x: %f\n", coord.x);
// 	coord.y = 400 + x * (- sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) + cos(fdf->rot->x_degree) * sin(fdf->rot->z_degree))
// 			+ y * (sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + cos(fdf->rot->x_degree) * cos(fdf->rot->z_degree))
// 			- z * (sin(fdf->rot->x_degree) * cos(fdf->rot->y_degree));
// 	printf("y: %f\n", coord.y);
// 	coord.z = x * ( cos(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) - sin(fdf->rot->x_degree) * sin(fdf->rot->z_degree))
// 			+ y * (- cos(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + sin(fdf->rot->x_degree) * cos(fdf->rot->z_degree))
// 			+ z * cos(fdf->rot->x_degree) * cos(fdf->rot->y_degree);
// 	printf("z: %f\n", coord.z);
// 	return (coord);
// }









//oz, oy, ox

// t_coord			ft_rotate(t_fdf *fdf, float x, float y, float z)
// {
// 	t_coord	coord;

// 	printf("degrees: x: %f, y: %f, z: %f\n", fdf->rot->x_degree, fdf->rot->y_degree, fdf->rot->z_degree);
// 	coord.x = x * cos(fdf->rot->y_degree) * cos(fdf->rot->z_degree) + y *
// 		(sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) *
// 		cos(fdf->rot->z_degree) - cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->z_degree)) + z * (cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) +
// 		sin(fdf->rot->x_degree) * sin(fdf->rot->z_degree));
// 	printf("x: %f\n", coord.x);
// 	coord.y = x * cos(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + y *
// 		(sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) *
// 		sin(fdf->rot->z_degree) + cos(fdf->rot->x_degree) *
// 		cos(fdf->rot->z_degree)) + z * (cos(fdf->rot->x_degree) *
// 		sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) -
// 		sin(fdf->rot->x_degree) * cos(fdf->rot->z_degree));
// 	printf("y: %f\n", coord.y);
// 	coord.z = - x * sin(fdf->rot->y_degree) + y * sin(fdf->rot->x_degree) *
// 		cos(fdf->rot->y_degree) + z * cos(fdf->rot->x_degree) *
// 		cos(fdf->rot->y_degree);
// 	printf("z: %f\n", coord.z);
// 	return (coord);
// }


//Max's ox, oy, oz

t_coord			ft_rotate(t_fdf *fdf, float x, float y, float z)
{
	t_coord	coord;

	printf("degrees: x: %f, y: %f, z: %f\n", fdf->rot->x_degree, fdf->rot->y_degree, fdf->rot->z_degree);
	coord.x = x * (cos(fdf->rot->y_degree) * cos(fdf->rot->z_degree))
			- y * (sin(fdf->rot->z_degree) * cos(fdf->rot->y_degree))
			+ z * (sin(fdf->rot->y_degree));
	printf("x: %f\n", coord.x);
	coord.y = x * (sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) + cos(fdf->rot->x_degree) * sin(fdf->rot->z_degree))
			+ y * (-sin(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + cos(fdf->rot->x_degree) * cos(fdf->rot->z_degree))
			- z * (sin(fdf->rot->x_degree) * cos(fdf->rot->y_degree));
	printf("y: %f\n", coord.y);
	coord.z = x * (-cos(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * cos(fdf->rot->z_degree) - sin(fdf->rot->x_degree) * sin(fdf->rot->z_degree))
			+ y * (cos(fdf->rot->x_degree) * sin(fdf->rot->y_degree) * sin(fdf->rot->z_degree) + sin(fdf->rot->x_degree) * cos(fdf->rot->z_degree))
			+ z * cos(fdf->rot->x_degree) * cos(fdf->rot->y_degree);
	printf("z: %f\n", coord.z);
	return (coord);
}










void ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x2 >= x1 ? 1 : -1;
  int sy = y2 >= y1 ? 1 : -1;
  int x = x1 + sx;
  int y = y1;
  int i = 0;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    while(i++ <= dx)
    {
    mlx_pixel_put(fdf->mlx, fdf->win, x, y, color == 0 ? 0xFF00 : 0xFF0000);
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
    mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, color == 0 ? 0xFF00 : 0xFF0000);
    while(i++ <= dy)
    {mlx_pixel_put(fdf->mlx, fdf->win, x, y, color == 0 ? 0xFF00 : 0xFF0000);
		y += sy;
      if (d >0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
    mlx_pixel_put(fdf->mlx, fdf->win, x, y, color == 0 ? 0xFF00 : 0xFF0000);
    }
  }
}

// omiroshn's Bresenham

// void		ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int z)
// {
// 	int dx;
// 	int dy;
// 	int x;
// 	int y;
// 	int err;
// 	int err2;

// 	dx = abs(x2 - x1);
// 	dy = abs(y2 - y1);
// 	x = x2 - x1 > 0 ? x1 : x2;
// 	y = y2 - y1 > 0 ? y1 : y2;
// 	err = dx + dy;
// 	ft_printf("%d|%d|%d\n", dx, dy, err);
// 	while ((dx && x != x2) || (dy && y != y2))
// 	{
// 		mlx_pixel_put(fdf->mlx, fdf->win, WIDTH / 2 + x, HEIGHT / 2 + y, z == 0 ? 0xFFFFFF : 0xFF0000);
// 		err2 = 2 * err;
// 		if (err2 >= dy)
// 		{
// 			err += dy;
// 			x += dx >= 0 ? 1 : -1;
// 		}
// 		else if (err2 <= dx)
// 		{
// 			err += dx;
// 			y += dy >= 0 ? 1 : -1;
// 		}
// 		else
// 			break ;
// 	}
// }



// void			ft_draw_line(t_fdf *fdf, float x1, float y1, float x2, float y2, float z)
// {
// 	float	x;
// 	float	y;
// 	float	dx;
// 	float	dy;
// 	float	error;

// 	dx = x2 - x1 > 0 ? x2 - x1 : x1 - x2;
// 	dy = y2 - y1 > 0 ? y2 - y1 : y1 - y2;
// 	x = x2 - x1 > 0 ? x1 : x2;
// 	y = y2 - y1 > 0 ? y1 : y2;
// 	error = 2 * dy - dx;
// 	while ((dx && x < x2 ) || (dy && y < y2))
// 	{
// 		mlx_pixel_put(fdf->mlx, fdf->win, x, y, z == 0 ? 0xFFFFFF : 0xFF0000);
// 		if (dx != 0)
// 		{
// 			error += dy / dx;
// 			if (error >= 0.5)
// 			{
// 				y += y2 - y1 < 0 ? -1 : 1;
// 				error += 2 * dy - dx;
// 			}
// 			else
// 				error += 2 * dy;
// 			x += 1.0;
// 		}
// 		else
// 			y += 1.0;
// 	}
// 	// 0xFFFFFF - mlx_get_color_value(fdf->mlx, (int)z)
// }


void			lets_paint(t_fdf *fdf)
{
	int			i;
	int			j;
	t_coord		**coord;

	j = 0;
	coord = (t_coord **)malloc(sizeof(t_coord *) * fdf->y);
	while (j < fdf->y)
	{
		coord[j] = (t_coord *)malloc(sizeof(t_coord) * fdf->x);
		i = 0;
		while (i < fdf->x)
		{
			coord[j][i] = ft_rotate(fdf, fdf->zoom * (i - fdf->x / 2), fdf->zoom * (j - fdf->y / 2), (float)fdf->arr[j][i] * 10);
			coord[j][i].x += WIDTH / 2;
			coord[j][i].y += HEIGHT / 2;
			i++;
		}
		j++;
	}
	j = 0;
	while (j + 1 < fdf->y)
	{
		i = 0;
		while (i + 1 < fdf->x)
		{
			ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, fdf->arr[j][i + 1] - fdf->arr[j][i] > 0 ? fdf->arr[j][i + 1] : fdf->arr[j][i]);
			ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, fdf->arr[j + 1][i] - fdf->arr[j][i] > 0 ? fdf->arr[j + 1][i] : fdf->arr[j][i]);
			i++;
		}
		ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, fdf->arr[j + 1][i] - fdf->arr[j][i] > 0 ? fdf->arr[j + 1][i] : fdf->arr[j][i]);
		j++;
	}
	i = -1;
	while (++i + 1 < fdf->x)
		ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, fdf->arr[j][i + 1] - fdf->arr[j][i] > 0 ? fdf->arr[j][i + 1] : fdf->arr[j][i]);
}

static int		key_mapping(int key, t_fdf **fdf)
{
	if (key == ESC)
		exit(0);
	else if (key == MACOS_W)
		(*fdf)->curry -= 20;
	else if (key == MACOS_A)
		(*fdf)->currx -= 20;
	else if (key == MACOS_D)
		(*fdf)->currx += 20;
	else if (key == MACOS_S)
		(*fdf)->curry += 20;
	else if (key == MACOS_UP)
		(*fdf)->rot->x_degree += 0.05 * M_PI;
	else if (key == MACOS_DOWN)
		(*fdf)->rot->x_degree -= 0.05 * M_PI;
	else if (key == MACOS_LEFT)
		(*fdf)->rot->y_degree -= 0.05 * M_PI;
	else if (key == MACOS_RIGHT)
		(*fdf)->rot->y_degree += 0.05 * M_PI;
	else if (key == 6)
		(*fdf)->rot->z_degree -= 0.05 * M_PI;
	else if (key == 7)
		(*fdf)->rot->z_degree += 0.05 * M_PI;
	else if (key == MACOS_PLUS || key == MACOS_PL)
		(*fdf)->zoom += 10;
	else if (key == MACOS_MINUS || key == MACOS_MIN)
		(*fdf)->zoom -= 10;
	mlx_clear_window((*fdf)->mlx, (*fdf)->win);
	lets_paint(*fdf);

	return (0);
}

static int		**make_arr(char *str, int x, int y, char *line)
{
	int		fd;
	int		i;
	int		j;
	int		**arr;
	char	***string;

	i = 0;
	string = (char ***)malloc(sizeof(char **) * y);
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
		string[i++] = ft_strsplit(line, ' ');
	close(fd);
	j = 0;
	arr = (int **)malloc(sizeof(int *) * y);
	while (j < y)
	{
		arr[j] = (int *)malloc(sizeof(int) * x);
		i = 0;
		while (i < x)
		{
		// 	if (string[j][i][0] == '0' && string[j][i][1] == 'x')
				arr[j][i] = ft_atoi_hex(string[j][i]);
		// 	else
				arr[j][i] = ft_atoi(string[j][i]);
			i++;
		}
		j++;
	}
	return (arr);
}

static int		get_y(char *str)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		y++;
		ft_strdel(&line);
	}
	close(fd);
	return (y);
}

static int		get_x(char *str)
{
	int		x;
	int		tmp;
	int		i;
	int		fd;
	char	*line;

	x = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tmp = 0;
		i = -1;
		while (line[++i])
			if (line[i] != ' ' && (line[i + 1] == ' ' || !line[i + 1]))
				tmp++;
		ft_strdel(&line);
		if (!x && x != tmp)
			x = tmp;
		else if (x != tmp || !x)
			return (-1);
	}
	close(fd);
	return (x);
}

static int		ft_exit(void *param)
{
	exit (0);
}

int				main(int argc, char **argv)
{
	int		x;
	int		y;
	t_fdf	*fdf;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*line;
	int		**arr;
	char	***string;

	if (argc != 2)
	{
		ft_printf("Usage : %s <filename> [ case_size z_size ]\n", argv[0]);
		return (0);
	}
	y = get_y(argv[1]);
	if ((x = get_x(argv[1])) < 0)
	{
		ft_printf("Invalid map.\n");
		return (-1);
	}
	// int fd = open(argv[1], O_RDONLY);
	// while (get_next_line(fd, &line))
	// {
	// 	ft_printf("%s\n", line);
	// 	ft_strdel(&line);
	// }
	// get_next_line(fd, &line);
	// ft_printf("%s", line);
	// arr = make_arr(argv[1], x, y, line);
	// fdf = new_fdf(arr, x, y);

	// // checking the matrix int **arr
	
	// int i = 0;
	// int j = 0;
	// while (j < y)
	// {
	// 	i = 0;
	// 	while (i < x)
	// 	{
	// 		if (arr[j][i] == 0)
	// 			ft_printf("00 ");
	// 		else
	// 			ft_printf("%d ", arr[j][i]);
	// 		i++;
	// 	}
	// 	ft_printf("\n");
	// 	j++;
	// }
	
	// lets_paint(fdf);
	// mlx_hook(fdf->win, 2, 0, key_mapping, &fdf);
	// mlx_hook(fdf->win, 17, 0, ft_exit, (void *)0); //exit by presiing "x" button
	// mlx_loop(fdf->mlx);
	system("leaks fdf > leaks");
	return (0);
}