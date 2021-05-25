/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:35:27 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/25 18:36:36 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mov_updown(t_g *g, int neg)
{
	float	xpos;
	float	ypos;

	xpos = g->player.x + (SPEED * neg);
	ypos = g->player.y + (SPEED * neg);
	if (!is_wall(*g, (int)xpos, (int)ypos))
	{
		g->player.x = xpos;
		g->player.y = ypos;
	}
}

/*
void	mov_updown(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)g->player.x, (int)(g->player.y + mov)))
		g->player.y += (SPEED * neg);
}

void	mov_lateral(t_g *g, int neg)
{
	int		mov;

	mov = SPEED * neg;
	if (!is_wall(*g, (int)(g->player.x + mov), (int)g->player.y))
		g->player.x += (SPEED * neg);
}
*/

void	rot_view(t_g *g, int neg)
{
	float	dirX;
	float	dirY;

	dirX = g->player.dirX;
	dirY = g->player.dirY;
	g->player.dirX = dirX * cos(neg * SPEEDTURN) - dirY * sin(neg * SPEEDTURN);
	g->player.dirY = dirX * sin(neg * SPEEDTURN) + dirY * cos(neg * SPEEDTURN);
	g->player.planeX = g->player.dirY;
	g->player.planeY = -1 * g->player.dirX;
}
