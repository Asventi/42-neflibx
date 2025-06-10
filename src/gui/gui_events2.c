/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:20:11 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 19:20:11 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "window.h"
#include "libft.h"

void	keypress_f(t_guielem *elem, int keycode)
{
	if (elem->type == TXT_INPUT)
		elem_txt_key(elem, keycode);
}

void	gui_keypress(int keycode, void *p)
{
	const t_window	*win = (t_window *)p;
	size_t			i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		if (win->gui_elems[i].active && win->gui_elems[i].type == TXT_INPUT)
			keypress_f(&win->gui_elems[i], keycode);
	}
}

void	gui_ptr(int x, int y, void *p)
{
	const t_window	*win = (t_window *)p;
	int				gx;
	int				gy;
	size_t			i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		gx = win->gui_elems[i].x;
		gy = win->gui_elems[i].y;
		if (gx <= x && x <= gx + win->gui_elems[i].w
			&& gy <= y && y <= gy + win->gui_elems[i].h)
		{
			win->gui_elems[i].focus = true;
		}
		else
			win->gui_elems[i].focus = false;
	}
}
