/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:58:35 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/08 15:42:27by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = (char *)win->addr + (y * win->line_length + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_col(t_win *win, t_col col)
{
	while (col.start < col.size_max)
		my_pixel_put(win, col.x, col.start++, col.color);
}

static int	check_color(int *color)
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

t_img	*open_xpm(void *mlx_ptr, char *cardino)
{
	t_img	*img;

	img = wrmalloc(sizeof(t_img));
	img = &(t_img){.road = cardino, .h = 64, .w = 64};
	if (img->road)
	{
		img->img = mlx_xpm_file_to_image(mlx_ptr, img->road,
				&img->w, &img->h);
		if (img->img)
		{
			img->addr = (int *) mlx_get_data_addr(img->img,
					&img->bytes, &img->sizeline, &img->endian);
			return (img);
		}
	}
	ft_err(5);
	return (img);
}

void	get_texture(t_g *g)
{
	g->tex.cardino[0] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[0].road);
	g->tex.cardino[1] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[1].road);
	g->tex.cardino[2] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[2].road);
	g->tex.cardino[3] = *open_xpm(g->win.mlx_ptr, g->tex.cardino[3].road);
	g->tex.sprite[0].road = ft_strdup("./textures/sprites/sonic1.xpm");
	g->tex.sprite[0] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[0].road);
	g->tex.sprite[1].road = ft_strdup("./textures/sprites/sonic2.xpm");
	g->tex.sprite[1] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[1].road);
	g->tex.sprite[2].road = ft_strdup("./textures/sprites/sonic3.xpm");
	g->tex.sprite[2] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[2].road);
	g->tex.sprite[3].road = ft_strdup("./textures/sprites/sonic4.xpm");
	g->tex.sprite[3] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[3].road);
	g->tex.sprite[4].road = ft_strdup("./textures/sprites/sonic5.xpm");
	g->tex.sprite[4] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[4].road);
	g->tex.sprite[5].road = ft_strdup("./textures/sprites/sonic6.xpm");
	g->tex.sprite[5] = *open_xpm(g->win.mlx_ptr, g->tex.sprite[5].road);
	g->tex.floor = check_color(g->tex.f);
	g->tex.ceiling = check_color(g->tex.c);
}
