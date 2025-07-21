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

#include "window.h"
#include "libft.h"

t_guielem	**get_child(t_window const *const win, t_guielem *const el)
{
	t_guielem	**childs;
	size_t		i;

	childs = vct_create(sizeof (t_guielem *), 0, 0);
	if (!childs)
		return (NULL);
	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].puid == el->uid)
			vct_add(&childs, &(void *){win->gui_elems + i});
	}
	return (childs);
}

t_guielem	*get_by_id(t_window const *const win, const char *const str)
{
	size_t	i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (!ft_strcmp(str, win->gui_elems[i].id))
			return (win->gui_elems + i);
	}
	return (NULL);
}

t_guielem	*get_by_uid(t_window const *const win, uint32_t uid)
{
	size_t	i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].uid == uid)
			return (win->gui_elems + i);
	}
	return (NULL);
}

t_guielem	*get_by_pos(t_window const *const win,
	int32_t x, int32_t y, void (*not_found_cb)(t_guielem *))
{
	size_t		i;
	int32_t		gx;
	int32_t		gy;
	t_guielem	*ret;

	i = -1;
	ret = NULL;
	while (++i < vct_size(win->gui_elems))
	{
		gx = win->gui_elems[i].x;
		gy = win->gui_elems[i].y;
		if (win->gui_elems[i].hide || win->gui_elems[i].type == ROOT)
			continue ;
		if (gx <= x && x <= gx + win->gui_elems[i].w
			&& gy <= y && y <= gy + win->gui_elems[i].h
			&& (ret == NULL || ret->z < win->gui_elems[i].z))
		{
			not_found_cb(ret);
			ret = win->gui_elems + i;
		}
		else if (not_found_cb)
			not_found_cb(win->gui_elems + i);
	}
	return (ret);
}

t_guielem	*get_focused_el(t_window const *win)
{
	size_t	i;

	i = -1;
	while (++i < vct_size(win->gui_elems))
	{
		if (win->gui_elems[i].focus)
			return (win->gui_elems + i);
	}
	return (NULL);
}
