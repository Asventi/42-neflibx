/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:58:29 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/12 16:58:29 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdint.h>

# include "image.h"

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
	int32_t	color;
}	t_point;

void	draw_line(t_point pt1, t_point pt2, t_image *img);

#endif
