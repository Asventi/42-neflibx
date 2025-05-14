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

void	draw_box_shadow(t_guielem *e, t_image *img);
void	draw_inner_shadow(t_guielem *e, t_image *img);

#endif
