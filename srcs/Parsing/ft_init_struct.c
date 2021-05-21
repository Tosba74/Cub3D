/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/20 16:48:02 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct_img(t_texture *img_c)
{
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
	
	no = (t_img) {};
	so = (t_img) {};
	ea = (t_img) {};
	we = (t_img) {};
	img_c->no = no;	
	img_c->so = so;
	img_c->ea = ea;	
	img_c->we = we;
}

void	ft_init_global(t_g *global)
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_win		win;
	t_mov		mov;
	t_texture	img_c;

	data = (t_data){.cardino[0][0] = "NO", .cardino[0][1] = "SO",
		.cardino[0][2] = "WE", .cardino[0][3] = "EA"};
	map = (t_map){};
	player = (t_player){};
	win = (t_win){.bpp = 6, .line_length = 12};
	mov = (t_mov) {};
	// img_c = (t_texture) {};
	init_struct_img(&img_c);	
	global->data = data;
	global->map = map;
	global->player = player;
	global->win = win;
	global->mov = mov;
	global->img_c = img_c;
}
