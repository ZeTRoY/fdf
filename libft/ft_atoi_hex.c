/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:42:59 by aroi              #+#    #+#             */
/*   Updated: 2018/07/23 16:55:31 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\f' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi_hex(const char *str)
{
	size_t		i;
	long int	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	while (ft_ishex((int)str[i]))
	{
		if (ft_isdigit(str[i]))
			n = n * 16 + (int)str[i++] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = n * 16 + (int)str[i++] - 'A' + 10;
		else
			n = n * 16 + (int)str[i++] - 'a' + 10;
	}
	return (sign * (int)n);
}