/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:34:57 by pjarnac           #+#    #+#             */
/*   Updated: 2025/05/27 13:34:57 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"

void	elem_txt_press(t_guielem *input, int x, int y)
{
	(void)x;
	(void)y;
	input->active = true;
}
