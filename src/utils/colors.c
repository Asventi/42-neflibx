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

int32_t	get_argb(unsigned char a, unsigned char r,
						unsigned char g, unsigned char b)
{
	return ((int32_t)a << 24 | (int32_t)r << 16 | (int32_t)g << 8 | (int32_t)b);
}

unsigned char	get_a(int32_t color)
{
	return (color >> 24 & 0xFF);
}

unsigned char	get_r(int32_t color)
{
	return (color >> 16 & 0xFF);
}

unsigned char	get_g(int32_t color)
{
	return (color >> 8 & 0xFF);
}

unsigned char	get_b(int32_t color)
{
	return (color & 0xFF);
}