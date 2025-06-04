/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:06:42 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/04 15:06:42 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

t_guielem	*get_by_label(t_window *win, const char *const str)
{
	size_t	i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (ft_strcmp(str, win->gui_elems[i].label) == 0)
			return (win->gui_elems + i);
	}
	return (NULL);
}
