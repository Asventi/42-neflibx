/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:03:54 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/03 11:03:54 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>

#include "events.h"
#include "window.h"
#include "mlx.h"

void	register_events(t_window *win)
{
	mlx_hook(win->win, KeyPress, KeyPressMask, keypress_event, win->events);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask,
		keyrelease_event, win->events);
	mlx_hook(win->win, ButtonPress, ButtonPressMask,
		btnpress_event, win->events);
	mlx_hook(win->win, ButtonRelease, ButtonReleaseMask,
		btnrelease_event, win->events);
	mlx_hook(win->win, MotionNotify, PointerMotionMask,
		pointer_event, win->events);
}
