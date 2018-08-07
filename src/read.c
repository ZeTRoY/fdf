/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:45:14 by aroi              #+#    #+#             */
/*   Updated: 2018/07/29 13:13:37 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void		ft_add_color(char *string, int *color)
{
	int k;

	k = 0;
	while (ft_issign(string[k]) || ft_isdigit(string[k]))
		k++;
	if (string[k++] != ' ')
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

static t_color	**ft_givearr(char ***string, int x, int y, t_color **arr)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		arr[j] = (t_color *)malloc(sizeof(t_color) * x);
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

t_color			**make_arr(char *str, int x, int y, char *line)
{
	int				i;
	int				fd;
	t_color			**arr;
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
	if (!(arr = (t_color **)malloc(sizeof(t_color *) * y)))
		return (0);
	ft_givearr(string, x, y, arr);
	ft_delsplitted(string);
	return (arr);
}
