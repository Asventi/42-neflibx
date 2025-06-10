/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:21 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:34:21 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "draw.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"
#include "window.h"

void	draw_txt_input(t_guielem *el)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	const int32_t	w = el->w;
	const int32_t	h = el->h;
	const int32_t	to_w = get_c_to_write(el);

	draw_el_box(el);
	draw_str(el->img, el->label, point(x, y - CHAR_HEIGHT * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
	draw_str(el->img, el->txt + to_w, point(x + w * INPUT_MARGIN, y
			+ (h - CHAR_HEIGHT * el->size) / 2, TXT_COLOR), el->size);
	if (el->focus)
	{
		draw_rectangle(el->img, point(x + (el->cursor - to_w)
				* CHAR_WIDTH * el->size + (w * INPUT_MARGIN), y + h / 2 - 4 - (2
					* el->size), 0xd3c6aa), 1, CHAR_HEIGHT * el->size + 4);
	}
}

t_guielem	*create_txt_input(t_image *img, t_txt_cb cb, void *p)
{
	t_guielem *const	el = vct_add_dest(&img->win->gui_elems);

	el->cb.callback = (t_generic_cb)cb;
	el->cb.cb_param = p;
	el->type = TXT_INPUT;
	el->color = GUI_EL_COLOR;
	el->w = 150;
	el->h = 20;
	el->label = "input";
	el->img = img;
	el->cursor = 0;
	el->txt = vct_create(sizeof (char), 0, 0);
	el->size = 1;
	el->focus = false;
	el->hide = false;
	vct_add(&el->txt, &(char){0});
	return (el);
}
