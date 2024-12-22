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
#include "neflibx.h"

int	end(int keycode, t_display *display)
{
	if (keycode == 65507 || keycode == 65307)
	{
		destroy_all_windows(display);
		mlx_loop_end(display->mlx);
	}
	return (0);
}

int	main_loop(t_display *display)
{
	return (0);
}

int	main(void)
{
	t_display	*display;
	int			win1;
	int			win2;
	int			win3;

	display = init_display();
	win1 = init_window(display, 800, 800, "win1");
	draw_line(display, 0, 0, 200, 170);
	mlx_key_hook(display->wins[0]->win, end, display);
	mlx_loop(display->mlx);
	destroy_display(display);
}