/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:43 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/14 18:39:43 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# define GUI_COLOR 0xbecde6

# include <stdint.h>
# include <stdbool.h>

# include "image.h"

typedef enum e_guiid
{
	BUTTON
}	t_guiid;

// Base struct for all GUI elements providing callback and parameters.
typedef struct s_guielem
{
	t_guiid		id;
	t_callback	cb;
	t_image		*img;
	int32_t		x;
	int32_t		y;
	int32_t		w;
	int32_t		h;
	uint32_t	color;
	uint8_t		opacity;
}	t_guielem;

typedef struct s_button
{
	t_guielem	b;
	bool		shadow;
	char		*label;
}	t_button;

typedef struct s_box
{

}	t_box;

void	draw_button(t_button *btn);
void	create_button(t_button *btn, t_image *img,
			t_generic_cb cb, void *p);

#endif
