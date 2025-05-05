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

void	draw_box_shadow(t_guielem *e)
{
	draw_rectangle(e->img,
		point(e->x + 2, e->y + e->h, 0x57595c), e->w - 1, 2);
	draw_rectangle(e->img,
		point(e->x + e->w, e->y + 2, 0x57595c), 1, e->h - 1);
}
