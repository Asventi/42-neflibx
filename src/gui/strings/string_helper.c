/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:01:25 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/05 13:01:25 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui/gui.h"
#include "libft.h"
#include "gui/letters.h"

int32_t	get_c_to_write(t_guielem *el)
{
	if (ft_strlen(el->txt) > (el->w * 0.9) / (CHAR_WIDTH * el->size))
		return (ft_strlen(el->txt) - (el->w * 0.9) / (CHAR_WIDTH * el->size));
	return (0);
}
