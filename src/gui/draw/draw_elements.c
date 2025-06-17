/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:55:28 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/10 11:55:28 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui_draw.h"
#include "draw.h"
#include "colors.h"

void	draw_border(t_guielem *e, uint32_t color, int32_t size, int32_t shift)
{
	draw_rectangle(e->img, point(e->x - shift - size + 1, e->y - size
			- shift + 1, color), e->w + shift * 2 + (size - 1) * 2, size);
	draw_rectangle(e->img, point(e->x - shift - size + 1, e->y + e->h
			+ shift - 1, color), e->w + shift * 2 + (size - 1) * 2, size);
	draw_rectangle(e->img, point(e->x - size - shift + 1, e->y - shift, color),
		size, e->h + shift * 2);
	draw_rectangle(e->img, point(e->x + e->w + shift - 1, e->y - shift, color),
		size, e->h + shift * 2);
}

void	draw_gui_aa(t_guielem *e)
{
	int				size;
	const uint32_t	aa_col = color_mix(GUI_EL_COLOR, 0xffffff, 32);

	size = (e->w + e->h) * AA_MULTIPLIER;
	if (size < 1)
		size = 1;
	draw_border(e, aa_col, size, 1);
}

void	draw_gui_active(t_guielem *e)
{
	int	size;

	size = (e->w + e->h) * SHADOW_MULTIPLIER;
	if (size < 1)
		size = 1;
	draw_border(e, SHADOW_COLOR, size, - size + 1);
}

void	draw_el_box(t_guielem *el)
{
	if (el->hover && !el->focus)
		draw_rectangle(el->img, point(el->x, el->y,
			GUI_FOCUS_COLOR), el->w, el->h);
	else
		draw_rectangle(el->img, point(el->x, el->y, el->color), el->w, el->h);
	draw_gui_aa(el);
	if (el->focus)
		draw_gui_active(el);
}
