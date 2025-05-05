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

#include "mlx.h"
#include "window.h"
#include "libft.h"

int	destroy_window(t_window *window)
{
	int8_t	i;

	i = -1;
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	while (++i < EVENTS_NUM)
		if (window->events[i])
			vct_destroy(window->events[i]);
	return (0);
}

int	end_loop(t_window *window)
{
	mlx_loop_end(window->mlx);
	return (0);
}

int	init_window(t_window *window, int x, int y, char *title)
{
	int	i;

	*window = (t_window){0};
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
	i = -1;
	while (++i < EVENTS_NUM)
	{
		window->events[i] = vct_create(sizeof (t_callback), 0, 0);
		if (!window->events[i])
			return (destroy_window(window));
	}
	window->x = x;
	window->y = y;
	window->title = title;
	return (0);
}
