/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:33:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 21:33:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "neflibx.h"

static t_window **extend_windows(t_display *display)
{
	int			i;
	t_window	**windows;

	windows = malloc(sizeof (t_window *) * (display->wins_num + 1));
	if (!windows)
		return (0);
	i = -1;
	while (++i < display->wins_num)
		windows[i] = display->wins[i];
	if (display->wins_num > 0)
		free(display->wins);
	display->wins_num++;
	return (windows);
}

int	init_window(t_display *display, int x, int y, char *title)
{
	t_window	*window;
	t_window	**windows;

	if (!display)
		return (-1);
	window = (t_window *)malloc(sizeof (t_window));
	if (!window)
		return (-1);
	windows = extend_windows(display);
	if (!windows)
		return (-1);
	window->win = mlx_new_window(display->mlx, x, y, title);
	if (!window->win)
		return (-1);
	window->x = x;
	window->y = y;
	window->display = display;
	display->wins = windows;
	display->wins[display->wins_num - 1] = window;
	return (display->wins_num - 1);
}

int	destroy_window(t_display *display, int id)
{
	if (display->wins[id])
	{
		mlx_destroy_window(display->mlx, display->wins[id]->win);
		free(display->wins[id]);
		display->wins[id] = 0;
	}
	return (0);
}

int	destroy_all_windows(t_display *display)
{
	int		i;

	i = -1;
	while (++i < display->wins_num)
		destroy_window(display, i);
	return (0);
}