/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:23:42 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/24 16:23:42 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	register_keypress(t_callback events[EVENTS_NUM][EVENTS_LIMIT], t_key_cb cb, void *cb_param)
{
	int32_t	i;

	i = 0;
	while (i < EVENTS_LIMIT && events[0][i].callback)
		i++;
	events[0][i].callback = (t_generic_cb)cb;
	events[0][i].cb_param = cb_param;
}

int	keypress_event(int keycode, t_callback events[EVENTS_NUM][EVENTS_LIMIT])
{
	int32_t		i;

	i = 0;
	while (i < EVENTS_LIMIT && events[0][i].callback)
	{
		((t_key_cb)events[0][i].callback)(keycode,
			events[0][i].cb_param);
		i++;
	}
	return (0);
}
