/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:25:39 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/14 18:26:47 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_textr(t_g *g)
{
	if (g->ray.side == 0)
	{
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '1')
		{
			if (g->ray.posX > g->ray.mapX)
				g->tex.texNum = 3;
			else
				g->tex.texNum = 2;
		}
		g->tex.wallX = g->ray.posY + g->ray.perpWallDist * g->ray.rayDirY;
	}
	else
	{
		if (g->map.map[g->ray.mapY][g->ray.mapX] == '1')
		{
			if (g->ray.posY > g->ray.mapY)
				g->tex.texNum = 1;
			else
				g->tex.texNum = 0;
		}
		g->tex.wallX = g->ray.posX + g->ray.perpWallDist * g->ray.rayDirX;
	}
	// printf("%d\n", g->tex.texNum);
}

// GOOD
// void	draw_wall(t_g *g, int x, t_col col)
// {
// 	int	y;
// 	int	color;

// 	ft_init_textr(g);
// 	// g->tex.wall.stop = col.size_max;
// 	g->tex.wall.start = col.start;
// 	g->tex.wall.height = col.size_max - col.start;
// 	// printf("wallx = %f\n", g->tex.wallX);
// 	g->tex.wallX -= floor((g->tex.wallX));
// 	g->tex.texX = (int)(g->tex.wallX * (float)(g->tex.cardino[g->tex.texNum].w));
// 	if (g->ray.side == 0 && g->ray.rayDirX > 0)
// 		g->tex.texX = g->tex.cardino[g->tex.texNum].w - g->tex.texX - 1;
// 	if (g->ray.side == 1 && g->ray.rayDirY < 0)
// 		g->tex.texX = g->tex.cardino[g->tex.texNum].w - g->tex.texX - 1;
// 	g->tex.step = 1.0 * g->tex.cardino[g->tex.texNum].h / g->tex.wall.height;
// 	// printf("texh = %d, wallheight = %d\n", g->tex.cardino[g->tex.texNum].h, g->tex.wall.height);
// 	g->tex.texPos = (g->tex.wall.start - g->win.h / 2 + g->tex.wall.height / 2)
// 		* g->tex.step;
// 	y = g->tex.wall.start - 1;
// 	// if (y < 0)
// 	// 	y = 0;
// 	// if (col.size_max > g->win.h)
// 	// 	col.size_max = g->win.h;
// 	while (++y < col.size_max)
// 	{
// 		g->tex.texY = (int)(g->tex.texPos) & (g->tex.cardino[g->tex.texNum].h - 1);
// 		g->tex.texPos += g->tex.step;
// 		color = g->tex.cardino[g->tex.texNum].addr[g->tex.cardino[g->tex.texNum].h
// 			* g->tex.texY + g->tex.texX];
// 		if (g->ray.side == 1)
// 			color = (color >> 1) & 8355711;
// 		// printf("h = %d, texY = %d, texX = %d texNUM = %d\n", g->tex.cardino[g->tex.texNum].h, g->tex.texY, g->tex.texX, g->tex.texNum);
// 		// printf("color => r = %d, g = %d, b = %d\n", color / (256*256), (color % (256*256)) / 256, ((color % (256*256)) % 256));
// 		my_pixel_put(&g->win, x, y, color);
// 	}
// }
void	draw_wall(t_g *g, t_wall size, t_texture *t, int x)
{
	int	y;
	int	color;

	ft_init_textr(g);
	t->wallX -= floor((t->wallX));
	t->texX = (int)(t->wallX * (float)(t->texWidth));
	if (g->ray.side == 0 && g->ray.rayDirX > 0)
		t->texX = t->texWidth - t->texX - 1;
	if (g->ray.side == 1 && g->ray.rayDirY < 0)
		t->texX = t->texWidth - t->texX - 1;
	t->step = 1.0 * t->texHeight / size.height;
	t->texPos = (size.start - g->win.h / 2 + size.height / 2) * t->step;
	y = size.start - 1;
	while (++y < size.stop)
	{
		t->texY = (int)(t->texPos) & (t->texHeight - 1);
		t->texPos += t->step;
		color = t->cardino[t->texNum].addr[t->cardino[t->texNum].h
			* t->texY + t->texX];
		if (g->ray.side == 1)
			color = (color >> 1) & 8355711;
		my_pixel_put(&g->win, x, y, color);
	}
}
// void	draw_wall(t_g *g, int x, t_col size)
// {
// 	int	y;
// 	int	color;

// 	ft_init_textr(g);
// 	g->tex.wallX -= floor((g->tex.wallX));
// 	g->tex.texX = (int)(g->tex.wallX * (float)(g->tex.texWidth));
// 	if (g->ray.side == 0 && g->ray.rayDirX > 0)
// 		g->tex.texX = g->tex.texWidth - g->tex.texX - 1;
// 	if (g->ray.side == 1 && g->ray.rayDirY < 0)
// 		g->tex.texX = g->tex.texWidth - g->tex.texX - 1;
// 	g->tex.step = 1.0 * g->tex.texHeight / (size.size_max - size.size_max);
// 	g->tex.texPos = (size.start - g->win.h / 2 + (size.size_max - size.size_max) / 2) * g->tex.step;
// 	y = size.start - 1;
// 	while (++y < size.size_max)
// 	{
// 		g->tex.texY = (int)(g->tex.texPos) & (g->tex.texHeight - 1);
// 		g->tex.texPos += g->tex.step;
// 		color = g->tex.cardino[g->tex.texNum].addr[g->tex.cardino[g->tex.texNum].h
// 			* g->tex.texY + g->tex.texX];
// 		if (g->ray.side == 1)
// 			color = (color >> 1) & 8355711;
// 		my_pixel_put(&g->win, x, y, color);
// 	}
// }
// void	draw_screen(t_g *g)
// {
// 	int			x;
// 	t_col		col;

// 	x = -1;
// 	while (++x < g->win.w)
// 	{
// 		get_wall_size(x, g);
// 		col = (t_col){x, 0, g->tex.wall.start, g->tex.ceiling};
// 		draw_col(&g->win, col);
// 		draw_wall(g, x, col);
// 		col = (t_col){x, g->tex.wall.stop, g->win.h, g->tex.floor};
// 		draw_col(&g->win, col);
// 	}
// 	// ft_draw_sprite(g, &g->txtr->var, g->txtr);
// 	// ft_clear_lst(&g->lst_sprite);
// }


// void	draw_screen(t_g *game)
// {
// 	int			x_win;
// 	t_col		col;
// 	t_size_wall	size_wall;

// 	x_win = 0;
// 	while (x_win < game->data.rx)
// 	{
// 		size_wall = ft_get_wall_size(x_win, game);
// 		if (game->trip == 0)
// 		{
// 			col = (t_col){x_win, 0, size_wall.start, game->data.rgb_c};
// 			draw_col(col, game);
// 			draw_wall(game, size_wall, game->txtr, x_win);
// 			col = (t_col){x_win, size_wall.stop,
// 				game->data.ry, game->data.rgb_f};
// 			draw_col(col, game);
// 		}
// 		else
// 			draw_trip(x_win, game, size_wall);
// 		x_win++;
// 	}
// 	ft_draw_sprite(game, &game->txtr->var, game->txtr);
// 	ft_clear_lst(&game->lst_sprite);
// }