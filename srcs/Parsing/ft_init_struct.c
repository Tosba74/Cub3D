/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/28 16:47:41 by bmangin          ###   ########lyon.fr   */
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

void	ft_init_player(t_player *player, t_map *map, int i)
{
	player->x = (float)i;
	player->y = (float)map->line;
	if (player->view == 'N')
	{
		player->dirY = -1;
		player->planeX = 0.66;
	}
	else if (player->view == 'S')
	{
		player->dirY = 1;
		player->planeX = -0.66;
	}
	else if (player->view == 'E')
	{
		player->dirX = 1;
		player->planeY = 0.66;
	}
	else if (player->view == 'W')
	{
		player->dirX = -1;
		player->planeY = -0.66;
	}
}

void	ft_init_global(t_g *global)
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_win		win;
	t_mov		mov;

	data = (t_data){.cardino[0][0] = "NO", .cardino[0][1] = "SO",
		.cardino[0][2] = "WE", .cardino[0][3] = "EA"};
	map = (t_map){};
	player = (t_player){};
	win = (t_win){};
	mov = (t_mov){};
	global->data = data;
	global->map = map;
	global->player = player;
	global->win = win;
	global->mov = mov;
	init_struct_img(global);
}
