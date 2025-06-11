/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:47:34 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 13:47:34 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TXT_INPUT_H
# define TXT_INPUT_H

# include "gui/gui.h"

t_guielem	*create_txt_input(t_image *img, t_txt_cb cb, void *p);
void		draw_txt_input(t_guielem *el);

void		elem_txt_key(t_guielem *input, int keycode);
void		elem_txt_release(t_guielem *input, int x, int y);
void		elem_txt_press(t_guielem *input, int x, int y);

#endif
