/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:13:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/12 17:13:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stdint.h>

# include "events.h"
# include "image.h"
# include "gui/gui.h"

typedef struct s_window
{
	void		*mlx;
	void		*win;
	char		*title;
	t_callback	*events[EVENTS_NUM];
	int			x;
	int			y;
	t_guielem	*gui_elems;
	t_guielem	*active_elem;
	bool		shift;
}	t_window;

int		init_window(t_window *window, int x, int y, char *title);
int		destroy_window(t_window *window);
int		end_loop(t_window *window);
void	register_events(t_window *win);
int		init_events(t_window *win);
void	add_gui_elem(t_window *win, t_guielem *elem);

#endif
