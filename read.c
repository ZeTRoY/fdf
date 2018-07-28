/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:45:14 by aroi              #+#    #+#             */
/*   Updated: 2018/07/28 17:05:48 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				ft_delsplitted(char ***string)
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

static void				ft_add_color(char *string, int *color)
{
	int k;

	k = 0;
	while (ft_isdigit(string[k]))
		k++;
	if (string[k++])
	{
		if (string[k] == '0' && string[k + 1] == 'x')
		{
			*color = ft_atoi_base(string + k + 2, 16);
			k += 2;
		}
		else
			*color = ft_atoi(string + k);
	}
}

static t_twovariables	**ft_givearr(char ***string, int x, int y,
							t_twovariables **arr)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		arr[j] = (t_twovariables *)malloc(sizeof(t_twovariables) * x);
		i = 0;
		while (i < x)
		{
			arr[j][i].z = ft_atoi(string[j][i]);
			ft_add_color(string[j][i], &arr[j][i].color);
			i++;
		}
		j++;
	}
	return (arr);
}

t_twovariables			**make_arr(char *str, int x, int y, char *line)
{
	int				i;
	int				fd;
	t_twovariables	**arr;
	char			***string;

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
	if (!(arr = (t_twovariables **)malloc(sizeof(t_twovariables *) * y)))
		return (0);
	ft_givearr(string, x, y, arr);
	ft_delsplitted(string);
	return (arr);
}

int						get_y(char *str)
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

int						get_x(char *str)
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
