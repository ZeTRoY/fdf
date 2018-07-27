/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 01:14:30 by aroi              #+#    #+#             */
/*   Updated: 2018/07/27 10:53:08 by aroi             ###   ########.fr       */
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

t_coord			ft_rotate(t_fdf *fdf, float x, float y, float z, int color)
{
	t_coord	coord;

	coord.x = x * (cos(fdf->rot.y_degree) * cos(fdf->rot.z_degree))
			- y * (sin(fdf->rot.z_degree) * cos(fdf->rot.y_degree))
			+ z * (sin(fdf->rot.y_degree));
	coord.y = x * (sin(fdf->rot.x_degree) * sin(fdf->rot.y_degree) * cos(fdf->rot.z_degree) + cos(fdf->rot.x_degree) * sin(fdf->rot.z_degree))
			+ y * (-sin(fdf->rot.x_degree) * sin(fdf->rot.y_degree) * sin(fdf->rot.z_degree) + cos(fdf->rot.x_degree) * cos(fdf->rot.z_degree))
			- z * (sin(fdf->rot.x_degree) * cos(fdf->rot.y_degree));
	coord.z = x * (-cos(fdf->rot.x_degree) * sin(fdf->rot.y_degree) * cos(fdf->rot.z_degree) - sin(fdf->rot.x_degree) * sin(fdf->rot.z_degree))
			+ y * (cos(fdf->rot.x_degree) * sin(fdf->rot.y_degree) * sin(fdf->rot.z_degree) + sin(fdf->rot.x_degree) * cos(fdf->rot.z_degree))
			+ z * cos(fdf->rot.x_degree) * cos(fdf->rot.y_degree);
	if (color)
		coord.color = color;
	else if (z != 0.0)
		coord.color = 0xFF0000;
	else
		coord.color = 0xFF00;
	return (coord);
}





// float				ft_grad(int color1, int color2, float percent)
// {
// 	int red;
// 	int green;
// 	int blue;

// 	if (color1 - color2 == 0)
// 		return (color1);
// 	red = (color1 >> 16) + ((color2 >> 16) - (color1 >> 16)) * percent;
// 	green = (color1 >> 8 & 0xFF) + ((color2 >> 8 & 0xFF) - (color1 >> 8 & 0xFF)) * percent;
// 	blue = (color1 & 0xFF) + ((color2 & 0xFF) - (color1 & 0xFF)) * percent;
// 	return (red << 16 | green << 8 | blue);
// }

// float			ft_percent(int x, int y, int x2, int y2)
// {
// 	int length1;
// 	int length2;

// 	length1 = sqrt((x2 - x) * (x2 - x) + ((y2 - y) * (y2 - y)));
// 	length2 = sqrt(x2 * x2 + y2 * y2);
// 	return ((length2 - length1) / (float)length2);
// }

// void ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color1, int color2)
void ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x2 >= x1 ? 1 : -1;
  int sy = y2 >= y1 ? 1 : -1;
  int x = x1 + sx;
  int y = y1;
  int i = 0;
  float percent;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    while(i++ <= dx)
    {
		// printf("per0: %f\n", percent);
    // mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		// *(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(color1, color2, ft_percent(x, y, x2, y2));
		*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = color;
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
    // mlx_pixel_put(fdf->mlx, fdf->win, x1, y1, color);
	// percent = ft_percent(x, y, x2, y2);
		// printf("per1: %f\n", percent);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		// *(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(color1, color2, ft_percent(x, y, x2, y2));
		*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = color;
    while(i++ <= dy)
    {
		// mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
	// percent = ft_percent(x, y, x2, y2);
		// printf("per2: %f\n", percent);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		// *(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(color1, color2, ft_percent(x, y, x2, y2));
		*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = color;
		y += sy;
      if (d >0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
    // mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
	// percent = ft_percent(x, y, x2, y2);
		// printf("per3: %f\n", percent);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		// *(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = ft_grad(color1, color2, ft_percent(x, y, x2, y2));
		*(int *)(fdf->img.addr + y * fdf->img.size + x * fdf->img.bpp) = color;
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

void			ft_freecoord(t_coord **coord, int y)
{
	int j;

	j = 0;
	if (!coord)
		return ;
	while (j < y)
		if (coord[j++])
			free(coord[j - 1]);
	free(coord);
}

/*
**._______________________________________________________________.
**|	A function for putpixel into a window directly or onto image. |
**|								||								  |
**|								\/								  |
**|_______________________________________________________________|
*/

void			lets_paint(t_fdf *fdf)
{
	int			i;
	int			j;
	t_coord		**coord;

	j = 0;
	if (fdf->zoom < 0)
		fdf->zoom = 0;
	coord = (t_coord **)malloc(sizeof(t_coord *) * fdf->y);
	while (j < fdf->y)
	{
		coord[j] = (t_coord *)malloc(sizeof(t_coord) * fdf->x);
		i = 0;
		while (i < fdf->x)
		{
			coord[j][i] = ft_rotate(fdf, fdf->zoom * (i - fdf->x / 2), fdf->zoom * (j - fdf->y / 2), fdf->zoom * fdf->height * fdf->arr[j][i].z, fdf->arr[j][i].color);
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
			// ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, coord[j][i].color, coord[j][i + 1].color);
			ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, MAX(coord[j][i].color, coord[j][i + 1].color));
			// ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, coord[j][i].color, coord[j + 1][i].color);
			ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, MAX(coord[j][i].color, coord[j + 1][i].color));
			i++;
		}
		// ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, coord[j][i].color, coord[j + 1][i].color);
		ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j + 1][i].x, fdf->curry + coord[j + 1][i].y, MAX(coord[j][i].color, coord[j + 1][i].color));
		j++;
	}
	i = -1;
	while (++i + 1 < fdf->x)
		// ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, coord[j][i].color, coord[j][i + 1].color);
		ft_draw_line(fdf, fdf->currx + coord[j][i].x, fdf->curry + coord[j][i].y, fdf->currx + coord[j][i + 1].x, fdf->curry + coord[j][i + 1].y, MAX(coord[j][i].color, coord[j][i + 1].color));
	ft_freecoord(coord, fdf->y);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

static void		ft_delsplitted(char ***string)
{
	int i;
	int j;

	j = 0;
	while (string[j])
	{
		i = 0;
		while (string[j][i])
			if (string[j][i++])
				free(string[j][i - 1]);
		if (string[j++])
			free(string[j - 1]);
	}
	if (string)
		free(string);
}

static t_color	**ft_givearr(char ***string, int x, int y, t_color **arr)
{
	int i;
	int j;
	int k;

	j = -1;
	while (++j < y)
	{
		arr[j] = (t_color *)malloc(sizeof(t_color) * x);
		i = -1;
		while (++i < x)
		{
			k = 0;
			arr[j][i].z = ft_atoi(string[j][i]);
			while (ft_isdigit(string[j][i][k]))
				k++;
			if (string[j][i][k++])
			{
				if (string[j][i][k] == '0' && string[j][i][k + 1] == 'x')
				{
					arr[j][i].color = ft_atoi_base(string[j][i] + k + 2, 16);
					k += 2;
				}
				else
					arr[j][i].color = ft_atoi(string[j][i] + k);
			}
		}
	}
	return (arr);
}

static t_color	**make_arr(char *str, int x, int y, char *line)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	t_color	**arr;
	char	***string;

	i = 0;
	if (!(string = (char ***)malloc(sizeof(char **) * (y + 1))))
		return (0);
	string[y] = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		string[i++] = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	close(fd);
	j = 0;
	if (!(arr = (t_color **)malloc(sizeof(t_color *) * y)))
		return (0);
	ft_givearr(string, x, y, arr);
	ft_delsplitted(string);
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

int				main(int argc, char **argv)
{
	int		x;
	int		y;
	t_fdf	*fdf;
	char	*line;

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
	fdf = new_fdf(make_arr(argv[1], x, y, line), x, y);
	lets_paint(fdf);
	mlx_hook(fdf->win, 2, 0, key_mapping, fdf);
	mlx_hook(fdf->win, 17, 0, ft_exit, (void *)0); //exit by presiing "x" button
	mlx_loop(fdf->mlx);
	return (0);
}
	// // checking the matrix int **arr
	
	// int i = 0;
	// int j = 0;
	// while (j < y)
	// {
	// 	i = 0;
	// 	while (i < x)
	// 	{
	// 		// if (arr[j][i].z == 0)
	// 		// 	ft_printf("00 ");
	// 		// else
	// 			ft_printf("%d ", arr[j][i].color);
	// 		i++;
	// 	}
	// 	ft_printf("\n");
	// 	j++;
	// }
