/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/12 01:02:35 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_ray *ray, t_map *map, char *line, int i)
{
	ray->camera = line[i];
	line[i] = '0';
	ray->posX = (float)i;
	ray->posY = (float)map->line;
	if (ray->camera == 'N')
	{
		ray->dirY = -1;
		ray->planeX = 0.66;
	}
	else if (ray->camera == 'S')
	{
		ray->dirY = 1;
		ray->planeX = -0.66;
	}
	else if (ray->camera == 'E')
	{
		ray->dirX = 1;
		ray->planeY = 0.66;
	}
	else if (ray->camera == 'W')
	{
		ray->dirX = -1;
		ray->planeY = -0.66;
	}
	map->nb_player++;
}

static void	init_struct(t_g *g)
{
	int		i;

	g->win.mlx_ptr = mlx_init();
	g->lst = NULL;
	g->tex = (t_texture){.text_width = 64, .text_height = 64};
	g->tex.wall = (t_wall){};
	i = -1;
	while (++i < 4)
		g->tex.cardino[i] = (t_img){};
	i = -1;
	while (++i < 2)
		g->tex.sprite[i] = (t_img){};
}

void	ft_init_global(t_g *global)
{
	t_map		map;
	t_win		win;
	t_ray		ray;
	t_texture	tex;
	t_sprite	sprite;

	map = (t_map){};
	win = (t_win){};
	ray = (t_ray){};
	tex = (t_texture){};
	sprite = (t_sprite){};
	global->time = 0;
	global->map = map;
	global->win = win;
	global->ray = ray;
	global->tex = tex;
	global->sprite = sprite;
	init_struct(global);
}
