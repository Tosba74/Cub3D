/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:10 by bmangin           #+#    #+#             */
/*   Updated: 2021/05/18 11:22:04 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


// static void	putput(int key, t_g g)
// {
// 	printf("\n-------------\n");
// 	ft_putbytes(key);
// 	printf(" <== %d\n", key);
// 	// printf("| Pos X => %-12f Pos Y => %-14f |\n", g.player.x, g.player.y);
// 	ft_print_player(g);
// 	printf("------- ------\n");
// }

int     deal_key(int key, void *param)
{
	t_g *g = param;
	// putput(key, *g);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->win.key_pressv |= MOV_LEFT;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->win.key_pressv |= MOV_RIGHT;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->win.key_pressh |= MOV_UP;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->win.key_pressh |= MOV_DOWN;
	}
	return (0);
}


int	death_key(int key, void *param)
{
	t_g *g = param;
	// putput(key, *g);
	if (key == KEY_ESC)
	{
		close_window(g);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		g->win.key_pressv &= ~MOV_LEFT;
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		g->win.key_pressv &= ~MOV_RIGHT;
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		g->win.key_pressh &= ~MOV_UP;
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		g->win.key_pressh &= ~MOV_DOWN;
	}
	return (0);
}

// void	move(t_g *g)
// {
// 	float	dx;
// 	float	dy;
// 	char	mov;

// 	dx = 0;
// 	dy = 0;
// 	mov = 0;
// 	if (g->win.key_pressv == MOV_LEFT)
// 		g->player.x += -SPEED;
// 	else if (g->win.key_pressv == MOV_RIGHT)
// 		g->player.x *= SPEED;
// 	if (g->win.key_pressh == MOV_DOWN)
// 		g->player.y *= SPEED;
// 	else if (g->win.key_pressh == MOV_UP)
// 		g->player.y *= -SPEED;
// }
	
	
// 	printf("dx == %f\n", dx);
// 	printf("dy == %f\n", dy);
// 	g->player.x += dx;
// 	g->player.y += dy;
// 	printf("x == %f\n", g->player.x);
// 	printf("y == %f\n", g->player.y);
// }

void	move(t_g *g)
{
	if (g->win.key_pressh == MOV_UP && !is_wall(*g))
		g->player.y -= SPEED;
	if (g->win.key_pressh == MOV_DOWN && !is_wall(*g))
		g->player.y += SPEED;
	if (g->win.key_pressv == MOV_LEFT && !is_wall(*g))
		g->player.x -= SPEED;
	if (g->win.key_pressv == MOV_RIGHT && !is_wall(*g))
		g->player.x += SPEED;
}
