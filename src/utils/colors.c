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

uint32_t	argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((uint32_t)a << 24 | (uint32_t)r << 16 |
		(uint32_t)g << 8 | (uint32_t)b);
}

uint8_t	get_a(uint32_t color)
{
	return (color >> 24 & 0xFF);
}

uint8_t	get_r(uint32_t color)
{
	return (color >> 16 & 0xFF);
}

uint8_t	get_g(uint32_t color)
{
	return (color >> 8 & 0xFF);
}

uint8_t	get_b(uint32_t color)
{
	return (color & 0xFF);
}
