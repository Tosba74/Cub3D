/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:35:27 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/21 17:26:46 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mov_updown(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)(g->player.x), (int)(g->player.y + mov)))
		g->player.y += (SPEED * neg);
}

void	mov_lateral(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)(g->player.x + mov), (int)(g->player.y)))
		g->player.x += (SPEED * neg);
}

void	rot_view(t_g *g, int neg)
{
	// int		neg;
	g->player.dir++;
	neg = 0;
	// if (g->mov.rot_left = 1)
	// 	neg = -1;
	// else if (g->mov.rot_right = 1)
	// 	neg = 1;
	// g->player.x += (SPEED * neg);
}
