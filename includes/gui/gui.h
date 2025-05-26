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

# include "events.h"

typedef enum e_guiid
{
	BUTTON
}	t_guiid;

// Base struct for all GUI elements providing callback and parameters.
typedef struct s_guielem
{
	t_guiid		id;
	t_callback	cb;
	int32_t		x;
	int32_t		y;
	int32_t		w;
	int32_t		h;
	t_image		*img;
	uint32_t	color;
	uint8_t		opacity;
	bool		active;
	bool		shadow;
	char		*label;
}	t_guielem;

void	gui_render(t_image *img);

void	draw_button(t_guielem *btn, t_image *img);
void	create_button(t_image *img, t_guielem *btn, t_generic_cb cb, void *p);

void	gui_btnrelease(int keycode, int x, int y, void *p);
void	gui_btnpress(int keycode, int x, int y, void *p);

void	elem_btn_press(t_guielem *btn, int x, int y);
void	elem_btn_release(t_guielem *btn, int x, int y);

#endif
