/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:34:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/14 12:34:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"
#include "gui/elems/button.h"
#include "gui/elems/txt_input.h"

void	btnpress_f(t_guielem *elem, int x, int y)
{
	if (elem->type == BUTTON)
		elem_btn_press(elem, x, y);
	else if (elem->type == TXT_INPUT)
		elem_txt_press(elem, x, y);
}

void	btnrelease_f(t_guielem *elem, int x, int y)
{
	if (elem->type == BUTTON)
		elem_btn_release(elem, x, y);
}

void	gui_btnpress(int keycode, int x, int y, void *p)
{
	const t_window	*win = (t_window *)p;
	int				gx;
	int				gy;
	size_t			i;

	i = -1;
	if (keycode != 1)
		return ;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		gx = win->gui_elems[i].x;
		gy = win->gui_elems[i].y;
		if (gx <= x && x <= gx + win->gui_elems[i].w
			&& gy <= y && y <= gy + win->gui_elems[i].h)
		{
			btnpress_f(&win->gui_elems[i], x, y);
		}
	}
}

void	gui_btnrelease(int keycode, int x, int y, void *p)
{
	const t_window	*win = (t_window *)p;
	int				gx;
	int				gy;
	size_t			i;

	i = -1;
	if (keycode != 1)
		return ;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		gx = win->gui_elems[i].x;
		gy = win->gui_elems[i].y;
		if (gx <= x && x <= gx + win->gui_elems[i].w
			&& gy <= y && y <= gy + win->gui_elems[i].h)
		{
			btnrelease_f(&win->gui_elems[i], x, y);
		}
		else
			win->gui_elems[i].focus = false;
	}
}
