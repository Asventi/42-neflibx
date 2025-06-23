/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:00:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/23 11:00:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui_draw.h"
#include "draw.h"
#include "colors.h"
#include "libft.h"

void	draw_scroll(t_guielem *el, t_image *img)
{
	t_guielem **const	childs = get_child(img->win, el);

	free_vct(childs);
}
