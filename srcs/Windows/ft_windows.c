/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:33:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/12 18:54:34 by bmangin          ###   ########lyon.fr   */
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
	int			x;
	int			start;
	int			stop;
	int			size;
	t_col			*col;

	x = -1;
	// printf("\033[H\033[2J");
	// printf("img = %d\n", g->tex.cardino[0].addr[64]);
	while (++x < g->win.w)
	{
		size = (int)(g->win.h / ft_dda(g, x));
		start = g->win.h / 2 - size / 2;
		if (start < 0)
			start = 0;
		stop = g->win.h / 2 + size / 2;
		if (stop > g->win.h)
			stop = g->win.h;
		col = &(t_col){x, 0, start, g->tex.ceiling};
		draw_col(&g->win, *col);
		if (g->ray.side == 1)
		{
			col = &(t_col){x, start, stop, (0x00FFFF00 >> 1) & 8355711};
			draw_wall(g, x, *col);
			// draw_col(&g->win, *col);
		}
		else
		{
			col = &(t_col){x, start, stop, (0x00FFFF00 >> 1) & 8355711};
			draw_wall(g, x, *col);
			// draw_col(&g->win, *col);
		}
		col = &(t_col){x, stop, g->win.h, g->tex.floor};
		draw_col(&g->win, *col);
	}
}

static int	update(void *param)
{
	t_g	*g;

	g = param;
	// mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	clear_window(g);
	move(g);
	draw_screen(g);
	minimap(g);
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, 0, 0);
	mlx_do_sync(g->win.mlx_ptr);
	return (0);
}

static void	proc_win(t_g *g)
{
	g->win.mlx_ptr = mlx_init();
	mlx_get_screen_size(g->win.mlx_ptr, &g->win.w, &g->win.h);
	if (X_RES < g->win.w)
		g->win.w = X_RES;
	if (Y_RES < g->win.h)
		g->win.h = Y_RES;
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->win.w, g->win.h,
			"Cub3d");
	g->win.img = mlx_new_image(g->win.mlx_ptr, g->win.w, g->win.h);
	g->win.addr = (int *)mlx_get_data_addr(g->win.img, &(g->win.bpp),
			&(g->win.line_length), &(g->win.endian));
}

void	new_win(t_g *g)
{
	proc_win(g);
	get_texture(g);
	mlx_do_key_autorepeatoff(g->win.mlx_ptr);
	mlx_hook(g->win.win_ptr, 02, KeyPressMask, key_deal, g);
	mlx_hook(g->win.win_ptr, 03, KeyReleaseMask, key_death, g);
	mlx_loop_hook(g->win.mlx_ptr, update, g);
	mlx_loop(g->win.mlx_ptr);
}
