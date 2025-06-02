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

void	draw_button(t_guielem *btn, t_image *img)
{
	int32_t	x;
	int32_t	y;
	int32_t	w;
	int32_t	h;

	x = btn->x;
	y = btn->y;
	w = btn->w;
	h = btn->h;
	draw_rectangle(img, point(x, y, btn->color), w, h);
	draw_str(img, btn->label, point(x + (w - ft_strlen(btn->label)
				* CHAR_WIDTH) / 2, y + (h - CHAR_HEIGHT) / 2, 0xFFFFFF), 1);
	if (btn->shadow && !btn->active)
		draw_box_shadow(btn, img);
	else if (btn->shadow && btn->active)
		draw_inner_shadow(btn, img);
}

void	create_button(t_image *img, t_guielem *btn, t_generic_cb cb, void *p)
{
	btn->cb.callback = cb;
	btn->cb.cb_param = p;
	btn->id = BUTTON;
	btn->color = GUI_COLOR;
	btn->w = 150;
	btn->h = 60;
	btn->opacity = 0;
	btn->shadow = true;
	btn->active = false;
	btn->label = "";
	btn->img = img;
	btn->hide = false;
}
