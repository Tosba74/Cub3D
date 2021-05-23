/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/23 17:41:45 by bmangin          ###   ########lyon.fr   */
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
