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

# define EVENTS_NUM 16
# define KEYPRESS 0
# define KEYRELEASE 1
# define BTNPRESS 2
# define BTNRELEASE 3
# define POINTER 4

# include <stdint.h>

typedef void	(*t_generic_cb)(void *p);
typedef void	(*t_key_cb)(int keycode, void *p);
typedef void	(*t_btn_cb)(int keycode, int x, int y, void *p);
typedef void	(*t_ptr_cb)(int x, int y, void *p);

typedef struct s_callback
{
	t_generic_cb	callback;
	void			*cb_param;
}	t_callback;

void	register_keypress(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param);

int		keypress_event(int keycode,
			t_callback *events[EVENTS_NUM]);

void	register_keyrelease(t_callback *events[EVENTS_NUM],
			t_key_cb cb, void *cb_param);

int		keyrelease_event(int keycode,
			t_callback *events[EVENTS_NUM]);

void	register_btnpress(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param);

int		btnpress_event(int keycode, int x, int y,
			t_callback *events[EVENTS_NUM]);

void	register_btnrelease(t_callback *events[EVENTS_NUM],
			t_btn_cb cb, void *cb_param);

int		btnrelease_event(int keycode, int x, int y,
			t_callback *events[EVENTS_NUM]);

void	register_pointer(t_callback *events[EVENTS_NUM],
			t_ptr_cb cb, void *cb_param);

int	pointer_event(int x, int y,
		t_callback *events[EVENTS_NUM]);

#endif
