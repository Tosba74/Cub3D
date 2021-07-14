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

static void	ft_init_texture(t_g *g)
{
	if (g->ray.side == 0)
	{
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '1')
		{
			if (g->ray.posX > g->ray.mapX)
				g->tex.text_num = 3;
			else
				g->tex.text_num = 2;
		}
		g->tex.wallX = g->ray.posY + g->ray.perpWallDist * g->ray.rayDirY;
	}
	else
	{
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '1')
		{
			if (g->ray.posY > g->ray.mapY)
				g->tex.text_num = 1;
			else
				g->tex.text_num = 0;
		}
		g->tex.wallX = g->ray.posX + g->ray.perpWallDist * g->ray.rayDirX;
	}
}

static void	draw_wall(t_g *g, t_wall size, t_texture *t, int x)
{
	int	y;
	int	color;

	ft_init_texture(g);
	t->wallX -= floor((t->wallX));
	t->text_x = (int)(t->wallX * (float)(t->text_width));
	if (g->ray.side == 0 && g->ray.rayDirX > 0)
		t->text_x = t->text_width - t->text_x - 1;
	if (g->ray.side == 1 && g->ray.rayDirY < 0)
		t->text_x = t->text_width - t->text_x - 1;
	t->step = 1.0 * t->text_height / size.height;
	t->text_pos = (size.start - g->win.h / 2 + size.height / 2) * t->step;
	y = size.start - 1;
	while (++y < size.stop)
	{
		t->text_y = (int)(t->text_pos) & (t->text_height - 1);
		t->text_pos += t->step;
		color = t->cardino[t->text_num].addr[t->cardino[t->text_num].h
			* t->text_y + t->text_x];
		if (g->ray.side == 1)
			color = (color >> 1) & 8355711;
		my_pixel_put(&g->win, x, y, color);
	}
}

static void	get_wall_size(int x_win, t_g *g)
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
	draw_sprite(g, &g->ray, &g->tex);
	clear_lst(&g->lst);
}
