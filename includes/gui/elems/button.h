/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:47:04 by pjarnac           #+#    #+#             */
/*   Updated: 2025/06/11 13:47:04 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H

# include "gui/gui.h"

t_guielem	*create_button(t_image *img, t_generic_cb cb, void *p);
void		draw_button(t_guielem *el);

void		elem_btn_press(t_guielem *btn, int x, int y);
void		elem_btn_release(t_guielem *btn, int x, int y);

#endif
