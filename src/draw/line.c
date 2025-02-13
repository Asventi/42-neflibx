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

#include "neflibx.h"

static inline uint32_t	abs(int32_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	draw_line_x(t_point pt1, t_point pt2, t_image *img)
{
	const int32_t	dx = pt2.x - pt1.x;
	const int32_t	dir = (pt2.y - pt1.y >= 0) * 2 - 1;
	const int32_t	dy = (pt2.y - pt1.y) * dir;
	int32_t			p;

	p = 2 * dy - dx;
	while (pt1.x <= pt2.x)
	{
		put_pixel_img(img, pt1.x, pt1.y, pt1.color);
		if (p > 0)
		{
			pt1.y += dir;
			p = p - 2 * dx;
		}
		p = p + 2 * dy;
		pt1.x++;
	}
}

static void	draw_line_y(t_point pt1, t_point pt2, t_image *img)
{
	const int32_t	dy = pt2.y - pt1.y;
	const int32_t	dir = (pt2.x - pt1.x >= 0) * 2 - 1;
	const int32_t	dx = (pt2.x - pt1.x) * dir;
	int32_t			p;

	p = 2 * dx - dy;
	while (pt1.y <= pt2.y)
	{
		put_pixel_img(img, pt1.x, pt1.y, pt1.color);
		if (p > 0)
		{
			pt1.x += dir;
			p = p - 2 * dy;
		}
		p = p + 2 * dx;
		pt1.y++;
	}
}

void	draw_line(t_point pt1, t_point pt2, t_image *img)
{
	if (abs(pt2.x - pt1.x) > abs(pt2.y - pt1.y))
	{
		if (pt1.x > pt2.x)
			draw_line_x(pt2, pt1, img);
		else
			draw_line_x(pt1, pt2, img);
	}
	else
	{
		if (pt1.y > pt2.y)
			draw_line_y(pt2, pt1, img);
		else
			draw_line_y(pt1, pt2, img);
	}
}
