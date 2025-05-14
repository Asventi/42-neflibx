/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:26:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/06 15:26:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

#include "colors.h"
#include "draw.h"
#include "window.h"
#include "libft.h"
#include "mlx.h"

void	gui_render(void *p)
{
	t_window	*win;
	size_t		i;

	win = (t_window *)p;
	i = 0;
	while (i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].id == BUTTON)
			draw_button(&win->gui_elems[i], win->gui_elems[i].img);
		i++;
	}
	if (vct_size(win->gui_elems) > 0)
		mlx_put_image_to_window(win->mlx, win->win, win->gui_elems[0].img->img, 0, 0);
}
