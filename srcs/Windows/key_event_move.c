/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/25 13:35:21 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int			key_deal(int key, void *param)
{
	t_g	*g;
	
	g = param;
	if (key == KEY_ESC)
		close_window(g);	
	else if (key == KEY_UP)
		g->win.input ^= MOV_UP;
	else if (key == KEY_DOWN)
		g->win.input ^= MOV_DOWN;
	else if (key == KEY_LEFT)
		g->win.input ^= MOV_LEFT;
	else if (key == KEY_RIGHT)
		g->win.input ^= MOV_RIGHT;
	else if (key == KEY_Q)
		g->win.input ^= TURN_LEFT;
	else if (key == KEY_E)
		g->win.input ^= TURN_RIGHT;
	else
		return (0);
	return (1);
}

int			key_death(int key, void *param)
{
	t_g	*g;

	g = param;
	if (key == KEY_ESC)
		close_window(g);	
	else if (key == KEY_UP)
		g->win.input &= MOV_UP;
	else if (key == KEY_DOWN)
		g->win.input &= MOV_DOWN;
	else if (key == KEY_LEFT)
		g->win.input &= MOV_LEFT;
	else if (key == KEY_RIGHT)
		g->win.input &= MOV_RIGHT;
	else if (key == KEY_Q)
		g->win.input &= TURN_LEFT;
	else if (key == KEY_E)
		g->win.input &= TURN_RIGHT;
	else
		return (0);
	return (1);
}

void    move(t_g *g)
{
	char mov;
	char movx;
	char movy;
	char rot;

	mov = g->win.input;
	movx = mov & (MOV_LEFT | MOV_RIGHT);
	movy = mov & (MOV_DOWN | MOV_UP);
	rot = mov & (TURN_LEFT | TURN_RIGHT);
	if (movx == MOV_RIGHT)
		mov_updown(g, 1);
	else if (movx == MOV_LEFT)
		mov_updown(g, -1);
	if (movy == MOV_DOWN)
		mov_updown(g, 1);
	else if (movy == MOV_UP)
		mov_updown(g, -1);
	if (rot == TURN_RIGHT)
		rot_view(g, 1);
	else if (rot == TURN_LEFT)
		rot_view(g, -1);
}
