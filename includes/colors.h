/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:05 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/14 18:21:05 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

typedef union u_color
{
	uint32_t	argb;
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_color;

t_color		argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
uint32_t	colorx(int32_t color, float m);
uint32_t	colorp(uint32_t color, uint32_t color2);
uint32_t	color_mix(uint32_t color1, uint32_t color2);

#endif
