/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:52:46 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 17:34:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <neflibx.h>
#include <math.h>

t_color	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_color){.b = b, .g = g, .r = r, .a = a});
}

uint32_t	colorx(int32_t color, float m)
{
	t_color		ncolor;
	uint32_t	rgb;

	ncolor.argb = color;
	rgb = ncolor.r * m;
	if (rgb > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb;
	rgb = ncolor.g * m;
	if (rgb > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb;
	rgb = ncolor.b * m;
	if (rgb > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb;
	return (ncolor.argb);
}

uint32_t	colorp(uint32_t color, uint32_t color2)
{
	t_color		ncolor;
	t_color		ncolor2;
	uint32_t	rgb;

	ncolor.argb = color;
	ncolor2.argb = color2;
	rgb = ncolor.r + ncolor2.r;
	if (rgb > 255)
		ncolor.r = 255;
	else
		ncolor.r = rgb;
	rgb = ncolor.g + ncolor2.g;
	if (rgb > 255)
		ncolor.g = 255;
	else
		ncolor.g = rgb;
	rgb = ncolor.b + ncolor2.b;
	if (rgb > 255)
		ncolor.b = 255;
	else
		ncolor.b = rgb;
	return (ncolor.argb);
}

uint32_t	color_mix(uint32_t color, uint32_t mix_color, uint32_t nb_mix)
{
	t_color		old;
	t_color		mix;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	old.argb = color;
	mix.argb = mix_color;
	r = roundf((nb_mix * old.r + mix.r) * ((float)1 / (nb_mix + 1)));
	if (r > 255)
		r = 255;
	g = roundf((nb_mix * old.g + mix.g) * ((float)1 / (nb_mix + 1)));
	if (g > 255)
		g = 255;
	b = roundf((nb_mix * old.b + mix.b) * ((float)1 / (nb_mix + 1)));
	if (b > 255)
		b = 255;
	return (r * 0x10000 + g * 0x100 + b);
}
