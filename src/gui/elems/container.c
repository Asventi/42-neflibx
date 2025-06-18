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

void	draw_container(t_guielem *el, t_image *img)
{
	const int32_t	x = el->x;
	const int32_t	y = el->y;

	draw_el_box(el, img);
	draw_str(img, el->label, point(x, y - CHAR_HEIGHT * el->size
			- LABEL_SPACING, TXT_COLOR), el->size);
}

t_guielem	*create_container(t_guielem **container)
{
	t_guielem *const	el = vct_add_dest(container);

	*el = (t_guielem){0};
	el->type = CONTAINER;
	el->color = CONTAINER_COLOR;
	el->w = 400;
	el->h = 400;
	el->size = 1;
	el->container = *container;
	return (el);
}
