/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:21:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/20 14:21:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "draw.h"
#include "gui/gui.h"

void	draw_gui_aa(t_guielem *e, t_image *img)
{
	const int		size = (e->w + e->h) * SHADOW_MULTIPLIER;
	const uint32_t	aa_col = color_mix(GUI_EL_COLOR, 0xffffff, 32);

	draw_rectangle(img, point(e->x - 1, e->y - size, aa_col),
		e->w + 2, size);
	draw_rectangle(img, point(e->x - 1, e->y + e->h, aa_col),
		e->w + 2, size);
	draw_rectangle(img, point(e->x - size, e->y, aa_col),
		size, e->h);
	draw_rectangle(img, point(e->x + e->w, e->y, aa_col),
		size, e->h);
}

void	draw_gui_shadow(t_guielem *e, t_image *img)
{
	const int	size = (e->w + e->h) * SHADOW_MULTIPLIER;

	draw_rectangle(img,
		point(e->x, e->y, SHADOW_COLOR), e->w, size);
	draw_rectangle(img,
		point(e->x, e->y, SHADOW_COLOR), size, e->h);
	draw_rectangle(img,
		point(e->x, e->y + e->h - size, SHADOW_COLOR), e->w, size);
	draw_rectangle(img,
		point(e->x + e->w - size, e->y, SHADOW_COLOR), size, e->h);
}
