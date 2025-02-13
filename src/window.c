/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:16:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:16:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/X.h>

#include "mlx.h"
#include "window.h"
#include "utils.h"

void	destroy_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
}

int	end_loop(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

int8_t	init_window(t_window *window, int32_t x, int32_t y, char *title)
{
	ft_bzero(window, sizeof (t_window));
	window->mlx = mlx_init();
	if (!window->mlx)
		return (-1);
	window->win = mlx_new_window(window->mlx, x, y, title);
	if (!window->win)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		return (-1);
	}
	window->x = x;
	window->y = y;
	window->title = title;
	mlx_hook(window->win, DestroyNotify, StructureNotifyMask,
		end_loop, window);
	return (0);
}
