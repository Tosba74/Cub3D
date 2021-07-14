/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:28:05 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/14 10:40:21 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_carre(t_g *g, int x, int y, int color)
{
	int	w;
	int	h;

	h = -1;
	while (++h != 10)
	{
		w = -1;
		while (++w != 10)
		{
			if (w == 0 || w == 9 || h == 0 || h == 9)
				my_pixel_put(&g->win, x + w, y + h, 900000);
			else
				my_pixel_put(&g->win, x + w, y + h, color);
		}
	}
}

static void	print_carrev(t_g *g, int x, int y, int color)
{
	int	w;
	int	h;

	h = -1;
	while (++h != 10)
	{
		w = -1;
		while (++w != 10)
			if (w == 0 || w == 9 || h == 0 || h == 9)
				my_pixel_put(&g->win, x + w, y + h, color);
	}
}

static void	print_player(t_g *g, int x, int y, int color)
{
	int	w;
	int	h;

	h = -1;
	while (++h != 6)
	{
		w = -1;
		while (++w != 6)
			my_pixel_put(&g->win, x + w + 5, y + h + 5, color);
	}
}

int	minimap(t_g *g)
{
	int	x;
	int	i;
	int	t;
	int	y;

	i = -1;
	t = -1;
	y = 10;
	while (g->map.map[++t])
	{
		i = -1;
		x = 10;
		while (g->map.map[t][++i])
		{
			if (g->map.map[t][i] == '1')
				print_carre(g, x, y, 5197647);
			else if (g->map.map[t][i] == '0')
				print_carrev(g, x, y, 16514295);
			x += 10;
		}
		y += 10;
		print_player(g, (g->ray.posX * 10) + 2,
			(g->ray.posY * 10) + 2, 16066342);
	}
	return (0);
}
