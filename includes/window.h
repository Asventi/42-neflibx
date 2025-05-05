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

typedef struct s_window
{
	void		*mlx;
	void		*win;
	char		*title;
	t_callback	*events[EVENTS_NUM];
	int			x;
	int			y;

}	t_window;

int		init_window(t_window *window, int x, int y, char *title);
int		destroy_window(t_window *window);
int		end_loop(t_window *window);
void	register_events(t_window *win);

#endif
