/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:42:51 by pjarnac           #+#    #+#             */
/*   Updated: 2025/02/13 10:42:51 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	nef_bzero(void *s, size_t n)
{
	while (n)
	{
		((uint8_t *)s)[n - 1] = 0;
		n--;
	}
}
