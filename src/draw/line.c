/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:35:55 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 20:35:55 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "neflibx.h"

int	draw_line(t_display *display, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;

	dx = x1 - x0;
	dy = y1 - y0;
	p = 2*dy - dx;
	while (x0 <= x1)
	{
		mlx_pixel_put(display->mlx, display->wins[0]->win, x0, y0, 0x00FFFFFF);
		if (p > 0)
		{
			y0++;
			p = p - 2*dx;
		}
		p = p + 2*dy;
		x0++;
	}
	return (0);
}
