/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:47:14 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/20 17:40:40y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img		open_xpm(t_g *g, char *cardino)
{
	t_img	img;
	int		ret;

	img = (t_img) {};
	ret = iscardino(&(g->data), cardino, 2);
	if (0 <= ret && ret < 4)
	{
		img.road = g->data.cardino[1][ret];
		if (img.road)
		{
			img.img = mlx_xpm_file_to_image(g->win.mlx_ptr, img.road, &(g->win.bpp), &(g->win.bpp));
			if (img.img)
				return (img);
		}
	}
	ft_err(5);
	return(img);
}

int		check_color(int *color)
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
	return(ft_get_color(color[0], color[1], color[2]));
}

void		get_texture(t_g *g)
{
	g->img_c.no = (open_xpm(g, "NO"));
	g->img_c.so = (open_xpm(g, "SO"));
	g->img_c.ea = (open_xpm(g, "EA"));
	g->img_c.we = (open_xpm(g, "WE"));
	g->img_c.floor = check_color(g->data.f);
	g->img_c.ceiling = check_color(g->data.c);
	ft_print_img(*g);
}
