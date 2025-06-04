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

void	gui_render(t_image *img)
{
	size_t		i;
	t_window	*win;

	win = img->win;
	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		if (win->gui_elems[i].type == BUTTON)
			draw_button(&win->gui_elems[i], win->gui_elems[i].img);
		else if (win->gui_elems[i].type == TXT_INPUT)
			draw_txt_input(&win->gui_elems[i], win->gui_elems[i].img);
	}
}
