/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:49:18 by pjarnac           #+#    #+#             */
/*   Updated: 2025/01/06 10:49:18 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "image.h"

int8_t	create_image(t_image *image, int32_t w, int32_t h, t_window *window)
{
	image->img = mlx_new_image(window->mlx, w, h);
	if (!image->img)
		return (-1);
	image->w = w;
	image->h = h;
	image->win = window;
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->len, &image->endian);
	if (!image->addr)
	{
		mlx_destroy_image(window->mlx, image->img);
		return (-1);
	}
	return (0);
}

void	put_pixel_img(t_image *image, int32_t x, int32_t y, int32_t color)
{
	int8_t	i;
	char	*dest;

	color = mlx_get_color_value(image->win->mlx, color);
	i = 0;
	dest = image->addr + y * image->len + x * (image->bpp / 8);
	while (i < image->bpp / 8)
	{
		if (image->endian == 0)
			*(dest + i) = (char)(color & 0xFF);
		else
			*(dest + image->bpp / 8 - i - 1) = (char)(color & 0xFF);
		color = color >> 8;
		i++;
	}
}

void	destroy_image(t_image *image)
{
	mlx_destroy_image(image->win->mlx, image->img);
}
