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
/*
static void cmpbytes(void)
{
	ft_putnbr(MOV_RIGHT&MOV_LEFT);
	ft_putstr("=>");
	ft_putbytes(MOV_RIGHT&MOV_LEFT);
	ft_putchar('\n');
	// ft_putnbr(MOV_A|MOV_D);
	// ft_putstr("=>");
	// ft_putbytes(MOV_A|MOV_D);
	// ft_putchar('\n');
	ft_putnbr(MOV_UP&MOV_DOWN);
	ft_putstr("=>");
	ft_putbytes(MOV_UP&MOV_DOWN);
	ft_putchar('\n');
	// ft_putnbr(MOV_W|MOV_S);
	// ft_putstr("=>");
	// ft_putbytes(MOV_W|MOV_S);
	// ft_putchar('\n');
}
*/

void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
	// ft_putstr("FINISH !!!\n");
	// wrdestroy();
	// exit(1);
}

// static void	clear_window(t_g *g)
// {
// 	int x;
// 	int y;
// 	x = -1;
// 	y = -1;
// 	while(++y < g->win.h)
// 	{
// 		x = -1;
// 		while (++x < g->win.w)
// 			my_pixel_put(g, x, y, 0x00000000);
// 	}
// }

static int	update(void *param)
{
	t_g *g = param;

	// clear_window(g);
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	move(g);
	minimap(g);
	mlx_put_image_to_window(g->win.mlx_ptr, g->win.win_ptr, g->win.img, g->win.w, g->win.h);
	return (0);
}

static void	proc_win(t_g *g)
{
	g->win.mlx_ptr = mlx_init();
	g->win.win_ptr = mlx_new_window(g->win.mlx_ptr, g->win.w, g->win.h, "42");
	get_texture(g);
	g->win.img = mlx_new_image(g->win.mlx_ptr, g->win.w ,g->win.h);
	g->win.addr = (int *)mlx_get_data_addr(g->win.img, &(g->win.bpp), &(g->win.line_length), &(g->win.endian));
	// int ret = mlx_get_screen_size(g->win.mlx_ptr, &(g->data.w), &(g->data.h));
	// printf("ret => %d\n",ret);
	mlx_do_key_autorepeatoff(g->win.mlx_ptr);
	mlx_loop_hook(g->win.mlx_ptr, update, g);
	mlx_hook(g->win.win_ptr, KeyPress, KeyPressMask, deal_key, g);
	mlx_hook(g->win.win_ptr, KeyRelease, KeyReleaseMask, death_key, g);
	// update(g);
	mlx_loop(g->win.mlx_ptr);
}

void	new_win(t_g *tg)
{
	proc_win(tg);
}
