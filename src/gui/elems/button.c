/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:58 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/17 13:23:58 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "window.h"
#include "gui/letters.h"
#include "gui/gui_draw.h"
#include "libft.h"

void	draw_button(t_guielem *el)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;

	draw_el_box(el);
	draw_str(el->img, el->label, point(x, y - CHAR_HEIGHT * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
	draw_str(el->img, el->txt, point(get_center_w(el, el->txt),
		get_center_h(el), TXT_COLOR), el->size);
}

t_guielem	*create_button(t_image *img, t_generic_cb cb, void *p)
{
	t_guielem *const	btn = vct_add_dest(&img->win->gui_elems);

	btn->cb.callback = cb;
	btn->cb.cb_param = p;
	btn->type = BUTTON;
	btn->color = GUI_EL_COLOR;
	btn->w = 150;
	btn->h = 60;
	btn->opacity = 0;
	btn->focus = false;
	btn->hover = false;
	btn->label = "";
	btn->txt = "";
	btn->img = img;
	btn->size = 1;
	btn->hide = false;
	return (btn);
}
