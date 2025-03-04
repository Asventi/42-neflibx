/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:24:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/24 16:24:02 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# ifndef EVENTS_LIMIT
#  define EVENTS_LIMIT 32
# endif
# define EVENTS_NUM 16

# include <stdint.h>

typedef void	(*t_generic_cb)(void *p);
typedef void	(*t_key_cb)(int keycode, void *p);

typedef struct s_callback
{
	t_generic_cb	callback;
	void			*cb_param;
}	t_callback;

void	register_keypress(t_callback events[EVENTS_NUM][EVENTS_LIMIT],
			t_key_cb cb, void *cb_param);

int		keypress_event(int keycode,
			t_callback events[EVENTS_NUM][EVENTS_LIMIT]);

void	register_keyrelease(t_callback events[EVENTS_NUM][EVENTS_LIMIT],
			t_key_cb cb, void *cb_param);

int		keyrelease_event(int keycode,
			t_callback events[EVENTS_NUM][EVENTS_LIMIT]);

#endif
