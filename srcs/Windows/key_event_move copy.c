/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/18 15:00:14 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


// static void	putput(int key, t_g g)
// {
// 	printf("\n-------------\n");
// 	ft_putbytes(key);
// 	printf(" <== %d\n", key);
// 	// printf("| Pos X => %-12f Pos Y => %-14f |\n", g.player.x, g.player.y);
// 	ft_print_player(g);
// 	printf("------- ------\n");
// }

int     deal_key(int key, void *param)
{
	t_g *g = param;
	// putput(key, *g);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->mov.mov_left = 1;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->mov.mov_right = 1;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->mov.mov_up = 1;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->mov.mov_down = 1;
	}
	else if (key == KEY_Q)
	{
		g->mov.rot_left = 1;
	}
	else if (key == KEY_E)
	{
		g->mov.rot_right = 1;
	}
	return (0);
}


int	death_key(int key, void *param)
{
	t_g *g = param;
	// putput(key, *g);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->mov.mov_left = 0;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->mov.mov_right = 0;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->mov.mov_up = 0;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->mov.mov_down = 0;
	}
	else if (key == KEY_Q)
	{
		g->mov.rot_left = 0;
	}
	else if (key == KEY_E)
	{
		g->mov.rot_right = 0;
	}
	return (0);
}

void	move(t_g *g)
{
	if (g->mov.mov_up == 1) 
		mov_updown(g, -1);
	if (g->mov.mov_down == 1) 
		mov_updown(g, 1);
	if (g->mov.mov_right == 1)
		mov_lateral(g, 1);
	if (g->mov.mov_left == 1)
		mov_lateral(g, -1);
	if (g->mov.rot_right == 1)
		rot_view(g, 1);
	if (g->mov.rot_left == 1)
		rot_view(g, -1);
}
