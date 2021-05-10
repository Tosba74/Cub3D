/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/09 22:24:33 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


# include "cub3d.h"

void	close_window(t_g *g)
{
	mlx_clear_window(g->win.mlx_ptr, g->win.win_ptr);
	mlx_destroy_window(g->win.mlx_ptr, g->win.win_ptr);
	ft_err(19);
	// ft_putstr("FINISH !!!\n");
	// wrdestroy();
	// exit(1);
}

int     deal_key(int key, void *param)
{
	t_g *g = param;
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" <== %d\n", key);
		printf("-------------\n");
		return (MOV_LEFT);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" ==> %d\n", key);
		printf("-------------\n");
		return (MOV_RIGHT);
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" vvv %d\n", key);
		printf("-------------\n");
		return (MOV_DOWN);
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		printf("\n-------------\n");
		ft_putbytes(key);
		printf(" ^^^ %d\n", key);
		printf("-------------\n");
		return (MOV_UP);
	}
	else if (key)
	{
		printf("-------------");
		ft_putbytes(key);
		printf("<> %d\n", key);
		printf("-------------");
	}
	return(0);   
}
void	move(t_g *g)
{
    int    dx;
    int    dy;
	char	mov;
    char    movx;
    char    movy;
	
	mov = 0;
	movx = mov & (MOV_LEFT | MOV_RIGHT);
	movy = mov & (MOV_DOWN | MOV_UP);
    if (movx == MOV_LEFT)
        dx = -SPEED;
    else if (movx == MOV_RIGHT)
        dx = SPEED;
    if (movy == MOV_DOWN)
        dy = SPEED;
    else if (movy == MOV_UP)
        dy = -SPEED;
	g->player.x += dx;
	g->player.y += dy;
}

key_hook(getkeys);
loop_hook(move);