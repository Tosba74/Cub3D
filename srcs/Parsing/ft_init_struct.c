/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:36:49 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/11 15:37:27 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_global(t_g *global)
{
	t_data		data;
	t_map		map;
	t_player	player;
	t_win		win;

	data = (t_data){.cardino[0][0] = "NO", .cardino[0][1] = "SO",
		.cardino[0][2] = "WE", .cardino[0][3] = "EA"};
	map = (t_map){};
	player = (t_player){};
	win = (t_win){.bpp = 6, .line_length = 12};
	global->data = data;
	global->map = map;
	global->player = player;
	global->win = win;
}
