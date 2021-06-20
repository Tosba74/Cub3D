/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:25:39 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/19 18:24:20 by bmangin          ###   ########lyon.fr   */
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
}

void	draw_wall(t_g *g, t_wall size, t_texture *t, int x)
{
	int	y;
	int	color;

	ft_init_texture(g);
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
