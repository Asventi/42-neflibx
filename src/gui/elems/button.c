/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:58 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/17 13:23:58 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "draw.h"
#include "gui.h"

void	show_button(t_window *window, t_button *button)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < button->h)
	{
		j = -1;
		while (++j < button->w)
		{
			put_pixel_img(img, point(button->base.x + j,
				button->base.y + i, button->color));
		}
	}

}

void	create_button(t_button *button)
{

}
