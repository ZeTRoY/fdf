/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:37:07 by aroi              #+#    #+#             */
/*   Updated: 2018/07/26 10:17:00 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_ishexnumber(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < '0' || (*str > '9' && *str < 'A') ||
			(*str > 'F' && *str < 'a') || *str > 'f')
			return (0);
		str++;
	}
	return (1);
}
