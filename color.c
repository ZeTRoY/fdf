/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:56:24 by aroi              #+#    #+#             */
/*   Updated: 2018/07/27 21:40:34 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float			ft_grad(int color1, int color2, float percent)
{
	int red;
	int green;
	int blue;

	if (color1 - color2 == 0)
		return (color1);
	red = (color1 >> 16) + ((color2 >> 16) - (color1 >> 16)) * percent;
	green = ((color1 >> 8) & 0xFF) +
		((color2 >> 8 & 0xFF) - (color1 >> 8 & 0xFF)) * percent;
	blue = (color1 & 0xFF) + ((color2 & 0xFF) - (color1 & 0xFF)) * percent;
	return (red << 16 | green << 8 | blue);
}

float			ft_percent(int i, int i1, int i2)
{
	if (i == i1)
		return (0.0);
	else if (i == i2)
		return (1.0);
	return ((float)(i - i1) / (i2 - i1));
}
