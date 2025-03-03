/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:09:51 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/13 09:09:51 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_point	point(int x, int y, uint32_t color)
{
	t_point	pt;

	pt.x = x;
	pt.y = y;
	pt.color = color;
	return (pt);
}
