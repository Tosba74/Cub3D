/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/21 18:24:35 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_player *player)
{
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
