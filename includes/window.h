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
	t_callback	events[EVENTS_NUM][EVENTS_LIMIT];
	int32_t		x;
	int32_t		y;

}	t_window;

int8_t	init_window(t_window *window, int32_t x, int32_t y, char *title);
void	destroy_window(t_window *window);
int		end_loop(t_window *window);
void	register_events(t_window *win);

#endif
