/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 08:24:30 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/19 08:24:30 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "gui/letters.h"
#include "draw.h"

void	draw_char(t_image *img, const char *bits, t_point pt, int32_t size)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < CHAR_HEIGHT)
	{
		x = 0;
		while (x < CHAR_WIDTH)
		{
			if (bits[y] >> x & 0x1)
				draw_rectangle(img, point_s(pt.x + x * size,
						pt.y + y * size, pt.color), size, size);
			x++;
		}
		y++;
	}
}

void	draw_nstr(t_image *img, const char *str, t_point pt, int32_t sn[2])
{
	int32_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] && i < sn[1])
	{
		a_e(img, str[i], pt, sn[0]);
		pt.x += CHAR_WIDTH * sn[0];
		i++;
	}
}

void	draw_str(t_image *img, const char *str, t_point pt, int32_t size)
{
	int32_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		a_e(img, str[i], pt, size);
		pt.x += CHAR_WIDTH * size;
		i++;
	}
}
