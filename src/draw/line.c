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

static int	draw_line_x(t_window *win, t_point pt1, t_point pt2)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	if (dy < 0)
		dir = -1;
	else
		dir = 1;
	dy *= dir;
	p = 2 * dy - dx;
	while (pt1.x <= pt2.x)
	{
		mlx_pixel_put(win->display->mlx, win->win, pt1.x, pt1.y, pt1.color);
		if (p > 0)
		{
			pt1.y += dir;
			p = p - 2 * dx;
		}
		p = p + 2 * dy;
		pt1.x++;
	}
	return (0);
}

static int	draw_line_y(t_window *win, t_point pt1, t_point pt2)
{
	int	dx;
	int	dy;
	int	p;
	int	dir;

	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	if (dx < 0)
		dir = -1;
	else
		dir = 1;
	dx *= dir;
	p = 2 * dx - dy;
	while (pt1.y <= pt2.y)
	{
		mlx_pixel_put(win->display->mlx, win->win, pt1.x, pt1.y, pt1.color);
		if (p > 0)
		{
			pt1.x += dir;
			p = p - 2 * dy;
		}
		p = p + 2 * dx;
		pt1.y++;
	}
	return (0);
}

int	draw_line(t_window *window, t_point pt1, t_point pt2)
{
	if (abs(pt2.x - pt1.x) > abs(pt2.y - pt1.y))
	{
		if (pt1.x > pt2.x)
			draw_line_x(window, pt2, pt1);
		else
			draw_line_x(window, pt1, pt2);
	}
	else
	{
		if (pt1.y > pt2.y)
			draw_line_y(window, pt2, pt1);
		else
			draw_line_y(window, pt1, pt2);
	}
	return (0);
}
