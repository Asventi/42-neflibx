/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:01:10 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:01:10 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <X11/keysym.h>
#include "neflibx.h"

static t_point	create_point(int x, int y, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.color = color;
	return (point);
}

int	end(int keycode, t_display *display)
{
	if (keycode == XK_Escape)
	{
		destroy_all_windows(display);
		mlx_loop_end(display->mlx);
	}
	return (0);
}

int	main(void)
{
	t_display	*display;
	t_window	*win1;
	t_window	*win2;
	t_window	*win3;

	display = init_display();
	win1 = init_window(display, 800, 800, "win1");
	draw_line(win1, create_point(100, 100, 0xFFFFFF),
		create_point(600, 200, 0xFFFFFF));
	destroy_window(win1);
	mlx_key_hook(display->wins[0]->win, end, display);
	mlx_loop(display->mlx);
	destroy_display(display);
}
