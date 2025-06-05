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

void	draw_button(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	const int32_t	w = el->w;
	const int32_t	h = el->h;

	draw_rectangle(img, point(x, y, el->color), w, h);
	draw_str(img, el->label, point(x, y - CHAR_HEIGHT * el->size
		- LABEL_SPACING, TXT_COLOR), el->size);
	draw_str(img, el->txt, point(get_center_w(el, el->txt), get_center_h(el),
		TXT_COLOR), el->size);
	draw_gui_aa(el, img);
	if (el->active)
		draw_gui_shadow(el, img);
}

void	create_button(t_image *img, t_guielem *btn, t_generic_cb cb, void *p)
{
	btn->cb.callback = cb;
	btn->cb.cb_param = p;
	btn->type = BUTTON;
	btn->color = GUI_EL_COLOR;
	btn->w = 150;
	btn->h = 60;
	btn->opacity = 0;
	btn->active = false;
	btn->label = "";
	btn->txt = "";
	btn->img = img;
	btn->size = 1;
	btn->hide = false;
}
