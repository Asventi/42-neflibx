/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:01:52 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/16 12:01:52 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "gui/gui_draw.h"
#include "gui/letters.h"
#include "libft.h"
#include "window.h"

void	draw_container(t_guielem *el)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;

	draw_el_box(el);
	draw_str(el->img, el->label, point(x, y - CHAR_HEIGHT * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
}

t_guielem	*create_container(t_image *img)
{
	t_guielem *const	btn = vct_add_dest(&img->win->gui_elems);

	*btn = (t_guielem){0};
	btn->type = CONTAINER;
	btn->color = CONTAINER_COLOR;
	btn->w = 400;
	btn->h = 400;
	btn->label = "";
	btn->txt = "";
	btn->img = img;
	btn->size = 1;
	return (btn);
}
