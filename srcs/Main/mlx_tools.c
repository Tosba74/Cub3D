/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:58:35 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/28 19:14:26 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = (char *)win->addr + (y * win->line_length + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_window(t_g *g)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < g->win.h)
	{
		x = -1;
		while (++x < g->win.w)
			my_pixel_put(&g->win, x, y, 0x00000000);
	}
}

void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
}

void	draw_col(t_g *g, int x, int start, int stop, int color)
{
	while (start < stop)
	{
		my_pixel_put(&g->win, x, start, color);
		start++;
	}
}

t_img	open_xpm(t_g *g, char *cardino)
{
	t_img	img;
	int		ret;

	img = (t_img){};
	ret = iscardino(&(g->data), cardino, 2);
	if (0 <= ret && ret < 4)
	{
		img.road = g->data.cardino[1][ret];
		if (img.road)
		{
			img.img = mlx_xpm_file_to_image(g->win.mlx_ptr, img.road,
					&(g->win.bpp), &(g->win.bpp));
			if (img.img)
				return (img);
		}
	}
	ft_err(5);
	return (img);
}