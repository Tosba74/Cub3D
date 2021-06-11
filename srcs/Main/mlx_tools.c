/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:58:35 by bmangin           #+#    #+#             */
/*   Updated: 2021/06/08 14:06:44by bmangin          ###   ########lyon.fr   */
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

t_img	*open_xpm(void *mlx_ptr, char *cardino)
{
	t_img	*img;

	(void)mlx_ptr;
	img = &(t_img){.road = cardino, .h = 64, .w = 64};
	if (img->road)
	{
		img->img = mlx_xpm_file_to_image(mlx_ptr, img->road,
				&img->w, &img->h);
		if (img->img)
		{
			img->addr = (int *)mlx_get_data_addr(img->img, &img->bytes,
				&img->sizeline, &img->endian);
			return (img);
		}
	}
	ft_err(5);
	return (img);
}
