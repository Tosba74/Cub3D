/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:52:59 by bmangin           #+#    #+#             */
/*   Updated: 2021/07/12 00:15:48 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(-1);
	return (0);
}

int	key_deal(int key, void *param)
{
	t_g	*g;

	g = param;
	if (key == KEY_ESC)
		close_window(g);
	else if (key == KEY_UP || key == KEY_W)
		g->win.keypress |= MOV_UP;
	else if (key == KEY_DOWN || key == KEY_S)
		g->win.keypress |= MOV_DOWN;
	else if (key == KEY_A)
		g->win.keypress |= MOV_LEFT;
	else if (key == KEY_D)
		g->win.keypress |= MOV_RIGHT;
	else if (key == KEY_Q || key == KEY_LEFT)
		g->win.keypress |= TURN_LEFT;
	else if (key == KEY_E || key == KEY_RIGHT)
		g->win.keypress |= TURN_RIGHT;
	return (0);
}

int	key_death(int key, void *param)
{
	t_g	*g;

	g = param;
	if (key == KEY_ESC)
		close_window(g);
	else if (key == KEY_UP || key == KEY_W)
		g->win.keypress ^= MOV_UP;
	else if (key == KEY_DOWN || key == KEY_S)
		g->win.keypress ^= MOV_DOWN;
	else if (key == KEY_A)
		g->win.keypress ^= MOV_LEFT;
	else if (key == KEY_D)
		g->win.keypress ^= MOV_RIGHT;
	else if (key == KEY_Q || key == KEY_LEFT)
		g->win.keypress ^= TURN_LEFT;
	else if (key == KEY_E || key == KEY_RIGHT)
		g->win.keypress ^= TURN_RIGHT;
	return (0);
}

static void	clear_window(t_g *g)
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

int	update(void *param)
{
	t_g	*g;

	g = param;
	clear_window(g);
	move(g);
	draw_screen(g);
	minimap(g);
	g->time++;
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, 0, 0);
	mlx_do_sync(g->win.mlx_ptr);
	return (0);
}
