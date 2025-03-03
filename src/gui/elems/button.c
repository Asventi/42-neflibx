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
#include "gui/gui.h"
#include "gui/letters.h"
#include "gui/gui_draw.h"
#include "utils.h"

void	draw_button(t_button *btn)
{
	int32_t	x;
	int32_t	y;
	int32_t	w;
	int32_t	h;

	x = btn->b.x;
	y = btn->b.y;
	w = btn->b.w;
	h = btn->b.h;
	draw_rectangle(btn->b.img, point(x, y, btn->b.color), w, h);
	draw_str(btn->b.img, btn->label, point(x + (w - nef_strlen(btn->label)
				* CHAR_WIDTH) / 2, y + (h - CHAR_HEIGHT) / 2, 0xFFFFFF), 1);
	if (btn->shadow)
		draw_box_shadow((t_guielem *)btn);
}

void	create_button(t_button *btn, t_image *img, t_generic_cb cb, void *p)
{
	btn->b.cb.callback = cb;
	btn->b.cb.cb_param = p;
	btn->b.id = BUTTON;
	btn->b.img = img;
	btn->b.color = GUI_COLOR;
	btn->b.w = 150;
	btn->b.h = 60;
	btn->b.opacity = 0;
	btn->shadow = true;
	btn->label = "";
}
