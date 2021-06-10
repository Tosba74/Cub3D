/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/10 17:58:02 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(int *color)
{
	int		i;

	i = -1;
	while (color[++i] && i < 3)
	{
		if (0 > color[i] || color[i] > 255)
			ft_err(6);
	}
	if (i != 3)
		ft_err(6);
	return (ft_get_color(color[0], color[1], color[2]));
}

void	get_texture(t_g *g)
{
	g->tex.cardino[0] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[0].road);
	g->tex.cardino[1] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[1].road);
	g->tex.cardino[2] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[2].road);
	g->tex.cardino[3] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[3].road);
	g->tex.floor = check_color(g->tex.f);
	g->tex.ceiling = check_color(g->tex.c);
	ft_print_img(*g);
}

void	ft_init_player(t_ray *ray, t_map *map, int i)
{
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
}

void	init_struct_img(t_g *g)
{
	int		i;
	
	i = -1;
	g->tex = (t_texture){};
	g->tex.wall = (t_wall){};
	while (++i < 4)
		g->tex.cardino[i] = (t_img){};
	
}

void	ft_init_global(t_g *global)
{
	t_map		map;
	t_win		win;
	t_ray		ray;
	t_sprite	sprite;
	

	map = (t_map){};
	win = (t_win){};
	ray = (t_ray){};
	sprite = (t_sprite){};
	global->map = map;
	global->win = win;
	global->ray = ray;
	global->sprite = sprite;
	init_struct_img(global);
}
