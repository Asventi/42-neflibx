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

static void	cursor(t_guielem *input, int keycode)
{
	int32_t	to_w;

	to_w = 0;
	if ((int32_t)ft_strlen(input->txt) > (input->w - 2)
		/ (CHAR_WIDTH * input->size))
		to_w = ft_strlen(input->txt) - (input->w - 2)
			/ (CHAR_WIDTH * input->size);
	if (keycode == XK_Right
		&& input->cursor < (int32_t)vct_size(input->txt) - 1)
		input->cursor += 1;
	else if (keycode == XK_Left && input->cursor > to_w)
		input->cursor -= 1;
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
		input->active = false;
		input->cursor = 0;
	}
	else if (keycode == XK_BackSpace && input->cursor > 0)
	{
		vct_delete(input->txt, input->cursor - 1);
		input->cursor -= 1;
	}
	cursor(input, keycode);
}

void	draw_txt_input(t_guielem *input, t_image *img)
{
	const int32_t	x = input->x;
	const int32_t	y = input->y;
	const int32_t	w = input->w;
	const int32_t	h = input->h;
	int32_t			to_w;

	draw_rectangle(img, point(x, y, input->color), w, h);
	draw_str(img, input->label, point(x, y - CHAR_HEIGHT * input->size - 4,
		0xFFFFFF), input->size);
	to_w = 0;
	if ((int32_t)ft_strlen(input->txt) > (w - 2) / (CHAR_WIDTH * input->size))
		to_w = ft_strlen(input->txt) - (w - 2) / (CHAR_WIDTH * input->size);
	draw_str(img, input->txt + to_w,
		point(x + 2, y + (h - CHAR_HEIGHT * input->size) / 2, 0), input->size);
	if (input->shadow && !input->active)
		draw_box_shadow(input, img);
	else if (input->shadow && input->active)
	{
		draw_inner_shadow(input, img);
		draw_rectangle(img, point(x + (input->cursor - to_w)
				* CHAR_WIDTH * input->size + 1, y + h / 2
				- 4 - (2 * input->size), 0), 1, CHAR_HEIGHT * input->size + 4);
	}
}

void	create_txt_input(t_image *img, t_guielem *input, t_txt_cb cb, void *p)
{
	input->cb.callback = (t_generic_cb)cb;
	input->cb.cb_param = p;
	input->id = TXT_INPUT;
	input->color = INPUT_COLOR;
	input->w = 150;
	input->h = 20;
	input->opacity = 0;
	input->shadow = true;
	input->label = "input";
	input->img = img;
	input->cursor = 0;
	input->txt = vct_create(sizeof (char), 0, 0);
	input->size = 1;
	input->hide = false;
	vct_add(&input->txt, &(char){0});
}
