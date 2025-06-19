/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:06:57 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/04 14:06:57 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "draw.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"

#include <X11/keysym.h>

#include "window.h"

void	draw_txt_input(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;
	const int32_t	w = el->w;
	const int32_t	h = el->h;
	int32_t			to_w;

	draw_rectangle(img, point(x, y, el->color), w, h);
	draw_str(img, el->label, point(x, y - CHAR_HEIGHT * el->size - 4,
			TXT_COLOR), el->size);
	to_w = 0;
	if (ft_strlen(el->txt) > (w - w * 0.1) / (CHAR_WIDTH * el->size))
		to_w = ft_strlen(el->txt) - (w - w * 0.1) / (CHAR_WIDTH * el->size);
	draw_str(img, el->txt + to_w, point(x + w * 0.05, y
			+ (h - CHAR_HEIGHT * el->size) / 2, TXT_COLOR), el->size);
	if (el->shadow && !el->active)
		draw_box_shadow(el, img);
	else if (el->shadow && el->active)
	{
		draw_inner_shadow(el, img);
		draw_rectangle(img, point(x + (el->cursor - to_w)
				* CHAR_WIDTH * el->size + (w * 0.05), y + h / 2 - 4 - (2
					* el->size), 0xd3c6aa), 1, CHAR_HEIGHT * el->size + 4);
	}
}

void	create_txt_box(t_image *img, t_guielem *txt, t_txt_cb cb, void *p)
{
	txt->cb.callback = (t_generic_cb)cb;
	txt->cb.cb_param = p;
	txt->id = TXT_INPUT;
	txt->color = BACK_COLOR;
	txt->w = 150;
	txt->h = 20;
	txt->opacity = 0;
	txt->shadow = true;
	txt->label = "txt_box";
	txt->img = img;
	txt->cursor = 0;
	txt->txt = vct_create(sizeof (char), 0, 0);
	txt->size = 1;
	txt->active = false;
	txt->hide = false;
	vct_add(&txt->txt, &(char){0});
}
