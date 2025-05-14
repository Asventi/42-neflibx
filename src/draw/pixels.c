/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:56:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/14 14:56:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "image.h"
#include "draw.h"
#include "window.h"

void	put_pixel_img(t_image *image, t_point pt)
{
	char	*dest;

	pt.color = mlx_get_color_value(image->win->mlx, (int32_t) pt.color);
	dest = image->addr + pt.y * image->len + pt.x * (image->bpp / 8);
	*(uint32_t *)dest = pt.color;
}
