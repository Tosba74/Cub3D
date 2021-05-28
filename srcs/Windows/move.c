/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:35:27 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/28 15:17:56 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mov_updown(t_g *g, int neg)
{
	float	xpos;
	float	ypos;

	xpos = g->player.x + (SPEED * neg) * g->player.dirX;
	ypos = g->player.y + (SPEED * neg) * g->player.dirY;
	if (!is_wall(*g, (int)xpos, (int)ypos))
	{
		g->player.x = xpos;
		g->player.y = ypos;
	}
}

void	mov_lateral(t_g *g, int neg)
{
	float	xpos;
	float	ypos;

	xpos = g->player.x + (SPEED * neg) * g->player.planeX;
	ypos = g->player.y + (SPEED * neg) * g->player.planeY;
	if (!is_wall(*g, (int)xpos, (int)ypos))
	{
		g->player.x = xpos;
		g->player.y = ypos;
	}
}

void	rot_view(t_g *g, int neg)
{
	float	dirX;
	float	dirY;
	float	planeX;

	dirX = g->player.dirX;
	dirY = g->player.dirY;
	g->player.dirX = dirX * cos(neg * SPEEDTURN) - dirY * sin(neg * SPEEDTURN);
	g->player.dirY = dirX * sin(neg * SPEEDTURN) + dirY * cos(neg * SPEEDTURN);
	planeX = g->player.planeX;
	g->player.planeX = planeX * cos(neg * SPEEDTURN)
		- g->player.planeY * sin(neg * SPEEDTURN);
	g->player.planeY = planeX * sin(neg * SPEEDTURN)
		+ g->player.planeY * cos(neg * SPEEDTURN);
}
