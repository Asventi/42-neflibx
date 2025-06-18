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

#include "window.h"
#include "libft.h"
#include "gui/elems/button.h"
#include "gui/elems/txt_input.h"
#include "gui/elems/container.h"

void	draw_elem(t_guielem *el)
{
	if (el->type == BUTTON)
		draw_button(el);
	else if (el->type == TXT_INPUT)
		draw_txt_input(el);
	else if (el->type == CONTAINER)
		draw_container(el);
}

int		compare_z(void *a, void *b)
{
	if (((t_guielem *)a)->z < ((t_guielem *)b)->z)
		return (1);
	return (0);
}

void	gui_render(t_image *img)
{
	size_t					i;
	t_window const *const	win = img->win;

	vct_sort(win->gui_elems, compare_z);
	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].hide == true)
			continue ;
		draw_elem(win->gui_elems + i);
	}
}
