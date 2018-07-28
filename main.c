/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 01:14:30 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 21:32:19 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	error(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

static int			get_y(char *str)
{
	int		y;
	int		res;
	int		fd;
	char	*line;

	y = 0;
	fd = open(str, O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		y++;
		ft_strdel(&line);
	}
	if (res < 0)
		return (-1);
	close(fd);
	return (y);
}

static int			get_x(char *str)
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

static int			read_file(t_fdf **fdf, char *str)
{
	int		x;
	int		y;
	char	*line;

	if ((y = get_y(str)) < 0)
		return (error("Error: Invalid name of file."));
	if ((x = get_x(str)) < 0)
		return (error("Error: Invalid map."));
	line = NULL;
	*fdf = new_fdf(make_arr(str, x, y, line), x, y);
	return (0);
}

int					main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (error("Usage: ./fdf <filename>"));
	if (read_file(&fdf, argv[1]))
		return (1);
	system("afplay -v 0.8 ./music/Ludovico_Einaudi_-_Indaco.mp3 &");
	ft_show_intro(fdf);
	mlx_hook(fdf->win, 2, 0, key_mapping, fdf);
	mlx_hook(fdf->win, 17, 0, ft_exit, (void *)0);
	mlx_loop(fdf->mlx);
	return (0);
}
