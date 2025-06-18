/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:24:13 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/20 14:24:13 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_DRAW_H
# define GUI_DRAW_H

# include "gui.h"

void	draw_border(t_guielem *e, uint32_t color, int32_t size, int32_t shift);
void	draw_gui_aa(t_guielem *e, t_image *img);
void	draw_gui_active(t_guielem *e, t_image *img);
void	draw_el_box(t_guielem *el, t_image *img);
int32_t	get_c_to_write(t_guielem *el);
int32_t	get_center_h(t_guielem *el);
int32_t	get_center_w(t_guielem *el, char *str);

#endif
