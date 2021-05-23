/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:33:03 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/07 18:49:44bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// static void	texture_to_win(t_g *g)
// {
// 	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->img_c.no.img, 450 ,20);
// 	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->img_c.so.img, 520 ,20);
// 	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->img_c.ea.img, 600 ,20);
// 	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->img_c.we.img, 680 ,20);
// }

void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
	// ft_putstr("FINISH !!!\n");
	// wrdestroy();
	// exit(1);
}

void	draw_screen(t_g *g)
{
	int			x_win;
	int			start;
	int			stop;
	int			size;
	t_rc_var	var;

	x_win = 0;
	size = (int)(g->win.h / ft_dda(g, x_win, &var));;
	start = g->win.h / 2 - size / 2;
	stop = g->win.h / 2 + size / 2;
	while (x_win < g->win.w)
	{
		draw_col(g, x_win, 0, start, g->img_c.ceiling);
		draw_col(g, x_win, start, stop, 0x00FFFF00);
		draw_col(g, x_win, stop, g->win.h, g->img_c.floor);
		x_win++;
	}
	
}

static int	update(void *param)
{
	t_g *g = param;

	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	move(g);
	draw_screen(g);
	minimap(g);
	// texture_to_win(g);
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, 0, 0);
	mlx_do_sync(g->win.mlx_ptr);
	return (0);
}

static void	mlx_proc_win(t_g *g)
{
	int xmax;
	int ymax;

	xmax = 0;
	ymax = 0;
	mlx_get_screen_size(g->win.mlx_ptr, &xmax, &ymax);
	printf("xmax => %d | ymax = =%d\n", xmax, ymax);
	if (g->data.w > xmax)
		g->win.w = xmax;
	if (g->data.h > ymax)
		g->win.h = ymax;
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->win.w, g->win.h, "Cub3d");
	g->win.img = mlx_new_image(g->win.mlx_ptr, g->win.w ,g->win.h);
	g->win.addr = (int*)mlx_get_data_addr(g->win.img, &(g->win.bpp), &(g->win.line_length), &(g->win.endian));
	// get_texture(g);
	// update(g);
}

void	new_win(t_g *g)
{
	g->win.mlx_ptr = mlx_init();
	mlx_proc_win(g);
	mlx_do_key_autorepeatoff(g->win.mlx_ptr);
	mlx_hook(g->win.win_ptr, 02, KeyPressMask, deal_key, g);
	mlx_hook(g->win.win_ptr, 03, KeyReleaseMask, death_key, g);
	mlx_loop_hook(g->win.mlx_ptr, update, g);
	mlx_loop(g->win.mlx_ptr);
}
