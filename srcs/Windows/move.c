/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:35:27 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/08 15:35:35 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mov_updown(t_g *g, int neg)
{
	float	xpos;
	float	ypos;

	xpos = g->ray.posX + (SPEED * neg) * g->ray.dirX;
	ypos = g->ray.posY + (SPEED * neg) * g->ray.dirY;
	if (!is_wall(*g, (int)xpos, (int)g->ray.posY))
		g->ray.posX = xpos;
	if (!is_wall(*g, (int)g->ray.posX, (int)ypos))
		g->ray.posY = ypos;
}

static void	mov_lateral(t_g *g, int neg)
{
	float	xpos;
	float	ypos;

	xpos = g->ray.posX + (SPEED * neg) * g->ray.planeX;
	ypos = g->ray.posY + (SPEED * neg) * g->ray.planeY;
	if (!is_wall(*g, (int)xpos, (int)g->ray.posY))
		g->ray.posX = xpos;
	if (!is_wall(*g, (int)g->ray.posX, (int)ypos))
		g->ray.posY = ypos;
}

static void	rot_view(t_g *g, int neg)
{
	float	dirX;
	float	dirY;
	float	planeX;

	dirX = g->ray.dirX;
	dirY = g->ray.dirY;
	planeX = g->ray.planeX;
	g->ray.dirX = dirX * cos(neg * SPEEDTURN)
		- dirY * sin(neg * SPEEDTURN);
	g->ray.dirY = dirX * sin(neg * SPEEDTURN)
		+ dirY * cos(neg * SPEEDTURN);
	g->ray.planeX = planeX * cos(neg * SPEEDTURN)
		- g->ray.planeY * sin(neg * SPEEDTURN);
	g->ray.planeY = planeX * sin(neg * SPEEDTURN)
		+ g->ray.planeY * cos(neg * SPEEDTURN);
}

void	move(t_g *g)
{
	char	mov;
	char	movx;
	char	movy;
	char	rot;

	mov = g->win.keypress;
	movx = mov & (MOV_LEFT | MOV_RIGHT);
	movy = mov & (MOV_DOWN | MOV_UP);
	rot = mov & (TURN_LEFT | TURN_RIGHT);
	if (movx == MOV_RIGHT)
		mov_lateral(g, 1);
	else if (movx == MOV_LEFT)
		mov_lateral(g, -1);
	if (movy == MOV_DOWN)
		mov_updown(g, -1);
	else if (movy == MOV_UP)
		mov_updown(g, 1);
	if (rot == TURN_RIGHT)
		rot_view(g, 1);
	else if (rot == TURN_LEFT)
		rot_view(g, -1);
}
