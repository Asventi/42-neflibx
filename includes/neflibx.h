/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neflibx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:36:06 by pjarnac           #+#    #+#             */
/*   Updated: 2024/12/20 20:36:06 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEFLIBX_H
# define NEFLIBX_H

# include "mlx.h"

typedef struct s_display t_display;

typedef struct s_window
{
	void	*win;
	t_display	*display;
	int		x;
	int		y;
}	t_window;

typedef struct s_display
{
	void		*mlx;
	t_window	**wins;
	int			wins_num;
	int			x;
	int			y;
}	t_display;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

// Display management
t_display	*init_display(void);
int			destroy_display(t_display *display);

// Windows management
t_window	*init_window(t_display *display, int x, int y, char *title);
int			destroy_window(t_window *window);
int			destroy_all_windows(t_display *display);

// Graphic operations
int			draw_line(t_window *window, t_point pt1, t_point pt2);

#endif
