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

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	draw_line_x(t_display *display, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dy - dx;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	while (x0 <= x1)
	{
		mlx_pixel_put(display->mlx, display->wins[0]->win, x0, y0, 0x00FFFFFF);
		if (p > 0)
		{
			y0 += dir;
			p = p - 2 * dx;
		}
		p = p + 2 * dy;
		x0++;
	}
	return (0);
}

static int	draw_line_y(t_display *display, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dx - dy;
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	while (y0 <= y1)
	{
		mlx_pixel_put(display->mlx, display->wins[0]->win, x0, y0, 0x00FFFFFF);
		if (p > 0)
		{
			x0 += dir;
			p = p - 2 * dy;
		}
		p = p + 2 * dx;
		y0++;
	}
	return (0);
}

int	draw_line(t_display *display, int x0, int y0, int x1, int y1)
{
	if (abs(x1 - x0) > abs(y1 - y0))
	{
		if (x0 > x1)
			draw_line_x(display, x1, y1, x0, y0);
		else
			draw_line_x(display, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			draw_line_y(display, x1, y1, x0, y0);
		else
			draw_line_y(display, x0, y0, x1, y1);
	}
	return (0);
}
