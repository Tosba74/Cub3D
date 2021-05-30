/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/29 22:49:32 by bmangin          ###   ########lyon.fr   */
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
	g->img_c.no = (open_xpm(g, "NO"));
	g->img_c.so = (open_xpm(g, "SO"));
	g->img_c.ea = (open_xpm(g, "EA"));
	g->img_c.we = (open_xpm(g, "WE"));
	g->img_c.floor = check_color(g->data.f);
	g->img_c.ceiling = check_color(g->data.c);
	ft_print_img(*g);
}

void	init_struct_img(t_g *g)
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;

	g->img_c = (t_texture){};
	no = (t_img){};
	so = (t_img){};
	ea = (t_img){};
	we = (t_img){};
	g->img_c.no = no;
	g->img_c.so = so;
	g->img_c.ea = ea;
	g->img_c.we = we;
}

void	ft_init_player(t_ray *ray, t_map *map, int i)
{
	ray->posX = (float)i;
	ray->posY = (float)map->line;
	if (ray->view == 'N')
	{
		ray->dirY = -1;
		ray->planeX = 0.66;
	}
	else if (ray->view == 'S')
	{
		ray->dirY = 1;
		ray->planeX = -0.66;
	}
	else if (ray->view == 'E')
	{
		ray->dirX = 1;
		ray->planeY = 0.66;
	}
	else if (ray->view == 'W')
	{
		ray->dirX = -1;
		ray->planeY = -0.66;
	}
}

void	ft_init_global(t_g *global)
{
	t_data		data;
	t_map		map;
	t_win		win;
	t_ray		ray;

	data = (t_data){.cardino[0][0] = "NO", .cardino[0][1] = "SO",
		.cardino[0][2] = "WE", .cardino[0][3] = "EA"};
	map = (t_map){};
	win = (t_win){};
	ray = (t_ray){};
	global->data = data;
	global->map = map;
	global->win = win;
	global->ray = ray;
	init_struct_img(global);
}
