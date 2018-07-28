/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 03:01:27 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 20:33:03 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"

# define WIDTH 1366
# define HEIGHT 768
# define ESC_BUTTON 53
# define MACOS_H 4
# define MACOS_W 13
# define MACOS_A 0
# define MACOS_S 1
# define MACOS_D 2
# define MACOS_Z 6
# define MACOS_X 7
# define MACOS_N 45
# define MACOS_P 35
# define MACOS_BACKSPACE 51
# define MACOS_PL 24
# define MACOS_PLUS 69
# define MACOS_MIN 27
# define MACOS_MINUS 78
# define MACOS_ARR_UP 116
# define MACOS_ARR_DOWN 121
# define MACOS_UP 126
# define MACOS_DOWN 125
# define MACOS_LEFT 123
# define MACOS_RIGHT 124

# define MAX(x, y) x > y ? x : y

typedef struct		s_bresenham
{
	int				x;
	int				y;
	int				color;
	int				dx;
	int				dy;
	int				d;
	int				d1;
	int				d2;
}					t_bresenham;

typedef	struct		s_color
{
	int				z;
	int				color;
}					t_color;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				end;
}					t_img;

typedef struct		s_rot
{
	float			x_degree;
	float			y_degree;
	float			z_degree;
}					t_rot;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_color			**arr;
	t_coord			**coord;
	float			currx;
	float			curry;
	int				x;
	int				y;
	struct s_rot	rot;
	float			zoom;
	float			height;
	int				info;
	int				music;
}					t_fdf;

t_fdf				*new_fdf(t_color **arr, int x, int y);
void				change_coord(t_fdf *fdf);
t_color				**make_arr(char *str, int x, int y, char *line);
int					ft_exit(void);
int					key_mapping(int key, t_fdf *fdf);
void				lets_paint(t_fdf *fdf);
void				ft_create_image(void *mlx, t_img *image);
void				ft_draw_info_table(t_fdf *fdf);
void				ft_show_intro(t_fdf *fdf);
void				ft_draw_line(t_fdf *fdf, t_bresenham br1, t_bresenham br2);
void				draw_a_circle(t_img img, int r);
float				ft_percent(int i, int i1, int i2);
float				ft_grad(int color1, int color2, float percent);
void				change_music(t_fdf *fdf, int key);

#endif
