/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:19:42 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/18 18:32:46 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void raycast(t_g *g)
{
	t_vector	vector;
	float		pos_x;
	float		pos_y;

	vector = (t_vector) {.x = -1};
	pos_x = g->player.x;
	pos_y = g->player.y;
}