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
# define INPUT_COLOR 0xdfe4ed

# include <stdint.h>
# include <stdbool.h>

# include "events.h"
# include "image.h"

typedef enum e_guiid
{
	BUTTON,
	TXT_INPUT
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
	int32_t		cursor;
	bool		active;
	bool		shadow;
	char		*txt;
	int32_t		size;
	char		*label;
}	t_guielem;

void	gui_render(t_image *img);
void	handle_shift_press(int keycode, void *p);
void	handle_shift_release(int keycode, void *p);

void	draw_button(t_guielem *btn, t_image *img);
void	create_button(t_image *img, t_guielem *btn, t_generic_cb cb, void *p);

void	gui_btnrelease(int keycode, int x, int y, void *p);
void	gui_btnpress(int keycode, int x, int y, void *p);
void	gui_keypress(int keycode, void *p);

void	elem_btn_press(t_guielem *btn, int x, int y);
void	elem_btn_release(t_guielem *btn, int x, int y);

void	create_txt_input(t_image *img, t_guielem *input,
			t_txt_cb cb, void *p);
void	draw_txt_input(t_guielem *input, t_image *img);

void	elem_txt_key(t_guielem *input, int keycode);
void	elem_txt_release(t_guielem *input, int x, int y);
void	elem_txt_press(t_guielem *input, int x, int y);

#endif
