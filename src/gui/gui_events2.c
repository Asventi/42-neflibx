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

#include "window.h"
#include "gui/elems/txt_input.h"

void	keypress_f(t_guielem *elem, int keycode)
{
	if (elem->type == TXT_INPUT)
		elem_txt_key(elem, keycode);
}

void	gui_keypress(int keycode, void *p)
{
	t_window const *const	win = (t_window *)p;
	t_guielem *const		el = get_focused_el(win);

	if (!el)
		return ;
	keypress_f(el, keycode);
}

void	gui_ptr(int x, int y, void *p)
{
	t_window const *const	win = (t_window *)p;
	t_guielem *const		el = get_by_pos(win, x, y, unhover);

	if (!el)
		return ;
	if (el->type == CONTAINER)
		return ;
	el->hover = true;
}
