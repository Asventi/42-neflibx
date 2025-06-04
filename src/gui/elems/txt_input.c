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

#include <X11/keysym.h>

#include "window.h"

static void	cursor(t_guielem *el, int keycode)
{
	int32_t	to_w;

	to_w = 0;
	if (ft_strlen(el->txt) > (el->w - el->w * 0.1) / (CHAR_WIDTH * el->size))
		to_w = ft_strlen(el->txt) - (el->w - el->w * 0.1)
			/ (CHAR_WIDTH * el->size);
	if (keycode == XK_Right
		&& el->cursor < (int32_t)vct_size(el->txt) - 1)
		el->cursor += 1;
	else if (keycode == XK_Left && el->cursor > to_w)
		el->cursor -= 1;
}

void	elem_txt_key(t_guielem *input, int keycode)
{
	if (!input->active)
		return ;
	if (32 <= keycode && keycode <= 126)
	{
		if (input->img->win->shift)
			keycode = get_shifted(keycode);
		vct_insert(&input->txt, &keycode, input->cursor);
		input->cursor += 1;
	}
	else if (keycode == XK_Return)
	{
		((t_txt_cb)input->cb.callback)(input->txt, input->cb.cb_param);
		vct_erase(input->txt, 0, vct_size(input->txt) - 1);
		input->cursor = 0;
	}
	else if (keycode == XK_BackSpace && input->cursor > 0)
	{
		vct_delete(input->txt, input->cursor - 1);
		input->cursor -= 1;
	}
	cursor(input, keycode);
}

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
		draw_gui_aa(el, img);
	else if (el->shadow && el->active)
	{
		draw_gui_shadow(el, img);
		draw_rectangle(img, point(x + (el->cursor - to_w)
				* CHAR_WIDTH * el->size + (w * 0.05), y + h / 2 - 4 - (2
					* el->size), 0xd3c6aa), 1, CHAR_HEIGHT * el->size + 4);
	}
}

void	create_txt_input(t_image *img, t_guielem *input, t_txt_cb cb, void *p)
{
	input->cb.callback = (t_generic_cb)cb;
	input->cb.cb_param = p;
	input->type = TXT_INPUT;
	input->color = GUI_EL_COLOR;
	input->w = 150;
	input->h = 20;
	input->opacity = 0;
	input->shadow = true;
	input->label = "input";
	input->img = img;
	input->cursor = 0;
	input->txt = vct_create(sizeof (char), 0, 0);
	input->size = 1;
	input->active = false;
	input->hide = false;
	vct_add(&input->txt, &(char){0});
}
