/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:33:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/13 23:28:37by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// data->time = clock();
// 	data->frame_time = (float)(data->time - data->prev_time) / CLOCKS_PER_SEC;
// 	if (++data->frame_uni > 30)
// 	{
// 		printf("\rfps:%.2f", 1 / data->frame_time);
// 		fflush(stdout);
// 		data->frame_uni = 0;
// 	}
// 	data->prev_time = data->time;

void	get_wall_size(int x_win, t_g *g)
{
	g->tex.wall.height = (int)(g->win.h
			/ ft_dda(g, x_win));
	g->tex.wall.start = g->win.h / 2 - g->tex.wall.height / 2;
	if (g->tex.wall.start < 0)
		g->tex.wall.start = 0;
	g->tex.wall.stop = g->win.h / 2 + g->tex.wall.height / 2;
	if (g->tex.wall.stop >= g->win.h)
		g->tex.wall.stop = g->win.h;
}

void	draw_screen(t_g *g)
{
	int			x_win;
	t_col		col;

	x_win = 0;
	while (x_win < g->win.w)
	{
		get_wall_size(x_win, g);
		col = (t_col){x_win, 0, g->tex.wall.start, g->tex.ceiling};
		draw_col(&g->win, col);
		draw_wall(g, g->tex.wall, &g->tex, x_win);
		col = (t_col){x_win, g->tex.wall.stop, g->win.h, g->tex.floor};
		draw_col(&g->win, col);
		x_win++;
	}
	// draw_sprite(g);
	// clear_lst(&g->sprite.lst);
}
