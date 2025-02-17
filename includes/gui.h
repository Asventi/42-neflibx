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

# define BUTTON 0

# include <stdint.h>

# include "window.h"
# include "image.h"

// Base struct for all GUI elements providing callback and parameters.
typedef struct s_guielem
{
	uint8_t	id;
	void	(*callback)(void *p);
	void	*cb_param;
	int32_t	x;
	int32_t y;
}	t_guielem;

typedef struct s_button
{
	t_guielem	base;
	uint32_t	color;
	uint8_t		opacity;
	int32_t		w;
	int32_t		h;
	char		*text;
}	t_button;

typedef struct s_box
{

}	t_box;

void	show_button(t_window *window, t_button *button);

#endif
