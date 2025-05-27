/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/07 10:52:46 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <neflibx.h>

t_color	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_color){.b = b, .g = g, .r = r, .a = a});
}

uint32_t	colorx(int32_t color, float m)
{
	t_color		ncolor;
	uint32_t	rgb[3];

	ncolor.argb = color;
	rgb[0] = ncolor.r * m;
	if (rgb[0] > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb[0];
	rgb[1] = ncolor.g * m;
	if (rgb[1] > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb[1];
	rgb[1] = ncolor.b * m;
	if (rgb[1] > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb[1];
	return (ncolor.argb);
}

uint32_t	colorp(uint32_t color, uint32_t color2)
{
	t_color		ncolor;
	t_color		ncolor2;
	uint32_t	rgb[3];

	ncolor.argb = color;
	ncolor2.argb = color2;
	rgb[0] = ncolor.r + ncolor2.r;
	if (rgb[0] > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb[0];
	rgb[1] = ncolor.g + ncolor2.g;
	if (rgb[1] > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb[1];
	rgb[1] = ncolor.b + ncolor2.b;
	if (rgb[1] > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb[1];
	return (ncolor.argb);
}

uint32_t	color_mix(uint32_t color1, uint32_t color2)
{
	uint32_t	col1;
	uint32_t	col2;

	col1 = colorx(color1, 0.5);
	col2 = colorx(color2, 0.5);
	return (colorp(col1, col2));
}
