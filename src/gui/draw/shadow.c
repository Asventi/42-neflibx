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

#include "draw.h"
#include "gui/gui.h"

void	draw_box_shadow(t_guielem *e, t_image *img)
{
	const int	size = (e->w + e->h) / 200 + 1;

	draw_rectangle(img,
		point(e->x, e->y + e->h - size + 1, SHADOW_COLOR), e->w, size);
	draw_rectangle(img,
		point(e->x + e->w - size + 1, e->y, SHADOW_COLOR), size, e->h);
}

void	draw_inner_shadow(t_guielem *e, t_image *img)
{
	const int	size = (e->w + e->h) / 200 + 1;

	draw_rectangle(img,
		point(e->x, e->y + e->h - size + 1, e->color), e->w, size);
	draw_rectangle(img,
		point(e->x + e->w - size + 1, e->y, e->color), size, e->h);
	draw_rectangle(img,
		point(e->x, e->y, SHADOW_COLOR), e->w + 1, size);
	draw_rectangle(img,
		point(e->x, e->y, SHADOW_COLOR), size, e->h + 1);
}
