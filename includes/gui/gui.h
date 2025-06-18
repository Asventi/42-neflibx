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

# define GUI_EL_COLOR 0x414b50
# define GUI_FOCUS_COLOR 0x495156
# define BACK_COLOR 0x2e383c
// # define BACK_COLOR 0xFF
# define CONTAINER_COLOR 0x374145
# define SHADOW_COLOR 0x1e2326
# define TXT_COLOR 0xd3c6aa
# define RED_TXT 0xe67e80
# define GREEN_TXT 0xa7c080

# define SHADOW_MULTIPLIER 0.005f
# define AA_MULTIPLIER 0.005f

# define INPUT_MARGIN 0.05f
# define LABEL_SPACING 6

# include <stdint.h>
# include <stdbool.h>

# include "events.h"
# include "image.h"

typedef enum e_guitype
{
	NONE,
	BUTTON,
	TXT_INPUT,
	CONTAINER
}	t_guitype;

// Base struct for all GUI elements providing callback and parameters.
typedef struct s_guielem
{
	t_guitype			type;
	t_image				*img;
	char				*id;
	uint32_t			uid;
	t_callback			cb;
	int32_t				x;
	int32_t				y;
	int32_t				z;
	int32_t				w;
	int32_t				h;
	uint32_t			color;
	uint8_t				opacity;
	int32_t				cursor;
	bool				focus;
	bool				hover;
	bool				hide;
	char				*txt;
	float				scroll;
	int32_t				size;
	char				*label;
	struct s_guielem	*container;
	struct s_guielem	*sub_els;
}	t_guielem;

void		gui_render(t_image *img);
int			compare_z(void *a, void *b);
void		handle_shift_press(int keycode, void *p);
void		handle_shift_release(int keycode, void *p);
void		unfocus_all(t_window const *win);
void		unfocus(t_guielem *el);
void		unhover(t_guielem *el);

t_guielem	*get_by_label(t_window const *win, const char *str);
t_guielem	*get_by_pos(t_window const *win, int32_t x, int32_t y,
	void (*not_found_cb)(t_guielem *));
t_guielem	*get_by_id(t_window const *win, const char *str);
t_guielem	*get_focused_el(t_window const *win);

#endif
