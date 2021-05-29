/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/25 18:22:50y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_deal(int key, void *param)
{
	t_g	*g;

	g = param;
	if (key == KEY_ESC)
		close_window(g);
	else if (key == KEY_UP || key == KEY_W)
		g->win.keypress |= MOV_UP;
	else if (key == KEY_DOWN || key == KEY_S)
		g->win.keypress |= MOV_DOWN;
	else if (key == KEY_LEFT || key == KEY_A)
		g->win.keypress |= MOV_LEFT;
	else if (key == KEY_RIGHT || key == KEY_D)
		g->win.keypress |= MOV_RIGHT;
	else if (key == KEY_Q)
		g->win.keypress |= TURN_LEFT;
	else if (key == KEY_E)
		g->win.keypress |= TURN_RIGHT;
	return (0);
}

int	key_death(int key, void *param)
{
	t_g	*g;

	g = param;
	if (key == KEY_ESC)
		close_window(g);
	else if (key == KEY_UP || key == KEY_W)
		g->win.keypress ^= MOV_UP;
	else if (key == KEY_DOWN || key == KEY_S)
		g->win.keypress ^= MOV_DOWN;
	else if (key == KEY_LEFT || key == KEY_A)
		g->win.keypress ^= MOV_LEFT;
	else if (key == KEY_RIGHT || key == KEY_D)
		g->win.keypress ^= MOV_RIGHT;
	else if (key == KEY_Q)
		g->win.keypress ^= TURN_LEFT;
	else if (key == KEY_E)
		g->win.keypress ^= TURN_RIGHT;
	return (0);
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
