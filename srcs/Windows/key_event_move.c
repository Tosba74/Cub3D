/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/11 17:51:18 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
	// ft_putstr("FINISH !!!\n");
	// wrdestroy();
	// exit(1);
}

static void	putput(int key)
{
	printf("\n-------------\n");
	ft_putbytes(key);
	printf(" <== %d\n", key);
	printf("-------------\n");
}

int     deal_key(int key, void *param)
{
	t_g *g = param;
	putput(key);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->win.key_press |= MOV_LEFT;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->win.key_press |= MOV_RIGHT;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->win.key_press |= MOV_UP;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->win.key_press |= MOV_DOWN;
	}
	return (0);   
}


int	death_key(int key, void *param)
{
	t_g *g = param;
	putput(key);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->win.key_press &= ~MOV_LEFT;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->win.key_press &= ~MOV_RIGHT;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->win.key_press &= ~MOV_UP;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->win.key_press &= ~MOV_DOWN;
	}
	return (0);
}

void	move(t_g *g)
{
	float	dx;
	float	dy;
	char	mov;
	char	movx;
	char	movy;

	dx = 0;
	dy = 0;
	mov = 0;
	movx = mov & (MOV_LEFT | MOV_RIGHT);
	movy = mov & (MOV_DOWN | MOV_UP);
	if (movx == MOV_LEFT)
		dx *= -SPEED;
	else if (movx == MOV_RIGHT)
		dx *= SPEED;
	if (movy == MOV_DOWN)
		dy *= SPEED;
	else if (movy == MOV_UP)
		dy *= -SPEED;
	g->player.x += dx;
	g->player.y += dy;
}
